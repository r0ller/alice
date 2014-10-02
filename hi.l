%{
#include <ctype.h>
#ifndef YACC
	#include <stdio.h>
	#include "sqlite3.h"
	#include <stdlib.h>
	#include "db.h"
	db *sqlite=NULL;
	#include "db.c"
	#include "lexer.h"
	lexer *lex=NULL;
	#include "lexer.c"
#else
	int line=0;
#endif
%}

%%
[ \t]+				;
!$					return 0;
[-a-zA-Z]+			{
					unsigned int i;
					char *errmsg=NULL;
					int token;

					for(i=0;i<yyleng;++i) yytext[i]=tolower(yytext[i]);
					if(lex==NULL)lex=new_lexer();
					token=lex->public.scan(lex, yytext, &errmsg);
					if(token<0){
						destroy_lexer(&lex);
						printf("Error: more than one token found for word '%s' in lexicon\n",yytext);
						if(errmsg!=NULL)
							printf("%s\n", errmsg);
						exit(EXIT_FAILURE);
					}
					#ifdef YACC
						printf("token+1: %d\n",token+1);
						return token+1;
					#else
						printf("token+1: %d\n",token+1);
					#endif
					}
%%

#ifndef YACC
int yywrap(void){
	return 1;
}

int main(void){
	
	sqlite=new_db();
	if(sqlite->public.open(sqlite,"hi.db")){
		fprintf(stderr, "Can't open database: %s\n", sqlite->public.get_errmsg(sqlite));
		sqlite->public.close(sqlite);
		exit(EXIT_FAILURE);
	}
	yylex();
	destroy_lexer(&lex);
	sqlite->public.close(sqlite);
	destroy_db(&sqlite);
	return 0;
}
#endif
