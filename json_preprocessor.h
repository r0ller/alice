#ifndef JSON_PREPROCESSOR_H
	#define JSON_PREPROCESSOR_H

	#include <string>
	#include <vector>
	#include "preprocessor.h"
	#include "rapidjson/document.h"

	class json_preprocessor:public preprocessor{
		private:
			rapidjson::Document jsondoc;
			std::vector<std::tuple<unsigned int,unsigned int,unsigned int,std::string>> obj_node_level_obj_nr_row_nr_to_key_value;
			void traverse(const rapidjson::Value::Object&,const unsigned int,const unsigned int,const unsigned int);
			void traverseArray(const rapidjson::Value::Array&,const unsigned int,const unsigned int,std::string&);
		public:
			json_preprocessor(const time_t&,const std::string&);
			~json_preprocessor();
			std::tuple<unsigned int,unsigned int,unsigned int,std::string> get_row(const unsigned int);
	};

#endif