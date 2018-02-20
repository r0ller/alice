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
#line 1 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:339  */

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

#line 103 "y.tab.c" /* yacc.c:339  */

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
    t_ENG_A_Stem = 2,
    t_ENG_ADV = 3,
    t_ENG_DET = 4,
    t_ENG_N_Stem = 5,
    t_ENG_N_Pl = 6,
    t_ENG_N_Sg = 7,
    t_ENG_PREP = 8,
    t_ENG_QPRO = 9,
    t_ENG_V_Stem = 10,
    t_ENG_V_Aux = 11,
    t_ENG_RPRO = 12,
    t_ENG_RPRO_Relative = 13,
    t_ENG_NEG_Stem = 14,
    t_ENG_PAR = 19,
    t_ENG_DET_Indef = 20,
    t_ENG_DET_fwVowel = 21,
    t_ENG_DET_fwConsonant = 22,
    t_ENG_N_swVowel = 23,
    t_ENG_N_swConsonant = 24,
    t_ENG_V_Gerund = 25
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

#line 175 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

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
      12,    13,    14,    15,    16,     2,     2,     2,     2,    17,
      18,    19,    20,    21,    22,    23,     2,     2,     2,     2,
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
       0,    63,    63,    73,    83,    91,   100,   110,   120,   128,
     138,   147,   155,   164,   174,   182,   190,   198,   207,   216,
     225,   234,   243,   253,   263,   272,   281,   290,   299,   308,
     316,   325,   333,   340,   350,   359,   368,   377,   386,   395,
     403,   412,   421,   430,   439,   448,   458,   468,   478,   487,
     497,   507,   516,   525,   535,   545,   553,   563,   573,   582,
     591,   600,   608,   616,   625,   633,   641,   649,   658,   668,
     677,   687,   697,   706,   714,   723,   732,   740,   749,   759,
     769,   779,   789,   799,   807,   816
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "t_Con", "t_ENG_A_Stem", "t_ENG_ADV",
  "t_ENG_DET", "t_ENG_N_Stem", "t_ENG_N_Pl", "t_ENG_N_Sg", "t_ENG_PREP",
  "t_ENG_QPRO", "t_ENG_V_Stem", "t_ENG_V_Aux", "t_ENG_RPRO",
  "t_ENG_RPRO_Relative", "t_ENG_NEG_Stem", "t_ENG_PAR", "t_ENG_DET_Indef",
  "t_ENG_DET_fwVowel", "t_ENG_DET_fwConsonant", "t_ENG_N_swVowel",
  "t_ENG_N_swConsonant", "t_ENG_V_Gerund", "$accept", "ENG_1Con", "ENG_A",
  "ENG_AP", "ENG_Adv", "ENG_AdvP", "ENG_CNP", "ENG_Con", "ENG_DP",
  "ENG_Det_stem", "ENG_IVP", "ENG_Indef_Det", "ENG_Indef_Det_a",
  "ENG_Indef_Det_an", "ENG_N", "ENG_NEG", "ENG_NP", "ENG_NV", "ENG_N_Pl",
  "ENG_N_Pl_0Con", "ENG_N_Pl_0Con_swC", "ENG_N_Pl_0Con_swV", "ENG_N_Sg",
  "ENG_N_Sg_0Con", "ENG_N_Sg_0Con_swC", "ENG_N_Sg_0Con_swV", "ENG_N_Stem",
  "ENG_N_lfea_Pl", "ENG_N_lfea_Sg", "ENG_PP", "ENG_Prep", "ENG_QPro",
  "ENG_RC", "ENG_RPro", "ENG_RPro_lfea_relative", "ENG_RPro_stem",
  "ENG_TP", "ENG_Tense_particle", "ENG_V", "ENG_VP", "ENG_V_Stem",
  "ENG_V_ger", "ENG_V_lfea_aux", "ENG_V_lfea_ger", "ENG_Vbar1",
  "ENG_Vbar2", "ENG_Vbar3", "ENG_Vbar4", "ENG_lfea_IndefDet",
  "ENG_lfea_fwConsonant", "ENG_lfea_fwVowel", "ENG_lfea_swConsonant",
  "ENG_lfea_swVowel", "ENG_nCon", "S", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    19,    20,    21,
      22,    23,    24,    25
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      34,   -57,   -57,   -57,    30,    26,     9,    51,    51,    30,
      30,    58,   -57,     1,   -57,    27,     3,    63,    54,    64,
     -57,    66,   -57,   -57,   -57,   -57,   -57,   -57,   -57,    59,
     -57,    71,    61,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
      40,     8,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
      31,    80,    80,    80,    31,    80,    80,    67,     8,    80,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,    63,
     -57,    30,    69,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,    77,    80,   -57,
     -57,   -57,    80,    80,    80,    80,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,     6,    23,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    68,    57,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    58,    56,    60,    63,     0,     0,     0,
      76,    58,    78,    18,    80,    79,    19,    20,    45,     0,
      11,     0,     0,    12,    77,    55,    10,     3,     6,    50,
      37,     0,    24,     7,    75,    25,     2,     9,    72,    21,
       0,    28,    30,    22,     0,    38,    40,     0,     0,    33,
      70,    71,    59,    69,    49,    54,    61,    73,    74,     0,
      62,     0,     0,    64,    65,    66,    67,     1,    81,    43,
      47,    42,    82,    44,    83,     4,     5,     0,    37,     8,
      35,    36,     0,    29,    31,    32,    39,    41,    46,    34,
      26,    84,    48,    51,     0,     0,    53,    52,    14,    15,
      23,    16,    27,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -33,   -56,   -57,   -57,    72,   -32,   -38,    68,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -10,   -57,   -57,   -57,
      50,    52,   -57,    70,    84,    85,    -4,   -57,   -57,   -16,
     -57,   -57,    78,   -57,   -57,   -57,   -57,   -57,    -3,   -57,
      35,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,    45,    46,    20,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    40,    41,    42,    43,    44,    45,    46,     4,     5,
     103,     6,     7,     8,    47,   112,    48,   104,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    99,    81,    68,
      69,    58,    70,    71,   107,    72,     9,    10,    11,    12,
      21,    14,    62,    63,    15,    16,    17,    18,    23,    26,
      27,    79,    83,    59,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      73,    20,    84,    31,    31,    67,    34,    75,    88,    89,
      37,    36,    37,    64,    60,    28,    64,    65,    92,    92,
      92,   101,    96,    97,    61,    88,   100,    37,    24,    25,
      36,    37,    38,    64,    28,    13,    87,    64,    39,   110,
       1,    65,     2,    36,    22,    35,     2,    28,   108,   111,
      84,     3,    82,    78,    84,   101,   101,   101,    28,   102,
       1,    36,    37,    38,    77,    28,    36,    37,   105,    39,
      28,    93,    94,    95,    39,    98,    80,    29,    32,    60,
      80,    78,    82,    36,   106,    98,    76,    66,   109,   113,
      85,    30,    86,    33,    74,    90,    91
};

static const yytype_uint8 yycheck[] =
{
      16,     4,    40,     7,     8,    15,     9,    17,    41,    41,
       4,     3,     4,    10,    13,     7,    10,    14,    51,    52,
      53,    59,    55,    56,    23,    58,    58,     4,    19,    20,
       3,     4,     5,    10,     7,     0,    40,    10,    11,    16,
       6,    14,    12,     3,    18,    10,    12,     7,   104,   105,
      88,    17,    21,    22,    92,    93,    94,    95,     7,    69,
       6,     3,     4,     5,     0,     7,     3,     4,    71,    11,
       7,    51,    52,    53,    11,     8,     9,     7,     8,    13,
       9,    22,    21,     3,    15,     8,    18,    15,   104,   105,
      40,     7,    40,     8,    16,    50,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    12,    17,    32,    33,    35,    36,    37,    60,
      61,    62,    63,    64,    65,    68,    69,    70,    71,    78,
      62,    64,    18,    72,    19,    20,    73,    74,     7,    47,
      48,    50,    47,    49,    62,    64,     3,     4,     5,    11,
      25,    26,    27,    28,    29,    30,    31,    38,    40,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    55,    77,
      13,    23,    66,    67,    10,    14,    29,    40,    53,    54,
      56,    57,    59,    53,    56,    40,    32,     0,    22,    75,
       9,    52,    21,    76,    31,    44,    45,    50,    25,    30,
      75,    76,    25,    77,    77,    77,    25,    25,     8,    51,
      30,    31,    40,    34,    41,    62,    15,    58,    26,    53,
      16,    26,    39,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    26,    27,    27,    28,    29,    30,    30,
      31,    32,    32,    33,    34,    34,    34,    34,    35,    36,
      37,    38,    38,    39,    40,    40,    40,    41,    42,    42,
      42,    42,    42,    42,    43,    44,    45,    46,    46,    46,
      46,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    60,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    65,
      66,    67,    68,    69,    69,    70,    71,    71,    72,    73,
      74,    75,    76,    77,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     2,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     2,     2,     1,     2,     2,     2,     1,     1,     2,
       1,     2,     2,     2,     2,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     1,     2,     1,     1,     1,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     1,     2,
       1,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     2,     2,     1
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
#line 64 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_1Con";
(yyval)=sparser->set_node_info(word,ENG_Con);
logger::singleton()->log(0,"ENG_1Con->ENG_Con");

}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_A_Stem);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 84 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_1Con=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_AP",ENG_1Con,ENG_N_Pl_0Con_swC);
logger::singleton()->log(0,"ENG_AP->ENG_1Con ENG_N_Pl_0Con_swC");

}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 92 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_1Con=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_AP",ENG_1Con,ENG_N_Pl_0Con_swV);
logger::singleton()->log(0,"ENG_AP->ENG_1Con ENG_N_Pl_0Con_swV");

}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_ADV);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_Adv=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_AdvP";
(yyval)=sparser->set_node_info(word,ENG_Adv);
logger::singleton()->log(0,"ENG_AdvP->ENG_Adv");

}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_A=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_CNP",ENG_A,ENG_CNP);
logger::singleton()->log(0,"ENG_CNP->ENG_A ENG_CNP");

}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 129 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_N=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_CNP";
(yyval)=sparser->set_node_info(word,ENG_N);
logger::singleton()->log(0,"ENG_CNP->ENG_N");

}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 139 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_Con);
(yyval)=sparser->set_node_info(word,empty_node_info);
std::cout<<"Constant:"<<word.word<<std::endl;
}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Indef_Det_a=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);
logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC");

}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 156 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Indef_Det_an=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);
logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV");

}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 165 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 175 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_NV=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_A=sparser->get_node_info((yyvsp[0]));
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
(yyval)=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_A);
std::cout<<"ENG_IVP->ENG_NV ENG_A"<<std::endl;
}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 183 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_NV=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
(yyval)=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
std::cout<<"ENG_IVP->ENG_NV ENG_PP"<<std::endl;
}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 191 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_A=sparser->get_node_info((yyvsp[0]));
sparser->add_feature_to_leaf(ENG_V,"RCV");
(yyval)=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_A);
std::cout<<"ENG_IVP->ENG_V ENG_A"<<std::endl;
}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
sparser->add_feature_to_leaf(ENG_V,"RCV");
(yyval)=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
std::cout<<"ENG_IVP->ENG_V ENG_PP"<<std::endl;
}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 208 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Det_stem=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_lfea_IndefDet=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);
logger::singleton()->log(0,"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet");

}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 217 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Indef_Det=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_lfea_fwConsonant=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);
logger::singleton()->log(0,"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant");

}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 226 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Indef_Det=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_lfea_fwVowel=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);
logger::singleton()->log(0,"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel");

}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 235 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_N_Pl=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_N";
(yyval)=sparser->set_node_info(word,ENG_N_Pl);
logger::singleton()->log(0,"ENG_N->ENG_N_Pl");

}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 244 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_N_Sg=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_N";
(yyval)=sparser->set_node_info(word,ENG_N_Sg);
logger::singleton()->log(0,"ENG_N->ENG_N_Sg");

}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 254 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_NEG_Stem);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 264 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_AP=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_NP";
(yyval)=sparser->set_node_info(word,ENG_AP);
logger::singleton()->log(0,"ENG_NP->ENG_AP");

}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 273 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_NP";
(yyval)=sparser->set_node_info(word,ENG_CNP);
logger::singleton()->log(0,"ENG_NP->ENG_CNP");

}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 282 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_QPro=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);
logger::singleton()->log(0,"ENG_NP->ENG_QPro ENG_CNP");

}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 291 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_NEG=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_NV",ENG_V,ENG_NEG);
logger::singleton()->log(0,"ENG_NV->ENG_V ENG_NEG");

}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 300 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_N_Pl";
(yyval)=sparser->set_node_info(word,ENG_N_Pl_0Con_swC);
logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC");

}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 309 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_nCon=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);
logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon");

}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 317 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_N_Pl";
(yyval)=sparser->set_node_info(word,ENG_N_Pl_0Con_swV);
logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV");

}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 326 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_nCon=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);
logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon");

}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 334 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in 'list file abc def'
//TODO: Any better solution???
return -1;
}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 341 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_nCon=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_N_Pl";
(yyval)=sparser->set_node_info(word,ENG_nCon);
logger::singleton()->log(0,"ENG_N_Pl->ENG_nCon");

}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 351 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Stem=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_N_lfea_Pl=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);
logger::singleton()->log(0,"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl");

}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 360 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Pl_0Con=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_lfea_swConsonant=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);
logger::singleton()->log(0,"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant");

}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 369 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Pl_0Con=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_lfea_swVowel=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);
logger::singleton()->log(0,"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel");

}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 378 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_1Con=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_N_Sg";
(yyval)=sparser->set_node_info(word,ENG_1Con);
logger::singleton()->log(0,"ENG_N_Sg->ENG_1Con");

}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 387 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_N_Sg";
(yyval)=sparser->set_node_info(word,ENG_N_Sg_0Con_swC);
logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC");

}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 396 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_1Con=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swC,ENG_1Con);
logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con");

}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 404 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_N_Sg";
(yyval)=sparser->set_node_info(word,ENG_N_Sg_0Con_swV);
logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV");

}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 413 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_1Con=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swV,ENG_1Con);
logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con");

}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 422 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Stem=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_N_lfea_Sg=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Sg_0Con",ENG_N_Stem,ENG_N_lfea_Sg);
logger::singleton()->log(0,"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg");

}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 431 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Sg_0Con=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_lfea_swConsonant=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);
logger::singleton()->log(0,"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant");

}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 440 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_N_Sg_0Con=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_lfea_swVowel=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);
logger::singleton()->log(0,"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel");

}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 449 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Stem);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 459 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Pl);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 469 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_Sg);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 479 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Prep=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);
logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");

}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 488 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_PREP);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 498 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_QPRO);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 508 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_RPro=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_IVP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);
logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVP");

}
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 517 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_RPro_stem=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_RPro_lfea_relative=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_RPro",ENG_RPro_stem,ENG_RPro_lfea_relative);
logger::singleton()->log(0,"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative");

}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 526 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_RPRO_Relative);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 536 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_RPRO);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 546 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Tense_particle=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_V_Stem=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_Stem);
logger::singleton()->log(0,"ENG_TP->ENG_Tense_particle ENG_V_Stem");

}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 554 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_V_ger=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_TP";
(yyval)=sparser->set_node_info(word,ENG_V_ger);
logger::singleton()->log(0,"ENG_TP->ENG_V_ger");

}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 564 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_PAR);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 574 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_V_Stem=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_V";
(yyval)=sparser->set_node_info(word,ENG_V_Stem);
logger::singleton()->log(0,"ENG_V->ENG_V_Stem");

}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 583 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_V_Stem=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_V_lfea_aux=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_V",ENG_V_Stem,ENG_V_lfea_aux);
logger::singleton()->log(0,"ENG_V->ENG_V_Stem ENG_V_lfea_aux");

}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 592 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_VP";
(yyval)=sparser->set_node_info(word,ENG_Vbar1);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar1");

}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 601 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_AdvP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");

}
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 609 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_RC=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_RC");

}
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 617 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[0]));
word.gcat="ENG_VP";
(yyval)=sparser->set_node_info(word,ENG_Vbar2);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar2");

}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 626 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_PP");

}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 634 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_RC=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_RC");

}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 642 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Vbar3=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar3 ENG_NP");

}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 650 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Vbar4=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_DP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);
logger::singleton()->log(0,"ENG_VP->ENG_Vbar4 ENG_DP");

}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 659 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Stem);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 669 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_V_Stem=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_V_lfea_ger=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_V_ger",ENG_V_Stem,ENG_V_lfea_ger);
logger::singleton()->log(0,"ENG_V_ger->ENG_V_Stem ENG_V_lfea_ger");

}
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 678 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Aux);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 688 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_V_Gerund);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 698 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
sparser->add_feature_to_leaf(ENG_V,"main_verb");
(yyval)=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
std::cout<<"ENG_Vbar1->ENG_V ENG_NP"<<std::endl;
}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 707 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);
logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_NP");

}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 715 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_PP);
logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_PP");

}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 724 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_AdvP=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_Vbar3",ENG_V,ENG_AdvP);
logger::singleton()->log(0,"ENG_Vbar3->ENG_V ENG_AdvP");

}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 733 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_DP=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_V=sparser->get_node_info((yyvsp[0]));
sparser->add_feature_to_leaf(ENG_V,"main_verb");
(yyval)=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
std::cout<<"ENG_Vbar4->ENG_DP ENG_V"<<std::endl;
}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 741 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_TP=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_V=sparser->get_node_info((yyvsp[0]));
sparser->add_feature_to_leaf(ENG_V,"main_verb");
(yyval)=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
std::cout<<"ENG_Vbar4->ENG_TP ENG_V"<<std::endl;
}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 750 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_Indef);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 760 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_fwConsonant);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 770 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_DET_fwVowel);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 780 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_swConsonant);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 790 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& empty_node_info={};
word=lex->last_word_scanned(t_ENG_N_swVowel);
(yyval)=sparser->set_node_info(word,empty_node_info);
logger::singleton()->log(0,word.gcat+"->"+word.lexeme);

}
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 800 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_1Con=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);
logger::singleton()->log(0,"ENG_nCon->ENG_1Con ENG_Con");

}
#line 2590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 808 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
const node_info& ENG_nCon=sparser->get_node_info((yyvsp[-1]));
const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
(yyval)=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);
logger::singleton()->log(0,"ENG_nCon->ENG_nCon ENG_Con");

}
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 817 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1646  */
    {
lexicon word;
const node_info& ENG_VP=sparser->get_node_info((yyvsp[0]));
word.gcat="S";
(yyval)=sparser->set_node_info(word,ENG_VP);
logger::singleton()->log(0,"S->ENG_VP");

}
#line 2615 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2619 "y.tab.c" /* yacc.c:1646  */
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
#line 825 "/home/r0ller/hi/alice/hi_desktop/hi.y" /* yacc.c:1906  */

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

	logger=logger::singleton("console",3,"LE");//Don't forget to turn off log mode if necessary e.g. in android release versions
	logger::singleton()->log(0,"human_input:"+std::string(human_input));
	token_paths=new tokenpaths;
	while(human_input!=NULL&&toa!=0&&token_paths->is_any_left()==true){
		std::cout<<"picking new token path"<<std::endl;
		try{
			if(sqlite==NULL){
				#ifdef __ANDROID__
					if(vm!=NULL) jvm=vm;
					else{
						logger::singleton()->log(0,"vm is NULL!");
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
			logger::singleton()->log(0,"lexer started");
			sparser=new interpreter(toa);
			logger::singleton()->log(0,"interpreter started");
			if(toa&HI_SYNTAX||toa&HI_SEMANTICS){
				int parse_error=yyparse();
				if(parse_error==0){
					if(toa&HI_SEMANTICS){
						transgraph=sparser->longest_match_for_semantic_rules_found();
						if(transgraph!=NULL){
							token_paths->validate_parse_tree(sparser->nodes());
							token_paths->validate_path(lex->word_entries(),transgraph);
							logger::singleton()->log(0,"TRUE");
						}
						else{
							logger::singleton()->log(0,"semantic error");
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
					logger::singleton()->log(0,"syntax error");
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
