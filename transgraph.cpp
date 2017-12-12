#include "transgraph.h"
unsigned int transgraph::global_id=0;

transgraph::transgraph(const std::pair<std::string,unsigned int>& functor,const morphan_result *morphan){
	this->functor=functor;
	if(morphan!=NULL) this->morphan=morphan;
	else this->morphan=NULL;
	my_id=++transgraph::global_id;
}

transgraph::~transgraph(){
	for(auto&& i:arguments){
		if(i.second!=NULL) delete i.second;
	}
}

unsigned int transgraph::id() const{
	return my_id;
}

void transgraph::insert(const unsigned int d_counter, const transgraph *functor){
	arguments.insert(std::make_pair(d_counter,functor));
}


//#if defined(__ANDROID__)
//std::string transgraph::transcript(const std::string& type) const{
//	std::string transcript,initial_argscript,argument_list,parameter_list;
//	db *sqlite=NULL;
//	query_result *dependencies=NULL,*functor_id_entry=NULL,*functor_def_entry=NULL;
//	const std::pair<const unsigned int,field> *d_counter_field=NULL;
//	const std::string *semantic_dependency=NULL,*ref_d_key=NULL,*functor_id=NULL,*functor_def=NULL;
//	std::map<d_counter,std::string> argument_scripts;
//	unsigned int morphan_index=0;
//
//	logger::singleton()->log(0,"transcripting:"+functor.first+"_"+std::to_string(functor.second));
//	sqlite=db_factory::get_instance();
//	if(type!="CON"){
//		dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"' ORDER BY LEXEME, D_KEY, D_COUNTER;");
//		if(dependencies==NULL){
//			throw std::runtime_error("No entries found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//		}
//	}
//	if(type=="CON"){
//		transcript=functor.first;
//	}
//	else{
//		parameter_list="[";
//		for(auto&& i:arguments){
//			d_counter_field=dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first));
//			if(d_counter_field==NULL){
//				throw std::runtime_error("Empty d_counter field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//			}
//			semantic_dependency=dependencies->field_value_at_row_position(d_counter_field->first,"semantic_dependency");
//			if(semantic_dependency==NULL){
//				throw std::runtime_error("Empty semantic_dependency field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//			}
//			if(*semantic_dependency=="CON"){
//				auto argument_script=argument_scripts.find(i.first);
//				if(argument_script!=argument_scripts.end()){
//					argument_script->second+=" "+i.second->transcript(*semantic_dependency);
//				}
//				else{
//					initial_argscript=functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_"+std::to_string(i.second->id())+"_IN='";
//					initial_argscript+=i.second->transcript(*semantic_dependency);
//					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
//				}
//			}
//			else{
//				auto argument_script=argument_scripts.find(i.first);
//				if(argument_script!=argument_scripts.end()){
//					argument_script->second+=" "+i.second->transcript(*semantic_dependency);
//				}
//				else{
//					initial_argscript=i.second->transcript(*semantic_dependency);
//					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
//				}
//			}
//			ref_d_key=dependencies->field_value_at_row_position(d_counter_field->first,"ref_d_key");
//			if(ref_d_key==NULL){
//				throw std::runtime_error("Empty ref_d_key field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//			}
//			if(*semantic_dependency=="CON"){
//				if(argument_list.empty()==true){
//					argument_list+=functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_"+std::to_string(i.second->id())+"_IN";
//					parameter_list+="'"+functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_"+std::to_string(i.second->id())+"_IN"+"'";
//				}
//				else{
//					argument_list+=","+functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_"+std::to_string(i.second->id())+"_IN";
//					parameter_list+=",'"+functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_"+std::to_string(i.second->id())+"_IN"+"'";
//				}
//			}
//			else{
//				if(argument_list.empty()==true){
//					argument_list+=*semantic_dependency+"_"+*ref_d_key+"_"+std::to_string(i.second->id())+"_OUT";
//					parameter_list+="'"+*semantic_dependency+"_"+*ref_d_key+"_"+std::to_string(i.second->id())+"_OUT"+"'";
//				}
//				else{
//					argument_list+=","+*semantic_dependency+"_"+*ref_d_key+"_"+std::to_string(i.second->id())+"_OUT";
//					parameter_list+=",'"+*semantic_dependency+"_"+*ref_d_key+"_"+std::to_string(i.second->id())+"_OUT"+"'";
//				}
//			}
//		}
//		parameter_list+="]";
//		for(auto&& i:argument_scripts){
//			if(*dependencies->field_value_at_row_position(dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first))->first,"semantic_dependency")=="CON"){
//				transcript+=i.second+"';";
//			}
//			else{
//				transcript+=i.second;
//			}
//		}
//		std::string function_name=functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id);
//		if(argument_list.empty()==false){
//			transcript+="function "+function_name+"("+"function_name,parameter_list,"+argument_list+"){ ";
//		}
//		else{
//			transcript+="function "+function_name+"(){ ";
//		}
//		if(morphan!=NULL){
//			transcript+=functor.first+"_"+std::to_string(functor.second)+"_WORD='"+morphan->word()+"';";
//			transcript+=functor.first+"_"+std::to_string(functor.second)+"_STEM='"+morphan->stem()+"';";
//			transcript+=functor.first+"_"+std::to_string(functor.second)+"_GCAT='"+morphan->gcat()+"';";
//			transcript+=functor.first+"_"+std::to_string(functor.second)+"_MORPHEMES=new Array();";
//			for(auto&& i:morphan->morphemes()){
//				transcript+=functor.first+"_"+std::to_string(functor.second)+"_MORPHEMES["+std::to_string(morphan_index)+"]='";
//				transcript+=i+"';";
//				++morphan_index;
//			}
//		}
//		functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"';");
//		if(functor_id_entry==NULL){
//			throw std::runtime_error("No entries found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
//		}
//		functor_id=functor_id_entry->field_value_at_row_position(0,"functor_id");
//		if(functor_id==NULL){
//			throw std::runtime_error("Empty functor_id field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
//		}
//		functor_def_entry=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS WHERE FUNCTOR_ID = '"+*functor_id+"';");
//		if(functor_def_entry==NULL){
//			throw std::runtime_error("No entries found for functor id "+*functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
//		}
//		functor_def=functor_def_entry->field_value_at_row_position(0,"definition");
//		if(functor_def==NULL){
//			throw std::runtime_error("Empty definition field found for functor id "+*functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
//		}
//		if(functor_def->empty()==false){
//			if(argument_list.empty()==false){
//				transcript+=*functor_def+" }\n"+function_name+"_OUT="+function_name+"("+"'"+function_name+"',"+parameter_list+","+argument_list+")"+";";
//			}
//			else{
//				transcript+=*functor_def+" }\n"+function_name+"_OUT="+function_name+"("+"'"+function_name+"');";
//			}
//		}
//		else{
//			transcript+="true; }\n"+function_name+"_OUT="+function_name+"();";
//		}
//	}
//	return transcript;
//}
//#elif defined(__EMSCRIPTEN__)
//std::string transgraph::transcript(const std::string& type) const{
//	std::string transcript,initial_argscript,argument_list;
//	db *sqlite=NULL;
//	query_result *dependencies=NULL,*functor_id_entry=NULL,*functor_def_entry=NULL;
//	const std::pair<const unsigned int,field> *d_counter_field=NULL;
//	const std::string *semantic_dependency=NULL,*ref_d_key=NULL,*functor_id=NULL,*functor_def=NULL;
//	std::map<d_counter,std::string> argument_scripts;
//	unsigned int morphan_index=0;
//
//	std::cout<<"transcripting:"<<functor.first<<"_"<<functor.second<<std::endl;
//	sqlite=db_factory::get_instance();
//	if(type!="CON"){
//		dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"' ORDER BY LEXEME, D_KEY, D_COUNTER;");
//		if(dependencies==NULL){
//			throw std::runtime_error("No entries found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//		}
//	}
//	if(type=="CON"){
//		transcript="{\"value\":\""+functor.first+"\",";
//		functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = 'CON' AND D_KEY ='"+std::to_string(functor.second)+"';");
//		if(functor_id_entry==NULL){
//			throw std::runtime_error("No entries found for functor CON and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
//		}
//		functor_id=functor_id_entry->field_value_at_row_position(0,"functor_id");
//		if(functor_id==NULL){
//			throw std::runtime_error("Empty functor_id field found for functor CON and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
//		}
//		functor_def_entry=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS WHERE FUNCTOR_ID = '"+*functor_id+"';");
//		if(functor_def_entry==NULL){
//			throw std::runtime_error("No entries found for functor id "+*functor_id+" of functor CON and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
//		}
//		functor_def=functor_def_entry->field_value_at_row_position(0,"definition");
//		if(functor_def==NULL){
//			throw std::runtime_error("Empty definition field found for functor id "+*functor_id+" of functor CON and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
//		}
//		if(functor_def->empty()==false){
//			transcript+="\"def_tags\":["+*functor_def+"]},";
//		}
//		else{
//			transcript+="\"def_tags\":[]},";
//		}
//	}
//	else{
//		transcript+="{\"functor\":\""+functor.first+"_"+std::to_string(functor.second)+"\",";
//		if(morphan!=NULL){
//			transcript+="\"word\":\""+morphan->word()+"\",";
//			transcript+="\"stem\":\""+morphan->stem()+"\",";
//			transcript+="\"gcat\":\""+morphan->gcat()+"\",";
//			transcript+="\"morphemes\":[";
//			for(auto&& i:morphan->morphemes()){
//				transcript+="{\"morpheme\":\"";
//				transcript+=i+"\"},";
//				++morphan_index;
//			}
//			if(transcript.back()==',') transcript.pop_back();
//			transcript+="],";
//		}
//		functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"';");
//		if(functor_id_entry==NULL){
//			throw std::runtime_error("No entries found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
//		}
//		functor_id=functor_id_entry->field_value_at_row_position(0,"functor_id");
//		if(functor_id==NULL){
//			throw std::runtime_error("Empty functor_id field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
//		}
//		functor_def_entry=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS WHERE FUNCTOR_ID = '"+*functor_id+"';");
//		if(functor_def_entry==NULL){
//			throw std::runtime_error("No entries found for functor id "+*functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
//		}
//		functor_def=functor_def_entry->field_value_at_row_position(0,"definition");
//		if(functor_def==NULL){
//			throw std::runtime_error("Empty definition field found for functor id "+*functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
//		}
//		if(functor_def->empty()==false){
//			transcript+="\"def_tags\":["+*functor_def+"],\"dependencies\":[";
//		}
//		else{
//			transcript+="\"def_tags\":[],\"dependencies\":[";
//		}
//		for(auto&& i:arguments){
//			d_counter_field=dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first));
//			if(d_counter_field==NULL){
//				throw std::runtime_error("Empty d_counter field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//			}
//			semantic_dependency=dependencies->field_value_at_row_position(d_counter_field->first,"semantic_dependency");
//			if(semantic_dependency==NULL){
//				throw std::runtime_error("Empty semantic_dependency field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//			}
//			if(*semantic_dependency=="CON"){
//				auto argument_script=argument_scripts.find(i.first);
//				if(argument_script!=argument_scripts.end()){
//					argument_script->second+=i.second->transcript(*semantic_dependency);
//				}
//				else{
//					initial_argscript="{\"functor\":\""+*semantic_dependency+"_"+std::to_string(i.first)+"\",\"constants\":[";
//					initial_argscript+=i.second->transcript(*semantic_dependency);
//					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
//				}
//			}
//			else{
//				auto argument_script=argument_scripts.find(i.first);
//				if(argument_script!=argument_scripts.end()){
//					argument_script->second+=i.second->transcript(*semantic_dependency);
//				}
//				else{
//					initial_argscript=i.second->transcript(*semantic_dependency);
//					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
//				}
//			}
////			ref_d_key=dependencies->field_value_at_row_position(d_counter_field->first,"ref_d_key");
////			if(ref_d_key==NULL) exit(EXIT_FAILURE);//TODO: throw exception
////			if(*semantic_dependency=="CON"){
////				if(argument_list.empty()==true){
////					argument_list+=functor.first+"_"+std::to_string(functor.second)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_IN";
////				}
////				else{
////					argument_list+=","+functor.first+"_"+std::to_string(functor.second)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_IN";
////				}
////			}
////			else{
////				if(argument_list.empty()==true){
////					argument_list+=*semantic_dependency+"_"+*ref_d_key+"_OUT";
////				}
////				else{
////					argument_list+=","+*semantic_dependency+"_"+*ref_d_key+"_OUT";
////				}
////			}
//		}
//		for(auto&& i:argument_scripts){
//			if(*dependencies->field_value_at_row_position(dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first))->first,"semantic_dependency")=="CON"){
//				transcript+=i.second;
//				if(transcript.back()==',') transcript.pop_back();
//				transcript+="]},";
//			}
//			else{
//				transcript+=i.second;
//			}
//		}
//		if(transcript.back()==',') transcript.pop_back();
//		transcript+="]},";
//	}
//	return transcript;
//}
//#elif defined(__SHELL__)
//std::string transgraph::transcript(const std::string& type) const{
//	std::string transcript,initial_argscript,argument_list,parameter_list;
//	db *sqlite=NULL;
//	query_result *dependencies=NULL,*functor_id_entry=NULL,*functor_def_entry=NULL;
//	const std::pair<const unsigned int,field> *d_counter_field=NULL;
//	const std::string *semantic_dependency=NULL,*ref_d_key=NULL,*functor_id=NULL,*functor_def=NULL;
//	std::map<d_counter,std::string> argument_scripts;
//	unsigned int morphan_index=0;
//
//	std::cout<<"transcripting:"<<functor.first<<"_"<<functor.second<<std::endl;
//	sqlite=db_factory::get_instance();
//	if(type!="CON"){
//		dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"' ORDER BY LEXEME, D_KEY, D_COUNTER;");
//		if(dependencies==NULL){
//			throw std::runtime_error("No entries found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//		}
//	}
//	if(type=="CON"){
//		transcript=functor.first;
//	}
//	else{
//		parameter_list="\"";
//		for(auto&& i:arguments){
//			d_counter_field=dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first));
//			if(d_counter_field==NULL){
//				throw std::runtime_error("Empty d_counter field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//			}
//			semantic_dependency=dependencies->field_value_at_row_position(d_counter_field->first,"semantic_dependency");
//			if(semantic_dependency==NULL){
//				throw std::runtime_error("Empty semantic_dependency field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//			}
//			if(*semantic_dependency=="CON"){
//				auto argument_script=argument_scripts.find(i.first);
//				if(argument_script!=argument_scripts.end()){
//					argument_script->second+=" "+i.second->transcript(*semantic_dependency);
//				}
//				else{
//					initial_argscript=functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_"+std::to_string(i.second->id())+"_IN=(";
//					initial_argscript+=i.second->transcript(*semantic_dependency);
//					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
//				}
//			}
//			else{
//				auto argument_script=argument_scripts.find(i.first);
//				if(argument_script!=argument_scripts.end()){
//					argument_script->second+=" "+i.second->transcript(*semantic_dependency);
//				}
//				else{
//					initial_argscript=i.second->transcript(*semantic_dependency);
//					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
//				}
//			}
//			ref_d_key=dependencies->field_value_at_row_position(d_counter_field->first,"ref_d_key");
//			if(ref_d_key==NULL){
//				throw std::runtime_error("Empty ref_d_key field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
//			}
//			if(*semantic_dependency=="CON"){
//				argument_list+=" $"+functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_"+std::to_string(i.second->id())+"_IN";
//				parameter_list+=" "+functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_"+std::to_string(i.second->id())+"_IN ";
//			}
//			else{
//				argument_list+=" $"+*semantic_dependency+"_"+*ref_d_key+"_"+std::to_string(i.second->id())+"_OUT";
//				parameter_list+=" "+*semantic_dependency+"_"+*ref_d_key+"_"+std::to_string(i.second->id())+"_OUT ";
//			}
//		}
//		parameter_list+="\"";
//		for(auto&& i:argument_scripts){
//			if(*dependencies->field_value_at_row_position(dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first))->first,"semantic_dependency")=="CON"){
//				transcript+=i.second+");";
//			}
//			else{
//				transcript+=i.second;
//			}
//		}
//		std::string function_name=functor.first+"_"+std::to_string(functor.second)+"_"+std::to_string(my_id);
//		transcript+=function_name+"(){ ";
//		if(morphan!=NULL){
//			transcript+=functor.first+"_"+std::to_string(functor.second)+"_WORD='"+morphan->word()+"';";
//			transcript+=functor.first+"_"+std::to_string(functor.second)+"_STEM='"+morphan->stem()+"';";
//			transcript+=functor.first+"_"+std::to_string(functor.second)+"_GCAT='"+morphan->gcat()+"';";
//			for(auto&& i:morphan->morphemes()){
//				transcript+=functor.first+"_"+std::to_string(functor.second)+"_MORPHEMES["+std::to_string(morphan_index)+"]='";
//				transcript+=i+"';";
//				++morphan_index;
//			}
//		}
//		functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"';");
//		if(functor_id_entry==NULL){
//			throw std::runtime_error("No entries found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
//		}
//		functor_id=functor_id_entry->field_value_at_row_position(0,"functor_id");
//		if(functor_id==NULL){
//			throw std::runtime_error("Empty functor_id field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
//		}
//		functor_def_entry=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS WHERE FUNCTOR_ID = '"+*functor_id+"';");
//		if(functor_def_entry==NULL){
//			throw std::runtime_error("No entries found for functor id "+*functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
//		}
//		functor_def=functor_def_entry->field_value_at_row_position(0,"definition");
//		if(functor_def==NULL){
//			throw std::runtime_error("Empty definition field found for functor id "+*functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
//		}
//		if(functor_def->empty()==false){
//			transcript+=*functor_def+" };"+function_name+" \""+function_name+"\" "+parameter_list+" "+argument_list+";";
//		}
//		else{
//			transcript+="true; };"+function_name+" \""+function_name+"\" "+parameter_list+" "+argument_list+";";
//		}
//	}
//	return transcript;
//}
//#else
std::string transgraph::transcript(std::map<std::string,std::string>& functors) const{
	std::string transcript,initial_argscript,argument_list;
	db *sqlite=NULL;
	query_result *dependencies=NULL,*functor_id_entry=NULL,*functor_def_entry=NULL;
	const std::pair<const unsigned int,field> *d_counter_field=NULL;
	const std::string *semantic_dependency=NULL,*functor_id=NULL,*functor_def=NULL;
	std::map<d_counter,std::string> argument_scripts;

	sqlite=db_factory::get_instance();
	dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"' ORDER BY LEXEME, D_KEY, D_COUNTER;");
	std::cout<<"transcripting:"<<functor.first<<"_"<<functor.second<<std::endl;
	if(morphan!=NULL){
		transcript="{\"id\":\""+std::to_string(my_id)+"\",";
		if(morphan->gcat()=="CON"){
			transcript+="\"functor\":\"CON\",";
		}
		else{
			transcript+="\"functor\":\""+functor.first+"\",";
		}
		transcript+="\"d_key\":\""+std::to_string(functor.second)+"\",";
		transcript+="\"morpheme id\":\""+std::to_string(morphan->id())+"\",";
	}
	else{
		transcript="{\"id\":\""+std::to_string(my_id)+"\",";
		transcript+="\"functor\":\""+functor.first+"\",";
		transcript+="\"d_key\":\""+std::to_string(functor.second)+"\",";
	}
	if(dependencies!=NULL&&(morphan==NULL||morphan!=NULL&&morphan->gcat()!="CON")){
		functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"';");
		if(functor_id_entry==NULL){
			throw std::runtime_error("No entries found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
		}
		functor_id=functor_id_entry->field_value_at_row_position(0,"functor_id");
		if(functor_id==NULL){
			throw std::runtime_error("Empty functor_id field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
		}
		functor_def_entry=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS WHERE FUNCTOR_ID = '"+*functor_id+"';");
		if(functor_def_entry==NULL){
			throw std::runtime_error("No entries found for functor id "+*functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
		}
		functor_def=functor_def_entry->field_value_at_row_position(0,"definition");
		if(functor_def==NULL){
			throw std::runtime_error("Empty definition field found for functor id "+*functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
		}
		if(functor_def->empty()==false){
			std::string functor_def_json=transgraph::apply_json_escapes(*functor_def);
			functors.insert(std::make_pair(*functor_id,functor_def_json));
		}
		else{
			functors.insert(std::make_pair(*functor_id,""));
		}
		transcript+="\"functor id\":\""+*functor_id+"\"";
		for(auto&& i:arguments){
			d_counter_field=dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first));
			if(d_counter_field==NULL){
				throw std::runtime_error("Empty d_counter field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
			}
			semantic_dependency=dependencies->field_value_at_row_position(d_counter_field->first,"semantic_dependency");
			if(semantic_dependency==NULL){
				throw std::runtime_error("Empty semantic_dependency field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in DEPOLEX db table.");
			}
			if(*semantic_dependency=="CON"){
				auto argument_script=argument_scripts.find(i.first);
				if(argument_script!=argument_scripts.end()){
					argument_script->second+=i.second->transcript(functors);
				}
				else{
					initial_argscript=i.second->transcript(functors);
					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
				}
			}
			else{
				auto argument_script=argument_scripts.find(i.first);
				if(argument_script!=argument_scripts.end()){
					argument_script->second+=i.second->transcript(functors);
				}
				else{
					initial_argscript=i.second->transcript(functors);
					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
				}
			}
		}
		if(argument_scripts.empty()==false){
			transcript+=",\"dependencies\":[";
			for(auto&& i:argument_scripts){
				transcript+=i.second;
			}
			if(transcript.back()==',') transcript.pop_back();
			transcript+="]";
		}
		transcript+="},";
	}
	else{
		if(transcript.back()==',') transcript.pop_back();
		transcript+="},";
	}
	return transcript;
}
//#endif

std::string transgraph::apply_json_escapes(const std::string& nonjsonstr){

	std::string::size_type position=0;
	std::string jsonstr;

	jsonstr=nonjsonstr;
	while(position<jsonstr.length()){
		position=jsonstr.find('\\',position);
		if(position==std::string::npos) break;
		jsonstr.insert(position,1,'\\');
		position=position+2;
	}
	position=0;
	while(position<jsonstr.length()){
		position=jsonstr.find('"',position);
		if(position==std::string::npos) break;
		jsonstr.insert(position,1,'\\');
		position=position+2;
	}
	position=0;
	while(position<jsonstr.length()){
		position=jsonstr.find('\n',position);
		if(position==std::string::npos) break;
		jsonstr.erase(position,1);
	}
	position=0;
	while(position<jsonstr.length()){
		position=jsonstr.find('\r',position);
		if(position==std::string::npos) break;
		jsonstr.erase(position,1);
	}
	position=0;
	while(position<jsonstr.length()){
		position=jsonstr.find('\t',position);
		if(position==std::string::npos) break;
		jsonstr.erase(position,1);
	}
	position=0;
	while(position<jsonstr.length()){
		position=jsonstr.find('\b',position);
		if(position==std::string::npos) break;
		jsonstr.erase(position,1);
	}
	position=0;
	while(position<jsonstr.length()){
		position=jsonstr.find('\f',position);
		if(position==std::string::npos) break;
		jsonstr.erase(position,1);
	}
	return jsonstr;
}
