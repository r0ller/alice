%{
#define YACC
#include <stdio.h>
#include "sqlite3.h"
#include <stdlib.h>
#include "db.h"
db *sqlite=NULL;
#include "db.c"
#include "lexer.h"
lexer *lex=NULL;
#include "lexer.c"
#include "sp.h"
sp *sparser=NULL;
#include "sp.c"
int yylex(void);
#include "lex.yy.c"
%}

/* TODO: check if rules can be set up without defining constants for tokens here.
 * Token constants block flexibility: every time one adds a new word to the lexicon,
 * a new token with the rowid of the entry (+1) must be added here and the whole
 * stuff needs to be recompiled.*/
%start	S
%token	hiCONSTANT 1
%token	hiLIST1 2
%token	hiLIST2 3
%token	hiCOPY 4
%token	hiDIRECTORY 5
%token	hiDIRECTORIES 6
%token	hiEXECUTABLE 7
%token	hiNONEXECUTABLE 8
%token	hiALL 9
%token	hiFILE 10
%token	hiFILES 11
%token	hiTO 12
%%
S	:	NP VP
{
				const node_info *VP;

				VP=sparser->public.get_node_info(sparser,$2);
				printf("S->NP VP\n");
				return 0;
};
VP	:	Vt NP
{
				const node_info *NP, *Vt, *object_node;

				Vt=sparser->public.get_node_info(sparser,$1);
				NP=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.combine_nodes(sparser,"VP",Vt,NP);
				if($$<0){
					object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Vt->expression,object_node->expression);
					return -1;
				}
				printf("VP->Vt NP\n");
}
	|	Vdt PP
{
				const node_info *Vdt, *PP, *object_node;
		
				Vdt=sparser->public.get_node_info(sparser,$1);
				PP=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.combine_nodes(sparser,"VP",Vdt,PP);
				if($$<0){
					object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);
					return -1;
				}
				printf("VP->Vdt PP\n");
};
Vdt	:	Vt NP
{
				const node_info *NP, *Vt, *object_node;
			
				Vt=sparser->public.get_node_info(sparser,$1);
				NP=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.combine_nodes(sparser,"Vdt",Vt,NP);
				if($$<0){
					object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Vt->expression,object_node->expression);
					return -1;
				}
				printf("Vdt->Vt NP\n");
};
Vt	:	V
{
				const node_info *V;
			
				V=sparser->public.get_node_info(sparser,$1);
				$$=sparser->public.set_node_info(sparser,"Vt",NULL,V);
				printf("Vt->V\n");
};
PP:		Prep NP
{
				const node_info *Prep, *NP;

				Prep=sparser->public.get_node_info(sparser,$1);
				NP=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.set_node_info(sparser,"PP",NULL,NP);
				printf("PP->Prep NP\n");
};
NP	:	CNP
{
				const node_info *CNP;

				CNP=sparser->public.get_node_info(sparser,$1);
				$$=sparser->public.set_node_info(sparser,"NP",NULL,CNP);
				printf("NP->CNP\n");
}
	|	QPro CNP
{
				const node_info *Det, *CNP, *object_node;

				Det=sparser->public.get_node_info(sparser,$1);
				CNP=sparser->public.get_node_info(sparser,$2);
				/*TODO: kell ellenőrizni, hogy van-e konstans?
				object_node=sparser->public.get_object_node(sparser,CNP);
				if(object_node->right_child!=NULL){
					printf("Syntax error: constants like %s cannot be quantified!\n",(*object_node->right_child)->expression);
					return 0;
				}*/
				$$=sparser->public.combine_nodes(sparser,"NP",Det,CNP);
				/* No check for $$<0 since quantifier pronouns are not validated as
				 * everything in the current model seems to be countable.*/
				printf("NP->QPro CNP:%s\n",Det->expression);
}
	|	Pro
{
				printf("NP->Pro\n");
};
CNP	:	A CNP
{
				const node_info *CNP, *A, *object_node;

				A=sparser->public.get_node_info(sparser,$1);
				CNP=sparser->public.get_node_info(sparser,$2);
				/*TODO: ellenőrizni, hogy ha a CNP paraméteres akkor hiba mint a QPro CNP-nél!*/
				$$=sparser->public.combine_nodes(sparser,"CNP",A,CNP);
				if($$<0){
					object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);
					return -1;
				}
				printf("CNP->A CNP:%s\n",A->expression);
}
	|	N
{
				const node_info *N;

				N=sparser->public.get_node_info(sparser,$1);
				$$=sparser->public.set_node_info(sparser,"CNP",NULL,N);
				printf("CNP->N:%s\n",N->expression);
};
V	:	hiLIST1
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiLIST1-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiCOPY
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiCOPY-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
};
QPro	:	hiALL
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiALL-1);
				/*TODO: consider what if quantifiers like ALL are handled as functors?*/
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
};
N	:	hiFILE
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiFILE-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiFILES
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiFILES-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiFILE Con
{
				lexicon word;
				const node_info *Con;

				word=lex->public.get_word_by_token(lex,hiFILE-1);
				Con=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,Con);
				printf("%s->%s %s\n",word.gcat,word.lexeme,Con->expression);
}
	|	hiDIRECTORY Con
{
				lexicon word;
				const node_info *Con;

				word=lex->public.get_word_by_token(lex,hiDIRECTORY-1);
				Con=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,Con);
				printf("%s->%s %s\n",word.gcat,word.lexeme,Con->expression);
}
	|	hiDIRECTORIES
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiDIRECTORIES-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	Con
{
				const node_info *Con;

				Con=sparser->public.get_node_info(sparser,$1);
				$$=sparser->public.set_node_info(sparser,"N",NULL,Con);
				printf("N->%s\n",Con->expression);
};
A	:	hiEXECUTABLE
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiEXECUTABLE-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiNONEXECUTABLE
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiNONEXECUTABLE-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
};
Prep:	hiTO
{
				lexicon word;
			
				word=lex->public.get_word_by_token(lex,hiTO-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
};
Pro	:	/*empty*/
{
				printf("Pro->null\n");
};
Con	:	hiCONSTANT
{
				$$=sparser->public.set_node_info(sparser,"Con",yytext,NULL);
				printf("Constant:%s\n",yytext);
};
%%

void yyerror(char *s){
	fprintf(stderr,"%s in command\n",s);
	line=0;
	return;
}

int yywrap(){
	return 1;
}

int main(void){

	sqlite=new_db();
	if(sqlite->public.open(sqlite,"hi.db")){
		fprintf(stderr, "Can't open database: %s\n", sqlite->public.get_errmsg(sqlite));
		sqlite->public.close(sqlite);
		exit(EXIT_FAILURE);
	}
	sparser=new_sp();
	while(!yyparse()){
		printf("VALID COMMAND\n");
		destroy_lexer(&lex);
		destroy_sp(&sparser);
		sparser=new_sp();
		}
	printf("INVALID COMMAND\n");
	destroy_sp(&sparser);
	destroy_lexer(&lex);
	sqlite->public.close(sqlite);
	destroy_db(&sqlite);
	return 0;
}
