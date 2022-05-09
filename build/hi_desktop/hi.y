%code{
#include "tokensymbols.h"
}
%code{
int yylex(yy::parser::semantic_type* yylval);
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
#include "logger.h"
#include "hilib.h"
#include "db_factory.h"
#include "lexer.h"
#include "sp.h"
#include "tokenpaths.h"
#include "query_result.h"
#include "morphan_result.h"
#include "morphan.h"
#include "transgraph.h"
morphan *stemmer=NULL;
lexer *lex=NULL;
interpreter *sparser=NULL;
tokenpaths *token_paths=NULL;
db *db_factory::singleton_instance=NULL;

}
%language "c++"
%define api.value.type {int}
%define parse.error verbose
%start	S
%token	END 0
%token	t_ENG_CON_Stem
%token	t_ENG_A_Stem
%token	t_ENG_Punct_Stem
%token	t_ENG_Punct_FullStop
%token	t_ENG_Punct_QuestionMark
%token	t_ENG_Punct_ExclamationMark
%token	t_ENG_ADV_Stem
%token	t_ENG_DET_Stem
%token	t_ENG_N_Stem
%token	t_ENG_N_Pl
%token	t_ENG_N_Sg
%token	t_ENG_PREP_Stem
%token	t_ENG_QPRO_Stem
%token	t_ENG_V_Stem
%token	t_ENG_V_Aux
%token	t_ENG_RPRO_Stem
%token	t_ENG_RPRO_Relative
%token	t_ENG_VNEG_Stem
%token	t_ENG_ANEG_Stem
%token	t_ENG_PAR_Stem
%token	t_ENG_DET_Indef
%token	t_ENG_DET_fwVowel
%token	t_ENG_DET_fwConsonant
%token	t_ENG_N_swVowel
%token	t_ENG_N_swConsonant
%token	t_ENG_V_Gerund
%token	t_ENG_CONJ_Stem
%%
ENG_1Con:
ENG_Con 
{
const node_info& ENG_Con=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_1Con->ENG_Con");
$$=sparser->set_node_info("ENG_1Con",ENG_Con);

};
ENG_A:
ENG_A_Stem 
{
const node_info& ENG_A_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A->ENG_A_Stem");
$$=sparser->set_node_info("ENG_A",ENG_A_Stem);

};
ENG_A0NEG:
ENG_A 
{
const node_info& ENG_A=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A0NEG->ENG_A");
$$=sparser->set_node_info("ENG_A0NEG",ENG_A);

};
ENG_ANEG:
ENG_ANEG_Stem 
{
const node_info& ENG_ANEG_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ANEG->ENG_ANEG_Stem");
$$=sparser->set_node_info("ENG_ANEG",ENG_ANEG_Stem);

};
ENG_ANEG_Stem:
t_ENG_ANEG_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ANEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_ANEG_Stem",word);

};
ENG_AP:
ENG_Abar1 
{
const node_info& ENG_Abar1=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar1");
$$=sparser->set_node_info("ENG_AP",ENG_Abar1);

}
|ENG_Abar2 
{
const node_info& ENG_Abar2=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar2");
$$=sparser->set_node_info("ENG_AP",ENG_Abar2);

}
|ENG_Alist 
{
const node_info& ENG_Alist=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Alist");
$$=sparser->set_node_info("ENG_AP",ENG_Alist);

};
ENG_A_Stem:
t_ENG_A_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_A_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_A_Stem",word);

};
ENG_Abar1:
ENG_A0NEG 
{
const node_info& ENG_A0NEG=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_A0NEG");
$$=sparser->set_node_info("ENG_Abar1",ENG_A0NEG);

}
|ENG_ANEG ENG_A
{
const node_info& ENG_ANEG=sparser->get_node_info($1);
const node_info& ENG_A=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_ANEG ENG_A");
$$=sparser->combine_nodes("ENG_Abar1",ENG_ANEG,ENG_A);

};
ENG_Abar2:
ENG_Abar2 ENG_CONJA
{
const node_info& ENG_Abar2=sparser->get_node_info($1);
const node_info& ENG_CONJA=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar2 ENG_CONJA");
$$=sparser->combine_nodes("ENG_Abar2",ENG_Abar2,ENG_CONJA);

}
|ENG_Ahead ENG_CONJA
{
const node_info& ENG_Ahead=sparser->get_node_info($1);
const node_info& ENG_CONJA=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Ahead ENG_CONJA");
$$=sparser->combine_nodes("ENG_Abar2",ENG_Ahead,ENG_CONJA);

}
|ENG_Alist ENG_CONJA
{
const node_info& ENG_Alist=sparser->get_node_info($1);
const node_info& ENG_CONJA=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Alist ENG_CONJA");
$$=sparser->combine_nodes("ENG_Abar2",ENG_Alist,ENG_CONJA);

};
ENG_Adv:
t_ENG_ADV_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ADV_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Adv",word);

};
ENG_AdvP:
ENG_Adv 
{
const node_info& ENG_Adv=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AdvP->ENG_Adv");
$$=sparser->set_node_info("ENG_AdvP",ENG_Adv);

};
ENG_Ahead:
ENG_Abar1 
{
const node_info& ENG_Abar1=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Ahead->ENG_Abar1");
$$=sparser->set_node_info("ENG_Ahead",ENG_Abar1);

};
ENG_Alist:
ENG_Abar1 ENG_Abar1
{
const node_info& ENG_Abar11=sparser->get_node_info($1);
const node_info& ENG_Abar12=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Abar1 ENG_Abar1");
$$=sparser->combine_nodes("ENG_Alist",ENG_Abar11,ENG_Abar12);

}
|ENG_Alist ENG_Abar1
{
const node_info& ENG_Alist=sparser->get_node_info($1);
const node_info& ENG_Abar1=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Alist ENG_Abar1");
$$=sparser->combine_nodes("ENG_Alist",ENG_Alist,ENG_Abar1);

};
ENG_CAP:
ENG_1Con ENG_N_Pl_0Con_swC
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swC");
$$=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swC);

}
|ENG_1Con ENG_N_Pl_0Con_swV
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swV");
$$=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swV);

};
ENG_CNP:
ENG_AP ENG_N
{
const node_info& ENG_AP=sparser->get_node_info($1);
const node_info& ENG_N=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_AP ENG_N");
$$=sparser->combine_nodes("ENG_CNP",ENG_AP,ENG_N);

}
|ENG_N 
{
const node_info& ENG_N=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_N");
$$=sparser->set_node_info("ENG_CNP",ENG_N);

};
ENG_CONJ:
ENG_CONJ_Stem 
{
const node_info& ENG_CONJ_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJ->ENG_CONJ_Stem");
$$=sparser->set_node_info("ENG_CONJ",ENG_CONJ_Stem);

};
ENG_CONJA:
ENG_CONJ ENG_Abar1
{
const node_info& ENG_CONJ=sparser->get_node_info($1);
const node_info& ENG_Abar1=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Abar1");
$$=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Abar1);

}
|ENG_CONJ ENG_Alist
{
const node_info& ENG_CONJ=sparser->get_node_info($1);
const node_info& ENG_Alist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Alist");
$$=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Alist);

};
ENG_CONJ_Stem:
t_ENG_CONJ_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CONJ_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_CONJ_Stem",word);

};
ENG_Con:
t_ENG_CON_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Con",word);

};
ENG_DP:
ENG_Indef_Det_a ENG_N_Sg_0Con_swC
{
const node_info& ENG_Indef_Det_a=sparser->get_node_info($1);
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC");
$$=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);

}
|ENG_Indef_Det_an ENG_N_Sg_0Con_swV
{
const node_info& ENG_Indef_Det_an=sparser->get_node_info($1);
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV");
$$=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);

};
ENG_Det_stem:
t_ENG_DET_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Det_stem",word);

};
ENG_IVP:
ENG_NV ENG_PP
{
const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");
$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
}
|ENG_V ENG_AP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_AP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_AP");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_AP);
}
|ENG_V ENG_PP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
};
ENG_Indef_Det:
ENG_Det_stem ENG_lfea_IndefDet
{
const node_info& ENG_Det_stem=sparser->get_node_info($1);
const node_info& ENG_lfea_IndefDet=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet");
$$=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);

};
ENG_Indef_Det_a:
ENG_Indef_Det ENG_lfea_fwConsonant
{
const node_info& ENG_Indef_Det=sparser->get_node_info($1);
const node_info& ENG_lfea_fwConsonant=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant");
$$=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);

};
ENG_Indef_Det_an:
ENG_Indef_Det ENG_lfea_fwVowel
{
const node_info& ENG_Indef_Det=sparser->get_node_info($1);
const node_info& ENG_lfea_fwVowel=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel");
$$=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);

};
ENG_N:
ENG_N_Pl 
{
const node_info& ENG_N_Pl=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Pl");
$$=sparser->set_node_info("ENG_N",ENG_N_Pl);

}
|ENG_N_Sg 
{
const node_info& ENG_N_Sg=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Sg");
$$=sparser->set_node_info("ENG_N",ENG_N_Sg);

};
ENG_NP:
ENG_CAP 
{
const node_info& ENG_CAP=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CAP");
$$=sparser->set_node_info("ENG_NP",ENG_CAP);

}
|ENG_CNP 
{
const node_info& ENG_CNP=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CNP");
$$=sparser->set_node_info("ENG_NP",ENG_CNP);

}
|ENG_QPro ENG_CNP
{
const node_info& ENG_QPro=sparser->get_node_info($1);
const node_info& ENG_CNP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_QPro ENG_CNP");
$$=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);

};
ENG_NV:
ENG_V ENG_VNEG
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_VNEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_V ENG_VNEG");
$$=sparser->combine_nodes("ENG_NV",ENG_V,ENG_VNEG);

};
ENG_N_Pl:
ENG_N_Pl_0Con_swC 
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC");
$$=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swC);

}
|ENG_N_Pl_0Con_swC ENG_nCon
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info($1);
const node_info& ENG_nCon=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon");
$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);

}
|ENG_N_Pl_0Con_swV 
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV");
$$=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swV);

}
|ENG_N_Pl_0Con_swV ENG_nCon
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info($1);
const node_info& ENG_nCon=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon");
$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);

}
|ENG_N_Sg ENG_nCon
{
//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in 'list file abc def'
//TODO: Any better solution???
YYERROR;
}
|ENG_nCon 
{
const node_info& ENG_nCon=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_nCon");
$$=sparser->set_node_info("ENG_N_Pl",ENG_nCon);

};
ENG_N_Pl_0Con:
ENG_N_Stem ENG_N_lfea_Pl
{
const node_info& ENG_N_Stem=sparser->get_node_info($1);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl");
$$=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);

};
ENG_N_Pl_0Con_swC:
ENG_N_Pl_0Con ENG_lfea_swConsonant
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant");
$$=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);

};
ENG_N_Pl_0Con_swV:
ENG_N_Pl_0Con ENG_lfea_swVowel
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swVowel=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel");
$$=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);

};
ENG_N_Sg:
ENG_1Con 
{
const node_info& ENG_1Con=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_1Con");
$$=sparser->set_node_info("ENG_N_Sg",ENG_1Con);

}
|ENG_N_Sg_0Con_swC 
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC");
$$=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swC);

}
|ENG_N_Sg_0Con_swC ENG_1Con
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info($1);
const node_info& ENG_1Con=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con");
$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swC,ENG_1Con);

}
|ENG_N_Sg_0Con_swV 
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV");
$$=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swV);

}
|ENG_N_Sg_0Con_swV ENG_1Con
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info($1);
const node_info& ENG_1Con=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con");
$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swV,ENG_1Con);

};
ENG_N_Sg_0Con:
ENG_N_Stem ENG_N_lfea_Sg
{
const node_info& ENG_N_Stem=sparser->get_node_info($1);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg");
$$=sparser->combine_nodes("ENG_N_Sg_0Con",ENG_N_Stem,ENG_N_lfea_Sg);

};
ENG_N_Sg_0Con_swC:
ENG_N_Sg_0Con ENG_lfea_swConsonant
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant");
$$=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);

};
ENG_N_Sg_0Con_swV:
ENG_N_Sg_0Con ENG_lfea_swVowel
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info($1);
const node_info& ENG_lfea_swVowel=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel");
$$=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);

};
ENG_N_Stem:
t_ENG_N_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_N_Stem",word);

};
ENG_N_lfea_Pl:
t_ENG_N_Pl 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Pl);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_N_lfea_Pl",word);

};
ENG_N_lfea_Sg:
t_ENG_N_Sg 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_N_lfea_Sg",word);

};
ENG_PP:
ENG_Prep ENG_NP
{
const node_info& ENG_Prep=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");
$$=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);

};
ENG_Prep:
t_ENG_PREP_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PREP_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Prep",word);

};
ENG_Punct:
ENG_Punct_Stem ENG_Punct_ExclamationMark
{
const node_info& ENG_Punct_Stem=sparser->get_node_info($1);
const node_info& ENG_Punct_ExclamationMark=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct->ENG_Punct_Stem ENG_Punct_ExclamationMark");
$$=sparser->combine_nodes("ENG_Punct",ENG_Punct_Stem,ENG_Punct_ExclamationMark);

}
|ENG_Punct_Stem ENG_Punct_FullStop
{
const node_info& ENG_Punct_Stem=sparser->get_node_info($1);
const node_info& ENG_Punct_FullStop=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct->ENG_Punct_Stem ENG_Punct_FullStop");
$$=sparser->combine_nodes("ENG_Punct",ENG_Punct_Stem,ENG_Punct_FullStop);

}
|ENG_Punct_Stem ENG_Punct_QuestionMark
{
const node_info& ENG_Punct_Stem=sparser->get_node_info($1);
const node_info& ENG_Punct_QuestionMark=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct->ENG_Punct_Stem ENG_Punct_QuestionMark");
$$=sparser->combine_nodes("ENG_Punct",ENG_Punct_Stem,ENG_Punct_QuestionMark);

};
ENG_Punct_ExclamationMark:
t_ENG_Punct_ExclamationMark 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_ExclamationMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Punct_ExclamationMark",word);

};
ENG_Punct_FullStop:
t_ENG_Punct_FullStop 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_FullStop);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Punct_FullStop",word);

};
ENG_Punct_QuestionMark:
t_ENG_Punct_QuestionMark 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_QuestionMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Punct_QuestionMark",word);

};
ENG_Punct_Stem:
t_ENG_Punct_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Punct_Stem",word);

};
ENG_QPro:
t_ENG_QPRO_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_QPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_QPro",word);

};
ENG_RC:
ENG_RPro ENG_IVP
{
const node_info& ENG_RPro=sparser->get_node_info($1);
const node_info& ENG_IVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVP");
$$=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);

};
ENG_RPro:
ENG_RPro_stem ENG_RPro_lfea_relative
{
const node_info& ENG_RPro_stem=sparser->get_node_info($1);
const node_info& ENG_RPro_lfea_relative=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative");
$$=sparser->combine_nodes("ENG_RPro",ENG_RPro_stem,ENG_RPro_lfea_relative);

};
ENG_RPro_lfea_relative:
t_ENG_RPRO_Relative 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_RPro_lfea_relative",word);

};
ENG_RPro_stem:
t_ENG_RPRO_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_RPro_stem",word);

};
ENG_TP:
ENG_Tense_particle ENG_V_Stem
{
const node_info& ENG_Tense_particle=sparser->get_node_info($1);
const node_info& ENG_V_Stem=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_Tense_particle ENG_V_Stem");
$$=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_Stem);

}
|ENG_V_ger 
{
const node_info& ENG_V_ger=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_V_ger");
$$=sparser->set_node_info("ENG_TP",ENG_V_ger);

};
ENG_Tense_particle:
t_ENG_PAR_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PAR_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Tense_particle",word);

};
ENG_V:
ENG_V_Stem 
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");
$$=sparser->set_node_info("ENG_V",ENG_V_Stem);

}
|ENG_V_Stem ENG_V_lfea_aux
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_aux=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem ENG_V_lfea_aux");
$$=sparser->combine_nodes("ENG_V",ENG_V_Stem,ENG_V_lfea_aux);

};
ENG_VNEG:
ENG_VNEG_Stem 
{
const node_info& ENG_VNEG_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VNEG->ENG_VNEG_Stem");
$$=sparser->set_node_info("ENG_VNEG",ENG_VNEG_Stem);

};
ENG_VNEG_Stem:
t_ENG_VNEG_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_VNEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_VNEG_Stem",word);

};
ENG_VP:
ENG_Vbar1 
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1");
$$=sparser->set_node_info("ENG_VP",ENG_Vbar1);

}
|ENG_Vbar1 ENG_AP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_AP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AP);

}
|ENG_Vbar1 ENG_AdvP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_AdvP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);

}
|ENG_Vbar1 ENG_RC
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_RC=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_RC");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);

}
|ENG_Vbar2 
{
const node_info& ENG_Vbar2=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2");
$$=sparser->set_node_info("ENG_VP",ENG_Vbar2);

}
|ENG_Vbar2 ENG_PP
{
const node_info& ENG_Vbar2=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_PP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);

}
|ENG_Vbar2 ENG_RC
{
const node_info& ENG_Vbar2=sparser->get_node_info($1);
const node_info& ENG_RC=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_RC");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);

}
|ENG_Vbar3 ENG_NP
{
const node_info& ENG_Vbar3=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar3 ENG_NP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);

}
|ENG_Vbar4 ENG_DP
{
const node_info& ENG_Vbar4=sparser->get_node_info($1);
const node_info& ENG_DP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar4 ENG_DP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);

}
|ENG_Vbar5 ENG_AP
{
const node_info& ENG_Vbar5=sparser->get_node_info($1);
const node_info& ENG_AP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar5 ENG_AP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar5,ENG_AP);

}
|ENG_Vbar5 ENG_DP
{
const node_info& ENG_Vbar5=sparser->get_node_info($1);
const node_info& ENG_DP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar5 ENG_DP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar5,ENG_DP);

};
ENG_V_Stem:
t_ENG_V_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_V_Stem",word);

};
ENG_V_ger:
ENG_V_Stem ENG_V_lfea_ger
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_ger=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_ger->ENG_V_Stem ENG_V_lfea_ger");
$$=sparser->combine_nodes("ENG_V_ger",ENG_V_Stem,ENG_V_lfea_ger);

};
ENG_V_lfea_aux:
t_ENG_V_Aux 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Aux);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_V_lfea_aux",word);

};
ENG_V_lfea_ger:
t_ENG_V_Gerund 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Gerund);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_V_lfea_ger",word);

};
ENG_Vbar1:
ENG_V ENG_NP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");
$$=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
};
ENG_Vbar2:
ENG_Vbar1 ENG_NP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_NP");
$$=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);

}
|ENG_Vbar1 ENG_PP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_PP");
$$=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_PP);

};
ENG_Vbar3:
ENG_V ENG_AdvP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_AdvP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar3->ENG_V ENG_AdvP");
$$=sparser->combine_nodes("ENG_Vbar3",ENG_V,ENG_AdvP);

};
ENG_Vbar4:
ENG_DP ENG_V
{
const node_info& ENG_DP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
}
|ENG_TP ENG_V
{
const node_info& ENG_TP=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");
$$=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
};
ENG_Vbar5:
ENG_N_Sg ENG_V
{
const node_info& ENG_N_Sg=sparser->get_node_info($1);
const node_info& ENG_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar5->ENG_N_Sg ENG_V");
$$=sparser->combine_nodes("ENG_Vbar5",ENG_V,ENG_N_Sg);
};
ENG_lfea_IndefDet:
t_ENG_DET_Indef 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Indef);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_lfea_IndefDet",word);

};
ENG_lfea_fwConsonant:
t_ENG_DET_fwConsonant 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_lfea_fwConsonant",word);

};
ENG_lfea_fwVowel:
t_ENG_DET_fwVowel 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_lfea_fwVowel",word);

};
ENG_lfea_swConsonant:
t_ENG_N_swConsonant 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_lfea_swConsonant",word);

};
ENG_lfea_swVowel:
t_ENG_N_swVowel 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_lfea_swVowel",word);

};
ENG_nCon:
ENG_1Con ENG_Con
{
const node_info& ENG_1Con=sparser->get_node_info($1);
const node_info& ENG_Con=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_1Con ENG_Con");
$$=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);

}
|ENG_nCon ENG_Con
{
const node_info& ENG_nCon=sparser->get_node_info($1);
const node_info& ENG_Con=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_nCon ENG_Con");
$$=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);

};
S:
ENG_VP ENG_Punct
{
const node_info& ENG_VP=sparser->get_node_info($1);
const node_info& ENG_Punct=sparser->get_node_info($2);
std::vector<unsigned int> nodes;
sparser->get_nodes_by_symbol(ENG_Punct,"QuestionMark",std::string(),nodes);
if(nodes.size()==1){
	const node_info& punct=sparser->get_node_info(nodes[0]);
	sparser->add_feature_to_leaf(ENG_VP,"main_verb","interrogative",true);
}
else{
	nodes.clear();
	sparser->get_nodes_by_symbol(ENG_Punct,"FullStop",std::string(),nodes);
	if(nodes.size()==1){
		const node_info& punct=sparser->get_node_info(nodes[0]);
		sparser->add_feature_to_leaf(ENG_VP,"main_verb","indicative",true);
	}
	else{
		sparser->add_feature_to_leaf(ENG_VP,"main_verb","imperative",true);
	}
}
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP ENG_Punct");
$$=sparser->combine_nodes("S",ENG_VP,ENG_Punct);
};
%%
int yylex(yy::parser::semantic_type* yylval){
	int token;
	lexicon word={};

	if(lex->is_end_of_input()==false){
		token=lex->next_token();
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"next token:"+std::to_string(token));
		return token;
	}
	else return 0;//historic indicator of YACC about end of input stream
}

void yy::parser::error(const std::string& msg){
	token_paths->log_yyerror(msg);
	return;
}

#ifdef __EMSCRIPTEN__
extern "C"{
#endif

#ifdef __ANDROID__
const char *hi(const char *human_input,const char *language,const unsigned char toa,const char *target_language,const char *db_uri,JavaVM *vm,jobject activityobj,const char *source,const unsigned char crh){
#else
const char *hi(const char *human_input,const char *language,const unsigned char toa,const char *target_language,const char *db_uri,const char *source,const unsigned char crh){
#endif

    std::string analyses;
	db *sqlite=NULL;
	transgraph *transgraph=NULL;
	char *analysischr=NULL;
	std::locale locale;
	yy::parser parser;
    std::time_t timestamp=std::time(nullptr);

    logger::singleton("console",0,"LE");//Don't forget to turn off logging i.e. comment out if necessary e.g. in android release versions
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"human_input:"+std::string(human_input));
    token_paths=new tokenpaths(toa);
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
			lex=new lexer(human_input,language,locale,false,token_paths);
			token_paths->assign_lexer(lex);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"lexer started");
            sparser=new interpreter(toa);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"interpreter started");
            if(toa&HI_SYNTAX||toa&HI_SYNTAX&&toa&HI_SEMANTICS){
				int parse_error=parser.parse();
				if(parse_error==0){
					if(toa&HI_SEMANTICS){
						transgraph=sparser->longest_match_for_semantic_rules_found();
						if(transgraph!=NULL){
							token_paths->validate_parse_tree(sparser->nodes());
							token_paths->validate_path(lex->word_entries(),transgraph,true);
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
						token_paths->validate_path(lex->word_entries(),NULL,true);
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
            else if(toa&HI_SEMANTICS){
                sparser->build_dependency_semantics(toa,crh,language,lex,token_paths);
                delete sparser;
                sparser=NULL;
                transgraph=NULL;
                delete lex;
                lex=NULL;
                break;
            }
            delete lex;
            lex=NULL;
			if(toa==HI_MORPHOLOGY) break;
		}
		catch(sql_execution_error& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"sql_execution_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_open_db& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"failed_to_open_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(failed_to_close_db& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"failed_to_close_db:"+std::string(exception.what()));
			return NULL;
		}
		catch(lexicon_type_and_db_table_schema_mismatch& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"lexicon_type_and_db_table_schema_mismatch:"+std::string(exception.what()));
			return NULL;
		}
		catch(more_than_one_token_found& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"more_than_one_token_found:"+std::string(exception.what()));
			return NULL;
		}
		catch(morphan_error& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"morphan_error:"+std::string(exception.what()));
			return NULL;
		}
		catch(object_node_missing& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"object_node_missing:"+std::string(exception.what()));
			return NULL;
		}
		catch(head_node_missing& exception){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"head_node_missing:"+std::string(exception.what()));
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
		catch(dependency_counter_manner_validation_failed& exception){
			token_paths->invalidate_path(lex->word_entries(),"semantic error",&exception);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"semantic error:"+std::string(exception.what()));
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
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"missing_prerequisite_symbol:"+std::string(exception.what()));
			return NULL;
		}
		catch(std::runtime_error& exception){//Catch underived exceptions thrown with string based messages
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"runtime error:"+std::string(exception.what()));
			return NULL;
		}
		catch(...){
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"unexpected error ...");
			return NULL;
		}
    morphan_result::clear_global_features();
    transgraph::clear_node_functor_map();
    }
    analyses=token_paths->create_analysis(toa,language,target_language,std::string(human_input),timestamp,std::string(source));
    if(analyses.empty()==false){
        analysischr=new char[analyses.length()+1];
        analyses.copy(analysischr,analyses.length(),0);
        analysischr[analyses.length()]='\0';
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
