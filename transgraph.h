#ifndef TRANSGRAPH_H
	#define TRANSGRAPH_H

	#include <utility>
	#include <map>
	#include <string>

	typedef unsigned int d_counter;

	class transgraph{
		private:
		std::pair<std::string,unsigned int> functor;
		std::multimap<d_counter,const transgraph *> arguments;
		const morphan_result *lfeas;
		public:
		transgraph(const std::pair<std::string,unsigned int>&,const morphan_result *);
		~transgraph();
		void insert(const unsigned int, const transgraph *);
		std::string transcript(const std::string&) const;
	};

#endif
