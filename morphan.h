#ifndef MORPHAN_H
	#define MORPHAN_H

	#include <stdbool.h>
	#include "fomalib.h"
	#include <string>
	#include <vector>

	class morphan{
		private:
			morphan();
			static morphan *singleton_instance;
			fsm *fst;
			apply_handle *morphan_handle;
		public:
			~morphan();
			static morphan *get_instance(){
				if(morphan::singleton_instance==NULL){
					morphan::singleton_instance=new morphan;
				}
				return morphan::singleton_instance;
			};
			morphan_result *analyze(const std::string&);
	};
#endif
