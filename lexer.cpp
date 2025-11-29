#include "lexer.h"
extern interpreter *sparser;
extern std::map<std::string, unsigned int> symbol_token_map;
extern std::map<unsigned int,std::string> token_symbol_map;

morphan* lexer::stemmer=NULL;
std::map<std::string,std::vector<std::string>> lexer::sentences_word_forms;
std::map<std::string,std::vector<lexicon> > lexer::cache;

/*PUBLIC*/
lexer::lexer(const char *input_string,const char *language,std::locale& locale,const bool generate_tokens,tokenpaths *token_paths){
		lid=std::string(language);
		human_input=std::string(input_string);
		stemmer=morphan::get_instance(lid);
		token=0;
		this->locale=locale;
		generate_tokens_=generate_tokens;
		word_forms_=analyze_and_cache(human_input);
		word_form_iterator=word_forms_.begin();
		this->token_paths=token_paths;
		end_token_returned=false;
}

lexer::~lexer(){
	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"destructing lexer");
	destroy_words();
}

unsigned int lexer::next_token(){
	std::string last_word,new_word_form;
	lexicon new_word;
	std::vector<lexicon> new_words;

	if(token_deque.empty()==false){
		token=token_deque.front();
		token_deque.pop_front();
	}
	else{
		last_word=next_word();
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"last word:"+last_word);
		if(last_word.empty()==false){
			auto cache_hit=copy_word_from_cache(last_word);
			if(cache_hit.second.empty()==false){
				new_words=cache_hit.second;
			}
			else{
				throw std::runtime_error("Word not found in cache:"+last_word);
			}
			new_word=token_paths->next_word(new_words);
			if(new_word.word.empty()==true){
				throw std::runtime_error("Got no next word from token paths.");
			}
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"new word:"+last_word);
			if(token_paths->toa()&HI_LEO_SYNTAX&&new_word.lexicon_entry==false&&new_word.word.empty()==false&&new_word.gcat!="CON"&&new_word.dependencies==NULL){
				new_word.tokens.clear();
				new_word.tokens.push_back(yy::parser::token::YYerror);
			}
			words.push_back(new_word);
			token_deque=new_word.tokens;
			token=token_deque.front();
			token_deque.pop_front();
		}
		else token=0;
	}
	return token;
}

lexicon lexer::last_word_scanned(){
	lexicon word;
	unsigned int nr_of_words;

	nr_of_words=words.size();
	word.token=words[nr_of_words-1].token;
	word.word=words[nr_of_words-1].word;
	word.lid=words[nr_of_words-1].lid;
	word.gcat=words[nr_of_words-1].gcat;
	word.lexeme=words[nr_of_words-1].lexeme;
	word.dependencies=words[nr_of_words-1].dependencies;
	word.morphalytics=words[nr_of_words-1].morphalytics;
	word.tokens=words[nr_of_words-1].tokens;
	word.lexicon_entry=words[nr_of_words-1].lexicon_entry;
	return word;
}

lexicon lexer::last_word_scanned(const unsigned int token){
	lexicon word;
	unsigned int nr_of_words;
	bool token_found=false;

	nr_of_words=words.size();
	if(token==words[nr_of_words-1].token){
		word=last_word_scanned();
	}
	else{
		for(auto&& i:words[nr_of_words-1].tokens) if(i==token) token_found=true;
		if(token_found==true){
			word.token=token;
			//word.word=words[nr_of_words-1].word;//Leave empty
			word.lid=words[nr_of_words-1].lid;
			//word.lexeme=words[nr_of_words-1].lexeme;//Leave empty
			word.dependencies=NULL;//Leave empty
			word.morphalytics=words[nr_of_words-1].morphalytics;
			word.tokens=words[nr_of_words-1].tokens;
			word.lexicon_entry=words[nr_of_words-1].lexicon_entry;
			word.gcat=token_symbol_map.find(token)->second;
		}
		else{
			throw std::runtime_error("Token "+std::to_string(token)+" not found for the last word scanned.");
		}
	}
	return word;
}

lexicon lexer::get_word_by_lexeme(const std::string lexeme){
	lexicon word;
	unsigned int i,nr_of_words;

	nr_of_words=words.size();
	if(lexeme.empty()==false){
		for(i=0;i<nr_of_words;i++){
			if(lexeme==words[i].lexeme){
				word.token=words[i].token;
				word.word=words[i].word;
				word.lid=words[i].lid;
				word.gcat=words[i].gcat;
				word.lexeme=words[i].lexeme;
				word.dependencies=words[i].dependencies;
				word.morphalytics=words[i].morphalytics;
				word.lexicon_entry=words[i].lexicon_entry;
				word.tokens=words[i].tokens;
				break;
			}
		}
	}
	return word;
}

lexicon lexer::tokenize_word(morphan_result& morphalytics, const std::string& language, const bool generate_tokens){
	unsigned int i=0, nr_of_morphemes=0, token=0;
	size_t tag_position=0;
	lexicon new_word;
	db *sqlite=NULL;
	std::multimap<unsigned int,field>::const_iterator field_position, gcat_position;
	query_result *lexeme=NULL, *gcats_and_lingfeas=NULL;
	std::string lingfea,symbol;
	const std::pair<const unsigned int,field> *field;
	std::vector<std::string> morphemes;

	sqlite=db_factory::get_instance();
	//TODO:convert gcat to uppercase
	//std::transform(morphalytics.gcat().begin(),morphalytics.gcat().end(),gcat.begin(),::toupper);
	lexeme=sqlite->exec_sql("SELECT WORD, LID, GCAT, LEXEME FROM LEXICON WHERE WORD = '" + sqlite->escape(morphalytics.stem()) + "' AND LID = '"+language+"' AND GCAT = '" + morphalytics.gcat() + "';");
	if(lexeme!=NULL&&lexeme->result_set().empty()==false){
		for(field_position=lexeme->result_set().begin();field_position!=lexeme->result_set().end();++field_position){
			if(field_position->second.field_name=="word")
				new_word.word=field_position->second.field_value;
			else if(field_position->second.field_name=="lid")
				new_word.lid=field_position->second.field_value;
			else if(field_position->second.field_name=="gcat")
				new_word.gcat=field_position->second.field_value;
			else if(field_position->second.field_name=="lexeme"){
				new_word.lexicon_entry=true;
				new_word.lexeme=field_position->second.field_value;
				new_word.dependencies=dependencies_read_for_functor(new_word.lexeme);
				new_word.morphalytics=&morphalytics;
				gcats_and_lingfeas=sqlite->exec_sql("SELECT * FROM GCAT WHERE GCAT = '"+new_word.gcat+"' AND LID = '"+language+"';");
				morphemes=morphalytics.morphemes();
				nr_of_morphemes=morphemes.size();
				if(gcats_and_lingfeas!=NULL){
					for(i=0;i<nr_of_morphemes;++i){
						tag_position=morphemes[i].find("[stem]");
						if(tag_position==std::string::npos){
							lingfea=morphemes[i];
							logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"lingfea:"+lingfea);
							field=gcats_and_lingfeas->first_value_for_field_name_found("feature",lingfea);
							if(field==NULL||field->second.field_value.empty()==true){
	//							Don't do anything, just skip lfeas that are not registered
							}
							else{
								symbol="t_"+new_word.lid+"_"+new_word.gcat+"_"+field->second.field_value;
								auto&& symbol_token_map_entry=symbol_token_map.find(symbol);
								if(symbol_token_map_entry!=symbol_token_map.end()){
									token=symbol_token_map_entry->second;
									logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token:"+symbol);
									new_word.tokens.push_back(token);
								}
								else{
									if(generate_tokens==true){
										if(symbol_token_map.size()!=token_symbol_map.size()) throw std::runtime_error("Token-symbol map sizes differ when trying to add symbol "+symbol);
										token=symbol_token_map.size()+1;
										symbol_token_map.insert(std::make_pair(symbol,token));
										token_symbol_map.insert(std::make_pair(token,symbol));
										logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token:"+symbol);
										new_word.tokens.push_back(token);
									}
									else{
										//TODO: figure out if it's necessary to harden modelling this way:
										//Throwing this exception here means that each and every gcat+feature
										//combination (morpheme symbol) must have a token generated.
										//As a corollary, it must be present in the grammar as well.
										//For the ML scenarios this is ok but in case of manual modelling
										//one may not want to process each and every morpheme.
										//throw std::runtime_error("No token found for symbol "+symbol);
									}
								}
							}
						}
						else{
							field=gcats_and_lingfeas->first_value_for_field_name_found("feature","Stem");
							if(field==NULL){
								throw std::runtime_error("No Stem is defined for gcat "+new_word.gcat+" in GCAT db table.");
							}
							symbol="t_"+new_word.lid+"_"+new_word.gcat+"_"+field->second.field_value;
							auto&& symbol_token_map_entry=symbol_token_map.find(symbol);
							if(symbol_token_map_entry!=symbol_token_map.end()){
								token=symbol_token_map_entry->second;
								logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token:"+symbol);
								new_word.tokens.push_back(token);
								new_word.token=token;
							}
							else{
								if(generate_tokens==true){
									if(symbol_token_map.size()!=token_symbol_map.size()) throw std::runtime_error("Token-symbol map sizes differ when trying to add symbol "+symbol);
									token=symbol_token_map.size()+1;
									symbol_token_map.insert(std::make_pair(symbol,token));
									token_symbol_map.insert(std::make_pair(token,symbol));
									logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token:"+symbol);
									new_word.tokens.push_back(token);
									new_word.token=token;
								}
								else{
									throw std::runtime_error("No Stem token is defined for gcat "+new_word.gcat+" in GCAT db table.");
								}
							}
						}
					}
					delete gcats_and_lingfeas;
				}
			}
			else{
				throw lexicon_type_and_db_table_schema_mismatch();
			}
		}
		delete lexeme;
	}
	else{//Happens if the stemmer could provide an analysis but the stem is not found in the lexicon.
		//Another possibility would be to make it strictly available for CONs like if(morphalytics.gcat()=="CON")
		//but let's make a bold step. See comment at the line below when reading dependencies.
		new_word.lexicon_entry=false;
		new_word.word=morphalytics.word();
		new_word.lid=language;
		new_word.gcat=morphalytics.gcat();
		new_word.lexeme=morphalytics.stem();
		new_word.dependencies=dependencies_read_for_functor(new_word.gcat);
		//By passing in gcat, the old behaviour for reading dependencies of "CON" is retained and a new
		//feature is introduced by which one can bind lexemes not existing in the lexicon to a functor by
		//their gcat.
		//Furthermore, if neither a lexeme is registered for a stem in the lexicon, nor a dependency entry
		//in the depolex table, it poses no problem any more unless the node of the stem is combined.
		//As it has been historically always assumed that there's a dependency entry for the stems,
		//no checks are set up in the code for checking the 'dependencies' attribute being NULL.
		//Currently, combining such a node (i.e. having no dependency entries) with another node will
		//result in a dump.
		//TODO: Set up checks for the dependencies attribute being NULL.
		new_word.morphalytics=&morphalytics;
		gcats_and_lingfeas=sqlite->exec_sql("SELECT * FROM GCAT WHERE GCAT = '"+new_word.gcat+"' AND LID = '"+language+"';");
		morphemes=morphalytics.morphemes();
		nr_of_morphemes=morphemes.size();
		if(gcats_and_lingfeas!=NULL){
			for(i=0;i<nr_of_morphemes;++i){
				tag_position=morphemes[i].find("[stem]");
				if(tag_position==std::string::npos){
					lingfea=morphemes[i];
					field=gcats_and_lingfeas->first_value_for_field_name_found("feature",lingfea);
					if(field==NULL||field->second.field_value.empty()==true){
	//					Don't do anything, just skip lfeas that are not registered
					}
					else{
						symbol="t_"+new_word.lid+"_"+new_word.gcat+"_"+field->second.field_value;
						auto&& symbol_token_map_entry=symbol_token_map.find(symbol);
						if(symbol_token_map_entry!=symbol_token_map.end()){
							token=symbol_token_map_entry->second;
							logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token:"+symbol);
							new_word.tokens.push_back(token);
						}
						else{
							if(generate_tokens==true){
								if(symbol_token_map.size()!=token_symbol_map.size()) throw std::runtime_error("Token-symbol map sizes differ when trying to add symbol "+symbol);
								token=symbol_token_map.size()+1;
								symbol_token_map.insert(std::make_pair(symbol,token));
								token_symbol_map.insert(std::make_pair(token,symbol));
								logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token:"+symbol);
								new_word.tokens.push_back(token);
							}
							else{
								//TODO: figure out if it's necessary to harden modelling this way:
								//Throwing this exception here means that each and every gcat+feature
								//combination (morpheme symbol) must have a token generated.
								//As a corollary, it must be present in the grammar as well.
								//For the ML scenarios this is ok but in case of manual modelling
								//one may not want to process each and every morpheme.
								//throw std::runtime_error("No token found for symbol "+symbol);
							}
						}
					}
				}
				else{
					field=gcats_and_lingfeas->first_value_for_field_name_found("feature","Stem");
					if(field==NULL){
						throw std::runtime_error("No Stem is defined for gcat "+new_word.gcat+" in GCAT db table.");
					}
					symbol="t_"+new_word.lid+"_"+new_word.gcat+"_"+field->second.field_value;
					auto&& symbol_token_map_entry=symbol_token_map.find(symbol);
					if(symbol_token_map_entry!=symbol_token_map.end()){
						token=symbol_token_map_entry->second;
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token:"+symbol);
						new_word.tokens.push_back(token);
						new_word.token=token;
					}
					else{
						if(generate_tokens==true){
							if(symbol_token_map.size()!=token_symbol_map.size()) throw std::runtime_error("Token-symbol map sizes differ when trying to add symbol "+symbol);
							token=symbol_token_map.size()+1;
							symbol_token_map.insert(std::make_pair(symbol,token));
							token_symbol_map.insert(std::make_pair(token,symbol));
							logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token:"+symbol);
							new_word.tokens.push_back(token);
							new_word.token=token;
						}
						else{
							throw std::runtime_error("No Stem token is defined for gcat "+new_word.gcat+" in GCAT db table.");
						}
					}
				}
			}
			delete gcats_and_lingfeas;
		}
	}
	return new_word;
}

query_result* lexer::dependencies_read_for_functor(const std::string& functor,const bool optional_only){
	db *sqlite=NULL;
	query_result *dependencies=NULL;
	std::string semantic_dependency,ref_d_key;

	sqlite=db_factory::get_instance();
	dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor+"' ORDER BY LEXEME, D_KEY, D_COUNTER;");
	if(dependencies==NULL){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"If this gets combined with another node, you'll get a dump as no dependency entries found for "+functor);
		//Don't throw anything, see comment in tokenize_word() when calling this function for lexemes not being found in the lexicon
		//throw std::runtime_error("No dependency entry defined for functor "+functor+" in DEPOLEX db table.");
	}
	else{
		for(unsigned int i=0, n=dependencies->nr_of_result_rows();i<n;++i){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"row index:"+std::to_string(i)+" lexeme:"+*dependencies->field_value_at_row_position(i,"lexeme")+" d_key:"+*dependencies->field_value_at_row_position(i,"d_key")+" d_counter:"+*dependencies->field_value_at_row_position(i,"d_counter"));
			semantic_dependency=*dependencies->field_value_at_row_position(i,"semantic_dependency");
			ref_d_key=*dependencies->field_value_at_row_position(i,"ref_d_key");
			if(semantic_dependency.empty()==false&&ref_d_key.empty()==false){
				read_dependencies_by_key(semantic_dependency,ref_d_key,dependencies,optional_only);
			}
		}
	}
	return dependencies;
}

void lexer::read_dependencies_by_key(const std::string& functor, const std::string& d_key, query_result* dependencies, const bool optional_only){
	db *sqlite=NULL;
	query_result *result=NULL;
	std::string semantic_dependency,ref_d_key,d_failover;
	const std::pair<const unsigned int,field> *dependency=NULL;

	sqlite=db_factory::get_instance();
	if(optional_only==true){
		result=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor+"' AND D_KEY = '"+d_key+"' AND ( OPTIONAL_PARENT_ALLOWED != 0 OR OPTIONAL_PARENT_ALLOWED IS NOT NULL ) ORDER BY LEXEME, D_KEY, D_COUNTER;");
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"reading dependency "+functor+" ref_d_key "+d_key);
		if(result!=NULL){
			dependencies->append(*result);
			for(unsigned int i=0, n=result->nr_of_result_rows();i<n;++i){
				semantic_dependency=*result->field_value_at_row_position(i,"semantic_dependency");
				ref_d_key=*result->field_value_at_row_position(i,"ref_d_key");
				d_failover=*result->field_value_at_row_position(i,"d_failover");
				if(semantic_dependency.empty()==false&&ref_d_key.empty()==false){
					dependency=dependencies->first_value_for_field_name_found("lexeme",semantic_dependency);
					while(dependency!=NULL&&*dependencies->field_value_at_row_position(dependency->first,"d_key")!=ref_d_key){
						dependency=dependencies->value_for_field_name_found_after_row_position(dependency->first,"lexeme",semantic_dependency);
					}
					if(dependency==NULL&&std::atoi(d_failover.c_str())!=0){
						read_dependencies_by_key(semantic_dependency,ref_d_key,dependencies,optional_only);
					}
				}
			}
		}
	}
	else{
		result=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor+"' AND D_KEY = '"+d_key+"' ORDER BY LEXEME, D_KEY, D_COUNTER;");
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"reading dependency "+functor+" ref_d_key "+d_key);
		if(result==NULL){
			throw std::runtime_error("No dependency entry defined for functor "+functor+" in DEPOLEX db table.");
		}
		dependencies->append(*result);
		for(unsigned int i=0, n=result->nr_of_result_rows();i<n;++i){
			semantic_dependency=*result->field_value_at_row_position(i,"semantic_dependency");
			ref_d_key=*result->field_value_at_row_position(i,"ref_d_key");
			if(semantic_dependency.empty()==false&&ref_d_key.empty()==false){
				dependency=dependencies->first_value_for_field_name_found("lexeme",semantic_dependency);
				while(dependency!=NULL&&*dependencies->field_value_at_row_position(dependency->first,"d_key")!=ref_d_key){
					dependency=dependencies->value_for_field_name_found_after_row_position(dependency->first,"lexeme",semantic_dependency);
				}
				if(dependency==NULL){
					read_dependencies_by_key(semantic_dependency,ref_d_key,dependencies);
				}
			}
		}
	}
	return;
}

unsigned int lexer::nr_of_words(){
	return words.size();
}

void lexer::destroy_words(){

	if(words.empty()==false){
		words.clear();
	}
	return;
}

std::string lexer::language(){
	return lid;
}

bool lexer::is_end_of_input(){
	if(word_form_iterator==word_forms_.end()&&token_deque.empty()==true) return true;
	else return false;
}

std::string lexer::validated_words(){
	std::set<unsigned int> validated_terminals;
	std::set<std::string> validated_words;
	std::string words_found;

	validated_terminals=sparser->validated_terminals();
	for(auto&& i:validated_terminals){
		if(sparser->get_node_info(i).expression.morphalytics!=NULL&&sparser->get_node_info(i).expression.morphalytics->is_mocked()==false&&sparser->get_node_info(i).expression.word.empty()==false){
			validated_words.insert(sparser->get_node_info(i).expression.morphalytics->word());
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"validated word:"+sparser->get_node_info(i).expression.morphalytics->word());
		}
		else if(sparser->get_node_info(i).expression.word.empty()==false){
			validated_words.insert(sparser->get_node_info(i).expression.word);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"validated word:"+sparser->get_node_info(i).expression.word);
		}
	}
	for(auto&& i:words){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"word in lexicon:"+i.word);
		if(i.morphalytics!=NULL&&i.morphalytics->is_mocked()==false&&i.word.empty()==false&&i.gcat!="CON"){
			if(validated_words.find(i.morphalytics->word())!=validated_words.end()) words_found+=i.morphalytics->word()+" ";
		}
		else if(i.word.empty()==false&&i.gcat!="CON"){
			if(validated_words.find(i.word)!=validated_words.end()) words_found+=i.word+" ";
		}
	}
	if(words_found.empty()==false) words_found.pop_back();
	return words_found;
}

std::vector<lexicon> lexer::word_entries(){
	return words;
}

unsigned int lexer::last_token_returned(){
	return token;
}

std::vector<std::string> lexer::analyze_and_cache(std::string& human_input){
	//Don't change the cache after it's been called for a sentence as token path calculation won't
	//be updated as tokenpaths::next_word() (fed by lexer::next_token()) relies on the cache and the
	//already calculated token paths.
	std::string::iterator human_input_iterator;
	std::string last_word,new_word_form;
	lexicon new_word;
	std::vector<lexicon> new_words;
	std::vector<morphan_result> *morphalytics;
	std::vector<std::string> word_forms;
	db *sqlite=NULL;
	query_result *language_entries=NULL;

	auto sentence_hit=sentences_word_forms.find(human_input);
	if(sentence_hit==sentences_word_forms.end()){
		human_input_iterator=human_input.begin();
		while(human_input_iterator<human_input.end()){
			last_word.clear();
			new_words.clear();
			new_word_form.clear();
			do{
				for(;human_input_iterator<human_input.end()&&std::isspace(human_input[std::distance(human_input.begin(),human_input_iterator)],locale)==false;++human_input_iterator){
					last_word+=std::tolower(human_input[std::distance(human_input.begin(),human_input_iterator)],locale);
				}
			}while(last_word.empty()==true&&human_input_iterator++<human_input.end());
			if(last_word.empty()==false){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"caching word:"+last_word);
				word_forms.push_back(last_word);
				auto cache_hit=cache.find(last_word);
				if(cache_hit==cache.end()){
					sqlite=db_factory::get_instance();
					language_entries=sqlite->exec_sql("SELECT * FROM LANGUAGES;");
					morphalytics=stemmer->analyze(last_word,false);
					if(morphalytics!=NULL&&morphalytics->empty()==false){
						if(morphalytics->size()==1&&morphalytics->front().is_mocked()==true){//The word could not be analysed -> treat it as constant
							std::string symbol="t_"+language()+"_CON_Stem";
							auto&& symbol_token_map_entry=symbol_token_map.find(symbol);
							if(symbol_token_map_entry==symbol_token_map.end()){
								if(generate_tokens_==true){
									if(symbol_token_map.size()!=token_symbol_map.size()) throw std::runtime_error("Token-symbol map sizes differ when trying to add symbol "+symbol);
									token=symbol_token_map.size()+1;
									symbol_token_map.insert(std::make_pair(symbol,token));
									token_symbol_map.insert(std::make_pair(token,symbol));
									new_word.token=token;
								}
								else{
									throw std::runtime_error("No token found for symbol "+symbol);
								}
							}
							else{
								new_word.token=symbol_token_map_entry->second;
							}
							new_word.word=last_word;
							new_word.gcat="CON";
							new_word.lexeme=last_word;
							new_word.dependencies=dependencies_read_for_functor("CON");
							new_word.morphalytics=&morphalytics->front();
							new_word.tokens.clear();
							new_word.tokens.push_back(new_word.token);
							new_word.lexicon_entry=false;
							new_word_form=last_word;
							new_words.push_back(new_word);
							//TODO: check if there's any valid analysis in other fsts but don't add CONs from those
							for(unsigned int i=0;i<language_entries->nr_of_result_rows();++i){
								//1. get stemmer for language
								//2. analyse word
								//3. store new analyses if there are any non-const
								std::string current_lid=*language_entries->field_value_at_row_position(i,"lid");
								morphan *lid_stemmer=morphan::get_instance(current_lid);
								morphalytics=lid_stemmer->analyze(last_word,false);
								if(morphalytics!=NULL&&(morphalytics->size()>1||morphalytics->size()==1&&morphalytics->front().is_mocked()==false)){
									for(auto&& i:*morphalytics){
										new_word=tokenize_word(i,current_lid,generate_tokens_);
										if(new_word.tokens.empty()==true){
											throw std::runtime_error("No tokens found for word:"+last_word);
										}
										new_words.push_back(new_word);
										if(new_word_form.empty()==true){
											//Due to the fact, that the last_word is read from input and the tokenize_word()
											//reads the word and the tokens from the db, in certain cases last_word contains an additional whitespace
											//which makes the two strings different in length. Thus, token_paths->next_word(last_word)
											//would fail in finding the word, as token_paths->add_word(new_word) stores the db word form.
											//So let's store the word form as it's added to token_paths.
											new_word_form=new_word.word;
										}
										new_word.tokens.clear();
									}
								}
							}
						}
						else{
							for(auto&& i:*morphalytics){
								std::string lid=language();
								new_word=tokenize_word(i,lid,generate_tokens_);
								if(new_word.tokens.empty()==true){
									throw std::runtime_error("No tokens found for word:"+last_word);
								}
								new_words.push_back(new_word);
								if(new_word_form.empty()==true){
									//Due to the fact, that the last_word is read from input and the tokenize_word()
									//reads the word and the tokens from the db, in certain cases last_word contains an additional whitespace
									//which makes the two strings different in length. Thus, token_paths->next_word(last_word)
									//would fail in finding the word, as token_paths->add_word(new_word) stores the db word form.
									//So let's store the word form as it's added to token_paths.
									new_word_form=new_word.word;
								}
								new_word.tokens.clear();
							}
						}
						logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"Inserting "+last_word+" in lexer cache");
						cache.insert(std::make_pair(last_word,new_words));
					}
					else throw std::runtime_error("Got neither real nor mocked morphological analysis. Stop.");
				}
			}
			else human_input_iterator=human_input.end();//Don't let the iterator advance into infinity in case of garbage input
		}
		sentences_word_forms.insert(std::make_pair(human_input,word_forms));
	}
	else{
		word_forms=sentence_hit->second;
	}
	return word_forms;
}

std::string lexer::next_word(){
	std::string word;

	if(word_form_iterator!=word_forms_.end()) word=*(word_form_iterator++);
	return word;
}

std::vector<std::string> lexer::word_forms(){
	return word_forms_;
}

std::string lexer::work_string(){
	return human_input;
}

std::map<unsigned int,lexicon> lexer::find_main_verb(const std::vector<lexicon>& words) const{
	std::map<unsigned int,lexicon> main_verbs;
	db *sqlite=NULL;
	query_result *result=NULL;
	const std::pair<const unsigned int,field> *result_entry=NULL;

	sqlite=db_factory::get_instance();
	result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='main_symbol';");
	std::string main_symbol=*result->field_value_at_row_position(0,"value");
	delete result;
	result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='"+main_symbol+"';");
	std::string main_gcat=*result->field_value_at_row_position(0,"value");
	unsigned int index=0;
	for(auto& word:words){
		if(word.morphalytics!=NULL&&main_gcat.find("<"+word.gcat+">")!=std::string::npos){
			main_verbs.insert(std::make_pair(index,word));
		}
		++index;
	}
	return main_verbs;
}

std::map<unsigned int,lexicon> lexer::find_word_by_lexeme(const std::vector<lexicon>& words,const std::set<unsigned int>& processed_words,const std::string& lexeme){
	std::map<unsigned int,lexicon> words_found;
	unsigned int index=0;

	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"looking for word by lexeme:"+lexeme);
	for(auto& word:words){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"word:"+word.word+", lexeme:"+word.lexeme);
		if(word.lexeme==lexeme){
			words_found.insert(std::make_pair(index,word));
		}
		++index;
	}
	return words_found;
}

std::map<unsigned int,lexicon> lexer::find_word_by_gcat(const std::vector<lexicon>& words,const std::set<unsigned int>& processed_words,const std::string& gcat){
	std::map<unsigned int,lexicon> words_found;
	unsigned int index=0;

	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"looking for word by gcat:"+gcat);
	for(auto& word:words){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"word:"+word.word+", gcat:"+word.gcat);
		if(word.gcat==gcat){
			words_found.insert(std::make_pair(index,word));
		}
		++index;
	}
	return words_found;
}

std::vector<lexicon> lexer::cached_word_entries(){
	std::vector<lexicon> words;

	for(auto&& word_analyses:cache){
		for(auto&& word_analysis:word_analyses.second){
			words.push_back(word_analysis);
		}
	}
	return words;
}

std::pair<std::string,std::vector<lexicon>> lexer::copy_word_from_cache(std::string& word){
//TODO:
//-replace all private lexer cache.find() calls with this
//-review all lexer::word_analyses calls as there are cases when it's called just to call cache.find()
//-review all usage of the lexer cache either private or public to ensure that cached morphalytics instance is not used instead of the copyconstructed one
//-make sure that when the next token is requested, a lexicon with a copyconstructed morphalytics is returned

	auto cache_hit=cache.find(word);
	std::pair<std::string,std::vector<lexicon>> lexicons=*cache_hit;
	for(auto&& lexicon: lexicons.second){
		//deep copy only morphalytics for now as currently only that needs to be different
		lexicon.morphalytics=new morphan_result(*lexicon.morphalytics);
	}
	return lexicons;
}

bool lexer::is_end_token_returned(){
	return end_token_returned;
}

void lexer::end_reached(){
	end_token_returned=true;
}
