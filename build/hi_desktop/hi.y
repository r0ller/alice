%code{
#include "tokensymbols.h"
}
%code{
#ifndef C_DECLARATIONS
#define C_DECLARATIONS
int yylex(yy::parser::semantic_type* yylval);
#include <iostream>
#include <locale>
#include <algorithm>
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
#include "pp_factory.h"
morphan *stemmer=NULL;
lexer *lex=NULL;
interpreter *sparser=NULL;
tokenpaths *token_paths=NULL;
db *db_factory::singleton_instance=NULL;
#endif
}
%language "c++"
%define api.value.type {int}
%define parse.error verbose
%start	S
%token	END 0
%token	t_ENG_CON_Stem
%token	t_ENG_A_Stem
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
%token	t_ENG_Num_Stem
%token	t_ENG_Num_Ord
%token	t_ENG_Num_Npref1n
%token	t_ENG_Num_Npref2n
%token	t_ENG_Num_Npref3n
%token	t_ENG_Num_Npref4n
%token	t_ENG_Num_Npref5n
%token	t_ENG_Num_Npref6n
%token	t_ENG_Num_Npref7n
%token	t_ENG_Num_Npref8n
%token	t_ENG_Num_Npref9n
%token	t_ENG_Num_swVowel
%token	t_ENG_Num_swConsonant
%token	t_ENG_DET_Def
%token	t_HUN_CON_Stem
%token	t_HUN_Punct_Stem
%token	t_HUN_Punct_FullStop
%token	t_HUN_Punct_QuestionMark
%token	t_HUN_Punct_ExclamationMark
%token	t_HUN_Pronoun_Stem
%token	t_HUN_Pronoun_Int
%token	t_HUN_Pronoun_Nom
%token	t_HUN_Num_Stem
%token	t_HUN_Num_Ik
%token	t_HUN_Num_Par
%token	t_HUN_Num_Npref1
%token	t_HUN_Num_Npref2
%token	t_HUN_Num_Npref3
%token	t_HUN_Num_Npref4
%token	t_HUN_Num_Npref5
%token	t_HUN_Num_Npref6
%token	t_HUN_Num_Npref7
%token	t_HUN_Num_Npref8
%token	t_HUN_Num_Npref9
%token	t_HUN_Num_Npref1nn
%token	t_HUN_Num_Npref1nnn
%token	t_HUN_Det_Stem
%token	t_HUN_Det_Def
%token	t_HUN_Det_fwVowel
%token	t_HUN_Det_fwConsonant
%token	t_HUN_CON_swVowel
%token	t_HUN_CON_swConsonant
%token	t_HUN_Num_Acc
%token	t_HUN_Num_Npref1n
%token	t_HUN_Num_Npref2n
%token	t_HUN_Num_Npref3n
%token	t_HUN_Num_Npref4n
%token	t_HUN_Num_Npref5n
%token	t_HUN_Num_Npref6n
%token	t_HUN_Num_Npref7n
%token	t_HUN_Num_Npref8n
%token	t_HUN_Num_Npref9n
%token	t_HUN_Num_swVowel
%token	t_HUN_Num_swConsonant
%token	t_HUN_Noun_Stem
%token	t_HUN_Noun_Acc
%token	t_HUN_Noun_swVowel
%token	t_HUN_Noun_swConsonant
%token	t_HUN_CON_Acc
%token	t_HUN_Verb_Stem
%token	t_HUN_Verb_ConjDefSg2
%token	t_HUN_Vbpfx_Stem
%token	t_HUN_Noun_Relative
%token	t_HUN_Conj_Stem
%token	t_HUN_Neg_Stem
%token	t_HUN_Noun_Plur
%token	t_HUN_Noun_Ine
%token	t_HUN_Verb_IndefSg3
%token	t_HUN_Verb_ConjIndefSg2
%token	t_HUN_Adj_Stem
%token	t_HUN_CON_Sub
%token	t_HUN_Noun_Sub
%token	t_HUN_CON_Ins
%token	t_HUN_Verb_IndefPl3
%token	t_HUN_Verb_DefSg1
%token	t_HUN_Noun_Dat
%token	t_HUN_CON_Dat
%token	t_HUN_Num_Dat
%token	t_HUN_Noun_Del
%token	t_HUN_Num_Del
%token	t_HUN_Noun_Pref
%token	t_JSON_CON_Stem
%token	t_JSON_Punct_Stem
%token	t_JSON_Punct_Hash
%token	t_JSON_Punct_Comma
%token	t_JSON_Punct_Colon
%token	t_JSON_Punct_Quotes
%token	t_JSON_Punct_OpeningSBracket
%token	t_JSON_Punct_ClosingSBracket
%token	t_JSON_Punct_Relative

%precedence t_HUN_CON_Stem t_HUN_Num_Stem t_HUN_CON_swVowel t_HUN_CON_swConsonant t_HUN_Num_swVowel t_HUN_Num_swConsonant t_HUN_Noun_Stem t_HUN_Noun_swVowel t_HUN_Noun_swConsonant t_HUN_Neg_Stem t_HUN_Adj_Stem
%precedence t_HUN_Conj_Stem
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
ENG_Abar1 ENG_CONJA
{
const node_info& ENG_Abar1=sparser->get_node_info($1);
const node_info& ENG_CONJA=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar1 ENG_CONJA");
$$=sparser->combine_nodes("ENG_Abar2",ENG_Abar1,ENG_CONJA);

}
|ENG_Abar2 ENG_CONJA
{
const node_info& ENG_Abar2=sparser->get_node_info($1);
const node_info& ENG_CONJA=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar2 ENG_CONJA");
$$=sparser->combine_nodes("ENG_Abar2",ENG_Abar2,ENG_CONJA);

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
ENG_ConjPVP:
ENG_CONJ ENG_PVP
{
const node_info& ENG_CONJ=sparser->get_node_info($1);
const node_info& ENG_PVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjPVP->ENG_CONJ ENG_PVP");
$$=sparser->combine_nodes("ENG_ConjPVP",ENG_CONJ,ENG_PVP);

}
|ENG_CONJ ENG_PVPlist
{
const node_info& ENG_CONJ=sparser->get_node_info($1);
const node_info& ENG_PVPlist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjPVP->ENG_CONJ ENG_PVPlist");
$$=sparser->combine_nodes("ENG_ConjPVP",ENG_CONJ,ENG_PVPlist);

};
ENG_ConjV:
ENG_CONJ ENG_IVP
{
const node_info& ENG_CONJ=sparser->get_node_info($1);
const node_info& ENG_IVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjV->ENG_CONJ ENG_IVP");
$$=sparser->combine_nodes("ENG_ConjV",ENG_CONJ,ENG_IVP);

}
|ENG_CONJ ENG_IVPlist
{
const node_info& ENG_CONJ=sparser->get_node_info($1);
const node_info& ENG_IVPlist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjV->ENG_CONJ ENG_IVPlist");
$$=sparser->combine_nodes("ENG_ConjV",ENG_CONJ,ENG_IVPlist);

};
ENG_DP:
ENG_Def_Det ENG_N
{
const node_info& ENG_Def_Det=sparser->get_node_info($1);
const node_info& ENG_N=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Def_Det ENG_N");
$$=sparser->combine_nodes("ENG_DP",ENG_Def_Det,ENG_N);

}
|ENG_Def_Det ENG_Num_Ord
{
const node_info& ENG_Def_Det=sparser->get_node_info($1);
const node_info& ENG_Num_Ord=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Def_Det ENG_Num_Ord");
$$=sparser->combine_nodes("ENG_DP",ENG_Def_Det,ENG_Num_Ord);

}
|ENG_Indef_Det_a ENG_N_Sg_0Con_swC
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
ENG_Def_Det:
ENG_Det_stem ENG_lfea_DefDet
{
const node_info& ENG_Det_stem=sparser->get_node_info($1);
const node_info& ENG_lfea_DefDet=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Def_Det->ENG_Det_stem ENG_lfea_DefDet");
$$=sparser->combine_nodes("ENG_Def_Det",ENG_Det_stem,ENG_lfea_DefDet);

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
ENG_NV ENG_NP
{
const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"ENG_V_Aux","V",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_NP");
$$=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_NP);
}
|ENG_NV ENG_PP
{
const node_info& ENG_NV=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
sparser->add_feature_to_leaf(ENG_NV,"ENG_V_Aux","V",std::string("RCV"));
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
|ENG_V ENG_NP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
unsigned int leaf_node_id=sparser->add_feature_to_leaf(ENG_V,"ENG_V_Aux","V",std::string("RCV"));
if(leaf_node_id==0) sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_NP");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_NP);
}
|ENG_V ENG_PP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
unsigned int leaf_node_id=sparser->add_feature_to_leaf(ENG_V,"ENG_V_Aux","V",std::string("RCV"));
if(leaf_node_id==0) sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
$$=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
};
ENG_IVPConj:
ENG_IVPConj ENG_ConjV
{
const node_info& ENG_IVPConj=sparser->get_node_info($1);
const node_info& ENG_ConjV=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_IVPConj ENG_ConjV");
$$=sparser->combine_nodes("ENG_IVPConj",ENG_IVPConj,ENG_ConjV);

}
|ENG_Vhead ENG_ConjV
{
const node_info& ENG_Vhead=sparser->get_node_info($1);
const node_info& ENG_ConjV=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_Vhead ENG_ConjV");
$$=sparser->combine_nodes("ENG_IVPConj",ENG_Vhead,ENG_ConjV);

}
|ENG_Vlisthead ENG_ConjV
{
const node_info& ENG_Vlisthead=sparser->get_node_info($1);
const node_info& ENG_ConjV=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_Vlisthead ENG_ConjV");
$$=sparser->combine_nodes("ENG_IVPConj",ENG_Vlisthead,ENG_ConjV);

};
ENG_IVPlist:
ENG_IVP ENG_IVP
{
const node_info& ENG_IVP1=sparser->get_node_info($1);
const node_info& ENG_IVP2=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPlist->ENG_IVP ENG_IVP");
$$=sparser->combine_nodes("ENG_IVPlist",ENG_IVP1,ENG_IVP2);

}
|ENG_IVPlist ENG_IVP
{
const node_info& ENG_IVPlist=sparser->get_node_info($1);
const node_info& ENG_IVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPlist->ENG_IVPlist ENG_IVP");
$$=sparser->combine_nodes("ENG_IVPlist",ENG_IVPlist,ENG_IVP);

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
ENG_NV_Aux ENG_V_Stem
{
const node_info& ENG_NV_Aux=sparser->get_node_info($1);
const node_info& ENG_V_Stem=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_NV_Aux ENG_V_Stem");
$$=sparser->combine_nodes("ENG_NV",ENG_NV_Aux,ENG_V_Stem);

}
|ENG_V ENG_VNEG
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_VNEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_V ENG_VNEG");
$$=sparser->combine_nodes("ENG_NV",ENG_V,ENG_VNEG);

};
ENG_NV_Aux:
ENG_V_Aux ENG_VNEG
{
const node_info& ENG_V_Aux=sparser->get_node_info($1);
const node_info& ENG_VNEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV_Aux->ENG_V_Aux ENG_VNEG");
$$=sparser->combine_nodes("ENG_NV_Aux",ENG_V_Aux,ENG_VNEG);

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
ENG_Num:
ENG_Num_Pref ENG_Num
{
const node_info& ENG_Num_Pref=sparser->get_node_info($1);
const node_info& ENG_Num=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Pref ENG_Num");
$$=sparser->combine_nodes("ENG_Num",ENG_Num_Pref,ENG_Num);

}
|ENG_Num_Stem 
{
const node_info& ENG_Num_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Stem");
$$=sparser->set_node_info("ENG_Num",ENG_Num_Stem);

};
ENG_Num_Ord:
ENG_Num ENG_Num_lfea_Ord
{
const node_info& ENG_Num=sparser->get_node_info($1);
const node_info& ENG_Num_lfea_Ord=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num_Ord->ENG_Num ENG_Num_lfea_Ord");
$$=sparser->combine_nodes("ENG_Num_Ord",ENG_Num,ENG_Num_lfea_Ord);

};
ENG_Num_Pref:
t_ENG_Num_Npref1n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

}
|t_ENG_Num_Npref2n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

}
|t_ENG_Num_Npref3n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

}
|t_ENG_Num_Npref4n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

}
|t_ENG_Num_Npref5n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

}
|t_ENG_Num_Npref6n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

}
|t_ENG_Num_Npref7n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

}
|t_ENG_Num_Npref8n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

}
|t_ENG_Num_Npref9n 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Pref",word);

};
ENG_Num_Stem:
t_ENG_Num_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_Stem",word);

};
ENG_Num_lfea_Ord:
t_ENG_Num_Ord 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Ord);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_lfea_Ord",word);

};
ENG_PNVPbar:
ENG_VNEG ENG_PVPbar
{
const node_info& ENG_VNEG=sparser->get_node_info($1);
const node_info& ENG_PVPbar=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PNVPbar->ENG_VNEG ENG_PVPbar");
$$=sparser->combine_nodes("ENG_PNVPbar",ENG_VNEG,ENG_PVPbar);

};
ENG_PP:
ENG_Prep ENG_NP
{
const node_info& ENG_Prep=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");
$$=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);

};
ENG_PVP:
ENG_PNVPbar 
{
const node_info& ENG_PNVPbar=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVP->ENG_PNVPbar");
$$=sparser->set_node_info("ENG_PVP",ENG_PNVPbar);

}
|ENG_PVPbar 
{
const node_info& ENG_PVPbar=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVP->ENG_PVPbar");
$$=sparser->set_node_info("ENG_PVP",ENG_PVPbar);

};
ENG_PVPConj:
ENG_PVPConj ENG_ConjPVP
{
const node_info& ENG_PVPConj=sparser->get_node_info($1);
const node_info& ENG_ConjPVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPConj ENG_ConjPVP");
$$=sparser->combine_nodes("ENG_PVPConj",ENG_PVPConj,ENG_ConjPVP);

}
|ENG_PVPhead ENG_ConjPVP
{
const node_info& ENG_PVPhead=sparser->get_node_info($1);
const node_info& ENG_ConjPVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPhead ENG_ConjPVP");
$$=sparser->combine_nodes("ENG_PVPConj",ENG_PVPhead,ENG_ConjPVP);

}
|ENG_PVPlisthead ENG_ConjPVP
{
const node_info& ENG_PVPlisthead=sparser->get_node_info($1);
const node_info& ENG_ConjPVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPlisthead ENG_ConjPVP");
$$=sparser->combine_nodes("ENG_PVPConj",ENG_PVPlisthead,ENG_ConjPVP);

};
ENG_PVPbar:
ENG_V_Ger ENG_NP
{
const node_info& ENG_V_Ger=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPbar->ENG_V_Ger ENG_NP");
$$=sparser->combine_nodes("ENG_PVPbar",ENG_V_Ger,ENG_NP);
}
|ENG_V_Ger ENG_PP
{
const node_info& ENG_V_Ger=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPbar->ENG_V_Ger ENG_PP");
$$=sparser->combine_nodes("ENG_PVPbar",ENG_V_Ger,ENG_PP);
};
ENG_PVPhead:
ENG_PVP 
{
const node_info& ENG_PVP=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPhead->ENG_PVP");
$$=sparser->set_node_info("ENG_PVPhead",ENG_PVP);

};
ENG_PVPlist:
ENG_PVP ENG_PVP
{
const node_info& ENG_PVP1=sparser->get_node_info($1);
const node_info& ENG_PVP2=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlist->ENG_PVP ENG_PVP");
$$=sparser->combine_nodes("ENG_PVPlist",ENG_PVP1,ENG_PVP2);

}
|ENG_PVPlist ENG_PVP
{
const node_info& ENG_PVPlist=sparser->get_node_info($1);
const node_info& ENG_PVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlist->ENG_PVPlist ENG_PVP");
$$=sparser->combine_nodes("ENG_PVPlist",ENG_PVPlist,ENG_PVP);

};
ENG_PVPlisthead:
ENG_PVPlist 
{
const node_info& ENG_PVPlist=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlisthead->ENG_PVPlist");
$$=sparser->set_node_info("ENG_PVPlisthead",ENG_PVPlist);

};
ENG_Prep:
t_ENG_PREP_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PREP_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Prep",word);

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

}
|ENG_RPro ENG_IVPConj
{
const node_info& ENG_RPro=sparser->get_node_info($1);
const node_info& ENG_IVPConj=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVPConj");
$$=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVPConj);

}
|ENG_RPro ENG_IVPlist
{
const node_info& ENG_RPro=sparser->get_node_info($1);
const node_info& ENG_IVPlist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVPlist");
$$=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVPlist);

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
|ENG_V_Ger 
{
const node_info& ENG_V_Ger=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_V_Ger");
$$=sparser->set_node_info("ENG_TP",ENG_V_Ger);

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
ENG_V_Aux 
{
const node_info& ENG_V_Aux=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Aux");
$$=sparser->set_node_info("ENG_V",ENG_V_Aux);

}
|ENG_V_Stem 
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");
$$=sparser->set_node_info("ENG_V",ENG_V_Stem);

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
|ENG_Vbar1 ENG_AdvP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_AdvP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);

}
|ENG_Vbar1 ENG_PVP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_PVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVP");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVP);

}
|ENG_Vbar1 ENG_PVPConj
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_PVPConj=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVPConj");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVPConj);

}
|ENG_Vbar1 ENG_PVPlist
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_PVPlist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVPlist");
$$=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVPlist);

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

};
ENG_V_Aux:
ENG_V_Stem ENG_V_lfea_aux
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_aux=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Aux->ENG_V_Stem ENG_V_lfea_aux");
$$=sparser->combine_nodes("ENG_V_Aux",ENG_V_Stem,ENG_V_lfea_aux);

};
ENG_V_Ger:
ENG_V_Stem ENG_V_lfea_ger
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_ger=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Ger->ENG_V_Stem ENG_V_lfea_ger");
$$=sparser->combine_nodes("ENG_V_Ger",ENG_V_Stem,ENG_V_lfea_ger);

};
ENG_V_Stem:
t_ENG_V_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_V_Stem",word);

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
}
|ENG_V 
{
const node_info& ENG_V=sparser->get_node_info($1);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_V");
$$=sparser->set_node_info("ENG_Vbar4",ENG_V);
};
ENG_Vhead:
ENG_IVP 
{
const node_info& ENG_IVP=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vhead->ENG_IVP");
$$=sparser->set_node_info("ENG_Vhead",ENG_IVP);

};
ENG_Vlisthead:
ENG_IVPlist 
{
const node_info& ENG_IVPlist=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vlisthead->ENG_IVPlist");
$$=sparser->set_node_info("ENG_Vlisthead",ENG_IVPlist);

};
ENG_lfea_DefDet:
t_ENG_DET_Def 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Def);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_lfea_DefDet",word);

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
HUN_1Con:
HUN_Con 
{
const node_info& HUN_Con=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_1Con->HUN_Con");
$$=sparser->set_node_info("HUN_1Con",HUN_Con);

};
HUN_A0NEG:
HUN_Adj 
{
const node_info& HUN_Adj=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_A0NEG->HUN_Adj");
$$=sparser->set_node_info("HUN_A0NEG",HUN_Adj);

};
HUN_ANEG:
HUN_Neg HUN_Adj
{
const node_info& HUN_Neg=sparser->get_node_info($1);
const node_info& HUN_Adj=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ANEG->HUN_Neg HUN_Adj");
$$=sparser->combine_nodes("HUN_ANEG",HUN_Neg,HUN_Adj);

};
HUN_ANP:
HUN_N_Sg HUN_N_Sg
{
const node_info& HUN_N_Sg1=sparser->get_node_info($1);
const node_info& HUN_N_Sg2=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ANP->HUN_N_Sg HUN_N_Sg");
$$=sparser->combine_nodes("HUN_ANP",HUN_N_Sg1,HUN_N_Sg2);

};
HUN_AN_Acc:
HUN_N_Acc END
{
const node_info& HUN_N_Acc=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AN_Acc->HUN_N_Acc END");
$$=sparser->set_node_info("HUN_AN_Acc",HUN_N_Acc);
};
HUN_AP:
HUN_Abar3 HUN_N_Acc
{
const node_info& HUN_Abar3=sparser->get_node_info($1);
const node_info& HUN_N_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Abar3 HUN_N_Acc");
$$=sparser->combine_nodes("HUN_AP",HUN_Abar3,HUN_N_Acc);

}
|HUN_Abar4 HUN_ConjA_End
{
const node_info& HUN_Abar4=sparser->get_node_info($1);
const node_info& HUN_ConjA_End=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Abar4 HUN_ConjA_End");
$$=sparser->combine_nodes("HUN_AP",HUN_Abar4,HUN_ConjA_End);

}
|HUN_Alist HUN_N_Acc
{
const node_info& HUN_Alist=sparser->get_node_info($1);
const node_info& HUN_N_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Alist HUN_N_Acc");
$$=sparser->combine_nodes("HUN_AP",HUN_Alist,HUN_N_Acc);

};
HUN_Abar1:
HUN_N_Acc HUN_A0NEG
{
const node_info& HUN_N_Acc=sparser->get_node_info($1);
const node_info& HUN_A0NEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Acc HUN_A0NEG");
$$=sparser->combine_nodes("HUN_Abar1",HUN_N_Acc,HUN_A0NEG);

}
|HUN_N_Ins HUN_A0NEG
{
const node_info& HUN_N_Ins=sparser->get_node_info($1);
const node_info& HUN_A0NEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Ins HUN_A0NEG");
$$=sparser->combine_nodes("HUN_Abar1",HUN_N_Ins,HUN_A0NEG);

}
|HUN_N_Sub HUN_A0NEG
{
const node_info& HUN_N_Sub=sparser->get_node_info($1);
const node_info& HUN_A0NEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Sub HUN_A0NEG");
$$=sparser->combine_nodes("HUN_Abar1",HUN_N_Sub,HUN_A0NEG);

};
HUN_Abar1N:
HUN_N_Acc HUN_ANEG
{
const node_info& HUN_N_Acc=sparser->get_node_info($1);
const node_info& HUN_ANEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Acc HUN_ANEG");
$$=sparser->combine_nodes("HUN_Abar1N",HUN_N_Acc,HUN_ANEG);

}
|HUN_N_Ins HUN_ANEG
{
const node_info& HUN_N_Ins=sparser->get_node_info($1);
const node_info& HUN_ANEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Ins HUN_ANEG");
$$=sparser->combine_nodes("HUN_Abar1N",HUN_N_Ins,HUN_ANEG);

}
|HUN_N_Sub HUN_ANEG
{
const node_info& HUN_N_Sub=sparser->get_node_info($1);
const node_info& HUN_ANEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Sub HUN_ANEG");
$$=sparser->combine_nodes("HUN_Abar1N",HUN_N_Sub,HUN_ANEG);

};
HUN_Abar2:
HUN_Abar1 
{
const node_info& HUN_Abar1=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2->HUN_Abar1");
$$=sparser->set_node_info("HUN_Abar2",HUN_Abar1);

};
HUN_Abar2N:
HUN_Abar1N 
{
const node_info& HUN_Abar1N=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2N->HUN_Abar1N");
$$=sparser->set_node_info("HUN_Abar2N",HUN_Abar1N);

}
|HUN_NAbar1 
{
const node_info& HUN_NAbar1=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2N->HUN_NAbar1");
$$=sparser->set_node_info("HUN_Abar2N",HUN_NAbar1);

};
HUN_Abar3:
HUN_Abar2 
{
const node_info& HUN_Abar2=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3->HUN_Abar2");
$$=sparser->set_node_info("HUN_Abar3",HUN_Abar2);

}
|HUN_Abar2N 
{
const node_info& HUN_Abar2N=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3->HUN_Abar2N");
$$=sparser->set_node_info("HUN_Abar3",HUN_Abar2N);

};
HUN_Abar3_End:
HUN_Abar3 HUN_AN_Acc
{
const node_info& HUN_Abar3=sparser->get_node_info($1);
const node_info& HUN_AN_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3_End->HUN_Abar3 HUN_AN_Acc");
$$=sparser->combine_nodes("HUN_Abar3_End",HUN_Abar3,HUN_AN_Acc);

};
HUN_Abar4:
HUN_A0NEG 
{
const node_info& HUN_A0NEG=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_A0NEG");
$$=sparser->set_node_info("HUN_Abar4",HUN_A0NEG);

}
|HUN_ANEG 
{
const node_info& HUN_ANEG=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_ANEG");
$$=sparser->set_node_info("HUN_Abar4",HUN_ANEG);

}
|HUN_Abar3 
{
const node_info& HUN_Abar3=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar3");
$$=sparser->set_node_info("HUN_Abar4",HUN_Abar3);

}
|HUN_Abar4 HUN_ConjA
{
const node_info& HUN_Abar4=sparser->get_node_info($1);
const node_info& HUN_ConjA=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar4 HUN_ConjA");
$$=sparser->combine_nodes("HUN_Abar4",HUN_Abar4,HUN_ConjA);

}
|HUN_Abar4 HUN_ConjAlist
{
const node_info& HUN_Abar4=sparser->get_node_info($1);
const node_info& HUN_ConjAlist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar4 HUN_ConjAlist");
$$=sparser->combine_nodes("HUN_Abar4",HUN_Abar4,HUN_ConjAlist);

}
|HUN_Alist 
{
const node_info& HUN_Alist=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Alist");
$$=sparser->set_node_info("HUN_Abar4",HUN_Alist);

};
HUN_Adj:
HUN_Adj_Stem 
{
const node_info& HUN_Adj_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Adj->HUN_Adj_Stem");
$$=sparser->set_node_info("HUN_Adj",HUN_Adj_Stem);

};
HUN_Adj_Stem:
t_HUN_Adj_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Adj_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Adj_Stem",word);

};
HUN_Alist:
HUN_Abar3 HUN_Abar3
{
const node_info& HUN_Abar31=sparser->get_node_info($1);
const node_info& HUN_Abar32=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist->HUN_Abar3 HUN_Abar3");
$$=sparser->combine_nodes("HUN_Alist",HUN_Abar31,HUN_Abar32);

}
|HUN_Alist HUN_Abar3
{
const node_info& HUN_Alist=sparser->get_node_info($1);
const node_info& HUN_Abar3=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist->HUN_Alist HUN_Abar3");
$$=sparser->combine_nodes("HUN_Alist",HUN_Alist,HUN_Abar3);

};
HUN_Alist_End:
HUN_Alist HUN_AN_Acc
{
const node_info& HUN_Alist=sparser->get_node_info($1);
const node_info& HUN_AN_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist_End->HUN_Alist HUN_AN_Acc");
$$=sparser->combine_nodes("HUN_Alist_End",HUN_Alist,HUN_AN_Acc);

};
HUN_Con:
HUN_lfea_swConsonant HUN_Con
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info($1);
const node_info& HUN_Con=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Con->HUN_lfea_swConsonant HUN_Con");
$$=sparser->combine_nodes("HUN_Con",HUN_lfea_swConsonant,HUN_Con);

}
|HUN_lfea_swVowel HUN_Con
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info($1);
const node_info& HUN_Con=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Con->HUN_lfea_swVowel HUN_Con");
$$=sparser->combine_nodes("HUN_Con",HUN_lfea_swVowel,HUN_Con);

}
|t_HUN_CON_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Con",word);

};
HUN_Con_lfea_Acc:
t_HUN_CON_Acc 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Con_lfea_Acc",word);

};
HUN_Con_lfea_Dat:
t_HUN_CON_Dat 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Con_lfea_Dat",word);

};
HUN_Con_lfea_Ins:
t_HUN_CON_Ins 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Ins);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Con_lfea_Ins",word);

};
HUN_Con_lfea_Sub:
t_HUN_CON_Sub 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Sub);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Con_lfea_Sub",word);

};
HUN_Conj:
HUN_Conj_Stem 
{
const node_info& HUN_Conj_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Conj->HUN_Conj_Stem");
$$=sparser->set_node_info("HUN_Conj",HUN_Conj_Stem);

};
HUN_ConjA:
HUN_Conj HUN_A0NEG %prec t_HUN_Conj_Stem
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_A0NEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_A0NEG");
$$=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_A0NEG);

}
|HUN_Conj HUN_ANEG %prec t_HUN_Conj_Stem
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_ANEG=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_ANEG");
$$=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_ANEG);

}
|HUN_Conj HUN_Abar3 %prec t_HUN_Conj_Stem
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_Abar3=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_Abar3");
$$=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_Abar3);

}
|HUN_Conj HUN_Alist %prec t_HUN_Conj_Stem
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_Alist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_Alist");
$$=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_Alist);

};
HUN_ConjA_End:
HUN_ConjA HUN_AN_Acc
{
const node_info& HUN_ConjA=sparser->get_node_info($1);
const node_info& HUN_AN_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_AN_Acc");
$$=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_AN_Acc);

}
|HUN_ConjA HUN_Abar3_End
{
const node_info& HUN_ConjA=sparser->get_node_info($1);
const node_info& HUN_Abar3_End=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_Abar3_End");
$$=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_Abar3_End);

}
|HUN_ConjA HUN_Alist_End
{
const node_info& HUN_ConjA=sparser->get_node_info($1);
const node_info& HUN_Alist_End=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_Alist_End");
$$=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_Alist_End);

};
HUN_ConjAlist:
HUN_ConjA HUN_Abar3
{
const node_info& HUN_ConjA=sparser->get_node_info($1);
const node_info& HUN_Abar3=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjAlist->HUN_ConjA HUN_Abar3");
$$=sparser->combine_nodes("HUN_ConjAlist",HUN_ConjA,HUN_Abar3);

}
|HUN_ConjA HUN_Alist
{
const node_info& HUN_ConjA=sparser->get_node_info($1);
const node_info& HUN_Alist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjAlist->HUN_ConjA HUN_Alist");
$$=sparser->combine_nodes("HUN_ConjAlist",HUN_ConjA,HUN_Alist);

};
HUN_ConjN:
HUN_N_Sg HUN_ConjNbar1
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_ConjNbar1=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjN->HUN_N_Sg HUN_ConjNbar1");
$$=sparser->combine_nodes("HUN_ConjN",HUN_N_Sg,HUN_ConjNbar1);

};
HUN_ConjNbar1:
HUN_Conj HUN_N_Sg %prec t_HUN_Conj_Stem
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_N_Sg=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjNbar1->HUN_Conj HUN_N_Sg");
$$=sparser->combine_nodes("HUN_ConjNbar1",HUN_Conj,HUN_N_Sg);

};
HUN_ConjV:
HUN_Conj HUN_INVP
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_INVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_INVP");
$$=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_INVP);

}
|HUN_Conj HUN_IVP
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_IVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_IVP");
$$=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_IVP);

}
|HUN_Conj HUN_IVPlist
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_IVPlist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_IVPlist");
$$=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_IVPlist);

};
HUN_Conj_Stem:
t_HUN_Conj_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Conj_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Conj_Stem",word);

};
HUN_DP:
HUN_DPbar HUN_N_Acc
{
const node_info& HUN_DPbar=sparser->get_node_info($1);
const node_info& HUN_N_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Acc");
$$=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Acc);

}
|HUN_DPbar HUN_N_Dat
{
const node_info& HUN_DPbar=sparser->get_node_info($1);
const node_info& HUN_N_Dat=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Dat");
$$=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Dat);

}
|HUN_DPbar HUN_N_Ine
{
const node_info& HUN_DPbar=sparser->get_node_info($1);
const node_info& HUN_N_Ine=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Ine");
$$=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Ine);

};
HUN_DPbar:
HUN_Def_Det_a HUN_lfea_swConsonant
{
const node_info& HUN_Def_Det_a=sparser->get_node_info($1);
const node_info& HUN_lfea_swConsonant=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_a HUN_lfea_swConsonant");
$$=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_a,HUN_lfea_swConsonant);

}
|HUN_Def_Det_az HUN_lfea_swVowel
{
const node_info& HUN_Def_Det_az=sparser->get_node_info($1);
const node_info& HUN_lfea_swVowel=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_az HUN_lfea_swVowel");
$$=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_az,HUN_lfea_swVowel);

};
HUN_Def_Det:
HUN_Det_stem HUN_lfea_DefDet
{
const node_info& HUN_Det_stem=sparser->get_node_info($1);
const node_info& HUN_lfea_DefDet=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det->HUN_Det_stem HUN_lfea_DefDet");
$$=sparser->combine_nodes("HUN_Def_Det",HUN_Det_stem,HUN_lfea_DefDet);

};
HUN_Def_Det_a:
HUN_Def_Det HUN_lfea_fwConsonant
{
const node_info& HUN_Def_Det=sparser->get_node_info($1);
const node_info& HUN_lfea_fwConsonant=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det_a->HUN_Def_Det HUN_lfea_fwConsonant");
$$=sparser->combine_nodes("HUN_Def_Det_a",HUN_Def_Det,HUN_lfea_fwConsonant);

};
HUN_Def_Det_az:
HUN_Def_Det HUN_lfea_fwVowel
{
const node_info& HUN_Def_Det=sparser->get_node_info($1);
const node_info& HUN_lfea_fwVowel=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det_az->HUN_Def_Det HUN_lfea_fwVowel");
$$=sparser->combine_nodes("HUN_Def_Det_az",HUN_Def_Det,HUN_lfea_fwVowel);

};
HUN_Det_stem:
t_HUN_Det_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Det_stem",word);

};
HUN_Empty:
%empty 
{
lexicon empty;
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Empty->%empty");
$$=sparser->set_node_info("HUN_Empty",empty);
};
HUN_INVP:
HUN_NP HUN_INVPbar2
{
const node_info& HUN_NP=sparser->get_node_info($1);
const node_info& HUN_INVPbar2=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_NP HUN_INVPbar2");
$$=sparser->combine_nodes("HUN_INVP",HUN_NP,HUN_INVPbar2);

}
|HUN_Neg HUN_INVPbar
{
const node_info& HUN_Neg=sparser->get_node_info($1);
const node_info& HUN_INVPbar=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_Neg HUN_INVPbar");
$$=sparser->combine_nodes("HUN_INVP",HUN_Neg,HUN_INVPbar);

}
|HUN_Neg HUN_IVPbar
{
const node_info& HUN_Neg=sparser->get_node_info($1);
const node_info& HUN_IVPbar=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_Neg HUN_IVPbar");
$$=sparser->combine_nodes("HUN_INVP",HUN_Neg,HUN_IVPbar);

};
HUN_INVPbar:
HUN_V HUN_N_Ins
{
const node_info& HUN_V=sparser->get_node_info($1);
const node_info& HUN_N_Ins=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar->HUN_V HUN_N_Ins");
$$=sparser->combine_nodes("HUN_INVPbar",HUN_V,HUN_N_Ins);
}
|HUN_V HUN_N_Sub
{
const node_info& HUN_V=sparser->get_node_info($1);
const node_info& HUN_N_Sub=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar->HUN_V HUN_N_Sub");
$$=sparser->combine_nodes("HUN_INVPbar",HUN_V,HUN_N_Sub);
};
HUN_INVPbar2:
HUN_Neg HUN_V
{
const node_info& HUN_Neg=sparser->get_node_info($1);
const node_info& HUN_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar2->HUN_Neg HUN_V");
$$=sparser->combine_nodes("HUN_INVPbar2",HUN_Neg,HUN_V);
};
HUN_IVP:
HUN_IVPbar 
{
const node_info& HUN_IVPbar=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVP->HUN_IVPbar");
$$=sparser->set_node_info("HUN_IVP",HUN_IVPbar);

};
HUN_IVPConj:
HUN_IVPConj HUN_ConjV
{
const node_info& HUN_IVPConj=sparser->get_node_info($1);
const node_info& HUN_ConjV=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_IVPConj HUN_ConjV");
$$=sparser->combine_nodes("HUN_IVPConj",HUN_IVPConj,HUN_ConjV);

}
|HUN_Vhead HUN_ConjV
{
const node_info& HUN_Vhead=sparser->get_node_info($1);
const node_info& HUN_ConjV=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_Vhead HUN_ConjV");
$$=sparser->combine_nodes("HUN_IVPConj",HUN_Vhead,HUN_ConjV);

}
|HUN_Vlisthead HUN_ConjV
{
const node_info& HUN_Vlisthead=sparser->get_node_info($1);
const node_info& HUN_ConjV=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_Vlisthead HUN_ConjV");
$$=sparser->combine_nodes("HUN_IVPConj",HUN_Vlisthead,HUN_ConjV);

};
HUN_IVPbar:
HUN_N_Acc HUN_V
{
const node_info& HUN_N_Acc=sparser->get_node_info($1);
const node_info& HUN_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Acc HUN_V");
$$=sparser->combine_nodes("HUN_IVPbar",HUN_V,HUN_N_Acc);
}
|HUN_N_Ins HUN_V
{
const node_info& HUN_N_Ins=sparser->get_node_info($1);
const node_info& HUN_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Ins HUN_V");
$$=sparser->combine_nodes("HUN_IVPbar",HUN_N_Ins,HUN_V);
}
|HUN_N_Sub HUN_V
{
const node_info& HUN_N_Sub=sparser->get_node_info($1);
const node_info& HUN_V=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Sub HUN_V");
$$=sparser->combine_nodes("HUN_IVPbar",HUN_N_Sub,HUN_V);
}
|HUN_V HUN_N_Acc
{
const node_info& HUN_V=sparser->get_node_info($1);
const node_info& HUN_N_Acc=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_V HUN_N_Acc");
$$=sparser->combine_nodes("HUN_IVPbar",HUN_V,HUN_N_Acc);
};
HUN_IVPlist:
HUN_INVP HUN_INVP
{
const node_info& HUN_INVP1=sparser->get_node_info($1);
const node_info& HUN_INVP2=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_INVP HUN_INVP");
$$=sparser->combine_nodes("HUN_IVPlist",HUN_INVP1,HUN_INVP2);

}
|HUN_INVP HUN_IVP
{
const node_info& HUN_INVP=sparser->get_node_info($1);
const node_info& HUN_IVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_INVP HUN_IVP");
$$=sparser->combine_nodes("HUN_IVPlist",HUN_INVP,HUN_IVP);

}
|HUN_IVP HUN_INVP
{
const node_info& HUN_IVP=sparser->get_node_info($1);
const node_info& HUN_INVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVP HUN_INVP");
$$=sparser->combine_nodes("HUN_IVPlist",HUN_IVP,HUN_INVP);

}
|HUN_IVP HUN_IVP
{
const node_info& HUN_IVP1=sparser->get_node_info($1);
const node_info& HUN_IVP2=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVP HUN_IVP");
$$=sparser->combine_nodes("HUN_IVPlist",HUN_IVP1,HUN_IVP2);

}
|HUN_IVPlist HUN_INVP
{
const node_info& HUN_IVPlist=sparser->get_node_info($1);
const node_info& HUN_INVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVPlist HUN_INVP");
$$=sparser->combine_nodes("HUN_IVPlist",HUN_IVPlist,HUN_INVP);

}
|HUN_IVPlist HUN_IVP
{
const node_info& HUN_IVPlist=sparser->get_node_info($1);
const node_info& HUN_IVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVPlist HUN_IVP");
$$=sparser->combine_nodes("HUN_IVPlist",HUN_IVPlist,HUN_IVP);

};
HUN_ImpVerb:
HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2
{
const node_info& HUN_Verb_stem=sparser->get_node_info($1);
const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2");
$$=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);
}
|HUN_Verb_stem HUN_Verb_lfea_ConjIndefSg2
{
const node_info& HUN_Verb_stem=sparser->get_node_info($1);
const node_info& HUN_Verb_lfea_ConjIndefSg2=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjIndefSg2");
$$=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjIndefSg2);
}
|HUN_Verb_stem HUN_Verb_lfea_DefSg1
{
const node_info& HUN_Verb_stem=sparser->get_node_info($1);
const node_info& HUN_Verb_lfea_DefSg1=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_DefSg1");
$$=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_DefSg1);
};
HUN_ImpVerbPfx:
HUN_ImpVerb HUN_Vbpfx
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_Vbpfx=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerbPfx->HUN_ImpVerb HUN_Vbpfx");
$$=sparser->combine_nodes("HUN_ImpVerbPfx",HUN_ImpVerb,HUN_Vbpfx);

};
HUN_ImpVerb_N_Acc:
HUN_ImpVerb HUN_N_Acc
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_N_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb_N_Acc->HUN_ImpVerb HUN_N_Acc");
$$=sparser->combine_nodes("HUN_ImpVerb_N_Acc",HUN_ImpVerb,HUN_N_Acc);

};
HUN_ImpVerb_N_Dat:
HUN_ImpVerb HUN_N_Dat
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_N_Dat=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb_N_Dat->HUN_ImpVerb HUN_N_Dat");
$$=sparser->combine_nodes("HUN_ImpVerb_N_Dat",HUN_ImpVerb,HUN_N_Dat);

};
HUN_IndVerb:
HUN_Verb_stem HUN_Verb_lfea_InDefSg3
{
const node_info& HUN_Verb_stem=sparser->get_node_info($1);
const node_info& HUN_Verb_lfea_InDefSg3=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IndVerb->HUN_Verb_stem HUN_Verb_lfea_InDefSg3");
$$=sparser->combine_nodes("HUN_IndVerb",HUN_Verb_stem,HUN_Verb_lfea_InDefSg3);
};
HUN_NAbar1:
HUN_Neg HUN_Abar1
{
const node_info& HUN_Neg=sparser->get_node_info($1);
const node_info& HUN_Abar1=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NAbar1->HUN_Neg HUN_Abar1");
$$=sparser->combine_nodes("HUN_NAbar1",HUN_Neg,HUN_Abar1);

};
HUN_NP:
HUN_N_Acc 
{
const node_info& HUN_N_Acc=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Acc");
$$=sparser->set_node_info("HUN_NP",HUN_N_Acc);

}
|HUN_N_Ins 
{
const node_info& HUN_N_Ins=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Ins");
$$=sparser->set_node_info("HUN_NP",HUN_N_Ins);

}
|HUN_N_Sg 
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Sg");
$$=sparser->set_node_info("HUN_NP",HUN_N_Sg);

}
|HUN_N_Sub 
{
const node_info& HUN_N_Sub=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Sub");
$$=sparser->set_node_info("HUN_NP",HUN_N_Sub);

};
HUN_N_Acc:
HUN_ANP HUN_Noun_lfea_Acc
{
const node_info& HUN_ANP=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_ANP HUN_Noun_lfea_Acc");
$$=sparser->combine_nodes("HUN_N_Acc",HUN_ANP,HUN_Noun_lfea_Acc);

}
|HUN_N_Pl HUN_Noun_lfea_Acc
{
const node_info& HUN_N_Pl=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Pl HUN_Noun_lfea_Acc");
$$=sparser->combine_nodes("HUN_N_Acc",HUN_N_Pl,HUN_Noun_lfea_Acc);

}
|HUN_N_Sg HUN_Con_lfea_Acc
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Con_lfea_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Con_lfea_Acc");
$$=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Con_lfea_Acc);

}
|HUN_N_Sg HUN_Noun_lfea_Acc
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Noun_lfea_Acc");
$$=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Noun_lfea_Acc);

}
|HUN_Num HUN_Num_lfea_Acc
{
const node_info& HUN_Num=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_Num HUN_Num_lfea_Acc");
$$=sparser->combine_nodes("HUN_N_Acc",HUN_Num,HUN_Num_lfea_Acc);

}
|HUN_Nums HUN_Num_lfea_Acc
{
const node_info& HUN_Nums=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_Nums HUN_Num_lfea_Acc");
$$=sparser->combine_nodes("HUN_N_Acc",HUN_Nums,HUN_Num_lfea_Acc);

};
HUN_N_Dat:
HUN_N_Sg HUN_Con_lfea_Dat
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Con_lfea_Dat=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Con_lfea_Dat");
$$=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Con_lfea_Dat);

}
|HUN_N_Sg HUN_Noun_lfea_Dat
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Dat=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Noun_lfea_Dat");
$$=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Noun_lfea_Dat);

}
|HUN_N_Sg HUN_Noun_lfea_Del
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Del=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Noun_lfea_Del");
$$=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Noun_lfea_Del);

}
|HUN_Num HUN_Num_lfea_Dat
{
const node_info& HUN_Num=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Dat=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Num HUN_Num_lfea_Dat");
$$=sparser->combine_nodes("HUN_N_Dat",HUN_Num,HUN_Num_lfea_Dat);

}
|HUN_Num HUN_Num_lfea_Del
{
const node_info& HUN_Num=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Del=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Num HUN_Num_lfea_Del");
$$=sparser->combine_nodes("HUN_N_Dat",HUN_Num,HUN_Num_lfea_Del);

}
|HUN_Nums HUN_Num_lfea_Dat
{
const node_info& HUN_Nums=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Dat=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Nums HUN_Num_lfea_Dat");
$$=sparser->combine_nodes("HUN_N_Dat",HUN_Nums,HUN_Num_lfea_Dat);

};
HUN_N_Ine:
HUN_N_Pl HUN_Noun_lfea_Ine
{
const node_info& HUN_N_Pl=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Ine=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ine->HUN_N_Pl HUN_Noun_lfea_Ine");
$$=sparser->combine_nodes("HUN_N_Ine",HUN_N_Pl,HUN_Noun_lfea_Ine);

}
|HUN_N_Sg HUN_Noun_lfea_Ine
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Ine=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ine->HUN_N_Sg HUN_Noun_lfea_Ine");
$$=sparser->combine_nodes("HUN_N_Ine",HUN_N_Sg,HUN_Noun_lfea_Ine);

};
HUN_N_Ins:
HUN_N_Sg HUN_Con_lfea_Ins
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Con_lfea_Ins=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ins->HUN_N_Sg HUN_Con_lfea_Ins");
$$=sparser->combine_nodes("HUN_N_Ins",HUN_N_Sg,HUN_Con_lfea_Ins);

};
HUN_N_Pl:
HUN_Noun_Stem HUN_Noun_lfea_Plur
{
const node_info& HUN_Noun_Stem=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Plur=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Pl->HUN_Noun_Stem HUN_Noun_lfea_Plur");
$$=sparser->combine_nodes("HUN_N_Pl",HUN_Noun_Stem,HUN_Noun_lfea_Plur);

};
HUN_N_Sg:
HUN_1Con 
{
const node_info& HUN_1Con=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_1Con");
$$=sparser->set_node_info("HUN_N_Sg",HUN_1Con);

}
|HUN_Noun_Pref HUN_Noun_Stem
{
const node_info& HUN_Noun_Pref=sparser->get_node_info($1);
const node_info& HUN_Noun_Stem=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_Noun_Pref HUN_Noun_Stem");
$$=sparser->combine_nodes("HUN_N_Sg",HUN_Noun_Pref,HUN_Noun_Stem);

}
|HUN_Noun_Stem 
{
const node_info& HUN_Noun_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_Noun_Stem");
$$=sparser->set_node_info("HUN_N_Sg",HUN_Noun_Stem);

}
|HUN_nCon 
{
const node_info& HUN_nCon=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_nCon");
$$=sparser->set_node_info("HUN_N_Sg",HUN_nCon);

};
HUN_N_Sub:
HUN_N_Sg HUN_Con_lfea_Sub
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Con_lfea_Sub=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sub->HUN_N_Sg HUN_Con_lfea_Sub");
$$=sparser->combine_nodes("HUN_N_Sub",HUN_N_Sg,HUN_Con_lfea_Sub);

}
|HUN_N_Sg HUN_Noun_lfea_Sub
{
const node_info& HUN_N_Sg=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Sub=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sub->HUN_N_Sg HUN_Noun_lfea_Sub");
$$=sparser->combine_nodes("HUN_N_Sub",HUN_N_Sg,HUN_Noun_lfea_Sub);

};
HUN_Neg:
HUN_Neg_Stem 
{
const node_info& HUN_Neg_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Neg->HUN_Neg_Stem");
$$=sparser->set_node_info("HUN_Neg",HUN_Neg_Stem);

};
HUN_Neg_Stem:
t_HUN_Neg_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Neg_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Neg_Stem",word);

};
HUN_Noun_Pref:
t_HUN_Noun_Pref 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Pref);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_Pref",word);

};
HUN_Noun_Stem:
HUN_lfea_swConsonant HUN_Noun_Stem
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info($1);
const node_info& HUN_Noun_Stem=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Noun_Stem->HUN_lfea_swConsonant HUN_Noun_Stem");
$$=sparser->combine_nodes("HUN_Noun_Stem",HUN_lfea_swConsonant,HUN_Noun_Stem);

}
|HUN_lfea_swVowel HUN_Noun_Stem
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info($1);
const node_info& HUN_Noun_Stem=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Noun_Stem->HUN_lfea_swVowel HUN_Noun_Stem");
$$=sparser->combine_nodes("HUN_Noun_Stem",HUN_lfea_swVowel,HUN_Noun_Stem);

}
|t_HUN_Noun_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_Stem",word);

};
HUN_Noun_lfea_Acc:
t_HUN_Noun_Acc 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_lfea_Acc",word);

};
HUN_Noun_lfea_Dat:
t_HUN_Noun_Dat 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_lfea_Dat",word);

};
HUN_Noun_lfea_Del:
t_HUN_Noun_Del 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Del);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_lfea_Del",word);

};
HUN_Noun_lfea_Ine:
t_HUN_Noun_Ine 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Ine);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_lfea_Ine",word);

};
HUN_Noun_lfea_Plur:
t_HUN_Noun_Plur 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Plur);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_lfea_Plur",word);

};
HUN_Noun_lfea_Relative:
t_HUN_Noun_Relative 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_lfea_Relative",word);

};
HUN_Noun_lfea_Sub:
t_HUN_Noun_Sub 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Sub);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Noun_lfea_Sub",word);

};
HUN_Num:
HUN_Num HUN_Num_lfea_Ik
{
const node_info& HUN_Num=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Ik=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Ik");
$$=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Ik);

}
|HUN_Num HUN_Num_lfea_Par
{
const node_info& HUN_Num=sparser->get_node_info($1);
const node_info& HUN_Num_lfea_Par=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Par");
$$=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Par);

}
|HUN_Num_Pref HUN_Num
{
const node_info& HUN_Num_Pref=sparser->get_node_info($1);
const node_info& HUN_Num=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num_Pref HUN_Num");
$$=sparser->combine_nodes("HUN_Num",HUN_Num_Pref,HUN_Num);

}
|HUN_Num_Stem 
{
const node_info& HUN_Num_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num_Stem");
$$=sparser->set_node_info("HUN_Num",HUN_Num_Stem);

}
|HUN_lfea_swConsonant HUN_Num
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info($1);
const node_info& HUN_Num=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_lfea_swConsonant HUN_Num");
$$=sparser->combine_nodes("HUN_Num",HUN_lfea_swConsonant,HUN_Num);

}
|HUN_lfea_swVowel HUN_Num
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info($1);
const node_info& HUN_Num=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_lfea_swVowel HUN_Num");
$$=sparser->combine_nodes("HUN_Num",HUN_lfea_swVowel,HUN_Num);

};
HUN_Num_Pref:
t_HUN_Num_Npref1 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref1n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref1nn 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1nn);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref1nnn 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1nnn);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref2 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref2n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref3 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref3n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref4 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref4);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref4n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref5 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref5);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref5n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref6 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref6);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref6n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref7 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref7);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref7n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref8 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref8);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref8n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref9 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref9);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

}
|t_HUN_Num_Npref9n 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Pref",word);

};
HUN_Num_Stem:
t_HUN_Num_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_Stem",word);

};
HUN_Num_lfea_Acc:
t_HUN_Num_Acc 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_lfea_Acc",word);

};
HUN_Num_lfea_Dat:
t_HUN_Num_Dat 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_lfea_Dat",word);

};
HUN_Num_lfea_Del:
t_HUN_Num_Del 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Del);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_lfea_Del",word);

};
HUN_Num_lfea_Ik:
t_HUN_Num_Ik 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Ik);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_lfea_Ik",word);

};
HUN_Num_lfea_Par:
t_HUN_Num_Par 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Par);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Num_lfea_Par",word);

};
HUN_Nums:
HUN_Num HUN_Num
{
const node_info& HUN_Num1=sparser->get_node_info($1);
const node_info& HUN_Num2=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Nums->HUN_Num HUN_Num");
$$=sparser->combine_nodes("HUN_Nums",HUN_Num1,HUN_Num2);

}
|HUN_Nums HUN_Num
{
const node_info& HUN_Nums=sparser->get_node_info($1);
const node_info& HUN_Num=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Nums->HUN_Nums HUN_Num");
$$=sparser->combine_nodes("HUN_Nums",HUN_Nums,HUN_Num);

};
HUN_Pron_Int:
HUN_Pron_Int HUN_Pron_lfea_Nom
{
const node_info& HUN_Pron_Int=sparser->get_node_info($1);
const node_info& HUN_Pron_lfea_Nom=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Pron_Int->HUN_Pron_Int HUN_Pron_lfea_Nom");
$$=sparser->combine_nodes("HUN_Pron_Int",HUN_Pron_Int,HUN_Pron_lfea_Nom);

}
|HUN_Pron_Stem HUN_Pron_lfea_Int
{
const node_info& HUN_Pron_Stem=sparser->get_node_info($1);
const node_info& HUN_Pron_lfea_Int=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Pron_Int->HUN_Pron_Stem HUN_Pron_lfea_Int");
$$=sparser->combine_nodes("HUN_Pron_Int",HUN_Pron_Stem,HUN_Pron_lfea_Int);

};
HUN_Pron_Stem:
t_HUN_Pronoun_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Pron_Stem",word);

};
HUN_Pron_lfea_Int:
t_HUN_Pronoun_Int 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Int);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Pron_lfea_Int",word);

};
HUN_Pron_lfea_Nom:
t_HUN_Pronoun_Nom 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Nom);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Pron_lfea_Nom",word);

};
HUN_Punct:
HUN_Punct_Stem HUN_Punct_ExclamationMark
{
const node_info& HUN_Punct_Stem=sparser->get_node_info($1);
const node_info& HUN_Punct_ExclamationMark=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_ExclamationMark");
$$=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_ExclamationMark);

}
|HUN_Punct_Stem HUN_Punct_FullStop
{
const node_info& HUN_Punct_Stem=sparser->get_node_info($1);
const node_info& HUN_Punct_FullStop=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_FullStop");
$$=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_FullStop);

}
|HUN_Punct_Stem HUN_Punct_QuestionMark
{
const node_info& HUN_Punct_Stem=sparser->get_node_info($1);
const node_info& HUN_Punct_QuestionMark=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_QuestionMark");
$$=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_QuestionMark);

};
HUN_Punct_ExclamationMark:
t_HUN_Punct_ExclamationMark 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_ExclamationMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Punct_ExclamationMark",word);

};
HUN_Punct_FullStop:
t_HUN_Punct_FullStop 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_FullStop);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Punct_FullStop",word);

};
HUN_Punct_QuestionMark:
t_HUN_Punct_QuestionMark 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_QuestionMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Punct_QuestionMark",word);

};
HUN_Punct_Stem:
t_HUN_Punct_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Punct_Stem",word);

};
HUN_RC:
HUN_Conj HUN_N_Sg
{
const node_info& HUN_Conj=sparser->get_node_info($1);
const node_info& HUN_N_Sg=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_Conj HUN_N_Sg");
$$=sparser->combine_nodes("HUN_RC",HUN_Conj,HUN_N_Sg);

}
|HUN_RPro HUN_INVP
{
const node_info& HUN_RPro=sparser->get_node_info($1);
const node_info& HUN_INVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_INVP");
$$=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_INVP);

}
|HUN_RPro HUN_IVP
{
const node_info& HUN_RPro=sparser->get_node_info($1);
const node_info& HUN_IVP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVP");
$$=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVP);

}
|HUN_RPro HUN_IVPConj
{
const node_info& HUN_RPro=sparser->get_node_info($1);
const node_info& HUN_IVPConj=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVPConj");
$$=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVPConj);

}
|HUN_RPro HUN_IVPlist
{
const node_info& HUN_RPro=sparser->get_node_info($1);
const node_info& HUN_IVPlist=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVPlist");
$$=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVPlist);

};
HUN_RPro:
HUN_Noun_Stem HUN_Noun_lfea_Relative
{
const node_info& HUN_Noun_Stem=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Relative=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RPro->HUN_Noun_Stem HUN_Noun_lfea_Relative");
$$=sparser->combine_nodes("HUN_RPro",HUN_Noun_Stem,HUN_Noun_lfea_Relative);

}
|HUN_RPro HUN_Noun_lfea_Plur
{
const node_info& HUN_RPro=sparser->get_node_info($1);
const node_info& HUN_Noun_lfea_Plur=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RPro->HUN_RPro HUN_Noun_lfea_Plur");
$$=sparser->combine_nodes("HUN_RPro",HUN_RPro,HUN_Noun_lfea_Plur);

};
HUN_V:
HUN_Verb_stem HUN_Verb_lfea_IndefPl3
{
const node_info& HUN_Verb_stem=sparser->get_node_info($1);
const node_info& HUN_Verb_lfea_IndefPl3=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_V->HUN_Verb_stem HUN_Verb_lfea_IndefPl3");
$$=sparser->combine_nodes("HUN_V",HUN_Verb_stem,HUN_Verb_lfea_IndefPl3);

};
HUN_VP:
HUN_ImpVerb HUN_AP
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_AP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_AP");
$$=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_AP);

}
|HUN_ImpVerb HUN_DP
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_DP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_DP");
$$=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_DP);

}
|HUN_ImpVerb HUN_Empty
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_Empty=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_Empty");
$$=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_Empty);

}
|HUN_ImpVerbPfx HUN_DP
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info($1);
const node_info& HUN_DP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_DP");
$$=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_DP);

}
|HUN_ImpVerbPfx HUN_NP
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info($1);
const node_info& HUN_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_NP");
$$=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_NP);

}
|HUN_IndVerb HUN_ConjN
{
const node_info& HUN_IndVerb=sparser->get_node_info($1);
const node_info& HUN_ConjN=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_ConjN,"Conj","qword",false,true);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_IndVerb HUN_ConjN");
$$=sparser->combine_nodes("HUN_VP",HUN_IndVerb,HUN_ConjN);
}
|HUN_IndVerb HUN_N_Sg
{
const node_info& HUN_IndVerb=sparser->get_node_info($1);
const node_info& HUN_N_Sg=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_IndVerb HUN_N_Sg");
$$=sparser->combine_nodes("HUN_VP",HUN_IndVerb,HUN_N_Sg);

}
|HUN_Neg HUN_ImpVerb
{
const node_info& HUN_Neg=sparser->get_node_info($1);
const node_info& HUN_ImpVerb=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Neg HUN_ImpVerb");
$$=sparser->combine_nodes("HUN_VP",HUN_Neg,HUN_ImpVerb);

}
|HUN_Pron_Int HUN_IndVerb
{
const node_info& HUN_Pron_Int=sparser->get_node_info($1);
const node_info& HUN_IndVerb=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_Pron_Int,"Pronoun",std::string("qword"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Pron_Int HUN_IndVerb");
$$=sparser->combine_nodes("HUN_VP",HUN_Pron_Int,HUN_IndVerb);
}
|HUN_Vbar1 HUN_NP
{
const node_info& HUN_Vbar1=sparser->get_node_info($1);
const node_info& HUN_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar1 HUN_NP");
$$=sparser->combine_nodes("HUN_VP",HUN_Vbar1,HUN_NP);

}
|HUN_Vbar2 HUN_N_Ins
{
const node_info& HUN_Vbar2=sparser->get_node_info($1);
const node_info& HUN_N_Ins=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar2 HUN_N_Ins");
$$=sparser->combine_nodes("HUN_VP",HUN_Vbar2,HUN_N_Ins);

}
|HUN_Vbar2 HUN_RC
{
const node_info& HUN_Vbar2=sparser->get_node_info($1);
const node_info& HUN_RC=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar2 HUN_RC");
$$=sparser->combine_nodes("HUN_VP",HUN_Vbar2,HUN_RC);

}
|HUN_Vbar3 HUN_RC
{
const node_info& HUN_Vbar3=sparser->get_node_info($1);
const node_info& HUN_RC=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar3 HUN_RC");
$$=sparser->combine_nodes("HUN_VP",HUN_Vbar3,HUN_RC);

};
HUN_Vbar1:
HUN_ImpVerb HUN_DP
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_DP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar1->HUN_ImpVerb HUN_DP");
$$=sparser->combine_nodes("HUN_Vbar1",HUN_ImpVerb,HUN_DP);

};
HUN_Vbar2:
HUN_ImpVerb HUN_N_Acc
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_N_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar2->HUN_ImpVerb HUN_N_Acc");
$$=sparser->combine_nodes("HUN_Vbar2",HUN_ImpVerb,HUN_N_Acc);

}
|HUN_ImpVerb HUN_N_Dat
{
const node_info& HUN_ImpVerb=sparser->get_node_info($1);
const node_info& HUN_N_Dat=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar2->HUN_ImpVerb HUN_N_Dat");
$$=sparser->combine_nodes("HUN_Vbar2",HUN_ImpVerb,HUN_N_Dat);

};
HUN_Vbar3:
HUN_ImpVerb_N_Acc HUN_N_Dat
{
const node_info& HUN_ImpVerb_N_Acc=sparser->get_node_info($1);
const node_info& HUN_N_Dat=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar3->HUN_ImpVerb_N_Acc HUN_N_Dat");
$$=sparser->combine_nodes("HUN_Vbar3",HUN_ImpVerb_N_Acc,HUN_N_Dat);

}
|HUN_ImpVerb_N_Dat HUN_N_Acc
{
const node_info& HUN_ImpVerb_N_Dat=sparser->get_node_info($1);
const node_info& HUN_N_Acc=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar3->HUN_ImpVerb_N_Dat HUN_N_Acc");
$$=sparser->combine_nodes("HUN_Vbar3",HUN_ImpVerb_N_Dat,HUN_N_Acc);

};
HUN_Vbpfx:
t_HUN_Vbpfx_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Vbpfx_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Vbpfx",word);

};
HUN_Verb_lfea_ConjDefSg2:
t_HUN_Verb_ConjDefSg2 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_ConjDefSg2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Verb_lfea_ConjDefSg2",word);

};
HUN_Verb_lfea_ConjIndefSg2:
t_HUN_Verb_ConjIndefSg2 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_ConjIndefSg2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Verb_lfea_ConjIndefSg2",word);

};
HUN_Verb_lfea_DefSg1:
t_HUN_Verb_DefSg1 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_DefSg1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Verb_lfea_DefSg1",word);

};
HUN_Verb_lfea_InDefSg3:
t_HUN_Verb_IndefSg3 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_IndefSg3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Verb_lfea_InDefSg3",word);

};
HUN_Verb_lfea_IndefPl3:
t_HUN_Verb_IndefPl3 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_IndefPl3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Verb_lfea_IndefPl3",word);

};
HUN_Verb_stem:
t_HUN_Verb_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_Verb_stem",word);

};
HUN_Vhead:
HUN_INVP 
{
const node_info& HUN_INVP=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vhead->HUN_INVP");
$$=sparser->set_node_info("HUN_Vhead",HUN_INVP);

}
|HUN_IVP 
{
const node_info& HUN_IVP=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vhead->HUN_IVP");
$$=sparser->set_node_info("HUN_Vhead",HUN_IVP);

};
HUN_Vlisthead:
HUN_IVPlist 
{
const node_info& HUN_IVPlist=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vlisthead->HUN_IVPlist");
$$=sparser->set_node_info("HUN_Vlisthead",HUN_IVPlist);

};
HUN_lfea_DefDet:
t_HUN_Det_Def 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_Def);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_DefDet",word);

};
HUN_lfea_fwConsonant:
t_HUN_Det_fwConsonant 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_fwConsonant",word);

};
HUN_lfea_fwVowel:
t_HUN_Det_fwVowel 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_fwVowel",word);

};
HUN_lfea_swConsonant:
t_HUN_CON_swConsonant 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
|t_HUN_Noun_swConsonant 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
|t_HUN_Num_swConsonant 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_swConsonant",word);

};
HUN_lfea_swVowel:
t_HUN_CON_swVowel 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_swVowel",word);

}
|t_HUN_Noun_swVowel 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_swVowel",word);

}
|t_HUN_Num_swVowel 
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("HUN_lfea_swVowel",word);

};
HUN_nCon:
HUN_1Con HUN_Con
{
const node_info& HUN_1Con=sparser->get_node_info($1);
const node_info& HUN_Con=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_nCon->HUN_1Con HUN_Con");
$$=sparser->combine_nodes("HUN_nCon",HUN_1Con,HUN_Con);

}
|HUN_nCon HUN_Con
{
const node_info& HUN_nCon=sparser->get_node_info($1);
const node_info& HUN_Con=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_nCon->HUN_nCon HUN_Con");
$$=sparser->combine_nodes("HUN_nCon",HUN_nCon,HUN_Con);

};
JSON_Array:
JSON_Open_Array JSON_Closing_Value_Element
{
const node_info& JSON_Open_Array=sparser->get_node_info($1);
const node_info& JSON_Closing_Value_Element=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Array->JSON_Open_Array JSON_Closing_Value_Element");
$$=sparser->combine_nodes("JSON_Array",JSON_Open_Array,JSON_Closing_Value_Element);

};
JSON_CON:
t_JSON_CON_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_CON",word);

};
JSON_ClosingSBracket:
JSON_Punct_Stem JSON_Punct_ClosingSBracket
{
const node_info& JSON_Punct_Stem=sparser->get_node_info($1);
const node_info& JSON_Punct_ClosingSBracket=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_ClosingSBracket->JSON_Punct_Stem JSON_Punct_ClosingSBracket");
$$=sparser->combine_nodes("JSON_ClosingSBracket",JSON_Punct_Stem,JSON_Punct_ClosingSBracket);

};
JSON_Closing_Value_Element:
JSON_Array JSON_ClosingSBracket
{
const node_info& JSON_Array=sparser->get_node_info($1);
const node_info& JSON_ClosingSBracket=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_Array JSON_ClosingSBracket");
$$=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_Array,JSON_ClosingSBracket);

}
|JSON_CON JSON_ClosingSBracket
{
const node_info& JSON_CON=sparser->get_node_info($1);
const node_info& JSON_ClosingSBracket=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_CON JSON_ClosingSBracket");
$$=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_CON,JSON_ClosingSBracket);

}
|JSON_Hash_Ref JSON_ClosingSBracket
{
const node_info& JSON_Hash_Ref=sparser->get_node_info($1);
const node_info& JSON_ClosingSBracket=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_Hash_Ref JSON_ClosingSBracket");
$$=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_Hash_Ref,JSON_ClosingSBracket);

}
|JSON_String JSON_ClosingSBracket
{
const node_info& JSON_String=sparser->get_node_info($1);
const node_info& JSON_ClosingSBracket=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_String JSON_ClosingSBracket");
$$=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_String,JSON_ClosingSBracket);

};
JSON_Colon:
JSON_Punct_Stem JSON_Punct_Colon
{
const node_info& JSON_Punct_Stem=sparser->get_node_info($1);
const node_info& JSON_Punct_Colon=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Colon->JSON_Punct_Stem JSON_Punct_Colon");
$$=sparser->combine_nodes("JSON_Colon",JSON_Punct_Stem,JSON_Punct_Colon);

};
JSON_Comma:
JSON_Punct_Stem JSON_Punct_Comma
{
const node_info& JSON_Punct_Stem=sparser->get_node_info($1);
const node_info& JSON_Punct_Comma=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Comma->JSON_Punct_Stem JSON_Punct_Comma");
$$=sparser->combine_nodes("JSON_Comma",JSON_Punct_Stem,JSON_Punct_Comma);

};
JSON_Hash:
JSON_Punct_Stem JSON_Punct_Hash
{
const node_info& JSON_Punct_Stem=sparser->get_node_info($1);
const node_info& JSON_Punct_Hash=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Hash->JSON_Punct_Stem JSON_Punct_Hash");
$$=sparser->combine_nodes("JSON_Hash",JSON_Punct_Stem,JSON_Punct_Hash);

};
JSON_Hash_Ref:
JSON_Hash_Relative JSON_CON
{
const node_info& JSON_Hash_Relative=sparser->get_node_info($1);
const node_info& JSON_CON=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Hash_Ref->JSON_Hash_Relative JSON_CON");
$$=sparser->combine_nodes("JSON_Hash_Ref",JSON_Hash_Relative,JSON_CON);

};
JSON_Hash_Relative:
JSON_Hash JSON_Hash_lfea_relative
{
const node_info& JSON_Hash=sparser->get_node_info($1);
const node_info& JSON_Hash_lfea_relative=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Hash_Relative->JSON_Hash JSON_Hash_lfea_relative");
$$=sparser->combine_nodes("JSON_Hash_Relative",JSON_Hash,JSON_Hash_lfea_relative);

};
JSON_Hash_lfea_relative:
t_JSON_Punct_Relative 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_Hash_lfea_relative",word);

};
JSON_Key:
JSON_String JSON_Colon
{
const node_info& JSON_String=sparser->get_node_info($1);
const node_info& JSON_Colon=sparser->get_node_info($2);
sparser->add_feature_to_leaf(JSON_Colon,"Punct",std::string("main_verb"));
sparser->add_feature_to_leaf(JSON_Colon,"Punct",std::string("json_key_value"),false,true);
sparser->add_feature_to_leaf(JSON_Colon,"main_verb",std::string("indicative"),true);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key->JSON_String JSON_Colon");
$$=sparser->combine_nodes("JSON_Key",JSON_String,JSON_Colon);
};
JSON_Key_Value_Pair:
JSON_Key JSON_Array
{
const node_info& JSON_Key=sparser->get_node_info($1);
const node_info& JSON_Array=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_Array");
$$=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_Array);

}
|JSON_Key JSON_CON
{
const node_info& JSON_Key=sparser->get_node_info($1);
const node_info& JSON_CON=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_CON");
$$=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_CON);

}
|JSON_Key JSON_Hash_Ref
{
const node_info& JSON_Key=sparser->get_node_info($1);
const node_info& JSON_Hash_Ref=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_Hash_Ref");
$$=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_Hash_Ref);
}
|JSON_Key JSON_String
{
const node_info& JSON_Key=sparser->get_node_info($1);
const node_info& JSON_String=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_String");
$$=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_String);

};
JSON_Open_Array:
JSON_Open_Array JSON_Value_List_Element
{
const node_info& JSON_Open_Array=sparser->get_node_info($1);
const node_info& JSON_Value_List_Element=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_Array->JSON_Open_Array JSON_Value_List_Element");
$$=sparser->combine_nodes("JSON_Open_Array",JSON_Open_Array,JSON_Value_List_Element);

}
|JSON_OpeningSBracket 
{
const node_info& JSON_OpeningSBracket=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_Array->JSON_OpeningSBracket");
$$=sparser->set_node_info("JSON_Open_Array",JSON_OpeningSBracket);

};
JSON_Open_String:
JSON_Quotes HUN_N_Sg
{
const node_info& JSON_Quotes=sparser->get_node_info($1);
const node_info& HUN_N_Sg=sparser->get_node_info($2);
sparser->add_feature_to_leaf(HUN_N_Sg,"Noun",std::string("json_key"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_String->JSON_Quotes HUN_N_Sg");
$$=sparser->combine_nodes("JSON_Open_String",JSON_Quotes,HUN_N_Sg);
}
|JSON_Quotes JSON_CON
{
const node_info& JSON_Quotes=sparser->get_node_info($1);
const node_info& JSON_CON=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_String->JSON_Quotes JSON_CON");
$$=sparser->combine_nodes("JSON_Open_String",JSON_Quotes,JSON_CON);

};
JSON_OpeningSBracket:
JSON_Punct_Stem JSON_Punct_OpeningSBracket
{
const node_info& JSON_Punct_Stem=sparser->get_node_info($1);
const node_info& JSON_Punct_OpeningSBracket=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_OpeningSBracket->JSON_Punct_Stem JSON_Punct_OpeningSBracket");
$$=sparser->combine_nodes("JSON_OpeningSBracket",JSON_Punct_Stem,JSON_Punct_OpeningSBracket);

};
JSON_Punct_ClosingSBracket:
t_JSON_Punct_ClosingSBracket 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_ClosingSBracket);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_Punct_ClosingSBracket",word);

};
JSON_Punct_Colon:
t_JSON_Punct_Colon 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Colon);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_Punct_Colon",word);

};
JSON_Punct_Comma:
t_JSON_Punct_Comma 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Comma);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_Punct_Comma",word);

};
JSON_Punct_Hash:
t_JSON_Punct_Hash 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Hash);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_Punct_Hash",word);

};
JSON_Punct_OpeningSBracket:
t_JSON_Punct_OpeningSBracket 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_OpeningSBracket);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_Punct_OpeningSBracket",word);

};
JSON_Punct_Quotes:
t_JSON_Punct_Quotes 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Quotes);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_Punct_Quotes",word);

};
JSON_Punct_Stem:
t_JSON_Punct_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("JSON_Punct_Stem",word);

};
JSON_Quotes:
JSON_Punct_Stem JSON_Punct_Quotes
{
const node_info& JSON_Punct_Stem=sparser->get_node_info($1);
const node_info& JSON_Punct_Quotes=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Quotes->JSON_Punct_Stem JSON_Punct_Quotes");
$$=sparser->combine_nodes("JSON_Quotes",JSON_Punct_Stem,JSON_Punct_Quotes);

};
JSON_String:
JSON_Open_String JSON_Quotes
{
const node_info& JSON_Open_String=sparser->get_node_info($1);
const node_info& JSON_Quotes=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_String->JSON_Open_String JSON_Quotes");
$$=sparser->combine_nodes("JSON_String",JSON_Open_String,JSON_Quotes);

};
JSON_Value_List_Element:
JSON_Array JSON_Comma
{
const node_info& JSON_Array=sparser->get_node_info($1);
const node_info& JSON_Comma=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_Array JSON_Comma");
$$=sparser->combine_nodes("JSON_Value_List_Element",JSON_Array,JSON_Comma);

}
|JSON_CON JSON_Comma
{
const node_info& JSON_CON=sparser->get_node_info($1);
const node_info& JSON_Comma=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_CON JSON_Comma");
$$=sparser->combine_nodes("JSON_Value_List_Element",JSON_CON,JSON_Comma);

}
|JSON_Hash_Ref JSON_Comma
{
const node_info& JSON_Hash_Ref=sparser->get_node_info($1);
const node_info& JSON_Comma=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_Hash_Ref JSON_Comma");
$$=sparser->combine_nodes("JSON_Value_List_Element",JSON_Hash_Ref,JSON_Comma);

}
|JSON_String JSON_Comma
{
const node_info& JSON_String=sparser->get_node_info($1);
const node_info& JSON_Comma=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_String JSON_Comma");
$$=sparser->combine_nodes("JSON_Value_List_Element",JSON_String,JSON_Comma);

};
S:
ENG_VP 
{
const node_info& ENG_VP=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP");
$$=sparser->set_node_info("S",ENG_VP);

}
|HUN_VP HUN_Punct
{
const node_info& HUN_VP=sparser->get_node_info($1);
const node_info& HUN_Punct=sparser->get_node_info($2);
std::vector<unsigned int> nodes;
sparser->get_nodes_by_symbol(HUN_Punct,"QuestionMark",std::string(),nodes);
if(nodes.size()==1){
		const node_info& punct=sparser->get_node_info(nodes[0]);
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"interrogative");
		sparser->add_feature_to_leaf(HUN_VP,"main_verb",std::string("interrogative"),true);
}
else{
		nodes.clear();
		sparser->get_nodes_by_symbol(HUN_Punct,"FullStop",std::string(),nodes);
		if(nodes.size()==1){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"indicative");
				const node_info& punct=sparser->get_node_info(nodes[0]);
				sparser->add_feature_to_leaf(HUN_VP,"main_verb",std::string("indicative"),true);
		}
		else{
				logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"imperative");
				sparser->add_feature_to_leaf(HUN_VP,"main_verb",std::string("imperative"),true);
		}
}
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->HUN_VP HUN_Punct");
$$=sparser->combine_nodes("S",HUN_VP,HUN_Punct);
}
|JSON_Key_Value_Pair 
{
const node_info& JSON_Key_Value_Pair=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->JSON_Key_Value_Pair");
$$=sparser->set_node_info("S",JSON_Key_Value_Pair);

};
%%
//Included just in order that the IDE can see what's
//in there and it does not report so many errors.
#ifndef C_DECLARATIONS
#include "C_declarations.cpp"
#endif

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

	std::string analyses,modified_human_input,main_verb_symbols,main_verb_lexeme;
	db *sqlite=NULL;
	transgraph *transgraph=NULL;
	char *analysischr=NULL;
	std::locale locale;
	yy::parser parser;
	std::time_t timestamp=std::time(nullptr);
	std::set<std::pair<std::string,unsigned int>> functors_with_matching_nr_of_deps;
	std::set<std::pair<std::string,unsigned int>>::const_iterator functor_with_matching_nr_of_deps;
	lexicon main_verb;

	logger::singleton("console",0,"LE");//Don't forget to turn off logging i.e. comment out if necessary e.g. in android release versions
	logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"human_input:"+std::string(human_input));
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
	query_result *main_symbol_result=NULL;
	main_symbol_result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='main_symbol';");
	std::string main_symbol=*main_symbol_result->field_value_at_row_position(0,"value");
	delete main_symbol_result;
	query_result *main_verb_result=NULL;
	main_verb_result=sqlite->exec_sql("SELECT * FROM SETTINGS WHERE key='"+main_symbol+"';");
	main_verb_symbols=*main_verb_result->field_value_at_row_position(0,"value");
	std::replace(main_verb_symbols.begin(),main_verb_symbols.end(),'<','\'');
	std::replace(main_verb_symbols.begin(),main_verb_symbols.end(),'>','\'');
	delete main_verb_result;
	query_result *language_results=NULL;
	language_results=sqlite->exec_sql("SELECT * FROM LANGUAGES WHERE lid='"+std::string(language)+"';");
	bool natural_language;
	if(language_results!=NULL){
		natural_language=std::atoi(language_results->field_value_at_row_position(0,"natural_language")->c_str());
	}
	else{
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"language not defined in db");
		return NULL;
	}
	bool preprocessing_finished=false;
	unsigned int row_nr=0;
	preprocessor *pp=NULL;
	std::string ref_id;
	while(preprocessing_finished==false){
		std::string pp_human_input;
		std::string prev_ref_id;
		if(row_nr==0){
			if(natural_language==false){
				pp=pp_factory::get_instance(language,timestamp,human_input);
			}
			else{
				preprocessing_finished=true;
				pp_human_input=human_input;
			}
		}
		if(pp!=NULL){
			std::pair<std::string,std::string> next_row=pp->get_row(row_nr);
			if(next_row.first.empty()==false){
				prev_ref_id=ref_id;
				ref_id=next_row.first;
				pp_human_input=next_row.second;
			}
			else{
				preprocessing_finished=true;
				ref_id="";
				prev_ref_id="";
			}
			++row_nr;
		}
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"preprocessed human input:"+pp_human_input);
		token_paths=new tokenpaths(toa);
		while(pp_human_input.empty()==false&&toa!=0&&token_paths->is_any_left()==true){
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
				transgraph::clear_node_functor_map();
				if(modified_human_input.empty()==true){
					lex=new lexer(pp_human_input.c_str(),language,locale,false,token_paths);
					token_paths->assign_lexer(lex);
				}
				logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"lexer started");
				sparser=new interpreter(toa,std::to_string(timestamp),prev_ref_id);
				logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"interpreter started");
				bool delete_lexer=true;
				if(toa&HI_SYNTAX||toa&HI_SYNTAX&&toa&HI_SEMANTICS){
					int parse_error=parser.parse();
					if(parse_error==0){
						if(toa&HI_SEMANTICS){
							transgraph=sparser->longest_match_for_semantic_rules_found();
							if(transgraph!=NULL){
								token_paths->validate_parse_tree(sparser->nodes());
								token_paths->validate_path(lex->word_entries(),transgraph,sparser->context_nodes(),true);
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
							token_paths->validate_path(lex->word_entries(),NULL,sparser->context_nodes(),true);
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
				else if(toa&HI_MORPHOLOGY&&toa&HI_SEMANTICS){
					if(crh>0){
						if(modified_human_input.empty()==true){
							modified_human_input=token_paths->add_context_reference_word(crh,pp_human_input,main_verb_lexeme);
							lex=token_paths->lexer();
							delete_lexer=false;
							while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
								lex->next_token();
							}
							main_verb=lex->get_word_by_lexeme(main_verb_lexeme);
						}
						sparser->build_dependency_semantics(lex,token_paths,main_verb);
						delete sparser;
						sparser=NULL;
						transgraph=NULL;
						if(token_paths->is_any_left()==true){
							delete lex;
							lex=new lexer(modified_human_input.c_str(),language,locale,false,token_paths);
							token_paths->assign_lexer(lex);
							while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
								lex->next_token();
							}
							main_verb=lex->get_word_by_lexeme(main_verb_lexeme);
							delete_lexer=false;
						}
					}
					else{
						//1. Find functor(s) with gcat set in settings
						//2. Determine the intersection of functors_found of each iteration
						//3. If there are >1 functors in the intersection, select those that
						//   have the highest number of dependencies found.
						//4. If there are >1, make as many turns as necessary to return analysis for each.
						if(modified_human_input.empty()==true){
							while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
								lex->next_token();
							}
							if(functors_with_matching_nr_of_deps.empty()==true){//Run only once, not for each token path
								//Get every possible word analysis from lexer cache to be able to look up all possible functors
								std::vector<lexicon> words=lex->word_entries();
								std::vector<lexicon> all_words=lex->cached_word_entries();
								//std::map<unsigned int,lexicon> main_verbs=lex->find_main_verb(words);
								functors_with_matching_nr_of_deps=sparser->find_functors_with_matching_nr_of_deps(all_words,words,main_verb_symbols);
								functor_with_matching_nr_of_deps=functors_with_matching_nr_of_deps.begin();
							}
							if(functor_with_matching_nr_of_deps!=functors_with_matching_nr_of_deps.end()){
								query_result *result=NULL;
								main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
								if(main_verb.lexeme.empty()==true){
									result=sqlite->exec_sql("SELECT * FROM LEXICON WHERE LEXEME='"+functor_with_matching_nr_of_deps->first+"' AND LID='"+lex->language()+"' AND GCAT in("+main_verb_symbols+");");
									if(result!=NULL){
										std::string word=*result->field_value_at_row_position(0,"word");
										modified_human_input=token_paths->modify_human_input(word,pp_human_input);
										lex=token_paths->lexer();
										delete_lexer=false;
										delete result;
										while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
											lex->next_token();
										}
										main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
									}
								}
								else{
									modified_human_input=pp_human_input;
									delete_lexer=false;
								}
							}
						}
						if(functor_with_matching_nr_of_deps!=functors_with_matching_nr_of_deps.end()){
							sparser->build_dependency_semantics(lex,token_paths,main_verb);
							if(token_paths->is_any_left()==true){
								delete lex;
								lex=new lexer(modified_human_input.c_str(),language,locale,false,token_paths);
								token_paths->assign_lexer(lex);
								while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
									lex->next_token();
								}
								main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
								delete_lexer=false;
							}
							else{
								++functor_with_matching_nr_of_deps;
								if(functor_with_matching_nr_of_deps!=functors_with_matching_nr_of_deps.end()){
									query_result *result=NULL;
									main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
									if(main_verb.lexeme.empty()==true){
										result=sqlite->exec_sql("SELECT * FROM LEXICON WHERE LEXEME='"+functor_with_matching_nr_of_deps->first+"' AND LID='"+lex->language()+"' AND GCAT in("+main_verb_symbols+");");
										if(result!=NULL){
											std::string word=*result->field_value_at_row_position(0,"word");
											modified_human_input=token_paths->modify_human_input(word,pp_human_input);
											lex=token_paths->lexer();
											delete_lexer=false;
											delete result;
											while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
												lex->next_token();
											}
											main_verb=lex->get_word_by_lexeme(functor_with_matching_nr_of_deps->first);
										}
									}
									else{
										modified_human_input=pp_human_input;
										delete_lexer=false;
									}
								}
							}
						}
						else{
							token_paths->invalidate_parse_tree(sparser->nodes());
							token_paths->invalidate_path(lex->word_entries(),"semantic error",NULL);
						}
						delete sparser;
						sparser=NULL;
						transgraph=NULL;
					}
				}
				if(delete_lexer==true){
					delete lex;
					lex=NULL;
				}
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
			morphan_result::clear_features_to_inherit();
			transgraph::clear_node_functor_map();
		}
		if(pp_human_input.empty()==false){
			try{
				analyses=token_paths->create_analysis(toa,language,target_language,std::string(pp_human_input),timestamp,std::string(source),ref_id);
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
			}
			catch(std::runtime_error& exception){//Catch underived exceptions thrown with string based messages
				logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"runtime error:"+std::string(exception.what()));
				return NULL;
			}
			catch(...){
				logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"unexpected error ...");
				return NULL;
			}
		}
	}
	return analysischr;
}
#ifdef __EMSCRIPTEN__
}
#endif
