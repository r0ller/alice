#include "logger.h"
#include "tokenpaths.h"
#include "hilib.h"
#include "sp.h"

extern interpreter *sparser;
extern std::map<std::string, unsigned int> symbol_token_map;
extern std::map<unsigned int,std::string> token_symbol_map;

tokenpaths::tokenpaths(){
	lex=NULL;
	is_any_path_left=true;
	path_nr_to_start_at=0;
	current_path_nr=0;
	path_nr_to_stop_at=0;
}

tokenpaths::tokenpaths(const unsigned int start,const unsigned int stop){
	lex=NULL;
	is_any_path_left=true;
	path_nr_to_start_at=start;
	current_path_nr=start;
	path_nr_to_stop_at=stop;
}

tokenpaths::~tokenpaths(){
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
			}
			reset();
		}
	}
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

std::string tokenpaths::morphology(std::vector<lexicon>& word_analyses,unsigned int& nr_of_cons){
	std::string morphology;

    nr_of_cons=0;
	for(auto&& word:word_analyses){
		morphology+="{\"morpheme id\":\""+std::to_string(word.morphalytics->id())+"\",";
		morphology+="\"word\":\""+word.morphalytics->word()+"\",";
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

void tokenpaths::morphology_wo_cons(const std::vector<lexicon>& word_analyses,std::vector<lexicon>& words_wo_cons){
    lexicon con;
    unsigned int most_con_tags=0,nr_of_non_cons=0;

    //1) remove morphemes having CON gcat if multiple morpheme analyses are available for the same word form with
    //different gcat and only leave the one having the most tags
    //2) or if multiple morpheme analyses are available but only with CON gcat, leave the one having the most tags
    for(auto& word_analysis:word_analyses){
/*        if(word_analysis.morphalytics->gcat()=="CON"){
            unsigned int nr_of_tags=word_analysis.morphalytics->morphemes().size();
            if(nr_of_tags>most_con_tags){
                most_con_tags=nr_of_tags;
                con=word_analysis;
            }
        }
        else{*/
        std::cout<<"checking word_analysis:"<<word_analysis.word<<", gcat:"<<word_analysis.gcat<<", lexeme:"<<word_analysis.lexeme<<", morphemes:"<<word_analysis.morphalytics->morphemes().size()<<std::endl;
            for(auto word_wo_con=words_wo_cons.begin();word_wo_con!=words_wo_cons.end();){
                std::cout<<"checking word_wo_con:"<<word_wo_con->word<<", gcat:"<<word_wo_con->gcat<<", lexeme:"<<word_wo_con->lexeme<<", morphemes:"<<word_wo_con->morphalytics->morphemes().size()<<std::endl;
                if(word_analysis.word==word_wo_con->word&&word_analysis.gcat==word_wo_con->gcat&&word_analysis.lexeme==word_wo_con->lexeme
                   &&word_analysis.morphalytics->morphemes().size()>word_wo_con->morphalytics->morphemes().size()){
                    std::cout<<"word_analysis word has more morphemes"<<std::endl;
                    word_wo_con=words_wo_cons.erase(word_wo_con);
                }
                else{
                    ++word_wo_con;
                }
            }
            words_wo_cons.push_back(word_analysis);
//            ++nr_of_non_cons;
//        }
    }
//    if(nr_of_non_cons==0&&most_con_tags>0){
//        words_wo_cons.push_back(con);
//    }
    return;
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

std::string tokenpaths::create_analysis(const unsigned char& toa,const std::string& target_language,const std::string& sentence,const std::time_t& timestamp,const std::string& source){
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
        //TODO:
        //1. done->rank analyses in create_analysis(), store the successful and the failed analyses in different db tables
        //2. check if the returned analyses has the 'errors' property
        //3. if there's no error, return the ranked analyses
        //4. if there's an error but there's a main verb, call the syntactically incorrect sentence analyzer algorithm
        //5. if there's an error and no verb, look up the main verbs in the previous analyses. The mandatory dependencies
        //   of the verb finally chosen shall match the lexemes of the top ranked analysis.
        //   Besides that if there are mandatory dependencies that the top ranked analysis does not provide,
        //   check if they belong to the verb (like a prefix) and copy the corresponding word(s) together
        //   with the verb to construct a new (syntactically incorrect) sentence.
        //6. start over the interpreter with the newly constructed sentence but this newly triggered interpretation
        //   shall be marked as autocorrected sentence interpretation in order that it can be stored in the db
        //   at the end of the interpretation
        std::map<std::string,std::vector<lexicon> > words_analyses=lexer::words_analyses();
        std::vector<lexicon> words_wo_cons;
        for(auto&& word_analyses:words_analyses){
            morphology_wo_cons(word_analyses.second,words_wo_cons);
        }
        std::vector<lexicon> main_verbs=find_main_verb(words_wo_cons);
        if(main_verbs.size()==1){
            std::set<unsigned int> processed_words;
            lexicon main_verb=main_verbs[0];
            main_verb.morphalytics->add_feature("main_verb");
            valid_parse_trees.clear();
            valid_graphs.clear();
            valid_paths.clear();
            invalid_parse_trees.clear();
            invalid_paths.clear();
            interpreter *sparser=new interpreter(toa);
//            try{
                unsigned int main_verb_node_id=0;
                build_dependency_semantics(sparser,words_wo_cons,processed_words,main_verb,main_verb_node_id);
                const node_info& main_node=sparser->get_node_info(main_verb_node_id);
                unsigned int root_node_id=sparser->set_node_info("S",main_node);
                transgraph *transgraph=NULL;
                transgraph=sparser->longest_match_for_semantic_rules_found();
                if(transgraph!=NULL){
                    validate_parse_tree(sparser->nodes());
                    validate_path(words_wo_cons,transgraph,true);
                    logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"TRUE");
                }
                else{
                    logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"semantic error");
                    invalidate_parse_tree(sparser->nodes());
                    invalidate_path(words_wo_cons,"semantic error",NULL);
                }
/*            }
            catch(...){
                logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Unhandled exception when building dependency semantics.");
            }*/
        }
        else{
            if(main_verbs.size()>1){
                logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"More than one main verb found.");
            }
            else{
                logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"No main verb found.");
            }
        }
    }
    nr_of_analyses=valid_paths.size();
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
        sqlite->exec_sql("INSERT INTO FAILED_ANALYSES VALUES('"+source+"','"+std::to_string(timestamp)+"','"+sentence+"','"+analysis+"');");
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
            analysis+="}";
            ranked_analyses_map.insert(std::make_pair(nr_of_cons,analysis));
            sqlite->exec_sql("INSERT INTO ANALYSES VALUES('"+source+"','"+std::to_string(timestamp)+"','"+sentence+"','"+std::to_string(nr_of_cons)+"','"+analysis+"');");
        }
        analysis="{\"analyses\":[";
        for(auto& i:ranked_analyses_map){
            analysis+=i.second+",";
        }
        if(analysis.back()==',') analysis.pop_back();
        analysis+="]}";
	}
	return analysis;
}

std::vector<lexicon> tokenpaths::find_main_verb(const std::vector<lexicon>& words){
    std::vector<lexicon> main_verbs;

    for(auto& word:words){
        //TODO: introduce a key-value pair for main_verb (or just main?) and read the gcat value
        if(word.morphalytics!=NULL&&word.gcat=="V"){
            std::cout<<word.word<<","<<word.gcat<<","<<word.lexeme<<std::endl;
            main_verbs.push_back(word);
        }
    }
    return main_verbs;
}

lexicon tokenpaths::find_word_by_lexeme(const std::vector<lexicon>& words,const std::string& lexeme){
    lexicon word_found;

    for(auto& word:words){
        if(word.lexeme==lexeme){
            word_found=word;
            break;
        }
    }
    return word_found;
}

lexicon tokenpaths::find_word_by_gcat(const std::vector<lexicon>& words,const std::string& gcat){
    lexicon word_found;

    for(auto& word:words){
        std::cout<<"gcats:"<<word.gcat<<std::endl;
        if(word.gcat==gcat){
            word_found=word;
            break;
        }
    }
    return word_found;
}

void tokenpaths::build_dependency_semantics(interpreter *sparser,std::vector<lexicon>& words,std::set<unsigned int>& processed_words,const lexicon& main_word,unsigned int& main_verb_node_id){
    const std::pair<const unsigned int,field> *depolex_entry=NULL;

    std::cout<<"main_word.lexeme:"<<main_word.lexeme<<", word:"<<main_word.word<<std::endl;
    if(main_word.gcat!="CON"){
        depolex_entry=main_word.dependencies->first_value_for_field_name_found("lexeme",main_word.lexeme);
        while(depolex_entry!=NULL&&main_word.lexeme==*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"lexeme")){
            std::string d_key=*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"d_key");
            while(depolex_entry!=NULL&&main_word.lexeme==*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"lexeme")
                  &&d_key==*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"d_key")){
                std::string dependency_lexeme=*main_word.dependencies->field_value_at_row_position(depolex_entry->first,"semantic_dependency");
                std::cout<<"dependency_lexeme:"<<dependency_lexeme<<std::endl;
                //find_word_by_lexeme() returns the first hit but there may be more than one word with the same lexeme
                //so when recording which word has already been combined as dependency then the word entry (lexicon) itself
                //needs to be recorded not only the lexeme
                lexicon dependency=find_word_by_lexeme(words,dependency_lexeme);
                //combine_nodes() must be a recursive function that iterates over the dependency subtree of
                //the current depolex_entry. It creates the nodes and calls interpreter::combine_nodes()
                //After iterating over the dependency subtrees of the main_word, the same must be done what
                //happens after a successful syntactic analyis -> see C_code.cpp
                if(dependency.lexeme.empty()==true){
                    dependency=find_word_by_gcat(words,dependency_lexeme);
                }
                std::cout<<"dependency.lexeme:"<<dependency.lexeme<<", dependency.gcat:"<<dependency.gcat<<std::endl;
                if(dependency.lexeme.empty()==false||dependency.lexeme.empty()==true&&dependency.gcat=="CON"){
                    combine_nodes(sparser,words,processed_words,main_word,dependency,main_verb_node_id);
                }
                depolex_entry=main_word.dependencies->value_for_field_name_found_after_row_position(depolex_entry->first,"lexeme",main_word.lexeme);
            }
        }
    }
}

void tokenpaths::combine_nodes(interpreter *sparser,std::vector<lexicon>& words,std::set<unsigned int>& processed_words,const lexicon& main_word,const lexicon& dependent_word,unsigned int& main_verb_node_id){
    std::multimap<std::pair<std::string,std::string>,std::pair<unsigned int,std::string> > *functors_found=NULL;
    std::multimap<unsigned int,std::pair<unsigned int,unsigned int> > functors_validated_for_nodes;

    unsigned int main_node_id=sparser->set_node_info(main_word.gcat,main_word);
    node_info main_node=sparser->get_node_info(main_node_id);
    unsigned int dependent_node_id=sparser->set_node_info(dependent_word.gcat,dependent_word);
    node_info dependent_node=sparser->get_node_info(dependent_node_id);
    std::cout<<"dependent.lexeme:"<<dependent_word.lexeme<<std::endl;
    try{
        //wrap this in tokenpaths::is_valid_combination(){
        functors_found=sparser->is_valid_expression(main_node,dependent_node);
        if(functors_found!=NULL){
            //this part is copied from interpreter::is_valid_combination()
            //and may worth wrapping in a new method in that class so that
            //it can be simply called here and there
            for(auto&& m:*functors_found){
                functors_validated_for_nodes.insert(std::make_pair(main_node.node_id,std::make_pair(m.second.first,dependent_node.node_id)));
            }
            delete functors_found;
            for(auto&& i:functors_validated_for_nodes){
                if(main_node.expression.dependencies==NULL||dependent_node.expression.dependencies==NULL){
                    //TODO: check if rule_step_failed needs to be set here or exception should be thrown.
                    //This may be the right place (check it!) to prevent dumps if a word gets combined with another
                    //one where one of them is not registered in the DEPOLEX.
                    //See comments in lexer::dependencies_read_for_functor().
                    //As there may be more than one functors, it might be the case that execution can continue if
                    //there's at least one, where the dependencies attributes are not null.
                    //this may make sense as a first try instead of throwing an exception:
                    //rule_step_failed=std::atoi(rule_entry_failure_copy->second.field_value.c_str());
                }
                else{//this else branch was not here earlier so this alone may complicate matters even though the
                    // if branch still does not do anything
                    main_node.dependency_validation_matrix.insert(i.second);
                    logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"inserting in dvm ("+std::to_string(i.second.first)+","+std::to_string(i.second.second)+") dependent node functor "+dependent_node.expression.lexeme+" for main node functor "+main_node.expression.lexeme);
                    if(dependent_node.node_links.find(main_node.node_id)==dependent_node.node_links.end()){
                        dependent_node.node_links.insert(std::make_pair(main_node.node_id,0));//TODO:get rid of second member in node_links
                    }
                }
            }
        //}
            //if tokenpaths::is_valid_combination() succeeds, only then combine_nodes()
            unsigned int combined_node_id=sparser->combine_nodes(main_word.gcat+"_"+dependent_word.gcat+"_"+std::to_string(main_node_id)+"_"+std::to_string(dependent_node_id),main_node,dependent_node);
            if(main_word.morphalytics->has_feature("main_verb")==true||main_word.morphalytics->has_feature("main_verb")==true) main_verb_node_id=combined_node_id;
            std::cout<<"combined_node_id:"<<combined_node_id<<std::endl;
            unsigned int i=0;
            for(auto word=words.begin();word!=words.end();++word){
                if(word->lexeme==dependent_word.lexeme&&processed_words.find(i)==processed_words.end()){
                    //mark the first hit only as find_word_by_lexeme() returns always the first hit
                    processed_words.insert(i);
                    break;
                }
                ++i;
            }
        }
    }
    catch(invalid_combination& exception){
        logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Unhandled exception in tokenpaths::combine_nodes().");
    }
    //It doesn't matter if main_word and dependent_word cannot be combined, continue looking for possible combinations
    build_dependency_semantics(sparser,words,processed_words,dependent_word,main_verb_node_id);
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

/*
void tokenpaths::mapFunctorDependenciesToSemantics(){

-get main verb
-get functor id of main verb
-get dependencies of main verb
-get related dependencies (dependecies of all other words?)
-merge dependencies and related dependencies
-findFunctorDependenciesForSemanticOnes:
    -
}
*/
