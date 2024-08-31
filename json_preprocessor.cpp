#include "json_preprocessor.h"

json_preprocessor::json_preprocessor(const time_t& timestamp,const std::string& jsondoc):preprocessor(timestamp){
	this->jsondoc.Parse(jsondoc.c_str());
	rapidjson::Value::Object jsonObj=this->jsondoc.GetObject();
	traverse(jsonObj,0,0);
}

json_preprocessor::~json_preprocessor(){

}

void json_preprocessor::traverse(const rapidjson::Value::Object& jsonObj,const unsigned int level,const unsigned int row_nr){
	std::string row;
	unsigned int obj_row_nr=0;

	for(auto& i:jsonObj){
		if(i.value.IsObject()==true){
			rapidjson::Value::Object obj=i.value.GetObject();
			traverse(obj,level+1,obj_row_nr);
			row=" \" "+std::string(i.name.GetString())+" \" : # "+timestamp+"_"+std::to_string(level+1)+"_"+std::to_string(obj_row_nr);
		}
		else if(i.value.IsArray()==true){
			rapidjson::Value::Array array=i.value.GetArray();
			std::string value=" [ ";
			traverseArray(array,level,row_nr,value);
			value+=" ] ";
			row=" \" "+std::string(i.name.GetString())+" \" : "+value;
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
		obj_node_level_row_nr_to_key_value.push_back(std::make_pair(std::to_string(level)+"_"+std::to_string(row_nr),row));
		++obj_row_nr;
	}
}

void json_preprocessor::traverseArray(const rapidjson::Value::Array& jsonArray,const unsigned int level,const unsigned int row_nr,std::string& value){

	for(auto& i:jsonArray){
		if(i.IsObject()==true){
			rapidjson::Value::Object obj=i.GetObject();
			traverse(obj,level,row_nr);
			value+=" , # "+timestamp+std::to_string(level)+"_"+std::to_string(row_nr);
		}
		else if(i.IsArray()==true){
			rapidjson::Value::Array array=i.GetArray();
			value+=" , [";
			traverseArray(array,level,row_nr,value);
			value+=" ]";
		}
		else{
			if(i.IsBool()==true){
				if(i.IsTrue()==true){
					value+=" , true";
				}
				else{
					value+=" , false";
				}
			}
			else if(i.IsDouble()==true){
				value+=" , "+std::to_string(i.GetDouble());
			}
			else if(i.IsFloat()==true){
				value+=" , "+std::to_string(i.GetFloat());
			}
			else if(i.IsInt()==true){
				value+=" , "+std::to_string(i.GetInt());
			}
			else{
				value+=" , "+std::string(i.GetString());
			}
		}
	}
}

std::pair<std::string,std::string> json_preprocessor::get_row(const unsigned int row_nr){
	std::pair<std::string,std::string> ref_id_and_row;

	if(row_nr<obj_node_level_row_nr_to_key_value.size()){
		ref_id_and_row=obj_node_level_row_nr_to_key_value.at(row_nr);
	}
	return ref_id_and_row;
}