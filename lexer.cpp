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
	lexicon new_word;

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
			if(morphalytics==NULL){//The word could not be analysed -> treat it as constant
				new_word.token=0;
				new_word.word=last_word;
				new_word.gcat="CON";
				new_word.lexeme=last_word;
				words.push_back(new_word);
				++nr_of_words;
				return 0;
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

	if(human_input_iterator!=human_input.end()){
		word.token=words[nr_of_words-1].token;
		word.word=words[nr_of_words-1].word;
		word.lid=words[nr_of_words-1].lid;
		word.gcat=words[nr_of_words-1].gcat;
		word.lexeme=words[nr_of_words-1].lexeme;
		word.dependencies=words[nr_of_words-1].dependencies;
		word.morphalytics=words[nr_of_words-1].morphalytics;
	}
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
	unsigned int i=0, nr_of_morphemes=0, tag_position=0, token=0;
	lexicon new_word;
	db *sqlite=NULL;
	std::multimap<unsigned int,field>::const_iterator field_position, gcat_position;
	query_result *lexeme=NULL, *gcats_and_lingfeas=NULL;
	std::string lingfea;
	const std::pair<const unsigned int,field> *field;
	std::vector<std::string> morphemes;
	std::deque<unsigned int> tokens;

	sqlite=db::get_instance();
	//TODO:convert gcat to uppercase
	//std::transform(morphalytics.gcat().begin(),morphalytics.gcat().end(),gcat.begin(),::toupper);
	lexeme=sqlite->exec_sql("SELECT WORD, LID, GCAT, LEXEME FROM LEXICON WHERE WORD = '" + morphalytics.stem() + "' AND LID = 'ENG' AND GCAT = '" + morphalytics.gcat() + "';");
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
				new_word.dependencies=dependencies_read_for_functor(new_word.lexeme);
				new_word.morphalytics=&morphalytics;
				gcats_and_lingfeas=sqlite->exec_sql("SELECT * FROM GCAT WHERE GCAT = '"+new_word.gcat+"' AND LID = 'ENG';");
				morphemes=morphalytics.morphemes();
				nr_of_morphemes=morphemes.size();
				for(i=0;i<nr_of_morphemes;++i){
					tag_position=morphemes[i].find("[lfea]");
					if(tag_position!=std::string::npos){
						lingfea=morphemes[i].substr(0,tag_position);
						field=gcats_and_lingfeas->first_value_for_field_name_found("feature",lingfea);
						if(field->second.field_value.empty()==true){
							//TODO: throw exception
							exit(EXIT_FAILURE);
						}
						//std::cout<<"token:"<<*gcats_and_lingfeas->field_value_at_row_position(field->first,"token")<<std::endl;
						token=std::atoi(gcats_and_lingfeas->field_value_at_row_position(field->first,"token")->c_str());
						tokens.push_back(token);
					}
					else{
						tag_position=morphemes[i].find("[stem]");
						if(tag_position!=std::string::npos){
							field=gcats_and_lingfeas->first_value_for_field_name_found("feature","Stem");
							if(field==NULL){
								field=gcats_and_lingfeas->first_value_for_field_name_found("feature","");//Will SQLite3 find the empty string as value???
									if(field==NULL){
									//TODO: throw exception
										exit(EXIT_FAILURE);
									}
							}
							//std::cout<<"token:"<<*gcats_and_lingfeas->field_value_at_row_position(field->first,"token")<<std::endl;
							token=std::atoi(gcats_and_lingfeas->field_value_at_row_position(field->first,"token")->c_str());
							tokens.push_back(token);
						}
					}
				}
				new_word.token=token;
				words.push_back(new_word);
			}
			else{
				throw lexicon_type_and_db_table_schema_mismatch();
			}
		}
//		std::cout<<"nr of dependencies="<<words.rbegin()->dependencies->result_rows()<<std::endl;
		nr_of_words+=lexeme->nr_of_result_rows();
		delete lexeme;
		delete gcats_and_lingfeas;
	}
	return tokens;
}

query_result* lexer::dependencies_read_for_functor(const std::string& functor){
	db *sqlite=NULL;
	query_result *dependencies=NULL;
	std::string semantic_dependency,ref_d_key;
	unsigned int n=0;

	sqlite=db::get_instance();
	dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor+"';");
	for(unsigned int i=0, n=dependencies->nr_of_result_rows();i<n;++i){
		semantic_dependency=*dependencies->field_value_at_row_position(i,"semantic_dependency");
		ref_d_key=*dependencies->field_value_at_row_position(i,"ref_d_key");
		if(semantic_dependency.empty()==false&&ref_d_key.empty()==false){
			read_dependencies_by_key(semantic_dependency,ref_d_key,dependencies);
		}
	}
	return dependencies;
}

void lexer::read_dependencies_by_key(const std::string& functor, const std::string& d_key, query_result* dependencies){
	db *sqlite=NULL;
	query_result *result=NULL;
	std::string semantic_dependency,ref_d_key;
	unsigned int n;

	sqlite=db::get_instance();
	result=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor+"' AND D_KEY = '"+d_key+"';");
//	std::cout<<"reading dependency "<<functor<<" ref_d_key "<<d_key<<std::endl;
	dependencies->append(*result);
	for(unsigned int i=0, n=result->nr_of_result_rows();i<n;++i){
		semantic_dependency=*result->field_value_at_row_position(i,"semantic_dependency");
		ref_d_key=*result->field_value_at_row_position(i,"ref_d_key");
		if(semantic_dependency.empty()==false&&ref_d_key.empty()==false){
			read_dependencies_by_key(semantic_dependency,ref_d_key,dependencies);
		}
	}
	return;
}

void lexer::destroy_words(){

	if(words.empty()==false){
		words.clear();
		nr_of_words=0;
	}
	return;
}
