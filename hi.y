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
	#include "morphan_result.cpp"
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

/* Every time one introduces a new gcat in the gcat table,
 * its token must be:
 * 1) taken from the gcat table entry,
 * 2) increased by 1,
 * 3) added here with that value,
 * and the whole stuff needs to be recompiled.
 * NOTE: the constant token t_Con has ALWAYS the value 1 here.*/
%start	S
%token	t_Con 1
%token	t_ENG_A 2
%token	t_ENG_Adv 3
%token	t_ENG_Det 4
%token	t_ENG_N_stem 5
%token	t_ENG_N_lfea_Pl 6
%token	t_ENG_N_lfea_Sg 7
%token	t_ENG_Prep 8
%token	t_ENG_QPro 9
%token	t_ENG_V_stem 10
%%
S	:	ENG_VP
{
				const node_info& ENG_VP=sparser->get_node_info($1);
				std::cout<<"S->ENG_VP"<<std::endl;
};
ENG_VP	:	ENG_Vbar1
{
				lexicon word;

				const node_info& ENG_Vbar1=sparser->get_node_info($1);
				word.gcat="ENG_VP";
				$$=sparser->set_node_info(word,ENG_Vbar1);
				std::cout<<"ENG_VP->ENG_Vbar1"<<std::endl;
}
	|	ENG_Vbar1 ENG_AdvP
{
				const node_info& ENG_Vbar1=sparser->get_node_info($1);
				const node_info& ENG_AdvP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar1 ENG_AdvP"<<std::endl;
}
	|	ENG_Vbar2
{
				lexicon word;

				const node_info& ENG_Vbar2=sparser->get_node_info($1);
				word.gcat="ENG_VP";
				$$=sparser->set_node_info(word,ENG_Vbar2);
				std::cout<<"ENG_VP->ENG_Vbar2"<<std::endl;
}
	|	ENG_Vbar2 ENG_PP
{
				const node_info& ENG_Vbar2=sparser->get_node_info($1);
				const node_info& ENG_PP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar2 ENG_PP"<<std::endl;
}
	|	ENG_Vbar3 ENG_NP
{
				const node_info& ENG_Vbar3=sparser->get_node_info($1);
				const node_info& ENG_NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar3 ENG_NP"<<std::endl;
};
ENG_Vbar3	:	ENG_V ENG_AdvP
{
				const node_info& ENG_V=sparser->get_node_info($1);
				const node_info& ENG_AdvP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VBAR3",ENG_V,ENG_AdvP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_Vbar3->ENG_V ENG_AdvP"<<std::endl;
};
ENG_Vbar2	:	ENG_Vbar1 ENG_PP
{
				const node_info& ENG_Vbar1=sparser->get_node_info($1);
				const node_info& ENG_PP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VBAR2",ENG_Vbar1,ENG_PP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_PP"<<std::endl;
}
		|	ENG_Vbar1 ENG_NP
{
				const node_info& ENG_Vbar1=sparser->get_node_info($1);
				const node_info& ENG_NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_NP"<<std::endl;
};
ENG_Vbar1	:	ENG_V ENG_NP
{
				const node_info& ENG_V=sparser->get_node_info($1);
				const node_info& ENG_NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VBAR1",ENG_V,ENG_NP);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_Vbar1->ENG_V ENG_NP"<<std::endl;
};
ENG_PP	:	ENG_Prep ENG_NP
{
				const node_info& ENG_Prep=sparser->get_node_info($1);
				const node_info& ENG_NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Prep->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_PP->ENG_Prep ENG_NP"<<std::endl;
};
ENG_NP	:	ENG_CNP
{
				lexicon word;

				const node_info& ENG_CNP=sparser->get_node_info($1);
				word.gcat="ENG_NP";
				$$=sparser->set_node_info(word,ENG_CNP);
				std::cout<<"ENG_NP->ENG_CNP"<<std::endl;
}
	|	ENG_QPro ENG_CNP
{
				const node_info& ENG_QPro=sparser->get_node_info($1);
				const node_info& ENG_CNP=sparser->get_node_info($2);
				/*	TODO: really need to check if there's a constant ?
					Currently, it's done to make functor argument diff easier.*/
				/*const node_info& object_node=sparser->get_node_info(sparser->get_object_node(CNP));
				if(object_node.right_child!=0){
					//printf("Syntax error: constants like %s cannot be quantified!\n",sparser->get_node_info(object_node.right_child).expression.c_str());
					return -1;
				}*/
				$$=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);
				/* No check for $$<0 since quantifier pronouns are not validated as
				 * everything in the current model seems to be countable.*/
				std::cout<<"ENG_NP->ENG_QPro ENG_CNP"<<std::endl;
};
/*	|	Pro
{
				std::cout<<"NP->Pro"<<std::endl;
};*/
ENG_CNP	:	ENG_A ENG_CNP
{
				const node_info& ENG_A=sparser->get_node_info($1);
				const node_info& ENG_CNP=sparser->get_node_info($2);
				/*TODO: ellenorizni, hogy ha a CNP parameteres akkor hiba mint a QPro CNP-nal!*/
				$$=sparser->combine_nodes("ENG_CNP",ENG_A,ENG_CNP);
				if($$<0){
					/*object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_CNP->ENG_A ENG_CNP"<<std::endl;
}
	|	ENG_N
{
				lexicon word;

				const node_info& ENG_N=sparser->get_node_info($1);
				word.gcat="ENG_CNP";
				$$=sparser->set_node_info(word,ENG_N);
				std::cout<<"ENG_CNP->ENG_N"<<std::endl;
};
ENG_AdvP : ENG_Adv
{
				lexicon word;

				const node_info& ENG_Adv=sparser->get_node_info($1);
				word.gcat="ENG_AdvP";
				$$=sparser->set_node_info(word,ENG_Adv);
				std::cout<<"ENG_AdvP->ENG_Adv"<<std::endl;
};
ENG_V	:	t_ENG_V_stem
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_QPro	:	t_ENG_QPro
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
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
				std::cout<<"ENG_N->ENG_N_Sg"<<std::endl;
}
	|	ENG_N_Pl
{
				lexicon word;

				const node_info& ENG_N_Pl=sparser->get_node_info($1);
				word.gcat="ENG_N";
				$$=sparser->set_node_info(word,ENG_N_Pl);
				std::cout<<"ENG_N->ENG_N_Pl"<<std::endl;
};
ENG_N_Sg_0Con	:	ENG_N_Stem	ENG_N_lfea_Sg
{
				const node_info& ENG_N_Stem=sparser->get_node_info($1);
				const node_info& ENG_N_lfea_Sg=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Stem,ENG_N_lfea_Sg);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg"<<std::endl;
};
ENG_N_Sg	:	ENG_N_Sg_0Con	ENG_1Con
{
				const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
				const node_info& ENG_1Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con ENG_1Con"<<std::endl;
}
	|	ENG_1Con
{
				lexicon word;

				const node_info& ENG_1Con=sparser->get_node_info($1);
				word.gcat="ENG_N_Sg";
				$$=sparser->set_node_info(word,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_1Con"<<std::endl;
};
ENG_N_Pl_0Con	:	ENG_N_Stem	ENG_N_lfea_Pl
{
				const node_info& ENG_N_Stem=sparser->get_node_info($1);
				const node_info& ENG_N_lfea_Pl=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl"<<std::endl;
};
ENG_1Con	:	ENG_Con
{
				lexicon word;

				const node_info& ENG_Con=sparser->get_node_info($1);
				word.gcat="ENG_1Con";
				$$=sparser->set_node_info(word,ENG_Con);
				std::cout<<"ENG_1Con->ENG_Con:"<<ENG_Con.expression.lexeme<<std::endl;
};
ENG_nCon	:	ENG_1Con	ENG_Con
{
				const node_info& ENG_1Con=sparser->get_node_info($1);
				const node_info& ENG_Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_nCon->ENG_1Con ENG_Con"<<std::endl;
}
	|	ENG_nCon ENG_Con
{
				const node_info& ENG_nCon=sparser->get_node_info($1);
				const node_info& ENG_Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_nCon->ENG_nCon ENG_Con"<<std::endl;
};
ENG_N_Pl	:	ENG_N_Pl_0Con
{
				lexicon word;

				const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
				word.gcat="ENG_N_Pl";
				$$=sparser->set_node_info(word,ENG_N_Pl_0Con);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con"<<std::endl;
}
	|	ENG_N_Pl_0Con	ENG_nCon
{
				const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
				const node_info& ENG_nCon=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con,ENG_nCon);
				if($$<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con ENG_nCon"<<std::endl;
}
	|	ENG_nCon
{
				lexicon word;

				const node_info& ENG_nCon=sparser->get_node_info($1);
				word.gcat="ENG_N_Pl";
				$$=sparser->set_node_info(word,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_nCon"<<std::endl;
};
ENG_N_Stem	: t_ENG_N_stem
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
				//WELL, it would have been good if I had written here if duplicating word info poses any problem...
				word.gcat="ENG_N_lfea_Sg";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_N_lfea_Pl	: t_ENG_N_lfea_Pl
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				word.gcat="ENG_N_lfea_Pl";
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
ENG_Con	:	t_Con
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
/*Exclude Det for now so now "Shut down THE comupter" won't work
ENG_Det :	t_ENG_Det
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned();
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
*/
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
			if(yyparse()==0){
				if(sparser->is_longest_match_for_semantic_rules_found()==true)
					std::cout<<"TRUE";
					//shell_command=sparser->get_command();
				else std::cout<<"FALSE";
			}
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
