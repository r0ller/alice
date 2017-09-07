#ifndef MORPHAN_H
	#define MORPHAN_H

//	#include <stdbool.h>
	typedef bool _Bool;
	#include "fomalib.h"
	#include "morphan_result.h"
	#include <string>
	#include <vector>
	#include <map>

	class morphan{
		private:
			morphan(const std::string&);
			static morphan *singleton_instance;
			fsm *fst=NULL;
			apply_handle *morphan_handle=NULL;
			char *pfstname=NULL;
			std::string lid;
			static std::map<std::pair<std::string,std::string>,std::vector<morphan_result>* > cache;
		public:
			~morphan();
			static morphan *get_instance(const std::string& lid){
				if(morphan::singleton_instance==NULL){
					morphan::singleton_instance=new morphan(lid);
				}
				return morphan::singleton_instance;
			};
			static void delete_cache(){
				for(auto&& i:cache){
					delete i.second;
				}
				cache.clear();
			};
			std::vector<morphan_result> *analyze(const std::string&);
	};
#endif
