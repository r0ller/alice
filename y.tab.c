#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#ifdef _LIBC
#include "namespace.h"
#endif
#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "hi.y"
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
#line 47 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();


#define t_Con 1
#define t_ENG_A 2
#define t_ENG_Adv 3
#define t_ENG_Det 4
#define t_ENG_N_stem 5
#define t_ENG_N_lfea_Pl 6
#define t_ENG_N_lfea_Sg 7
#define t_ENG_Prep 8
#define t_ENG_QPro 9
#define t_ENG_V_stem 10
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    1,    6,    4,    4,    2,
    5,    7,    7,   10,   10,    3,    8,   11,   13,   13,
   17,   15,   15,   21,   20,   24,   24,   16,   16,   16,
   18,   19,   22,   12,    9,   23,   14,
};
static const short yylen[] = {                            2,
    1,    1,    2,    1,    2,    2,    2,    2,    2,    2,
    2,    1,    2,    2,    1,    1,    1,    1,    1,    1,
    2,    2,    1,    2,    1,    2,    2,    1,    2,    1,
    1,    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
   17,    0,    1,    0,    0,    0,    0,   36,   34,   37,
   31,   35,   18,    3,    8,    9,    0,   12,    0,    0,
   15,   16,   19,   20,    0,    0,    0,    0,   25,    0,
    5,    6,    7,   10,   11,   13,   14,   22,   33,   32,
   21,   24,   26,    0,    0,   27,
};
static const short yydgoto[] = {                          2,
    3,    4,   14,    5,   15,    6,   16,    7,   17,   18,
   19,   20,   21,   22,   23,   24,   25,   26,   41,   27,
   28,   42,   29,   30,
};
static const short yysindex[] = {                        -6,
    0,    0,    0,   48,    3,   62,   57,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   62,    0,   67,   67,
    0,    0,    0,    0,   22,    9,   22,   22,    0,   22,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   22,   22,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,   20,   30,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,   19,    0,   29,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   39,    0,
};
static const short yygindex[] = {                         0,
    0,    0,   26,    0,   31,    0,   -5,    0,    0,    6,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -19,
    0,    0,  -27,    7,
};
#define YYTABLESIZE 72
static const short yytable[] = {                         43,
   32,   34,   46,    1,   23,   38,   23,   23,   44,   23,
   12,   35,   23,   23,   39,   40,   43,   46,   28,    2,
   28,   28,    8,   28,   36,   37,   28,   28,   30,    4,
   30,   30,   33,   30,   45,   31,   30,   30,   29,    0,
   29,   29,    0,   29,    0,    0,   29,   29,    8,    9,
   10,    0,   11,    0,    0,   12,   13,    8,    9,   10,
    0,   11,    8,    9,    0,   13,   11,    8,    9,    0,
   13,   11,
};
static const short yycheck[] = {                         27,
    6,    7,   30,   10,    0,   25,    2,    3,   28,    5,
    8,   17,    8,    9,    6,    7,   44,   45,    0,    0,
    2,    3,    1,    5,   19,   20,    8,    9,    0,    0,
    2,    3,    7,    5,   28,    5,    8,    9,    0,   -1,
    2,    3,   -1,    5,   -1,   -1,    8,    9,    1,    2,
    3,   -1,    5,   -1,   -1,    8,    9,    1,    2,    3,
   -1,    5,    1,    2,   -1,    9,    5,    1,    2,   -1,
    9,    5,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 10
#if YYDEBUG
static const char *yyname[] = {

"end-of-file","t_Con","t_ENG_A","t_ENG_Adv","t_ENG_Det","t_ENG_N_stem",
"t_ENG_N_lfea_Pl","t_ENG_N_lfea_Sg","t_ENG_Prep","t_ENG_QPro","t_ENG_V_stem",
};
static const char *yyrule[] = {
"$accept : S",
"S : ENG_VP",
"ENG_VP : ENG_Vbar1",
"ENG_VP : ENG_Vbar1 ENG_AdvP",
"ENG_VP : ENG_Vbar2",
"ENG_VP : ENG_Vbar2 ENG_PP",
"ENG_VP : ENG_Vbar3 ENG_NP",
"ENG_Vbar3 : ENG_V ENG_AdvP",
"ENG_Vbar2 : ENG_Vbar1 ENG_PP",
"ENG_Vbar2 : ENG_Vbar1 ENG_NP",
"ENG_Vbar1 : ENG_V ENG_NP",
"ENG_PP : ENG_Prep ENG_NP",
"ENG_NP : ENG_CNP",
"ENG_NP : ENG_QPro ENG_CNP",
"ENG_CNP : ENG_A ENG_CNP",
"ENG_CNP : ENG_N",
"ENG_AdvP : ENG_Adv",
"ENG_V : t_ENG_V_stem",
"ENG_QPro : t_ENG_QPro",
"ENG_N : ENG_N_Sg",
"ENG_N : ENG_N_Pl",
"ENG_N_Sg_0Con : ENG_N_Stem ENG_N_lfea_Sg",
"ENG_N_Sg : ENG_N_Sg_0Con ENG_1Con",
"ENG_N_Sg : ENG_1Con",
"ENG_N_Pl_0Con : ENG_N_Stem ENG_N_lfea_Pl",
"ENG_1Con : ENG_Con",
"ENG_nCon : ENG_1Con ENG_Con",
"ENG_nCon : ENG_nCon ENG_Con",
"ENG_N_Pl : ENG_N_Pl_0Con",
"ENG_N_Pl : ENG_N_Pl_0Con ENG_nCon",
"ENG_N_Pl : ENG_nCon",
"ENG_N_Stem : t_ENG_N_stem",
"ENG_N_lfea_Sg : t_ENG_N_lfea_Sg",
"ENG_N_lfea_Pl : t_ENG_N_lfea_Pl",
"ENG_A : t_ENG_A",
"ENG_Prep : t_ENG_Prep",
"ENG_Con : t_Con",
"ENG_Adv : t_ENG_Adv",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 452 "hi.y"

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
#line 333 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 46 "hi.y"
	{
				const node_info& ENG_VP=sparser->get_node_info(yystack.l_mark[0]);
				std::cout<<"S->ENG_VP"<<std::endl;
}
break;
case 2:
#line 51 "hi.y"
	{
				lexicon word;

				const node_info& ENG_Vbar1=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_VP";
				yyval=sparser->set_node_info(word,ENG_Vbar1);
				std::cout<<"ENG_VP->ENG_Vbar1"<<std::endl;
}
break;
case 3:
#line 60 "hi.y"
	{
				const node_info& ENG_Vbar1=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_AdvP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar1 ENG_AdvP"<<std::endl;
}
break;
case 4:
#line 72 "hi.y"
	{
				lexicon word;

				const node_info& ENG_Vbar2=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_VP";
				yyval=sparser->set_node_info(word,ENG_Vbar2);
				std::cout<<"ENG_VP->ENG_Vbar2"<<std::endl;
}
break;
case 5:
#line 81 "hi.y"
	{
				const node_info& ENG_Vbar2=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_PP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar2 ENG_PP"<<std::endl;
}
break;
case 6:
#line 93 "hi.y"
	{
				const node_info& ENG_Vbar3=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_NP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar3 ENG_NP"<<std::endl;
}
break;
case 7:
#line 105 "hi.y"
	{
				const node_info& ENG_V=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_AdvP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_VBAR3",ENG_V,ENG_AdvP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_Vbar3->ENG_V ENG_AdvP"<<std::endl;
}
break;
case 8:
#line 117 "hi.y"
	{
				const node_info& ENG_Vbar1=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_PP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_VBAR2",ENG_Vbar1,ENG_PP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_PP"<<std::endl;
}
break;
case 9:
#line 129 "hi.y"
	{
				const node_info& ENG_Vbar1=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_NP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_NP"<<std::endl;
}
break;
case 10:
#line 141 "hi.y"
	{
				const node_info& ENG_V=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_NP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_VBAR1",ENG_V,ENG_NP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_Vbar1->ENG_V ENG_NP"<<std::endl;
}
break;
case 11:
#line 153 "hi.y"
	{
				const node_info& ENG_Prep=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_NP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Prep->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_PP->ENG_Prep ENG_NP"<<std::endl;
}
break;
case 12:
#line 165 "hi.y"
	{
				lexicon word;

				const node_info& ENG_CNP=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_NP";
				yyval=sparser->set_node_info(word,ENG_CNP);
				std::cout<<"ENG_NP->ENG_CNP"<<std::endl;
}
break;
case 13:
#line 174 "hi.y"
	{
				const node_info& ENG_QPro=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_CNP=sparser->get_node_info(yystack.l_mark[0]);
				/*	TODO: really need to check if there's a constant ?
					Currently, it's done to make functor argument diff easier.*/
				/*const node_info& object_node=sparser->get_node_info(sparser->get_object_node(CNP));
				if(object_node.right_child!=0){
					//printf("Syntax error: constants like %s cannot be quantified!\n",sparser->get_node_info(object_node.right_child).expression.c_str());
					return -1;
				}*/
				yyval=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);
				/* No check for $$<0 since quantifier pronouns are not validated as
				 * everything in the current model seems to be countable.*/
				std::cout<<"ENG_NP->ENG_QPro ENG_CNP"<<std::endl;
}
break;
case 14:
#line 194 "hi.y"
	{
				const node_info& ENG_A=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_CNP=sparser->get_node_info(yystack.l_mark[0]);
				/*TODO: ellenorizni, hogy ha a CNP parameteres akkor hiba mint a QPro CNP-nal!*/
				yyval=sparser->combine_nodes("ENG_CNP",ENG_A,ENG_CNP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_CNP->ENG_A ENG_CNP"<<std::endl;
}
break;
case 15:
#line 207 "hi.y"
	{
				lexicon word;

				const node_info& ENG_N=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_CNP";
				yyval=sparser->set_node_info(word,ENG_N);
				std::cout<<"ENG_CNP->ENG_N"<<std::endl;
}
break;
case 16:
#line 216 "hi.y"
	{
				lexicon word;

				const node_info& ENG_Adv=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_AdvP";
				yyval=sparser->set_node_info(word,ENG_Adv);
				std::cout<<"ENG_AdvP->ENG_Adv"<<std::endl;
}
break;
case 17:
#line 225 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 18:
#line 234 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				/*TODO: consider what if quantifiers like ALL are handled as functors?*/
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 19:
#line 244 "hi.y"
	{
				lexicon word;
	
				const node_info& ENG_N_Sg=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_N";
				yyval=sparser->set_node_info(word,ENG_N_Sg);
				std::cout<<"ENG_N->ENG_N_Sg"<<std::endl;
}
break;
case 20:
#line 253 "hi.y"
	{
				lexicon word;

				const node_info& ENG_N_Pl=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_N";
				yyval=sparser->set_node_info(word,ENG_N_Pl);
				std::cout<<"ENG_N->ENG_N_Pl"<<std::endl;
}
break;
case 21:
#line 262 "hi.y"
	{
				const node_info& ENG_N_Stem=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_N_lfea_Sg=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_N_Sg",ENG_N_Stem,ENG_N_lfea_Sg);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg"<<std::endl;
}
break;
case 22:
#line 274 "hi.y"
	{
				const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_1Con=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con ENG_1Con"<<std::endl;
}
break;
case 23:
#line 281 "hi.y"
	{
				lexicon word;

				const node_info& ENG_1Con=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_N_Sg";
				yyval=sparser->set_node_info(word,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_1Con"<<std::endl;
}
break;
case 24:
#line 290 "hi.y"
	{
				const node_info& ENG_N_Stem=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_N_lfea_Pl=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl"<<std::endl;
}
break;
case 25:
#line 302 "hi.y"
	{
				lexicon word;

				const node_info& ENG_Con=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_1Con";
				yyval=sparser->set_node_info(word,ENG_Con);
				std::cout<<"ENG_1Con->ENG_Con:"<<ENG_Con.expression.lexeme<<std::endl;
}
break;
case 26:
#line 311 "hi.y"
	{
				const node_info& ENG_1Con=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_Con=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_nCon->ENG_1Con ENG_Con"<<std::endl;
}
break;
case 27:
#line 323 "hi.y"
	{
				const node_info& ENG_nCon=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_Con=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_nCon->ENG_nCon ENG_Con"<<std::endl;
}
break;
case 28:
#line 335 "hi.y"
	{
				lexicon word;

				const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_N_Pl";
				yyval=sparser->set_node_info(word,ENG_N_Pl_0Con);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con"<<std::endl;
}
break;
case 29:
#line 344 "hi.y"
	{
				const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& ENG_nCon=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con,ENG_nCon);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con ENG_nCon"<<std::endl;
}
break;
case 30:
#line 356 "hi.y"
	{
				lexicon word;

				const node_info& ENG_nCon=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ENG_N_Pl";
				yyval=sparser->set_node_info(word,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_nCon"<<std::endl;
}
break;
case 31:
#line 365 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 32:
#line 374 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();/*TODO: it's unnecessary to duplicate the word info for each node that is related to an affix of the stem of the last scanned word*/
				/*Create a method that returns the info only about the affix in question. Hint: create a method 'lexicon lexer::get_lexicon_info_by_token( uint token )' which*/
				/*would return everything what last_word_scanned() returns but: if the token belongs to a stem it equals to calling last_word_scanned()*/
				/*if the token belongs to an lfea, every field is the same as when calling last_word_scanned() but: the token field would contain the token of the lfea,*/
				/*and if the affix has a functor, then the gcat is the corresponding PREFIX/INFIX/SUFFIX and the lexeme corresponds to that of the affix*/
				/*if the affix does not have a functor, then the gcat is again either PREFIX/INFIX/SUFFIX but the lexeme field is empty*/
				/*WELL, it would have been good if I had written here if duplicating word info poses any problem...*/
				word.gcat="ENG_N_lfea_Sg";
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 33:
#line 390 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				word.gcat="ENG_N_lfea_Pl";
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 34:
#line 400 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 35:
#line 409 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned();
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 36:
#line 422 "hi.y"
	{
				const node_info empty_node_info={};
				lexicon word;

				word=lex->last_word_scanned();
				word.gcat="CON";
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<"Constant:"<<word.word<<std::endl;
}
break;
case 37:
#line 432 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned();
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
#line 1000 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
