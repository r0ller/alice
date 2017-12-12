%{
	extern "C"{
		int yyparse(void);
		int yylex(void);
		void yyerror(char const *yymsgp);
		int yywrap(void);
	}

	#include <iostream>
	#include <locale>
	#ifdef __ANDROID__
		#include "jni.h"
		JavaVM *jvm=NULL;
		jobject activity;
	#endif
	#ifdef __EMSCRIPTEN__
		#include <emscripten.h>
	#endif

	#include "logger.cpp"
	#include "hilib.h"
	#include "db.h"
	#include "lexer.h"
	#include "sp.h"
	morphan *stemmer=NULL;
	lexer *lex=NULL;
	interpreter *sparser=NULL;
	#include "tokenpaths.cpp"
	tokenpaths *token_paths=NULL;
	#include "query_result.cpp"
	#include "morphan_result.cpp"
	#include "morphan.cpp"
	#include "lexer.cpp"
	#include "sp.cpp"
	#include "transgraph.cpp"
%}
