#include "tokenpaths.h"
#include "transgraph.h"
#include "sp.h"

tokenpaths::tokenpaths(){
	is_any_path_left=true;
}

tokenpaths::~tokenpaths(){
}

bool tokenpaths::is_any_left(){
	return is_any_path_left;
}

bool tokenpaths::is_path_already_evaluated(const std::vector<lexicon>& path_to_find, std::vector<std::vector<lexicon> >& paths){

	for(auto&& path:paths){
		if(path.size()==path_to_find.size()){
			unsigned int nr_of_matching_words=0;
			for(auto&& word_in_path_to_find:path_to_find){
				if(word_in_path_to_find.word!=path.at(nr_of_matching_words).word||word_in_path_to_find.tokens!=path.at(nr_of_matching_words).tokens){
					break;
				}
				++nr_of_matching_words;
			}
			if(nr_of_matching_words==path_to_find.size()){
				return true;
			}
		}
	}
	return false;
}

lexicon tokenpaths::next_word(const std::vector<lexicon>& words){
	std::vector<lexicon> new_path;

	for(auto&& word:words){
		new_path.clear();
		new_path=this->words;
		new_path.push_back(word);
		if(is_path_already_evaluated(new_path,valid_paths)==false&&is_path_already_evaluated(new_path,invalid_paths)==false&&is_path_already_evaluated(new_path,internal_invalid_paths)==false){
			this->words.push_back(word);
			return word;
		}
	}
	if(this->words.empty()==false){
		add_internal_invalid_path(this->words);
	}
	else{
		//That's all folks, every possibility has been checked.
		is_any_path_left=false;
	}
	reset();
	throw invalid_token_path();
}

void tokenpaths::reset(){
	words.clear();
}

void tokenpaths::validate_path(const std::vector<lexicon>& words, const transgraph* transgraph){
	valid_paths.push_back(words);
	valid_graphs.push_back(transgraph);
	reset();
}

void tokenpaths::invalidate_path(const std::vector<lexicon>& words,const std::string& reason,std::exception *exception){
	std::string last_word,validated_words,error;

	invalid_paths.push_back(words);
//	std::cout<<"yychar="<<yychar<<std::endl;
//	std::cout<<"last_word_scanned().token="<<lex->last_word_scanned().token<<std::endl;
//	std::cout<<"last_token_returned()="<<lex->last_token_returned()<<std::endl;
	std::set<unsigned int> validated_terminals;
	validated_terminals=sparser->validated_terminals();
//	if(yychar!=YYEMPTY&&yychar!=YYEOF&&validated_terminals.find(yychar)!=validated_terminals.end()){
//		std::cout<<"yychar found in validated terminals!"<<std::endl;
//	}
//	else if(yychar!=YYEMPTY&&yychar!=YYEOF&&validated_terminals.find(yychar)==validated_terminals.end()){
//		std::cout<<"yychar NOT found in validated terminals!"<<std::endl;
//	}
//	else std::cout<<"yychar is empty or 0"<<std::endl;

//	if(validated_terminals.find(lex->last_token_returned())!=validated_terminals.end()){
//		std::cout<<"last token found in validated terminals!"<<std::endl;
//	}
//	else{
//		std::cout<<"last token NOT found in validated terminals!"<<std::endl;
//	}
//	if(lex->nr_of_words()==1&&lex->last_word_scanned().token==lex->last_token_returned()){
//	}
//	TODO: find out which token should be passed to the followup_token() call in which case (see experimenting if-else cases above for printing out the error token
//	followup_token(lex->last_token_returned());

	if(reason=="syntax error"||reason=="semantic error"){
		validated_words=lex->validated_words();
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"processed words:"+validated_words);
		if(lex->last_word_scanned().morphalytics!=NULL&&lex->last_word_scanned().morphalytics->is_mocked()==false)
			last_word=lex->last_word_scanned().morphalytics->word();
		else last_word=lex->last_word_scanned().word;
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"FALSE: error at "+last_word);
		error="{\"source\":\"hi\",";
		error+="\"type\":\""+reason+"\",";
		if(validated_words.empty()==false){
			error+="\"processed\":\""+validated_words+"\","+"\"last word\":\""+last_word+"\"";
		}
		else{
			error+="\"last word\":\""+last_word+"\"";
		}
		if(exception!=NULL){
			error+=",\"message\":\""+std::string(exception->what())+"\"";
		}
		error+="}";
	}
	else if(reason=="invalid combination"){
		error="{\"source\":\"hi\",";
		error+="\"type\":\""+reason+"\",";
		if(validated_words.empty()==false){
			error+="\"processed\":\""+validated_words+"\","+"\"failed\":\""+static_cast<invalid_combination *>(exception)->get_left()+" "+static_cast<invalid_combination *>(exception)->get_right()+"\"";
		}
		else{
			error+="\"failed\":\""+static_cast<invalid_combination *>(exception)->get_left()+" "+static_cast<invalid_combination *>(exception)->get_right()+"\"";
		}
		error+="}";
	}
	else{

	}

	if(yyerror.empty()==false){
		error+=",{\"source\":\"bison\",";
		error+="\"type\":\"syntax error\",";
		error+="\"message\":\""+yyerror+"\"}";
		yyerror.clear();
	}
	invalid_path_errors.push_back(error);
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
	auto&& token_symbol_map_entry=token_symbol_map.find(token);
	if(token_symbol_map_entry!=token_symbol_map.end()){
		if(gcat=="CON")	symbol="t_Con";
		else symbol=token_symbol_map_entry->second;
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token symbol:"+symbol);
		delete result;
	}
	else{
		throw std::runtime_error("No symbol found for token: "+std::to_string(token));
	}
	result=sqlite->exec_sql("SELECT * FROM GRAMMAR WHERE LID = '"+lex->language()+"' AND ( HEAD_SYMBOL = '"+symbol+"' OR NON_HEAD_SYMBOL = '"+symbol+"' );");
	if(result!=NULL){
		for(unsigned int i=0;i<result->nr_of_result_rows();++i){
			parent_symbol=*result->field_value_at_row_position(i,"parent_symbol");
			head_symbol=*result->field_value_at_row_position(i,"head_symbol");
			non_head_symbol=*result->field_value_at_row_position(i,"non_head_symbol");
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,parent_symbol+" "+head_symbol+" "+non_head_symbol);
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
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"anchor token:"+i.first.first+" anchor counter:"+std::to_string(i.first.second)+" followup token:"+i.second);
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

	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"find rhs up");
	sqlite=db_factory::get_instance();
	result=sqlite->exec_sql("SELECT * FROM GRAMMAR WHERE LID = '"+lex->language()+"' AND ( HEAD_SYMBOL = '"+symbol+"' OR NON_HEAD_SYMBOL = '"+symbol+"' );");
	if(result!=NULL){
		for(unsigned int i=0;i<result->nr_of_result_rows();++i){
			parent_symbol=*result->field_value_at_row_position(i,"parent_symbol");
			head_symbol=*result->field_value_at_row_position(i,"head_symbol");
			non_head_symbol=*result->field_value_at_row_position(i,"non_head_symbol");
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,parent_symbol+" "+head_symbol+" "+non_head_symbol);
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
	else if(symbol=="S"){
		if(lhs_rules_processed.find(std::make_tuple(parent_symbol,head_symbol,non_head_symbol))==lhs_rules_processed.end()){
			lhs_rules_processed.insert(std::make_tuple(parent_symbol,head_symbol,non_head_symbol));
			find_lhs_down(anchor_symbol,anchor_symbol_counter,symbol,token_paths,lhs_rules_processed);
		}
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

	logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"find lhs down");
	sqlite=db_factory::get_instance();
	result=sqlite->exec_sql("SELECT * FROM GRAMMAR WHERE LID = '"+lex->language()+"' AND PARENT_SYMBOL = '"+symbol+"';");
	if(result!=NULL){
		for(unsigned int i=0;i<result->nr_of_result_rows();++i){
			parent_symbol=*result->field_value_at_row_position(i,"parent_symbol");
			head_symbol=*result->field_value_at_row_position(i,"head_symbol");
			non_head_symbol=*result->field_value_at_row_position(i,"non_head_symbol");
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,parent_symbol+" "+head_symbol+" "+non_head_symbol);
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
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"token "+symbol+" found for anchor "+anchor_symbol);
		token_paths.insert(std::make_pair(std::make_pair(anchor_symbol,anchor_symbol_counter),symbol));
	}
}

std::string tokenpaths::semantics(std::vector<lexicon>& word_analyses, std::map<std::string,std::string>& functors, unsigned int& id_index, const std::string& target_language){
	const std::pair<const unsigned int,field> *rowid_field=NULL;
	std::string transcript;
	std::string functor;

	for(auto&& word:word_analyses){
		if(word.dependencies!=NULL){
			if(word.lexicon_entry==true){
				functor=word.lexeme;
			}
			else{
				functor=word.gcat;
			}
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"transpiling functor "+functor);
			unsigned int prev_dkey=0;
			rowid_field=word.dependencies->first_value_for_field_name_found("lexeme",functor);
			while(rowid_field!=NULL){
				unsigned int d_key=std::atoi(word.dependencies->field_value_at_row_position(rowid_field->first,"d_key")->c_str());
				if(d_key!=prev_dkey){
					prev_dkey=d_key;
					if(word.gcat=="CON"){
						const std::pair<std::string,unsigned int> functor_dkey=std::make_pair(word.lexeme,d_key);
						transgraph *graph=new transgraph(std::string(),functor_dkey,word.morphalytics);
						id_index=std::atoi(graph->id().c_str());
						transcript+=graph->transcript(functors,target_language);
					}
					else{
						const std::pair<std::string,unsigned int> functor_dkey=std::make_pair(functor,d_key);
						transgraph *graph=new transgraph(std::string(),functor_dkey,word.morphalytics);
						id_index=std::atoi(graph->id().c_str());
						transcript+=graph->transcript(functors,target_language);
					}
				}
				rowid_field=word.dependencies->value_for_field_name_found_after_row_position(rowid_field->first,"lexeme",functor);
			}
		}
		else{//transpile also words having only morphalytics but no depolex entries
			functor=word.lexeme;//this is the stem in such cases
			unsigned int d_key=0;//0 is anyway not allowed, smallest value allowed is 1
			const std::pair<std::string,unsigned int> functor_dkey=std::make_pair(functor,d_key);
			transgraph *graph=new transgraph(std::string(),functor_dkey,word.morphalytics);
			id_index=std::atoi(graph->id().c_str());
			transcript+=graph->transcript(functors,target_language);
		}
	}
	return transcript;
}

std::string tokenpaths::morphology(std::vector<lexicon>& word_analyses){
	std::string morphology;

	for(auto&& word:word_analyses){
		morphology+="{\"morpheme id\":\""+std::to_string(word.morphalytics->id())+"\",";
		morphology+="\"word\":\""+word.morphalytics->word()+"\",";
		morphology+="\"stem\":\""+word.morphalytics->stem()+"\",";
		morphology+="\"gcat\":\""+word.morphalytics->gcat()+"\"";
		if(word.morphalytics->is_mocked()==false){
			morphology+=",\"tags\":[";
			unsigned int morphan_index=0;
			for(auto&& i:word.morphalytics->morphemes()){
				morphology+="\""+i+"\",";
				++morphan_index;
			}
			if(morphology.back()==',') morphology.pop_back();
			morphology+="]";
		}
		morphology+="},";
	}
	return morphology;
}

std::string tokenpaths::dependencies(query_result& dependency,std::map<std::pair<std::string,std::string>,std::string>& functor_dkey_id_of_dependencies){
	std::string dependencies;

	db *sqlite=db_factory::get_instance();
	for(unsigned int i=0;i<dependency.nr_of_result_rows();++i){
		const std::string lexeme=*dependency.field_value_at_row_position(i,"lexeme");
		const std::string d_key=*dependency.field_value_at_row_position(i,"d_key");
		dependencies+="{\"functor\":\""+lexeme+"\",";
		dependencies+="\"d_key\":\""+d_key+"\",";
		dependencies+="\"d_counter\":\""+*dependency.field_value_at_row_position(i,"d_counter")+"\",";
		dependencies+="\"optional_parent_allowed\":\""+*dependency.field_value_at_row_position(i,"optional_parent_allowed")+"\",";
		dependencies+="\"d_failover\":\""+*dependency.field_value_at_row_position(i,"d_failover")+"\",";
		dependencies+="\"d_successor\":\""+*dependency.field_value_at_row_position(i,"d_successor")+"\",";
		dependencies+="\"manner\":\""+*dependency.field_value_at_row_position(i,"manner")+"\",";
		dependencies+="\"semantic_dependency\":\""+*dependency.field_value_at_row_position(i,"semantic_dependency")+"\",";
		dependencies+="\"ref_d_key\":\""+*dependency.field_value_at_row_position(i,"ref_d_key")+"\"},";
		query_result *functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+lexeme+"' AND D_KEY ='"+d_key+"';");
		if(functor_id_entry==NULL){
			throw std::runtime_error("No entries found for functor "+lexeme+" and d_key "+d_key+" in FUNCTORS db table.");
		}
		const std::string functor_id=*functor_id_entry->field_value_at_row_position(0,"functor_id");
		if(functor_id.empty()==false){
			functor_dkey_id_of_dependencies.insert(std::make_pair(std::make_pair(lexeme,d_key),functor_id));
		}
	}
	return dependencies;
}

std::string tokenpaths::functors(const std::map<std::string,std::map<std::string,std::string> >& functors_of_words,const std::map<std::string,std::vector<lexicon> >& words_analyses,const unsigned int& id_index,std::string& related_semantics){
	std::set<std::string> functor_ids_of_words,functor_ids_of_dependencies;
	std::map<std::pair<std::string,std::string>,std::string> functor_dkey_id_of_dependencies;
	std::string functors;
	std::vector<std::pair<std::pair<std::string,std::string>,std::string> > functor_dkey_ids;

	for(auto&& word_functors:functors_of_words){
		std::set<query_result *> functor_dependencies;
		auto word_analyses=words_analyses.find(word_functors.first);
		for(auto&& word:word_analyses->second){
			if(word.dependencies!=NULL)	functor_dependencies.insert(word.dependencies);
		}
		for(auto&& functor:word_functors.second){
			auto&& functor_inserted=functor_ids_of_words.insert(functor.first);
			if(functor_inserted.second==true){
				functors+="{";
				functors+="\"functor id\":\""+functor.first+"\",";
				functors+="\"definition\":\""+functor.second+"\"";
				if(functor_dependencies.empty()==false){
					functors+=",\"dependencies\":[";
					for(auto&& dependency:functor_dependencies){
						functors+=dependencies(*dependency,functor_dkey_id_of_dependencies);
					}
					if(functors.back()==',') functors.pop_back();
					functors+="]";
				}
				functors+="},";
			}
		}
	}
	for(auto&& functor:functor_dkey_id_of_dependencies){
		//convert the map into a vector so that new elements can be added
		//to the end of it while iterating over itself
		functor_dkey_ids.push_back(functor);
	}
	unsigned int id=id_index;
	db *sqlite=db_factory::get_instance();
	for(unsigned int i=0;i<functor_dkey_ids.size();++i){
		auto functor=functor_dkey_ids[i];//keep this variable as copy, as reference it'd get invalidated due to the functor_dkey_ids.push_back() within the loop
		if(functor_ids_of_words.find(functor.second)==functor_ids_of_words.end()
			&&functor_ids_of_dependencies.find(functor.second)==functor_ids_of_dependencies.end()){
			functor_ids_of_dependencies.insert(functor.second);
			query_result *functor_def_entry=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS WHERE FUNCTOR_ID = '"+functor.second+"';");
			if(functor_def_entry==NULL){
				throw std::runtime_error("No entries found for functor id "+functor.second+" in FUNCTOR_DEFS db table.");
			}
			const std::string functor_def=*functor_def_entry->field_value_at_row_position(0,"definition");
			functors+="{";
			functors+="\"functor id\":\""+functor.second+"\",";
			functors+="\"definition\":\""+transgraph::apply_json_escapes(functor_def)+"\"";
			query_result *functor_dependencies=lexer::dependencies_read_for_functor(functor.first.first);
			if(functor_dependencies!=NULL){
				functors+=",\"dependencies\":[";
				std::map<std::pair<std::string,std::string>,std::string> new_functor_dkeys_ids;
				functors+=dependencies(*functor_dependencies,new_functor_dkeys_ids);
				for(auto&& new_functor:new_functor_dkeys_ids){
					if(functor_ids_of_words.find(new_functor.second)==functor_ids_of_words.end()
						&&functor_ids_of_dependencies.find(new_functor.second)==functor_ids_of_dependencies.end()){
						functor_dkey_ids.push_back(new_functor);
					}
				}
				if(functors.back()==',') functors.pop_back();
				functors+="]";
			}
			functors+="},";
			++id;
			related_semantics+="{";
			related_semantics+="\"id\":\""+std::to_string(id)+"\",";
			related_semantics+="\"functor\":\""+functor.first.first+"\",";
			related_semantics+="\"d_key\":\""+functor.first.second+"\",";
			related_semantics+="\"functor id\":\""+functor.second+"\"";
			related_semantics+="},";
		}
	}
	return functors;
}

std::string tokenpaths::create_analysis(const unsigned char& toa,const std::string& target_language){
	std::map<std::string,std::string> related_functors;
	std::map<std::string,std::map<std::string,std::string> > functors_of_words;

	unsigned int nr_of_analyses=valid_paths.size();
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"There are "+std::to_string(nr_of_analyses)+" analyses.");
	std::string analysis="{\"analyses\":[";
	if(nr_of_analyses==0){
		analysis+="{";
		std::map<std::string,std::vector<lexicon> > words_analyses=lexer::words_analyses();
		if(toa&HI_MORPHOLOGY){
			analysis+="\"morphology\":[";
			for(auto&& word_analyses:words_analyses){
				analysis+=morphology(word_analyses.second);
			}
			if(analysis.back()==',') analysis.pop_back();
			analysis+="],";
		}
		if(toa&HI_SYNTAX){
			analysis+="\"syntax\":[";
			analysis+="],";
		}
		if(toa&HI_SEMANTICS){
			std::string semantic_analysis="\"semantics\":[";
			std::vector<std::string> word_forms=lexer::word_forms();
			unsigned int id_index=0;
			for(auto&& word_form:word_forms){
				auto&& word_analyses=words_analyses.find(word_form);
				related_functors.clear();
				semantic_analysis+=semantics(word_analyses->second,related_functors,id_index,target_language);
				functors_of_words.insert(std::make_pair(word_analyses->first,related_functors));
			}
			if(semantic_analysis.back()==',') semantic_analysis.pop_back();
			semantic_analysis+="],";
			std::string functor_analysis="\"functors\":[";
			std::string related_semantics="\"related semantics\":[";
			functor_analysis+=functors(functors_of_words,words_analyses,id_index,related_semantics);
			if(functor_analysis.back()==',') functor_analysis.pop_back();
			functor_analysis+="],";
			if(related_semantics.back()==',') related_semantics.pop_back();
			related_semantics+="],";
			analysis+=semantic_analysis;
			analysis+=related_semantics;
			analysis+=functor_analysis;
		}
		if(invalid_path_errors.empty()==false){
			analysis+="\"errors\":[";
			unsigned int id=0;
			for(auto&& error:invalid_path_errors){
				analysis+="{\"tokenpath id\":\""+std::to_string(++id)+"\",\"messages\":["+error+"]},";
			}
			if(analysis.back()==',') analysis.pop_back();
			analysis+="]";
		}
		if(analysis.back()==',') analysis.pop_back();
		analysis+="}";
	}
	else{
		for(unsigned int i=0;i<nr_of_analyses;++i){
			related_functors.clear();
			analysis+="{";
			if(toa&HI_MORPHOLOGY){
				analysis+="\"morphology\":["+morphology(valid_paths.at(i));
				if(analysis.back()==',') analysis.pop_back();
				analysis+="],";
			}
			if(toa&HI_SYNTAX){
				analysis+="\"syntax\":[";
				analysis+=syntax(valid_parse_trees.at(i));
				analysis+="],";
			}
			if(toa&HI_SEMANTICS){
				analysis+="\"semantics\":["+valid_graphs.at(i)->transcript(related_functors,target_language);
				if(analysis.back()==',') analysis.pop_back();
				analysis+="],";
				analysis+="\"functors\":[";
				for(auto&& functor:related_functors){
					analysis+="{";
					analysis+="\"functor id\":\""+functor.first+"\",";
					analysis+="\"definition\":\""+functor.second+"\"";
					analysis+="},";
				}
				if(analysis.back()==',') analysis.pop_back();
				analysis+="]";
			}
			if(analysis.back()==',') analysis.pop_back();
			analysis+="},";
		}
		if(analysis.back()==',') analysis.pop_back();
	}
	analysis+="]}";
	return analysis;
}

std::string tokenpaths::syntax(const std::vector<node_info>& nodes){

	const node_info& root=nodes.back();
	std::string syntax=traverse_nodes_lr(root,nodes);
	return syntax;
}

std::string tokenpaths::traverse_nodes_lr(const node_info& root_node, const std::vector<node_info>& nodes){

	std::string syntax="{\"symbol\":\""+root_node.symbol+"\"";
	if(root_node.left_child==0&&root_node.right_child==0){
		if(root_node.expression.morphalytics!=NULL) syntax+=",\"morpheme id\":\""+std::to_string(root_node.expression.morphalytics->id())+"\"";
		syntax+="}";
		return syntax;
	}
	syntax+=",\"left child\":";
	if(root_node.left_child!=0) syntax+=traverse_nodes_lr(nodes.at(root_node.left_child-1),nodes);
	else syntax+="{}";
	syntax+=",\"right child\":";
	if(root_node.right_child!=0) syntax+=traverse_nodes_lr(nodes.at(root_node.right_child-1),nodes);
	else syntax+="{}";
	syntax+="}";
	return syntax;
}

void tokenpaths::log_yyerror(const std::string& error){
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"bison:"+error);
	yyerror=error;
}

void tokenpaths::validate_parse_tree(const std::vector<node_info>& nodes){
	valid_parse_trees.push_back(nodes);
}

void tokenpaths::invalidate_parse_tree(const std::vector<node_info>& nodes){
	invalid_parse_trees.push_back(nodes);
}
