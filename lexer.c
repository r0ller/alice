#include "lexer.h"
#include "db.h"
#include <string.h>

struct cl_lexer{
	struct public_lex{
		int (*scan)(lexer *, const char *, char **);
		lexicon (*get_word_by_token)(lexer *, unsigned int);/*mainly for yacc to avoid repetitive db read*/
		}public;
	struct private_lex{
		int (*store_word)(lexer *, db *);
		char *(*prepare_query)(lexer *, const char *);
		void (*destroy_words)(lexer *);
		lexicon **words;
		unsigned int nr_of_words;
		unsigned char newline_set;
		}private;
};

/*PUBLIC*/
lexer *new_lexer(void){
	/*static*/ lexer *plex=NULL;

	/*if(lexer==NULL){*/
		plex=malloc(sizeof(lexer));
		plex->public.scan=&hi_scan;
		plex->public.get_word_by_token=&hi_get_word_by_token;
		plex->private.store_word=&hi_store_word;
		plex->private.prepare_query=&hi_prepare_lex_query;
		plex->private.destroy_words=&hi_destroy_words;
		plex->private.words=NULL;
		plex->private.nr_of_words=0;
		plex->private.newline_set=0;
		/*}*/
	return plex;
}

void destroy_lexer(lexer **this){
	if(*this!=NULL){
		(*this)->private.destroy_words(*this);
		free(*this);
		*this=NULL;
	}
	return;
}

int hi_scan(lexer *this, const char *word, char **errmsg){/*return:-2:newline_set -1:hiba (pl.tobb mint 1 token), 0:konstans, >0:token*/
	int token=0;
	char *query=NULL;

	/*FIXME: a prepare_query-t es az exec_sql-t beletenni a store_word-be!*/
	query=this->private.prepare_query(this, word);
	if(sqlite->public.exec_sql(sqlite, query, errmsg))return -1;
	token=this->private.store_word(this, sqlite);
	free(query);/*ez is megy a store_word-be!*/
	return token;
}

lexicon hi_get_word_by_token(lexer *this, unsigned int token){
	lexicon word;
	unsigned int i;

	if(token>0){
		for(i=0;i<this->private.nr_of_words;i++){
			if(token==(*this->private.words[i]).rowid){
				word.rowid=(*this->private.words[i]).rowid;
				strcpy(word.word,(*this->private.words[i]).word);
				strcpy(word.gcat,(*this->private.words[i]).gcat);
				strcpy(word.lexeme,(*this->private.words[i]).lexeme);
				strcpy(word.functor,(*this->private.words[i]).functor);
			}
		}
	}
	return word;
}

/*PRIVATE*/
int hi_store_word(lexer *this, db *sqlite){/*return: -1:hiba (pl. tobb mint 1 token), 0: konstans, >0: token*/
	int i=0, verb_index=-1, token=0;
	lexicon **words=NULL;

	if(sqlite->public.result_size/5>0){
		this->private.words=realloc(this->private.words,(this->private.nr_of_words+sqlite->public.result_size/5)*sizeof(lexicon *));
		words=this->private.words+this->private.nr_of_words;
		do{
			*words=malloc(sizeof(lexicon));
			(*words)->rowid=atoi(sqlite->public.query_result_values[i]);
			i++;
			strcpy((*words)->word,sqlite->public.query_result_values[i]);
			i++;
			strcpy((*words)->gcat,sqlite->public.query_result_values[i]);
			if((*words)->gcat[0]=='V') verb_index=this->private.nr_of_words+i/5;
			i++;
			strcpy((*words)->lexeme,sqlite->public.query_result_values[i]);
			i++;
			strcpy((*words)->functor,sqlite->public.query_result_values[i]);
			i++;
			words++;
		}while(i<sqlite->public.result_size);
		if(sqlite->public.result_size/5>1){
			for(i=0;i<sqlite->public.result_size/5;i++){
				if(this->private.nr_of_words==0 && verb_index==i){
					/*more than 1 token found but due to the word position*/
					/*we take the one with the grammatical category 'verb'*/
					token=this->private.words[i]->rowid;
					break;
				}
				else token=-1;/*more than one token found*/
			}
		}
		else token=this->private.words[this->private.nr_of_words]->rowid;
		this->private.nr_of_words+=sqlite->public.result_size/5;
	}
	return token;
}

char *hi_prepare_lex_query(lexer *this, const char *word){
	char *query=NULL, length, *string="SELECT ROWID, WORD, GCAT, LEXEME, FUNCTOR FROM LEXICON WHERE WORD = '";

	length=strlen(string)+strlen(word)+3;
	query=realloc(query,length);
	strcpy(query,string);
	strcat(query,word);
	strcat(query,"';");
	return query;
}

void hi_destroy_words(lexer *this){
	unsigned int i;

	if(this->private.words!=NULL){
		for(i=0;i<this->private.nr_of_words;i++){
			free(this->private.words[i]);
		}
		free(this->private.words);
		this->private.words=NULL;
		this->private.nr_of_words=0;
		this->private.newline_set=0;
	}
	return;
}
