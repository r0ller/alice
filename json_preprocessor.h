#ifndef JSON_PREPROCESSOR_H
	#define JSON_PREPROCESSOR_H

	#include <string>
	#include <vector>
	#include "preprocessor.h"
	#include "rapidjson/document.h"
	#include "logger.h"
	#include <map>

	class json_preprocessor:public preprocessor{
		private:
			rapidjson::Document jsondoc;
			std::vector<std::pair<std::string,std::string>> ref_ids_and_rows;
			std::map<std::string,std::string> ref_ids_to_search_ref_ids;
			void traverse(const rapidjson::Value::Object&,const std::string&,const unsigned int,const unsigned int,const unsigned int);
			void traverseArray(const rapidjson::Value::Array&,const std::string&,const unsigned int,const unsigned int,const unsigned int,std::string&);
		public:
			json_preprocessor(const time_t&,const std::string&);
			~json_preprocessor();
			std::pair<std::string,std::string> get_row(const unsigned int) const;
			std::string get_search_ref_id(const std::string&) const;
	};

#endif