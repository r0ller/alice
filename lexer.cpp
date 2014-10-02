#include "lexer.h"
#include "db.h"

/*PUBLIC*/
lexer::lexer(const char *input_string){
		nr_of_words=0;
		human_input=std::string (input_string);
		human_input_iterator=human_input.begin();
		stemmer=morphan::get_instance();
}

lexer::~lexer(){
	destroy_words();
	delete stemmer;
}

unsigned int lexer::next_token(){
	unsigned int token=0;
	std::string last_word;
	morphan_result *morphalytics=NULL;

	if(token_deque.empty()==false){
		token=token_deque.front();
		token_deque.pop_front();
	}
	else{
		last_word.clear();
		do{
			for(;human_input_iterator<human_input.end()&&std::isspace(human_input[std::distance(human_input.begin(),human_input_iterator)])==false;++human_input_iterator){
				last_word+=std::tolower(human_input[std::distance(human_input.begin(),human_input_iterator)]);
			}
		}while(last_word.empty()==true&&human_input_iterator++<human_input.end());
		if(last_word.empty()==false){
			morphalytics=stemmer->analyze(last_word);//What if there're >1 analyses for the same word form???
			if(morphalytics==NULL){
				//TODO: throw exception
				exit(EXIT_FAILURE);
			}
			token_deque=store_word(*morphalytics);
			if(token_deque.empty()==true){
				//TODO: throw exception
				exit(EXIT_FAILURE);
			}
			token=token_deque.front();
			token_deque.pop_front();
		}
		else human_input_iterator=human_input.end();//Don't let the iterator advance into infinity in case of garbage input
	}
	return token;
}

lexicon lexer::last_word_scanned(){
	lexicon word;

	word.token=words[nr_of_words].token;
	word.word=words[nr_of_words].word;
	word.lid=words[nr_of_words].lid;
	word.gcat=words[nr_of_words].gcat;
	word.lexeme=words[nr_of_words].lexeme;
	word.dependencies=words[nr_of_words].dependencies;
	word.morphalytics=words[nr_of_words].morphalytics;
	return word;
}

lexicon lexer::get_word_by_lexeme(const std::string lexeme){
	lexicon word;
	unsigned int i;

	if(lexeme.empty()==false){
		for(i=0;i<nr_of_words;i++){
			if(lexeme==words[i].lexeme+words[i].lid+words[i].gcat){
				word.token=words[i].token;
				word.word=words[i].word;
				word.lid=words[i].lid;
				word.gcat=words[i].gcat;
				word.lexeme=words[i].lexeme;
				word.dependencies=words[i].dependencies;
				word.morphalytics=words[i].morphalytics;
			}
		}
	}
	return word;
}

/*PRIVATE*/
std::deque<unsigned int> lexer::store_word(morphan_result& morphalytics){
	unsigned int i=0, nr_of_gcats=0, nr_of_morphemes=0, tag_position=0, lingfea_token=0, token=0;
	lexicon new_word;
	db *sqlite=NULL;
	std::multimap<unsigned int,field>::const_iterator field_position, gcat_position;
	query_result *lexeme=NULL, *gcats=NULL, *lingfeas=NULL;
	std::string lingfea;
	std::pair<unsigned int,field> field;
	std::vector<std::string> morphemes;
	std::deque<unsigned int> tokens;

	sqlite=db::get_instance();
	lexeme=sqlite->exec_sql("SELECT WORD, LID, GCAT, LEXEME FROM LEXICON WHERE WORD = '" + morphalytics.stem() + "' AND LID = 'ENG' AND GCAT = '" +morphalytics.gcat()+ "';");
	if(lexeme!=NULL&&lexeme->result_set().empty()==false){
		for(field_position=lexeme->result_set().begin();field_position!=lexeme->result_set().end();++field_position){
			if(field_position->second.field_name=="word")
				new_word.word=field_position->second.field_value;
			else if(field_position->second.field_name=="lid")
				new_word.lid=field_position->second.field_value;
			else if(field_position->second.field_name=="gcat")
				new_word.gcat=field_position->second.field_value;
			else if(field_position->second.field_name=="lexeme"){
				new_word.lexeme=field_position->second.field_value;
				new_word.dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+new_word.lexeme+new_word.lid+new_word.gcat+"';");
				new_word.morphalytics=&morphalytics;
				gcats=sqlite->exec_sql("SELECT DISTINCT GCAT FROM LEXICON WHERE LID = 'ENG';");
				nr_of_gcats=gcats->result_rows();
				for(i=0;i<nr_of_gcats;++i){
					gcat_position=gcats->get_row(i);
					if(gcat_position->second.field_value==morphalytics.gcat()){
						token=i+1;//0 is reserved for yacc to indicate end of input, so add 1
						new_word.token=token;
						break;
					}
				}
				words.push_back(new_word);
				lingfeas=sqlite->exec_sql("SELECT * FROM LINGFEAS WHERE GCAT = '"+new_word.gcat+"' AND LID = 'ENG';");
				morphemes=morphalytics.morphemes();
				nr_of_morphemes=morphemes.size();
				for(i=0;i<nr_of_morphemes;++i){
					tag_position=morphemes[i].find("[lfea]");
					if(tag_position!=std::string::npos){
						lingfea=morphemes[i].substr(0,tag_position);
						field=lingfeas->find_field_value("FEATURE",lingfea);
						if(field.second.field_value.empty()==true){
							//TODO: throw exception
							exit(EXIT_FAILURE);
						}
						lingfea_token=field.first;
						tokens.push_back(lingfea_token);
					}
					else{
						tag_position=morphemes[i].find("[stem]");
						if(tag_position!=std::string::npos){
							tokens.push_back(new_word.token);
						}
					}
				}
			}
			else{
				throw lexicon_type_and_db_table_schema_mismatch();
			}
		}
//		std::cout<<"nr of dependencies="<<words.rbegin()->dependencies->result_rows()<<std::endl;
		nr_of_words+=lexeme->result_rows();
		delete lexeme;
		delete gcats;
		delete lingfeas;
	}
	return tokens;
}

void lexer::destroy_words(){

	if(words.empty()==false){
		words.clear();
		nr_of_words=0;
	}
	return;
}
