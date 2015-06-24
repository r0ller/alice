#include "transgraph.h"

transgraph::transgraph(const std::pair<std::string,unsigned int>& functor){
	this->functor=functor;
}

transgraph::~transgraph(){
	for(auto&& i:arguments){
		delete i.second;
	}
}

void transgraph::insert(const unsigned int d_counter, const transgraph *functor){
	arguments.insert(std::make_pair(d_counter,functor));
}

std::string transgraph::transcript(const std::string& type) const{
	std::string transcript,initial_argscript,argument_list;
	db *sqlite=NULL;
	query_result *dependencies=NULL,*functor_id_entry=NULL,*functor_def_entry=NULL;
	const std::pair<const unsigned int,field> *d_counter_field=NULL;
	const std::string *semantic_dependency=NULL,*ref_d_key=NULL,*functor_id=NULL,*functor_def=NULL;
	std::map<d_counter,std::string> argument_scripts;

	std::cout<<"transcripting:"<<functor.first<<"_"<<functor.second<<std::endl;
	sqlite=db::get_instance();
	if(type!="CON"){
		dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"' ORDER BY LEXEME, D_KEY, D_COUNTER;");
		if(dependencies==NULL) exit(EXIT_FAILURE);//TODO: throw exception
	}
	if(type=="CON"){
		transcript=functor.first;
	}
	else{
		for(auto&& i:arguments){
			d_counter_field=dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first));
			if(d_counter_field==NULL) exit(EXIT_FAILURE);//TODO: throw exception
			semantic_dependency=dependencies->field_value_at_row_position(d_counter_field->first,"semantic_dependency");
			if(semantic_dependency==NULL) exit(EXIT_FAILURE);//TODO: throw exception
			if(*semantic_dependency=="CON"){
				auto argument_script=argument_scripts.find(i.first);
				if(argument_script!=argument_scripts.end()){
					argument_script->second+=" "+i.second->transcript(*semantic_dependency);
				}
				else{
					initial_argscript=functor.first+"_"+std::to_string(functor.second)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_IN=(";
					initial_argscript+=i.second->transcript(*semantic_dependency);
					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
				}
			}
			else{
				auto argument_script=argument_scripts.find(i.first);
				if(argument_script!=argument_scripts.end()){
					argument_script->second+=" "+i.second->transcript(*semantic_dependency);
				}
				else{
					initial_argscript=i.second->transcript(*semantic_dependency);
					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
				}
			}
			ref_d_key=dependencies->field_value_at_row_position(d_counter_field->first,"ref_d_key");
			if(ref_d_key==NULL) exit(EXIT_FAILURE);//TODO: throw exception
			if(*semantic_dependency=="CON"){
				argument_list+=" "+functor.first+"_"+std::to_string(functor.second)+"_"+*semantic_dependency+"_"+std::to_string(i.first)+"_IN";
			}
			else{
				argument_list+=" "+*semantic_dependency+"_"+*ref_d_key+"_OUT";
			}
		}
		for(auto&& i:argument_scripts){
			if(*dependencies->field_value_at_row_position(dependencies->first_value_for_field_name_found("d_counter",std::to_string(i.first))->first,"semantic_dependency")=="CON"){
				transcript+=i.second+");";
			}
			else{
				transcript+=i.second;
			}
		}
		transcript+=functor.first+"_"+std::to_string(functor.second)+"(){ ";
		functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"';");
		if(functor_id_entry==NULL) exit(EXIT_FAILURE);//TODO: throw exception
		functor_id=functor_id_entry->field_value_at_row_position(0,"functor_id");
		if(functor_id==NULL) exit(EXIT_FAILURE);//TODO: throw exception
		functor_def_entry=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS WHERE FUNCTOR_ID = '"+*functor_id+"';");
		if(functor_def_entry==NULL) exit(EXIT_FAILURE);//TODO: throw exception
		functor_def=functor_def_entry->field_value_at_row_position(0,"definition");
		if(functor_def==NULL) exit(EXIT_FAILURE);//TODO: throw exception
		if(functor_def->empty()==false){
			transcript+=*functor_def+" };"+functor.first+"_"+std::to_string(functor.second)+argument_list+";";
		}
		else{
			transcript+="true; };"+functor.first+"_"+std::to_string(functor.second)+argument_list+";";
		}
	}
	return transcript;
}
