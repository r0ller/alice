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
%token	t_ENG_VNEG_Stem 14
%token	t_ENG_ANEG_Stem 15
%token	t_ENG_PAR 19
%token	t_ENG_DET_Indef 20
%token	t_ENG_DET_fwVowel 21
%token	t_ENG_DET_fwConsonant 22
%token	t_ENG_N_swVowel 23
%token	t_ENG_N_swConsonant 24
%token	t_ENG_V_Gerund 25
%token	t_ENG_CONJ_Stem 26
%%
ENG_1Con:
ENG_Con 
{
lexicon word;
const node_info& ENG_Con=sparser->get_node_info($1);
word.gcat="ENG_1Con";
$$=sparser->set_node_info(word,ENG_Con);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_1Con->ENG_Con");

};
ENG_A:
ENG_A_Stem 
{
lexicon word;
const node_info& ENG_A_Stem=sparser->get_node_info($1);
word.gcat="ENG_A";
$$=sparser->set_node_info(word,ENG_A_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A->ENG_A_Stem");

};
ENG_A0NEG:
ENG_A 
{
lexicon word;
const node_info& ENG_A=sparser->get_node_info($1);
word.gcat="ENG_A0NEG";
$$=sparser->set_node_info(word,ENG_A);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A0NEG->ENG_A");

};
ENG_ANEG:
ENG_ANEG_Stem 
{
lexicon word;
const node_info& ENG_ANEG_Stem=sparser->get_node_info($1);
word.gcat="ENG_ANEG";
$$=sparser->set_node_info(word,ENG_ANEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ANEG->ENG_ANEG_Stem");

};
ENG_ANEG_Stem:
t_ENG_ANEG_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_ANEG_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_AP:
ENG_Abar1 
{
lexicon word;
const node_info& ENG_Abar1=sparser->get_node_info($1);
word.gcat="ENG_AP";
$$=sparser->set_node_info(word,ENG_Abar1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar1");

}
|ENG_Abar2 
{
lexicon word;
const node_info& ENG_Abar2=sparser->get_node_info($1);
word.gcat="ENG_AP";
$$=sparser->set_node_info(word,ENG_Abar2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar2");

}
|ENG_Alist 
{
lexicon word;
const node_info& ENG_Alist=sparser->get_node_info($1);
word.gcat="ENG_AP";
$$=sparser->set_node_info(word,ENG_Alist);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Alist");

};
ENG_A_Stem:
t_ENG_A_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_A_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_Abar1:
ENG_A0NEG 
{
lexicon word;
const node_info& ENG_A0NEG=sparser->get_node_info($1);
word.gcat="ENG_Abar1";
$$=sparser->set_node_info(word,ENG_A0NEG);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_A0NEG");

}
|ENG_ANEG ENG_A
{
const node_info& ENG_ANEG=sparser->get_node_info($1);
const node_info& ENG_A=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Abar1",ENG_ANEG,ENG_A);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_ANEG ENG_A");

};
ENG_Abar2:
ENG_Abar2 ENG_CONJA
{
const node_info& ENG_Abar2=sparser->get_node_info($1);
const node_info& ENG_CONJA=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Abar2",ENG_Abar2,ENG_CONJA);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar2 ENG_CONJA");

}
|ENG_Ahead ENG_CONJA
{
const node_info& ENG_Ahead=sparser->get_node_info($1);
const node_info& ENG_CONJA=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Abar2",ENG_Ahead,ENG_CONJA);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Ahead ENG_CONJA");

}
|ENG_Alist ENG_CONJA
{
const node_info& ENG_Alist=sparser->get_node_info($1);
const node_info& ENG_CONJA=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Abar2",ENG_Alist,ENG_CONJA);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Alist ENG_CONJA");

};
ENG_Adv:
t_ENG_ADV 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_ADV);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_AdvP:
ENG_Adv 
{
lexicon word;
const node_info& ENG_Adv=sparser->get_node_info($1);
word.gcat="ENG_AdvP";
$$=sparser->set_node_info(word,ENG_Adv);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AdvP->ENG_Adv");

};
ENG_Ahead:
ENG_Abar1 
{
lexicon word;
const node_info& ENG_Abar1=sparser->get_node_info($1);
word.gcat="ENG_Ahead";
$$=sparser->set_node_info(word,ENG_Abar1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Ahead->ENG_Abar1");

};
ENG_Alist:
ENG_Abar1 ENG_Abar1
{
const node_info& ENG_Abar11=sparser->get_node_info($1);
const node_info& ENG_Abar12=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Alist",ENG_Abar11,ENG_Abar12);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Abar1 ENG_Abar1");

}
|ENG_Alist ENG_Abar1
{
const node_info& ENG_Alist=sparser->get_node_info($1);
const node_info& ENG_Abar1=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Alist",ENG_Alist,ENG_Abar1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Alist ENG_Abar1");

};
ENG_CAP:
ENG_1Con ENG_N_Pl_0Con_swC
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swC);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swC");

}
|ENG_1Con ENG_N_Pl_0Con_swV
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swV);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swV");

};
ENG_CNP:
ENG_AP ENG_N
{
const node_info& ENG_AP=sparser->get_node_info($1);
const node_info& ENG_N=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_CNP",ENG_AP,ENG_N);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_AP ENG_N");

}
|ENG_N 
{
lexicon word;
const node_info& ENG_N=sparser->get_node_info($1);
word.gcat="ENG_CNP";
$$=sparser->set_node_info(word,ENG_N);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_N");

};
ENG_CONJ:
ENG_CONJ_Stem 
{
lexicon word;
const node_info& ENG_CONJ_Stem=sparser->get_node_info($1);
word.gcat="ENG_CONJ";
$$=sparser->set_node_info(word,ENG_CONJ_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJ->ENG_CONJ_Stem");

};
ENG_CONJA:
ENG_CONJ ENG_Abar1
{
const node_info& ENG_CONJ=sparser->get_node_info($1);
const node_info& ENG_Abar1=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Abar1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Abar1");

}
|ENG_CONJ ENG_Alist
{
const node_info& ENG_CONJ=sparser->get_node_info($1);
const node_info& ENG_Alist=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Alist);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Alist");

};
ENG_CONJ_Stem:
t_ENG_CONJ_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_CONJ_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_Con:
t_Con 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_Con);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"Constant:"+word.word);
};
ENG_DP:
ENG_Indef_Det_a ENG_N_Sg_0Con_swC
{
const node_info& ENG_Indef_Det_a=sparser->get_node_info($1);
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC");

}
|ENG_Indef_Det_an ENG_N_Sg_0Con_swV
{
const node_info& ENG_Indef_Det_an=sparser->get_node_info($1);
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV");

};
ENG_Det_stem:
t_ENG_DET 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_IVP:
ENG_NV ENG_AP
{
const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_AP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_AP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_AP");
}
|ENG_NV ENG_PP
{
const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");
}
|ENG_V ENG_AP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_AP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"RCV");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_AP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_AP");
}
|ENG_V ENG_PP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"RCV");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
};
ENG_Indef_Det:
ENG_Det_stem ENG_lfea_IndefDet
{
const node_info& ENG_Det_stem=sparser->get_node_info($1);
const node_info& ENG_lfea_IndefDet=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet");

};
ENG_Indef_Det_a:
ENG_Indef_Det ENG_lfea_fwConsonant
{
const node_info& ENG_Indef_Det=sparser->get_node_info($1);
const node_info& ENG_lfea_fwConsonant=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant");

};
ENG_Indef_Det_an:
ENG_Indef_Det ENG_lfea_fwVowel
{
const node_info& ENG_Indef_Det=sparser->get_node_info($1);
const node_info& ENG_lfea_fwVowel=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel");

};
ENG_N:
ENG_N_Pl 
{
lexicon word;
const node_info& ENG_N_Pl=sparser->get_node_info($1);
word.gcat="ENG_N";
$$=sparser->set_node_info(word,ENG_N_Pl);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Pl");

}
|ENG_N_Sg 
{
lexicon word;
const node_info& ENG_N_Sg=sparser->get_node_info($1);
word.gcat="ENG_N";
$$=sparser->set_node_info(word,ENG_N_Sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Sg");

};
ENG_NP:
ENG_CAP 
{
lexicon word;
const node_info& ENG_CAP=sparser->get_node_info($1);
word.gcat="ENG_NP";
$$=sparser->set_node_info(word,ENG_CAP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CAP");

}
|ENG_CNP 
{
lexicon word;
const node_info& ENG_CNP=sparser->get_node_info($1);
word.gcat="ENG_NP";
$$=sparser->set_node_info(word,ENG_CNP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CNP");

}
|ENG_QPro ENG_CNP
{
const node_info& ENG_QPro=sparser->get_node_info($1);
const node_info& ENG_CNP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_QPro ENG_CNP");

};
ENG_NV:
ENG_V ENG_VNEG
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_VNEG=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_NV",ENG_V,ENG_VNEG);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_V ENG_VNEG");

};
ENG_N_Pl:
ENG_N_Pl_0Con_swC 
{
lexicon word;
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($1);
word.gcat="ENG_N_Pl";
$$=sparser->set_node_info(word,ENG_N_Pl_0Con_swC);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC");

}
|ENG_N_Pl_0Con_swC ENG_nCon
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($1);
const node_info& ENG_nCon=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon");

}
|ENG_N_Pl_0Con_swV 
{
lexicon word;
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($1);
word.gcat="ENG_N_Pl";
$$=sparser->set_node_info(word,ENG_N_Pl_0Con_swV);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV");

}
|ENG_N_Pl_0Con_swV ENG_nCon
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($1);
const node_info& ENG_nCon=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon");

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
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_nCon");

};
ENG_N_Pl_0Con:
ENG_N_Stem ENG_N_lfea_Pl
{
const node_info& ENG_N_Stem=sparser->get_node_info($1);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl");

};
ENG_N_Pl_0Con_swC:
ENG_N_Pl_0Con ENG_lfea_swConsonant
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant");

};
ENG_N_Pl_0Con_swV:
ENG_N_Pl_0Con ENG_lfea_swVowel
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swVowel=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel");

};
ENG_N_Sg:
ENG_1Con 
{
lexicon word;
const node_info& ENG_1Con=sparser->get_node_info($1);
word.gcat="ENG_N_Sg";
$$=sparser->set_node_info(word,ENG_1Con);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_1Con");

}
|ENG_N_Sg_0Con_swC 
{
lexicon word;
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($1);
word.gcat="ENG_N_Sg";
$$=sparser->set_node_info(word,ENG_N_Sg_0Con_swC);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC");

}
|ENG_N_Sg_0Con_swC ENG_1Con
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($1);
const node_info& ENG_1Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swC,ENG_1Con);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con");

}
|ENG_N_Sg_0Con_swV 
{
lexicon word;
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($1);
word.gcat="ENG_N_Sg";
$$=sparser->set_node_info(word,ENG_N_Sg_0Con_swV);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV");

}
|ENG_N_Sg_0Con_swV ENG_1Con
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($1);
const node_info& ENG_1Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swV,ENG_1Con);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con");

};
ENG_N_Sg_0Con:
ENG_N_Stem ENG_N_lfea_Sg
{
const node_info& ENG_N_Stem=sparser->get_node_info($1);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg_0Con",ENG_N_Stem,ENG_N_lfea_Sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg");

};
ENG_N_Sg_0Con_swC:
ENG_N_Sg_0Con ENG_lfea_swConsonant
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant");

};
ENG_N_Sg_0Con_swV:
ENG_N_Sg_0Con ENG_lfea_swVowel
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swVowel=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel");

};
ENG_N_Stem:
t_ENG_N_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_N_lfea_Pl:
t_ENG_N_Pl 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Pl);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_N_lfea_Sg:
t_ENG_N_Sg 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Sg);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_PP:
ENG_Prep ENG_NP
{
const node_info& ENG_Prep=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");

};
ENG_Prep:
t_ENG_PREP 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_PREP);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_QPro:
t_ENG_QPRO 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_QPRO);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_RC:
ENG_RPro ENG_IVP
{
const node_info& ENG_RPro=sparser->get_node_info($1);
const node_info& ENG_IVP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVP");

};
ENG_RPro:
ENG_RPro_stem ENG_RPro_lfea_relative
{
const node_info& ENG_RPro_stem=sparser->get_node_info($1);
const node_info& ENG_RPro_lfea_relative=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_RPro",ENG_RPro_stem,ENG_RPro_lfea_relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative");

};
ENG_RPro_lfea_relative:
t_ENG_RPRO_Relative 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_RPRO_Relative);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_RPro_stem:
t_ENG_RPRO 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_RPRO);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_TP:
ENG_Tense_particle ENG_V_Stem
{
const node_info& ENG_Tense_particle=sparser->get_node_info($1);
const node_info& ENG_V_Stem=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_Tense_particle ENG_V_Stem");

}
|ENG_V_ger 
{
lexicon word;
const node_info& ENG_V_ger=sparser->get_node_info($1);
word.gcat="ENG_TP";
$$=sparser->set_node_info(word,ENG_V_ger);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_V_ger");

};
ENG_Tense_particle:
t_ENG_PAR 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_PAR);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_V:
ENG_V_Stem 
{
lexicon word;
const node_info& ENG_V_Stem=sparser->get_node_info($1);
word.gcat="ENG_V";
$$=sparser->set_node_info(word,ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");

}
|ENG_V_Stem ENG_V_lfea_aux
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_aux=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_V",ENG_V_Stem,ENG_V_lfea_aux);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem ENG_V_lfea_aux");

};
ENG_VNEG:
ENG_VNEG_Stem 
{
lexicon word;
const node_info& ENG_VNEG_Stem=sparser->get_node_info($1);
word.gcat="ENG_VNEG";
$$=sparser->set_node_info(word,ENG_VNEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VNEG->ENG_VNEG_Stem");

};
ENG_VNEG_Stem:
t_ENG_VNEG_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_VNEG_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_VP:
ENG_Vbar1 
{
lexicon word;
const node_info& ENG_Vbar1=sparser->get_node_info($1);
word.gcat="ENG_VP";
$$=sparser->set_node_info(word,ENG_Vbar1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1");

}
|ENG_Vbar1 ENG_AdvP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_AdvP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");

}
|ENG_Vbar1 ENG_RC
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_RC=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_RC");

}
|ENG_Vbar2 
{
lexicon word;
const node_info& ENG_Vbar2=sparser->get_node_info($1);
word.gcat="ENG_VP";
$$=sparser->set_node_info(word,ENG_Vbar2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2");

}
|ENG_Vbar2 ENG_PP
{
const node_info& ENG_Vbar2=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_PP");

}
|ENG_Vbar2 ENG_RC
{
const node_info& ENG_Vbar2=sparser->get_node_info($1);
const node_info& ENG_RC=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_RC");

}
|ENG_Vbar3 ENG_NP
{
const node_info& ENG_Vbar3=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar3 ENG_NP");

}
|ENG_Vbar4 ENG_DP
{
const node_info& ENG_Vbar4=sparser->get_node_info($1);
const node_info& ENG_DP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar4 ENG_DP");

};
ENG_V_Stem:
t_ENG_V_Stem 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Stem);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_V_ger:
ENG_V_Stem ENG_V_lfea_ger
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_ger=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_V_ger",ENG_V_Stem,ENG_V_lfea_ger);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_ger->ENG_V_Stem ENG_V_lfea_ger");

};
ENG_V_lfea_aux:
t_ENG_V_Aux 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Aux);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_V_lfea_ger:
t_ENG_V_Gerund 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Gerund);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_Vbar1:
ENG_V ENG_NP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");
};
ENG_Vbar2:
ENG_Vbar1 ENG_NP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_NP");

}
|ENG_Vbar1 ENG_PP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_PP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_PP");

};
ENG_Vbar3:
ENG_V ENG_AdvP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_AdvP=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_Vbar3",ENG_V,ENG_AdvP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar3->ENG_V ENG_AdvP");

};
ENG_Vbar4:
ENG_DP ENG_V
{
const node_info& ENG_DP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");
}
|ENG_TP ENG_V
{
const node_info& ENG_TP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");
};
ENG_lfea_IndefDet:
t_ENG_DET_Indef 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_Indef);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_lfea_fwConsonant:
t_ENG_DET_fwConsonant 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_fwConsonant);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_lfea_fwVowel:
t_ENG_DET_fwVowel 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_fwVowel);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_lfea_swConsonant:
t_ENG_N_swConsonant 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_swConsonant);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_lfea_swVowel:
t_ENG_N_swVowel 
{
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_swVowel);
$$=sparser->set_node_info(word,empty_node_info);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

};
ENG_nCon:
ENG_1Con ENG_Con
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_1Con ENG_Con");

}
|ENG_nCon ENG_Con
{
const node_info& ENG_nCon=sparser->get_node_info($1);
const node_info& ENG_Con=sparser->get_node_info($2);
$$=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_nCon ENG_Con");

};
S:
ENG_VP 
{
lexicon word;
const node_info& ENG_VP=sparser->get_node_info($1);
word.gcat="S";
$$=sparser->set_node_info(word,ENG_VP);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP");

};
%%
int yylex(void){
	int token;
	lexicon word={};

	if(lex->is_end_of_input()==false){
		token=lex->next_token();
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"next token:"+std::to_string(token));
		return token+1;
	}
	else return 0;//historic indicator of YACC about end of input stream
}

void yyerror(char const *yymsgp){
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
	std::locale locale;

	logger::singleton("console",0,"LE");//Don't forget to turn off logging i.e. comment out if necessary e.g. in android release versions
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"human_input:"+std::string(human_input));
	token_paths=new tokenpaths;
	while(human_input!=NULL&&toa!=0&&token_paths->is_any_left()==true){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"picking new token path");
		try{
			if(sqlite==NULL){
				#ifdef __ANDROID__
					if(vm!=NULL) jvm=vm;
					else{
						logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"vm is NULL!");
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
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"lexer started");
			sparser=new interpreter(toa);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"interpreter started");
			if(toa&HI_SYNTAX||toa&HI_SEMANTICS){
				int parse_error=yyparse();
				if(parse_error==0){
					if(toa&HI_SEMANTICS){
						transgraph=sparser->longest_match_for_semantic_rules_found();
						if(transgraph!=NULL){
							token_paths->validate_parse_tree(sparser->nodes());
							token_paths->validate_path(lex->word_entries(),transgraph);
							logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"TRUE");
						}
						else{
							logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"semantic error");
							token_paths->invalidate_parse_tree(sparser->nodes());
							token_paths->invalidate_path(lex->word_entries(),"semantic error",NULL);
						}
					}
					else if(toa&HI_SYNTAX){
						token_paths->validate_parse_tree(sparser->nodes());
						token_paths->validate_path(lex->word_entries(),NULL);
					}
					else{
						throw std::runtime_error("Logic error: missing type of analysis code coverage in case of semantic error");
					}
				}
				else{//syntax error for token in yychar
					logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"syntax error");
					if(toa&HI_SEMANTICS){
						token_paths->invalidate_parse_tree(sparser->nodes());
						token_paths->invalidate_path(lex->word_entries(),"syntax error",NULL);
					}
					else if(toa&HI_SYNTAX){
						token_paths->invalidate_parse_tree(sparser->nodes());
						token_paths->invalidate_path(lex->word_entries(),"syntax error",NULL);
					}
					else{
						throw std::runtime_error("Logic error: missing type of analysis code coverage in case of syntax error");
					}
				}
				delete sparser;
				sparser=NULL;
				transgraph=NULL;
			}
			delete lex;
			lex=NULL;
			if(toa==HI_MORPHOLOGY) break;
		}
		catch(sql_execution_error& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"sql_execution_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_open_db& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"failed_to_open_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_close_db& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"failed_to_close_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(lexicon_type_and_db_table_schema_mismatch& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"lexicon_type_and_db_table_schema_mismatch:"+std::string(exception.what()));
			return NULL;
		}
		catch(more_than_one_token_found& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"more_than_one_token_found:"+std::string(exception.what()));
			return NULL;
		}
		catch(morphan_error& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"morphan_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(object_node_missing& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"object_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(head_node_missing& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"head_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(invalid_combination& exception){
			token_paths->invalidate_path(lex->word_entries(),"invalid combination",&exception);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"invalid_combination:"+std::string(exception.what()));
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
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"missing_prerequisite_symbol:"+std::string(exception.what()));
			return NULL;
		}
		catch(std::runtime_error& exception){//Catch underived exceptions thrown with string based messages
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"runtime exception:"+std::string(exception.what()));
			return NULL;
		}
		catch(...){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(2,"Unexpected error ...");
			return NULL;
		}
	}
	analysis=token_paths->create_analysis(toa,target_language);
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
