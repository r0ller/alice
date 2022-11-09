#include "logger.h"
#include "tokenpaths.h"
#include "hi_constants.h"
#include "sp.h"

extern interpreter *sparser;
extern std::map<std::string, unsigned int> symbol_token_map;
extern std::map<unsigned int,std::string> token_symbol_map;

tokenpaths::tokenpaths(const unsigned char toa){
    this->toa=toa;
	lex=NULL;
	is_any_path_left=true;
	path_nr_to_start_at=0;
	current_path_nr=0;
	path_nr_to_stop_at=0;
}

tokenpaths::tokenpaths(const unsigned int start,const unsigned int stop){
    toa=0;
    lex=NULL;
	is_any_path_left=true;
	path_nr_to_start_at=start;
	current_path_nr=start;
	path_nr_to_stop_at=stop;
}

tokenpaths::~tokenpaths(){
    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"destructing tokenpaths");
}

std::vector<unsigned short int> tokenpaths::path_nr_to_indices(const unsigned int path_nr){
	std::vector<unsigned short int> indices;

	unsigned int rem_path_nr=path_nr;
	std::vector<std::string> word_forms=lex->word_forms();
	for(int i=0;i<word_forms.size();++i){
		indices.push_back(0);
	}
	//base of nth position is the size of the nth array
	//[1,2] [3,4,5] [6,7] -> bases: 2, 3, 2
	//value = 5 -> indices = [0, 2, 1] -> evaluates to: 157
	//136 137 146 147 156 >157< 5th position
	//236 237 246 247 256 257
	for(int i=word_forms.size()-1;i>=0;--i){
		auto words_at_index=lexer::words_analyses().find(word_forms[i])->second;
		indices[i]=rem_path_nr%words_at_index.size();
		//std::cout<<"word form:"<<word_forms[i]<<",rem_path_nr:"<<rem_path_nr<<",words_at_index:"<<words_at_index.size()<<",indices[i]:"<<indices[i]<<std::endl;
		rem_path_nr/=words_at_index.size();
		//std::cout<<"new rem_path_nr:"<<rem_path_nr<<std::endl;
		if(rem_path_nr==0){
			break;
		}
	}
	return indices;
}

bool tokenpaths::is_any_left(){
	return is_any_path_left;
}

lexicon tokenpaths::next_word(const std::vector<lexicon>& words){

	if(is_any_path_left==true){
		//std::cout<<"this->words.size:"<<this->words.size()<<",path_indices.size:"<<path_indices.size()<<",words.size:"<<words.size()<<std::endl;
		//std::cout<<"path_indices[this->words.size()]:"<<path_indices[this->words.size()]<<std::endl;
		lexicon word=words[path_indices[this->words.size()]];
		this->words.push_back(word);
		return word;
	}
	else{
		throw invalid_token_path();
	}
}

void tokenpaths::reset(){
	words.clear();
}

void tokenpaths::validate_path(const std::vector<lexicon>& words, const transgraph* transgraph, const bool store){
	//TODO:check why words are accepted from outside when the instance anyway has its own words attribute
	if(is_any_path_left==true&&words.size()==path_indices.size()){
		if(current_path_nr<path_nr_to_stop_at){
			++current_path_nr;
			if(current_path_nr==path_nr_to_stop_at) is_any_path_left=false;
			if(store==true){
				valid_paths.push_back(words);
				valid_graphs.push_back(transgraph);
                valid_graphs_node_functor_maps.push_back(transgraph::node_functor_map());
			}
			reset();
		}
	}
}

void tokenpaths::validate_path_wo_checks(const std::vector<lexicon>& words, const transgraph* transgraph){
    //TODO:check why words are accepted from outside when the instance anyway has its own words attribute
    valid_paths.push_back(words);
    valid_graphs.push_back(transgraph);
    valid_graphs_node_functor_maps.push_back(transgraph::node_functor_map());
    reset();
}

void tokenpaths::invalidate_path(const std::vector<lexicon>& words,const std::string& reason,std::exception *exception){
	std::string last_word,validated_words,error;

//	if(is_any_path_left==true&&words.size()==path_indices.size()){ //<--This condition did NOT work out, figure out something else to prevent unnecessary calls from having an effect
		if(current_path_nr<path_nr_to_stop_at){
			++current_path_nr;
			if(current_path_nr==path_nr_to_stop_at) is_any_path_left=false;
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
                if(toa&HI_SYNTAX){
                    validated_words=lex->validated_words();
                    logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"processed words:"+validated_words);
                    if(lex->last_word_scanned().morphalytics!=NULL&&lex->last_word_scanned().morphalytics->is_mocked()==false)
                        last_word=lex->last_word_scanned().morphalytics->word();
                    else last_word=lex->last_word_scanned().word;
                }
                else if(toa&HI_SEMANTICS){
                    last_word=words[0].word;
                }
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
		else{
		//TODO: figure out what to do here: throw exception like runtime error or logic error? if exception at all...
		}
//	}
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
            std::vector<std::tuple<unsigned int,std::string,std::string,unsigned int,unsigned int,std::string,unsigned int,std::string,std::string>> dependency_path;
            while(rowid_field!=NULL){
				unsigned int d_key=std::atoi(word.dependencies->field_value_at_row_position(rowid_field->first,"d_key")->c_str());
				if(d_key!=prev_dkey){
					prev_dkey=d_key;
					if(word.gcat=="CON"){
						const std::pair<std::string,unsigned int> functor_dkey=std::make_pair(word.lexeme,d_key);
						transgraph *graph=new transgraph(std::string(),functor_dkey,word.morphalytics);
						id_index=std::atoi(graph->id().c_str());
                        std::map<unsigned int,std::pair<std::string,unsigned int>> node_functor_map;
                        transcript+=graph->transcript(functors,node_functor_map,target_language,dependency_path);
					}
					else{
						const std::pair<std::string,unsigned int> functor_dkey=std::make_pair(functor,d_key);
						transgraph *graph=new transgraph(std::string(),functor_dkey,word.morphalytics);
						id_index=std::atoi(graph->id().c_str());
                        std::map<unsigned int,std::pair<std::string,unsigned int>> node_functor_map;
                        transcript+=graph->transcript(functors,node_functor_map,target_language,dependency_path);
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
            std::map<unsigned int,std::pair<std::string,unsigned int>> node_functor_map;
            std::vector<std::tuple<unsigned int,std::string,std::string,unsigned int,unsigned int,std::string,unsigned int,std::string,std::string>> dependency_path;
            transcript+=graph->transcript(functors,node_functor_map,target_language,dependency_path);
		}
	}
	return transcript;
}

std::string tokenpaths::morphology(std::vector<lexicon>& word_analyses,unsigned int& nr_of_cons){
	std::string morphology;

    nr_of_cons=0;
	for(auto&& word:word_analyses){
		morphology+="{\"morpheme id\":\""+std::to_string(word.morphalytics->id())+"\",";
		morphology+="\"word\":\""+word.morphalytics->word()+"\",";
        morphology+="\"lexeme\":\""+word.lexeme+"\",";
        morphology+="\"stem\":\""+word.morphalytics->stem()+"\",";
		morphology+="\"gcat\":\""+word.morphalytics->gcat()+"\"";
        if(word.morphalytics->gcat()=="CON") ++nr_of_cons;
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
		query_result *functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+sqlite->escape(lexeme)+"' AND D_KEY ='"+d_key+"';");
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

std::string tokenpaths::create_analysis(const unsigned char& toa,const std::string& language,const std::string& target_language,const std::string& sentence,const std::time_t& timestamp,const std::string& source){
	std::map<std::string,std::string> related_functors;
	std::map<std::string,std::map<std::string,std::string> > functors_of_words;
    std::multimap<unsigned int,std::string> ranked_analyses_map;
    db *sqlite=NULL;
    std::string analysis;
    unsigned int nr_of_cons=0;

    sqlite=db_factory::get_instance();
    unsigned int nr_of_analyses=valid_paths.size();
	if(nr_of_analyses==0&&toa==HI_MORPHOLOGY){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"There is 1 analysis.");
	}
	else{
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"There are "+std::to_string(nr_of_analyses)+" analyses.");
	}
    if(nr_of_analyses==0){
        analysis="{";
        std::map<std::string,std::vector<lexicon> > words_analyses=lexer::words_analyses();
        if(toa&HI_MORPHOLOGY){
			analysis+="\"morphology\":[";
			for(auto&& word_analyses:words_analyses){
                analysis+=morphology(word_analyses.second,nr_of_cons);
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
			std::vector<std::string> word_forms=lexer::word_forms(sentence);
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
        sqlite->exec_sql("INSERT INTO FAILED_ANALYSES VALUES('"+source+"','"+std::to_string(timestamp)+"','"+sqlite->escape(sentence)+"','"+sqlite->escape(analysis)+"');");
    }
    else{
		for(unsigned int i=0;i<nr_of_analyses;++i){
			related_functors.clear();
            analysis="{";
			if(toa&HI_MORPHOLOGY){
                analysis+="\"morphology\":["+morphology(valid_paths.at(i),nr_of_cons);
				if(analysis.back()==',') analysis.pop_back();
				analysis+="],";
			}
			if(toa&HI_SYNTAX){
				//TODO: features added at syntactic level (like main_verb) do not appear in the analyses.
				//Features added at syntactic level should be recorded in the corresponding node which
				//requires turning the nodeinfo struct into a class finally. (That should be done to
				//the lexicon struct along with that as well.) Once that's done, a corresponding
				//method shall be added and the method interpreter::add_feature_to_leaf() shall
				//be changed to call that newly added method to add a feature to the leaf node instead of calling
				//morphan_result::add_feature(). However, the way how interpreter::get_nodes_by_symbol() looks for
				//nodes needs to be considered carefully before changing anything.
				//After all those changes, the features added at syntactic level shall be extracted
				//in tokenpaths::syntax().
				analysis+="\"syntax\":[";
				analysis+=syntax(valid_parse_trees.at(i));
				analysis+="],";
			}
            std::vector<std::tuple<unsigned int,std::string,std::string,unsigned int,unsigned int,std::string,unsigned int,std::string,std::string>> dependency_path;
			if(toa&HI_SEMANTICS){
                analysis+="\"semantics\":["+valid_graphs.at(i)->transcript(related_functors,valid_graphs_node_functor_maps[i],target_language,dependency_path);
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
                analysis+="],";
			}
            //preparing to collect data for jsemantics
            std::map<unsigned int,std::string> global_features=morphan_result::global_features();
            query_result *result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='indicative_mood_tag' OR key='interrogative_mood_tag' OR key='imperative_mood_tag';");
            if(result!=NULL){
                std::string indicative_mood_tag;
                const std::pair<const unsigned int,field> *mood_tag=result->first_value_for_field_name_found("key","indicative_mood_tag");
                if(mood_tag!=NULL){
                    indicative_mood_tag=*result->field_value_at_row_position(mood_tag->first,"value");
                }
                std::string interrogative_mood_tag;
                mood_tag=result->first_value_for_field_name_found("key","interrogative_mood_tag");
                if(mood_tag!=NULL){
                    interrogative_mood_tag=*result->field_value_at_row_position(mood_tag->first,"value");
                }
                std::string imperative_mood_tag;
                mood_tag=result->first_value_for_field_name_found("key","imperative_mood_tag");
                if(mood_tag!=NULL){
                    imperative_mood_tag=*result->field_value_at_row_position(mood_tag->first,"value");
                }
                std::string mood;
                for(auto&& feature:global_features){
                    if(feature.second==indicative_mood_tag||feature.second==interrogative_mood_tag||feature.second==imperative_mood_tag){
                        mood=feature.second;
                        break;
                    }
                }
                if(mood.empty()==false){
                    std::string analyses_deps="\"analysis_deps\":[";
                    for(unsigned int j=0;j<dependency_path.size();++j){
                        analyses_deps+="{\"source\":\""+source+"\",";
                        analyses_deps+="\"timestamp\":"+std::to_string(timestamp)+",";
                        analyses_deps+="\"sentence\":\""+transgraph::apply_json_escapes(sentence)+"\",";
                        analyses_deps+="\"rank\":"+std::to_string(nr_of_cons)+",";
                        analyses_deps+="\"a_counter\":"+std::to_string(i+1)+",";
                        analyses_deps+="\"mood\":\""+mood+"\",";
                        analyses_deps+="\"function\":\""+std::get<8>(dependency_path[j])+"\",";
                        analyses_deps+="\"counter\":"+std::to_string(j)+",";
                        analyses_deps+="\"level\":"+std::to_string(std::get<0>(dependency_path[j]))+",";
                        analyses_deps+="\"word\":\""+std::get<1>(dependency_path[j])+"\",";
                        analyses_deps+="\"lexeme\":\""+std::get<2>(dependency_path[j])+"\",";
                        analyses_deps+="\"d_key\":"+std::to_string(std::get<3>(dependency_path[j]))+",";
                        analyses_deps+="\"d_counter\":"+std::to_string(std::get<4>(dependency_path[j]))+",";
                        analyses_deps+="\"dependency\":\""+std::get<5>(dependency_path[j])+"\",";
                        analyses_deps+="\"ref_d_key\":"+std::to_string(std::get<6>(dependency_path[j]))+",";
                        analyses_deps+="\"tags\":\""+transgraph::apply_json_escapes(std::get<7>(dependency_path[j]))+"\"},";
                        sqlite->exec_sql("INSERT INTO ANALYSES_DEPS VALUES('"+source
                            +"','"+std::to_string(timestamp)
                            +"','"+sqlite->escape(sentence)
                            +"','"+std::to_string(nr_of_cons)//rank
                            +"','"+std::to_string(i+1)//a_counter
                            +"','"+mood
                            +"','"+std::get<8>(dependency_path[j])//function
                            +"','"+std::to_string(j)//counter
                            +"','"+std::to_string(std::get<0>(dependency_path[j]))//level
                            +"','"+std::get<1>(dependency_path[j])//word
                            +"','"+std::get<2>(dependency_path[j])//lexeme
                            +"','"+std::to_string(std::get<3>(dependency_path[j]))//d_key
                            +"','"+std::to_string(std::get<4>(dependency_path[j]))//d_counter
                            +"','"+std::get<5>(dependency_path[j])//dependency
                            +"','"+std::to_string(std::get<6>(dependency_path[j]))//ref_d_key
                            +"','"+std::get<7>(dependency_path[j])//tags
                            +"',''"//c_value: no calculated value can be supplied here
                            +");");
                    }
                    if(analyses_deps.back()==',') analyses_deps.pop_back();
                    analyses_deps+="]";
                    analysis+=analyses_deps;
                }
            }
            if(analysis.back()==',') analysis.pop_back();
            analysis+="}";
            ranked_analyses_map.insert(std::make_pair(nr_of_cons,analysis));
            sqlite->exec_sql("INSERT INTO ANALYSES VALUES('"+source+"','"+std::to_string(timestamp)+"','"+sqlite->escape(sentence)+"','"+std::to_string(nr_of_cons)+"','"+std::to_string(i+1)+"','"+sqlite->escape(analysis)+"');");
        }
        analysis="{\"analyses\":[";
        for(auto&& i:ranked_analyses_map){
            analysis+=i.second+",";
        }
        if(analysis.back()==',') analysis.pop_back();
        analysis+="]}";
	}
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

void tokenpaths::assign_lexer(lexer *lex){
    this->lex=lex;
	if(path_nr_to_stop_at==0) path_nr_to_stop_at=lexer::nr_of_paths(lex->work_string());
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"current_path_nr:"+std::to_string(current_path_nr));
	path_indices=path_nr_to_indices(current_path_nr);
}

std::string tokenpaths::add_context_reference_word(const unsigned char& crh){
    //TODO: Consider moving this and the related methods to the interpreter class.
    //The current implementation is not token path based which means that we try to figure out the one and only correct
    //morphological analysis for the verb which is impossible. At least, the "longest match" algorithm used in case of
    //syntactic and semantic analyses does not always provide the correct result in case of morphological analyses.
    //So it should be changed in a way that the dependency semantics algorithm gets executed for each token paths.
    //1. rank analyses in create_analysis(), store the successful and the failed analyses in different db tables
    //2. check if the returned analyses has the 'errors' property
    //3. if there's no error, return the ranked analyses
    //4. if there's an error but there's a main verb, call build_dependency_semantics()
    //5. if there's an error and no verb, look up the main verbs in the previous analyses. The mandatory dependencies
    //   of the verb finally chosen shall match the MOST of the lexemes of the human input i.e. the verb having the most
    //   mandatory dependencies matching most of the lexemes wins. Besides that if there are mandatory dependencies that are missing,
    //   check if they belong to the verb (like a prefix) and copy the corresponding word(s) of the missing dependencies
    //   together with the verb to construct a new (syntactically incorrect) sentence.
    //   However, it's not sure if it makes sense to check earlier utterances than the latest one.
    //6. start over the interpreter with the newly constructed sentence but this newly triggered interpretation
    //   shall be marked as autocorrected sentence interpretation in order that it can be stored in the db
    //   at the end of the interpretation
    db *sqlite=NULL;
    std::string modified_human_input;

    sqlite=db_factory::get_instance();
    if(crh&HI_VERB){//Currently only looking up verbs in earlier contexts is supported
        std::map<unsigned int,lexicon> main_verbs=lex->find_main_verb(words);
        if(main_verbs.size()==0){//Looking up verbs in earlier contexts makes only sense if there's no verb in the human input
            //Check only the latest utterance, as it's not sure if it makes sense to check earlier ones.
            query_result *result=NULL;
            result=sqlite->exec_sql("SELECT * FROM ANALYSES WHERE TIMESTAMP=(SELECT MAX(TIMESTAMP) FROM ANALYSES) AND RANK=(SELECT MIN(RANK) FROM ANALYSES WHERE TIMESTAMP=(SELECT MAX(TIMESTAMP) FROM ANALYSES));");
            if(result!=NULL){//&&result->nr_of_result_rows()==1){
                rapidjson::Document jsondoc;
                std::string previous_analysis=*result->field_value_at_row_position(0,"analysis");
                logger::singleton()==NULL?(void)0:logger::singleton()->log(0,previous_analysis);
                jsondoc.Parse(previous_analysis.c_str());
                //TODO:Check for the value of main_symbol first once that's added. See todo comment below about features added
                //at syntactic level. If nothing is found by main_symbol, the logic below shall be used to find
                //the verbs which currently only looks for the first verb having the same gcat set in settings db table
                //for the symbol of the main_symbol.
                query_result *main_symbol_result=NULL;
                main_symbol_result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='main_symbol';");
                std::string main_symbol=*main_symbol_result->field_value_at_row_position(0,"value");
                delete main_symbol_result;
                query_result *main_verb_result=NULL;
                main_verb_result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='"+main_symbol+"';");
                std::string main_verb=*main_verb_result->field_value_at_row_position(0,"value");
                delete main_verb_result;
                rapidjson::Value& morphologyArray=jsondoc["morphology"];
                std::string main_verb_word;
                rapidjson::Value morphologyObj;
                for(unsigned int i=0;i<morphologyArray.Size();++i){
                    morphologyObj=morphologyArray[i];
                    if(main_verb.find(std::string("<")+morphologyObj["gcat"].GetString()+std::string(">"))!=std::string::npos){
                        logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"main verb gcat:"+std::string(morphologyObj["gcat"].GetString()));
                        main_verb_word=morphologyObj["word"].GetString();
                        //TODO: Consider if the main verb shall be marked by the main verb symbol in the successful analyses when saved
                        //so that finding the main verb in earlier contexts (analyses) is not done (like here) by comparing their
                        //grammatical category against the grammatical categories set up for the main verb symbol in the settings table.
                        //E.g. a setence in an earlier analysis may contain more than one verb and here we just pick the first whose
                        //grammatical category matches any of the ones set up in the settings table but it may not be the main verb in that
                        //sentence.
                        break;
                    }
                }
                std::string human_input=lex->work_string();
                //In case of dependency semantics (for which this method prepares the human input) the order of words
                //does not matter as no syntactic analysis is carried out.
                modified_human_input=main_verb_word+" "+human_input;
                std::locale locale=std::locale();
                std::string language=lex->language();
                delete lex;
                //lex points to the same instance as ::lex so deletion is fine
                //but to assign a new lexer the global needs to be updated as well
                lex=new lexer(modified_human_input.c_str(),language.c_str(),locale,false,this);
                path_nr_to_stop_at=0;//TODO:This actually reinitializes that counter for assign_lexer() to work properly but could be done nicer. Figure out how.
                assign_lexer(lex);
            }
        }
    }
    return modified_human_input;
}
