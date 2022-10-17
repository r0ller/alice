// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.







# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 170 "build/hi_android/hi.y.cpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    typedef int semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // END
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    t_ENG_CON_Stem = 258,          // t_ENG_CON_Stem
    t_ENG_A_Stem = 259,            // t_ENG_A_Stem
    t_ENG_ADV_Stem = 260,          // t_ENG_ADV_Stem
    t_ENG_DET_Stem = 261,          // t_ENG_DET_Stem
    t_ENG_N_Stem = 262,            // t_ENG_N_Stem
    t_ENG_N_Pl = 263,              // t_ENG_N_Pl
    t_ENG_N_Sg = 264,              // t_ENG_N_Sg
    t_ENG_PREP_Stem = 265,         // t_ENG_PREP_Stem
    t_ENG_QPRO_Stem = 266,         // t_ENG_QPRO_Stem
    t_ENG_V_Stem = 267,            // t_ENG_V_Stem
    t_ENG_V_Aux = 268,             // t_ENG_V_Aux
    t_ENG_RPRO_Stem = 269,         // t_ENG_RPRO_Stem
    t_ENG_RPRO_Relative = 270,     // t_ENG_RPRO_Relative
    t_ENG_VNEG_Stem = 271,         // t_ENG_VNEG_Stem
    t_ENG_ANEG_Stem = 272,         // t_ENG_ANEG_Stem
    t_ENG_PAR_Stem = 273,          // t_ENG_PAR_Stem
    t_ENG_DET_Indef = 274,         // t_ENG_DET_Indef
    t_ENG_DET_fwVowel = 275,       // t_ENG_DET_fwVowel
    t_ENG_DET_fwConsonant = 276,   // t_ENG_DET_fwConsonant
    t_ENG_N_swVowel = 277,         // t_ENG_N_swVowel
    t_ENG_N_swConsonant = 278,     // t_ENG_N_swConsonant
    t_ENG_V_Gerund = 279,          // t_ENG_V_Gerund
    t_ENG_CONJ_Stem = 280,         // t_ENG_CONJ_Stem
    t_ENG_Num_Stem = 281,          // t_ENG_Num_Stem
    t_ENG_Num_Ord = 282,           // t_ENG_Num_Ord
    t_ENG_Num_Npref1n = 283,       // t_ENG_Num_Npref1n
    t_ENG_Num_Npref2n = 284,       // t_ENG_Num_Npref2n
    t_ENG_Num_Npref3n = 285,       // t_ENG_Num_Npref3n
    t_ENG_Num_Npref4n = 286,       // t_ENG_Num_Npref4n
    t_ENG_Num_Npref5n = 287,       // t_ENG_Num_Npref5n
    t_ENG_Num_Npref6n = 288,       // t_ENG_Num_Npref6n
    t_ENG_Num_Npref7n = 289,       // t_ENG_Num_Npref7n
    t_ENG_Num_Npref8n = 290,       // t_ENG_Num_Npref8n
    t_ENG_Num_Npref9n = 291,       // t_ENG_Num_Npref9n
    t_ENG_Num_swVowel = 292,       // t_ENG_Num_swVowel
    t_ENG_Num_swConsonant = 293,   // t_ENG_Num_swConsonant
    t_ENG_DET_Def = 294,           // t_ENG_DET_Def
    t_HUN_CON_Stem = 295,          // t_HUN_CON_Stem
    t_HUN_Num_Stem = 296,          // t_HUN_Num_Stem
    t_HUN_Num_Ik = 297,            // t_HUN_Num_Ik
    t_HUN_Num_Par = 298,           // t_HUN_Num_Par
    t_HUN_Num_Npref1 = 299,        // t_HUN_Num_Npref1
    t_HUN_Num_Npref2 = 300,        // t_HUN_Num_Npref2
    t_HUN_Num_Npref3 = 301,        // t_HUN_Num_Npref3
    t_HUN_Num_Npref4 = 302,        // t_HUN_Num_Npref4
    t_HUN_Num_Npref5 = 303,        // t_HUN_Num_Npref5
    t_HUN_Num_Npref6 = 304,        // t_HUN_Num_Npref6
    t_HUN_Num_Npref7 = 305,        // t_HUN_Num_Npref7
    t_HUN_Num_Npref8 = 306,        // t_HUN_Num_Npref8
    t_HUN_Num_Npref9 = 307,        // t_HUN_Num_Npref9
    t_HUN_Num_Npref1nn = 308,      // t_HUN_Num_Npref1nn
    t_HUN_Num_Npref1nnn = 309,     // t_HUN_Num_Npref1nnn
    t_HUN_Det_Stem = 310,          // t_HUN_Det_Stem
    t_HUN_Det_Def = 311,           // t_HUN_Det_Def
    t_HUN_Det_fwVowel = 312,       // t_HUN_Det_fwVowel
    t_HUN_Det_fwConsonant = 313,   // t_HUN_Det_fwConsonant
    t_HUN_CON_swVowel = 314,       // t_HUN_CON_swVowel
    t_HUN_CON_swConsonant = 315,   // t_HUN_CON_swConsonant
    t_HUN_Num_Acc = 316,           // t_HUN_Num_Acc
    t_HUN_Num_Npref1n = 317,       // t_HUN_Num_Npref1n
    t_HUN_Num_Npref2n = 318,       // t_HUN_Num_Npref2n
    t_HUN_Num_Npref3n = 319,       // t_HUN_Num_Npref3n
    t_HUN_Num_Npref4n = 320,       // t_HUN_Num_Npref4n
    t_HUN_Num_Npref5n = 321,       // t_HUN_Num_Npref5n
    t_HUN_Num_Npref6n = 322,       // t_HUN_Num_Npref6n
    t_HUN_Num_Npref7n = 323,       // t_HUN_Num_Npref7n
    t_HUN_Num_Npref8n = 324,       // t_HUN_Num_Npref8n
    t_HUN_Num_Npref9n = 325,       // t_HUN_Num_Npref9n
    t_HUN_Num_swVowel = 326,       // t_HUN_Num_swVowel
    t_HUN_Num_swConsonant = 327,   // t_HUN_Num_swConsonant
    t_HUN_Noun_Stem = 328,         // t_HUN_Noun_Stem
    t_HUN_Noun_Acc = 329,          // t_HUN_Noun_Acc
    t_HUN_Noun_swVowel = 330,      // t_HUN_Noun_swVowel
    t_HUN_Noun_swConsonant = 331,  // t_HUN_Noun_swConsonant
    t_HUN_CON_Acc = 332,           // t_HUN_CON_Acc
    t_HUN_Verb_Stem = 333,         // t_HUN_Verb_Stem
    t_HUN_Verb_ConjDefSg2 = 334,   // t_HUN_Verb_ConjDefSg2
    t_HUN_Vbpfx_Stem = 335,        // t_HUN_Vbpfx_Stem
    t_HUN_Noun_Relative = 336,     // t_HUN_Noun_Relative
    t_HUN_Conj_Stem = 337,         // t_HUN_Conj_Stem
    t_HUN_Neg_Stem = 338,          // t_HUN_Neg_Stem
    t_HUN_Noun_Plur = 339,         // t_HUN_Noun_Plur
    t_HUN_Noun_Ine = 340,          // t_HUN_Noun_Ine
    t_HUN_Verb_IndefSg3 = 341,     // t_HUN_Verb_IndefSg3
    t_HUN_Verb_ConjIndefSg2 = 342, // t_HUN_Verb_ConjIndefSg2
    t_HUN_Adj_Stem = 343,          // t_HUN_Adj_Stem
    t_HUN_CON_Sub = 344,           // t_HUN_CON_Sub
    t_HUN_CON_Ins = 345,           // t_HUN_CON_Ins
    t_HUN_Verb_IndefPl3 = 346,     // t_HUN_Verb_IndefPl3
    t_HUN_Verb_DefSg1 = 347,       // t_HUN_Verb_DefSg1
    t_HUN_Noun_Dat = 348,          // t_HUN_Noun_Dat
    t_HUN_CON_Dat = 349,           // t_HUN_CON_Dat
    t_HUN_Num_Dat = 350,           // t_HUN_Num_Dat
    t_HUN_Noun_Del = 351,          // t_HUN_Noun_Del
    t_HUN_Num_Del = 352            // t_HUN_Num_Del
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 98, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_t_ENG_CON_Stem = 3,                    // t_ENG_CON_Stem
        S_t_ENG_A_Stem = 4,                      // t_ENG_A_Stem
        S_t_ENG_ADV_Stem = 5,                    // t_ENG_ADV_Stem
        S_t_ENG_DET_Stem = 6,                    // t_ENG_DET_Stem
        S_t_ENG_N_Stem = 7,                      // t_ENG_N_Stem
        S_t_ENG_N_Pl = 8,                        // t_ENG_N_Pl
        S_t_ENG_N_Sg = 9,                        // t_ENG_N_Sg
        S_t_ENG_PREP_Stem = 10,                  // t_ENG_PREP_Stem
        S_t_ENG_QPRO_Stem = 11,                  // t_ENG_QPRO_Stem
        S_t_ENG_V_Stem = 12,                     // t_ENG_V_Stem
        S_t_ENG_V_Aux = 13,                      // t_ENG_V_Aux
        S_t_ENG_RPRO_Stem = 14,                  // t_ENG_RPRO_Stem
        S_t_ENG_RPRO_Relative = 15,              // t_ENG_RPRO_Relative
        S_t_ENG_VNEG_Stem = 16,                  // t_ENG_VNEG_Stem
        S_t_ENG_ANEG_Stem = 17,                  // t_ENG_ANEG_Stem
        S_t_ENG_PAR_Stem = 18,                   // t_ENG_PAR_Stem
        S_t_ENG_DET_Indef = 19,                  // t_ENG_DET_Indef
        S_t_ENG_DET_fwVowel = 20,                // t_ENG_DET_fwVowel
        S_t_ENG_DET_fwConsonant = 21,            // t_ENG_DET_fwConsonant
        S_t_ENG_N_swVowel = 22,                  // t_ENG_N_swVowel
        S_t_ENG_N_swConsonant = 23,              // t_ENG_N_swConsonant
        S_t_ENG_V_Gerund = 24,                   // t_ENG_V_Gerund
        S_t_ENG_CONJ_Stem = 25,                  // t_ENG_CONJ_Stem
        S_t_ENG_Num_Stem = 26,                   // t_ENG_Num_Stem
        S_t_ENG_Num_Ord = 27,                    // t_ENG_Num_Ord
        S_t_ENG_Num_Npref1n = 28,                // t_ENG_Num_Npref1n
        S_t_ENG_Num_Npref2n = 29,                // t_ENG_Num_Npref2n
        S_t_ENG_Num_Npref3n = 30,                // t_ENG_Num_Npref3n
        S_t_ENG_Num_Npref4n = 31,                // t_ENG_Num_Npref4n
        S_t_ENG_Num_Npref5n = 32,                // t_ENG_Num_Npref5n
        S_t_ENG_Num_Npref6n = 33,                // t_ENG_Num_Npref6n
        S_t_ENG_Num_Npref7n = 34,                // t_ENG_Num_Npref7n
        S_t_ENG_Num_Npref8n = 35,                // t_ENG_Num_Npref8n
        S_t_ENG_Num_Npref9n = 36,                // t_ENG_Num_Npref9n
        S_t_ENG_Num_swVowel = 37,                // t_ENG_Num_swVowel
        S_t_ENG_Num_swConsonant = 38,            // t_ENG_Num_swConsonant
        S_t_ENG_DET_Def = 39,                    // t_ENG_DET_Def
        S_t_HUN_CON_Stem = 40,                   // t_HUN_CON_Stem
        S_t_HUN_Num_Stem = 41,                   // t_HUN_Num_Stem
        S_t_HUN_Num_Ik = 42,                     // t_HUN_Num_Ik
        S_t_HUN_Num_Par = 43,                    // t_HUN_Num_Par
        S_t_HUN_Num_Npref1 = 44,                 // t_HUN_Num_Npref1
        S_t_HUN_Num_Npref2 = 45,                 // t_HUN_Num_Npref2
        S_t_HUN_Num_Npref3 = 46,                 // t_HUN_Num_Npref3
        S_t_HUN_Num_Npref4 = 47,                 // t_HUN_Num_Npref4
        S_t_HUN_Num_Npref5 = 48,                 // t_HUN_Num_Npref5
        S_t_HUN_Num_Npref6 = 49,                 // t_HUN_Num_Npref6
        S_t_HUN_Num_Npref7 = 50,                 // t_HUN_Num_Npref7
        S_t_HUN_Num_Npref8 = 51,                 // t_HUN_Num_Npref8
        S_t_HUN_Num_Npref9 = 52,                 // t_HUN_Num_Npref9
        S_t_HUN_Num_Npref1nn = 53,               // t_HUN_Num_Npref1nn
        S_t_HUN_Num_Npref1nnn = 54,              // t_HUN_Num_Npref1nnn
        S_t_HUN_Det_Stem = 55,                   // t_HUN_Det_Stem
        S_t_HUN_Det_Def = 56,                    // t_HUN_Det_Def
        S_t_HUN_Det_fwVowel = 57,                // t_HUN_Det_fwVowel
        S_t_HUN_Det_fwConsonant = 58,            // t_HUN_Det_fwConsonant
        S_t_HUN_CON_swVowel = 59,                // t_HUN_CON_swVowel
        S_t_HUN_CON_swConsonant = 60,            // t_HUN_CON_swConsonant
        S_t_HUN_Num_Acc = 61,                    // t_HUN_Num_Acc
        S_t_HUN_Num_Npref1n = 62,                // t_HUN_Num_Npref1n
        S_t_HUN_Num_Npref2n = 63,                // t_HUN_Num_Npref2n
        S_t_HUN_Num_Npref3n = 64,                // t_HUN_Num_Npref3n
        S_t_HUN_Num_Npref4n = 65,                // t_HUN_Num_Npref4n
        S_t_HUN_Num_Npref5n = 66,                // t_HUN_Num_Npref5n
        S_t_HUN_Num_Npref6n = 67,                // t_HUN_Num_Npref6n
        S_t_HUN_Num_Npref7n = 68,                // t_HUN_Num_Npref7n
        S_t_HUN_Num_Npref8n = 69,                // t_HUN_Num_Npref8n
        S_t_HUN_Num_Npref9n = 70,                // t_HUN_Num_Npref9n
        S_t_HUN_Num_swVowel = 71,                // t_HUN_Num_swVowel
        S_t_HUN_Num_swConsonant = 72,            // t_HUN_Num_swConsonant
        S_t_HUN_Noun_Stem = 73,                  // t_HUN_Noun_Stem
        S_t_HUN_Noun_Acc = 74,                   // t_HUN_Noun_Acc
        S_t_HUN_Noun_swVowel = 75,               // t_HUN_Noun_swVowel
        S_t_HUN_Noun_swConsonant = 76,           // t_HUN_Noun_swConsonant
        S_t_HUN_CON_Acc = 77,                    // t_HUN_CON_Acc
        S_t_HUN_Verb_Stem = 78,                  // t_HUN_Verb_Stem
        S_t_HUN_Verb_ConjDefSg2 = 79,            // t_HUN_Verb_ConjDefSg2
        S_t_HUN_Vbpfx_Stem = 80,                 // t_HUN_Vbpfx_Stem
        S_t_HUN_Noun_Relative = 81,              // t_HUN_Noun_Relative
        S_t_HUN_Conj_Stem = 82,                  // t_HUN_Conj_Stem
        S_t_HUN_Neg_Stem = 83,                   // t_HUN_Neg_Stem
        S_t_HUN_Noun_Plur = 84,                  // t_HUN_Noun_Plur
        S_t_HUN_Noun_Ine = 85,                   // t_HUN_Noun_Ine
        S_t_HUN_Verb_IndefSg3 = 86,              // t_HUN_Verb_IndefSg3
        S_t_HUN_Verb_ConjIndefSg2 = 87,          // t_HUN_Verb_ConjIndefSg2
        S_t_HUN_Adj_Stem = 88,                   // t_HUN_Adj_Stem
        S_t_HUN_CON_Sub = 89,                    // t_HUN_CON_Sub
        S_t_HUN_CON_Ins = 90,                    // t_HUN_CON_Ins
        S_t_HUN_Verb_IndefPl3 = 91,              // t_HUN_Verb_IndefPl3
        S_t_HUN_Verb_DefSg1 = 92,                // t_HUN_Verb_DefSg1
        S_t_HUN_Noun_Dat = 93,                   // t_HUN_Noun_Dat
        S_t_HUN_CON_Dat = 94,                    // t_HUN_CON_Dat
        S_t_HUN_Num_Dat = 95,                    // t_HUN_Num_Dat
        S_t_HUN_Noun_Del = 96,                   // t_HUN_Noun_Del
        S_t_HUN_Num_Del = 97,                    // t_HUN_Num_Del
        S_YYACCEPT = 98,                         // $accept
        S_ENG_1Con = 99,                         // ENG_1Con
        S_ENG_A = 100,                           // ENG_A
        S_ENG_A0NEG = 101,                       // ENG_A0NEG
        S_ENG_ANEG = 102,                        // ENG_ANEG
        S_ENG_ANEG_Stem = 103,                   // ENG_ANEG_Stem
        S_ENG_AP = 104,                          // ENG_AP
        S_ENG_A_Stem = 105,                      // ENG_A_Stem
        S_ENG_Abar1 = 106,                       // ENG_Abar1
        S_ENG_Abar2 = 107,                       // ENG_Abar2
        S_ENG_Adv = 108,                         // ENG_Adv
        S_ENG_AdvP = 109,                        // ENG_AdvP
        S_ENG_Alist = 110,                       // ENG_Alist
        S_ENG_CAP = 111,                         // ENG_CAP
        S_ENG_CNP = 112,                         // ENG_CNP
        S_ENG_CONJ = 113,                        // ENG_CONJ
        S_ENG_CONJA = 114,                       // ENG_CONJA
        S_ENG_CONJ_Stem = 115,                   // ENG_CONJ_Stem
        S_ENG_Con = 116,                         // ENG_Con
        S_ENG_ConjPVP = 117,                     // ENG_ConjPVP
        S_ENG_ConjV = 118,                       // ENG_ConjV
        S_ENG_DP = 119,                          // ENG_DP
        S_ENG_Def_Det = 120,                     // ENG_Def_Det
        S_ENG_Det_stem = 121,                    // ENG_Det_stem
        S_ENG_IVP = 122,                         // ENG_IVP
        S_ENG_IVPConj = 123,                     // ENG_IVPConj
        S_ENG_IVPlist = 124,                     // ENG_IVPlist
        S_ENG_Indef_Det = 125,                   // ENG_Indef_Det
        S_ENG_Indef_Det_a = 126,                 // ENG_Indef_Det_a
        S_ENG_Indef_Det_an = 127,                // ENG_Indef_Det_an
        S_ENG_N = 128,                           // ENG_N
        S_ENG_NP = 129,                          // ENG_NP
        S_ENG_NV = 130,                          // ENG_NV
        S_ENG_NV_Aux = 131,                      // ENG_NV_Aux
        S_ENG_N_Pl = 132,                        // ENG_N_Pl
        S_ENG_N_Pl_0Con = 133,                   // ENG_N_Pl_0Con
        S_ENG_N_Pl_0Con_swC = 134,               // ENG_N_Pl_0Con_swC
        S_ENG_N_Pl_0Con_swV = 135,               // ENG_N_Pl_0Con_swV
        S_ENG_N_Sg = 136,                        // ENG_N_Sg
        S_ENG_N_Sg_0Con = 137,                   // ENG_N_Sg_0Con
        S_ENG_N_Sg_0Con_swC = 138,               // ENG_N_Sg_0Con_swC
        S_ENG_N_Sg_0Con_swV = 139,               // ENG_N_Sg_0Con_swV
        S_ENG_N_Stem = 140,                      // ENG_N_Stem
        S_ENG_N_lfea_Pl = 141,                   // ENG_N_lfea_Pl
        S_ENG_N_lfea_Sg = 142,                   // ENG_N_lfea_Sg
        S_ENG_Num = 143,                         // ENG_Num
        S_ENG_Num_Ord = 144,                     // ENG_Num_Ord
        S_ENG_Num_Pref = 145,                    // ENG_Num_Pref
        S_ENG_Num_Stem = 146,                    // ENG_Num_Stem
        S_ENG_Num_lfea_Ord = 147,                // ENG_Num_lfea_Ord
        S_ENG_PNVPbar = 148,                     // ENG_PNVPbar
        S_ENG_PP = 149,                          // ENG_PP
        S_ENG_PVP = 150,                         // ENG_PVP
        S_ENG_PVPConj = 151,                     // ENG_PVPConj
        S_ENG_PVPbar = 152,                      // ENG_PVPbar
        S_ENG_PVPhead = 153,                     // ENG_PVPhead
        S_ENG_PVPlist = 154,                     // ENG_PVPlist
        S_ENG_PVPlisthead = 155,                 // ENG_PVPlisthead
        S_ENG_Prep = 156,                        // ENG_Prep
        S_ENG_QPro = 157,                        // ENG_QPro
        S_ENG_RC = 158,                          // ENG_RC
        S_ENG_RPro = 159,                        // ENG_RPro
        S_ENG_RPro_lfea_relative = 160,          // ENG_RPro_lfea_relative
        S_ENG_RPro_stem = 161,                   // ENG_RPro_stem
        S_ENG_TP = 162,                          // ENG_TP
        S_ENG_Tense_particle = 163,              // ENG_Tense_particle
        S_ENG_V = 164,                           // ENG_V
        S_ENG_VNEG = 165,                        // ENG_VNEG
        S_ENG_VNEG_Stem = 166,                   // ENG_VNEG_Stem
        S_ENG_VP = 167,                          // ENG_VP
        S_ENG_V_Aux = 168,                       // ENG_V_Aux
        S_ENG_V_Ger = 169,                       // ENG_V_Ger
        S_ENG_V_Stem = 170,                      // ENG_V_Stem
        S_ENG_V_lfea_aux = 171,                  // ENG_V_lfea_aux
        S_ENG_V_lfea_ger = 172,                  // ENG_V_lfea_ger
        S_ENG_Vbar1 = 173,                       // ENG_Vbar1
        S_ENG_Vbar2 = 174,                       // ENG_Vbar2
        S_ENG_Vbar3 = 175,                       // ENG_Vbar3
        S_ENG_Vbar4 = 176,                       // ENG_Vbar4
        S_ENG_Vhead = 177,                       // ENG_Vhead
        S_ENG_Vlisthead = 178,                   // ENG_Vlisthead
        S_ENG_lfea_DefDet = 179,                 // ENG_lfea_DefDet
        S_ENG_lfea_IndefDet = 180,               // ENG_lfea_IndefDet
        S_ENG_lfea_fwConsonant = 181,            // ENG_lfea_fwConsonant
        S_ENG_lfea_fwVowel = 182,                // ENG_lfea_fwVowel
        S_ENG_lfea_swConsonant = 183,            // ENG_lfea_swConsonant
        S_ENG_lfea_swVowel = 184,                // ENG_lfea_swVowel
        S_ENG_nCon = 185,                        // ENG_nCon
        S_HUN_1Con = 186,                        // HUN_1Con
        S_HUN_A0NEG = 187,                       // HUN_A0NEG
        S_HUN_ANEG = 188,                        // HUN_ANEG
        S_HUN_ANP = 189,                         // HUN_ANP
        S_HUN_AN_Acc = 190,                      // HUN_AN_Acc
        S_HUN_AP = 191,                          // HUN_AP
        S_HUN_Abar1 = 192,                       // HUN_Abar1
        S_HUN_Abar1N = 193,                      // HUN_Abar1N
        S_HUN_Abar2 = 194,                       // HUN_Abar2
        S_HUN_Abar2N = 195,                      // HUN_Abar2N
        S_HUN_Abar3 = 196,                       // HUN_Abar3
        S_HUN_Abar3_End = 197,                   // HUN_Abar3_End
        S_HUN_Abar4 = 198,                       // HUN_Abar4
        S_HUN_Adj = 199,                         // HUN_Adj
        S_HUN_Adj_Stem = 200,                    // HUN_Adj_Stem
        S_HUN_Alist = 201,                       // HUN_Alist
        S_HUN_Alist_End = 202,                   // HUN_Alist_End
        S_HUN_Con = 203,                         // HUN_Con
        S_HUN_Con_lfea_Acc = 204,                // HUN_Con_lfea_Acc
        S_HUN_Con_lfea_Dat = 205,                // HUN_Con_lfea_Dat
        S_HUN_Con_lfea_Ins = 206,                // HUN_Con_lfea_Ins
        S_HUN_Con_lfea_Sub = 207,                // HUN_Con_lfea_Sub
        S_HUN_Conj = 208,                        // HUN_Conj
        S_HUN_ConjA = 209,                       // HUN_ConjA
        S_HUN_ConjA_End = 210,                   // HUN_ConjA_End
        S_HUN_ConjAlist = 211,                   // HUN_ConjAlist
        S_HUN_ConjV = 212,                       // HUN_ConjV
        S_HUN_Conj_Stem = 213,                   // HUN_Conj_Stem
        S_HUN_DP = 214,                          // HUN_DP
        S_HUN_DPbar = 215,                       // HUN_DPbar
        S_HUN_Def_Det = 216,                     // HUN_Def_Det
        S_HUN_Def_Det_a = 217,                   // HUN_Def_Det_a
        S_HUN_Def_Det_az = 218,                  // HUN_Def_Det_az
        S_HUN_Det_stem = 219,                    // HUN_Det_stem
        S_HUN_Empty = 220,                       // HUN_Empty
        S_HUN_INVP = 221,                        // HUN_INVP
        S_HUN_INVPbar = 222,                     // HUN_INVPbar
        S_HUN_INVPbar2 = 223,                    // HUN_INVPbar2
        S_HUN_IVP = 224,                         // HUN_IVP
        S_HUN_IVPConj = 225,                     // HUN_IVPConj
        S_HUN_IVPbar = 226,                      // HUN_IVPbar
        S_HUN_IVPlist = 227,                     // HUN_IVPlist
        S_HUN_ImpVerb = 228,                     // HUN_ImpVerb
        S_HUN_ImpVerbPfx = 229,                  // HUN_ImpVerbPfx
        S_HUN_NAbar1 = 230,                      // HUN_NAbar1
        S_HUN_NP = 231,                          // HUN_NP
        S_HUN_N_Acc = 232,                       // HUN_N_Acc
        S_HUN_N_Dat = 233,                       // HUN_N_Dat
        S_HUN_N_Ine = 234,                       // HUN_N_Ine
        S_HUN_N_Ins = 235,                       // HUN_N_Ins
        S_HUN_N_Pl = 236,                        // HUN_N_Pl
        S_HUN_N_Sg = 237,                        // HUN_N_Sg
        S_HUN_N_Sub = 238,                       // HUN_N_Sub
        S_HUN_Neg = 239,                         // HUN_Neg
        S_HUN_Neg_Stem = 240,                    // HUN_Neg_Stem
        S_HUN_Noun_Stem = 241,                   // HUN_Noun_Stem
        S_HUN_Noun_lfea_Acc = 242,               // HUN_Noun_lfea_Acc
        S_HUN_Noun_lfea_Dat = 243,               // HUN_Noun_lfea_Dat
        S_HUN_Noun_lfea_Del = 244,               // HUN_Noun_lfea_Del
        S_HUN_Noun_lfea_Ine = 245,               // HUN_Noun_lfea_Ine
        S_HUN_Noun_lfea_Plur = 246,              // HUN_Noun_lfea_Plur
        S_HUN_Noun_lfea_Relative = 247,          // HUN_Noun_lfea_Relative
        S_HUN_Num = 248,                         // HUN_Num
        S_HUN_Num_Pref = 249,                    // HUN_Num_Pref
        S_HUN_Num_Stem = 250,                    // HUN_Num_Stem
        S_HUN_Num_lfea_Acc = 251,                // HUN_Num_lfea_Acc
        S_HUN_Num_lfea_Dat = 252,                // HUN_Num_lfea_Dat
        S_HUN_Num_lfea_Del = 253,                // HUN_Num_lfea_Del
        S_HUN_Num_lfea_Ik = 254,                 // HUN_Num_lfea_Ik
        S_HUN_Num_lfea_Par = 255,                // HUN_Num_lfea_Par
        S_HUN_Nums = 256,                        // HUN_Nums
        S_HUN_RC = 257,                          // HUN_RC
        S_HUN_RPro = 258,                        // HUN_RPro
        S_HUN_V = 259,                           // HUN_V
        S_HUN_VP = 260,                          // HUN_VP
        S_HUN_Vbar1 = 261,                       // HUN_Vbar1
        S_HUN_Vbar2 = 262,                       // HUN_Vbar2
        S_HUN_Vbpfx = 263,                       // HUN_Vbpfx
        S_HUN_Verb_lfea_ConjDefSg2 = 264,        // HUN_Verb_lfea_ConjDefSg2
        S_HUN_Verb_lfea_ConjIndefSg2 = 265,      // HUN_Verb_lfea_ConjIndefSg2
        S_HUN_Verb_lfea_DefSg1 = 266,            // HUN_Verb_lfea_DefSg1
        S_HUN_Verb_lfea_IndefPl3 = 267,          // HUN_Verb_lfea_IndefPl3
        S_HUN_Verb_stem = 268,                   // HUN_Verb_stem
        S_HUN_Vhead = 269,                       // HUN_Vhead
        S_HUN_Vlisthead = 270,                   // HUN_Vlisthead
        S_HUN_lfea_DefDet = 271,                 // HUN_lfea_DefDet
        S_HUN_lfea_fwConsonant = 272,            // HUN_lfea_fwConsonant
        S_HUN_lfea_fwVowel = 273,                // HUN_lfea_fwVowel
        S_HUN_lfea_swConsonant = 274,            // HUN_lfea_swConsonant
        S_HUN_lfea_swVowel = 275,                // HUN_lfea_swVowel
        S_HUN_nCon = 276,                        // HUN_nCon
        S_S = 277                                // S
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value (std::move (that.value))
      {}
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);
      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    YY_RVREF (semantic_type) v);

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {};

    /// Build a parser object.
    parser ();
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);



    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const short yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const short yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 1337,     ///< Last index in yytable_.
      yynnts_ = 180,  ///< Number of nonterminal symbols.
      yyfinal_ = 225 ///< Termination state number.
    };



  };


} // yy
#line 1108 "build/hi_android/hi.y.cpp"






// Unqualified %code blocks.
#line 1 "build/hi_android/hi.y"

#include "tokensymbols.h"
#line 4 "build/hi_android/hi.y"

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


#line 1149 "build/hi_android/hi.y.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 1222 "build/hi_android/hi.y.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // ENG_1Con: ENG_Con
#line 139 "build/hi_android/hi.y"
{
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_1Con->ENG_Con");
yylhs.value=sparser->set_node_info("ENG_1Con",ENG_Con);

}
#line 1677 "build/hi_android/hi.y.cpp"
    break;

  case 3: // ENG_A: ENG_A_Stem
#line 147 "build/hi_android/hi.y"
{
const node_info& ENG_A_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A->ENG_A_Stem");
yylhs.value=sparser->set_node_info("ENG_A",ENG_A_Stem);

}
#line 1688 "build/hi_android/hi.y.cpp"
    break;

  case 4: // ENG_A0NEG: ENG_A
#line 155 "build/hi_android/hi.y"
{
const node_info& ENG_A=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A0NEG->ENG_A");
yylhs.value=sparser->set_node_info("ENG_A0NEG",ENG_A);

}
#line 1699 "build/hi_android/hi.y.cpp"
    break;

  case 5: // ENG_ANEG: ENG_ANEG_Stem
#line 163 "build/hi_android/hi.y"
{
const node_info& ENG_ANEG_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ANEG->ENG_ANEG_Stem");
yylhs.value=sparser->set_node_info("ENG_ANEG",ENG_ANEG_Stem);

}
#line 1710 "build/hi_android/hi.y.cpp"
    break;

  case 6: // ENG_ANEG_Stem: t_ENG_ANEG_Stem
#line 171 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ANEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_ANEG_Stem",word);

}
#line 1722 "build/hi_android/hi.y.cpp"
    break;

  case 7: // ENG_AP: ENG_Abar1
#line 180 "build/hi_android/hi.y"
{
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar1");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Abar1);

}
#line 1733 "build/hi_android/hi.y.cpp"
    break;

  case 8: // ENG_AP: ENG_Abar2
#line 187 "build/hi_android/hi.y"
{
const node_info& ENG_Abar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar2");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Abar2);

}
#line 1744 "build/hi_android/hi.y.cpp"
    break;

  case 9: // ENG_AP: ENG_Alist
#line 194 "build/hi_android/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Alist");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Alist);

}
#line 1755 "build/hi_android/hi.y.cpp"
    break;

  case 10: // ENG_A_Stem: t_ENG_A_Stem
#line 202 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_A_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_A_Stem",word);

}
#line 1767 "build/hi_android/hi.y.cpp"
    break;

  case 11: // ENG_Abar1: ENG_A0NEG
#line 211 "build/hi_android/hi.y"
{
const node_info& ENG_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_A0NEG");
yylhs.value=sparser->set_node_info("ENG_Abar1",ENG_A0NEG);

}
#line 1778 "build/hi_android/hi.y.cpp"
    break;

  case 12: // ENG_Abar1: ENG_ANEG ENG_A
#line 218 "build/hi_android/hi.y"
{
const node_info& ENG_ANEG=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_A=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_ANEG ENG_A");
yylhs.value=sparser->combine_nodes("ENG_Abar1",ENG_ANEG,ENG_A);

}
#line 1790 "build/hi_android/hi.y.cpp"
    break;

  case 13: // ENG_Abar2: ENG_Abar1 ENG_CONJA
#line 227 "build/hi_android/hi.y"
{
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar1 ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Abar1,ENG_CONJA);

}
#line 1802 "build/hi_android/hi.y.cpp"
    break;

  case 14: // ENG_Abar2: ENG_Abar2 ENG_CONJA
#line 235 "build/hi_android/hi.y"
{
const node_info& ENG_Abar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar2 ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Abar2,ENG_CONJA);

}
#line 1814 "build/hi_android/hi.y.cpp"
    break;

  case 15: // ENG_Abar2: ENG_Alist ENG_CONJA
#line 243 "build/hi_android/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Alist ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Alist,ENG_CONJA);

}
#line 1826 "build/hi_android/hi.y.cpp"
    break;

  case 16: // ENG_Adv: t_ENG_ADV_Stem
#line 252 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ADV_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Adv",word);

}
#line 1838 "build/hi_android/hi.y.cpp"
    break;

  case 17: // ENG_AdvP: ENG_Adv
#line 261 "build/hi_android/hi.y"
{
const node_info& ENG_Adv=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AdvP->ENG_Adv");
yylhs.value=sparser->set_node_info("ENG_AdvP",ENG_Adv);

}
#line 1849 "build/hi_android/hi.y.cpp"
    break;

  case 18: // ENG_Alist: ENG_Abar1 ENG_Abar1
#line 269 "build/hi_android/hi.y"
{
const node_info& ENG_Abar11=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar12=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Abar1 ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_Alist",ENG_Abar11,ENG_Abar12);

}
#line 1861 "build/hi_android/hi.y.cpp"
    break;

  case 19: // ENG_Alist: ENG_Alist ENG_Abar1
#line 277 "build/hi_android/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Alist ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_Alist",ENG_Alist,ENG_Abar1);

}
#line 1873 "build/hi_android/hi.y.cpp"
    break;

  case 20: // ENG_CAP: ENG_1Con ENG_N_Pl_0Con_swC
#line 286 "build/hi_android/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swC");
yylhs.value=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swC);

}
#line 1885 "build/hi_android/hi.y.cpp"
    break;

  case 21: // ENG_CAP: ENG_1Con ENG_N_Pl_0Con_swV
#line 294 "build/hi_android/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swV");
yylhs.value=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swV);

}
#line 1897 "build/hi_android/hi.y.cpp"
    break;

  case 22: // ENG_CNP: ENG_AP ENG_N
#line 303 "build/hi_android/hi.y"
{
const node_info& ENG_AP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_AP ENG_N");
yylhs.value=sparser->combine_nodes("ENG_CNP",ENG_AP,ENG_N);

}
#line 1909 "build/hi_android/hi.y.cpp"
    break;

  case 23: // ENG_CNP: ENG_N
#line 311 "build/hi_android/hi.y"
{
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_N");
yylhs.value=sparser->set_node_info("ENG_CNP",ENG_N);

}
#line 1920 "build/hi_android/hi.y.cpp"
    break;

  case 24: // ENG_CONJ: ENG_CONJ_Stem
#line 319 "build/hi_android/hi.y"
{
const node_info& ENG_CONJ_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJ->ENG_CONJ_Stem");
yylhs.value=sparser->set_node_info("ENG_CONJ",ENG_CONJ_Stem);

}
#line 1931 "build/hi_android/hi.y.cpp"
    break;

  case 25: // ENG_CONJA: ENG_CONJ ENG_Abar1
#line 327 "build/hi_android/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Abar1);

}
#line 1943 "build/hi_android/hi.y.cpp"
    break;

  case 26: // ENG_CONJA: ENG_CONJ ENG_Alist
#line 335 "build/hi_android/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Alist");
yylhs.value=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Alist);

}
#line 1955 "build/hi_android/hi.y.cpp"
    break;

  case 27: // ENG_CONJ_Stem: t_ENG_CONJ_Stem
#line 344 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CONJ_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_CONJ_Stem",word);

}
#line 1967 "build/hi_android/hi.y.cpp"
    break;

  case 28: // ENG_Con: t_ENG_CON_Stem
#line 353 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Con",word);

}
#line 1979 "build/hi_android/hi.y.cpp"
    break;

  case 29: // ENG_ConjPVP: ENG_CONJ ENG_PVP
#line 362 "build/hi_android/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjPVP->ENG_CONJ ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_ConjPVP",ENG_CONJ,ENG_PVP);

}
#line 1991 "build/hi_android/hi.y.cpp"
    break;

  case 30: // ENG_ConjPVP: ENG_CONJ ENG_PVPlist
#line 370 "build/hi_android/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjPVP->ENG_CONJ ENG_PVPlist");
yylhs.value=sparser->combine_nodes("ENG_ConjPVP",ENG_CONJ,ENG_PVPlist);

}
#line 2003 "build/hi_android/hi.y.cpp"
    break;

  case 31: // ENG_ConjV: ENG_CONJ ENG_IVP
#line 379 "build/hi_android/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjV->ENG_CONJ ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_ConjV",ENG_CONJ,ENG_IVP);

}
#line 2015 "build/hi_android/hi.y.cpp"
    break;

  case 32: // ENG_ConjV: ENG_CONJ ENG_IVPlist
#line 387 "build/hi_android/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjV->ENG_CONJ ENG_IVPlist");
yylhs.value=sparser->combine_nodes("ENG_ConjV",ENG_CONJ,ENG_IVPlist);

}
#line 2027 "build/hi_android/hi.y.cpp"
    break;

  case 33: // ENG_DP: ENG_Def_Det ENG_N
#line 396 "build/hi_android/hi.y"
{
const node_info& ENG_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Def_Det ENG_N");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Def_Det,ENG_N);

}
#line 2039 "build/hi_android/hi.y.cpp"
    break;

  case 34: // ENG_DP: ENG_Def_Det ENG_Num_Ord
#line 404 "build/hi_android/hi.y"
{
const node_info& ENG_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_Ord=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Def_Det ENG_Num_Ord");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Def_Det,ENG_Num_Ord);

}
#line 2051 "build/hi_android/hi.y.cpp"
    break;

  case 35: // ENG_DP: ENG_Indef_Det_a ENG_N_Sg_0Con_swC
#line 412 "build/hi_android/hi.y"
{
const node_info& ENG_Indef_Det_a=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);

}
#line 2063 "build/hi_android/hi.y.cpp"
    break;

  case 36: // ENG_DP: ENG_Indef_Det_an ENG_N_Sg_0Con_swV
#line 420 "build/hi_android/hi.y"
{
const node_info& ENG_Indef_Det_an=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);

}
#line 2075 "build/hi_android/hi.y.cpp"
    break;

  case 37: // ENG_Def_Det: ENG_Det_stem ENG_lfea_DefDet
#line 429 "build/hi_android/hi.y"
{
const node_info& ENG_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_DefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Def_Det->ENG_Det_stem ENG_lfea_DefDet");
yylhs.value=sparser->combine_nodes("ENG_Def_Det",ENG_Det_stem,ENG_lfea_DefDet);

}
#line 2087 "build/hi_android/hi.y.cpp"
    break;

  case 38: // ENG_Det_stem: t_ENG_DET_Stem
#line 438 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Det_stem",word);

}
#line 2099 "build/hi_android/hi.y.cpp"
    break;

  case 39: // ENG_IVP: ENG_NV ENG_NP
#line 447 "build/hi_android/hi.y"
{
const node_info& ENG_NV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_NV,"ENG_V_Aux","V",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_NP);
}
#line 2111 "build/hi_android/hi.y.cpp"
    break;

  case 40: // ENG_IVP: ENG_NV ENG_PP
#line 455 "build/hi_android/hi.y"
{
const node_info& ENG_NV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_NV,"ENG_V_Aux","V",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
}
#line 2123 "build/hi_android/hi.y.cpp"
    break;

  case 41: // ENG_IVP: ENG_V ENG_AP
#line 463 "build/hi_android/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_AP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_AP);
}
#line 2135 "build/hi_android/hi.y.cpp"
    break;

  case 42: // ENG_IVP: ENG_V ENG_NP
#line 471 "build/hi_android/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
unsigned int leaf_node_id=sparser->add_feature_to_leaf(ENG_V,"ENG_V_Aux","V",std::string("RCV"));
if(leaf_node_id==0) sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_NP);
}
#line 2148 "build/hi_android/hi.y.cpp"
    break;

  case 43: // ENG_IVP: ENG_V ENG_PP
#line 480 "build/hi_android/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
unsigned int leaf_node_id=sparser->add_feature_to_leaf(ENG_V,"ENG_V_Aux","V",std::string("RCV"));
if(leaf_node_id==0) sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
}
#line 2161 "build/hi_android/hi.y.cpp"
    break;

  case 44: // ENG_IVPConj: ENG_IVPConj ENG_ConjV
#line 490 "build/hi_android/hi.y"
{
const node_info& ENG_IVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_IVPConj ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_IVPConj,ENG_ConjV);

}
#line 2173 "build/hi_android/hi.y.cpp"
    break;

  case 45: // ENG_IVPConj: ENG_Vhead ENG_ConjV
#line 498 "build/hi_android/hi.y"
{
const node_info& ENG_Vhead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_Vhead ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_Vhead,ENG_ConjV);

}
#line 2185 "build/hi_android/hi.y.cpp"
    break;

  case 46: // ENG_IVPConj: ENG_Vlisthead ENG_ConjV
#line 506 "build/hi_android/hi.y"
{
const node_info& ENG_Vlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_Vlisthead ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_Vlisthead,ENG_ConjV);

}
#line 2197 "build/hi_android/hi.y.cpp"
    break;

  case 47: // ENG_IVPlist: ENG_IVP ENG_IVP
#line 515 "build/hi_android/hi.y"
{
const node_info& ENG_IVP1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPlist->ENG_IVP ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_IVPlist",ENG_IVP1,ENG_IVP2);

}
#line 2209 "build/hi_android/hi.y.cpp"
    break;

  case 48: // ENG_IVPlist: ENG_IVPlist ENG_IVP
#line 523 "build/hi_android/hi.y"
{
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPlist->ENG_IVPlist ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_IVPlist",ENG_IVPlist,ENG_IVP);

}
#line 2221 "build/hi_android/hi.y.cpp"
    break;

  case 49: // ENG_Indef_Det: ENG_Det_stem ENG_lfea_IndefDet
#line 532 "build/hi_android/hi.y"
{
const node_info& ENG_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_IndefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);

}
#line 2233 "build/hi_android/hi.y.cpp"
    break;

  case 50: // ENG_Indef_Det_a: ENG_Indef_Det ENG_lfea_fwConsonant
#line 541 "build/hi_android/hi.y"
{
const node_info& ENG_Indef_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_fwConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);

}
#line 2245 "build/hi_android/hi.y.cpp"
    break;

  case 51: // ENG_Indef_Det_an: ENG_Indef_Det ENG_lfea_fwVowel
#line 550 "build/hi_android/hi.y"
{
const node_info& ENG_Indef_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_fwVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);

}
#line 2257 "build/hi_android/hi.y.cpp"
    break;

  case 52: // ENG_N: ENG_N_Pl
#line 559 "build/hi_android/hi.y"
{
const node_info& ENG_N_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Pl");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Pl);

}
#line 2268 "build/hi_android/hi.y.cpp"
    break;

  case 53: // ENG_N: ENG_N_Sg
#line 566 "build/hi_android/hi.y"
{
const node_info& ENG_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Sg");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Sg);

}
#line 2279 "build/hi_android/hi.y.cpp"
    break;

  case 54: // ENG_NP: ENG_CAP
#line 574 "build/hi_android/hi.y"
{
const node_info& ENG_CAP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CAP");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_CAP);

}
#line 2290 "build/hi_android/hi.y.cpp"
    break;

  case 55: // ENG_NP: ENG_CNP
#line 581 "build/hi_android/hi.y"
{
const node_info& ENG_CNP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CNP");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_CNP);

}
#line 2301 "build/hi_android/hi.y.cpp"
    break;

  case 56: // ENG_NP: ENG_QPro ENG_CNP
#line 588 "build/hi_android/hi.y"
{
const node_info& ENG_QPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CNP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_QPro ENG_CNP");
yylhs.value=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);

}
#line 2313 "build/hi_android/hi.y.cpp"
    break;

  case 57: // ENG_NV: ENG_NV_Aux ENG_V_Stem
#line 597 "build/hi_android/hi.y"
{
const node_info& ENG_NV_Aux=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_NV_Aux ENG_V_Stem");
yylhs.value=sparser->combine_nodes("ENG_NV",ENG_NV_Aux,ENG_V_Stem);

}
#line 2325 "build/hi_android/hi.y.cpp"
    break;

  case 58: // ENG_NV: ENG_V ENG_VNEG
#line 605 "build/hi_android/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_V ENG_VNEG");
yylhs.value=sparser->combine_nodes("ENG_NV",ENG_V,ENG_VNEG);

}
#line 2337 "build/hi_android/hi.y.cpp"
    break;

  case 59: // ENG_NV_Aux: ENG_V_Aux ENG_VNEG
#line 614 "build/hi_android/hi.y"
{
const node_info& ENG_V_Aux=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV_Aux->ENG_V_Aux ENG_VNEG");
yylhs.value=sparser->combine_nodes("ENG_NV_Aux",ENG_V_Aux,ENG_VNEG);

}
#line 2349 "build/hi_android/hi.y.cpp"
    break;

  case 60: // ENG_N_Pl: ENG_N_Pl_0Con_swC
#line 623 "build/hi_android/hi.y"
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swC);

}
#line 2360 "build/hi_android/hi.y.cpp"
    break;

  case 61: // ENG_N_Pl: ENG_N_Pl_0Con_swC ENG_nCon
#line 630 "build/hi_android/hi.y"
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);

}
#line 2372 "build/hi_android/hi.y.cpp"
    break;

  case 62: // ENG_N_Pl: ENG_N_Pl_0Con_swV
#line 638 "build/hi_android/hi.y"
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swV);

}
#line 2383 "build/hi_android/hi.y.cpp"
    break;

  case 63: // ENG_N_Pl: ENG_N_Pl_0Con_swV ENG_nCon
#line 645 "build/hi_android/hi.y"
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);

}
#line 2395 "build/hi_android/hi.y.cpp"
    break;

  case 64: // ENG_N_Pl: ENG_N_Sg ENG_nCon
#line 653 "build/hi_android/hi.y"
{
//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in 'list file abc def'
//TODO: Any better solution???
YYERROR;
}
#line 2406 "build/hi_android/hi.y.cpp"
    break;

  case 65: // ENG_N_Pl: ENG_nCon
#line 660 "build/hi_android/hi.y"
{
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_nCon");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_nCon);

}
#line 2417 "build/hi_android/hi.y.cpp"
    break;

  case 66: // ENG_N_Pl_0Con: ENG_N_Stem ENG_N_lfea_Pl
#line 668 "build/hi_android/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);

}
#line 2429 "build/hi_android/hi.y.cpp"
    break;

  case 67: // ENG_N_Pl_0Con_swC: ENG_N_Pl_0Con ENG_lfea_swConsonant
#line 677 "build/hi_android/hi.y"
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);

}
#line 2441 "build/hi_android/hi.y.cpp"
    break;

  case 68: // ENG_N_Pl_0Con_swV: ENG_N_Pl_0Con ENG_lfea_swVowel
#line 686 "build/hi_android/hi.y"
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);

}
#line 2453 "build/hi_android/hi.y.cpp"
    break;

  case 69: // ENG_N_Sg: ENG_1Con
#line 695 "build/hi_android/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_1Con");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_1Con);

}
#line 2464 "build/hi_android/hi.y.cpp"
    break;

  case 70: // ENG_N_Sg: ENG_N_Sg_0Con_swC
#line 702 "build/hi_android/hi.y"
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swC);

}
#line 2475 "build/hi_android/hi.y.cpp"
    break;

  case 71: // ENG_N_Sg: ENG_N_Sg_0Con_swC ENG_1Con
#line 709 "build/hi_android/hi.y"
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swC,ENG_1Con);

}
#line 2487 "build/hi_android/hi.y.cpp"
    break;

  case 72: // ENG_N_Sg: ENG_N_Sg_0Con_swV
#line 717 "build/hi_android/hi.y"
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swV);

}
#line 2498 "build/hi_android/hi.y.cpp"
    break;

  case 73: // ENG_N_Sg: ENG_N_Sg_0Con_swV ENG_1Con
#line 724 "build/hi_android/hi.y"
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swV,ENG_1Con);

}
#line 2510 "build/hi_android/hi.y.cpp"
    break;

  case 74: // ENG_N_Sg_0Con: ENG_N_Stem ENG_N_lfea_Sg
#line 733 "build/hi_android/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con",ENG_N_Stem,ENG_N_lfea_Sg);

}
#line 2522 "build/hi_android/hi.y.cpp"
    break;

  case 75: // ENG_N_Sg_0Con_swC: ENG_N_Sg_0Con ENG_lfea_swConsonant
#line 742 "build/hi_android/hi.y"
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);

}
#line 2534 "build/hi_android/hi.y.cpp"
    break;

  case 76: // ENG_N_Sg_0Con_swV: ENG_N_Sg_0Con ENG_lfea_swVowel
#line 751 "build/hi_android/hi.y"
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);

}
#line 2546 "build/hi_android/hi.y.cpp"
    break;

  case 77: // ENG_N_Stem: t_ENG_N_Stem
#line 760 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_Stem",word);

}
#line 2558 "build/hi_android/hi.y.cpp"
    break;

  case 78: // ENG_N_lfea_Pl: t_ENG_N_Pl
#line 769 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Pl);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Pl",word);

}
#line 2570 "build/hi_android/hi.y.cpp"
    break;

  case 79: // ENG_N_lfea_Sg: t_ENG_N_Sg
#line 778 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Sg",word);

}
#line 2582 "build/hi_android/hi.y.cpp"
    break;

  case 80: // ENG_Num: ENG_Num_Pref ENG_Num
#line 787 "build/hi_android/hi.y"
{
const node_info& ENG_Num_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Pref ENG_Num");
yylhs.value=sparser->combine_nodes("ENG_Num",ENG_Num_Pref,ENG_Num);

}
#line 2594 "build/hi_android/hi.y.cpp"
    break;

  case 81: // ENG_Num: ENG_Num_Stem
#line 795 "build/hi_android/hi.y"
{
const node_info& ENG_Num_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Stem");
yylhs.value=sparser->set_node_info("ENG_Num",ENG_Num_Stem);

}
#line 2605 "build/hi_android/hi.y.cpp"
    break;

  case 82: // ENG_Num_Ord: ENG_Num ENG_Num_lfea_Ord
#line 803 "build/hi_android/hi.y"
{
const node_info& ENG_Num=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_lfea_Ord=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num_Ord->ENG_Num ENG_Num_lfea_Ord");
yylhs.value=sparser->combine_nodes("ENG_Num_Ord",ENG_Num,ENG_Num_lfea_Ord);

}
#line 2617 "build/hi_android/hi.y.cpp"
    break;

  case 83: // ENG_Num_Pref: t_ENG_Num_Npref1n
#line 812 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2629 "build/hi_android/hi.y.cpp"
    break;

  case 84: // ENG_Num_Pref: t_ENG_Num_Npref2n
#line 820 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2641 "build/hi_android/hi.y.cpp"
    break;

  case 85: // ENG_Num_Pref: t_ENG_Num_Npref3n
#line 828 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2653 "build/hi_android/hi.y.cpp"
    break;

  case 86: // ENG_Num_Pref: t_ENG_Num_Npref4n
#line 836 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2665 "build/hi_android/hi.y.cpp"
    break;

  case 87: // ENG_Num_Pref: t_ENG_Num_Npref5n
#line 844 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2677 "build/hi_android/hi.y.cpp"
    break;

  case 88: // ENG_Num_Pref: t_ENG_Num_Npref6n
#line 852 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2689 "build/hi_android/hi.y.cpp"
    break;

  case 89: // ENG_Num_Pref: t_ENG_Num_Npref7n
#line 860 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2701 "build/hi_android/hi.y.cpp"
    break;

  case 90: // ENG_Num_Pref: t_ENG_Num_Npref8n
#line 868 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2713 "build/hi_android/hi.y.cpp"
    break;

  case 91: // ENG_Num_Pref: t_ENG_Num_Npref9n
#line 876 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2725 "build/hi_android/hi.y.cpp"
    break;

  case 92: // ENG_Num_Stem: t_ENG_Num_Stem
#line 885 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Stem",word);

}
#line 2737 "build/hi_android/hi.y.cpp"
    break;

  case 93: // ENG_Num_lfea_Ord: t_ENG_Num_Ord
#line 894 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Ord);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_lfea_Ord",word);

}
#line 2749 "build/hi_android/hi.y.cpp"
    break;

  case 94: // ENG_PNVPbar: ENG_VNEG ENG_PVPbar
#line 903 "build/hi_android/hi.y"
{
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PNVPbar->ENG_VNEG ENG_PVPbar");
yylhs.value=sparser->combine_nodes("ENG_PNVPbar",ENG_VNEG,ENG_PVPbar);

}
#line 2761 "build/hi_android/hi.y.cpp"
    break;

  case 95: // ENG_PP: ENG_Prep ENG_NP
#line 912 "build/hi_android/hi.y"
{
const node_info& ENG_Prep=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);

}
#line 2773 "build/hi_android/hi.y.cpp"
    break;

  case 96: // ENG_PVP: ENG_PNVPbar
#line 921 "build/hi_android/hi.y"
{
const node_info& ENG_PNVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVP->ENG_PNVPbar");
yylhs.value=sparser->set_node_info("ENG_PVP",ENG_PNVPbar);

}
#line 2784 "build/hi_android/hi.y.cpp"
    break;

  case 97: // ENG_PVP: ENG_PVPbar
#line 928 "build/hi_android/hi.y"
{
const node_info& ENG_PVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVP->ENG_PVPbar");
yylhs.value=sparser->set_node_info("ENG_PVP",ENG_PVPbar);

}
#line 2795 "build/hi_android/hi.y.cpp"
    break;

  case 98: // ENG_PVPConj: ENG_PVPConj ENG_ConjPVP
#line 936 "build/hi_android/hi.y"
{
const node_info& ENG_PVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPConj ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPConj,ENG_ConjPVP);

}
#line 2807 "build/hi_android/hi.y.cpp"
    break;

  case 99: // ENG_PVPConj: ENG_PVPhead ENG_ConjPVP
#line 944 "build/hi_android/hi.y"
{
const node_info& ENG_PVPhead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPhead ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPhead,ENG_ConjPVP);

}
#line 2819 "build/hi_android/hi.y.cpp"
    break;

  case 100: // ENG_PVPConj: ENG_PVPlisthead ENG_ConjPVP
#line 952 "build/hi_android/hi.y"
{
const node_info& ENG_PVPlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPlisthead ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPlisthead,ENG_ConjPVP);

}
#line 2831 "build/hi_android/hi.y.cpp"
    break;

  case 101: // ENG_PVPbar: ENG_V_Ger ENG_NP
#line 961 "build/hi_android/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPbar->ENG_V_Ger ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_PVPbar",ENG_V_Ger,ENG_NP);
}
#line 2842 "build/hi_android/hi.y.cpp"
    break;

  case 102: // ENG_PVPbar: ENG_V_Ger ENG_PP
#line 968 "build/hi_android/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPbar->ENG_V_Ger ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_PVPbar",ENG_V_Ger,ENG_PP);
}
#line 2853 "build/hi_android/hi.y.cpp"
    break;

  case 103: // ENG_PVPhead: ENG_PVP
#line 976 "build/hi_android/hi.y"
{
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPhead->ENG_PVP");
yylhs.value=sparser->set_node_info("ENG_PVPhead",ENG_PVP);

}
#line 2864 "build/hi_android/hi.y.cpp"
    break;

  case 104: // ENG_PVPlist: ENG_PVP ENG_PVP
#line 984 "build/hi_android/hi.y"
{
const node_info& ENG_PVP1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlist->ENG_PVP ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_PVPlist",ENG_PVP1,ENG_PVP2);

}
#line 2876 "build/hi_android/hi.y.cpp"
    break;

  case 105: // ENG_PVPlist: ENG_PVPlist ENG_PVP
#line 992 "build/hi_android/hi.y"
{
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlist->ENG_PVPlist ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_PVPlist",ENG_PVPlist,ENG_PVP);

}
#line 2888 "build/hi_android/hi.y.cpp"
    break;

  case 106: // ENG_PVPlisthead: ENG_PVPlist
#line 1001 "build/hi_android/hi.y"
{
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlisthead->ENG_PVPlist");
yylhs.value=sparser->set_node_info("ENG_PVPlisthead",ENG_PVPlist);

}
#line 2899 "build/hi_android/hi.y.cpp"
    break;

  case 107: // ENG_Prep: t_ENG_PREP_Stem
#line 1009 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PREP_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Prep",word);

}
#line 2911 "build/hi_android/hi.y.cpp"
    break;

  case 108: // ENG_QPro: t_ENG_QPRO_Stem
#line 1018 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_QPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_QPro",word);

}
#line 2923 "build/hi_android/hi.y.cpp"
    break;

  case 109: // ENG_RC: ENG_RPro ENG_IVP
#line 1027 "build/hi_android/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);

}
#line 2935 "build/hi_android/hi.y.cpp"
    break;

  case 110: // ENG_RC: ENG_RPro ENG_IVPConj
#line 1035 "build/hi_android/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVPConj");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVPConj);

}
#line 2947 "build/hi_android/hi.y.cpp"
    break;

  case 111: // ENG_RC: ENG_RPro ENG_IVPlist
#line 1043 "build/hi_android/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVPlist");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVPlist);

}
#line 2959 "build/hi_android/hi.y.cpp"
    break;

  case 112: // ENG_RPro: ENG_RPro_stem ENG_RPro_lfea_relative
#line 1052 "build/hi_android/hi.y"
{
const node_info& ENG_RPro_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RPro_lfea_relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative");
yylhs.value=sparser->combine_nodes("ENG_RPro",ENG_RPro_stem,ENG_RPro_lfea_relative);

}
#line 2971 "build/hi_android/hi.y.cpp"
    break;

  case 113: // ENG_RPro_lfea_relative: t_ENG_RPRO_Relative
#line 1061 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_RPro_lfea_relative",word);

}
#line 2983 "build/hi_android/hi.y.cpp"
    break;

  case 114: // ENG_RPro_stem: t_ENG_RPRO_Stem
#line 1070 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_RPro_stem",word);

}
#line 2995 "build/hi_android/hi.y.cpp"
    break;

  case 115: // ENG_TP: ENG_Tense_particle ENG_V_Stem
#line 1079 "build/hi_android/hi.y"
{
const node_info& ENG_Tense_particle=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_Tense_particle ENG_V_Stem");
yylhs.value=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_Stem);

}
#line 3007 "build/hi_android/hi.y.cpp"
    break;

  case 116: // ENG_TP: ENG_V_Ger
#line 1087 "build/hi_android/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_V_Ger");
yylhs.value=sparser->set_node_info("ENG_TP",ENG_V_Ger);

}
#line 3018 "build/hi_android/hi.y.cpp"
    break;

  case 117: // ENG_Tense_particle: t_ENG_PAR_Stem
#line 1095 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PAR_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Tense_particle",word);

}
#line 3030 "build/hi_android/hi.y.cpp"
    break;

  case 118: // ENG_V: ENG_V_Aux
#line 1104 "build/hi_android/hi.y"
{
const node_info& ENG_V_Aux=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Aux");
yylhs.value=sparser->set_node_info("ENG_V",ENG_V_Aux);

}
#line 3041 "build/hi_android/hi.y.cpp"
    break;

  case 119: // ENG_V: ENG_V_Stem
#line 1111 "build/hi_android/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");
yylhs.value=sparser->set_node_info("ENG_V",ENG_V_Stem);

}
#line 3052 "build/hi_android/hi.y.cpp"
    break;

  case 120: // ENG_VNEG: ENG_VNEG_Stem
#line 1119 "build/hi_android/hi.y"
{
const node_info& ENG_VNEG_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VNEG->ENG_VNEG_Stem");
yylhs.value=sparser->set_node_info("ENG_VNEG",ENG_VNEG_Stem);

}
#line 3063 "build/hi_android/hi.y.cpp"
    break;

  case 121: // ENG_VNEG_Stem: t_ENG_VNEG_Stem
#line 1127 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_VNEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_VNEG_Stem",word);

}
#line 3075 "build/hi_android/hi.y.cpp"
    break;

  case 122: // ENG_VP: ENG_Vbar1
#line 1136 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1");
yylhs.value=sparser->set_node_info("ENG_VP",ENG_Vbar1);

}
#line 3086 "build/hi_android/hi.y.cpp"
    break;

  case 123: // ENG_VP: ENG_Vbar1 ENG_AdvP
#line 1143 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AdvP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);

}
#line 3098 "build/hi_android/hi.y.cpp"
    break;

  case 124: // ENG_VP: ENG_Vbar1 ENG_PVP
#line 1151 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVP);

}
#line 3110 "build/hi_android/hi.y.cpp"
    break;

  case 125: // ENG_VP: ENG_Vbar1 ENG_PVPConj
#line 1159 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVPConj");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVPConj);

}
#line 3122 "build/hi_android/hi.y.cpp"
    break;

  case 126: // ENG_VP: ENG_Vbar1 ENG_PVPlist
#line 1167 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVPlist");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVPlist);

}
#line 3134 "build/hi_android/hi.y.cpp"
    break;

  case 127: // ENG_VP: ENG_Vbar1 ENG_RC
#line 1175 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_RC");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);

}
#line 3146 "build/hi_android/hi.y.cpp"
    break;

  case 128: // ENG_VP: ENG_Vbar2
#line 1183 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2");
yylhs.value=sparser->set_node_info("ENG_VP",ENG_Vbar2);

}
#line 3157 "build/hi_android/hi.y.cpp"
    break;

  case 129: // ENG_VP: ENG_Vbar2 ENG_PP
#line 1190 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);

}
#line 3169 "build/hi_android/hi.y.cpp"
    break;

  case 130: // ENG_VP: ENG_Vbar2 ENG_RC
#line 1198 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_RC");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);

}
#line 3181 "build/hi_android/hi.y.cpp"
    break;

  case 131: // ENG_VP: ENG_Vbar3 ENG_NP
#line 1206 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar3=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar3 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);

}
#line 3193 "build/hi_android/hi.y.cpp"
    break;

  case 132: // ENG_VP: ENG_Vbar4 ENG_DP
#line 1214 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar4=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar4 ENG_DP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);

}
#line 3205 "build/hi_android/hi.y.cpp"
    break;

  case 133: // ENG_V_Aux: ENG_V_Stem ENG_V_lfea_aux
#line 1223 "build/hi_android/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_aux=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Aux->ENG_V_Stem ENG_V_lfea_aux");
yylhs.value=sparser->combine_nodes("ENG_V_Aux",ENG_V_Stem,ENG_V_lfea_aux);

}
#line 3217 "build/hi_android/hi.y.cpp"
    break;

  case 134: // ENG_V_Ger: ENG_V_Stem ENG_V_lfea_ger
#line 1232 "build/hi_android/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_ger=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Ger->ENG_V_Stem ENG_V_lfea_ger");
yylhs.value=sparser->combine_nodes("ENG_V_Ger",ENG_V_Stem,ENG_V_lfea_ger);

}
#line 3229 "build/hi_android/hi.y.cpp"
    break;

  case 135: // ENG_V_Stem: t_ENG_V_Stem
#line 1241 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_Stem",word);

}
#line 3241 "build/hi_android/hi.y.cpp"
    break;

  case 136: // ENG_V_lfea_aux: t_ENG_V_Aux
#line 1250 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Aux);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_aux",word);

}
#line 3253 "build/hi_android/hi.y.cpp"
    break;

  case 137: // ENG_V_lfea_ger: t_ENG_V_Gerund
#line 1259 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Gerund);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_ger",word);

}
#line 3265 "build/hi_android/hi.y.cpp"
    break;

  case 138: // ENG_Vbar1: ENG_V ENG_NP
#line 1268 "build/hi_android/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
}
#line 3277 "build/hi_android/hi.y.cpp"
    break;

  case 139: // ENG_Vbar2: ENG_Vbar1 ENG_NP
#line 1277 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);

}
#line 3289 "build/hi_android/hi.y.cpp"
    break;

  case 140: // ENG_Vbar2: ENG_Vbar1 ENG_PP
#line 1285 "build/hi_android/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_PP);

}
#line 3301 "build/hi_android/hi.y.cpp"
    break;

  case 141: // ENG_Vbar3: ENG_V ENG_AdvP
#line 1294 "build/hi_android/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AdvP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar3->ENG_V ENG_AdvP");
yylhs.value=sparser->combine_nodes("ENG_Vbar3",ENG_V,ENG_AdvP);

}
#line 3313 "build/hi_android/hi.y.cpp"
    break;

  case 142: // ENG_Vbar4: ENG_DP ENG_V
#line 1303 "build/hi_android/hi.y"
{
const node_info& ENG_DP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
}
#line 3325 "build/hi_android/hi.y.cpp"
    break;

  case 143: // ENG_Vbar4: ENG_TP ENG_V
#line 1311 "build/hi_android/hi.y"
{
const node_info& ENG_TP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
}
#line 3337 "build/hi_android/hi.y.cpp"
    break;

  case 144: // ENG_Vbar4: ENG_V
#line 1319 "build/hi_android/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_V");
yylhs.value=sparser->set_node_info("ENG_Vbar4",ENG_V);
}
#line 3348 "build/hi_android/hi.y.cpp"
    break;

  case 145: // ENG_Vhead: ENG_IVP
#line 1327 "build/hi_android/hi.y"
{
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vhead->ENG_IVP");
yylhs.value=sparser->set_node_info("ENG_Vhead",ENG_IVP);

}
#line 3359 "build/hi_android/hi.y.cpp"
    break;

  case 146: // ENG_Vlisthead: ENG_IVPlist
#line 1335 "build/hi_android/hi.y"
{
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vlisthead->ENG_IVPlist");
yylhs.value=sparser->set_node_info("ENG_Vlisthead",ENG_IVPlist);

}
#line 3370 "build/hi_android/hi.y.cpp"
    break;

  case 147: // ENG_lfea_DefDet: t_ENG_DET_Def
#line 1343 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Def);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_DefDet",word);

}
#line 3382 "build/hi_android/hi.y.cpp"
    break;

  case 148: // ENG_lfea_IndefDet: t_ENG_DET_Indef
#line 1352 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Indef);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_IndefDet",word);

}
#line 3394 "build/hi_android/hi.y.cpp"
    break;

  case 149: // ENG_lfea_fwConsonant: t_ENG_DET_fwConsonant
#line 1361 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_fwConsonant",word);

}
#line 3406 "build/hi_android/hi.y.cpp"
    break;

  case 150: // ENG_lfea_fwVowel: t_ENG_DET_fwVowel
#line 1370 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_fwVowel",word);

}
#line 3418 "build/hi_android/hi.y.cpp"
    break;

  case 151: // ENG_lfea_swConsonant: t_ENG_N_swConsonant
#line 1379 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_swConsonant",word);

}
#line 3430 "build/hi_android/hi.y.cpp"
    break;

  case 152: // ENG_lfea_swVowel: t_ENG_N_swVowel
#line 1388 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_swVowel",word);

}
#line 3442 "build/hi_android/hi.y.cpp"
    break;

  case 153: // ENG_nCon: ENG_1Con ENG_Con
#line 1397 "build/hi_android/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_1Con ENG_Con");
yylhs.value=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);

}
#line 3454 "build/hi_android/hi.y.cpp"
    break;

  case 154: // ENG_nCon: ENG_nCon ENG_Con
#line 1405 "build/hi_android/hi.y"
{
const node_info& ENG_nCon=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_nCon ENG_Con");
yylhs.value=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);

}
#line 3466 "build/hi_android/hi.y.cpp"
    break;

  case 155: // HUN_1Con: HUN_Con
#line 1414 "build/hi_android/hi.y"
{
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_1Con->HUN_Con");
yylhs.value=sparser->set_node_info("HUN_1Con",HUN_Con);

}
#line 3477 "build/hi_android/hi.y.cpp"
    break;

  case 156: // HUN_A0NEG: HUN_Adj
#line 1422 "build/hi_android/hi.y"
{
const node_info& HUN_Adj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_A0NEG->HUN_Adj");
yylhs.value=sparser->set_node_info("HUN_A0NEG",HUN_Adj);

}
#line 3488 "build/hi_android/hi.y.cpp"
    break;

  case 157: // HUN_ANEG: HUN_Neg HUN_Adj
#line 1430 "build/hi_android/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Adj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ANEG->HUN_Neg HUN_Adj");
yylhs.value=sparser->combine_nodes("HUN_ANEG",HUN_Neg,HUN_Adj);

}
#line 3500 "build/hi_android/hi.y.cpp"
    break;

  case 158: // HUN_ANP: HUN_N_Sg HUN_N_Sg
#line 1439 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ANP->HUN_N_Sg HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_ANP",HUN_N_Sg1,HUN_N_Sg2);

}
#line 3512 "build/hi_android/hi.y.cpp"
    break;

  case 159: // HUN_AN_Acc: HUN_N_Acc END
#line 1448 "build/hi_android/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AN_Acc->HUN_N_Acc END");
yylhs.value=sparser->set_node_info("HUN_AN_Acc",HUN_N_Acc);
}
#line 3522 "build/hi_android/hi.y.cpp"
    break;

  case 160: // HUN_AP: HUN_Abar3 HUN_N_Acc
#line 1455 "build/hi_android/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Abar3 HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Abar3,HUN_N_Acc);

}
#line 3534 "build/hi_android/hi.y.cpp"
    break;

  case 161: // HUN_AP: HUN_Abar4 HUN_ConjA_End
#line 1463 "build/hi_android/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjA_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Abar4 HUN_ConjA_End");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Abar4,HUN_ConjA_End);

}
#line 3546 "build/hi_android/hi.y.cpp"
    break;

  case 162: // HUN_AP: HUN_Alist HUN_N_Acc
#line 1471 "build/hi_android/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Alist HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Alist,HUN_N_Acc);

}
#line 3558 "build/hi_android/hi.y.cpp"
    break;

  case 163: // HUN_Abar1: HUN_N_Acc HUN_A0NEG
#line 1480 "build/hi_android/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Acc HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Acc,HUN_A0NEG);

}
#line 3570 "build/hi_android/hi.y.cpp"
    break;

  case 164: // HUN_Abar1: HUN_N_Ins HUN_A0NEG
#line 1488 "build/hi_android/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Ins HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Ins,HUN_A0NEG);

}
#line 3582 "build/hi_android/hi.y.cpp"
    break;

  case 165: // HUN_Abar1: HUN_N_Sub HUN_A0NEG
#line 1496 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Sub HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Sub,HUN_A0NEG);

}
#line 3594 "build/hi_android/hi.y.cpp"
    break;

  case 166: // HUN_Abar1N: HUN_N_Acc HUN_ANEG
#line 1505 "build/hi_android/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Acc HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Acc,HUN_ANEG);

}
#line 3606 "build/hi_android/hi.y.cpp"
    break;

  case 167: // HUN_Abar1N: HUN_N_Ins HUN_ANEG
#line 1513 "build/hi_android/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Ins HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Ins,HUN_ANEG);

}
#line 3618 "build/hi_android/hi.y.cpp"
    break;

  case 168: // HUN_Abar1N: HUN_N_Sub HUN_ANEG
#line 1521 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Sub HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Sub,HUN_ANEG);

}
#line 3630 "build/hi_android/hi.y.cpp"
    break;

  case 169: // HUN_Abar2: HUN_Abar1
#line 1530 "build/hi_android/hi.y"
{
const node_info& HUN_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2->HUN_Abar1");
yylhs.value=sparser->set_node_info("HUN_Abar2",HUN_Abar1);

}
#line 3641 "build/hi_android/hi.y.cpp"
    break;

  case 170: // HUN_Abar2N: HUN_Abar1N
#line 1538 "build/hi_android/hi.y"
{
const node_info& HUN_Abar1N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2N->HUN_Abar1N");
yylhs.value=sparser->set_node_info("HUN_Abar2N",HUN_Abar1N);

}
#line 3652 "build/hi_android/hi.y.cpp"
    break;

  case 171: // HUN_Abar2N: HUN_NAbar1
#line 1545 "build/hi_android/hi.y"
{
const node_info& HUN_NAbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2N->HUN_NAbar1");
yylhs.value=sparser->set_node_info("HUN_Abar2N",HUN_NAbar1);

}
#line 3663 "build/hi_android/hi.y.cpp"
    break;

  case 172: // HUN_Abar3: HUN_Abar2
#line 1553 "build/hi_android/hi.y"
{
const node_info& HUN_Abar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3->HUN_Abar2");
yylhs.value=sparser->set_node_info("HUN_Abar3",HUN_Abar2);

}
#line 3674 "build/hi_android/hi.y.cpp"
    break;

  case 173: // HUN_Abar3: HUN_Abar2N
#line 1560 "build/hi_android/hi.y"
{
const node_info& HUN_Abar2N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3->HUN_Abar2N");
yylhs.value=sparser->set_node_info("HUN_Abar3",HUN_Abar2N);

}
#line 3685 "build/hi_android/hi.y.cpp"
    break;

  case 174: // HUN_Abar3_End: HUN_Abar3 HUN_AN_Acc
#line 1568 "build/hi_android/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3_End->HUN_Abar3 HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_Abar3_End",HUN_Abar3,HUN_AN_Acc);

}
#line 3697 "build/hi_android/hi.y.cpp"
    break;

  case 175: // HUN_Abar4: HUN_A0NEG
#line 1577 "build/hi_android/hi.y"
{
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_A0NEG");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_A0NEG);

}
#line 3708 "build/hi_android/hi.y.cpp"
    break;

  case 176: // HUN_Abar4: HUN_ANEG
#line 1584 "build/hi_android/hi.y"
{
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_ANEG");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_ANEG);

}
#line 3719 "build/hi_android/hi.y.cpp"
    break;

  case 177: // HUN_Abar4: HUN_Abar3
#line 1591 "build/hi_android/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar3");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_Abar3);

}
#line 3730 "build/hi_android/hi.y.cpp"
    break;

  case 178: // HUN_Abar4: HUN_Abar4 HUN_ConjA
#line 1598 "build/hi_android/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar4 HUN_ConjA");
yylhs.value=sparser->combine_nodes("HUN_Abar4",HUN_Abar4,HUN_ConjA);

}
#line 3742 "build/hi_android/hi.y.cpp"
    break;

  case 179: // HUN_Abar4: HUN_Abar4 HUN_ConjAlist
#line 1606 "build/hi_android/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjAlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar4 HUN_ConjAlist");
yylhs.value=sparser->combine_nodes("HUN_Abar4",HUN_Abar4,HUN_ConjAlist);

}
#line 3754 "build/hi_android/hi.y.cpp"
    break;

  case 180: // HUN_Abar4: HUN_Alist
#line 1614 "build/hi_android/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Alist");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_Alist);

}
#line 3765 "build/hi_android/hi.y.cpp"
    break;

  case 181: // HUN_Adj: HUN_Adj_Stem
#line 1622 "build/hi_android/hi.y"
{
const node_info& HUN_Adj_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Adj->HUN_Adj_Stem");
yylhs.value=sparser->set_node_info("HUN_Adj",HUN_Adj_Stem);

}
#line 3776 "build/hi_android/hi.y.cpp"
    break;

  case 182: // HUN_Adj_Stem: t_HUN_Adj_Stem
#line 1630 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Adj_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Adj_Stem",word);

}
#line 3788 "build/hi_android/hi.y.cpp"
    break;

  case 183: // HUN_Alist: HUN_Abar3 HUN_Abar3
#line 1639 "build/hi_android/hi.y"
{
const node_info& HUN_Abar31=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar32=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist->HUN_Abar3 HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_Alist",HUN_Abar31,HUN_Abar32);

}
#line 3800 "build/hi_android/hi.y.cpp"
    break;

  case 184: // HUN_Alist: HUN_Alist HUN_Abar3
#line 1647 "build/hi_android/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist->HUN_Alist HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_Alist",HUN_Alist,HUN_Abar3);

}
#line 3812 "build/hi_android/hi.y.cpp"
    break;

  case 185: // HUN_Alist_End: HUN_Alist HUN_AN_Acc
#line 1656 "build/hi_android/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist_End->HUN_Alist HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_Alist_End",HUN_Alist,HUN_AN_Acc);

}
#line 3824 "build/hi_android/hi.y.cpp"
    break;

  case 186: // HUN_Con: HUN_lfea_swConsonant HUN_Con
#line 1665 "build/hi_android/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Con->HUN_lfea_swConsonant HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_Con",HUN_lfea_swConsonant,HUN_Con);

}
#line 3836 "build/hi_android/hi.y.cpp"
    break;

  case 187: // HUN_Con: HUN_lfea_swVowel HUN_Con
#line 1673 "build/hi_android/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Con->HUN_lfea_swVowel HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_Con",HUN_lfea_swVowel,HUN_Con);

}
#line 3848 "build/hi_android/hi.y.cpp"
    break;

  case 188: // HUN_Con: t_HUN_CON_Stem
#line 1681 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con",word);

}
#line 3860 "build/hi_android/hi.y.cpp"
    break;

  case 189: // HUN_Con_lfea_Acc: t_HUN_CON_Acc
#line 1690 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Acc",word);

}
#line 3872 "build/hi_android/hi.y.cpp"
    break;

  case 190: // HUN_Con_lfea_Dat: t_HUN_CON_Dat
#line 1699 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Dat",word);

}
#line 3884 "build/hi_android/hi.y.cpp"
    break;

  case 191: // HUN_Con_lfea_Ins: t_HUN_CON_Ins
#line 1708 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Ins);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Ins",word);

}
#line 3896 "build/hi_android/hi.y.cpp"
    break;

  case 192: // HUN_Con_lfea_Sub: t_HUN_CON_Sub
#line 1717 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Sub);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Sub",word);

}
#line 3908 "build/hi_android/hi.y.cpp"
    break;

  case 193: // HUN_Conj: HUN_Conj_Stem
#line 1726 "build/hi_android/hi.y"
{
const node_info& HUN_Conj_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Conj->HUN_Conj_Stem");
yylhs.value=sparser->set_node_info("HUN_Conj",HUN_Conj_Stem);

}
#line 3919 "build/hi_android/hi.y.cpp"
    break;

  case 194: // HUN_ConjA: HUN_Conj HUN_A0NEG
#line 1734 "build/hi_android/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_A0NEG);

}
#line 3931 "build/hi_android/hi.y.cpp"
    break;

  case 195: // HUN_ConjA: HUN_Conj HUN_ANEG
#line 1742 "build/hi_android/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_ANEG);

}
#line 3943 "build/hi_android/hi.y.cpp"
    break;

  case 196: // HUN_ConjA: HUN_Conj HUN_Abar3
#line 1750 "build/hi_android/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_Abar3);

}
#line 3955 "build/hi_android/hi.y.cpp"
    break;

  case 197: // HUN_ConjA: HUN_Conj HUN_Alist
#line 1758 "build/hi_android/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_Alist");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_Alist);

}
#line 3967 "build/hi_android/hi.y.cpp"
    break;

  case 198: // HUN_ConjA_End: HUN_ConjA HUN_AN_Acc
#line 1767 "build/hi_android/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_AN_Acc);

}
#line 3979 "build/hi_android/hi.y.cpp"
    break;

  case 199: // HUN_ConjA_End: HUN_ConjA HUN_Abar3_End
#line 1775 "build/hi_android/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_Abar3_End");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_Abar3_End);

}
#line 3991 "build/hi_android/hi.y.cpp"
    break;

  case 200: // HUN_ConjA_End: HUN_ConjA HUN_Alist_End
#line 1783 "build/hi_android/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_Alist_End");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_Alist_End);

}
#line 4003 "build/hi_android/hi.y.cpp"
    break;

  case 201: // HUN_ConjAlist: HUN_ConjA HUN_Abar3
#line 1792 "build/hi_android/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjAlist->HUN_ConjA HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_ConjAlist",HUN_ConjA,HUN_Abar3);

}
#line 4015 "build/hi_android/hi.y.cpp"
    break;

  case 202: // HUN_ConjAlist: HUN_ConjA HUN_Alist
#line 1800 "build/hi_android/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjAlist->HUN_ConjA HUN_Alist");
yylhs.value=sparser->combine_nodes("HUN_ConjAlist",HUN_ConjA,HUN_Alist);

}
#line 4027 "build/hi_android/hi.y.cpp"
    break;

  case 203: // HUN_ConjV: HUN_Conj HUN_INVP
#line 1809 "build/hi_android/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_INVP);

}
#line 4039 "build/hi_android/hi.y.cpp"
    break;

  case 204: // HUN_ConjV: HUN_Conj HUN_IVP
#line 1817 "build/hi_android/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_IVP);

}
#line 4051 "build/hi_android/hi.y.cpp"
    break;

  case 205: // HUN_ConjV: HUN_Conj HUN_IVPlist
#line 1825 "build/hi_android/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_IVPlist");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_IVPlist);

}
#line 4063 "build/hi_android/hi.y.cpp"
    break;

  case 206: // HUN_Conj_Stem: t_HUN_Conj_Stem
#line 1834 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Conj_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Conj_Stem",word);

}
#line 4075 "build/hi_android/hi.y.cpp"
    break;

  case 207: // HUN_DP: HUN_DPbar HUN_N_Acc
#line 1843 "build/hi_android/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Acc);

}
#line 4087 "build/hi_android/hi.y.cpp"
    break;

  case 208: // HUN_DP: HUN_DPbar HUN_N_Dat
#line 1851 "build/hi_android/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Dat);

}
#line 4099 "build/hi_android/hi.y.cpp"
    break;

  case 209: // HUN_DP: HUN_DPbar HUN_N_Ine
#line 1859 "build/hi_android/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Ine");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Ine);

}
#line 4111 "build/hi_android/hi.y.cpp"
    break;

  case 210: // HUN_DPbar: HUN_Def_Det_a HUN_lfea_swConsonant
#line 1868 "build/hi_android/hi.y"
{
const node_info& HUN_Def_Det_a=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_a HUN_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_a,HUN_lfea_swConsonant);

}
#line 4123 "build/hi_android/hi.y.cpp"
    break;

  case 211: // HUN_DPbar: HUN_Def_Det_az HUN_lfea_swVowel
#line 1876 "build/hi_android/hi.y"
{
const node_info& HUN_Def_Det_az=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_az HUN_lfea_swVowel");
yylhs.value=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_az,HUN_lfea_swVowel);

}
#line 4135 "build/hi_android/hi.y.cpp"
    break;

  case 212: // HUN_Def_Det: HUN_Det_stem HUN_lfea_DefDet
#line 1885 "build/hi_android/hi.y"
{
const node_info& HUN_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_DefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det->HUN_Det_stem HUN_lfea_DefDet");
yylhs.value=sparser->combine_nodes("HUN_Def_Det",HUN_Det_stem,HUN_lfea_DefDet);

}
#line 4147 "build/hi_android/hi.y.cpp"
    break;

  case 213: // HUN_Def_Det_a: HUN_Def_Det HUN_lfea_fwConsonant
#line 1894 "build/hi_android/hi.y"
{
const node_info& HUN_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_fwConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det_a->HUN_Def_Det HUN_lfea_fwConsonant");
yylhs.value=sparser->combine_nodes("HUN_Def_Det_a",HUN_Def_Det,HUN_lfea_fwConsonant);

}
#line 4159 "build/hi_android/hi.y.cpp"
    break;

  case 214: // HUN_Def_Det_az: HUN_Def_Det HUN_lfea_fwVowel
#line 1903 "build/hi_android/hi.y"
{
const node_info& HUN_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_fwVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det_az->HUN_Def_Det HUN_lfea_fwVowel");
yylhs.value=sparser->combine_nodes("HUN_Def_Det_az",HUN_Def_Det,HUN_lfea_fwVowel);

}
#line 4171 "build/hi_android/hi.y.cpp"
    break;

  case 215: // HUN_Det_stem: t_HUN_Det_Stem
#line 1912 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Det_stem",word);

}
#line 4183 "build/hi_android/hi.y.cpp"
    break;

  case 216: // HUN_Empty: %empty
#line 1921 "build/hi_android/hi.y"
{
lexicon empty;
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Empty->%empty");
yylhs.value=sparser->set_node_info("HUN_Empty",empty);
}
#line 4193 "build/hi_android/hi.y.cpp"
    break;

  case 217: // HUN_INVP: HUN_NP HUN_INVPbar2
#line 1928 "build/hi_android/hi.y"
{
const node_info& HUN_NP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVPbar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_NP HUN_INVPbar2");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_NP,HUN_INVPbar2);

}
#line 4205 "build/hi_android/hi.y.cpp"
    break;

  case 218: // HUN_INVP: HUN_Neg HUN_INVPbar
#line 1936 "build/hi_android/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_Neg HUN_INVPbar");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_Neg,HUN_INVPbar);

}
#line 4217 "build/hi_android/hi.y.cpp"
    break;

  case 219: // HUN_INVP: HUN_Neg HUN_IVPbar
#line 1944 "build/hi_android/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_Neg HUN_IVPbar");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_Neg,HUN_IVPbar);

}
#line 4229 "build/hi_android/hi.y.cpp"
    break;

  case 220: // HUN_INVPbar: HUN_V HUN_N_Ins
#line 1953 "build/hi_android/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar->HUN_V HUN_N_Ins");
yylhs.value=sparser->combine_nodes("HUN_INVPbar",HUN_V,HUN_N_Ins);
}
#line 4241 "build/hi_android/hi.y.cpp"
    break;

  case 221: // HUN_INVPbar: HUN_V HUN_N_Sub
#line 1961 "build/hi_android/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar->HUN_V HUN_N_Sub");
yylhs.value=sparser->combine_nodes("HUN_INVPbar",HUN_V,HUN_N_Sub);
}
#line 4253 "build/hi_android/hi.y.cpp"
    break;

  case 222: // HUN_INVPbar2: HUN_Neg HUN_V
#line 1970 "build/hi_android/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar2->HUN_Neg HUN_V");
yylhs.value=sparser->combine_nodes("HUN_INVPbar2",HUN_Neg,HUN_V);
}
#line 4265 "build/hi_android/hi.y.cpp"
    break;

  case 223: // HUN_IVP: HUN_IVPbar
#line 1979 "build/hi_android/hi.y"
{
const node_info& HUN_IVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVP->HUN_IVPbar");
yylhs.value=sparser->set_node_info("HUN_IVP",HUN_IVPbar);

}
#line 4276 "build/hi_android/hi.y.cpp"
    break;

  case 224: // HUN_IVPConj: HUN_IVPConj HUN_ConjV
#line 1987 "build/hi_android/hi.y"
{
const node_info& HUN_IVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_IVPConj HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_IVPConj,HUN_ConjV);

}
#line 4288 "build/hi_android/hi.y.cpp"
    break;

  case 225: // HUN_IVPConj: HUN_Vhead HUN_ConjV
#line 1995 "build/hi_android/hi.y"
{
const node_info& HUN_Vhead=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_Vhead HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_Vhead,HUN_ConjV);

}
#line 4300 "build/hi_android/hi.y.cpp"
    break;

  case 226: // HUN_IVPConj: HUN_Vlisthead HUN_ConjV
#line 2003 "build/hi_android/hi.y"
{
const node_info& HUN_Vlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_Vlisthead HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_Vlisthead,HUN_ConjV);

}
#line 4312 "build/hi_android/hi.y.cpp"
    break;

  case 227: // HUN_IVPbar: HUN_N_Acc HUN_V
#line 2012 "build/hi_android/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Acc HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_V,HUN_N_Acc);
}
#line 4324 "build/hi_android/hi.y.cpp"
    break;

  case 228: // HUN_IVPbar: HUN_N_Ins HUN_V
#line 2020 "build/hi_android/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Ins HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_N_Ins,HUN_V);
}
#line 4336 "build/hi_android/hi.y.cpp"
    break;

  case 229: // HUN_IVPbar: HUN_N_Sub HUN_V
#line 2028 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Sub HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_N_Sub,HUN_V);
}
#line 4348 "build/hi_android/hi.y.cpp"
    break;

  case 230: // HUN_IVPbar: HUN_V HUN_N_Acc
#line 2036 "build/hi_android/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_V HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_V,HUN_N_Acc);
}
#line 4360 "build/hi_android/hi.y.cpp"
    break;

  case 231: // HUN_IVPlist: HUN_INVP HUN_INVP
#line 2045 "build/hi_android/hi.y"
{
const node_info& HUN_INVP1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_INVP HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_INVP1,HUN_INVP2);

}
#line 4372 "build/hi_android/hi.y.cpp"
    break;

  case 232: // HUN_IVPlist: HUN_INVP HUN_IVP
#line 2053 "build/hi_android/hi.y"
{
const node_info& HUN_INVP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_INVP HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_INVP,HUN_IVP);

}
#line 4384 "build/hi_android/hi.y.cpp"
    break;

  case 233: // HUN_IVPlist: HUN_IVP HUN_INVP
#line 2061 "build/hi_android/hi.y"
{
const node_info& HUN_IVP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVP HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVP,HUN_INVP);

}
#line 4396 "build/hi_android/hi.y.cpp"
    break;

  case 234: // HUN_IVPlist: HUN_IVP HUN_IVP
#line 2069 "build/hi_android/hi.y"
{
const node_info& HUN_IVP1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVP HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVP1,HUN_IVP2);

}
#line 4408 "build/hi_android/hi.y.cpp"
    break;

  case 235: // HUN_IVPlist: HUN_IVPlist HUN_INVP
#line 2077 "build/hi_android/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVPlist HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVPlist,HUN_INVP);

}
#line 4420 "build/hi_android/hi.y.cpp"
    break;

  case 236: // HUN_IVPlist: HUN_IVPlist HUN_IVP
#line 2085 "build/hi_android/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVPlist HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVPlist,HUN_IVP);

}
#line 4432 "build/hi_android/hi.y.cpp"
    break;

  case 237: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2
#line 2094 "build/hi_android/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);
}
#line 4444 "build/hi_android/hi.y.cpp"
    break;

  case 238: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_ConjIndefSg2
#line 2102 "build/hi_android/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_ConjIndefSg2=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjIndefSg2");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjIndefSg2);
}
#line 4456 "build/hi_android/hi.y.cpp"
    break;

  case 239: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_DefSg1
#line 2110 "build/hi_android/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_DefSg1=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_DefSg1");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_DefSg1);
}
#line 4468 "build/hi_android/hi.y.cpp"
    break;

  case 240: // HUN_ImpVerbPfx: HUN_ImpVerb HUN_Vbpfx
#line 2119 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Vbpfx=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerbPfx->HUN_ImpVerb HUN_Vbpfx");
yylhs.value=sparser->combine_nodes("HUN_ImpVerbPfx",HUN_ImpVerb,HUN_Vbpfx);

}
#line 4480 "build/hi_android/hi.y.cpp"
    break;

  case 241: // HUN_NAbar1: HUN_Neg HUN_Abar1
#line 2128 "build/hi_android/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NAbar1->HUN_Neg HUN_Abar1");
yylhs.value=sparser->combine_nodes("HUN_NAbar1",HUN_Neg,HUN_Abar1);

}
#line 4492 "build/hi_android/hi.y.cpp"
    break;

  case 242: // HUN_NP: HUN_N_Acc
#line 2137 "build/hi_android/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Acc");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Acc);

}
#line 4503 "build/hi_android/hi.y.cpp"
    break;

  case 243: // HUN_NP: HUN_N_Ins
#line 2144 "build/hi_android/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Ins");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Ins);

}
#line 4514 "build/hi_android/hi.y.cpp"
    break;

  case 244: // HUN_NP: HUN_N_Sg
#line 2151 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Sg");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Sg);

}
#line 4525 "build/hi_android/hi.y.cpp"
    break;

  case 245: // HUN_NP: HUN_N_Sub
#line 2158 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Sub");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Sub);

}
#line 4536 "build/hi_android/hi.y.cpp"
    break;

  case 246: // HUN_N_Acc: HUN_ANP HUN_Noun_lfea_Acc
#line 2166 "build/hi_android/hi.y"
{
const node_info& HUN_ANP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_ANP HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_ANP,HUN_Noun_lfea_Acc);

}
#line 4548 "build/hi_android/hi.y.cpp"
    break;

  case 247: // HUN_N_Acc: HUN_N_Pl HUN_Noun_lfea_Acc
#line 2174 "build/hi_android/hi.y"
{
const node_info& HUN_N_Pl=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Pl HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Pl,HUN_Noun_lfea_Acc);

}
#line 4560 "build/hi_android/hi.y.cpp"
    break;

  case 248: // HUN_N_Acc: HUN_N_Sg HUN_Con_lfea_Acc
#line 2182 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Con_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Con_lfea_Acc);

}
#line 4572 "build/hi_android/hi.y.cpp"
    break;

  case 249: // HUN_N_Acc: HUN_N_Sg HUN_Noun_lfea_Acc
#line 2190 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Noun_lfea_Acc);

}
#line 4584 "build/hi_android/hi.y.cpp"
    break;

  case 250: // HUN_N_Acc: HUN_Num HUN_Num_lfea_Acc
#line 2198 "build/hi_android/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_Num HUN_Num_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_Num,HUN_Num_lfea_Acc);

}
#line 4596 "build/hi_android/hi.y.cpp"
    break;

  case 251: // HUN_N_Acc: HUN_Nums HUN_Num_lfea_Acc
#line 2206 "build/hi_android/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_Nums HUN_Num_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_Nums,HUN_Num_lfea_Acc);

}
#line 4608 "build/hi_android/hi.y.cpp"
    break;

  case 252: // HUN_N_Dat: HUN_N_Sg HUN_Con_lfea_Dat
#line 2215 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Con_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Con_lfea_Dat);

}
#line 4620 "build/hi_android/hi.y.cpp"
    break;

  case 253: // HUN_N_Dat: HUN_N_Sg HUN_Noun_lfea_Dat
#line 2223 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Noun_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Noun_lfea_Dat);

}
#line 4632 "build/hi_android/hi.y.cpp"
    break;

  case 254: // HUN_N_Dat: HUN_N_Sg HUN_Noun_lfea_Del
#line 2231 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Del=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Noun_lfea_Del");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Noun_lfea_Del);

}
#line 4644 "build/hi_android/hi.y.cpp"
    break;

  case 255: // HUN_N_Dat: HUN_Num HUN_Num_lfea_Dat
#line 2239 "build/hi_android/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Num HUN_Num_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Num,HUN_Num_lfea_Dat);

}
#line 4656 "build/hi_android/hi.y.cpp"
    break;

  case 256: // HUN_N_Dat: HUN_Num HUN_Num_lfea_Del
#line 2247 "build/hi_android/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Del=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Num HUN_Num_lfea_Del");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Num,HUN_Num_lfea_Del);

}
#line 4668 "build/hi_android/hi.y.cpp"
    break;

  case 257: // HUN_N_Dat: HUN_Nums HUN_Num_lfea_Dat
#line 2255 "build/hi_android/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Nums HUN_Num_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Nums,HUN_Num_lfea_Dat);

}
#line 4680 "build/hi_android/hi.y.cpp"
    break;

  case 258: // HUN_N_Ine: HUN_N_Pl HUN_Noun_lfea_Ine
#line 2264 "build/hi_android/hi.y"
{
const node_info& HUN_N_Pl=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ine->HUN_N_Pl HUN_Noun_lfea_Ine");
yylhs.value=sparser->combine_nodes("HUN_N_Ine",HUN_N_Pl,HUN_Noun_lfea_Ine);

}
#line 4692 "build/hi_android/hi.y.cpp"
    break;

  case 259: // HUN_N_Ine: HUN_N_Sg HUN_Noun_lfea_Ine
#line 2272 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ine->HUN_N_Sg HUN_Noun_lfea_Ine");
yylhs.value=sparser->combine_nodes("HUN_N_Ine",HUN_N_Sg,HUN_Noun_lfea_Ine);

}
#line 4704 "build/hi_android/hi.y.cpp"
    break;

  case 260: // HUN_N_Ins: HUN_N_Sg HUN_Con_lfea_Ins
#line 2281 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ins->HUN_N_Sg HUN_Con_lfea_Ins");
yylhs.value=sparser->combine_nodes("HUN_N_Ins",HUN_N_Sg,HUN_Con_lfea_Ins);

}
#line 4716 "build/hi_android/hi.y.cpp"
    break;

  case 261: // HUN_N_Pl: HUN_Noun_Stem HUN_Noun_lfea_Plur
#line 2290 "build/hi_android/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Plur=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Pl->HUN_Noun_Stem HUN_Noun_lfea_Plur");
yylhs.value=sparser->combine_nodes("HUN_N_Pl",HUN_Noun_Stem,HUN_Noun_lfea_Plur);

}
#line 4728 "build/hi_android/hi.y.cpp"
    break;

  case 262: // HUN_N_Sg: HUN_1Con
#line 2299 "build/hi_android/hi.y"
{
const node_info& HUN_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_1Con");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_1Con);

}
#line 4739 "build/hi_android/hi.y.cpp"
    break;

  case 263: // HUN_N_Sg: HUN_Noun_Stem
#line 2306 "build/hi_android/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_Noun_Stem");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_Noun_Stem);

}
#line 4750 "build/hi_android/hi.y.cpp"
    break;

  case 264: // HUN_N_Sg: HUN_nCon
#line 2313 "build/hi_android/hi.y"
{
const node_info& HUN_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_nCon");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_nCon);

}
#line 4761 "build/hi_android/hi.y.cpp"
    break;

  case 265: // HUN_N_Sub: HUN_N_Sg HUN_Con_lfea_Sub
#line 2321 "build/hi_android/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Sub=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sub->HUN_N_Sg HUN_Con_lfea_Sub");
yylhs.value=sparser->combine_nodes("HUN_N_Sub",HUN_N_Sg,HUN_Con_lfea_Sub);

}
#line 4773 "build/hi_android/hi.y.cpp"
    break;

  case 266: // HUN_Neg: HUN_Neg_Stem
#line 2330 "build/hi_android/hi.y"
{
const node_info& HUN_Neg_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Neg->HUN_Neg_Stem");
yylhs.value=sparser->set_node_info("HUN_Neg",HUN_Neg_Stem);

}
#line 4784 "build/hi_android/hi.y.cpp"
    break;

  case 267: // HUN_Neg_Stem: t_HUN_Neg_Stem
#line 2338 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Neg_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Neg_Stem",word);

}
#line 4796 "build/hi_android/hi.y.cpp"
    break;

  case 268: // HUN_Noun_Stem: HUN_lfea_swConsonant HUN_Noun_Stem
#line 2347 "build/hi_android/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Noun_Stem->HUN_lfea_swConsonant HUN_Noun_Stem");
yylhs.value=sparser->combine_nodes("HUN_Noun_Stem",HUN_lfea_swConsonant,HUN_Noun_Stem);

}
#line 4808 "build/hi_android/hi.y.cpp"
    break;

  case 269: // HUN_Noun_Stem: HUN_lfea_swVowel HUN_Noun_Stem
#line 2355 "build/hi_android/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Noun_Stem->HUN_lfea_swVowel HUN_Noun_Stem");
yylhs.value=sparser->combine_nodes("HUN_Noun_Stem",HUN_lfea_swVowel,HUN_Noun_Stem);

}
#line 4820 "build/hi_android/hi.y.cpp"
    break;

  case 270: // HUN_Noun_Stem: t_HUN_Noun_Stem
#line 2363 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_Stem",word);

}
#line 4832 "build/hi_android/hi.y.cpp"
    break;

  case 271: // HUN_Noun_lfea_Acc: t_HUN_Noun_Acc
#line 2372 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Acc",word);

}
#line 4844 "build/hi_android/hi.y.cpp"
    break;

  case 272: // HUN_Noun_lfea_Dat: t_HUN_Noun_Dat
#line 2381 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Dat",word);

}
#line 4856 "build/hi_android/hi.y.cpp"
    break;

  case 273: // HUN_Noun_lfea_Del: t_HUN_Noun_Del
#line 2390 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Del);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Del",word);

}
#line 4868 "build/hi_android/hi.y.cpp"
    break;

  case 274: // HUN_Noun_lfea_Ine: t_HUN_Noun_Ine
#line 2399 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Ine);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Ine",word);

}
#line 4880 "build/hi_android/hi.y.cpp"
    break;

  case 275: // HUN_Noun_lfea_Plur: t_HUN_Noun_Plur
#line 2408 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Plur);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Plur",word);

}
#line 4892 "build/hi_android/hi.y.cpp"
    break;

  case 276: // HUN_Noun_lfea_Relative: t_HUN_Noun_Relative
#line 2417 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Relative",word);

}
#line 4904 "build/hi_android/hi.y.cpp"
    break;

  case 277: // HUN_Num: HUN_Num HUN_Num_lfea_Ik
#line 2426 "build/hi_android/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Ik=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Ik");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Ik);

}
#line 4916 "build/hi_android/hi.y.cpp"
    break;

  case 278: // HUN_Num: HUN_Num HUN_Num_lfea_Par
#line 2434 "build/hi_android/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Par=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Par");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Par);

}
#line 4928 "build/hi_android/hi.y.cpp"
    break;

  case 279: // HUN_Num: HUN_Num_Pref HUN_Num
#line 2442 "build/hi_android/hi.y"
{
const node_info& HUN_Num_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num_Pref HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num_Pref,HUN_Num);

}
#line 4940 "build/hi_android/hi.y.cpp"
    break;

  case 280: // HUN_Num: HUN_Num_Stem
#line 2450 "build/hi_android/hi.y"
{
const node_info& HUN_Num_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num_Stem");
yylhs.value=sparser->set_node_info("HUN_Num",HUN_Num_Stem);

}
#line 4951 "build/hi_android/hi.y.cpp"
    break;

  case 281: // HUN_Num: HUN_lfea_swConsonant HUN_Num
#line 2457 "build/hi_android/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_lfea_swConsonant HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_lfea_swConsonant,HUN_Num);

}
#line 4963 "build/hi_android/hi.y.cpp"
    break;

  case 282: // HUN_Num: HUN_lfea_swVowel HUN_Num
#line 2465 "build/hi_android/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_lfea_swVowel HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_lfea_swVowel,HUN_Num);

}
#line 4975 "build/hi_android/hi.y.cpp"
    break;

  case 283: // HUN_Num_Pref: t_HUN_Num_Npref1
#line 2474 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 4987 "build/hi_android/hi.y.cpp"
    break;

  case 284: // HUN_Num_Pref: t_HUN_Num_Npref1n
#line 2482 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 4999 "build/hi_android/hi.y.cpp"
    break;

  case 285: // HUN_Num_Pref: t_HUN_Num_Npref1nn
#line 2490 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1nn);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5011 "build/hi_android/hi.y.cpp"
    break;

  case 286: // HUN_Num_Pref: t_HUN_Num_Npref1nnn
#line 2498 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1nnn);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5023 "build/hi_android/hi.y.cpp"
    break;

  case 287: // HUN_Num_Pref: t_HUN_Num_Npref2
#line 2506 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5035 "build/hi_android/hi.y.cpp"
    break;

  case 288: // HUN_Num_Pref: t_HUN_Num_Npref2n
#line 2514 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5047 "build/hi_android/hi.y.cpp"
    break;

  case 289: // HUN_Num_Pref: t_HUN_Num_Npref3
#line 2522 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5059 "build/hi_android/hi.y.cpp"
    break;

  case 290: // HUN_Num_Pref: t_HUN_Num_Npref3n
#line 2530 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5071 "build/hi_android/hi.y.cpp"
    break;

  case 291: // HUN_Num_Pref: t_HUN_Num_Npref4
#line 2538 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref4);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5083 "build/hi_android/hi.y.cpp"
    break;

  case 292: // HUN_Num_Pref: t_HUN_Num_Npref4n
#line 2546 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5095 "build/hi_android/hi.y.cpp"
    break;

  case 293: // HUN_Num_Pref: t_HUN_Num_Npref5
#line 2554 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref5);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5107 "build/hi_android/hi.y.cpp"
    break;

  case 294: // HUN_Num_Pref: t_HUN_Num_Npref5n
#line 2562 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5119 "build/hi_android/hi.y.cpp"
    break;

  case 295: // HUN_Num_Pref: t_HUN_Num_Npref6
#line 2570 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref6);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5131 "build/hi_android/hi.y.cpp"
    break;

  case 296: // HUN_Num_Pref: t_HUN_Num_Npref6n
#line 2578 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5143 "build/hi_android/hi.y.cpp"
    break;

  case 297: // HUN_Num_Pref: t_HUN_Num_Npref7
#line 2586 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref7);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5155 "build/hi_android/hi.y.cpp"
    break;

  case 298: // HUN_Num_Pref: t_HUN_Num_Npref7n
#line 2594 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5167 "build/hi_android/hi.y.cpp"
    break;

  case 299: // HUN_Num_Pref: t_HUN_Num_Npref8
#line 2602 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref8);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5179 "build/hi_android/hi.y.cpp"
    break;

  case 300: // HUN_Num_Pref: t_HUN_Num_Npref8n
#line 2610 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5191 "build/hi_android/hi.y.cpp"
    break;

  case 301: // HUN_Num_Pref: t_HUN_Num_Npref9
#line 2618 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref9);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5203 "build/hi_android/hi.y.cpp"
    break;

  case 302: // HUN_Num_Pref: t_HUN_Num_Npref9n
#line 2626 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5215 "build/hi_android/hi.y.cpp"
    break;

  case 303: // HUN_Num_Stem: t_HUN_Num_Stem
#line 2635 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Stem",word);

}
#line 5227 "build/hi_android/hi.y.cpp"
    break;

  case 304: // HUN_Num_lfea_Acc: t_HUN_Num_Acc
#line 2644 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Acc",word);

}
#line 5239 "build/hi_android/hi.y.cpp"
    break;

  case 305: // HUN_Num_lfea_Dat: t_HUN_Num_Dat
#line 2653 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Dat",word);

}
#line 5251 "build/hi_android/hi.y.cpp"
    break;

  case 306: // HUN_Num_lfea_Del: t_HUN_Num_Del
#line 2662 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Del);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Del",word);

}
#line 5263 "build/hi_android/hi.y.cpp"
    break;

  case 307: // HUN_Num_lfea_Ik: t_HUN_Num_Ik
#line 2671 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Ik);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Ik",word);

}
#line 5275 "build/hi_android/hi.y.cpp"
    break;

  case 308: // HUN_Num_lfea_Par: t_HUN_Num_Par
#line 2680 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Par);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Par",word);

}
#line 5287 "build/hi_android/hi.y.cpp"
    break;

  case 309: // HUN_Nums: HUN_Num HUN_Num
#line 2689 "build/hi_android/hi.y"
{
const node_info& HUN_Num1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Nums->HUN_Num HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Nums",HUN_Num1,HUN_Num2);

}
#line 5299 "build/hi_android/hi.y.cpp"
    break;

  case 310: // HUN_Nums: HUN_Nums HUN_Num
#line 2697 "build/hi_android/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Nums->HUN_Nums HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Nums",HUN_Nums,HUN_Num);

}
#line 5311 "build/hi_android/hi.y.cpp"
    break;

  case 311: // HUN_RC: HUN_Conj HUN_N_Sg
#line 2706 "build/hi_android/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_Conj HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_Conj,HUN_N_Sg);

}
#line 5323 "build/hi_android/hi.y.cpp"
    break;

  case 312: // HUN_RC: HUN_RPro HUN_INVP
#line 2714 "build/hi_android/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_INVP);

}
#line 5335 "build/hi_android/hi.y.cpp"
    break;

  case 313: // HUN_RC: HUN_RPro HUN_IVP
#line 2722 "build/hi_android/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVP);

}
#line 5347 "build/hi_android/hi.y.cpp"
    break;

  case 314: // HUN_RC: HUN_RPro HUN_IVPConj
#line 2730 "build/hi_android/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVPConj");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVPConj);

}
#line 5359 "build/hi_android/hi.y.cpp"
    break;

  case 315: // HUN_RC: HUN_RPro HUN_IVPlist
#line 2738 "build/hi_android/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVPlist");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVPlist);

}
#line 5371 "build/hi_android/hi.y.cpp"
    break;

  case 316: // HUN_RPro: HUN_Noun_Stem HUN_Noun_lfea_Relative
#line 2747 "build/hi_android/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RPro->HUN_Noun_Stem HUN_Noun_lfea_Relative");
yylhs.value=sparser->combine_nodes("HUN_RPro",HUN_Noun_Stem,HUN_Noun_lfea_Relative);

}
#line 5383 "build/hi_android/hi.y.cpp"
    break;

  case 317: // HUN_RPro: HUN_RPro HUN_Noun_lfea_Plur
#line 2755 "build/hi_android/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Plur=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RPro->HUN_RPro HUN_Noun_lfea_Plur");
yylhs.value=sparser->combine_nodes("HUN_RPro",HUN_RPro,HUN_Noun_lfea_Plur);

}
#line 5395 "build/hi_android/hi.y.cpp"
    break;

  case 318: // HUN_V: HUN_Verb_stem HUN_Verb_lfea_IndefPl3
#line 2764 "build/hi_android/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_IndefPl3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_V->HUN_Verb_stem HUN_Verb_lfea_IndefPl3");
yylhs.value=sparser->combine_nodes("HUN_V",HUN_Verb_stem,HUN_Verb_lfea_IndefPl3);

}
#line 5407 "build/hi_android/hi.y.cpp"
    break;

  case 319: // HUN_VP: HUN_ImpVerb HUN_AP
#line 2773 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_AP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_AP);

}
#line 5419 "build/hi_android/hi.y.cpp"
    break;

  case 320: // HUN_VP: HUN_ImpVerb HUN_DP
#line 2781 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_DP);

}
#line 5431 "build/hi_android/hi.y.cpp"
    break;

  case 321: // HUN_VP: HUN_ImpVerb HUN_Empty
#line 2789 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Empty=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_Empty");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_Empty);

}
#line 5443 "build/hi_android/hi.y.cpp"
    break;

  case 322: // HUN_VP: HUN_ImpVerbPfx HUN_DP
#line 2797 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_DP);

}
#line 5455 "build/hi_android/hi.y.cpp"
    break;

  case 323: // HUN_VP: HUN_ImpVerbPfx HUN_NP
#line 2805 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_NP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_NP);

}
#line 5467 "build/hi_android/hi.y.cpp"
    break;

  case 324: // HUN_VP: HUN_Neg HUN_ImpVerb
#line 2813 "build/hi_android/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Neg HUN_ImpVerb");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Neg,HUN_ImpVerb);

}
#line 5479 "build/hi_android/hi.y.cpp"
    break;

  case 325: // HUN_VP: HUN_Vbar1 HUN_NP
#line 2821 "build/hi_android/hi.y"
{
const node_info& HUN_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar1 HUN_NP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar1,HUN_NP);

}
#line 5491 "build/hi_android/hi.y.cpp"
    break;

  case 326: // HUN_VP: HUN_Vbar2 HUN_N_Ins
#line 2829 "build/hi_android/hi.y"
{
const node_info& HUN_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar2 HUN_N_Ins");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar2,HUN_N_Ins);

}
#line 5503 "build/hi_android/hi.y.cpp"
    break;

  case 327: // HUN_VP: HUN_Vbar2 HUN_RC
#line 2837 "build/hi_android/hi.y"
{
const node_info& HUN_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar2 HUN_RC");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar2,HUN_RC);

}
#line 5515 "build/hi_android/hi.y.cpp"
    break;

  case 328: // HUN_Vbar1: HUN_ImpVerb HUN_DP
#line 2846 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar1->HUN_ImpVerb HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_Vbar1",HUN_ImpVerb,HUN_DP);

}
#line 5527 "build/hi_android/hi.y.cpp"
    break;

  case 329: // HUN_Vbar2: HUN_ImpVerb HUN_N_Acc
#line 2855 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar2->HUN_ImpVerb HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_Vbar2",HUN_ImpVerb,HUN_N_Acc);

}
#line 5539 "build/hi_android/hi.y.cpp"
    break;

  case 330: // HUN_Vbar2: HUN_ImpVerb HUN_N_Dat
#line 2863 "build/hi_android/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar2->HUN_ImpVerb HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_Vbar2",HUN_ImpVerb,HUN_N_Dat);

}
#line 5551 "build/hi_android/hi.y.cpp"
    break;

  case 331: // HUN_Vbpfx: t_HUN_Vbpfx_Stem
#line 2872 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Vbpfx_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Vbpfx",word);

}
#line 5563 "build/hi_android/hi.y.cpp"
    break;

  case 332: // HUN_Verb_lfea_ConjDefSg2: t_HUN_Verb_ConjDefSg2
#line 2881 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_ConjDefSg2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_ConjDefSg2",word);

}
#line 5575 "build/hi_android/hi.y.cpp"
    break;

  case 333: // HUN_Verb_lfea_ConjIndefSg2: t_HUN_Verb_ConjIndefSg2
#line 2890 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_ConjIndefSg2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_ConjIndefSg2",word);

}
#line 5587 "build/hi_android/hi.y.cpp"
    break;

  case 334: // HUN_Verb_lfea_DefSg1: t_HUN_Verb_DefSg1
#line 2899 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_DefSg1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_DefSg1",word);

}
#line 5599 "build/hi_android/hi.y.cpp"
    break;

  case 335: // HUN_Verb_lfea_IndefPl3: t_HUN_Verb_IndefPl3
#line 2908 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_IndefPl3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_IndefPl3",word);

}
#line 5611 "build/hi_android/hi.y.cpp"
    break;

  case 336: // HUN_Verb_stem: t_HUN_Verb_Stem
#line 2917 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_stem",word);

}
#line 5623 "build/hi_android/hi.y.cpp"
    break;

  case 337: // HUN_Vhead: HUN_INVP
#line 2926 "build/hi_android/hi.y"
{
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vhead->HUN_INVP");
yylhs.value=sparser->set_node_info("HUN_Vhead",HUN_INVP);

}
#line 5634 "build/hi_android/hi.y.cpp"
    break;

  case 338: // HUN_Vhead: HUN_IVP
#line 2933 "build/hi_android/hi.y"
{
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vhead->HUN_IVP");
yylhs.value=sparser->set_node_info("HUN_Vhead",HUN_IVP);

}
#line 5645 "build/hi_android/hi.y.cpp"
    break;

  case 339: // HUN_Vlisthead: HUN_IVPlist
#line 2941 "build/hi_android/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vlisthead->HUN_IVPlist");
yylhs.value=sparser->set_node_info("HUN_Vlisthead",HUN_IVPlist);

}
#line 5656 "build/hi_android/hi.y.cpp"
    break;

  case 340: // HUN_lfea_DefDet: t_HUN_Det_Def
#line 2949 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_Def);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_DefDet",word);

}
#line 5668 "build/hi_android/hi.y.cpp"
    break;

  case 341: // HUN_lfea_fwConsonant: t_HUN_Det_fwConsonant
#line 2958 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_fwConsonant",word);

}
#line 5680 "build/hi_android/hi.y.cpp"
    break;

  case 342: // HUN_lfea_fwVowel: t_HUN_Det_fwVowel
#line 2967 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_fwVowel",word);

}
#line 5692 "build/hi_android/hi.y.cpp"
    break;

  case 343: // HUN_lfea_swConsonant: t_HUN_CON_swConsonant
#line 2976 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 5704 "build/hi_android/hi.y.cpp"
    break;

  case 344: // HUN_lfea_swConsonant: t_HUN_Noun_swConsonant
#line 2984 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 5716 "build/hi_android/hi.y.cpp"
    break;

  case 345: // HUN_lfea_swConsonant: t_HUN_Num_swConsonant
#line 2992 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 5728 "build/hi_android/hi.y.cpp"
    break;

  case 346: // HUN_lfea_swVowel: t_HUN_CON_swVowel
#line 3001 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 5740 "build/hi_android/hi.y.cpp"
    break;

  case 347: // HUN_lfea_swVowel: t_HUN_Noun_swVowel
#line 3009 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 5752 "build/hi_android/hi.y.cpp"
    break;

  case 348: // HUN_lfea_swVowel: t_HUN_Num_swVowel
#line 3017 "build/hi_android/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 5764 "build/hi_android/hi.y.cpp"
    break;

  case 349: // HUN_nCon: HUN_1Con HUN_Con
#line 3026 "build/hi_android/hi.y"
{
const node_info& HUN_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_nCon->HUN_1Con HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_nCon",HUN_1Con,HUN_Con);

}
#line 5776 "build/hi_android/hi.y.cpp"
    break;

  case 350: // HUN_nCon: HUN_nCon HUN_Con
#line 3034 "build/hi_android/hi.y"
{
const node_info& HUN_nCon=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_nCon->HUN_nCon HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_nCon",HUN_nCon,HUN_Con);

}
#line 5788 "build/hi_android/hi.y.cpp"
    break;

  case 351: // S: ENG_VP
#line 3043 "build/hi_android/hi.y"
{
const node_info& ENG_VP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP");
yylhs.value=sparser->set_node_info("S",ENG_VP);

}
#line 5799 "build/hi_android/hi.y.cpp"
    break;

  case 352: // S: HUN_VP
#line 3050 "build/hi_android/hi.y"
{
const node_info& HUN_VP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->HUN_VP");
yylhs.value=sparser->set_node_info("S",HUN_VP);

}
#line 5810 "build/hi_android/hi.y.cpp"
    break;


#line 5814 "build/hi_android/hi.y.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -314;

  const short parser::yytable_ninf_ = -340;

  const short
  parser::yypact_[] =
  {
      14,  -314,  -314,  -314,  -314,  -314,    57,  1235,     2,   104,
      88,    88,    57,    57,   533,  -314,  -314,  -314,    53,  1296,
     122,   265,   132,   592,  1024,    37,  -314,  -314,  1061,   946,
      -8,   168,  -314,   138,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,   160,  -314,  -314,  -314,
     134,   160,   160,   160,   134,   160,   160,   205,   147,  -314,
    1301,  -314,   160,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,   154,  -314,   176,   166,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,   163,  -314,  -314,   188,  -314,   163,  -314,    32,
     169,  -314,  -314,    32,  -314,  -314,  -314,  -314,    36,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
      64,   169,  -314,   169,    89,   169,   265,  -314,    57,   181,
      57,  -314,  1311,   174,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    1079,  -314,  -314,   128,  -314,  -314,  -314,  -314,  -314,   928,
     125,  -314,  -314,   928,  -314,   216,  1061,   180,    47,    55,
     164,  -314,  -314,    16,  -314,    16,   128,   492,    16,   682,
     142,   459,  1181,  -314,   553,  -314,  1061,  1061,  1079,  -314,
    -314,  -314,  -314,    69,  -314,  1115,  1148,  -314,  -314,  -314,
      15,  -314,  -314,   139,   153,  -314,   727,    15,    15,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,   160,   160,   160,   160,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,   224,
    -314,  -314,  -314,  -314,    68,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,   170,  -314,  -314,  -314,  -314,  -314,   109,   169,
     110,  1311,    57,   376,   230,   169,   169,  -314,  -314,  -314,
    -314,  -314,  -314,  1079,  1079,  -314,  -314,  -314,    16,    69,
    1061,   637,   928,  -314,  -314,  -314,    16,  -314,  -314,  -314,
      -7,   499,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,   177,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   177,   177,   177,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   199,  -314,  -314,  -314,  -314,
    -314,  1181,  1181,   199,   199,  -314,  -314,  -314,  -314,   199,
    -314,  -314,   199,  -314,  -314,  -314,  -314,   768,   808,   125,
    -314,   848,   171,    37,    37,    37,   985,  -314,  1061,   165,
     125,   125,    68,    68,   170,   170,  -314,    57,  -314,  -314,
    -314,  -314,  -314,   163,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  1228,  1228,    16,  -314,   928,  -314,   928,  -314,
      25,  -314,  -314,  -314,  -314,  -314,  -314,  -314,   888,  -314,
    -314,  -314,  -314,    37,  -314,  -314,  -314,  -314,  -314,    37,
      37,    37,  1061,  -314,   419,  -314,  -314,  -314,  -314,    57,
      57,  -314,  -314,  -314,   888,   888,   888,  -314,  -314,  -314
  };

  const short
  parser::yydefact_[] =
  {
       0,    38,   135,   117,   336,   267,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   351,   118,   116,   119,   122,
     128,     0,     0,   216,     0,     0,   266,   352,     0,     0,
       0,     0,   142,   119,    28,    77,    92,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    69,     2,    33,    52,
       0,    60,    62,    53,     0,    70,    72,     0,     0,    34,
       0,    81,    65,   148,   147,    37,    49,   150,   149,    50,
      51,     0,    35,     0,     0,    36,   143,   115,    10,    16,
     108,     6,    69,     4,    11,     0,     5,     0,     3,     7,
       8,    17,   141,     9,    54,    55,    23,   138,     0,   136,
     137,   133,   134,   107,   114,   121,   123,   139,    96,   140,
     103,   125,    97,     0,   106,     0,     0,   127,     0,     0,
       0,   120,     0,     0,   129,   130,   131,   132,   188,   303,
     283,   287,   289,   291,   293,   295,   297,   299,   301,   285,
     286,   215,   346,   343,   284,   288,   290,   292,   294,   296,
     298,   300,   302,   348,   345,   270,   347,   344,   331,   182,
     262,   175,   176,     0,   319,   169,   170,   172,   173,   177,
       0,   156,   181,   180,   155,   328,     0,     0,     0,     0,
       0,   321,   171,   329,   330,     0,     0,     0,     0,     0,
     263,     0,     0,   280,     0,   240,     0,     0,   264,   322,
     323,   242,   243,   244,   245,     0,     0,   324,   325,   206,
       0,   193,   326,     0,   263,   327,     0,     0,     0,   332,
     333,   334,   237,   238,   239,     1,   153,   152,   151,    67,
      68,     0,    61,    63,    64,    75,    76,    71,    73,    78,
      79,    66,    74,    93,    82,    80,   154,    20,    21,     0,
      12,    22,    27,    18,     0,    13,    24,    14,    19,    15,
      56,   104,     0,    98,    99,   105,   100,    95,   109,   110,
     111,     0,     0,     0,   118,     0,     0,   113,   112,    94,
     101,   102,   349,     0,     0,   271,   246,   183,   160,     0,
       0,     0,   178,   161,   179,   184,   162,   207,   208,   209,
       0,     0,   342,   341,   213,   214,   210,   211,   340,   212,
     163,   166,     0,   164,   167,   247,   189,   192,   191,   272,
     190,   273,   248,   252,   260,   265,   158,   263,   249,   253,
     254,   165,   168,   241,   157,     0,     0,     0,   275,   261,
     307,   308,   304,   305,   306,   309,   250,   255,   256,   277,
     278,     0,     0,   279,   310,   251,   257,   186,   268,   281,
     187,   269,   282,   350,   311,   276,   316,   312,   313,   314,
     223,   315,     0,   242,   243,   245,     0,   317,     0,     0,
       0,     0,    25,    26,    29,    30,    47,     0,    44,    48,
      39,    40,    57,    41,    42,    43,    58,    59,    45,    46,
     194,   195,   196,   197,     0,   198,   201,   199,   202,   200,
       0,   274,   258,   259,   231,   232,   233,   234,     0,   224,
     235,   236,   217,     0,   227,   228,   229,   218,   219,     0,
       0,     0,     0,   230,     0,   335,   318,   225,   226,    31,
      32,   174,   185,   159,   203,   204,   205,   222,   220,   221
  };

  const short
  parser::yypgoto_[] =
  {
    -314,    -5,   182,  -314,  -314,  -314,    -2,  -314,   -76,  -314,
    -314,   261,    29,  -314,   187,   -57,   -56,  -314,    65,    18,
     -31,   272,  -314,  -314,  -108,  -314,  -100,  -314,  -314,  -314,
      -4,    49,  -314,  -314,  -314,  -314,   226,   227,  -314,   239,
     300,   304,    20,  -314,  -314,   256,  -314,  -314,  -314,  -314,
    -314,   -16,   -11,  -314,   197,  -314,    59,  -314,  -314,  -314,
     303,  -314,  -314,  -314,  -314,  -314,   148,   -21,  -314,  -314,
     149,   324,    81,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   277,   278,   152,  -314,    21,
      12,  -314,  -310,  -314,  -170,  -314,  -314,  -314,    50,  -314,
    -314,  -173,  -314,   -28,  -314,   264,  -314,  -314,  -314,  -314,
     -20,  -314,  -314,  -314,  -120,  -314,   305,  -314,  -314,  -314,
    -314,  -314,  -314,  -187,  -314,  -314,    23,  -314,   -41,   -82,
     312,  -314,  -314,   151,     0,   173,  -314,   -17,   184,   -23,
      -6,    42,  -314,   108,  -148,  -314,  -314,    38,   124,  -314,
     279,  -314,  -314,  -161,   158,  -314,  -314,  -314,    -9,  -314,
    -314,  -313,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
      27,  -314,  -314,  -314,  -314,  -314,    30,    83,  -314,  -314
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   254,   255,   256,    47,   263,
     388,     6,     7,     8,   386,   269,   270,     9,    10,    11,
      96,    97,   271,   272,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   241,   242,    58,    59,    60,    61,   244,
     108,   109,   261,   111,   112,   113,   114,   115,   116,    98,
     117,   118,   278,   119,    12,    13,   273,   120,   121,    15,
     274,   122,    33,   101,   102,    19,    20,    21,    22,   275,
     276,    65,    66,    69,    70,   235,   236,    62,   160,   310,
     311,   163,   405,   164,   165,   166,   167,   168,   287,   407,
     170,   171,   172,   173,   409,   174,   322,   323,   324,   325,
     418,   292,   293,   294,   419,   211,   175,   176,   177,   178,
     179,   180,   181,   414,   427,   422,   415,   369,   370,   371,
      23,    24,   182,   372,   373,   184,   299,   185,   186,   289,
     188,   376,    26,   190,   328,   329,   330,   412,   339,   366,
     205,   192,   193,   346,   347,   348,   349,   350,   206,   215,
     216,   378,    27,    28,    29,   195,   222,   223,   224,   436,
     379,   380,   381,   309,   304,   305,   196,   197,   198,    31
  };

  const short
  parser::yytable_[] =
  {
     187,   203,    46,    48,   124,   203,   213,   202,   110,   210,
     268,   202,   212,   253,   194,   286,   334,   258,   204,   333,
       1,    63,   204,   183,   201,   443,     2,    30,   201,   367,
      73,    73,     3,   355,   257,   162,    78,   259,   315,    34,
      78,    64,    25,    35,   161,   355,   231,   231,   231,    81,
     237,   238,    30,    81,   262,   128,   262,   252,   262,   217,
     424,   425,   426,   432,  -124,   189,    99,   285,   107,     2,
     126,   219,    78,   169,   142,   143,     2,   100,   411,   220,
     105,    18,    46,   251,   221,    81,   153,   154,   155,  -126,
     156,   157,     4,    46,    77,    35,   441,     5,   442,     5,
     123,     2,   249,   265,   159,   105,   281,   143,     5,   128,
     447,   226,   218,   159,   142,     4,   424,   425,   426,   154,
     333,     2,     2,   157,    67,    68,   153,   246,   142,   143,
     156,   264,   103,   266,  -145,  -146,   104,   214,     1,   334,
     153,   154,   155,   285,   156,   157,   316,   226,    14,    16,
     291,    99,   315,   301,    32,    16,   227,   228,   317,   318,
      76,    16,   389,    34,   326,   267,    34,   194,   225,   288,
      35,   280,   336,   296,   243,   200,   297,   228,   382,   208,
     326,   416,     2,   337,   420,   240,   105,   364,   227,   335,
     283,   123,    78,   203,   252,   123,   277,   314,   100,   374,
     332,   123,   285,   232,   233,   234,   313,   209,   306,   331,
     375,   290,   387,   239,   240,   290,  -320,   217,   387,   387,
     308,   351,   351,   295,   351,   312,   338,   312,   283,   318,
     312,   444,   239,   217,   365,   351,   351,   302,   303,   368,
     217,   340,   341,   284,   398,   399,   105,   217,   217,    71,
      74,   384,   396,   397,     5,   391,   435,   395,   416,   420,
     437,   438,   307,   403,   408,   159,   326,   250,    34,    78,
     218,   393,    35,   336,   352,   352,    80,   352,   326,   439,
     106,   284,    81,   383,   337,   260,   218,   440,   352,   352,
     335,   404,   410,   218,   127,   327,   226,   246,   246,   246,
     218,   218,   191,   401,   358,   361,   253,   258,   247,   248,
      72,   327,   400,   283,   283,    75,   245,   279,   327,   217,
     390,   385,   394,   125,    17,   358,   361,   229,   230,   199,
     312,   217,   389,   189,   290,   428,   446,   207,   312,   413,
     377,   402,   406,   123,   203,   203,     0,     0,   203,   298,
     374,   374,   356,   392,   374,   434,     0,   313,   331,   430,
     300,   375,   375,     0,     0,   375,   284,   284,     0,     0,
     431,     0,   218,     0,   265,     0,   429,     0,   433,    34,
      78,   351,   351,    35,   218,     0,   103,    80,    46,   251,
       0,   417,   105,    81,   421,   203,     0,   327,     0,     0,
       0,   374,   404,   404,     0,     0,   410,     0,   410,   327,
       0,   326,   375,     0,   423,   448,     0,     0,     0,     0,
       0,   203,   203,   203,   282,     0,   449,   374,   374,   374,
       0,     0,   433,     0,   352,   352,     0,     0,   375,   375,
     375,   445,     0,     0,   290,   290,   312,     0,   290,     0,
     290,     0,   312,   295,     0,   191,     0,     0,   295,   128,
     357,   360,   363,     0,   217,   123,   123,     0,   417,   421,
     345,   353,     0,   354,     0,   359,   362,     0,   142,   143,
       0,   357,   360,     0,   345,   354,     0,     0,     0,     0,
     153,   154,   155,   285,   156,   157,   316,     0,     0,     0,
     129,   340,   341,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,   218,   142,   143,
     342,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   128,     0,   156,   157,    34,    78,    79,   128,
      35,     0,   327,     0,    80,     0,     0,   357,   360,     0,
      81,   142,   143,     0,   343,     0,   344,     0,   142,   143,
       0,     0,     0,   153,   154,   155,   285,   156,   157,   316,
     153,   154,   155,   285,   156,   157,   316,     0,     0,     0,
       0,   317,   318,     0,   411,   319,   320,     0,   321,     0,
       0,     0,   319,   320,   129,   321,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,   142,   143,   342,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,   156,   157,
     359,   362,   128,   129,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   343,     0,
       0,   142,   143,     0,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,   156,   157,     0,
       0,     0,   158,     0,     0,     5,     0,   128,   129,     0,
     159,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,   142,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,   156,   157,     0,     0,     0,     0,     0,     0,
       5,     0,   128,   129,     0,   159,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,   142,   143,     0,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,   156,   157,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,     0,
     159,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,   142,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,   156,   157,     0,     4,     0,     0,   128,   129,
       5,   338,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   156,   157,     0,     4,     0,   128,   129,
    -337,     5,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   156,   157,     0,     4,     0,   128,   129,
    -338,     5,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   156,   157,     0,     4,     0,   128,   129,
    -339,     5,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   156,   157,     0,     4,     0,   128,   129,
       0,     5,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,   128,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   156,   157,   142,   143,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,   153,   154,   155,
       0,   156,   157,     0,     0,   128,   129,     0,   209,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,   142,   143,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
     156,   157,     0,     4,   128,   129,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,   142,   143,     0,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,   156,
     157,   128,   129,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,   128,
     142,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   142,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,     0,     0,   156,   157,   129,   340,   341,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,   142,   143,   342,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   129,
     156,   157,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,   142,   143,   342,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   129,   156,   157,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,    34,     0,
     142,   143,    35,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,     0,   156,   157,     0,     0,
       0,    36,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    34,
      78,    79,     0,    35,     0,     0,   103,    80,     2,     0,
     104,     0,   105,    81,    34,    78,     0,     0,    35,     0,
       0,   103,    80,     0,     0,     0,     0,    36,    81,    37,
      38,    39,    40,    41,    42,    43,    44,    45
  };

  const short
  parser::yycheck_[] =
  {
      23,    24,     7,     7,    20,    28,    29,    24,    19,    29,
     118,    28,    29,    89,    23,   163,   189,    93,    24,   189,
       6,    19,    28,    23,    24,     0,    12,     0,    28,   216,
      10,    11,    18,   194,    90,    23,     4,    93,   186,     3,
       4,    39,     0,     7,    23,   206,    51,    52,    53,    17,
      55,    56,    25,    17,   111,    40,   113,    25,   115,    29,
     373,   374,   375,   376,     0,    23,    13,    74,    19,    12,
      21,    79,     4,    23,    59,    60,    12,    24,    85,    87,
      16,     0,    87,    87,    92,    17,    71,    72,    73,     0,
      75,    76,    78,    98,    13,     7,   406,    83,   408,    83,
      19,    12,    82,   114,    88,    16,   122,    60,    83,    40,
     423,    46,    29,    88,    59,    78,   429,   430,   431,    72,
     290,    12,    12,    76,    20,    21,    71,    62,    59,    60,
      75,   113,    10,   115,    25,    25,    14,    29,     6,   312,
      71,    72,    73,    74,    75,    76,    77,    82,     0,     0,
     170,    13,   300,   176,     6,     6,    22,    23,    89,    90,
      12,    12,   270,     3,   187,   116,     3,   176,     0,   169,
       7,   122,   189,   173,    27,    24,   176,    23,   254,    28,
     203,   368,    12,   189,   371,     9,    16,   210,    22,   189,
     160,   110,     4,   216,    25,   114,    15,   185,    24,   216,
     188,   120,    74,    51,    52,    53,   185,    82,   178,   188,
     216,   169,   269,     8,     9,   173,     0,   187,   275,   276,
      56,   191,   192,   173,   194,   183,    84,   185,   198,    90,
     188,   418,     8,   203,    81,   205,   206,    57,    58,   216,
     210,    42,    43,   160,   275,   276,    16,   217,   218,    10,
      11,   262,   273,   274,    83,   271,    91,   273,   445,   446,
     380,   381,   179,   291,   292,    88,   289,    85,     3,     4,
     187,   273,     7,   290,   191,   192,    11,   194,   301,   387,
      19,   198,    17,   254,   290,    98,   203,   387,   205,   206,
     290,   291,   292,   210,    22,   187,   231,   232,   233,   234,
     217,   218,    23,   291,   196,   197,   382,   383,    82,    82,
      10,   203,   291,   283,   284,    11,    60,   120,   210,   289,
     271,   262,   273,    20,     0,   217,   218,    50,    50,    24,
     288,   301,   440,   291,   292,   376,   418,    25,   296,   301,
     216,   291,   292,   262,   367,   368,    -1,    -1,   371,   176,
     367,   368,   194,   272,   371,   378,    -1,   336,   337,   376,
     176,   367,   368,    -1,    -1,   371,   283,   284,    -1,    -1,
     376,    -1,   289,    -1,   385,    -1,   376,    -1,   378,     3,
       4,   351,   352,     7,   301,    -1,    10,    11,   393,   393,
      -1,   368,    16,    17,   371,   418,    -1,   289,    -1,    -1,
      -1,   418,   402,   403,    -1,    -1,   406,    -1,   408,   301,
      -1,   434,   418,    -1,   372,   432,    -1,    -1,    -1,    -1,
      -1,   444,   445,   446,   160,    -1,   432,   444,   445,   446,
      -1,    -1,   432,    -1,   351,   352,    -1,    -1,   444,   445,
     446,   418,    -1,    -1,   402,   403,   404,    -1,   406,    -1,
     408,    -1,   410,   403,    -1,   176,    -1,    -1,   408,    40,
     196,   197,   198,    -1,   434,   384,   385,    -1,   445,   446,
     191,   192,    -1,   194,    -1,   196,   197,    -1,    59,    60,
      -1,   217,   218,    -1,   205,   206,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,   434,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    40,    -1,    75,    76,     3,     4,     5,    40,
       7,    -1,   434,    -1,    11,    -1,    -1,   283,   284,    -1,
      17,    59,    60,    -1,    95,    -1,    97,    -1,    59,    60,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    89,    90,    -1,    85,    93,    94,    -1,    96,    -1,
      -1,    -1,    93,    94,    41,    96,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    75,    76,
     351,   352,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    95,    -1,
      -1,    59,    60,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    75,    76,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    40,    41,    -1,
      88,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    40,    41,    -1,    88,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      88,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,    76,    -1,    78,    -1,    -1,    40,    41,
      83,    84,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    76,    -1,    78,    -1,    40,    41,
      82,    83,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    76,    -1,    78,    -1,    40,    41,
      82,    83,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    76,    -1,    78,    -1,    40,    41,
      82,    83,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    76,    -1,    78,    -1,    40,    41,
      -1,    83,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    40,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    76,    59,    60,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      -1,    75,    76,    -1,    -1,    40,    41,    -1,    82,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    76,    -1,    78,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    59,    60,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      76,    40,    41,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    40,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    75,    76,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    75,    76,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    -1,    41,
      75,    76,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    -1,    41,    75,    76,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,     3,    -1,
      59,    60,     7,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    11,    12,    -1,
      14,    -1,    16,    17,     3,     4,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    26,    17,    28,
      29,    30,    31,    32,    33,    34,    35,    36
  };

  const short
  parser::yystos_[] =
  {
       0,     6,    12,    18,    78,    83,   119,   120,   121,   125,
     126,   127,   162,   163,   164,   167,   168,   169,   170,   173,
     174,   175,   176,   228,   229,   239,   240,   260,   261,   262,
     268,   277,   164,   170,     3,     7,    26,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    99,   116,   128,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   143,   144,
     145,   146,   185,    19,    39,   179,   180,    20,    21,   181,
     182,   137,   138,   140,   137,   139,   164,   170,     4,     5,
      11,    17,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   128,   129,   157,    13,
      24,   171,   172,    10,    14,    16,   109,   129,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   158,   159,   161,
     165,   166,   169,   170,   149,   158,   129,   119,    40,    41,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    59,    60,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    75,    76,    80,    88,
     186,   187,   188,   189,   191,   192,   193,   194,   195,   196,
     198,   199,   200,   201,   203,   214,   215,   216,   217,   218,
     219,   220,   230,   232,   233,   235,   236,   237,   238,   239,
     241,   248,   249,   250,   256,   263,   274,   275,   276,   214,
     231,   232,   235,   237,   238,   248,   256,   228,   231,    82,
     208,   213,   235,   237,   241,   257,   258,   274,   275,    79,
      87,    92,   264,   265,   266,     0,   116,    22,    23,   183,
     184,    99,   185,   185,   185,   183,   184,    99,    99,     8,
       9,   141,   142,    27,   147,   143,   116,   134,   135,   140,
     100,   128,    25,   106,   113,   114,   115,   114,   106,   114,
     112,   150,   113,   117,   117,   150,   117,   129,   122,   123,
     124,   130,   131,   164,   168,   177,   178,    15,   160,   152,
     129,   149,   203,   274,   275,    74,   242,   196,   232,   237,
     239,   208,   209,   210,   211,   196,   232,   232,   233,   234,
     236,   237,    57,    58,   272,   273,   274,   275,    56,   271,
     187,   188,   239,   187,   188,   242,    77,    89,    90,    93,
      94,    96,   204,   205,   206,   207,   237,   241,   242,   243,
     244,   187,   188,   192,   199,   232,   235,   238,    84,   246,
      42,    43,    61,    95,    97,   248,   251,   252,   253,   254,
     255,   274,   275,   248,   248,   251,   252,   203,   241,   248,
     203,   241,   248,   203,   237,    81,   247,   221,   224,   225,
     226,   227,   231,   232,   235,   238,   239,   246,   259,   268,
     269,   270,   106,   110,   150,   154,   122,   113,   118,   122,
     129,   149,   170,   104,   129,   149,   165,   165,   118,   118,
     187,   188,   196,   201,   232,   190,   196,   197,   201,   202,
     232,    85,   245,   245,   221,   224,   221,   224,   208,   212,
     221,   224,   223,   239,   259,   259,   259,   222,   226,   232,
     235,   238,   259,   232,   237,    91,   267,   212,   212,   122,
     124,   190,   190,     0,   221,   224,   227,   259,   235,   238
  };

  const short
  parser::yyr1_[] =
  {
       0,    98,    99,   100,   101,   102,   103,   104,   104,   104,
     105,   106,   106,   107,   107,   107,   108,   109,   110,   110,
     111,   111,   112,   112,   113,   114,   114,   115,   116,   117,
     117,   118,   118,   119,   119,   119,   119,   120,   121,   122,
     122,   122,   122,   122,   123,   123,   123,   124,   124,   125,
     126,   127,   128,   128,   129,   129,   129,   130,   130,   131,
     132,   132,   132,   132,   132,   132,   133,   134,   135,   136,
     136,   136,   136,   136,   137,   138,   139,   140,   141,   142,
     143,   143,   144,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   146,   147,   148,   149,   150,   150,   151,   151,
     151,   152,   152,   153,   154,   154,   155,   156,   157,   158,
     158,   158,   159,   160,   161,   162,   162,   163,   164,   164,
     165,   166,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   168,   169,   170,   171,   172,   173,   174,
     174,   175,   176,   176,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   185,   186,   187,   188,   189,   190,
     191,   191,   191,   192,   192,   192,   193,   193,   193,   194,
     195,   195,   196,   196,   197,   198,   198,   198,   198,   198,
     198,   199,   200,   201,   201,   202,   203,   203,   203,   204,
     205,   206,   207,   208,   209,   209,   209,   209,   210,   210,
     210,   211,   211,   212,   212,   212,   213,   214,   214,   214,
     215,   215,   216,   217,   218,   219,   220,   221,   221,   221,
     222,   222,   223,   224,   225,   225,   225,   226,   226,   226,
     226,   227,   227,   227,   227,   227,   227,   228,   228,   228,
     229,   230,   231,   231,   231,   231,   232,   232,   232,   232,
     232,   232,   233,   233,   233,   233,   233,   233,   234,   234,
     235,   236,   237,   237,   237,   238,   239,   240,   241,   241,
     241,   242,   243,   244,   245,   246,   247,   248,   248,   248,
     248,   248,   248,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   250,   251,   252,   253,   254,   255,   256,
     256,   257,   257,   257,   257,   257,   258,   258,   259,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   261,   262,
     262,   263,   264,   265,   266,   267,   268,   269,   269,   270,
     271,   272,   273,   274,   274,   274,   275,   275,   275,   276,
     276,   277,   277
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     2,     2,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       1,     2,     1,     2,     2,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       2,     2,     2,     1,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     0,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "t_ENG_CON_Stem", "t_ENG_A_Stem",
  "t_ENG_ADV_Stem", "t_ENG_DET_Stem", "t_ENG_N_Stem", "t_ENG_N_Pl",
  "t_ENG_N_Sg", "t_ENG_PREP_Stem", "t_ENG_QPRO_Stem", "t_ENG_V_Stem",
  "t_ENG_V_Aux", "t_ENG_RPRO_Stem", "t_ENG_RPRO_Relative",
  "t_ENG_VNEG_Stem", "t_ENG_ANEG_Stem", "t_ENG_PAR_Stem",
  "t_ENG_DET_Indef", "t_ENG_DET_fwVowel", "t_ENG_DET_fwConsonant",
  "t_ENG_N_swVowel", "t_ENG_N_swConsonant", "t_ENG_V_Gerund",
  "t_ENG_CONJ_Stem", "t_ENG_Num_Stem", "t_ENG_Num_Ord",
  "t_ENG_Num_Npref1n", "t_ENG_Num_Npref2n", "t_ENG_Num_Npref3n",
  "t_ENG_Num_Npref4n", "t_ENG_Num_Npref5n", "t_ENG_Num_Npref6n",
  "t_ENG_Num_Npref7n", "t_ENG_Num_Npref8n", "t_ENG_Num_Npref9n",
  "t_ENG_Num_swVowel", "t_ENG_Num_swConsonant", "t_ENG_DET_Def",
  "t_HUN_CON_Stem", "t_HUN_Num_Stem", "t_HUN_Num_Ik", "t_HUN_Num_Par",
  "t_HUN_Num_Npref1", "t_HUN_Num_Npref2", "t_HUN_Num_Npref3",
  "t_HUN_Num_Npref4", "t_HUN_Num_Npref5", "t_HUN_Num_Npref6",
  "t_HUN_Num_Npref7", "t_HUN_Num_Npref8", "t_HUN_Num_Npref9",
  "t_HUN_Num_Npref1nn", "t_HUN_Num_Npref1nnn", "t_HUN_Det_Stem",
  "t_HUN_Det_Def", "t_HUN_Det_fwVowel", "t_HUN_Det_fwConsonant",
  "t_HUN_CON_swVowel", "t_HUN_CON_swConsonant", "t_HUN_Num_Acc",
  "t_HUN_Num_Npref1n", "t_HUN_Num_Npref2n", "t_HUN_Num_Npref3n",
  "t_HUN_Num_Npref4n", "t_HUN_Num_Npref5n", "t_HUN_Num_Npref6n",
  "t_HUN_Num_Npref7n", "t_HUN_Num_Npref8n", "t_HUN_Num_Npref9n",
  "t_HUN_Num_swVowel", "t_HUN_Num_swConsonant", "t_HUN_Noun_Stem",
  "t_HUN_Noun_Acc", "t_HUN_Noun_swVowel", "t_HUN_Noun_swConsonant",
  "t_HUN_CON_Acc", "t_HUN_Verb_Stem", "t_HUN_Verb_ConjDefSg2",
  "t_HUN_Vbpfx_Stem", "t_HUN_Noun_Relative", "t_HUN_Conj_Stem",
  "t_HUN_Neg_Stem", "t_HUN_Noun_Plur", "t_HUN_Noun_Ine",
  "t_HUN_Verb_IndefSg3", "t_HUN_Verb_ConjIndefSg2", "t_HUN_Adj_Stem",
  "t_HUN_CON_Sub", "t_HUN_CON_Ins", "t_HUN_Verb_IndefPl3",
  "t_HUN_Verb_DefSg1", "t_HUN_Noun_Dat", "t_HUN_CON_Dat", "t_HUN_Num_Dat",
  "t_HUN_Noun_Del", "t_HUN_Num_Del", "$accept", "ENG_1Con", "ENG_A",
  "ENG_A0NEG", "ENG_ANEG", "ENG_ANEG_Stem", "ENG_AP", "ENG_A_Stem",
  "ENG_Abar1", "ENG_Abar2", "ENG_Adv", "ENG_AdvP", "ENG_Alist", "ENG_CAP",
  "ENG_CNP", "ENG_CONJ", "ENG_CONJA", "ENG_CONJ_Stem", "ENG_Con",
  "ENG_ConjPVP", "ENG_ConjV", "ENG_DP", "ENG_Def_Det", "ENG_Det_stem",
  "ENG_IVP", "ENG_IVPConj", "ENG_IVPlist", "ENG_Indef_Det",
  "ENG_Indef_Det_a", "ENG_Indef_Det_an", "ENG_N", "ENG_NP", "ENG_NV",
  "ENG_NV_Aux", "ENG_N_Pl", "ENG_N_Pl_0Con", "ENG_N_Pl_0Con_swC",
  "ENG_N_Pl_0Con_swV", "ENG_N_Sg", "ENG_N_Sg_0Con", "ENG_N_Sg_0Con_swC",
  "ENG_N_Sg_0Con_swV", "ENG_N_Stem", "ENG_N_lfea_Pl", "ENG_N_lfea_Sg",
  "ENG_Num", "ENG_Num_Ord", "ENG_Num_Pref", "ENG_Num_Stem",
  "ENG_Num_lfea_Ord", "ENG_PNVPbar", "ENG_PP", "ENG_PVP", "ENG_PVPConj",
  "ENG_PVPbar", "ENG_PVPhead", "ENG_PVPlist", "ENG_PVPlisthead",
  "ENG_Prep", "ENG_QPro", "ENG_RC", "ENG_RPro", "ENG_RPro_lfea_relative",
  "ENG_RPro_stem", "ENG_TP", "ENG_Tense_particle", "ENG_V", "ENG_VNEG",
  "ENG_VNEG_Stem", "ENG_VP", "ENG_V_Aux", "ENG_V_Ger", "ENG_V_Stem",
  "ENG_V_lfea_aux", "ENG_V_lfea_ger", "ENG_Vbar1", "ENG_Vbar2",
  "ENG_Vbar3", "ENG_Vbar4", "ENG_Vhead", "ENG_Vlisthead",
  "ENG_lfea_DefDet", "ENG_lfea_IndefDet", "ENG_lfea_fwConsonant",
  "ENG_lfea_fwVowel", "ENG_lfea_swConsonant", "ENG_lfea_swVowel",
  "ENG_nCon", "HUN_1Con", "HUN_A0NEG", "HUN_ANEG", "HUN_ANP", "HUN_AN_Acc",
  "HUN_AP", "HUN_Abar1", "HUN_Abar1N", "HUN_Abar2", "HUN_Abar2N",
  "HUN_Abar3", "HUN_Abar3_End", "HUN_Abar4", "HUN_Adj", "HUN_Adj_Stem",
  "HUN_Alist", "HUN_Alist_End", "HUN_Con", "HUN_Con_lfea_Acc",
  "HUN_Con_lfea_Dat", "HUN_Con_lfea_Ins", "HUN_Con_lfea_Sub", "HUN_Conj",
  "HUN_ConjA", "HUN_ConjA_End", "HUN_ConjAlist", "HUN_ConjV",
  "HUN_Conj_Stem", "HUN_DP", "HUN_DPbar", "HUN_Def_Det", "HUN_Def_Det_a",
  "HUN_Def_Det_az", "HUN_Det_stem", "HUN_Empty", "HUN_INVP", "HUN_INVPbar",
  "HUN_INVPbar2", "HUN_IVP", "HUN_IVPConj", "HUN_IVPbar", "HUN_IVPlist",
  "HUN_ImpVerb", "HUN_ImpVerbPfx", "HUN_NAbar1", "HUN_NP", "HUN_N_Acc",
  "HUN_N_Dat", "HUN_N_Ine", "HUN_N_Ins", "HUN_N_Pl", "HUN_N_Sg",
  "HUN_N_Sub", "HUN_Neg", "HUN_Neg_Stem", "HUN_Noun_Stem",
  "HUN_Noun_lfea_Acc", "HUN_Noun_lfea_Dat", "HUN_Noun_lfea_Del",
  "HUN_Noun_lfea_Ine", "HUN_Noun_lfea_Plur", "HUN_Noun_lfea_Relative",
  "HUN_Num", "HUN_Num_Pref", "HUN_Num_Stem", "HUN_Num_lfea_Acc",
  "HUN_Num_lfea_Dat", "HUN_Num_lfea_Del", "HUN_Num_lfea_Ik",
  "HUN_Num_lfea_Par", "HUN_Nums", "HUN_RC", "HUN_RPro", "HUN_V", "HUN_VP",
  "HUN_Vbar1", "HUN_Vbar2", "HUN_Vbpfx", "HUN_Verb_lfea_ConjDefSg2",
  "HUN_Verb_lfea_ConjIndefSg2", "HUN_Verb_lfea_DefSg1",
  "HUN_Verb_lfea_IndefPl3", "HUN_Verb_stem", "HUN_Vhead", "HUN_Vlisthead",
  "HUN_lfea_DefDet", "HUN_lfea_fwConsonant", "HUN_lfea_fwVowel",
  "HUN_lfea_swConsonant", "HUN_lfea_swVowel", "HUN_nCon", "S", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   138,   138,   146,   154,   162,   170,   179,   186,   193,
     201,   210,   217,   226,   234,   242,   251,   260,   268,   276,
     285,   293,   302,   310,   318,   326,   334,   343,   352,   361,
     369,   378,   386,   395,   403,   411,   419,   428,   437,   446,
     454,   462,   470,   479,   489,   497,   505,   514,   522,   531,
     540,   549,   558,   565,   573,   580,   587,   596,   604,   613,
     622,   629,   637,   644,   652,   659,   667,   676,   685,   694,
     701,   708,   716,   723,   732,   741,   750,   759,   768,   777,
     786,   794,   802,   811,   819,   827,   835,   843,   851,   859,
     867,   875,   884,   893,   902,   911,   920,   927,   935,   943,
     951,   960,   967,   975,   983,   991,  1000,  1008,  1017,  1026,
    1034,  1042,  1051,  1060,  1069,  1078,  1086,  1094,  1103,  1110,
    1118,  1126,  1135,  1142,  1150,  1158,  1166,  1174,  1182,  1189,
    1197,  1205,  1213,  1222,  1231,  1240,  1249,  1258,  1267,  1276,
    1284,  1293,  1302,  1310,  1318,  1326,  1334,  1342,  1351,  1360,
    1369,  1378,  1387,  1396,  1404,  1413,  1421,  1429,  1438,  1447,
    1454,  1462,  1470,  1479,  1487,  1495,  1504,  1512,  1520,  1529,
    1537,  1544,  1552,  1559,  1567,  1576,  1583,  1590,  1597,  1605,
    1613,  1621,  1629,  1638,  1646,  1655,  1664,  1672,  1680,  1689,
    1698,  1707,  1716,  1725,  1733,  1741,  1749,  1757,  1766,  1774,
    1782,  1791,  1799,  1808,  1816,  1824,  1833,  1842,  1850,  1858,
    1867,  1875,  1884,  1893,  1902,  1911,  1920,  1927,  1935,  1943,
    1952,  1960,  1969,  1978,  1986,  1994,  2002,  2011,  2019,  2027,
    2035,  2044,  2052,  2060,  2068,  2076,  2084,  2093,  2101,  2109,
    2118,  2127,  2136,  2143,  2150,  2157,  2165,  2173,  2181,  2189,
    2197,  2205,  2214,  2222,  2230,  2238,  2246,  2254,  2263,  2271,
    2280,  2289,  2298,  2305,  2312,  2320,  2329,  2337,  2346,  2354,
    2362,  2371,  2380,  2389,  2398,  2407,  2416,  2425,  2433,  2441,
    2449,  2456,  2464,  2473,  2481,  2489,  2497,  2505,  2513,  2521,
    2529,  2537,  2545,  2553,  2561,  2569,  2577,  2585,  2593,  2601,
    2609,  2617,  2625,  2634,  2643,  2652,  2661,  2670,  2679,  2688,
    2696,  2705,  2713,  2721,  2729,  2737,  2746,  2754,  2763,  2772,
    2780,  2788,  2796,  2804,  2812,  2820,  2828,  2836,  2845,  2854,
    2862,  2871,  2880,  2889,  2898,  2907,  2916,  2925,  2932,  2940,
    2948,  2957,  2966,  2975,  2983,  2991,  3000,  3008,  3016,  3025,
    3033,  3042,  3049
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97
    };
    // Last valid token kind.
    const int code_max = 352;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 6929 "build/hi_android/hi.y.cpp"

#line 3056 "build/hi_android/hi.y"

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
            else if(toa&HI_MORPHOLOGY&&toa&HI_SEMANTICS){
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
