#ifndef TRANSGRAPH_H
	#define TRANSGRAPH_H

	#include <utility>
	#include <map>
	#include <string>

	typedef unsigned int d_counter;

	class transgraph{
		private:
		static unsigned int global_id;
		unsigned int my_id;
		std::pair<std::string,unsigned int> functor;
		std::multimap<d_counter,const transgraph *> arguments;
		const morphan_result *morphan;
		public:
		transgraph(const std::pair<std::string,unsigned int>&,const morphan_result *);
		~transgraph();
		void insert(const unsigned int, const transgraph *);
		std::string transcript(const std::string&) const;
		unsigned int id() const;
	};

#endif
