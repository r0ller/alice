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
%define parse.lac full
%define parse.error verbose
%start	S
%token	t_Con 1
%token	t_ENG_A_Stem 2
%token	t_ENG_ADV 3
%token	t_ENG_DET 4
%token	t_ENG_N_Stem 5
%token	t_ENG_N_Pl 6
%token	t_ENG_N_Sg 7
%token	t_ENG_PREP 8
%token	t_ENG_QPRO 9
%token	t_ENG_V_Stem 10
%token	t_ENG_V_Aux 11
%token	t_ENG_RPRO 12
%token	t_ENG_RPRO_Relative 13
%token	t_ENG_NEG_Stem 14
%token	t_ENG_PAR 19
%token	t_ENG_DET_Indef 20
%token	t_ENG_DET_fwVowel 21
%token	t_ENG_DET_fwConsonant 22
%token	t_ENG_N_swVowel 23
%token	t_ENG_N_swConsonant 24
%token	t_ENG_V_Gerund 25
%token	t_HUN_CON_Acc 15
%token	t_HUN_Verb_Stem 16
%token	t_HUN_Verb_ConjDefSg2 17
%token	t_HUN_Vbpfx_Stem 18
%token	t_HUN_Num_Stem 26
%token	t_HUN_Num_Ik 27
%token	t_HUN_Num_Par 28
%token	t_HUN_Num_Npref1 29
%token	t_HUN_Num_Npref2 30
%token	t_HUN_Num_Npref3 31
%token	t_HUN_Num_Npref4 32
%token	t_HUN_Num_Npref5 33
%token	t_HUN_Num_Npref6 34
%token	t_HUN_Num_Npref7 35
%token	t_HUN_Num_Npref8 36
%token	t_HUN_Num_Npref9 37
%token	t_HUN_Num_Npref1nn 38
%token	t_HUN_Num_Npref1nnn 39
%token	t_HUN_Det 40
%token	t_HUN_Det_Def 41
%token	t_HUN_Det_fwVowel 42
%token	t_HUN_Det_fwConsonant 43
%token	t_HUN_CON_swVowel 44
%token	t_HUN_CON_swConsonant 45
%token	t_HUN_Num_Acc 46
%token	t_HUN_Num_Npref1n 47
%token	t_HUN_Num_Npref2n 48
%token	t_HUN_Num_Npref3n 49
%token	t_HUN_Num_Npref4n 50
%token	t_HUN_Num_Npref5n 51
%token	t_HUN_Num_Npref6n 52
%token	t_HUN_Num_Npref7n 53
%token	t_HUN_Num_Npref8n 54
%token	t_HUN_Num_Npref9n 55
%token	t_HUN_Num_swVowel 56
%token	t_HUN_Num_swConsonant 57
%token	t_HUN_Noun_Stem 58
%token	t_HUN_Noun_Acc 59
%token	t_HUN_Noun_swVowel 60
%token	t_HUN_Noun_swConsonant 61
%%
ENG_1Con:
ENG_Con 
{
lexicon word;
const node_info& ENG_Con=sparser->get_node_info($1);
word.gcat="ENG_1Con";
$$=sparser->set_node_info(word,ENG_Con);
logger::singleton()->log(0,"ENG_1Con->ENG_Con");

};
ENG_A:
t_ENG_A_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_A_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_AP:
ENG_1Con ENG_N_Pl_0Con_swC
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_AP",ENG_1Con,ENG_N_Pl_0Con_swC);
logger::singleton()->log(0,"ENG_AP->ENG_1Con ENG_N_Pl_0Con_swC");

}
|ENG_1Con ENG_N_Pl_0Con_swV
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_AP",ENG_1Con,ENG_N_Pl_0Con_swV);
logger::singleton()->log(0,"ENG_AP->ENG_1Con ENG_N_Pl_0Con_swV");

};
ENG_Adv:
t_ENG_ADV 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_ADV);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_AdvP:
ENG_Adv 
{
lexicon word;
const node_info& ENG_Adv=sparser->get_node_info($1);
word.gcat="ENG_AdvP";
$$=sparser->set_node_info(word,ENG_Adv);
logger::singleton()->log(0,"ENG_AdvP->ENG_Adv");

};
ENG_CNP:
ENG_A ENG_CNP
{
const node_info& ENG_A=sparser->get_node_info($1);
const node_info& ENG_CNP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_CNP",ENG_A,ENG_CNP);
logger::singleton()->log(0,"ENG_CNP->ENG_A ENG_CNP");

}
|ENG_N 
{
lexicon word;
const node_info& ENG_N=sparser->get_node_info($1);
word.gcat="ENG_CNP";
$$=sparser->set_node_info(word,ENG_N);
logger::singleton()->log(0,"ENG_CNP->ENG_N");

};
ENG_Con:
t_Con 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_Con);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,"Constant:"+word.word);
};
ENG_DP:
ENG_Indef_Det_a ENG_N_Sg_0Con_swC
{
const node_info& ENG_Indef_Det_a=sparser->get_node_info($1);
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);
logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC");

}
|ENG_Indef_Det_an ENG_N_Sg_0Con_swV
{
const node_info& ENG_Indef_Det_an=sparser->get_node_info($1);
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);
logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV");

};
ENG_Det_stem:
t_ENG_DET 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_IVP:
ENG_NV ENG_PP
{
const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");
}
|ENG_V ENG_PP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"RCV");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
};
ENG_Indef_Det:
ENG_Det_stem ENG_lfea_IndefDet
{
const node_info& ENG_Det_stem=sparser->get_node_info($1);
const node_info& ENG_lfea_IndefDet=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);
logger::singleton()->log(0,"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet");

};
ENG_Indef_Det_a:
ENG_Indef_Det ENG_lfea_fwConsonant
{
const node_info& ENG_Indef_Det=sparser->get_node_info($1);
const node_info& ENG_lfea_fwConsonant=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);
logger::singleton()->log(0,"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant");

};
ENG_Indef_Det_an:
ENG_Indef_Det ENG_lfea_fwVowel
{
const node_info& ENG_Indef_Det=sparser->get_node_info($1);
const node_info& ENG_lfea_fwVowel=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);
logger::singleton()->log(0,"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel");

};
ENG_N:
ENG_N_Pl 
{
lexicon word;
const node_info& ENG_N_Pl=sparser->get_node_info($1);
word.gcat="ENG_N";
$$=sparser->set_node_info(word,ENG_N_Pl);
logger::singleton()->log(0,"ENG_N->ENG_N_Pl");

}
|ENG_N_Sg 
{
lexicon word;
const node_info& ENG_N_Sg=sparser->get_node_info($1);
word.gcat="ENG_N";
$$=sparser->set_node_info(word,ENG_N_Sg);
logger::singleton()->log(0,"ENG_N->ENG_N_Sg");

};
ENG_NEG:
t_ENG_NEG_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_NEG_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_NP:
ENG_AP 
{
lexicon word;
const node_info& ENG_AP=sparser->get_node_info($1);
word.gcat="ENG_NP";
$$=sparser->set_node_info(word,ENG_AP);
logger::singleton()->log(0,"ENG_NP->ENG_AP");

}
|ENG_CNP 
{
lexicon word;
const node_info& ENG_CNP=sparser->get_node_info($1);
word.gcat="ENG_NP";
$$=sparser->set_node_info(word,ENG_CNP);
logger::singleton()->log(0,"ENG_NP->ENG_CNP");

}
|ENG_QPro ENG_CNP
{
const node_info& ENG_QPro=sparser->get_node_info($1);
const node_info& ENG_CNP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);
logger::singleton()->log(0,"ENG_NP->ENG_QPro ENG_CNP");

};
ENG_NV:
ENG_V ENG_NEG
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_NEG=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_NV",ENG_V,ENG_NEG);
logger::singleton()->log(0,"ENG_NV->ENG_V ENG_NEG");

};
ENG_N_Pl:
ENG_N_Pl_0Con_swC 
{
lexicon word;
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($1);
word.gcat="ENG_N_Pl";
$$=sparser->set_node_info(word,ENG_N_Pl_0Con_swC);
logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC");

}
|ENG_N_Pl_0Con_swC ENG_nCon
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($1);
const node_info& ENG_nCon=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);
logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon");

}
|ENG_N_Pl_0Con_swV 
{
lexicon word;
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($1);
word.gcat="ENG_N_Pl";
$$=sparser->set_node_info(word,ENG_N_Pl_0Con_swV);
logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV");

}
|ENG_N_Pl_0Con_swV ENG_nCon
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($1);
const node_info& ENG_nCon=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);
logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon");

}
|ENG_N_Sg ENG_nCon
{
//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in 'list file abc def'
//TODO: Any better solution???
return -1;
}
|ENG_nCon 
{
lexicon word;
const node_info& ENG_nCon=sparser->get_node_info($1);
word.gcat="ENG_N_Pl";
$$=sparser->set_node_info(word,ENG_nCon);
logger::singleton()->log(0,"ENG_N_Pl->ENG_nCon");

};
ENG_N_Pl_0Con:
ENG_N_Stem ENG_N_lfea_Pl
{
const node_info& ENG_N_Stem=sparser->get_node_info($1);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);
logger::singleton()->log(0,"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl");

};
ENG_N_Pl_0Con_swC:
ENG_N_Pl_0Con ENG_lfea_swConsonant
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);
logger::singleton()->log(0,"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant");

};
ENG_N_Pl_0Con_swV:
ENG_N_Pl_0Con ENG_lfea_swVowel
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swVowel=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);
logger::singleton()->log(0,"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel");

};
ENG_N_Sg:
ENG_1Con 
{
lexicon word;
const node_info& ENG_1Con=sparser->get_node_info($1);
word.gcat="ENG_N_Sg";
$$=sparser->set_node_info(word,ENG_1Con);
logger::singleton()->log(0,"ENG_N_Sg->ENG_1Con");

}
|ENG_N_Sg_0Con_swC 
{
lexicon word;
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($1);
word.gcat="ENG_N_Sg";
$$=sparser->set_node_info(word,ENG_N_Sg_0Con_swC);
logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC");

}
|ENG_N_Sg_0Con_swC ENG_1Con
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($1);
const node_info& ENG_1Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swC,ENG_1Con);
logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con");

}
|ENG_N_Sg_0Con_swV 
{
lexicon word;
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($1);
word.gcat="ENG_N_Sg";
$$=sparser->set_node_info(word,ENG_N_Sg_0Con_swV);
logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV");

}
|ENG_N_Sg_0Con_swV ENG_1Con
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($1);
const node_info& ENG_1Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swV,ENG_1Con);
logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con");

};
ENG_N_Sg_0Con:
ENG_N_Stem ENG_N_lfea_Sg
{
const node_info& ENG_N_Stem=sparser->get_node_info($1);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg_0Con",ENG_N_Stem,ENG_N_lfea_Sg);
logger::singleton()->log(0,"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg");

};
ENG_N_Sg_0Con_swC:
ENG_N_Sg_0Con ENG_lfea_swConsonant
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);
logger::singleton()->log(0,"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant");

};
ENG_N_Sg_0Con_swV:
ENG_N_Sg_0Con ENG_lfea_swVowel
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swVowel=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);
logger::singleton()->log(0,"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel");

};
ENG_N_Stem:
t_ENG_N_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_N_lfea_Pl:
t_ENG_N_Pl 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Pl);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_N_lfea_Sg:
t_ENG_N_Sg 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Sg);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_PP:
ENG_Prep ENG_NP
{
const node_info& ENG_Prep=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);
logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");

};
ENG_Prep:
t_ENG_PREP 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_PREP);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_QPro:
t_ENG_QPRO 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_QPRO);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_RC:
ENG_RPro ENG_IVP
{
const node_info& ENG_RPro=sparser->get_node_info($1);
const node_info& ENG_IVP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);
logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVP");

};
ENG_RPro:
ENG_RPro_stem ENG_RPro_lfea_relative
{
const node_info& ENG_RPro_stem=sparser->get_node_info($1);
const node_info& ENG_RPro_lfea_relative=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_RPro",ENG_RPro_stem,ENG_RPro_lfea_relative);
logger::singleton()->log(0,"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative");

};
ENG_RPro_lfea_relative:
t_ENG_RPRO_Relative 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_RPRO_Relative);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_RPro_stem:
t_ENG_RPRO 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_RPRO);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_TP:
ENG_Tense_particle ENG_V_Stem
{
const node_info& ENG_Tense_particle=sparser->get_node_info($1);
const node_info& ENG_V_Stem=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_Stem);
logger::singleton()->log(0,"ENG_TP->ENG_Tense_particle ENG_V_Stem");

}
|ENG_V_ger 
{
lexicon word;
const node_info& ENG_V_ger=sparser->get_node_info($1);
word.gcat="ENG_TP";
$$=sparser->set_node_info(word,ENG_V_ger);
logger::singleton()->log(0,"ENG_TP->ENG_V_ger");

};
ENG_Tense_particle:
t_ENG_PAR 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_PAR);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_V:
ENG_V_Stem 
{
lexicon word;
const node_info& ENG_V_Stem=sparser->get_node_info($1);
word.gcat="ENG_V";
$$=sparser->set_node_info(word,ENG_V_Stem);
logger::singleton()->log(0,"ENG_V->ENG_V_Stem");

}
|ENG_V_Stem ENG_V_lfea_aux
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_aux=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_V",ENG_V_Stem,ENG_V_lfea_aux);
logger::singleton()->log(0,"ENG_V->ENG_V_Stem ENG_V_lfea_aux");

};
ENG_VP:
ENG_Vbar1 
{
lexicon word;
const node_info& ENG_Vbar1=sparser->get_node_info($1);
word.gcat="ENG_VP";
$$=sparser->set_node_info(word,ENG_Vbar1);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar1");

}
|ENG_Vbar1 ENG_AdvP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_AdvP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");

}
|ENG_Vbar1 ENG_RC
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_RC=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_RC");

}
|ENG_Vbar2 
{
lexicon word;
const node_info& ENG_Vbar2=sparser->get_node_info($1);
word.gcat="ENG_VP";
$$=sparser->set_node_info(word,ENG_Vbar2);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar2");

}
|ENG_Vbar2 ENG_PP
{
const node_info& ENG_Vbar2=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_PP");

}
|ENG_Vbar2 ENG_RC
{
const node_info& ENG_Vbar2=sparser->get_node_info($1);
const node_info& ENG_RC=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_RC");

}
|ENG_Vbar3 ENG_NP
{
const node_info& ENG_Vbar3=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar3 ENG_NP");

}
|ENG_Vbar4 ENG_DP
{
const node_info& ENG_Vbar4=sparser->get_node_info($1);
const node_info& ENG_DP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar4 ENG_DP");

};
ENG_V_Stem:
t_ENG_V_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_V_ger:
ENG_V_Stem ENG_V_lfea_ger
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_ger=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_V_ger",ENG_V_Stem,ENG_V_lfea_ger);
logger::singleton()->log(0,"ENG_V_ger->ENG_V_Stem ENG_V_lfea_ger");

};
ENG_V_lfea_aux:
t_ENG_V_Aux 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Aux);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_V_lfea_ger:
t_ENG_V_Gerund 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Gerund);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_Vbar1:
ENG_V ENG_NP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");
};
ENG_Vbar2:
ENG_Vbar1 ENG_NP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);
logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_NP");

}
|ENG_Vbar1 ENG_PP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_PP);
logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_PP");

};
ENG_Vbar3:
ENG_V ENG_AdvP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_AdvP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Vbar3",ENG_V,ENG_AdvP);
logger::singleton()->log(0,"ENG_Vbar3->ENG_V ENG_AdvP");

};
ENG_Vbar4:
ENG_DP ENG_V
{
const node_info& ENG_DP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");
}
|ENG_TP ENG_V
{
const node_info& ENG_TP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");
};
ENG_lfea_IndefDet:
t_ENG_DET_Indef 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_Indef);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_lfea_fwConsonant:
t_ENG_DET_fwConsonant 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_fwConsonant);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_lfea_fwVowel:
t_ENG_DET_fwVowel 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_fwVowel);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_lfea_swConsonant:
t_ENG_N_swConsonant 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_swConsonant);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_lfea_swVowel:
t_ENG_N_swVowel 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_swVowel);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_nCon:
ENG_1Con ENG_Con
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);
logger::singleton()->log(0,"ENG_nCon->ENG_1Con ENG_Con");

}
|ENG_nCon ENG_Con
{
const node_info& ENG_nCon=sparser->get_node_info($1);
const node_info& ENG_Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);
logger::singleton()->log(0,"ENG_nCon->ENG_nCon ENG_Con");

};
HUN_1Con:
HUN_Con 
{
lexicon word;
const node_info& HUN_Con=sparser->get_node_info($1);
word.gcat="HUN_1Con";
$$=sparser->set_node_info(word,HUN_Con);
logger::singleton()->log(0,"HUN_1Con->HUN_Con");

};
HUN_Con:
HUN_lfea_swConsonant HUN_Con
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info($1);
const node_info& HUN_Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Con",HUN_lfea_swConsonant,HUN_Con);
logger::singleton()->log(0,"HUN_Con->HUN_lfea_swConsonant HUN_Con");

}
|HUN_lfea_swVowel HUN_Con
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info($1);
const node_info& HUN_Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Con",HUN_lfea_swVowel,HUN_Con);
logger::singleton()->log(0,"HUN_Con->HUN_lfea_swVowel HUN_Con");

}
|t_Con 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_Con);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,"Konstans:"+word.word);
};
HUN_Con_lfea_Acc:
t_HUN_CON_Acc 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_CON_Acc);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_DP:
HUN_DPbar HUN_N_Acc
{
const node_info& HUN_DPbar=sparser->get_node_info($1);
const node_info& HUN_N_Acc=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Acc);
logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Acc");

};
HUN_DPbar:
HUN_Def_Det_a HUN_lfea_swConsonant
{
const node_info& HUN_Def_Det_a=sparser->get_node_info($1);
const node_info& HUN_lfea_swConsonant=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_a,HUN_lfea_swConsonant);
logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_a HUN_lfea_swConsonant");

}
|HUN_Def_Det_az HUN_lfea_swVowel
{
const node_info& HUN_Def_Det_az=sparser->get_node_info($1);
const node_info& HUN_lfea_swVowel=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_az,HUN_lfea_swVowel);
logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_az HUN_lfea_swVowel");

};
HUN_Def_Det:
HUN_Det_stem HUN_lfea_DefDet
{
const node_info& HUN_Det_stem=sparser->get_node_info($1);
const node_info& HUN_lfea_DefDet=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Def_Det",HUN_Det_stem,HUN_lfea_DefDet);
logger::singleton()->log(0,"HUN_Def_Det->HUN_Det_stem HUN_lfea_DefDet");

};
HUN_Def_Det_a:
HUN_Def_Det HUN_lfea_fwConsonant
{
const node_info& HUN_Def_Det=sparser->get_node_info($1);
const node_info& HUN_lfea_fwConsonant=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Def_Det_a",HUN_Def_Det,HUN_lfea_fwConsonant);
logger::singleton()->log(0,"HUN_Def_Det_a->HUN_Def_Det HUN_lfea_fwConsonant");

};
HUN_Def_Det_az:
HUN_Def_Det HUN_lfea_fwVowel
{
const node_info& HUN_Def_Det=sparser->get_node_info($1);
const node_info& HUN_lfea_fwVowel=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Def_Det_az",HUN_Def_Det,HUN_lfea_fwVowel);
logger::singleton()->log(0,"HUN_Def_Det_az->HUN_Def_Det HUN_lfea_fwVowel");

};
HUN_Det_stem:
t_HUN_Det 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Det);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_ImpVerb:
HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2
{
const node_info& HUN_Verb_stem=sparser->get_node_info($1);
const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
$$=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);
logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2");
};
HUN_ImpVerbPfx:
HUN_ImpVerb HUN_Vbpfx
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_Vbpfx=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_ImpVerbPfx",HUN_ImpVerb,HUN_Vbpfx);
logger::singleton()->log(0,"HUN_ImpVerbPfx->HUN_ImpVerb HUN_Vbpfx");

};
HUN_NP:
HUN_N_Acc 
{
lexicon word;
const node_info& HUN_N_Acc=sparser->get_node_info($1);
word.gcat="HUN_NP";
$$=sparser->set_node_info(word,HUN_N_Acc);
logger::singleton()->log(0,"HUN_NP->HUN_N_Acc");

};
HUN_N_Acc:
HUN_N_Sg HUN_Con_lfea_Acc
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Con_lfea_Acc=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Con_lfea_Acc);
logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Con_lfea_Acc");

}
|HUN_N_Sg HUN_Noun_lfea_Acc
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Noun_lfea_Acc);
logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Noun_lfea_Acc");

}
|HUN_Num HUN_Num_lfea_Acc
{
const node_info& HUN_Num=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_N_Acc",HUN_Num,HUN_Num_lfea_Acc);
logger::singleton()->log(0,"HUN_N_Acc->HUN_Num HUN_Num_lfea_Acc");

}
|HUN_Nums HUN_Num_lfea_Acc
{
const node_info& HUN_Nums=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_N_Acc",HUN_Nums,HUN_Num_lfea_Acc);
logger::singleton()->log(0,"HUN_N_Acc->HUN_Nums HUN_Num_lfea_Acc");

};
HUN_N_Sg:
HUN_1Con 
{
lexicon word;
const node_info& HUN_1Con=sparser->get_node_info($1);
word.gcat="HUN_N_Sg";
$$=sparser->set_node_info(word,HUN_1Con);
logger::singleton()->log(0,"HUN_N_Sg->HUN_1Con");

}
|HUN_nCon 
{
lexicon word;
const node_info& HUN_nCon=sparser->get_node_info($1);
word.gcat="HUN_N_Sg";
$$=sparser->set_node_info(word,HUN_nCon);
logger::singleton()->log(0,"HUN_N_Sg->HUN_nCon");

}
|t_HUN_Noun_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Noun_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Noun_lfea_Acc:
t_HUN_Noun_Acc 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Noun_Acc);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Num:
HUN_Num HUN_Num_lfea_Ik
{
const node_info& HUN_Num=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Ik=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Ik);
logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Ik");

}
|HUN_Num HUN_Num_lfea_Par
{
const node_info& HUN_Num=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Par=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Par);
logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Par");

}
|HUN_Num_Pref HUN_Num
{
const node_info& HUN_Num_Pref=sparser->get_node_info($1);
const node_info& HUN_Num=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Num",HUN_Num_Pref,HUN_Num);
logger::singleton()->log(0,"HUN_Num->HUN_Num_Pref HUN_Num");

}
|HUN_Num_Stem 
{
lexicon word;
const node_info& HUN_Num_Stem=sparser->get_node_info($1);
word.gcat="HUN_Num";
$$=sparser->set_node_info(word,HUN_Num_Stem);
logger::singleton()->log(0,"HUN_Num->HUN_Num_Stem");

}
|HUN_lfea_swConsonant HUN_Num
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info($1);
const node_info& HUN_Num=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Num",HUN_lfea_swConsonant,HUN_Num);
logger::singleton()->log(0,"HUN_Num->HUN_lfea_swConsonant HUN_Num");

}
|HUN_lfea_swVowel HUN_Num
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info($1);
const node_info& HUN_Num=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Num",HUN_lfea_swVowel,HUN_Num);
logger::singleton()->log(0,"HUN_Num->HUN_lfea_swVowel HUN_Num");

};
HUN_Num_Pref:
t_HUN_Num_Npref1 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref1);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref1n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref1n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref1nn 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref1nn);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref1nnn 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref1nnn);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref2 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref2);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref2n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref2n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref3 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref3);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref3n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref3n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref4 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref4);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref4n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref4n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref5 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref5);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref5n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref5n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref6 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref6);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref6n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref6n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref7 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref7);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref7n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref7n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref8 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref8);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref8n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref8n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref9 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref9);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_Npref9n 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Npref9n);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Num_Stem:
t_HUN_Num_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Num_lfea_Acc:
t_HUN_Num_Acc 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Acc);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Num_lfea_Ik:
t_HUN_Num_Ik 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Ik);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Num_lfea_Par:
t_HUN_Num_Par 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_Par);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Nums:
HUN_Num HUN_Num
{
const node_info& HUN_Num1=sparser->get_node_info($1);
const node_info& HUN_Num2=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Nums",HUN_Num1,HUN_Num2);
logger::singleton()->log(0,"HUN_Nums->HUN_Num HUN_Num");

}
|HUN_Nums HUN_Num
{
const node_info& HUN_Nums=sparser->get_node_info($1);
const node_info& HUN_Num=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_Nums",HUN_Nums,HUN_Num);
logger::singleton()->log(0,"HUN_Nums->HUN_Nums HUN_Num");

};
HUN_VP:
HUN_ImpVerbPfx HUN_DP
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info($1);
const node_info& HUN_DP=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_DP);
logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_DP");

}
|HUN_ImpVerbPfx HUN_NP
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info($1);
const node_info& HUN_NP=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_NP);
logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_NP");

};
HUN_Vbpfx:
t_HUN_Vbpfx_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Vbpfx_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Verb_lfea_ConjDefSg2:
t_HUN_Verb_ConjDefSg2 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Verb_ConjDefSg2);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_Verb_stem:
t_HUN_Verb_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Verb_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_lfea_DefDet:
t_HUN_Det_Def 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Det_Def);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_lfea_fwConsonant:
t_HUN_Det_fwConsonant 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Det_fwConsonant);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_lfea_fwVowel:
t_HUN_Det_fwVowel 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Det_fwVowel);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_lfea_swConsonant:
t_HUN_CON_swConsonant 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_CON_swConsonant);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Noun_swConsonant 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Noun_swConsonant);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_swConsonant 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_swConsonant);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_lfea_swVowel:
t_HUN_CON_swVowel 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_CON_swVowel);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Noun_swVowel 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Noun_swVowel);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
|t_HUN_Num_swVowel 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_HUN_Num_swVowel);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
HUN_nCon:
HUN_1Con HUN_Con
{
const node_info& HUN_1Con=sparser->get_node_info($1);
const node_info& HUN_Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_nCon",HUN_1Con,HUN_Con);
logger::singleton()->log(0,"HUN_nCon->HUN_1Con HUN_Con");

}
|HUN_nCon HUN_Con
{
const node_info& HUN_nCon=sparser->get_node_info($1);
const node_info& HUN_Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("HUN_nCon",HUN_nCon,HUN_Con);
logger::singleton()->log(0,"HUN_nCon->HUN_nCon HUN_Con");

};
S:
ENG_VP 
{
lexicon word;
const node_info& ENG_VP=sparser->get_node_info($1);
word.gcat="S";
$$=sparser->set_node_info(word,ENG_VP);
logger::singleton()->log(0,"S->ENG_VP");

}
|HUN_VP 
{
lexicon word;
const node_info& HUN_VP=sparser->get_node_info($1);
word.gcat="S";
$$=sparser->set_node_info(word,HUN_VP);
logger::singleton()->log(0,"S->HUN_VP");

};
%%
int yylex(void){
	int token;
	lexicon word={};

	if(lex->is_end_of_input()==false){
		token=lex->next_token();
		std::cout<<"next token:"<<token<<std::endl;
		return token+1;
	}
	else return 0;//historic indicator of YACC about end of input stream
}

void yyerror(char const *yymsgp){
	std::cout<<yymsgp<<std::endl;//Could as well return as error till our own syntax error reporting gets better
	token_paths->log_yyerror(std::string(yymsgp));
	return;
}

#ifdef __EMSCRIPTEN__
extern "C"{
#endif

#ifdef __ANDROID__
const char *hi(const char *human_input,const char *language,const unsigned char toa,const char *target_language,const char *db_uri,JavaVM *vm,jobject activityobj){
#else
const char *hi(const char *human_input,const char *language,const unsigned char toa,const char *target_language,const char *db_uri){
#endif

	std::string analysis;
	db *sqlite=NULL;
	transgraph *transgraph=NULL;
	char *analysischr=NULL;
	logger *logger=NULL;
	std::locale locale;

	logger=logger::singleton("console",3,"LE");
	token_paths=new tokenpaths;
	while(human_input!=NULL&&token_paths->is_any_left()==true){
		std::cout<<"picking new token path"<<std::endl;
		try{
			if(sqlite==NULL){
				#ifdef __ANDROID__
					__android_log_print(ANDROID_LOG_INFO, "hi", "human_input: %s", human_input);
					if(vm!=NULL) jvm=vm;
					else{
						__android_log_print(ANDROID_LOG_INFO, "hi", "vm is NULL!");
						exit(EXIT_FAILURE);
					}
					activity=activityobj;
				#endif
				sqlite=db_factory::get_instance();
				#if defined(__EMSCRIPTEN__) && FS==NETWORK
				sqlite->open(db_uri);
				#elif defined(__EMSCRIPTEN__) && FS==NODEJS
				EM_ASM(
					FS.mkdir('/virtual');
					FS.mount(NODEFS, { root: '.' }, '/virtual');
				);
				sqlite->open("/virtual/"+std::string(db_uri));
				#else
				sqlite->open(db_uri);
				#endif
			}
			locale=std::locale();
			lex=new lexer(human_input,language,locale);
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
					token_paths->validate_path(lex->word_entries(),transgraph);
					logger::singleton()->log(0,"TRUE");
				}
				else{
					logger::singleton()->log(0,"semantic error");
					token_paths->invalidate_path(lex->word_entries(),"semantic error",NULL);
				}
			}
			else{//syntax error for token in yychar
				logger::singleton()->log(0,"syntax error");
				token_paths->invalidate_path(lex->word_entries(),"syntax error",NULL);
			}
			delete sparser;
			sparser=NULL;
			delete lex;
			lex=NULL;
			transgraph=NULL;
		}
		catch(sql_execution_error& exception){
			logger::singleton()->log(0,"sql_execution_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_open_db& exception){
			logger::singleton()->log(0,"failed_to_open_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_close_db& exception){
			logger::singleton()->log(0,"failed_to_close_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(lexicon_type_and_db_table_schema_mismatch& exception){
			logger::singleton()->log(0,"lexicon_type_and_db_table_schema_mismatch:"+std::string(exception.what()));
			return NULL;
		}
		catch(more_than_one_token_found& exception){
			logger::singleton()->log(0,"more_than_one_token_found:"+std::string(exception.what()));
			return NULL;
		}
		catch(morphan_error& exception){
			logger::singleton()->log(0,"morphan_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(object_node_missing& exception){
			logger::singleton()->log(0,"object_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(head_node_missing& exception){
			logger::singleton()->log(0,"head_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(invalid_combination& exception){
			token_paths->invalidate_path(lex->word_entries(),"invalid combination",&exception);
			logger::singleton()->log(0,"invalid_combination:"+std::string(exception.what()));
			if(token_paths->is_any_left()==true){
				delete sparser;
				sparser=NULL;
				delete lex;
				lex=NULL;
				transgraph=NULL;
			}
		}
		catch(invalid_token_path& exception){
			delete sparser;
			sparser=NULL;
			delete lex;
			lex=NULL;
			transgraph=NULL;
		}
		catch(missing_prerequisite_symbol& exception){
			logger::singleton()->log(0,"missing_prerequisite_symbol:"+std::string(exception.what()));
			return NULL;
		}
		catch(std::runtime_error& exception){//Catch underived exceptions thrown with string based messages
			logger::singleton()->log(0,"runtime exception:"+std::string(exception.what()));
			return NULL;
		}
		catch(...){
			logger::singleton()->log(0,"Unexpected error ...");
			return NULL;
		}
	}
	analysis=token_paths->create_analysis(toa);
	if(analysis.empty()==false){
		analysischr=new char[analysis.length()+1];
		analysis.copy(analysischr,analysis.length(),0);
		analysischr[analysis.length()]='\0';
	}
	lexer::delete_cache();
	delete token_paths;
	token_paths=NULL;
	if(sqlite!=NULL){
		//TODO: consider providing a release() function for the library
		//and NOT closing+freeing the db here as it'd increase performance
		//as in case of not freeing the stemmer.
		sqlite->close();
		db_factory::delete_instance();
		sqlite=NULL;
	}
	return analysischr;
}
#ifdef __EMSCRIPTEN__
}
#endif
