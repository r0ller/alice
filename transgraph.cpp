#include "logger.h"
#include "transgraph.h"
#include "db_factory.h"
#include "query_result.h"

unsigned int transgraph::global_id=0;

transgraph::transgraph(const std::string& id,const std::pair<std::string,unsigned int>& functor,const morphan_result *morphan){
	this->functor=functor;
	if(morphan!=NULL){
		this->morphan=morphan;
		if(id.empty()==false) my_id=id;
		else my_id=std::to_string(++transgraph::global_id);
	}
	else{
		this->morphan=NULL;
		if(id.empty()==false) my_id=id+"_"+std::to_string(++transgraph::global_id);
		else my_id=std::to_string(++transgraph::global_id);
	}
}

transgraph::~transgraph(){
	for(auto&& i:arguments){
		if(i.second!=NULL) delete i.second;
	}
}

std::string transgraph::id() const{
	return my_id;
}

void transgraph::insert(const unsigned int d_counter, const transgraph *functor){
	arguments.insert(std::make_pair(d_counter,functor));
}

std::string transgraph::transcript(std::map<std::string,std::string>& functors, const std::string& target_language) const{
	std::string transcript,initial_argscript,argument_list,functor_id,functor_def;
	db *sqlite=NULL;
	query_result *dependencies=NULL,*functor_id_entry=NULL,*functor_def_entry=NULL,*functor_tag_entries=NULL;
	const std::pair<const unsigned int,field> *d_counter_field=NULL;
	const std::string *semantic_dependency=NULL;
	std::map<d_counter,std::string> argument_scripts;

	sqlite=db_factory::get_instance();
	dependencies=sqlite->exec_sql("SELECT * FROM DEPOLEX WHERE LEXEME = '"+functor.first+"' AND D_KEY ='"+std::to_string(functor.second)+"' ORDER BY LEXEME, D_KEY, D_COUNTER;");
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"transcripting:"+functor.first+"_"+std::to_string(functor.second));
	if(morphan!=NULL){
		transcript="{\"id\":\""+my_id+"\",";
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
		transcript="{\"id\":\""+my_id+"\",";
		transcript+="\"functor\":\""+functor.first+"\",";
		transcript+="\"d_key\":\""+std::to_string(functor.second)+"\",";
	}
	if(dependencies!=NULL&&(morphan==NULL||morphan!=NULL&&morphan->gcat()!="CON")){
		functor_id_entry=sqlite->exec_sql("SELECT * FROM FUNCTORS WHERE FUNCTOR = '"+functor.first+"' AND D_KEY = '"+std::to_string(functor.second)+"';");
		if(functor_id_entry==NULL){
			throw std::runtime_error("No entries found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
		}
		functor_id=*functor_id_entry->field_value_at_row_position(0,"functor_id");
		if(functor_id.empty()==false){
			functor_def_entry=sqlite->exec_sql("SELECT * FROM FUNCTOR_DEFS WHERE FUNCTOR_ID = '"+functor_id+"' AND TLID = '"+target_language+"';");
			if(functor_def_entry==NULL){
				throw std::runtime_error("No entries found for functor id "+functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" with target language "+target_language+" in FUNCTOR_DEFS db table.");
			}
			functor_def=*functor_def_entry->field_value_at_row_position(0,"definition");
			if(functor_def.empty()==false){
				std::string functor_def_json=transgraph::apply_json_escapes(functor_def);
				functors.insert(std::make_pair(functor_id,functor_def_json));
			}
			else{
				functors.insert(std::make_pair(functor_id,""));
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"Empty definition field found for functor id "+functor_id+" of functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTOR_DEFS db table.");
			}
		}
		else{
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"Empty functor_id field found for functor "+functor.first+" and d_key "+std::to_string(functor.second)+" in FUNCTORS db table.");
		}
		functor_tag_entries=sqlite->exec_sql("SELECT * FROM FUNCTOR_TAGS WHERE FUNCTOR = '"+functor.first+"' AND D_KEY = '"+std::to_string(functor.second)+"' ORDER BY TRIGGER_TAG, COUNTER;");
		if(functor_tag_entries!=NULL){
			std::string tags="\"tags\":{";
			unsigned int nr_of_entries=functor_tag_entries->nr_of_result_rows();
			for(unsigned int i=0;i<nr_of_entries;++i){
				std::string trigger_tag=*functor_tag_entries->field_value_at_row_position(i,"trigger_tag");
				if(trigger_tag.empty()==true||trigger_tag.empty()==false&&morphan!=NULL&&morphan->has_feature(trigger_tag)==true){
					std::string tag=*functor_tag_entries->field_value_at_row_position(i,"tag");
					std::string value=*functor_tag_entries->field_value_at_row_position(i,"value");
					if(tag.empty()==false&&tags.find("\""+tag+"\":")==std::string::npos){
						tags+="\""+tag+"\":\""+value+"\",";
					}
				}
			}
			if(tags.back()==',') tags.pop_back();
			tags+="},";
			transcript+=tags;
		}
		transcript+="\"functor id\":\""+functor_id+"\"";
		for(auto&& i:arguments){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"checking argument with d_counter "+std::to_string(i.first));
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
					argument_script->second+=i.second->transcript(functors,target_language);
				}
				else{
					initial_argscript=i.second->transcript(functors,target_language);
					argument_scripts.insert(std::make_pair(i.first,initial_argscript));
				}
			}
			else{
				auto argument_script=argument_scripts.find(i.first);
				if(argument_script!=argument_scripts.end()){
					argument_script->second+=i.second->transcript(functors,target_language);
				}
				else{
					initial_argscript=i.second->transcript(functors,target_language);
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
