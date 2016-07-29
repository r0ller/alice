/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "../hi.y" /* yacc.c:339  */

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
	#include "tokenpaths.cpp"
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
	#include "transgraph.cpp"
	void yyerror(char const *yymsgp);

#line 97 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    t_Con = 1,
    t_ENG_A = 2,
    t_ENG_Adv = 3,
    t_ENG_Det = 4,
    t_ENG_N_stem = 5,
    t_ENG_N_lfea_Pl = 6,
    t_ENG_N_lfea_Sg = 7,
    t_ENG_Prep = 8,
    t_ENG_QPro = 9,
    t_ENG_V_stem = 10,
    t_ENG_V_lfea_aux = 11,
    t_ENG_RPro_stem = 12,
    t_ENG_RPro_lfea_relative = 13,
    t_ENG_Neg = 14,
    t_HUN_Con_lfea_Acc = 15,
    t_HUN_Verb_stem = 16,
    t_HUN_Verb_lfea_ConjDefSg2 = 17,
    t_HUN_Vbpfx = 18,
    t_ENG_Tense_particle = 19,
    t_ENG_Indef = 20,
    t_ENG_fwVowel = 21,
    t_ENG_fwConsonant = 22,
    t_ENG_swVowel = 23,
    t_ENG_swConsonant = 24,
    t_ENG_V_lfea_ger = 25
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 173 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   113

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    73,    78,    87,    94,   103,   110,   117,
     124,   131,   151,   159,   167,   174,   181,   188,   195,   203,
     211,   219,   226,   235,   244,   255,   262,   271,   280,   289,
     296,   303,   312,   322,   331,   340,   349,   358,   365,   372,
     379,   386,   393,   400,   407,   416,   425,   434,   441,   448,
     455,   467,   474,   481,   490,   499,   506,   513,   522,   529,
     538,   548,   558,   567,   574,   581,   594,   604,   613,   620,
     629,   648,   657,   664,   680,   687,   696,   703,   710,   717,
     726,   735,   744,   753,   762,   772,   779,   786,   794,   804,
     813,   822,   831,   840,   849,   858,   865,   872,   879,   886,
     893,   903
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "t_Con", "t_ENG_A", "t_ENG_Adv",
  "t_ENG_Det", "t_ENG_N_stem", "t_ENG_N_lfea_Pl", "t_ENG_N_lfea_Sg",
  "t_ENG_Prep", "t_ENG_QPro", "t_ENG_V_stem", "t_ENG_V_lfea_aux",
  "t_ENG_RPro_stem", "t_ENG_RPro_lfea_relative", "t_ENG_Neg",
  "t_HUN_Con_lfea_Acc", "t_HUN_Verb_stem", "t_HUN_Verb_lfea_ConjDefSg2",
  "t_HUN_Vbpfx", "t_ENG_Tense_particle", "t_ENG_Indef", "t_ENG_fwVowel",
  "t_ENG_fwConsonant", "t_ENG_swVowel", "t_ENG_swConsonant",
  "t_ENG_V_lfea_ger", "$accept", "S", "ENG_VP", "ENG_IVP", "ENG_NV",
  "ENG_Vbar3", "ENG_Vbar2", "ENG_Vbar1", "ENG_Vbar4", "ENG_PP", "ENG_NP",
  "ENG_CNP", "ENG_AdvP", "ENG_V", "ENG_V_ger", "ENG_V_stem",
  "ENG_V_lfea_aux", "ENG_V_lfea_ger", "ENG_QPro", "ENG_N", "ENG_DP",
  "ENG_N_Sg_0Con", "ENG_N_Sg_0Con_swC", "ENG_N_Sg_0Con_swV", "ENG_N_Sg",
  "ENG_N_Pl_0Con", "ENG_N_Pl_0Con_swC", "ENG_N_Pl_0Con_swV", "ENG_1Con",
  "ENG_nCon", "ENG_N_Pl", "ENG_N_Stem", "ENG_N_lfea_Sg", "ENG_N_lfea_Pl",
  "ENG_A", "ENG_AP", "ENG_Prep", "ENG_Con", "ENG_Adv", "ENG_RPro",
  "ENG_RPro_stem", "ENG_RPro_lfea_relative", "ENG_Tense_particle",
  "ENG_TP", "ENG_RC", "ENG_NEG", "ENG_Indef_Det_an", "ENG_Indef_Det_a",
  "ENG_Indef_Det", "ENG_Det_stem", "ENG_lfea_IndefDet", "ENG_lfea_fwVowel",
  "ENG_lfea_fwConsonant", "ENG_lfea_swVowel", "ENG_lfea_swConsonant",
  "HUN_VP", "HUN_ImpVerbPfx", "HUN_ImpVerb", "HUN_Verb_lfea_ConjDefSg2",
  "HUN_Verb_stem", "HUN_Vbpfx", "HUN_NP", "HUN_N", "HUN_N_Sg", "HUN_1Con",
  "HUN_nCon", "HUN_AccCon", "HUN_Con", "HUN_Con_lfea_Acc", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25
};
# endif

#define YYPACT_NINF -41

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-41)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,   -41,   -41,   -41,   -41,    14,   -41,    48,    56,    43,
      15,    13,   -41,    -2,    17,    17,    17,    34,    34,    54,
      22,   -41,    55,    29,    41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,    58,   -41,    46,    80,    80,    80,    46,    80,
      80,    66,    80,   -41,    71,    58,   -41,   -41,   -41,   -41,
     -41,    48,    17,    69,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,    72,
     -41,   -41,    61,   -41,    78,    62,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,     9,     9,    55,
     -41,   -41,   -41,   -41,   -41,   -41,    80,   -41,   -41,   -41,
     -41,   -41,   -41,    80,    80,   -41,   -41,    80,    80,   -41,
     -41,    81,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,    82,    27,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    79,    31,    89,    71,     0,     2,     0,     6,     4,
       0,     0,    73,    28,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     1,    66,    62,    59,    34,
       8,    22,     0,    26,     0,    45,    46,    35,     0,    53,
      54,    44,    57,    36,     0,     0,    23,    50,    65,    69,
       7,     0,     0,     0,    10,    67,    16,    17,     5,    27,
       9,    11,    18,    15,    32,    33,    29,    30,    19,    28,
      72,    20,     0,    38,     0,     0,    37,    81,    82,    76,
      77,    80,    78,   100,    85,    91,    92,     0,     0,    93,
      94,    90,    86,    88,    87,    24,    44,    83,    84,    41,
      40,    42,    43,     0,    58,    49,    48,    55,    56,    63,
      64,     0,    51,    52,    61,    60,    39,    47,    25,    21,
      74,     0,     0,    70,    68,   101,    95,    98,    96,    99,
      97,    13,    75,    12,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,    -9,
      -6,   -17,    79,   -10,   -41,     8,   -41,   -41,   -41,   -41,
      83,    64,    73,    77,   -41,   -41,    57,    59,    -5,    -1,
     -41,    -8,   -41,   -41,   -41,   -41,   -41,   -40,   -41,   -41,
     -41,   -41,   -41,   -41,    86,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,    63,    65,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -13,    11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,   120,   121,     7,     8,     9,    10,    50,
      30,    31,    58,    11,    12,    69,    66,    67,    32,    33,
      14,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,   116,   117,    45,    46,    51,    47,    59,    52,
      53,   124,    15,    16,    54,   134,    17,    18,    19,    20,
      82,    79,    80,    99,   100,    21,    22,    23,    94,    24,
      92,    84,    85,    86,    87,    88,    89,    90,   127
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,   112,   113,    57,    68,    62,    71,     1,    13,    74,
      74,    64,    83,     2,    25,    95,    26,    27,    55,     3,
      28,     1,     4,    70,    29,    65,   125,    96,   118,     2,
     101,   102,   103,   111,   103,   103,   104,    48,   107,   108,
      96,    28,   122,   132,    81,   119,    26,    27,    55,    91,
      28,    26,    27,    48,    29,    28,   112,    49,    83,    29,
      93,    26,    27,   112,   113,    28,    48,   113,   113,    26,
      49,    97,    98,    28,   126,   128,   130,    77,    78,   114,
     115,    72,    75,    26,   123,    64,    97,   115,    98,   114,
      63,    76,    48,    61,    73,    60,     0,     0,   109,   129,
     110,   105,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   133
};

static const yytype_int8 yycheck[] =
{
       9,    41,    42,     9,    14,    11,    16,     6,     0,    17,
      18,    13,     3,    12,     0,    32,     3,     4,     5,    18,
       7,     6,    21,    15,    11,    27,    17,    32,    45,    12,
      35,    36,    37,    41,    39,    40,    37,    10,    39,    40,
      45,     7,    52,    16,    22,    51,     3,     4,     5,    20,
       7,     3,     4,    10,    11,     7,    96,    14,     3,    11,
      19,     3,     4,   103,   104,     7,    10,   107,   108,     3,
      14,    25,    26,     7,    87,    88,    89,    23,    24,     8,
       9,    17,    18,     3,    15,    13,    25,     9,    26,     8,
      11,    18,    10,    10,    17,     9,    -1,    -1,    41,    88,
      41,    38,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    12,    18,    21,    29,    30,    33,    34,    35,
      36,    41,    42,    43,    48,    70,    71,    74,    75,    76,
      77,    83,    84,    85,    87,     0,     3,     4,     7,    11,
      38,    39,    46,    47,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    62,    63,    65,    10,    14,
      37,    64,    67,    68,    72,     5,    37,    38,    40,    66,
      72,    48,    38,    40,    13,    27,    44,    45,    41,    43,
      43,    41,    49,    51,    59,    49,    50,    23,    24,    79,
      80,    22,    78,     3,    89,    90,    91,    92,    93,    94,
      95,    20,    88,    19,    86,    39,    56,    25,    26,    81,
      82,    56,    56,    56,    57,    81,    82,    57,    57,    54,
      55,    59,    65,    65,     8,     9,    60,    61,    39,    38,
      31,    32,    41,    15,    69,    17,    95,    96,    95,    96,
      95,    37,    16,    37,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    29,    30,    30,    30,    30,    30,    30,
      30,    30,    31,    31,    32,    33,    34,    34,    35,    36,
      36,    37,    38,    38,    38,    39,    39,    40,    41,    41,
      42,    43,    44,    45,    46,    47,    47,    48,    48,    49,
      50,    51,    52,    52,    52,    52,    52,    53,    54,    55,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    59,
      60,    61,    62,    63,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    93,    93,    94,    94,
      95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     2,     2,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     2,     2,     2,
       1,     2,     2,     1,     1,     2,     2,     1,     2,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     2,     1,
       1,     1,     2,     1,     2,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 69 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_VP=sparser->get_node_info((yyvsp[0]));
				std::cout<<"S->ENG_VP"<<std::endl;
}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_VP=sparser->get_node_info((yyvsp[0]));
				std::cout<<"S->HUN_VP"<<std::endl;
}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 79 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_VP";
				(yyval)=sparser->set_node_info(word,ENG_Vbar1);
				std::cout<<"ENG_VP->ENG_Vbar1"<<std::endl;
}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 88 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_AdvP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);
				std::cout<<"ENG_VP->ENG_Vbar1 ENG_AdvP"<<std::endl;
}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_VP";
				(yyval)=sparser->set_node_info(word,ENG_Vbar2);
				std::cout<<"ENG_VP->ENG_Vbar2"<<std::endl;
}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 104 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);
				std::cout<<"ENG_VP->ENG_Vbar2 ENG_PP"<<std::endl;
}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 111 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar3=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);
				std::cout<<"ENG_VP->ENG_Vbar3 ENG_NP"<<std::endl;
}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 118 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_RC=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);
				std::cout<<"ENG_VP->ENG_Vbar1 ENG_RC"<<std::endl;
}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_RC=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);
				std::cout<<"ENG_VP->ENG_Vbar2 ENG_RC"<<std::endl;
}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 132 "../hi.y" /* yacc.c:1646  */
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
				const node_info& ENG_Vbar4=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_DP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);
				std::cout<<"ENG_VP->ENG_Vbar4 ENG_DP"<<std::endl;
}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 152 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
				sparser->add_feature_to_leaf(ENG_V,"RCV");
				(yyval)=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
				std::cout<<"ENG_IVP->ENG_V ENG_PP"<<std::endl;
}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 160 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_NV=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
				sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
				(yyval)=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
				std::cout<<"ENG_IVP->ENG_NV ENG_PP"<<std::endl;
}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 168 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NEG=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_NV",ENG_V,ENG_NEG);
				std::cout<<"ENG_NV->ENG_V ENG_NEG"<<std::endl;
}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 175 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_AdvP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VBAR3",ENG_V,ENG_AdvP);
				std::cout<<"ENG_Vbar3->ENG_V ENG_AdvP"<<std::endl;
}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 182 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VBAR2",ENG_Vbar1,ENG_PP);
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_PP"<<std::endl;
}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 189 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VBAR2",ENG_Vbar1,ENG_NP);
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_NP"<<std::endl;
}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 196 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
				sparser->add_feature_to_leaf(ENG_V,"main_verb");
				(yyval)=sparser->combine_nodes("ENG_VBAR1",ENG_V,ENG_NP);
				std::cout<<"ENG_Vbar1->ENG_V ENG_NP"<<std::endl;
}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 204 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_DP=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_V=sparser->get_node_info((yyvsp[0]));
				sparser->add_feature_to_leaf(ENG_V,"main_verb");
				(yyval)=sparser->combine_nodes("ENG_VBAR4",ENG_V,ENG_DP);
				std::cout<<"ENG_Vbar4->ENG_DP ENG_V"<<std::endl;
}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 212 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_TP=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_V=sparser->get_node_info((yyvsp[0]));
				sparser->add_feature_to_leaf(ENG_V,"main_verb");
				(yyval)=sparser->combine_nodes("ENG_VBAR4",ENG_V,ENG_TP);
				std::cout<<"ENG_Vbar4->ENG_TP ENG_V"<<std::endl;
}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 220 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Prep=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);
				std::cout<<"ENG_PP->ENG_Prep ENG_NP"<<std::endl;
}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 227 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_NP";
				(yyval)=sparser->set_node_info(word,ENG_CNP);
				std::cout<<"ENG_NP->ENG_CNP"<<std::endl;
}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 236 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_AP=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_NP";
				(yyval)=sparser->set_node_info(word,ENG_AP);
				std::cout<<"ENG_NP->ENG_AP"<<std::endl;
}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 245 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_QPro=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);
				std::cout<<"ENG_NP->ENG_QPro ENG_CNP"<<std::endl;
}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 256 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_A=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_CNP",ENG_A,ENG_CNP);
				std::cout<<"ENG_CNP->ENG_A ENG_CNP"<<std::endl;
}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 263 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_CNP";
				(yyval)=sparser->set_node_info(word,ENG_N);
				std::cout<<"ENG_CNP->ENG_N"<<std::endl;
}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 272 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_Adv=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_AdvP";
				(yyval)=sparser->set_node_info(word,ENG_Adv);
				std::cout<<"ENG_AdvP->ENG_Adv"<<std::endl;
}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 281 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_V_Stem=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_V";
				(yyval)=sparser->set_node_info(word,ENG_V_Stem);
				std::cout<<"ENG_V->ENG_V_Stem"<<std::endl;
}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 290 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V_stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_V_lfea_aux=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_V",ENG_V_stem,ENG_V_lfea_aux);
				std::cout<<"ENG_V->ENG_V_stem ENG_V_lfea_aux"<<std::endl;
}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 297 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V_stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_V_lfea_ger=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_V",ENG_V_stem,ENG_V_lfea_ger);
				std::cout<<"ENG_V->ENG_V_stem ENG_V_lfea_ger"<<std::endl;
}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 304 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_V_stem);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 313 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_V_lfea_aux);
//				word.gcat="Aux";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 323 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_V_lfea_ger);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 332 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_QPro);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 341 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
	
				const node_info& ENG_N_Sg=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N";
				(yyval)=sparser->set_node_info(word,ENG_N_Sg);
				std::cout<<"ENG_N->ENG_N_Sg"<<std::endl;
}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 350 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N_Pl=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N";
				(yyval)=sparser->set_node_info(word,ENG_N_Pl);
				std::cout<<"ENG_N->ENG_N_Pl"<<std::endl;
}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 359 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Indef_Det_a=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);
				std::cout<<"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC"<<std::endl;
}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 366 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Indef_Det_an=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);
				std::cout<<"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV"<<std::endl;
}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 373 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_N_lfea_Sg=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Sg0Con",ENG_N_Stem,ENG_N_lfea_Sg);
				std::cout<<"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg"<<std::endl;
}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 380 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Sg_0Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_lfea_swConsonant=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);
				std::cout<<"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant"<<std::endl;
}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 387 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Sg_0Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_lfea_swVowel=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);
				std::cout<<"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel"<<std::endl;
}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 394 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("Sg",ENG_N_Sg_0Con_swC,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con"<<std::endl;
}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 401 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("Sg",ENG_N_Sg_0Con_swV,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con"<<std::endl;
}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 408 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[0]));
				word.gcat="Sg";
				(yyval)=sparser->set_node_info(word,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_1Con"<<std::endl;
}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 417 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info((yyvsp[0]));
				word.gcat="Sg";
				(yyval)=sparser->set_node_info(word,ENG_N_Sg_0Con_swC);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con_swC"<<std::endl;
}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 426 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info((yyvsp[0]));
				word.gcat="Sg";
				(yyval)=sparser->set_node_info(word,ENG_N_Sg_0Con_swV);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con_swV"<<std::endl;
}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 435 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_N_lfea_Pl=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);
				std::cout<<"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl"<<std::endl;
}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 442 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Pl_0Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_lfea_swConsonant=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);
				std::cout<<"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant"<<std::endl;
}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 449 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Pl_0Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_lfea_swVowel=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);
				std::cout<<"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel"<<std::endl;
}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 456 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_1Con";
				(yyval)=sparser->set_node_info(word,ENG_Con);
				//TODO: find out why printing ENG_Con.expression.lexeme leads to segfault
				//in case of "list directory abc" but not in case of "list abc"
				//std::cout<<"ENG_1Con->ENG_Con:"<<ENG_Con.expression.lexeme<<std::endl;
				std::cout<<"ENG_1Con->ENG_Con"<<std::endl;
}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 468 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);
				std::cout<<"ENG_nCon->ENG_1Con ENG_Con"<<std::endl;
}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 475 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_nCon=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);
				std::cout<<"ENG_nCon->ENG_nCon ENG_Con"<<std::endl;
}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 482 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N_Pl";
				(yyval)=sparser->set_node_info(word,ENG_N_Pl_0Con_swC);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con_swC"<<std::endl;
}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 491 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N_Pl";
				(yyval)=sparser->set_node_info(word,ENG_N_Pl_0Con_swV);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con_swV"<<std::endl;
}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 500 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_nCon=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon"<<std::endl;
}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 507 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_nCon=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon"<<std::endl;
}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 514 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_nCon=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N_Pl";
				(yyval)=sparser->set_node_info(word,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_nCon"<<std::endl;
}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 523 "../hi.y" /* yacc.c:1646  */
    {
				//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
				//that a singular noun cannot combine with more than one constant like in 'list file abc def'
				//TODO: Any better solution???
				return -1;
}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 530 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_N_stem);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 539 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_N_lfea_Sg);
//				word.gcat="ENG_N_lfea_Sg";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 549 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_N_lfea_Pl);
//				word.gcat="ENG_N_lfea_Pl";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 559 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_A);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 568 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_AP",ENG_1Con,ENG_N_Pl_0Con_swC);
				std::cout<<"ENG_AP->ENG_1Con ENG_N_Pl_0Con_swC"<<std::endl;
}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 575 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_AP",ENG_1Con,ENG_N_Pl_0Con_swV);
				std::cout<<"ENG_AP->ENG_1Con ENG_N_Pl_0Con_swV"<<std::endl;
}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 582 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_Prep);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 595 "../hi.y" /* yacc.c:1646  */
    {
				const node_info empty_node_info={};
				lexicon word;

				word=lex->last_word_scanned(t_Con);
//				word.gcat="CON";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<"Constant:"<<word.word<<std::endl;
}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 605 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_Adv);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 614 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_RPro_stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_RPro_lfea_relative=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_RPRO",ENG_RPro_stem,ENG_RPro_lfea_relative);
				std::cout<<"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative"<<std::endl;
}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 621 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_RPro_stem);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 630 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_RPro_lfea_relative);
//				word.gcat="Relative";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 649 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_Tense_particle);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 658 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Tense_particle=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_V_stem=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_stem);
				std::cout<<"ENG_TP->ENG_Tense_particle ENG_V_stem"<<std::endl;
}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 665 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_V_ger=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_V_ger";
				(yyval)=sparser->set_node_info(word,ENG_V_ger);
				std::cout<<"ENG_TP->ENG_V_ger"<<std::endl;
}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 681 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_RPro=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_IVP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);
				std::cout<<"ENG_RC->ENG_RPro ENG_IVP"<<std::endl;
}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 688 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_ENG_Neg);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 697 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Indef_Det=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_lfea_fwVowel=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);
				std::cout<<"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel"<<std::endl;
}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 704 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Indef_Det=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_lfea_fwConsonant=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);
				std::cout<<"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant"<<std::endl;
}
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 711 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Det_stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_lfea_IndefDet=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);
				std::cout<<"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet"<<std::endl;
}
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 718 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_Det);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 727 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_Indef);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 736 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_fwVowel);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 745 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_fwConsonant);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 754 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_swVowel);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 763 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned(t_ENG_swConsonant);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 773 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_ImpVerbPfx=sparser->get_node_info((yyvsp[-1]));
				const node_info& HUN_NP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_NP);
				std::cout<<"HUN_VP->HUN_ImpVerbPfx HUN_NP"<<std::endl;
}
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 780 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_ImpVerb=sparser->get_node_info((yyvsp[-1]));
				const node_info& HUN_Vbpfx=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("HUN_ImpVerbPfx",HUN_ImpVerb,HUN_Vbpfx);
				std::cout<<"HUN_ImpVerbPfx->HUN_ImpVerb HUN_Vbpfx"<<std::endl;
}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 787 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_Verb_stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info((yyvsp[0]));
				sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
				(yyval)=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);
				std::cout<<"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2"<<std::endl;
}
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 795 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_HUN_Verb_lfea_ConjDefSg2);
//				word.gcat="ConjDefSg2";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 805 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_HUN_Verb_stem);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 814 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_HUN_Vbpfx);
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 823 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& HUN_NP=sparser->get_node_info((yyvsp[0]));
				word.gcat="HUN_NP";
				(yyval)=sparser->set_node_info(word,HUN_NP);
				std::cout<<"HUN_NP->HUN_N"<<std::endl;
}
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 832 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& HUN_N_Sg=sparser->get_node_info((yyvsp[0]));
				word.gcat="HUN_N";
				(yyval)=sparser->set_node_info(word,HUN_N_Sg);
				std::cout<<"HUN_N->HUN_N_Sg"<<std::endl;
}
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 841 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& HUN_AccCon=sparser->get_node_info((yyvsp[0]));
				word.gcat="Sg";
				(yyval)=sparser->set_node_info(word,HUN_AccCon);
				std::cout<<"HUN_N_Sg->HUN_AccCon"<<std::endl;
}
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 850 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& HUN_Con=sparser->get_node_info((yyvsp[0]));
				word.gcat="HUN_1Con";
				(yyval)=sparser->set_node_info(word,HUN_Con);
				std::cout<<"HUN_1Con->HUN_Con:"<<HUN_Con.expression.lexeme<<std::endl;
}
#line 2727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 859 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_1Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& HUN_Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("HUN_nCon",HUN_1Con,HUN_Con);
				std::cout<<"HUN_nCon->HUN_1Con HUN_Con"<<std::endl;
}
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 866 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_nCon=sparser->get_node_info((yyvsp[-1]));
				const node_info& HUN_Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("HUN_nCon",HUN_nCon,HUN_Con);
				std::cout<<"HUN_nCon->HUN_nCon HUN_Con"<<std::endl;
}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 873 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_AccCon=sparser->get_node_info((yyvsp[-1]));
				const node_info& HUN_Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("HUN_nCon",HUN_AccCon,HUN_Con);
				std::cout<<"HUN_nCon->HUN_AccCon HUN_Con"<<std::endl;
}
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 880 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_1Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& HUN_Con_lfea_Acc=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("HUN_AccCon",HUN_1Con,HUN_Con_lfea_Acc);
				std::cout<<"HUN_AccCon->HUN_1Con HUN_Con_lfea_Acc"<<std::endl;
}
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 887 "../hi.y" /* yacc.c:1646  */
    {
				const node_info& HUN_nCon=sparser->get_node_info((yyvsp[-1]));
				const node_info& HUN_Con_lfea_Acc=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("HUN_AccCon",HUN_nCon,HUN_Con_lfea_Acc);
				std::cout<<"HUN_AccCon->HUN_nCon HUN_Con_lfea_Acc"<<std::endl;
}
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 894 "../hi.y" /* yacc.c:1646  */
    {
				const node_info empty_node_info={};
				lexicon word;

				word=lex->last_word_scanned(t_Con);
//				word.gcat="CON";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<"Konstans:"<<word.word<<std::endl;
}
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 904 "../hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned(t_HUN_Con_lfea_Acc);
//				word.gcat="HUN_Con_lfea_Acc";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2814 "y.tab.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 913 "../hi.y" /* yacc.c:1906  */


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
					std::cout<<commandstr<<std::endl;
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
