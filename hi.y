%{
	extern "C"{
		int yyparse(void);
		int yylex(void);
		void yyerror(char *);
		int yywrap(void);
	}

	#ifdef __ANDROID__
	#include "log.h"
	#endif
	#include <iostream>
	#include "sqlite3.h"
	#include "db.h"
	#include "tokenpaths.cpp";
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
	#include "transgraph.cpp";
	void yyerror(char const *yymsgp);
%}

/* Every time one introduces a new gcat in the gcat table,
 * its token must be:
 * 1) taken from the gcat table entry,
 * 2) increased by 1,
 * 3) added here with that value,
 * and the whole stuff needs to be recompiled.
 * NOTE: the constant token t_Con has ALWAYS the value 1 here.*/
%define parse.lac full
%define parse.error verbose
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
%token	t_ENG_V_lfea_aux 11
%token	t_ENG_RPro_stem 12
%token	t_ENG_RPro_lfea_relative 13
%token	t_ENG_Neg 14
%token	t_HUN_Con_lfea_Acc 15
%token	t_HUN_Verb_stem 16
%token	t_HUN_Verb_lfea_ConjDefSg2 17
%token	t_HUN_Vbpfx 18
%token	t_ENG_Tense_particle 19
%token	t_ENG_Indef 20
%token	t_ENG_fwVowel 21
%token	t_ENG_fwConsonant 22
%token	t_ENG_swVowel 23
%token	t_ENG_swConsonant 24
%token	t_ENG_V_lfea_ger 25
%%
S	:	ENG_VP
{
				const node_info& ENG_VP=sparser->get_node_info($1);
				std::cout<<"S->ENG_VP"<<std::endl;
}
	|	HUN_VP
{
				const node_info& HUN_VP=sparser->get_node_info($1);
				std::cout<<"S->HUN_VP"<<std::endl;
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
				std::cout<<"ENG_VP->ENG_Vbar2 ENG_PP"<<std::endl;
}
	|	ENG_Vbar3 ENG_NP
{
				const node_info& ENG_Vbar3=sparser->get_node_info($1);
				const node_info& ENG_NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);
				std::cout<<"ENG_VP->ENG_Vbar3 ENG_NP"<<std::endl;
}
	|	ENG_Vbar1 ENG_RC
{
				const node_info& ENG_Vbar1=sparser->get_node_info($1);
				const node_info& ENG_RC=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);
				std::cout<<"ENG_VP->ENG_Vbar1 ENG_RC"<<std::endl;
}
	|	ENG_Vbar2 ENG_RC
{
				const node_info& ENG_Vbar2=sparser->get_node_info($1);
				const node_info& ENG_RC=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);
				std::cout<<"ENG_VP->ENG_Vbar2 ENG_RC"<<std::endl;
}
	|	ENG_Vbar4 ENG_DP
{
/*
an equipment is an entity ???is countable/uncountable differentiation necessary in the syntax???
to order is an activity
flying, is an activity
Consider:
topping is a property
topping is a property of pizza
type is a property
type is a property of pizza
hawaiian is a type of pizza
cheese is a topping
types of pizza are hawaiian margherita pepperoni
*/
				const node_info& ENG_Vbar4=sparser->get_node_info($1);
				const node_info& ENG_DP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);
				std::cout<<"ENG_VP->ENG_Vbar4 ENG_DP"<<std::endl;
};
ENG_IVP	:	ENG_V ENG_PP
{
				const node_info& ENG_V=sparser->get_node_info($1);
				const node_info& ENG_PP=sparser->get_node_info($2);
				sparser->add_feature_to_leaf(ENG_V,"RCV");
				$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
				std::cout<<"ENG_IVP->ENG_V ENG_PP"<<std::endl;
}
		|	ENG_NV ENG_PP
{
				const node_info& ENG_NV=sparser->get_node_info($1);
				const node_info& ENG_PP=sparser->get_node_info($2);
				sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
				$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
				std::cout<<"ENG_IVP->ENG_NV ENG_PP"<<std::endl;
};
ENG_NV	:	ENG_V ENG_NEG
{
				const node_info& ENG_V=sparser->get_node_info($1);
				const node_info& ENG_NEG=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_NV",ENG_V,ENG_NEG);
				std::cout<<"ENG_NV->ENG_V ENG_NEG"<<std::endl;
};
ENG_Vbar3	:	ENG_V ENG_AdvP
{
				const node_info& ENG_V=sparser->get_node_info($1);
				const node_info& ENG_AdvP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VBAR3",ENG_V,ENG_AdvP);
				std::cout<<"ENG_Vbar3->ENG_V ENG_AdvP"<<std::endl;
};
ENG_Vbar2	:	ENG_Vbar1 ENG_PP
{
				const node_info& ENG_Vbar1=sparser->get_node_info($1);
				const node_info& ENG_PP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VBAR2",ENG_Vbar1,ENG_PP);
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_PP"<<std::endl;
}
		|	ENG_Vbar1 ENG_NP
{
				const node_info& ENG_Vbar1=sparser->get_node_info($1);
				const node_info& ENG_NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_VBAR2",ENG_Vbar1,ENG_NP);
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_NP"<<std::endl;
};
ENG_Vbar1	:	ENG_V ENG_NP
{
				const node_info& ENG_V=sparser->get_node_info($1);
				const node_info& ENG_NP=sparser->get_node_info($2);
				sparser->add_feature_to_leaf(ENG_V,"main_verb");
				$$=sparser->combine_nodes("ENG_VBAR1",ENG_V,ENG_NP);
				std::cout<<"ENG_Vbar1->ENG_V ENG_NP"<<std::endl;
};
ENG_Vbar4	:	ENG_DP ENG_V
{
				const node_info& ENG_DP=sparser->get_node_info($1);
				const node_info& ENG_V=sparser->get_node_info($2);
				sparser->add_feature_to_leaf(ENG_V,"main_verb");
				$$=sparser->combine_nodes("ENG_VBAR4",ENG_V,ENG_DP);
				std::cout<<"ENG_Vbar4->ENG_DP ENG_V"<<std::endl;
}
			|	ENG_TP ENG_V
{
				const node_info& ENG_TP=sparser->get_node_info($1);
				const node_info& ENG_V=sparser->get_node_info($2);
				sparser->add_feature_to_leaf(ENG_V,"main_verb");
				$$=sparser->combine_nodes("ENG_VBAR4",ENG_V,ENG_TP);
				std::cout<<"ENG_Vbar4->ENG_TP ENG_V"<<std::endl;
};
ENG_PP	:	ENG_Prep ENG_NP
{
				const node_info& ENG_Prep=sparser->get_node_info($1);
				const node_info& ENG_NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);
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
		|	ENG_AP
{
				lexicon word;

				const node_info& ENG_AP=sparser->get_node_info($1);
				word.gcat="ENG_NP";
				$$=sparser->set_node_info(word,ENG_AP);
				std::cout<<"ENG_NP->ENG_AP"<<std::endl;
}
		|	ENG_QPro ENG_CNP
{
				const node_info& ENG_QPro=sparser->get_node_info($1);
				const node_info& ENG_CNP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);
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
				$$=sparser->combine_nodes("ENG_CNP",ENG_A,ENG_CNP);
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
ENG_V	:	ENG_V_stem
{
				lexicon word;

				const node_info& ENG_V_Stem=sparser->get_node_info($1);
				word.gcat="ENG_V";
				$$=sparser->set_node_info(word,ENG_V_Stem);
				std::cout<<"ENG_V->ENG_V_Stem"<<std::endl;
}
	|	ENG_V_stem ENG_V_lfea_aux
{
				const node_info& ENG_V_stem=sparser->get_node_info($1);
				const node_info& ENG_V_lfea_aux=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_V",ENG_V_stem,ENG_V_lfea_aux);
				std::cout<<"ENG_V->ENG_V_stem ENG_V_lfea_aux"<<std::endl;
};
ENG_V_ger:	ENG_V_stem ENG_V_lfea_ger
{
				const node_info& ENG_V_stem=sparser->get_node_info($1);
				const node_info& ENG_V_lfea_ger=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_V",ENG_V_stem,ENG_V_lfea_ger);
				std::cout<<"ENG_V->ENG_V_stem ENG_V_lfea_ger"<<std::endl;
};
ENG_V_stem	: t_ENG_V_stem
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_V_stem);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_V_lfea_aux	: t_ENG_V_lfea_aux
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_V_lfea_aux);
//				word.gcat="Aux";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_V_lfea_ger	: t_ENG_V_lfea_ger
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_V_lfea_ger);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_QPro	:	t_ENG_QPro
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_QPro);
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
ENG_DP :	ENG_Indef_Det_a ENG_N_Sg_0Con_swC
{
				const node_info& ENG_Indef_Det_a=sparser->get_node_info($1);
				const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);
				std::cout<<"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC"<<std::endl;
}
	|	ENG_Indef_Det_an ENG_N_Sg_0Con_swV
{
				const node_info& ENG_Indef_Det_an=sparser->get_node_info($1);
				const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);
				std::cout<<"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV"<<std::endl;
};
ENG_N_Sg_0Con	:	ENG_N_Stem	ENG_N_lfea_Sg
{
				const node_info& ENG_N_Stem=sparser->get_node_info($1);
				const node_info& ENG_N_lfea_Sg=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Sg0Con",ENG_N_Stem,ENG_N_lfea_Sg);
				std::cout<<"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg"<<std::endl;
};
ENG_N_Sg_0Con_swC	:	ENG_N_Sg_0Con	ENG_lfea_swConsonant
{
				const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
				const node_info& ENG_lfea_swConsonant=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);
				std::cout<<"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant"<<std::endl;
};
ENG_N_Sg_0Con_swV	:	ENG_N_Sg_0Con	ENG_lfea_swVowel
{
				const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
				const node_info& ENG_lfea_swVowel=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);
				std::cout<<"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel"<<std::endl;
};
ENG_N_Sg	:	ENG_N_Sg_0Con_swC	ENG_1Con
{
				const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($1);
				const node_info& ENG_1Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("Sg",ENG_N_Sg_0Con_swC,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con"<<std::endl;
}
	|	ENG_N_Sg_0Con_swV	ENG_1Con
{
				const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($1);
				const node_info& ENG_1Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("Sg",ENG_N_Sg_0Con_swV,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con"<<std::endl;
}
	|	ENG_1Con
{
				lexicon word;

				const node_info& ENG_1Con=sparser->get_node_info($1);
				word.gcat="Sg";
				$$=sparser->set_node_info(word,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_1Con"<<std::endl;
}
	|	ENG_N_Sg_0Con_swC
{
				lexicon word;

				const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($1);
				word.gcat="Sg";
				$$=sparser->set_node_info(word,ENG_N_Sg_0Con_swC);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con_swC"<<std::endl;
}
	|	ENG_N_Sg_0Con_swV
{
				lexicon word;

				const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($1);
				word.gcat="Sg";
				$$=sparser->set_node_info(word,ENG_N_Sg_0Con_swV);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con_swV"<<std::endl;
};
ENG_N_Pl_0Con	:	ENG_N_Stem	ENG_N_lfea_Pl
{
				const node_info& ENG_N_Stem=sparser->get_node_info($1);
				const node_info& ENG_N_lfea_Pl=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);
				std::cout<<"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl"<<std::endl;
};
ENG_N_Pl_0Con_swC	:	ENG_N_Pl_0Con	ENG_lfea_swConsonant
{
				const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
				const node_info& ENG_lfea_swConsonant=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);
				std::cout<<"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant"<<std::endl;
};
ENG_N_Pl_0Con_swV	:	ENG_N_Pl_0Con	ENG_lfea_swVowel
{
				const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
				const node_info& ENG_lfea_swVowel=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);
				std::cout<<"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel"<<std::endl;
};
ENG_1Con	:	ENG_Con
{
				lexicon word;

				const node_info& ENG_Con=sparser->get_node_info($1);
				word.gcat="ENG_1Con";
				$$=sparser->set_node_info(word,ENG_Con);
				//TODO: find out why printing ENG_Con.expression.lexeme leads to segfault
				//in case of "list directory abc" but not in case of "list abc"
				//std::cout<<"ENG_1Con->ENG_Con:"<<ENG_Con.expression.lexeme<<std::endl;
				std::cout<<"ENG_1Con->ENG_Con"<<std::endl;
};
ENG_nCon	:	ENG_1Con	ENG_Con
{
				const node_info& ENG_1Con=sparser->get_node_info($1);
				const node_info& ENG_Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);
				std::cout<<"ENG_nCon->ENG_1Con ENG_Con"<<std::endl;
}
	|	ENG_nCon ENG_Con
{
				const node_info& ENG_nCon=sparser->get_node_info($1);
				const node_info& ENG_Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);
				std::cout<<"ENG_nCon->ENG_nCon ENG_Con"<<std::endl;
};
ENG_N_Pl	:	ENG_N_Pl_0Con_swC
{
				lexicon word;

				const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($1);
				word.gcat="ENG_N_Pl";
				$$=sparser->set_node_info(word,ENG_N_Pl_0Con_swC);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con_swC"<<std::endl;
}
	|	ENG_N_Pl_0Con_swV
{
				lexicon word;

				const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($1);
				word.gcat="ENG_N_Pl";
				$$=sparser->set_node_info(word,ENG_N_Pl_0Con_swV);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con_swV"<<std::endl;
}
	|	ENG_N_Pl_0Con_swC	ENG_nCon
{
				const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($1);
				const node_info& ENG_nCon=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon"<<std::endl;
}
	|	ENG_N_Pl_0Con_swV	ENG_nCon
{
				const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($1);
				const node_info& ENG_nCon=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon"<<std::endl;
}
	|	ENG_nCon
{
				lexicon word;

				const node_info& ENG_nCon=sparser->get_node_info($1);
				word.gcat="ENG_N_Pl";
				$$=sparser->set_node_info(word,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_nCon"<<std::endl;
}
	|	ENG_N_Sg	ENG_nCon
{
				//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
				//that a singular noun cannot combine with more than one constant like in 'list file abc def'
				//TODO: Any better solution???
				return -1;
};
ENG_N_Stem	: t_ENG_N_stem
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_N_stem);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_N_lfea_Sg	: t_ENG_N_lfea_Sg
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_N_lfea_Sg);
//				word.gcat="ENG_N_lfea_Sg";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_N_lfea_Pl	: t_ENG_N_lfea_Pl
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_N_lfea_Pl);
//				word.gcat="ENG_N_lfea_Pl";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_A	:	t_ENG_A
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_A);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_AP	:	ENG_1Con ENG_N_Pl_0Con_swC
{
				const node_info& ENG_1Con=sparser->get_node_info($1);
				const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_AP",ENG_1Con,ENG_N_Pl_0Con_swC);
				std::cout<<"ENG_AP->ENG_1Con ENG_N_Pl_0Con_swC"<<std::endl;
}
	|	ENG_1Con ENG_N_Pl_0Con_swV
{
				const node_info& ENG_1Con=sparser->get_node_info($1);
				const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_AP",ENG_1Con,ENG_N_Pl_0Con_swV);
				std::cout<<"ENG_AP->ENG_1Con ENG_N_Pl_0Con_swV"<<std::endl;
};
ENG_Prep:	t_ENG_Prep
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_Prep);
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

				word=lex->last_word_scanned(t_Con);
//				word.gcat="CON";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<"Constant:"<<word.word<<std::endl;
};
ENG_Adv	:	t_ENG_Adv
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_Adv);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_RPro:		ENG_RPro_stem ENG_RPro_lfea_relative
{
				const node_info& ENG_RPro_stem=sparser->get_node_info($1);
				const node_info& ENG_RPro_lfea_relative=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_RPRO",ENG_RPro_stem,ENG_RPro_lfea_relative);
				std::cout<<"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative"<<std::endl;
};
ENG_RPro_stem : t_ENG_RPro_stem
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_RPro_stem);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_RPro_lfea_relative	: t_ENG_RPro_lfea_relative
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_RPro_lfea_relative);
//				word.gcat="Relative";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
/*ENG_T_empty	:		//empty
{
				lexicon word;
				const node_info empty_node_info={};

				word.gcat="T";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<"ENG_T_empty->null"<<std::endl;
};*/
ENG_Tense_particle	:	t_ENG_Tense_particle //e.g. "to"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_Tense_particle);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_TP	:	ENG_Tense_particle ENG_V_stem
{
				const node_info& ENG_Tense_particle=sparser->get_node_info($1);
				const node_info& ENG_V_stem=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_stem);
				std::cout<<"ENG_TP->ENG_Tense_particle ENG_V_stem"<<std::endl;
}
		|	ENG_V_ger
{
				lexicon word;

				const node_info& ENG_V_ger=sparser->get_node_info($1);
				word.gcat="ENG_V_ger";
				$$=sparser->set_node_info(word,ENG_V_ger);
				std::cout<<"ENG_TP->ENG_V_ger"<<std::endl;
};
/*		|	ENG_T_empty ENG_V_ger
{
				const node_info& ENG_T_empty=sparser->get_node_info($1);
				const node_info& ENG_V_ger=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_TP",ENG_T_empty,ENG_V_ger);
				std::cout<<"ENG_TP->ENG_T_empty ENG_V_ger"<<std::endl;
};*/
ENG_RC:		ENG_RPro ENG_IVP
{
				const node_info& ENG_RPro=sparser->get_node_info($1);
				const node_info& ENG_IVP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);
				std::cout<<"ENG_RC->ENG_RPro ENG_IVP"<<std::endl;
};
ENG_NEG:	t_ENG_Neg
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_Neg);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_Indef_Det_an:	ENG_Indef_Det ENG_lfea_fwVowel
{
				const node_info& ENG_Indef_Det=sparser->get_node_info($1);
				const node_info& ENG_lfea_fwVowel=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);
				std::cout<<"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel"<<std::endl;
};
ENG_Indef_Det_a:	ENG_Indef_Det ENG_lfea_fwConsonant
{
				const node_info& ENG_Indef_Det=sparser->get_node_info($1);
				const node_info& ENG_lfea_fwConsonant=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);
				std::cout<<"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant"<<std::endl;
};
ENG_Indef_Det:		ENG_Det_stem ENG_lfea_IndefDet
{
				const node_info& ENG_Det_stem=sparser->get_node_info($1);
				const node_info& ENG_lfea_IndefDet=sparser->get_node_info($2);
				$$=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);
				std::cout<<"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet"<<std::endl;
};
ENG_Det_stem:	t_ENG_Det
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_Det);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_lfea_IndefDet:	t_ENG_Indef
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_Indef);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_lfea_fwVowel:	t_ENG_fwVowel
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_fwVowel);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_lfea_fwConsonant:	t_ENG_fwConsonant
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_fwConsonant);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_lfea_swVowel:	t_ENG_swVowel
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_swVowel);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
ENG_lfea_swConsonant:	t_ENG_swConsonant
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_swConsonant);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
/*-----------------HUNGARIAN RULES-----------------*/
HUN_VP	:	HUN_ImpVerbPfx HUN_NP
{
				const node_info& HUN_ImpVerbPfx=sparser->get_node_info($1);
				const node_info& HUN_NP=sparser->get_node_info($2);
				$$=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_NP);
				std::cout<<"HUN_VP->HUN_ImpVerbPfx HUN_NP"<<std::endl;
};
HUN_ImpVerbPfx :	HUN_ImpVerb HUN_Vbpfx
{
				const node_info& HUN_ImpVerb=sparser->get_node_info($1);
				const node_info& HUN_Vbpfx=sparser->get_node_info($2);
				$$=sparser->combine_nodes("HUN_ImpVerbPfx",HUN_ImpVerb,HUN_Vbpfx);
				std::cout<<"HUN_ImpVerbPfx->HUN_ImpVerb HUN_Vbpfx"<<std::endl;
};
HUN_ImpVerb :	HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2
{
				const node_info& HUN_Verb_stem=sparser->get_node_info($1);
				const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info($2);
				sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
				$$=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);
				std::cout<<"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2"<<std::endl;
};
HUN_Verb_lfea_ConjDefSg2 : t_HUN_Verb_lfea_ConjDefSg2
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_HUN_Verb_lfea_ConjDefSg2);
//				word.gcat="ConjDefSg2";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
HUN_Verb_stem	: t_HUN_Verb_stem
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_HUN_Verb_stem);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
HUN_Vbpfx	: t_HUN_Vbpfx
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_HUN_Vbpfx);
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
HUN_NP	:	HUN_N
{
				lexicon word;

				const node_info& HUN_NP=sparser->get_node_info($1);
				word.gcat="HUN_NP";
				$$=sparser->set_node_info(word,HUN_NP);
				std::cout<<"HUN_NP->HUN_N"<<std::endl;
};
HUN_N	:	HUN_N_Sg
{
				lexicon word;

				const node_info& HUN_N_Sg=sparser->get_node_info($1);
				word.gcat="HUN_N";
				$$=sparser->set_node_info(word,HUN_N_Sg);
				std::cout<<"HUN_N->HUN_N_Sg"<<std::endl;
};
HUN_N_Sg	:	HUN_AccCon
{
				lexicon word;

				const node_info& HUN_AccCon=sparser->get_node_info($1);
				word.gcat="Sg";
				$$=sparser->set_node_info(word,HUN_AccCon);
				std::cout<<"HUN_N_Sg->HUN_AccCon"<<std::endl;
};
HUN_1Con	:	HUN_Con
{
				lexicon word;

				const node_info& HUN_Con=sparser->get_node_info($1);
				word.gcat="HUN_1Con";
				$$=sparser->set_node_info(word,HUN_Con);
				std::cout<<"HUN_1Con->HUN_Con:"<<HUN_Con.expression.lexeme<<std::endl;
};
HUN_nCon	:	HUN_1Con	HUN_Con
{
				const node_info& HUN_1Con=sparser->get_node_info($1);
				const node_info& HUN_Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("HUN_nCon",HUN_1Con,HUN_Con);
				std::cout<<"HUN_nCon->HUN_1Con HUN_Con"<<std::endl;
}
	|	HUN_nCon HUN_Con
{
				const node_info& HUN_nCon=sparser->get_node_info($1);
				const node_info& HUN_Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("HUN_nCon",HUN_nCon,HUN_Con);
				std::cout<<"HUN_nCon->HUN_nCon HUN_Con"<<std::endl;
}
	|	HUN_AccCon HUN_Con
{
				const node_info& HUN_AccCon=sparser->get_node_info($1);
				const node_info& HUN_Con=sparser->get_node_info($2);
				$$=sparser->combine_nodes("HUN_nCon",HUN_AccCon,HUN_Con);
				std::cout<<"HUN_nCon->HUN_AccCon HUN_Con"<<std::endl;
};
HUN_AccCon	:	HUN_1Con HUN_Con_lfea_Acc
{
				const node_info& HUN_1Con=sparser->get_node_info($1);
				const node_info& HUN_Con_lfea_Acc=sparser->get_node_info($2);
				$$=sparser->combine_nodes("HUN_AccCon",HUN_1Con,HUN_Con_lfea_Acc);
				std::cout<<"HUN_AccCon->HUN_1Con HUN_Con_lfea_Acc"<<std::endl;
}
			|	HUN_nCon HUN_Con_lfea_Acc
{
				const node_info& HUN_nCon=sparser->get_node_info($1);
				const node_info& HUN_Con_lfea_Acc=sparser->get_node_info($2);
				$$=sparser->combine_nodes("HUN_AccCon",HUN_nCon,HUN_Con_lfea_Acc);
				std::cout<<"HUN_AccCon->HUN_nCon HUN_Con_lfea_Acc"<<std::endl;
};
HUN_Con	:	t_Con
{
				const node_info empty_node_info={};
				lexicon word;

				word=lex->last_word_scanned(t_Con);
//				word.gcat="CON";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<"Konstans:"<<word.word<<std::endl;
};
HUN_Con_lfea_Acc : t_HUN_Con_lfea_Acc
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_HUN_Con_lfea_Acc);
//				word.gcat="HUN_Con_lfea_Acc";
				$$=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
};
%%

int yylex(void){
	int token;
	lexicon word={};

	if(lex->is_end_of_input()==false){
		token=lex->next_token();
		//std::cout<<"next token:"<<token<<std::endl;
		return token+1;
	}
	else return 0;//historic indicator of YACC about end of input stream
}

void yyerror(char const *yymsgp){
	std::cout<<yymsgp<<std::endl;
	return;
}

#ifdef __EMSCRIPTEN__
extern "C"{
#endif

const char *hi(const char *human_input,const char *language,char *error){
	std::string commandstr,last_word,validated_words;
	db *sqlite=NULL;
	transgraph *transgraph=NULL;
	char *commandchr=NULL;

	token_paths=new tokenpaths;
	//TODO: remove commandchr==NULL condition check when a complete implementation for
	//token paths coverage is done i.e. when all token paths are interpreted and not the
	//first interpretable token path wins
	while(human_input!=NULL&&commandchr==NULL&&token_paths->is_any_left()==true){
		std::cout<<"picking new token path"<<std::endl; 
		try{
			if(sqlite==NULL){
				sqlite=db::get_instance();
				#ifdef __ANDROID__
					__android_log_print(ANDROID_LOG_INFO, "hi", "human_input: %s", human_input);
					sqlite->open("/data/data/hi.pkg/hi.db");//TODO: get cwd on android
				#else
					sqlite->open("hi.db");
				#endif
			}
			lex=new lexer(human_input,language);
			#ifdef __ANDROID__
				__android_log_print(ANDROID_LOG_INFO, "hi", "lexer started");
			#endif
			sparser=new interpreter;
			#ifdef __ANDROID__
				__android_log_print(ANDROID_LOG_INFO, "hi", "interpreter started");
			#endif
			if(yyparse()==0){
				transgraph=sparser->longest_match_for_semantic_rules_found();
				if(transgraph!=NULL){
					token_paths->add_valid_path(lex->word_entries());
					std::cout<<"TRUE"<<std::endl;
					commandstr=transgraph->transcript(std::string());
//					std::cout<<commandstr<<std::endl;
				}
				else{
					token_paths->add_invalid_path(lex->word_entries());
					validated_words=lex->validated_words();
					std::cout<<"validated words:"<<validated_words<<std::endl;
					if(lex->last_word_scanned().morphalytics!=NULL)
						last_word=lex->last_word_scanned().morphalytics->word();
					else last_word=lex->last_word_scanned().word;
					std::cout<<"FALSE:"<<" error at "<<last_word<<std::endl;
					if(error!=NULL){
						if(validated_words.empty()==false){
							validated_words.copy(error,validated_words.length(),0);
							error[validated_words.length()]='/';
							last_word.copy(&error[validated_words.length()+1],last_word.length(),0);
							error[validated_words.length()+last_word.length()+1]='\0';
						}
						else{
							last_word.copy(error,last_word.length(),0);
							error[last_word.length()]='\0';
						}
					}
				}
			}
			else{//syntax error for token in yychar
				token_paths->add_invalid_path(lex->word_entries());
				token_paths->mark_syntax_error(lex->last_word_scanned());
				validated_words=lex->validated_words();
				std::cout<<"validated words:"<<validated_words<<std::endl;
				if(lex->last_word_scanned().morphalytics!=NULL)
					last_word=lex->last_word_scanned().morphalytics->word();
				else last_word=lex->last_word_scanned().word;
				std::cout<<"FALSE:"<<" error at "<<last_word<<std::endl;
				if(error!=NULL){
					if(validated_words.empty()==false){
						validated_words.copy(error,validated_words.length(),0);
						error[validated_words.length()]='/';
						last_word.copy(&error[validated_words.length()+1],last_word.length(),0);
						error[validated_words.length()+last_word.length()+1]='\0';
					}
					else{
						last_word.copy(error,last_word.length(),0);
						error[last_word.length()]='\0';
					}
				}
			}
			delete sparser;
			sparser=NULL;
			delete lex;
			lex=NULL;
			delete transgraph;
			if(commandstr.empty()==false){
				commandchr=new char[commandstr.length()+1];
				commandstr.copy(commandchr,commandstr.length(),0);
				commandchr[commandstr.length()]='\0';
				if(error!=NULL) error[0]='\0';
			}
		}
		catch(sql_execution_error& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(failed_to_open_db& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(failed_to_close_db& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(lexicon_type_and_db_table_schema_mismatch& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(more_than_one_token_found& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(object_node_missing& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(head_node_missing& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(invalid_combination& exception){
			token_paths->add_invalid_path(lex->word_entries());
			validated_words=lex->validated_words();
			std::cout<<"validated words:"<<validated_words<<std::endl;
			std::cout<<exception.what()<<std::endl;
			if(error!=NULL){
				if(validated_words.empty()==false){
					validated_words.copy(error,validated_words.length(),0);
					error[validated_words.length()]='/';
					std::string left_node_words=exception.get_left();
					left_node_words.copy(&error[validated_words.length()+1],left_node_words.length(),0);
					error[validated_words.length()+left_node_words.length()+1]=' ';
					std::string right_node_words=exception.get_right();
					right_node_words.copy(&error[validated_words.length()+left_node_words.length()+2],right_node_words.length(),0);
					error[validated_words.length()+left_node_words.length()+right_node_words.length()+2]='\0';
				}
				else{
					std::string left_node_words=exception.get_left();
					left_node_words.copy(error,left_node_words.length(),0);
					error[left_node_words.length()]=' ';
					std::string right_node_words=exception.get_right();
					right_node_words.copy(&error[left_node_words.length()+1],right_node_words.length(),0);
					error[left_node_words.length()+right_node_words.length()+1]='\0';
				}
			}
			return NULL;
		}
		catch(missing_prerequisite_symbol& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(std::exception& exception){
			std::cout<<exception.what()<<std::endl;
			return NULL;
		}
		catch(...){
			std::cout<<"Unexpected error ..."<<std::endl;
			return NULL;
		}
	}
	delete token_paths;
	token_paths=NULL;
	sqlite->close();
	delete sqlite;
	sqlite=NULL;
	return commandchr;
}
#ifdef __EMSCRIPTEN__
}
#endif
