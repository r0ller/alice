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
#line 1 "hi.y" /* yacc.c:339  */

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
	#include "transgraph.cpp";
	int line=0;

#line 95 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
    t_ENG_Neg = 14
  };
#endif
/* Tokens.  */
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
#define t_ENG_V_lfea_aux 11
#define t_ENG_RPro_stem 12
#define t_ENG_RPro_lfea_relative 13
#define t_ENG_Neg 14

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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   57

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  17
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  68

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
      12,    13,    14,    15,    16,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    58,    67,    79,    88,   100,   112,   119,
     126,   139,   151,   163,   175,   187,   199,   211,   223,   232,
     252,   265,   274,   283,   292,   299,   308,   318,   328,   337,
     346,   358,   365,   374,   383,   395,   404,   416,   428,   437,
     449,   458,   465,   474,   490,   500,   509,   522,   532,   541,
     548,   557,   568,   576,   583,   590
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "t_Con", "t_ENG_A", "t_ENG_Adv",
  "t_ENG_Det", "t_ENG_N_stem", "t_ENG_N_lfea_Pl", "t_ENG_N_lfea_Sg",
  "t_ENG_Prep", "t_ENG_QPro", "t_ENG_V_stem", "t_ENG_V_lfea_aux",
  "t_ENG_RPro_stem", "t_ENG_RPro_lfea_relative", "t_ENG_Neg", "$accept",
  "S", "ENG_VP", "ENG_IVP", "ENG_NV", "ENG_Vbar3", "ENG_Vbar2",
  "ENG_Vbar1", "ENG_PP", "ENG_NP", "ENG_CNP", "ENG_AdvP", "ENG_V",
  "ENG_V_stem", "ENG_V_lfea_aux", "ENG_QPro", "ENG_N", "ENG_N_Sg_0Con",
  "ENG_N_Sg", "ENG_N_Pl_0Con", "ENG_1Con", "ENG_nCon", "ENG_N_Pl",
  "ENG_N_Stem", "ENG_N_lfea_Sg", "ENG_N_lfea_Pl", "ENG_A", "ENG_Prep",
  "ENG_Con", "ENG_Adv", "ENG_RPro", "ENG_RPro_stem",
  "ENG_RPro_lfea_relative", "ENG_T", "ENG_TP", "ENG_RC", "ENG_NEG", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14
};
# endif

#define YYPACT_NINF -21

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-21)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -8,   -21,    10,   -21,    13,    23,     4,    27,    31,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,    18,   -21,    20,    20,
      20,    20,    20,   -21,    34,    18,   -21,   -21,   -21,   -21,
      13,   -21,    30,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,    20,    20,    20,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,    -8,   -21,   -21,
     -21,   -21,    36,     3,   -21,   -21,   -21,   -21
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,     0,     2,     0,     5,     3,     0,    23,     1,
      47,    45,    42,    27,     7,    18,     0,    21,    33,    28,
      38,    32,    40,    29,     0,     0,    35,    46,    50,     6,
       0,    52,     0,     9,    48,    14,    15,     4,    22,     8,
      16,    13,    26,    24,    19,    31,     0,    41,    39,    36,
      37,    44,    43,    30,    34,    20,    17,     0,    54,    51,
      49,    53,     0,     0,    11,    55,    10,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,    -6,    -1,
     -13,    40,    -9,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
      21,    16,   -21,   -21,   -21,   -21,   -21,   -21,   -20,   -21,
     -21,   -21,   -21,   -21,   -21,    43,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    61,    62,     4,     5,     6,    29,    14,
      15,    37,     7,     8,    43,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    53,    54,    25,    30,    26,    38,
      31,    32,    60,    57,    58,    33,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    49,    50,    44,     1,    36,    40,    10,    11,    34,
       9,    12,    55,    27,    27,    13,    10,    11,    28,    65,
      12,    10,    11,    10,    13,    12,    49,    50,    50,    56,
      10,    11,    34,    27,    12,    47,    48,    28,    13,    45,
      46,    46,    51,    52,    42,    59,    27,    41,    63,    39,
       0,     0,     0,     0,     0,     0,    64,    66
};

static const yytype_int8 yycheck[] =
{
       6,    21,    22,    16,    12,     6,     7,     3,     4,     5,
       0,     7,    25,    10,    10,    11,     3,     4,    14,    16,
       7,     3,     4,     3,    11,     7,    46,    47,    48,    30,
       3,     4,     5,    10,     7,    19,    20,    14,    11,    18,
      19,    20,     8,     9,    13,    15,    10,     7,    57,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    18,    19,    22,    23,    24,    29,    30,     0,
       3,     4,     7,    11,    26,    27,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    43,    45,    10,    14,    25,
      44,    47,    48,    52,     5,    25,    26,    28,    46,    52,
      26,    28,    13,    31,    27,    37,    37,    38,    38,    45,
      45,     8,     9,    41,    42,    27,    26,    50,    51,    15,
      49,    20,    21,    29,    25,    16,    25,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    17,    18,    19,    19,    19,    19,    19,    19,    19,
      20,    20,    21,    22,    23,    23,    24,    25,    26,    26,
      27,    27,    28,    29,    29,    30,    31,    32,    33,    33,
      34,    35,    35,    35,    36,    37,    38,    38,    39,    39,
      39,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     1,     2,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     0,     2,     2,     1
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
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
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
  switch (yyn)
    {
        case 2:
#line 54 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_VP=sparser->get_node_info((yyvsp[0]));
				std::cout<<"S->ENG_VP"<<std::endl;
}
#line 1302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_VP";
				(yyval)=sparser->set_node_info(word,ENG_Vbar1);
				std::cout<<"ENG_VP->ENG_Vbar1"<<std::endl;
}
#line 1315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_AdvP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);
				if((yyval)<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar1 ENG_AdvP"<<std::endl;
}
#line 1331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 80 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_VP";
				(yyval)=sparser->set_node_info(word,ENG_Vbar2);
				std::cout<<"ENG_VP->ENG_Vbar2"<<std::endl;
}
#line 1344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 89 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);
				if((yyval)<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar2 ENG_PP"<<std::endl;
}
#line 1360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar3=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);
				if((yyval)<0){
					/*object_node=sparser->public.get_object_node(sparser,PP);
					printf("Error: cannot interpret %s %s.\n",Vdt->left_child->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_VP->ENG_Vbar3 ENG_NP"<<std::endl;
}
#line 1376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_RC=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);
				std::cout<<"ENG_VP->ENG_Vbar1 ENG_RC"<<std::endl;
}
#line 1387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 120 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar2=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_RC=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);
				std::cout<<"ENG_VP->ENG_Vbar2 ENG_RC"<<std::endl;
}
#line 1398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
				sparser->add_feature_to_leaf(ENG_V,"RCV");
				(yyval)=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_IVP->ENG_V ENG_PP"<<std::endl;
}
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 140 "hi.y" /* yacc.c:1646  */
    {
			const node_info& ENG_NV=sparser->get_node_info((yyvsp[-1]));
			const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
			(yyval)=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
			if((yyval)<0){
				//object_node=sparser->get_object_node(NP);
				//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
				return -1;
			}
			std::cout<<"ENG_IVP->ENG_NV ENG_PP"<<std::endl;
}
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 152 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NEG=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_NV",ENG_V,ENG_NEG);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_NV->ENG_V ENG_NEG"<<std::endl;
}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 164 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_AdvP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VBAR3",ENG_V,ENG_AdvP);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_Vbar3->ENG_V ENG_AdvP"<<std::endl;
}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 176 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_PP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VBAR2",ENG_Vbar1,ENG_PP);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_PP"<<std::endl;
}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 188 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Vbar1=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_Vbar2->ENG_Vbar1 ENG_NP"<<std::endl;
}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 200 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_VBAR1",ENG_V,ENG_NP);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_Vbar1->ENG_V ENG_NP"<<std::endl;
}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 212 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_Prep=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_NP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);
				if((yyval)<0){
					/*object_node=sparser->public.get_object_node(sparser,NP);
					printf("Error: cannot interpret %s %s.\n",Prep->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_PP->ENG_Prep ENG_NP"<<std::endl;
}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 224 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_NP";
				(yyval)=sparser->set_node_info(word,ENG_CNP);
				std::cout<<"ENG_NP->ENG_CNP"<<std::endl;
}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 233 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_QPro=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
				/*	TODO: really need to check if there's a constant ?
					Currently, it's done to make functor argument diff easier.*/
				/*const node_info& object_node=sparser->get_node_info(sparser->get_object_node(CNP));
				if(object_node.right_child!=0){
					//printf("Syntax error: constants like %s cannot be quantified!\n",sparser->get_node_info(object_node.right_child).expression.c_str());
					return -1;
				}*/
				(yyval)=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);
				/* No check for $$<0 since quantifier pronouns are not validated as
				 * everything in the current model seems to be countable.*/
				std::cout<<"ENG_NP->ENG_QPro ENG_CNP"<<std::endl;
}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 253 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_A=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_CNP=sparser->get_node_info((yyvsp[0]));
				/*TODO: ellenorizni, hogy ha a CNP parameteres akkor hiba mint a QPro CNP-nal!*/
				(yyval)=sparser->combine_nodes("ENG_CNP",ENG_A,ENG_CNP);
				if((yyval)<0){
					/*object_node=sparser->public.get_object_node(sparser,CNP);
					printf("Error: cannot interpret %s %s.\n",A->expression,object_node->expression);*/
					return -1;
				}
				std::cout<<"ENG_CNP->ENG_A ENG_CNP"<<std::endl;
}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 266 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_CNP";
				(yyval)=sparser->set_node_info(word,ENG_N);
				std::cout<<"ENG_CNP->ENG_N"<<std::endl;
}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 275 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_Adv=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_AdvP";
				(yyval)=sparser->set_node_info(word,ENG_Adv);
				std::cout<<"ENG_AdvP->ENG_Adv"<<std::endl;
}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 284 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_V_Stem=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_V";
				(yyval)=sparser->set_node_info(word,ENG_V_Stem);
				std::cout<<"ENG_V->ENG_V_Stem"<<std::endl;
}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 293 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_V_stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_V_lfea_aux=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_V",ENG_V_stem,ENG_V_lfea_aux);
				std::cout<<"ENG_V->ENG_V_stem ENG_V_lfea_aux"<<std::endl;
}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 300 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 309 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				word.gcat="Aux";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 319 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				/*TODO: consider what if quantifiers like ALL are handled as functors?*/
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 329 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
	
				const node_info& ENG_N_Sg=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N";
				(yyval)=sparser->set_node_info(word,ENG_N_Sg);
				std::cout<<"ENG_N->ENG_N_Sg"<<std::endl;
}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 338 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N_Pl=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N";
				(yyval)=sparser->set_node_info(word,ENG_N_Pl);
				std::cout<<"ENG_N->ENG_N_Pl"<<std::endl;
}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 347 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_N_lfea_Sg=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Sg0Con",ENG_N_Stem,ENG_N_lfea_Sg);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg"<<std::endl;
}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 359 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Sg_0Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("Sg",ENG_N_Sg_0Con,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con ENG_1Con"<<std::endl;
}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 366 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[0]));
				word.gcat="Sg";
				(yyval)=sparser->set_node_info(word,ENG_1Con);
				std::cout<<"ENG_N_Sg->ENG_1Con"<<std::endl;
}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 375 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N_Sg_0Con=sparser->get_node_info((yyvsp[0]));
				word.gcat="Sg";
				(yyval)=sparser->set_node_info(word,ENG_N_Sg_0Con);
				std::cout<<"ENG_N_Sg->ENG_N_Sg_0Con"<<std::endl;
}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 384 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_N_lfea_Pl=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl"<<std::endl;
}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 396 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_1Con";
				(yyval)=sparser->set_node_info(word,ENG_Con);
				std::cout<<"ENG_1Con->ENG_Con:"<<ENG_Con.expression.lexeme<<std::endl;
}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 405 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_1Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_nCon->ENG_1Con ENG_Con"<<std::endl;
}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 417 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_nCon=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_Con=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_nCon->ENG_nCon ENG_Con"<<std::endl;
}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 429 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_N_Pl_0Con=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N_Pl";
				(yyval)=sparser->set_node_info(word,ENG_N_Pl_0Con);
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con"<<std::endl;
}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 438 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_N_Pl_0Con=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_nCon=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con,ENG_nCon);
				if((yyval)<0){
					//object_node=sparser->get_object_node(NP);
					//printf("Error: cannot interpret %s %s.\n",V->expression,object_node->expression);
					return -1;
				}
				std::cout<<"ENG_N_Pl->ENG_N_Pl_0Con ENG_nCon"<<std::endl;
}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 450 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;

				const node_info& ENG_nCon=sparser->get_node_info((yyvsp[0]));
				word.gcat="ENG_N_Pl";
				(yyval)=sparser->set_node_info(word,ENG_nCon);
				std::cout<<"ENG_N_Pl->ENG_nCon"<<std::endl;
}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 459 "hi.y" /* yacc.c:1646  */
    {
				//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
				//that a singular noun cannot combine with more than one constant like in 'list file abc def'
				//TODO: Any better solution???
				return -1;
}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 466 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 475 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();//TODO: it's unnecessary to duplicate the word info for each node that is related to an affix of the stem of the last scanned word
				//Create a method that returns the info only about the affix in question. Hint: create a method 'lexicon lexer::get_lexicon_info_by_token( uint token )' which
				//would return everything what last_word_scanned() returns but: if the token belongs to a stem it equals to calling last_word_scanned()
				//if the token belongs to an lfea, every field is the same as when calling last_word_scanned() but: the token field would contain the token of the lfea,
				//and if the affix has a functor, then the gcat is the corresponding PREFIX/INFIX/SUFFIX and the lexeme corresponds to that of the affix
				//if the affix does not have a functor, then the gcat is again either PREFIX/INFIX/SUFFIX but the lexeme field is empty
				//WELL, it would have been good if I had written here if duplicating word info poses any problem...
				word.gcat="ENG_N_lfea_Sg";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 491 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				word.gcat="ENG_N_lfea_Pl";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 501 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 510 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 523 "hi.y" /* yacc.c:1646  */
    {
				const node_info empty_node_info={};
				lexicon word;

				word=lex->last_word_scanned();
				word.gcat="CON";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<"Constant:"<<word.word<<std::endl;
}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 533 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};
			
				word=lex->last_word_scanned();
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 542 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_RPro_stem=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_RPro_lfea_relative=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_RPRO",ENG_RPro_stem,ENG_RPro_lfea_relative);
				std::cout<<"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative"<<std::endl;
}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 549 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 558 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				word.gcat="Relative";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 568 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word.gcat="T";
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<"ENG_T->null"<<std::endl;
}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 577 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_T=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_IVP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_TP",ENG_T,ENG_IVP);
				std::cout<<"ENG_TP->ENG_T ENG_IVP"<<std::endl;
}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 584 "hi.y" /* yacc.c:1646  */
    {
				const node_info& ENG_RPro=sparser->get_node_info((yyvsp[-1]));
				const node_info& ENG_TP=sparser->get_node_info((yyvsp[0]));
				(yyval)=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_TP);
				std::cout<<"ENG_RC->ENG_RPro ENG_TP"<<std::endl;
}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 591 "hi.y" /* yacc.c:1646  */
    {
				lexicon word;
				const node_info empty_node_info={};

				word=lex->last_word_scanned();
				(yyval)=sparser->set_node_info(word,empty_node_info);
				std::cout<<word.gcat<<"->"<<word.lexeme<<std::endl;
}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2051 "y.tab.c" /* yacc.c:1646  */
      default: break;
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
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
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

#if !defined yyoverflow || YYERROR_VERBOSE
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
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 610 "hi.y" /* yacc.c:1906  */


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
	std::string commandstr;
	db *sqlite=NULL;
	transgraph *transgraph=NULL;
	char *commandchr=NULL;

	try{
		if(human_input!=NULL){
			lex=new lexer(human_input);
			sqlite=db::get_instance();
			#ifdef __ANDROID__
				__android_log_print(ANDROID_LOG_INFO, "hi", "human_input: %s", human_input);
				sqlite->open("/data/data/hi.pkg/hi.db");//TODO: get cwd on android
			#else
				sqlite->open("hi.db");
			#endif
			sparser=new interpreter;
			if(yyparse()==0){
				transgraph=sparser->longest_match_for_semantic_rules_found();
				if(transgraph!=NULL){
					std::cout<<"TRUE"<<std::endl;
					commandstr=transgraph->transcript(std::string());
					//std::cout<<commandstr<<std::endl;
				}
				else std::cout<<"FALSE"<<std::endl;
			}
			else std::cout<<"FALSE"<<std::endl;
			delete sparser;
			sparser=NULL;
			delete lex;
			lex=NULL;
			sqlite->close();
			delete sqlite;
			sqlite=NULL;
			delete transgraph;
			if(commandstr.empty()==false){
				commandchr=new char[commandstr.length()+1];
				commandstr.copy(commandchr,commandstr.length(),0);
				commandchr[commandstr.length()]='\0';
			}
			return commandchr;
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
