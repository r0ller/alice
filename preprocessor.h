#ifndef PREPROCESSOR_H
	#define PREPROCESSOR_H

	#include <string>

	class preprocessor{
		protected:
			std::string timestamp;
		public:
			preprocessor(const time_t& timestamp);
			~preprocessor();
			virtual std::tuple<unsigned int,unsigned int,unsigned int,std::string> get_row(const unsigned int)=0;
	};

#endif
