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
	#include "morphan.cpp"
	morphan *stemmer=NULL;
	#include "lexer.h"
	lexer *lex=NULL;
	#include "lexer.cpp"
	#include "sp.h"
	interpreter *sparser=NULL;
	#include "sp.cpp"
	int line=0;
#line 46 "y.tab.c"

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


#define hiCONSTANT 1
#define hiLIST 2
#define hiCOPY 3
#define hiDIRECTORY 4
#define hiDIRECTORIES 5
#define hiEXECUTABLE 6
#define hiNONEXECUTABLE 7
#define hiALL 8
#define hiFILE 9
#define hiFILES 10
#define hiTO 11
#define hiREMOVE 12
#define hiDELETE 13
#define hiFROM 14
#define hiCHANGE 15
#define hiMOVE 16
#define hiIN 17
#define hiMAKE 18
#define hiDOWN 19
#define hiSHUT 20
#define hiCOMPUTER 21
#define hiTHE 22
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    1,    6,    4,    4,    2,
    5,    7,    7,   10,   10,    3,    8,   11,   13,   13,
   13,   13,   13,   13,   13,   12,   12,    9,    9,    9,
   15,   14,   16,
};
static const short yylen[] = {                            2,
    1,    1,    2,    1,    2,    2,    2,    2,    2,    2,
    2,    1,    2,    2,    1,    1,    1,    1,    2,    1,
    1,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,
};
static const short yydefred[] = {                         0,
   17,    0,    1,    0,    0,    0,    0,   31,    0,   23,
   26,   27,   18,    0,   20,   28,   29,   30,   32,   24,
    3,    8,    9,    0,   12,    0,    0,   15,   16,   25,
    5,    6,    7,   10,   22,   19,   11,   13,   14,
};
static const short yydgoto[] = {                          2,
    3,    4,   21,    5,   22,    6,   23,    7,   24,   25,
   26,   27,   28,   29,   30,    0,
};
static const short yysindex[] = {                        -2,
    0,    0,    0,   20,    2,   58,   39,    0,    3,    0,
    0,    0,    0,    3,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   58,    0,   68,   68,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,   14,   17,    0,    0,    0,    1,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,   16,    0,   30,    0,   26,    0,    0,  -24,
    0,    0,    0,    0,   42,    0,
};
#define YYTABLESIZE 89
static const short yytable[] = {                          1,
   21,   38,   39,    8,   21,   21,   21,   21,   21,   21,
   21,   21,   16,    2,   21,   17,    4,   21,   18,   21,
    8,   21,   33,    9,   10,   11,   12,   13,   14,   15,
   16,   32,   34,   17,   31,    0,   18,    0,   19,    8,
   20,    0,    9,   10,   11,   12,   13,   14,   15,   37,
   35,    0,    0,    0,    0,   36,    0,   19,    8,   20,
    0,    9,   10,   11,   12,   13,   14,   15,    8,    0,
    0,    9,   10,   11,   12,    0,   14,   15,   20,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,
};
static const short yycheck[] = {                          2,
    0,   26,   27,    1,    4,    5,    6,    7,    8,    9,
   10,   11,   11,    0,   14,   14,    0,   17,   17,   19,
    1,   21,    7,    4,    5,    6,    7,    8,    9,   10,
   11,    6,    7,   14,    5,   -1,   17,   -1,   19,    1,
   21,   -1,    4,    5,    6,    7,    8,    9,   10,   24,
    9,   -1,   -1,   -1,   -1,   14,   -1,   19,    1,   21,
   -1,    4,    5,    6,    7,    8,    9,   10,    1,   -1,
   -1,    4,    5,    6,    7,   -1,    9,   10,   21,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   21,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 22
#if YYDEBUG
static const char *yyname[] = {

"end-of-file","hiCONSTANT","hiLIST","hiCOPY","hiDIRECTORY","hiDIRECTORIES",
"hiEXECUTABLE","hiNONEXECUTABLE","hiALL","hiFILE","hiFILES","hiTO","hiREMOVE",
"hiDELETE","hiFROM","hiCHANGE","hiMOVE","hiIN","hiMAKE","hiDOWN","hiSHUT",
"hiCOMPUTER","hiTHE",
};
static const char *yyrule[] = {
"$accept : S",
"S : VP",
"VP : Vbar1",
"VP : Vbar1 AdvP",
"VP : Vbar2",
"VP : Vbar2 PP",
"VP : Vbar3 NP",
"Vbar3 : V AdvP",
"Vbar2 : Vbar1 PP",
"Vbar2 : Vbar1 NP",
"Vbar1 : V NP",
"PP : Prep NP",
"NP : CNP",
"NP : QPro CNP",
"CNP : A CNP",
"CNP : N",
"AdvP : Adv",
"V : hiLIST",
"QPro : hiALL",
"N : hiFILE Con",
"N : hiFILES",
"N : hiDIRECTORY",
"N : hiDIRECTORY Con",
"N : hiDIRECTORIES",
"N : hiCOMPUTER",
"N : Con",
"A : hiEXECUTABLE",
"A : hiNONEXECUTABLE",
"Prep : hiTO",
"Prep : hiFROM",
"Prep : hiIN",
"Con : hiCONSTANT",
"Adv : hiDOWN",
"Det : hiTHE",

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
#line 394 "hi.y"

int yylex(void){
	int token;
	lexicon word;

	token=lex->next_token();
//	word=lex->last_word_scanned();
//	if(token==0&&lex->last_word_scanned().empty()==true) return 0;//Historic indicator of YACC about end of input stream
//	else return token+1;
	return token;
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
#line 335 "y.tab.c"

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
#line 54 "hi.y"
	{
				const node_info& VP=sparser->get_node_info(yystack.l_mark[0]);
				std::cout<<"S->VP"<<std::endl;
				return 0;
}
break;
case 2:
#line 60 "hi.y"
	{
				lexicon word;

				const node_info& Vbar1=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="VP";
				yyval=sparser->set_node_info(word,Vbar1);
				std::cout<<"VP->Vbar1"<<std::endl;
}
break;
case 3:
#line 69 "hi.y"
	{
				const node_info& Vbar1=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& AdvP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("VP",Vbar1,AdvP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"VP->Vbar1 AdvP"<<std::endl;
}
break;
case 4:
#line 81 "hi.y"
	{
				lexicon word;

				const node_info& Vbar2=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="VP";
				yyval=sparser->set_node_info(word,Vbar2);
				std::cout<<"VP->Vbar2"<<std::endl;
}
break;
case 5:
#line 90 "hi.y"
	{
				const node_info& Vbar2=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& PP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("VP",Vbar2,PP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"VP->Vbar2 PP"<<std::endl;
}
break;
case 6:
#line 102 "hi.y"
	{
				const node_info& Vbar3=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& NP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("VP",Vbar3,NP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"VP->Vbar3 NP"<<std::endl;
}
break;
case 7:
#line 114 "hi.y"
	{
				const node_info& V=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& AdvP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("VBAR3",V,AdvP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"Vbar3->V AdvP"<<std::endl;
}
break;
case 8:
#line 126 "hi.y"
	{
				const node_info& Vbar1=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& PP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("VBAR2",Vbar1,PP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"Vbar2->Vbar1 PP"<<std::endl;
}
break;
case 9:
#line 138 "hi.y"
	{
				const node_info& Vbar1=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& NP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("VBAR2",Vbar1,NP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"Vbar2->Vbar1 NP"<<std::endl;
}
break;
case 10:
#line 150 "hi.y"
	{
				const node_info& V=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& NP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("VBAR1",V,NP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"Vbar1->V NP"<<std::endl;
}
break;
case 11:
#line 162 "hi.y"
	{
				const node_info& Prep=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& NP=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->combine_nodes("PP",Prep,NP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Prep->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"PP->Prep NP"<<std::endl;
}
break;
case 12:
#line 174 "hi.y"
	{
				lexicon word;

				const node_info& CNP=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="NP";
				yyval=sparser->set_node_info(word,CNP);
				std::cout<<"NP->CNP"<<std::endl;
}
break;
case 13:
#line 183 "hi.y"
	{
				const node_info& Det=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& CNP=sparser->get_node_info(yystack.l_mark[0]);
				/*	TODO: really need to check if there's a constant ?
					Currently, it's done to make functor argument diff easier.*/
				/*const node_info& object_node=sparser->get_node_info(sparser->get_object_node(CNP));
				if(object_node.right_child!=0){
					//printf("Syntax error: constants like %s cannot be quantified!\n",sparser->get_node_info(object_node.right_child).expression.c_str());
					return -1;
				}*/
				yyval=sparser->combine_nodes("NP",Det,CNP);
				/* No check for $$<0 since quantifier pronouns are not validated as
				 * everything in the current model seems to be countable.*/
				std::cout<<"NP->QPro CNP:"<<Det.expression.lexeme<<std::endl;
}
break;
case 14:
#line 203 "hi.y"
	{
				const node_info& A=sparser->get_node_info(yystack.l_mark[-1]);
				const node_info& CNP=sparser->get_node_info(yystack.l_mark[0]);
				/*TODO: ellenõrizni, hogy ha a CNP paraméteres akkor hiba mint a QPro CNP-nál!*/
				yyval=sparser->combine_nodes("CNP",A,CNP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"CNP->A CNP:"<<A.expression.lexeme<<std::endl;
}
break;
case 15:
#line 216 "hi.y"
	{
				lexicon word;

				const node_info& N=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="CNP";
				yyval=sparser->set_node_info(word,N);
				std::cout<<"CNP->N:"<<N.expression.lexeme<<std::endl;
}
break;
case 16:
#line 225 "hi.y"
	{
				lexicon word;

				const node_info& Adv=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="ADVP";
				yyval=sparser->set_node_info(word,Adv);
				std::cout<<"AdvP->Adv:"<<Adv.expression.lexeme<<std::endl;
}
break;
case 17:
#line 234 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiLIST-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 18:
#line 243 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiALL-1);
				/*TODO: consider what if quantifiers like ALL are handled as functors?*/
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 19:
#line 253 "hi.y"
	{
				lexicon word;
	
				word=lex->get_word_by_token(hiFILE-1);
				const node_info& Con=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->set_node_info(word,Con);
				std::cout<<word.gcat<<"->"<<word.lexeme<<" "<<Con.expression.lexeme<<std::endl;
}
break;
case 20:
#line 262 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiFILES-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 21:
#line 271 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiDIRECTORY-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 22:
#line 280 "hi.y"
	{
				lexicon word;

				word=lex->get_word_by_token(hiDIRECTORY-1);
				const node_info& Con=sparser->get_node_info(yystack.l_mark[0]);
				yyval=sparser->set_node_info(word,Con);
				std::cout<<word.gcat<<"->"<<word.lexeme<<" "<<Con.expression.lexeme<<std::endl;
}
break;
case 23:
#line 289 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiDIRECTORIES-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 24:
#line 298 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiCOMPUTER-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 25:
#line 307 "hi.y"
	{
				lexicon word;

				const node_info& Con=sparser->get_node_info(yystack.l_mark[0]);
				word.gcat="N";
				yyval=sparser->set_node_info(word,Con);
				std::cout<<"N->"<<Con.expression.lexeme<<std::endl;
}
break;
case 26:
#line 316 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiEXECUTABLE-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 27:
#line 325 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiNONEXECUTABLE-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 28:
#line 334 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiTO-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 29:
#line 343 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiFROM-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 30:
#line 352 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiIN-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 31:
#line 365 "hi.y"
	{
				const node_info empty_node_info={};
				lexicon word;

				const std::string& constant=lex->last_word_scanned();
				word.gcat="CON";
				word.lexeme=constant;
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<"Constant:"<<constant<<std::endl;
}
break;
case 32:
#line 376 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiDOWN-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 33:
#line 385 "hi.y"
	{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiTHE-1);
				yyval=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
#line 939 "y.tab.c"
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
