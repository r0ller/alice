#ifndef NL_PREPROCESSOR_H
	#define NL_PREPROCESSOR_H

	#include "preprocessor.h"
	#include <string>
	#include <vector>
	#include <locale>
	#include "lexer.h"
	extern tokenpaths *token_paths;
	extern lexer *lex;

	class nl_preprocessor:public preprocessor{
		private:
		std::vector<std::string> rows;
		std::string lid;
		public:
			nl_preprocessor(const time_t&,const std::string&,const std::string&);
			~nl_preprocessor();
			std::pair<std::string,std::string> get_row(const unsigned int) const;
			std::string get_search_ref_id(const std::string&) const;
			std::string add_space(const std::string&);
	};

#endif
