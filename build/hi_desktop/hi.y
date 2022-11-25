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
%token	t_ENG_CON_3sg
%token	t_ENG_CON_GEN
%token	t_ENG_DET_Stem
%token	t_ENG_N_Stem
%token	t_ENG_N_Pl
%token	t_ENG_N_Sg
%token	t_ENG_PREP_Stem
%token	t_ENG_PRON_Stem
%token	t_ENG_PRON_wh
%token	t_ENG_V_Stem
%token	t_ENG_V_3sg
%token	t_ENG_V_Aux
%token	t_ENG_Num_Stem
%token	t_ENG_Num_Nom
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
%token	t_ENG_Punct_Stem
%token	t_ENG_Punct_FullStop
%token	t_ENG_Punct_QuestionMark
%token	t_ENG_Punct_ExclamationMark
%%
ENG_1CON:
ENG_CON 
{
const node_info& ENG_CON=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_1CON->ENG_CON");
$$=sparser->set_node_info("ENG_1CON",ENG_CON);

};
ENG_CON:
t_ENG_CON_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_CON",word);

};
ENG_CON_3sgGEN:
ENG_CON_lfea_3sg ENG_CON_lfea_GEN
{
const node_info& ENG_CON_lfea_3sg=sparser->get_node_info($1);
const node_info& ENG_CON_lfea_GEN=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CON_3sgGEN->ENG_CON_lfea_3sg ENG_CON_lfea_GEN");
$$=sparser->combine_nodes("ENG_CON_3sgGEN",ENG_CON_lfea_3sg,ENG_CON_lfea_GEN);

};
ENG_CON_GEN:
ENG_CON ENG_CON_3sgGEN
{
const node_info& ENG_CON=sparser->get_node_info($1);
const node_info& ENG_CON_3sgGEN=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CON_GEN->ENG_CON ENG_CON_3sgGEN");
$$=sparser->combine_nodes("ENG_CON_GEN",ENG_CON,ENG_CON_3sgGEN);

};
ENG_CON_lfea_3sg:
t_ENG_CON_3sg 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_3sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_CON_lfea_3sg",word);

};
ENG_CON_lfea_GEN:
t_ENG_CON_GEN 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_GEN);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_CON_lfea_GEN",word);

};
ENG_DET_Stem:
t_ENG_DET_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_DET_Stem",word);

};
ENG_DP:
ENG_DET_Stem ENG_N
{
const node_info& ENG_DET_Stem=sparser->get_node_info($1);
const node_info& ENG_N=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_DET_Stem ENG_N");
$$=sparser->combine_nodes("ENG_DP",ENG_DET_Stem,ENG_N);

}
|ENG_DET_Stem ENG_Num_Nom
{
const node_info& ENG_DET_Stem=sparser->get_node_info($1);
const node_info& ENG_Num_Nom=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_DET_Stem ENG_Num_Nom");
$$=sparser->combine_nodes("ENG_DP",ENG_DET_Stem,ENG_Num_Nom);

}
|ENG_DET_Stem ENG_Num_Ord
{
const node_info& ENG_DET_Stem=sparser->get_node_info($1);
const node_info& ENG_Num_Ord=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_DET_Stem ENG_Num_Ord");
$$=sparser->combine_nodes("ENG_DP",ENG_DET_Stem,ENG_Num_Ord);

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
ENG_CON_GEN ENG_N
{
const node_info& ENG_CON_GEN=sparser->get_node_info($1);
const node_info& ENG_N=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CON_GEN ENG_N");
$$=sparser->combine_nodes("ENG_NP",ENG_CON_GEN,ENG_N);

}
|ENG_N 
{
const node_info& ENG_N=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_N");
$$=sparser->set_node_info("ENG_NP",ENG_N);

};
ENG_N_Pl:
ENG_N_Stem ENG_N_lfea_Pl
{
const node_info& ENG_N_Stem=sparser->get_node_info($1);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Stem ENG_N_lfea_Pl");
$$=sparser->combine_nodes("ENG_N_Pl",ENG_N_Stem,ENG_N_lfea_Pl);

};
ENG_N_Sg:
ENG_1CON 
{
const node_info& ENG_1CON=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_1CON");
$$=sparser->set_node_info("ENG_N_Sg",ENG_1CON);

}
|ENG_N_Stem ENG_N_lfea_Sg
{
const node_info& ENG_N_Stem=sparser->get_node_info($1);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Stem ENG_N_lfea_Sg");
$$=sparser->combine_nodes("ENG_N_Sg",ENG_N_Stem,ENG_N_lfea_Sg);

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
ENG_Num_Nom:
ENG_Num ENG_Num_lfea_Nom
{
const node_info& ENG_Num=sparser->get_node_info($1);
const node_info& ENG_Num_lfea_Nom=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num_Nom->ENG_Num ENG_Num_lfea_Nom");
$$=sparser->combine_nodes("ENG_Num_Nom",ENG_Num,ENG_Num_lfea_Nom);

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
ENG_Num_lfea_Nom:
t_ENG_Num_Nom 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Nom);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_lfea_Nom",word);

};
ENG_Num_lfea_Ord:
t_ENG_Num_Ord 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Ord);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_Num_lfea_Ord",word);

};
ENG_PP:
ENG_PREP ENG_NP
{
const node_info& ENG_PREP=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_PREP ENG_NP");
$$=sparser->combine_nodes("ENG_PP",ENG_PREP,ENG_NP);

};
ENG_PREP:
ENG_PREP_Stem 
{
const node_info& ENG_PREP_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PREP->ENG_PREP_Stem");
$$=sparser->set_node_info("ENG_PREP",ENG_PREP_Stem);

};
ENG_PREP_Stem:
t_ENG_PREP_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PREP_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_PREP_Stem",word);

};
ENG_PRON_Stem:
t_ENG_PRON_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PRON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_PRON_Stem",word);

};
ENG_PRON_lfea_wh:
t_ENG_PRON_wh 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PRON_wh);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_PRON_lfea_wh",word);

};
ENG_PRON_qw:
ENG_PRON_Stem ENG_PRON_lfea_wh
{
const node_info& ENG_PRON_Stem=sparser->get_node_info($1);
const node_info& ENG_PRON_lfea_wh=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PRON_qw->ENG_PRON_Stem ENG_PRON_lfea_wh");
$$=sparser->combine_nodes("ENG_PRON_qw",ENG_PRON_Stem,ENG_PRON_lfea_wh);

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
ENG_Punct_Imp:
ENG_Punct_Stem ENG_Punct_ExclamationMark
{
const node_info& ENG_Punct_Stem=sparser->get_node_info($1);
const node_info& ENG_Punct_ExclamationMark=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct_Imp->ENG_Punct_Stem ENG_Punct_ExclamationMark");
$$=sparser->combine_nodes("ENG_Punct_Imp",ENG_Punct_Stem,ENG_Punct_ExclamationMark);

};
ENG_Punct_Ind:
ENG_Punct_Stem ENG_Punct_FullStop
{
const node_info& ENG_Punct_Stem=sparser->get_node_info($1);
const node_info& ENG_Punct_FullStop=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct_Ind->ENG_Punct_Stem ENG_Punct_FullStop");
$$=sparser->combine_nodes("ENG_Punct_Ind",ENG_Punct_Stem,ENG_Punct_FullStop);

};
ENG_Punct_Int:
ENG_Punct_Stem ENG_Punct_QuestionMark
{
const node_info& ENG_Punct_Stem=sparser->get_node_info($1);
const node_info& ENG_Punct_QuestionMark=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct_Int->ENG_Punct_Stem ENG_Punct_QuestionMark");
$$=sparser->combine_nodes("ENG_Punct_Int",ENG_Punct_Stem,ENG_Punct_QuestionMark);

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
ENG_V:
ENG_V_Stem 
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");
$$=sparser->set_node_info("ENG_V",ENG_V_Stem);

}
|ENG_V_Stem ENG_V_lfea_3sg
{
const node_info& ENG_V_Stem=sparser->get_node_info($1);
const node_info& ENG_V_lfea_3sg=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem ENG_V_lfea_3sg");
$$=sparser->combine_nodes("ENG_V",ENG_V_Stem,ENG_V_lfea_3sg);

};
ENG_VP_Imp:
ENG_V ENG_DP
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_DP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Imp->ENG_V ENG_DP");
$$=sparser->combine_nodes("ENG_VP_Imp",ENG_V,ENG_DP);

}
|ENG_Vbar1 
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Imp->ENG_Vbar1");
$$=sparser->set_node_info("ENG_VP_Imp",ENG_Vbar1);

}
|ENG_Vbar1 ENG_PP
{
const node_info& ENG_Vbar1=sparser->get_node_info($1);
const node_info& ENG_PP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Imp->ENG_Vbar1 ENG_PP");
$$=sparser->combine_nodes("ENG_VP_Imp",ENG_Vbar1,ENG_PP);

};
ENG_VP_Ind:
ENG_Vbar2 ENG_NP
{
const node_info& ENG_Vbar2=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Ind->ENG_Vbar2 ENG_NP");
$$=sparser->combine_nodes("ENG_VP_Ind",ENG_Vbar2,ENG_NP);

};
ENG_VP_Int:
ENG_Vbar3 ENG_NP
{
const node_info& ENG_Vbar3=sparser->get_node_info($1);
const node_info& ENG_NP=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Int->ENG_Vbar3 ENG_NP");
$$=sparser->combine_nodes("ENG_VP_Int",ENG_Vbar3,ENG_NP);

};
ENG_V_Aux:
ENG_V ENG_V_lfea_Aux
{
const node_info& ENG_V=sparser->get_node_info($1);
const node_info& ENG_V_lfea_Aux=sparser->get_node_info($2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Aux->ENG_V ENG_V_lfea_Aux");
$$=sparser->combine_nodes("ENG_V_Aux",ENG_V,ENG_V_lfea_Aux);

};
ENG_V_Stem:
t_ENG_V_Stem 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_V_Stem",word);

};
ENG_V_lfea_3sg:
t_ENG_V_3sg 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_3sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_V_lfea_3sg",word);

};
ENG_V_lfea_Aux:
t_ENG_V_Aux 
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Aux);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
$$=sparser->set_node_info("ENG_V_lfea_Aux",word);

};
ENG_Vbar1:
ENG_V ENG_NP
{
const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(main_node,"main_verb");
std::string parent_symbol="ENG_Vbar1";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
};
ENG_Vbar2:
ENG_N_Sg ENG_V_Aux
{
const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(dependent_node,"V",std::string("main_verb"));
std::string parent_symbol="ENG_Vbar2";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
};
ENG_Vbar3:
ENG_PRON_qw ENG_V_Aux
{
const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(dependent_node,"main_verb");
std::string parent_symbol="ENG_Vbar3";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
};
S:
ENG_VP_Imp ENG_Punct_Imp
{
const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(main_node,"main_verb","imperative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
|ENG_VP_Ind ENG_Punct_Ind
{
const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(main_node,"main_verb","indicative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
|ENG_VP_Int ENG_Punct_Int
{
const node_info& main_node=sparser->get_node_info($1);
const node_info& dependent_node=sparser->get_node_info($2);
sparser->add_feature_to_leaf(main_node,"main_verb","interrogative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
$$=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
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

    std::string analyses,modified_human_input;
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
            if(modified_human_input.empty()==true){
                lex=new lexer(human_input,language,locale,false,token_paths);
            }
            else{
                lex=new lexer(modified_human_input.c_str(),language,locale,false,token_paths);
            }
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
            else if(toa&HI_MORPHOLOGY&&toa&HI_SEMANTICS){
                if(crh>0&&modified_human_input.empty()==true){
                    modified_human_input=token_paths->add_context_reference_word(crh);
                }
                while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
                    lex->next_token();
                }
                sparser->build_dependency_semantics(lex,token_paths);
                //sparser->build_dependency_semantics(toa,crh,language,lex,token_paths);
                delete sparser;
                sparser=NULL;
                transgraph=NULL;
                //delete lex;
                //lex=NULL;
                //break;
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
