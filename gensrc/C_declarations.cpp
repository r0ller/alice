%{
	extern "C"{
		int yyparse(void);
		int yylex(void);
		void yyerror(char const *yymsgp);
		int yywrap(void);
	}

	#ifdef __ANDROID__
	#include "log.h"
	#endif
	#include <iostream>
	#include "sqlite3.h"
	#include "db.h"
	#include "tokenpaths.cpp"
	tokenpaths *token_paths=NULL;
	#include "lexer.h"
	lexer *lex=NULL;
	#include "query_result.cpp"
	#include "db.cpp"
	#include "morphan_result.cpp"
	#include "morphan.cpp"
	morphan *stemmer=NULL;
	#include "sp.h"
	interpreter *sparser=NULL;
	#include "lexer.cpp"
	#include "sp.cpp"
	#include "transgraph.cpp"
%}
