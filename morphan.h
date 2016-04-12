#ifndef MORPHAN_H
	#define MORPHAN_H

//	#include <stdbool.h>
	typedef bool _Bool;
	#include "fomalib.h"
	#include "morphan_result.h"
	#include <string>
	#include <vector>

	class morphan{
		private:
			morphan(const std::string&);
			static morphan *singleton_instance;
			fsm *fst=NULL;
			apply_handle *morphan_handle=NULL;
			char *pfstname=NULL;
		public:
			~morphan();
			static morphan *get_instance(const std::string& lid){
				if(morphan::singleton_instance==NULL){
					morphan::singleton_instance=new morphan(lid);
				}
				return morphan::singleton_instance;
			};
			morphan_result *analyze(const std::string&);
	};
#endif
