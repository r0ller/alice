#include <stdlib.h>
#ifndef lint
#if 0
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#else
#if defined(__NetBSD__) && defined(__IDSTRING)
__IDSTRING(yyrcsid, "$NetBSD: skeleton.c,v 1.29 2008/07/18 14:25:37 drochner Exp $");
#endif /* __NetBSD__ && __IDSTRING */
#endif /* 0 */
#endif /* lint */
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
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
	#include "db.cpp"
	#include "lexer.h"
	lexer *lex=NULL;
	#include "lexer.cpp"
	#include "sp.h"
	interpreter *sparser=NULL;
	#include "sp.cpp"
	int line=0;
#line 40 "y.tab.c"
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
#define YYERRCODE 256
const short yylhs[] = {                                        -1,
    0,    2,    2,    2,    4,    3,    5,    1,    1,    1,
    8,    8,    6,    6,    6,    6,    6,    6,    6,    9,
   12,   12,   12,   12,   12,   12,   11,   11,    7,    7,
    7,   10,   13,
};
const short yylen[] = {                                         2,
    2,    1,    1,    2,    2,    2,    2,    1,    2,    1,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    1,    1,    2,    1,    1,    1,    1,    1,    1,
    1,    0,    1,
};
const short yydefred[] = {                                      0,
   33,    0,   25,   27,   28,   20,    0,   22,    0,    0,
    8,    0,   10,    0,   12,   26,   24,   21,   13,   14,
   15,   16,   17,   18,   19,    1,    0,    0,    0,    9,
   11,   29,   30,   31,    5,    0,    4,    6,    7,
};
const short yydgoto[] = {                                       9,
   10,   26,   27,   28,   35,   29,   36,   11,   12,   13,
   14,   15,   16,
};
const short yysindex[] = {                                     42,
    0,   23,    0,    0,    0,    0,   23,    0,    0,   19,
    0,   52,    0,   52,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -9,   -9,   42,    0,
    0,    0,    0,    0,    0,   42,    0,    0,    0,
};
const short yyrindex[] = {                                     26,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   10,   30,    9,    0,
    0,    0,    0,    0,    0,    9,    0,    0,    0,
};
const short yygindex[] = {                                      0,
  -29,    0,    0,    0,    5,    0,    0,   13,    0,    0,
    0,    0,    4,
};
#define YYTABLESIZE 62
const short yytable[] = {                                      38,
   23,   32,   23,   23,   33,   17,   39,   34,   32,    2,
   18,   23,   23,   23,   23,   23,   23,   23,   23,   32,
   19,   20,   32,    1,   30,   32,   31,   32,   32,    3,
   21,   22,   37,   23,   24,    0,   25,   32,   32,    0,
   32,   32,    1,   32,    0,    2,    3,    4,    5,    6,
    7,    8,    1,    0,    0,    2,    3,    4,    5,    0,
    7,    8,
};
const short yycheck[] = {                                      29,
    0,   11,    2,    3,   14,    2,   36,   17,    0,    0,
    7,   11,   12,   13,   14,   15,   16,   17,   18,   11,
    2,    3,   14,    1,   12,   17,   14,    2,    3,    0,
   12,   13,   28,   15,   16,   -1,   18,   12,   13,   -1,
   15,   16,    1,   18,   -1,    4,    5,    6,    7,    8,
    9,   10,    1,   -1,   -1,    4,    5,    6,    7,   -1,
    9,   10,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 18
#if YYDEBUG
const char * const yyname[] = {
"end-of-file","hiCONSTANT","hiLIST","hiCOPY","hiDIRECTORY","hiDIRECTORIES",
"hiEXECUTABLE","hiNONEXECUTABLE","hiALL","hiFILE","hiFILES","hiTO","hiREMOVE",
"hiDELETE","hiFROM","hiCHANGE","hiMOVE","hiIN","hiMAKE",
};
const char * const yyrule[] = {
"$accept : S",
"S : NP VP",
"VP : Vt",
"VP : Vdt",
"VP : Vdt PP",
"Vdt : Vt PP",
"Vt : V NP",
"PP : Prep NP",
"NP : CNP",
"NP : QPro CNP",
"NP : Pro",
"CNP : A CNP",
"CNP : N",
"V : hiLIST",
"V : hiCOPY",
"V : hiREMOVE",
"V : hiDELETE",
"V : hiCHANGE",
"V : hiMOVE",
"V : hiMAKE",
"QPro : hiALL",
"N : hiFILE Con",
"N : hiFILES",
"N : hiDIRECTORY",
"N : hiDIRECTORY Con",
"N : hiDIRECTORIES",
"N : Con",
"A : hiEXECUTABLE",
"A : hiNONEXECUTABLE",
"Prep : hiTO",
"Prep : hiFROM",
"Prep : hiIN",
"Pro :",
"Con : hiCONSTANT",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
static YYSTYPE yyvalzero;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
int yyparse(void);
#line 339 "hi.y"

int yylex(void){
	int token;

	token=lex->next_token();
	if(token==0&&lex->last_word_scanned().empty()==true) return 0;//Historic indicator of YACC about end of input stream
	else return token+1;
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
			if(yyparse()==0)shell_command=sparser->get_command();
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
#line 276 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void);
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
    if ((newss = (short *)realloc(yyss, newsize * sizeof *newss)) == NULL)
        return -1;
    yyss = newss;
    yyssp = newss + i;
    if ((newvs = (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs)) == NULL)
        return -1;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != NULL)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
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
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
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
    goto yynewerror;
yynewerror:
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
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
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
        yychar = (-1);
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
        yyval = yyvsp[1-yym];
    else
        yyval = yyvalzero;
    switch (yyn)
    {
case 1:
#line 47 "hi.y"
{
				const node_info& VP=sparser->get_node_info(yyvsp[0]);
				std::cout<<"S->NP VP"<<std::endl;
				return 0;
}
break;
case 2:
#line 53 "hi.y"
{
				const node_info& Vt=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->set_node_info("VP","",Vt);
				std::cout<<"VP->Vt"<<std::endl;
}
break;
case 3:
#line 59 "hi.y"
{
				const node_info& Vdt=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->set_node_info("VP","",Vdt);
				std::cout<<"VP->Vdt"<<std::endl;
}
break;
case 4:
#line 65 "hi.y"
{
				const node_info& Vdt=sparser->get_node_info(yyvsp[-1]);
				const node_info& PP=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->combine_nodes("VP",Vdt,PP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"VP->Vdt PP"<<std::endl;
}
break;
case 5:
#line 77 "hi.y"
{
				const node_info& Vt=sparser->get_node_info(yyvsp[-1]);
				const node_info& PP=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->combine_nodes("Vdt",Vt,PP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"Vdt->Vt PP"<<std::endl;
}
break;
case 6:
#line 89 "hi.y"
{
				const node_info& V=sparser->get_node_info(yyvsp[-1]);
				const node_info& NP=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->combine_nodes("Vt",V,NP);
				if(yyval<0){
					/*object_node=sparser->get_object_node(NP);*/
					/*printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"Vt->V NP"<<std::endl;
}
break;
case 7:
#line 101 "hi.y"
{
				const node_info& Prep=sparser->get_node_info(yyvsp[-1]);
				const node_info& NP=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->combine_nodes("PP",Prep,NP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Prep->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"PP->Prep NP"<<std::endl;
}
break;
case 8:
#line 113 "hi.y"
{
				const node_info& CNP=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->set_node_info("NP","",CNP);
				std::cout<<"NP->CNP"<<std::endl;
}
break;
case 9:
#line 119 "hi.y"
{
				const node_info& Det=sparser->get_node_info(yyvsp[-1]);
				const node_info& CNP=sparser->get_node_info(yyvsp[0]);
				/*	TODO: really need to check if there's a constant ?
					Currently, it's done to make functor argument diff easier.*/
				const node_info& object_node=sparser->get_node_info(sparser->get_object_node(CNP));
				if(object_node.right_child!=0){
					/*printf("Syntax error: constants like %s cannot be quantified!\n",sparser->get_node_info(object_node.right_child).expression.c_str());*/
					return -1;
				}
				yyval=sparser->combine_nodes("NP",Det,CNP);
				/* No check for $$<0 since quantifier pronouns are not validated as
				 * everything in the current model seems to be countable.*/
				std::cout<<"NP->QPro CNP:"<<Det.expression<<std::endl;
}
break;
case 10:
#line 135 "hi.y"
{
				std::cout<<"NP->Pro"<<std::endl;
}
break;
case 11:
#line 139 "hi.y"
{
				const node_info& A=sparser->get_node_info(yyvsp[-1]);
				const node_info& CNP=sparser->get_node_info(yyvsp[0]);
				/*TODO: ellenőrizni, hogy ha a CNP paraméteres akkor hiba mint a QPro CNP-nél!*/
				yyval=sparser->combine_nodes("CNP",A,CNP);
				if(yyval<0){
					/*object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"CNP->A CNP:"<<A.expression<<std::endl;
}
break;
case 12:
#line 152 "hi.y"
{
				const node_info& N=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->set_node_info("CNP","",N);
				std::cout<<"CNP->N:"<<N.expression<<std::endl;
}
break;
case 13:
#line 158 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiLIST-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 14:
#line 167 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiCOPY-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 15:
#line 176 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiREMOVE-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 16:
#line 185 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiDELETE-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 17:
#line 194 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiCHANGE-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 18:
#line 203 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiMOVE-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 19:
#line 212 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiMAKE-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 20:
#line 221 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiALL-1);
				/*TODO: consider what if quantifiers like ALL are handled as functors?*/
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 21:
#line 231 "hi.y"
{
				lexicon word;
	
				word=lex->get_word_by_token(hiFILE-1);
				const node_info& Con=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,Con);
				std::cout<<word.gcat<<"->"<<word.lexeme<<" "<<Con.expression<<std::endl;
}
break;
case 22:
#line 240 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiFILES-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 23:
#line 249 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiDIRECTORY-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 24:
#line 258 "hi.y"
{
				lexicon word;

				word=lex->get_word_by_token(hiDIRECTORY-1);
				const node_info& Con=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,Con);
				std::cout<<word.gcat<<"->"<<word.lexeme<<" "<<Con.expression<<std::endl;
}
break;
case 25:
#line 267 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiDIRECTORIES-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 26:
#line 276 "hi.y"
{
				const node_info& Con=sparser->get_node_info(yyvsp[0]);
				yyval=sparser->set_node_info("N","",Con);
				std::cout<<"N->"<<Con.expression<<std::endl;
}
break;
case 27:
#line 282 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiEXECUTABLE-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 28:
#line 291 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};

				word=lex->get_word_by_token(hiNONEXECUTABLE-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 29:
#line 300 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiTO-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 30:
#line 309 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiFROM-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 31:
#line 318 "hi.y"
{
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->get_word_by_token(hiIN-1);
				yyval=sparser->set_node_info(word.gcat,word.lexeme,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
break;
case 32:
#line 327 "hi.y"
{
				std::cout<<"Pro->null"<<std::endl;
}
break;
case 33:
#line 331 "hi.y"
{
				const node_info empty_node_info={};

				const std::string& constant=lex->last_word_scanned();
				yyval=sparser->set_node_info("Con",constant,empty_node_info);
				std::cout<<"Constant:"<<constant<<std::endl;
}
break;
#line 802 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
