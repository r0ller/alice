#include "tokenpaths.h"

tokenpaths::tokenpaths(){
	is_any_path_left=true;
}

tokenpaths::~tokenpaths(){
}

bool tokenpaths::is_any_left(){
	return is_any_path_left;
}

lexicon tokenpaths::next_word(const std::vector<lexicon>& words){
	std::vector<lexicon> new_path;
	bool add_word,add_path_as_validated=false,add_path_as_invalidated=false;

	for(auto&& word:words){
		new_path.clear();
		new_path=this->words;
		new_path.push_back(word);
		add_word=true;
		for(auto&& invalid_path:invalid_paths){
			if(invalid_path.size()==new_path.size()){
				unsigned int nr_of_matching_words=0;
				for(auto&& new_path_word:new_path){
					if(new_path_word.word!=invalid_path.at(nr_of_matching_words).word||new_path_word.tokens!=invalid_path.at(nr_of_matching_words).tokens){
						break;
					}
					++nr_of_matching_words;
				}
				if(nr_of_matching_words==new_path.size()){
					add_word=false;
					add_path_as_invalidated=true;
					break;
				}
			}
		}
		if(add_word==true){
			for(auto&& invalid_path:internal_invalid_paths){
				if(invalid_path.size()==new_path.size()){
					unsigned int nr_of_matching_words=0;
					for(auto&& new_path_word:new_path){
						if(new_path_word.word!=invalid_path.at(nr_of_matching_words).word||new_path_word.tokens!=invalid_path.at(nr_of_matching_words).tokens){
							break;
						}
						++nr_of_matching_words;
					}
					if(nr_of_matching_words==new_path.size()){
						add_word=false;
						add_path_as_invalidated=true;
						break;
					}
				}
			}
		}
		if(add_word==true){
			for(auto&& valid_path:valid_paths){
				if(valid_path.size()==new_path.size()){
					unsigned int nr_of_matching_words=0;
					for(auto&& new_path_word:new_path){
						if(new_path_word.word!=valid_path.at(nr_of_matching_words).word||new_path_word.tokens!=valid_path.at(nr_of_matching_words).tokens){
							break;
						}
						++nr_of_matching_words;
					}
					if(nr_of_matching_words==new_path.size()){
						add_word=false;
						add_path_as_validated=true;
						break;
					}
				}
			}
		}
		if(add_word==true){
			for(auto&& valid_path:internal_valid_paths){
				if(valid_path.size()==new_path.size()){
					unsigned int nr_of_matching_words=0;
					for(auto&& new_path_word:new_path){
						if(new_path_word.word!=valid_path.at(nr_of_matching_words).word||new_path_word.tokens!=valid_path.at(nr_of_matching_words).tokens){
							break;
						}
						++nr_of_matching_words;
					}
					if(nr_of_matching_words==new_path.size()){
						add_word=false;
						add_path_as_validated=true;
						break;
					}
				}
			}
		}
		if(add_word==true){
			this->words.push_back(word);
			return word;
		}
	}
	if(add_word==false){
		if(this->words.empty()==false){
			if(add_path_as_validated==true&&add_path_as_invalidated==false){
				add_internal_valid_path(this->words);
			}
			else if(add_path_as_validated==false&&add_path_as_invalidated==true){
				add_internal_invalid_path(this->words);
			}
			else{
				throw std::runtime_error("Can't decide if token path to add is invalid or valid.");
			}
		}
		else{
			//Theoretically, this indicates that every possibility has been checked. Let's see:)
			is_any_path_left=false;
		}
		reset();
		throw invalid_token_path();
	}
}

void tokenpaths::reset(){
	words.clear();
}

void tokenpaths::validate_path(const std::vector<lexicon>& words){
	valid_paths.push_back(words);
	reset();
}

void tokenpaths::add_internal_valid_path(const std::vector<lexicon>& words){
	internal_valid_paths.push_back(words);
}

void tokenpaths::invalidate_path(const std::vector<lexicon>& words){
	invalid_paths.push_back(words);
	reset();
}

void tokenpaths::add_internal_invalid_path(const std::vector<lexicon>& words){
	invalid_paths.push_back(words);
}

std::multimap<p_m1_token_symbol_m2_counter,token_symbol> tokenpaths::followup_token(const unsigned int token){
	db *sqlite=NULL;
	query_result *result=NULL;
	std::string head_symbol, non_head_symbol, parent_symbol, gcat, feature, lid, symbol;
	std::multimap<p_m1_token_symbol_m2_counter,token_symbol> token_paths;
	std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol> lhs_rules_processed, rhs_rules_processed;

	sqlite=db_factory::get_instance();
	result=sqlite->exec_sql("SELECT * FROM GCAT WHERE TOKEN = '"+std::to_string(token)+"';");
	if(result!=NULL&&result->nr_of_result_rows()==1){
		gcat=*result->field_value_at_row_position(0,"gcat");
		feature=*result->field_value_at_row_position(0,"feature");
		lid=*result->field_value_at_row_position(0,"lid");
		symbol="t_"+lid+"_"+gcat+"_"+feature;
		std::cout<<"token symbol:"<<symbol<<std::endl;
		delete result;
	}
	else{
		throw std::runtime_error("Either there's no entry for token "+std::to_string(token)+" or there are more than one in the GCAT db table.");
	}
	result=sqlite->exec_sql("SELECT * FROM GRAMMAR WHERE HEAD_SYMBOL = '"+symbol+"' OR NON_HEAD_SYMBOL = '"+symbol+"';");
	if(result!=NULL){
		for(unsigned int i=0;i<result->nr_of_result_rows();++i){
			parent_symbol=*result->field_value_at_row_position(i,"parent_symbol");
			std::cout<<"parent symbol:"<<parent_symbol<<std::endl;
			head_symbol=*result->field_value_at_row_position(i,"head_symbol");
			std::cout<<"head symbol:"<<head_symbol<<std::endl;
			non_head_symbol=*result->field_value_at_row_position(i,"non_head_symbol");
			std::cout<<"non-head symbol:"<<non_head_symbol<<std::endl;
			lhs_rules_processed.clear();
			rhs_rules_processed.clear();
			if(head_symbol==symbol&&non_head_symbol.empty()==false){
				lhs_rules_processed.insert(std::make_tuple(parent_symbol,head_symbol,non_head_symbol));
				find_lhs_down(symbol,i,non_head_symbol,token_paths,lhs_rules_processed);
			}
			else{
				rhs_rules_processed.insert(std::make_tuple(parent_symbol,head_symbol,non_head_symbol));
				find_rhs_up(symbol,i,parent_symbol,token_paths,lhs_rules_processed,rhs_rules_processed);
			}
		}
		delete result;
	}
	else{
		throw std::runtime_error("There's no entry for the head/non-head symbol "+symbol+" in the GRAMMAR db table.");
	}
	for(auto&& i:token_paths){
		std::cout<<"anchor token:"<<i.first.first<<" anchor counter:"<<i.first.second<<" followup token:"<<i.second<<std::endl;
	}
	return token_paths;
}

void tokenpaths::find_rhs_up(const std::string& anchor_symbol, const unsigned int anchor_symbol_counter, const std::string& symbol,
		std::multimap<p_m1_token_symbol_m2_counter,token_symbol>& token_paths,
		std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>& lhs_rules_processed,
		std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>& rhs_rules_processed){
	db *sqlite=NULL;
	query_result *result=NULL;
	std::string head_symbol, non_head_symbol, parent_symbol;

	std::cout<<"find rhs up"<<std::endl;
	sqlite=db_factory::get_instance();
	result=sqlite->exec_sql("SELECT * FROM GRAMMAR WHERE HEAD_SYMBOL = '"+symbol+"' OR NON_HEAD_SYMBOL = '"+symbol+"';");
	if(result!=NULL){
		for(unsigned int i=0;i<result->nr_of_result_rows();++i){
			parent_symbol=*result->field_value_at_row_position(i,"parent_symbol");
			std::cout<<"parent symbol:"<<parent_symbol<<std::endl;
			head_symbol=*result->field_value_at_row_position(i,"head_symbol");
			std::cout<<"head symbol:"<<head_symbol<<std::endl;
			non_head_symbol=*result->field_value_at_row_position(i,"non_head_symbol");
			std::cout<<"non-head symbol:"<<non_head_symbol<<std::endl;
			if(head_symbol==symbol&&non_head_symbol.empty()==false){
				if(lhs_rules_processed.find(std::make_tuple(parent_symbol,head_symbol,non_head_symbol))==lhs_rules_processed.end()){
					lhs_rules_processed.insert(std::make_tuple(parent_symbol,head_symbol,non_head_symbol));
					find_lhs_down(anchor_symbol,anchor_symbol_counter,non_head_symbol,token_paths,lhs_rules_processed);
				}
			}
			else{
				if(rhs_rules_processed.find(std::make_tuple(parent_symbol,head_symbol,non_head_symbol))==rhs_rules_processed.end()){
					rhs_rules_processed.insert(std::make_tuple(parent_symbol,head_symbol,non_head_symbol));
					find_rhs_up(anchor_symbol,anchor_symbol_counter,parent_symbol,token_paths,lhs_rules_processed,rhs_rules_processed);
				}
			}
		}
		delete result;
	}
	else{
		throw std::runtime_error("There's no entry for the head/non-head symbol "+symbol+" in the GRAMMAR db table.");
	}
}

void tokenpaths::find_lhs_down(const std::string& anchor_symbol, const unsigned int anchor_symbol_counter, const std::string& symbol,
		std::multimap<p_m1_token_symbol_m2_counter,token_symbol>& token_paths, std::set<t_m0_parent_symbol_m1_head_symbol_m2_non_head_symbol>& lhs_rules_processed){
	db *sqlite=NULL;
	query_result *result=NULL;
	std::string head_symbol, non_head_symbol, parent_symbol;

	std::cout<<"find lhs down"<<std::endl;
	sqlite=db_factory::get_instance();
	result=sqlite->exec_sql("SELECT * FROM GRAMMAR WHERE PARENT_SYMBOL = '"+symbol+"';");
	if(result!=NULL){
		for(unsigned int i=0;i<result->nr_of_result_rows();++i){
			parent_symbol=*result->field_value_at_row_position(i,"parent_symbol");
			std::cout<<"parent symbol:"<<parent_symbol<<std::endl;
			head_symbol=*result->field_value_at_row_position(i,"head_symbol");
			std::cout<<"head symbol:"<<head_symbol<<std::endl;
			non_head_symbol=*result->field_value_at_row_position(i,"non_head_symbol");
			std::cout<<"non-head symbol:"<<non_head_symbol<<std::endl;
			if(head_symbol.empty()==false&&non_head_symbol.empty()==false){
				if(lhs_rules_processed.find(std::make_tuple(parent_symbol,head_symbol,non_head_symbol))==lhs_rules_processed.end()){
					lhs_rules_processed.insert(std::make_tuple(parent_symbol,head_symbol,non_head_symbol));
					find_lhs_down(anchor_symbol,anchor_symbol_counter,head_symbol,token_paths,lhs_rules_processed);
				}
			}
			else if(head_symbol.empty()==false&&non_head_symbol.empty()==true){
				if(lhs_rules_processed.find(std::make_tuple(parent_symbol,head_symbol,non_head_symbol))==lhs_rules_processed.end()){
					lhs_rules_processed.insert(std::make_tuple(parent_symbol,head_symbol,non_head_symbol));
					find_lhs_down(anchor_symbol,anchor_symbol_counter,head_symbol,token_paths,lhs_rules_processed);
				}
			}
			else if(head_symbol.empty()==true&&non_head_symbol.empty()==false){
				if(lhs_rules_processed.find(std::make_tuple(parent_symbol,head_symbol,non_head_symbol))==lhs_rules_processed.end()){
					lhs_rules_processed.insert(std::make_tuple(parent_symbol,head_symbol,non_head_symbol));
					find_lhs_down(anchor_symbol,anchor_symbol_counter,non_head_symbol,token_paths,lhs_rules_processed);
				}
			}
			else{
				throw std::runtime_error("There's no entry for the parent symbol "+symbol+" in the GRAMMAR db table.");
			}
		}
		delete result;
	}
	else{
		std::cout<<"token "+symbol+" found for anchor "<<anchor_symbol<<std::endl;
		token_paths.insert(std::make_pair(std::make_pair(anchor_symbol,anchor_symbol_counter),symbol));
	}
}
