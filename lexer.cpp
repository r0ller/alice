#include "lexer.h"
#include "db.h"

/*PUBLIC*/
lexer::lexer(const char *input_string){
		nr_of_words=0;
		human_input=std::string (input_string);
		human_input_iterator=human_input.begin();
}

lexer::~lexer(){
	destroy_words();
}

int lexer::next_token(){/*return:-2:newline_set -1:hiba (pl.tobb mint 1 token), 0:konstans, >0:token*/
	int token=0;

	last_word.clear();
	do{
		for(;human_input_iterator<human_input.end()&&std::isspace(human_input[std::distance(human_input.begin(),human_input_iterator)])==false;++human_input_iterator){
			last_word+=std::tolower(human_input[std::distance(human_input.begin(),human_input_iterator)]);
		}
	}while(last_word.empty()==true&&human_input_iterator++<human_input.end());
	if(last_word.empty()==false) token=store_word(last_word);
	else human_input_iterator=human_input.end();//Don't let the iterator advance into infinity in case of garbage input
	return token;
}

lexicon lexer::get_word_by_token(unsigned int token){
	lexicon word;
	unsigned int i;

	if(token>0){
		for(i=0;i<nr_of_words;i++){
			if(token==words[i].rowid){
				word.rowid=words[i].rowid;
				word.word=words[i].word;
				word.gcat=words[i].gcat;
				word.lexeme=words[i].lexeme;
			}
		}
	}
	return word;
}

const std::string& lexer::last_word_scanned(){
	return last_word;
}

/*PRIVATE*/
int lexer::store_word(const std::string& word){/*return: -1:hiba (pl. tobb mint 1 token), 0: konstans, >0: token*/
	unsigned int i=0;
	int verb_index=-1, token=0;
	lexicon new_word;
	db *sqlite=NULL;
	std::string query;
	std::multimap<unsigned int,field>::const_iterator field_position;

	query=prepare_query(word);
	sqlite=db::get_instance();
	sqlite->exec_sql(query);
	if(sqlite->query_result_set().empty()==false){
		for(field_position=sqlite->query_result_set().begin();field_position!=sqlite->query_result_set().end();++field_position){
			if(field_position->second.field_name=="rowid")
				new_word.rowid=atoi(field_position->second.field_value.c_str());
			else if(field_position->second.field_name=="word")
				new_word.word=field_position->second.field_value;
			else if(field_position->second.field_name=="gcat"){
				new_word.gcat=field_position->second.field_value;
				if(new_word.gcat[0]=='V') verb_index=nr_of_words+field_position->first;
			}
			else if(field_position->second.field_name=="lexeme"){
				new_word.lexeme=field_position->second.field_value;
				words.push_back(new_word);
			}
			else throw lexicon_type_and_db_table_schema_mismatch();
			//printf("DEBUG: field '%s'=%s\n",field_position->second.first.c_str(),field_position->second.second.c_str());
		}
		if(sqlite->result_size()>1){
			for(i=0;i<sqlite->result_size();++i){
				if(nr_of_words==0 && verb_index==i){
					/*more than 1 token found but due to the word position*/
					/*we take the one with the grammatical category 'verb'*/
					token=words[i].rowid;
					break;
				}
				else throw more_than_one_token_found();/*more than one token found->throw exception*/
			}
		}
		else token=words[nr_of_words].rowid;
		nr_of_words+=sqlite->result_size();
		//printf("DEBUG nr_of_words=%d\n",nr_of_words);
	}
	return token;
}

std::string lexer::prepare_query(const std::string& word){
	return "SELECT ROWID, WORD, GCAT, LEXEME FROM LEXICON WHERE WORD = '" + word + "';";
}

void lexer::destroy_words(){

	if(words.empty()==false){
		words.clear();
		nr_of_words=0;
	}
	return;
}
