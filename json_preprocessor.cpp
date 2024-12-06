#include "json_preprocessor.h"

json_preprocessor::json_preprocessor(const time_t& timestamp,const std::string& jsondoc):preprocessor(timestamp){
	this->jsondoc.Parse(jsondoc.c_str());
	rapidjson::Value::Object jsonObj=this->jsondoc.GetObject();
	traverse(jsonObj,"",0,0,0);
}

json_preprocessor::~json_preprocessor(){

}

void json_preprocessor::traverse(const rapidjson::Value::Object& jsonObj,const std::string& parent_ref_id,const unsigned int level,const unsigned int row_nr,const unsigned int obj_nr){
	std::string row;
	unsigned int obj_row_nr=0;

	for(auto& i:jsonObj){
		if(i.value.IsObject()==true){
			rapidjson::Value::Object obj=i.value.GetObject();
			traverse(obj,std::to_string(level)+"_"+std::to_string(obj_row_nr)+"_"+std::to_string(obj_nr),level+1,0,0);
			row=" \" "+std::string(i.name.GetString())+" \" : # "+timestamp+"_"+std::to_string(level)+"_"+std::to_string(obj_row_nr)+"_"+std::to_string(obj_nr)+"_"+std::to_string(level+1)+"_"+std::to_string(0)+"_"+std::to_string(0);
		}
		else if(i.value.IsArray()==true){
			rapidjson::Value::Array array=i.value.GetArray();
			std::string value;
			traverseArray(array,std::to_string(level)+"_"+std::to_string(obj_row_nr)+"_"+std::to_string(obj_nr),level+1,0,0,value);
			row=" \" "+std::string(i.name.GetString())+" \" : # "+timestamp+"_"+std::to_string(level)+"_"+std::to_string(obj_row_nr)+"_"+std::to_string(obj_nr)+"_"+std::to_string(level+1)+"_"+std::to_string(0)+"_"+std::to_string(0);
		}
		else{
			std::string value;
			if(i.value.IsBool()==true){
				if(i.value.IsTrue()==true){
					value="true";
				}
				else{
					value="false";
				}
				row=" \" "+std::string(i.name.GetString())+" \" : "+value;
			}
			else if(i.value.IsDouble()==true){
				value=std::to_string(i.value.GetDouble());
				row=" \" "+std::string(i.name.GetString())+" \" : "+value;
			}
			else if(i.value.IsFloat()==true){
				value=std::to_string(i.value.GetFloat());
				row=" \" "+std::string(i.name.GetString())+" \" : "+value;
			}
			else if(i.value.IsInt()==true){
				value=std::to_string(i.value.GetInt());
				row=" \" "+std::string(i.name.GetString())+" \" : "+value;
			}
			else{
				value=std::to_string(*i.value.GetString());
				row=" \" "+std::string(i.name.GetString())+" \" : \" "+value+" \"";
			}
		}
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"parent_ref_id: "+parent_ref_id+", preprocessed row at level "+std::to_string(level)+", row nr "+std::to_string(obj_row_nr)+", obj nr "+std::to_string(obj_nr)+": "+row);
		std::string ref_id=timestamp+"_"+parent_ref_id+"_"+std::to_string(level)+"_"+std::to_string(obj_row_nr)+"_"+std::to_string(obj_nr);
		ref_ids_and_rows.push_back(std::make_pair(ref_id,row));
		ref_ids_to_search_ref_ids.insert(std::make_pair(ref_id,timestamp+"_"+parent_ref_id+"_"));
		++obj_row_nr;
	}
}

void json_preprocessor::traverseArray(const rapidjson::Value::Array& jsonArray,const std::string& parent_ref_id,const unsigned int level,const unsigned int row_nr,const unsigned int obj_nr,std::string& value){

	unsigned int element_obj_nr=0;
	for(auto& i:jsonArray){
		if(i.IsObject()==true){
			rapidjson::Value::Object obj=i.GetObject();
			traverse(obj,std::to_string(level)+"_"+std::to_string(row_nr)+"_"+std::to_string(element_obj_nr),level+1,0,0);
			value+=" # "+timestamp+"_"+std::to_string(level)+"_"+std::to_string(row_nr)+"_"+std::to_string(element_obj_nr)+"_"+std::to_string(level+1)+"_"+std::to_string(0)+"_"+std::to_string(0)+" ,";
			++element_obj_nr;
		}
		else if(i.IsArray()==true){
			rapidjson::Value::Array array=i.GetArray();
			traverseArray(array,std::to_string(level)+"_"+std::to_string(row_nr)+"_"+std::to_string(element_obj_nr),level+1,0,0,value);
			value+=" # "+timestamp+"_"+std::to_string(level)+"_"+std::to_string(row_nr)+"_"+std::to_string(element_obj_nr)+"_"+std::to_string(level+1)+"_"+std::to_string(0)+"_"+std::to_string(0)+" ,";
			++element_obj_nr;
		}
		else{
			if(i.IsBool()==true){
				if(i.IsTrue()==true){
					value+=" true ,";
				}
				else{
					value+=" false ,";
				}
			}
			else if(i.IsDouble()==true){
				value+=" "+std::to_string(i.GetDouble())+" ,";
			}
			else if(i.IsFloat()==true){
				value+=" "+std::to_string(i.GetFloat())+" ,";
			}
			else if(i.IsInt()==true){
				value+=" "+std::to_string(i.GetInt())+" ,";
			}
			else{
				value+=" \" "+std::string(i.GetString())+" \" ,";
			}
		}
	}
	if(value.back()==',') value.pop_back();
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"parent_ref_id: "+parent_ref_id+", preprocessed row at level "+std::to_string(level)+", row nr "+std::to_string(0)+", obj nr "+std::to_string(obj_nr)+": "+"[ "+value+" ]");
	std::string ref_id=timestamp+"_"+parent_ref_id+"_"+std::to_string(level)+"_0_"+std::to_string(obj_nr);
	ref_ids_and_rows.push_back(std::make_pair(ref_id,"[ "+value+" ]"));
	ref_ids_to_search_ref_ids.insert(std::make_pair(ref_id,ref_id));
}

std::pair<std::string,std::string> json_preprocessor::get_row(const unsigned int row_nr) const{
	std::pair<std::string,std::string> ref_id_and_row;

	if(row_nr<ref_ids_and_rows.size()){
		ref_id_and_row=ref_ids_and_rows.at(row_nr);
	}
	return ref_id_and_row;
}

std::string json_preprocessor::get_search_ref_id(const std::string& ref_id) const{
	std::string search_ref_id;

	auto hit=ref_ids_to_search_ref_ids.find(ref_id);
	if(hit!=ref_ids_to_search_ref_ids.end()) search_ref_id=hit->second;
	return search_ref_id;
}
