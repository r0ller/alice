#ifndef PREPROCESSOR_H
	#define PREPROCESSOR_H

	#include <string>

	class preprocessor{
		protected:
			std::string timestamp;
		public:
			preprocessor(const time_t& timestamp);
			~preprocessor();
			virtual std::pair<std::string,std::string> get_row(const unsigned int) const =0;
			virtual std::string get_search_ref_id(const std::string&) const =0;
	};

#endif
