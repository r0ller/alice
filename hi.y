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
	#include "query_result.cpp"
	#include "db.cpp"
	#include "morphan.cpp"
	morphan *stemmer=NULL;
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
%token	hiDOWN 19
%token	hiSHUT 20
%token	hiCOMPUTER 21
%token	hiTHE 22
%%
S	:	VP
{
				const node_info& VP=sparser->get_node_info($1);
				std::cout<<"S->VP"<<std::endl;
				return 0;
};
VP	:	Vbar1
{
				lexicon word;

				const node_info& Vbar1=sparser->get_node_info($1);
				word.gcat="VP";
				$$=sparser->set_node_info(word,Vbar1);
				std::cout<<"VP->Vbar1"<<std::endl;
}
	|	Vbar1 AdvP
{
				const node_info& Vbar1=sparser->get_node_info($1);
				const node_info& AdvP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("VP",Vbar1,AdvP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"VP->Vbar1 AdvP"<<std::endl;
}
	|	Vbar2
{
				lexicon word;

				const node_info& Vbar2=sparser->get_node_info($1);
				word.gcat="VP";
				$$=sparser->set_node_info(word,Vbar2);
				std::cout<<"VP->Vbar2"<<std::endl;
}
	|	Vbar2 PP
{
				const node_info& Vbar2=sparser->get_node_info($1);
				const node_info& PP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("VP",Vbar2,PP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"VP->Vbar2 PP"<<std::endl;
}
	|	Vbar3 NP
{
				const node_info& Vbar3=sparser->get_node_info($1);
				const node_info& NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("VP",Vbar3,NP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"VP->Vbar3 NP"<<std::endl;
};
Vbar3	:	V AdvP
{
				const node_info& V=sparser->get_node_info($1);
				const node_info& AdvP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("VBAR3",V,AdvP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"Vbar3->V AdvP"<<std::endl;
};
Vbar2	:	Vbar1 PP
{
				const node_info& Vbar1=sparser->get_node_info($1);
				const node_info& PP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("VBAR2",Vbar1,PP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"Vbar2->Vbar1 PP"<<std::endl;
}
		|	Vbar1 NP
{
				const node_info& Vbar1=sparser->get_node_info($1);
				const node_info& NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("VBAR2",Vbar1,NP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"Vbar2->Vbar1 NP"<<std::endl;
};
Vbar1	:	V NP
{
				const node_info& V=sparser->get_node_info($1);
				const node_info& NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("VBAR1",V,NP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"Vbar1->V NP"<<std::endl;
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
				lexicon word;

				const node_info& CNP=sparser->get_node_info($1);
				word.gcat="NP";
				$$=sparser->set_node_info(word,CNP);
				std::cout<<"NP->CNP"<<std::endl;
}
	|	QPro CNP
{
				const node_info& Det=sparser->get_node_info($1);
				const node_info& CNP=sparser->get_node_info($2);
				/*	TODO: really need to check if there's a constant ?
					Currently, it's done to make functor argument diff easier.*/
				/*const node_info& object_node=sparser->get_node_info(sparser->get_object_node(CNP));
				if(object_node.right_child!=0){
					//printf("Syntax error: constants like %s cannot be quantified!\n",sparser->get_node_info(object_node.right_child).expression.c_str());
					return -1;
				}*/
				$$=sparser->combine_nodes("NP",Det,CNP);
				/* No check for $$<0 since quantifier pronouns are not validated as
				 * everything in the current model seems to be countable.*/
				std::cout<<"NP->QPro CNP:"<<Det.expression.lexeme<<std::endl;
};
/*	|	Pro
{
				std::cout<<"NP->Pro"<<std::endl;
};*/
CNP	:	A CNP
{
				const node_info& A=sparser->get_node_info($1);
				const node_info& CNP=sparser->get_node_info($2);
				/*TODO: ellenõrizni, hogy ha a CNP paraméteres akkor hiba mint a QPro CNP-nál!*/
				$$=sparser->combine_nodes("CNP",A,CNP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"CNP->A CNP:"<<A.expression.lexeme<<std::endl;
}
	|	N
{
				lexicon word;

				const node_info& N=sparser->get_node_info($1);
				word.gcat="CNP";
				$$=sparser->set_node_info(word,N);
				std::cout<<"CNP->N:"<<N.expression.lexeme<<std::endl;
};
AdvP : Adv
{
				lexicon word;

				const node_info& Adv=sparser->get_node_info($1);
				word.gcat="ADVP";
				$$=sparser->set_node_info(word,Adv);
				std::cout<<"AdvP->Adv:"<<Adv.expression.lexeme<<std::endl;
};
V	:	hiLIST
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiLIST-1);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
QPro	:	hiALL
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiALL-1);
				/*TODO: consider what if quantifiers like ALL are handled as functors?*/
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_N	:	ENG_N_Sg
{
				lexicon word;
	
				const node_info& ENG_N_Sg=sparser->get_node_info($1);
				word.gcat="ENG_N";
				$$=sparser->set_node_info(word,ENG_N_Sg);
				std::cout<<"ENG_N->ENG_N_Sg:"<<ENG_N_Sg.expression.lexeme<<std::endl;
}
	|	ENG_N_Pl
{
				lexicon word;

				const node_info& ENG_N_Pl=sparser->get_node_info($1);
				word.gcat="ENG_N";
				$$=sparser->set_node_info(word,ENG_N_Pl);
				std::cout<<"ENG_N->ENG_N_Pl:"<<ENG_N_Pl.expression.lexeme<<std::endl;
};
ENG_N_Sg	:	ENG_N_stem
{
				lexicon word;

				const node_info& ENG_N_stem=sparser->get_node_info($1);
				word.gcat="ENG_N_stem";
				$$=sparser->set_node_info(word,ENG_N_stem);
				std::cout<<"ENG_N->ENG_N_Sg:"<<ENG_N_stem.expression.lexeme<<std::endl;
}
	|	ENG_Con
{
				lexicon word;

				const node_info& ENG_Con=sparser->get_node_info($1);
				word.gcat="ENG_Con";
				$$=sparser->set_node_info(word,ENG_Con);
				std::cout<<"ENG_N->ENG_Con:"<<ENG_Con.expression.lexeme<<std::endl;
};
ENG_N_Pl	:	ENG_N_stem	ENG_N_Pl
{
}
	|	ENG_N_Sg	ENG_Con
				//TODO: create an implementaion for set_node_info() that accepts two node_infos as input parameters
				//Question: what to do if both the stem and an affix have/can have functors like 'non' in 'nonexecutable'?
				//Shall combine_nodes() be called in such cases instead of set_node_info()? If so, how to decide when
				//any of these methods should be called? Can it be grasped at syntactic level? E.g. introducing a new
				//symbol for PREFIX and creating a rule like N: PREFIX N_stem in which we can decide if set_node_info()
				//or combine_nodes() should be called, depending on the prefix having a functor or not. If combine_nodes()
				//needs to be called, it must be enhanced (or the underlying parts) to be able to validate affixes
				//(all kinds:prefix, infix, suffix, circumfix) against verbs.
{
}
	|	ENG_N_Pl	ENG_Con
{
};
ENG_N_stem	: t_ENG_N_stem
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_N_lfea_Sg	: t_ENG_N_lfea_Sg
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();//TODO: it's unnecessary to duplicate the word info for each node that is related to an affix of the stem of the last scanned word
				//Create a method that returns the info only about the affix in question. Hint: create a method 'lexicon lexer::get_lexicon_info_by_token( uint token )' which
				//would return everything what last_word_scanned() returns but: if the token belongs to a stem it equals to calling last_word_scanned()
				//if the token belongs to an lfea, every field is the same as when calling last_word_scanned() but: the token field would contain the token of the lfea,
				//and if the affix has a functor, then the gcat is the corresponding PREFIX/INFIX/SUFFIX and the lexeme corresponds to that of the affix
				//if the affix does not have a functor, then the gcat is again either PREFIX/INFIX/SUFFIX but the lexeme field is empty
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_N_lfea_Pl	: t_ENG_N_lfea_Pl
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_A	:	t_ENG_A
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_Prep:	t_ENG_Prep
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned();
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
/*Pro	:	//empty
{
				std::cout<<"Pro->null"<<std::endl;
};*/
ENG_Con	:	t_ENG_Con
{
				const node_info empty_node_info={};
				lexicon word;

				word=lex->last_word_scanned();
				word.gcat="CON";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<"Constant:"<<word.word<<std::endl;
};
ENG_Adv	:	t_ENG_Adv
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned();
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_Det :	t_ENG_Det
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned();
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
%%

int yylex(void){
	int token;
	lexicon word={};

	token=lex->next_token();
	word=lex->last_word_scanned();//Check if any word was scanned
	if(token==0&&word.word.empty()==true) return 0;//Return 0 (historic indicator of YACC about end of input stream) only if no word was scanned last time where as a corollary token = 0 as well
	else return token+1;//return token+1 if a word was scanned but could not be tokenized (token=0)->consider it a constant (yacc %token for constant is 1)
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
			if(yyparse()==0)std::cout<<"TRUE";//shell_command=sparser->get_command();
			else std::cout<<"FALSE";
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
