%{
	extern "C"{
		int yyparse(void);
		int yylex(void);
		void yyerror(char *);
		int yywrap(void);
	}

	#include <iostream>
	#include "sqlite3.h"
	#include "db.h"
	#include "db.cpp"
	#include "lexer.h"
	lexer *lex=NULL;
	#include "lexer.cpp"
	#include "sp.h"
	interpreter *sparser=NULL;
	#include "sp.cpp"
	int line=0;
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
				const node_info& VP=sparser->get_node_info($2);
				std::cout<<"S->NP VP"<<std::endl;
				return 0;
};
VP	:	Vt
{
				const node_info& Vt=sparser->get_node_info($1);
				$$=sparser->set_node_info("VP","",Vt);
				std::cout<<"VP->Vt"<<std::endl;
}
	|	Vdt
{
				const node_info& Vdt=sparser->get_node_info($1);
				$$=sparser->set_node_info("VP","",Vdt);
				std::cout<<"VP->Vdt"<<std::endl;
}
	|	Vdt PP
{
				const node_info& Vdt=sparser->get_node_info($1);
				const node_info& PP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("VP",Vdt,PP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"VP->Vdt PP"<<std::endl;
};
Vdt	:	Vt PP
{
				const node_info& Vt=sparser->get_node_info($1);
				const node_info& PP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("Vdt",Vt,PP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"Vdt->Vt PP"<<std::endl;
};
Vt	:	V NP
{
				const node_info& V=sparser->get_node_info($1);
				const node_info& NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("Vt",V,NP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"Vt->V NP"<<std::endl;
};
PP	:	Prep NP
{
				const node_info& Prep=sparser->get_node_info($1);
				const node_info& NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("PP",Prep,NP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Prep->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"PP->Prep NP"<<std::endl;
};
NP	:	CNP
{
				const node_info& CNP=sparser->get_node_info($1);
				$$=sparser->set_node_info("NP","",CNP);
				std::cout<<"NP->CNP"<<std::endl;
}
	|	QPro CNP
{
				const node_info& Det=sparser->get_node_info($1);
				const node_info& CNP=sparser->get_node_info($2);
				/*	TODO: really need to check if there's a constant ?
					Currently, it's done to make functor argument diff easier.*/
				const node_info& object_node=sparser->get_node_info(sparser->get_object_node(CNP));
				if(object_node.right_child!=0){
					//printf("Syntax error: constants like %s cannot be quantified!\n",sparser->get_node_info(object_node.right_child).expression.c_str());
					return -1;
				}
				$$=sparser->combine_nodes("NP",Det,CNP);
				/* No check for $$<0 since quantifier pronouns are not validated as
				 * everything in the current model seems to be countable.*/
				std::cout<<"NP->QPro CNP:"<<Det.expression<<std::endl;
}
	|	Pro
{
				std::cout<<"NP->Pro"<<std::endl;
};
CNP	:	A CNP
{
				const node_info& A=sparser->get_node_info($1);
				const node_info& CNP=sparser->get_node_info($2);
				/*TODO: ellenőrizni, hogy ha a CNP paraméteres akkor hiba mint a QPro CNP-nél!*/
				$$=sparser->combine_nodes("CNP",A,CNP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"CNP->A CNP:"<<A.expression<<std::endl;
}
	|	N
{
				const node_info& N=sparser->get_node_info($1);
				$$=sparser->set_node_info("CNP","",N);
				std::cout<<"CNP->N:"<<N.expression<<std::endl;
};
V	:	hiLIST
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiLIST-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiCOPY
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiCOPY-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiREMOVE
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiREMOVE-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiDELETE
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiDELETE-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiCHANGE
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiCHANGE-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiMOVE
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiMOVE-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiMAKE
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiMAKE-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
QPro	:	hiALL
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiALL-1);
				/*TODO: consider what if quantifiers like ALL are handled as functors?*/
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
N	:	hiFILE Con
{
				lexicon word;
	
				word=lex->get_word_by_token(hiFILE-1);
				const node_info& Con=sparser->get_node_info($2);
				$$=sparser->set_node_info(word.gcat,word.lexeme,Con);
				std::cout<<word.gcat<<"->"<<word.lexeme<<" "<<Con.expression<<std::endl;
}
	|	hiFILES
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiFILES-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiDIRECTORY
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiDIRECTORY-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiDIRECTORY Con
{
				lexicon word;

				word=lex->get_word_by_token(hiDIRECTORY-1);
				const node_info& Con=sparser->get_node_info($2);
				$$=sparser->set_node_info(word.gcat,word.lexeme,Con);
				std::cout<<word.gcat<<"->"<<word.lexeme<<" "<<Con.expression<<std::endl;
}
	|	hiDIRECTORIES
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiDIRECTORIES-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	Con
{
				const node_info& Con=sparser->get_node_info($1);
				$$=sparser->set_node_info("N","",Con);
				std::cout<<"N->"<<Con.expression<<std::endl;
};
A	:	hiEXECUTABLE
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiEXECUTABLE-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiNONEXECUTABLE
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiNONEXECUTABLE-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
Prep:	hiTO
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiTO-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiFROM
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiFROM-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
	|	hiIN
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiIN-1);
				$$=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
Pro	:	/*empty*/
{
				std::cout<<"Pro->null"<<std::endl;
};
Con	:	hiCONSTANT
{
				const node_info empty_node_info={};

				const std::string& constant=lex->last_word_scanned();
				$$=sparser->set_node_info("Con",constant,empty_node_info);
				std::cout<<"Constant:"<<constant<<std::endl;
};
%%

int yylex(void){
	int token;

	token=lex->next_token();
	if(token==0&&lex->last_word_scanned().empty()==true) return 0;//Historic indicator of YACC about end of input stream
	else return token+1;
}

void yyerror(char *s){
	//fprintf(stderr,"%s in command\n",s);
	line=0;
	return;
}

int yywrap(){
	return 1;
}

const char *hi(const char *human_input){//TODO: introduce new parameter char *trace to return traces if not NULL
	std::string shell_command;
	db *sqlite=NULL;

	try{
		if(human_input!=NULL){
			lex=new lexer(human_input);
			sqlite=db::get_instance();
			sqlite->open("hi.db");
			sparser=new interpreter;
			if(yyparse()==0)shell_command=sparser->get_command();
			delete sparser;
			sparser=NULL;
			delete lex;
			lex=NULL;
			sqlite->close();
			delete sqlite;
			sqlite=NULL;
			return shell_command.c_str();
		}
	}
	catch(sql_execution_error& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(failed_to_open_db& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(failed_to_close_db& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(lexicon_type_and_db_table_schema_mismatch& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(more_than_one_token_found& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(object_node_missing& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(head_node_missing& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(invalid_combination& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(std::exception& exception){
		std::cout<<exception.what()<<std::endl;
		exit(EXIT_FAILURE);
	}
	catch(...){
		std::cout<<"Unexpected error ..."<<std::endl;
		exit(EXIT_FAILURE);
	}
}
