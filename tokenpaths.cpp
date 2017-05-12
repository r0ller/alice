#include "tokenpaths.h"

tokenpaths::tokenpaths(){

}

tokenpaths::~tokenpaths(){

}

bool tokenpaths::is_any_left(){
	unsigned int nr_of_paths=1,nr_of_paths_covered=0;
	t_word_count *word_count=NULL;

	if(wordtoken_counter.empty()==true&&(valid_paths.empty()==false||invalid_paths.empty()==false)
		||wordtoken_counter.empty()==false&&valid_paths.empty()==true&&invalid_paths.empty()==true){
		throw std::runtime_error("Well, I'm prepared for this. Cannot handle the state of word token counter, valid and invalid token paths.");
	}
	else if(wordtoken_counter.empty()==false&&(valid_paths.empty()==false||invalid_paths.empty()==false)){
		for(std::map<std::string,unsigned int>::iterator i=wordtoken_counter.begin();i!=wordtoken_counter.end();++i){
			word_count=new t_word_count(i);
			nr_of_paths=nr_of_paths*word_count->count;
			delete word_count;
		}
		nr_of_paths_covered=valid_paths.size()+invalid_paths.size();
//		std::cout<<"nr_of_paths="<<nr_of_paths<<", nr_of_paths_covered="<<nr_of_paths_covered<<std::endl;
		if(nr_of_paths==nr_of_paths_covered) return false;
		else if(nr_of_paths_covered<nr_of_paths) return true;
		else{
			throw std::runtime_error("What!? There are more token paths covered than the total number of all paths? I quit.");
		}
	}
	else if(wordtoken_counter.empty()==true){
		return true;
	}
	else{
		throw std::runtime_error("I'm not prepared for this. Cannot handle the state of word token counter, valid and invalid token paths.");
	}
}

void tokenpaths::add_word(const lexicon& word){
	bool exists_already=false;
	unsigned int nr_of_matching_words=0;
	t_word_count *word_count=NULL;
	std::map<std::string,unsigned int>::iterator it_wordtoken_counter;

	for(auto&& i:words){
		if(i.word==word.word){
			++nr_of_matching_words;
			if(i.tokens==word.tokens){
				exists_already=true;
			}
		}
	}
	if(exists_already==false){
		words.push_back(word);
		++nr_of_matching_words;
	}
	it_wordtoken_counter=wordtoken_counter.find(word.word);
	if(it_wordtoken_counter!=wordtoken_counter.end()){
		word_count=new t_word_count(it_wordtoken_counter);
		if(word_count->count<nr_of_matching_words) word_count->count=nr_of_matching_words;
		delete word_count;
	}
	else{
		wordtoken_counter.insert(std::make_pair(word.word,1));
	}
}

lexicon tokenpaths::next_word(const std::string& word){
	lexicon word_found={};

	for(auto&& i:words){
		if(i.word==word){
			word_found=i;
			break;
		}
	}
	return word_found;
}

void tokenpaths::mark_syntax_error(const lexicon& word){
	bool exists_already=false;

	for(auto&& i:words_with_token_errors){
		if(i.word==word.word&&i.tokens==word.tokens){
			exists_already=true;
			break;
		}
	}
	if(exists_already==false){
		words_with_token_errors.push_back(word);
		for(std::vector<lexicon>::iterator i=words.begin();i!=words.end();++i){
			if(i->word==word.word&&i->tokens==word.tokens){
				words.erase(i);
				break;
			}
		}
	}
}

void tokenpaths::add_valid_path(const std::vector<lexicon>& words){
	valid_paths.push_back(words);
}

void tokenpaths::add_invalid_path(const std::vector<lexicon>& words){
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
