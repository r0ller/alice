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
char *input_stream=NULL;
int yylex(void);
#include "lex.yy.c"
%}

/* TODO: check if rules can be set up without defining constants for tokens here.
 * Token constants block flexibility: every time one adds a new word to the lexicon,
 * a new token with the rowid of the entry (+1) must be added here and the whole
 * stuff needs to be recompiled.*/
%start	S
%token	hiCONSTANT 1
%token	hiLIST 2
%token	hiCOPY 3
%token	hiDIRECTORY 4
%token	hiDIRECTORIES 5
%token	hiEXECUTABLE 6
%token	hiNONEXECUTABLE 7
%token	hiALL 8
%token	hiFILE 9
%token	hiFILES 10
%token	hiTO 11
%token	hiREMOVE 12
%token	hiDELETE 13
%token	hiFROM 14
%token	hiCHANGE 15
%token	hiMOVE 16
%token	hiIN 17
%token	hiMAKE 18
%%
S	:	NP VP
{
				const node_info *VP;

				VP=sparser->public.get_node_info(sparser,$2);
				printf("S->NP VP\n");
				return 0;
};
VP	:	Vt
{
				const node_info *Vt;

				Vt=sparser->public.get_node_info(sparser,$1);
				$$=sparser->public.set_node_info(sparser,"VP",NULL,Vt);
				printf("VP->Vt\n");
}
	|	Vdt
{
				const node_info *Vdt;

				Vdt=sparser->public.get_node_info(sparser,$1);
				$$=sparser->public.set_node_info(sparser,"VP",NULL,Vdt);
				printf("VP->Vdt\n");
}
	|	Vdt PP
{
				const node_info *Vdt, *PP, *object_node;
		
				Vdt=sparser->public.get_node_info(sparser,$1);
				PP=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.combine_nodes(sparser,"VP",Vdt,PP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				printf("VP->Vdt PP\n");
};
Vdt	:	Vt PP
{
				const node_info *Vt, *PP, *object_node;
			
				Vt=sparser->public.get_node_info(sparser,$1);
				PP=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.combine_nodes(sparser,"Vdt",Vt,PP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vt->left_child->expression,object_node->expression);*/
					return -1;
				}
				printf("Vdt->Vt PP\n");
};
Vt	:	V NP
{
				const node_info *V, *NP, *object_node;

				V=sparser->public.get_node_info(sparser,$1);
				NP=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.combine_nodes(sparser,"Vt",V,NP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				printf("Vt->V NP\n");
};
PP	:	Prep NP
{
				const node_info *Prep, *NP, *object_node;

				Prep=sparser->public.get_node_info(sparser,$1);
				NP=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.combine_nodes(sparser,"PP",Prep,NP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Prep->expression,object_node->expression);*/
					return -1;
				}
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
				/*	TODO: really need to check if there's a constant ?
					Currently, it's done to make functor argument diff easier.*/
				object_node=sparser->public.get_object_node(sparser,CNP);
				if(object_node->right_child!=NULL){
					/*printf("Syntax error: constants like %s cannot be quantified!\n",object_node->right_child->expression);*/
					return -1;
				}
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
					/*object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);*/
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
V	:	hiLIST
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiLIST-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiCOPY
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiCOPY-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiREMOVE
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiREMOVE-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiDELETE
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiDELETE-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiCHANGE
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiCHANGE-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiMOVE
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiMOVE-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiMAKE
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiMAKE-1);
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
N	:	hiFILE Con
{
				lexicon word;
				const node_info *Con;
	
				word=lex->public.get_word_by_token(lex,hiFILE-1);
				Con=sparser->public.get_node_info(sparser,$2);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,Con);
				printf("%s->%s %s\n",word.gcat,word.lexeme,Con->expression);
}
	|	hiFILES
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiFILES-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiDIRECTORY
{
				lexicon word;

				word=lex->public.get_word_by_token(lex,hiDIRECTORY-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
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
}
	|	hiFROM
{
				lexicon word;
			
				word=lex->public.get_word_by_token(lex,hiFROM-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
}
	|	hiIN
{
				lexicon word;
			
				word=lex->public.get_word_by_token(lex,hiIN-1);
				$$=sparser->public.set_node_info(sparser,word.gcat,word.lexeme,NULL);
				printf("%s->%s\n",word.gcat,word.lexeme);
};
Pro	:	/*empty*/
{
				printf("Pro->null\n");
};
Con	:	hiCONSTANT
{
				/*if(sparser->private.nr_of_nodes==0)return -1;*/
				$$=sparser->public.set_node_info(sparser,"Con",yytext,NULL);
				printf("Constant:%s\n",yytext);
};
%%

void yyerror(char *s){
	/*fprintf(stderr,"%s in command\n",s);*/
	line=0;
	return;
}

int yywrap(){
	return 1;
}

const char *hi(const char *human_command){
const char *shell_command=NULL;

	if(human_command!=NULL){
		if(human_command[strlen(human_command)]!='!'){
			input_stream=malloc(strlen(human_command)+3);
			sprintf(input_stream,"%s!\n",human_command);
			}
		else{
			input_stream=malloc(strlen(human_command)+2);
			sprintf(input_stream,"%s\n",human_command);
			}
		sqlite=new_db();
		if(sqlite->public.open(sqlite,"hi.db")){
			/*fprintf(stderr, "Can't open database: %s\n", sqlite->public.get_errmsg(sqlite));*/
			sqlite->public.close(sqlite);
			exit(EXIT_FAILURE);
		}
		sparser=new_sp();
		if(yyparse()==0)shell_command=sparser->public.get_command(sparser);
		destroy_sp(&sparser);
		destroy_lexer(&lex);
		sqlite->public.close(sqlite);
		destroy_db(&sqlite);
		free(input_stream);
		return shell_command;
	}
}
