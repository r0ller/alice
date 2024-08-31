#ifndef PP_FACTORY_H
	#define PP_FACTORY_H

	#include "preprocessor.h"
	#include "json_preprocessor.h"

	class pp_factory{
		public:
			static preprocessor* get_instance(const std::string& lid,const time_t& timestamp,const std::string& text){
				preprocessor *pp=NULL;
				if(lid=="JSON"||lid=="json"){
					pp=(preprocessor*) new json_preprocessor(timestamp,text);
				}
				return pp;
			}
	};

#endif