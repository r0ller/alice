#ifndef TRANSGRAPH_H
	#define TRANSGRAPH_H

	#include <utility>
	#include <map>
	#include <string>
	#include "morphan_result.h"

	typedef unsigned int d_counter;

	class transgraph{
		private:
		static unsigned int global_id;//TODO:figure out when to reset or change it to instance level
		std::string my_id;
		std::pair<std::string,unsigned int> functor;
		std::multimap<d_counter,const transgraph *> arguments;
		const morphan_result *morphan;
		public:
		transgraph(const std::string&,const std::pair<std::string,unsigned int>&,const morphan_result *);
		~transgraph();
		void insert(const unsigned int, const transgraph *);
		std::string transcript(std::map<std::string,std::string>&, const std::string&) const;
		std::string id() const;
		static std::string apply_json_escapes(const std::string&);
	};

#endif
