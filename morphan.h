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
			static std::map<std::string,morphan*> lid_instances;
			fsm *fst=NULL;
			apply_handle *morphan_handle=NULL;
			char *pfstname=NULL;
			std::string lid_;
			std::string lid();
			bool natural_language;
		public:
			~morphan();
			static morphan *get_instance(const std::string& lid){
				morphan *lid_instance=NULL;
				auto instance_found=lid_instances.find(lid);
				if(instance_found==lid_instances.end()){
					lid_instance=new morphan(lid);
					lid_instances.insert(std::make_pair(lid,lid_instance));
				}
				else{
					lid_instance=instance_found->second;
				}
				return lid_instance;
			};
			std::vector<morphan_result> *analyze(const std::string&, const bool);
			std::vector<std::string> generate(const std::string&);
			bool is_natural_language();
	};
#endif
