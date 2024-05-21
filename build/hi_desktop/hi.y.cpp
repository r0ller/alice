// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#line 176 "build/hi_desktop/hi.y.cpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
    /// Symbol semantic values.
    typedef int value_type;
#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


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
    t_HUN_Punct_Stem = 296,        // t_HUN_Punct_Stem
    t_HUN_Punct_FullStop = 297,    // t_HUN_Punct_FullStop
    t_HUN_Punct_QuestionMark = 298, // t_HUN_Punct_QuestionMark
    t_HUN_Punct_ExclamationMark = 299, // t_HUN_Punct_ExclamationMark
    t_HUN_Pronoun_Stem = 300,      // t_HUN_Pronoun_Stem
    t_HUN_Pronoun_Int = 301,       // t_HUN_Pronoun_Int
    t_HUN_Pronoun_Nom = 302,       // t_HUN_Pronoun_Nom
    t_HUN_Num_Stem = 303,          // t_HUN_Num_Stem
    t_HUN_Num_Ik = 304,            // t_HUN_Num_Ik
    t_HUN_Num_Par = 305,           // t_HUN_Num_Par
    t_HUN_Num_Npref1 = 306,        // t_HUN_Num_Npref1
    t_HUN_Num_Npref2 = 307,        // t_HUN_Num_Npref2
    t_HUN_Num_Npref3 = 308,        // t_HUN_Num_Npref3
    t_HUN_Num_Npref4 = 309,        // t_HUN_Num_Npref4
    t_HUN_Num_Npref5 = 310,        // t_HUN_Num_Npref5
    t_HUN_Num_Npref6 = 311,        // t_HUN_Num_Npref6
    t_HUN_Num_Npref7 = 312,        // t_HUN_Num_Npref7
    t_HUN_Num_Npref8 = 313,        // t_HUN_Num_Npref8
    t_HUN_Num_Npref9 = 314,        // t_HUN_Num_Npref9
    t_HUN_Num_Npref1nn = 315,      // t_HUN_Num_Npref1nn
    t_HUN_Num_Npref1nnn = 316,     // t_HUN_Num_Npref1nnn
    t_HUN_Det_Stem = 317,          // t_HUN_Det_Stem
    t_HUN_Det_Def = 318,           // t_HUN_Det_Def
    t_HUN_Det_fwVowel = 319,       // t_HUN_Det_fwVowel
    t_HUN_Det_fwConsonant = 320,   // t_HUN_Det_fwConsonant
    t_HUN_CON_swVowel = 321,       // t_HUN_CON_swVowel
    t_HUN_CON_swConsonant = 322,   // t_HUN_CON_swConsonant
    t_HUN_Num_Acc = 323,           // t_HUN_Num_Acc
    t_HUN_Num_Npref1n = 324,       // t_HUN_Num_Npref1n
    t_HUN_Num_Npref2n = 325,       // t_HUN_Num_Npref2n
    t_HUN_Num_Npref3n = 326,       // t_HUN_Num_Npref3n
    t_HUN_Num_Npref4n = 327,       // t_HUN_Num_Npref4n
    t_HUN_Num_Npref5n = 328,       // t_HUN_Num_Npref5n
    t_HUN_Num_Npref6n = 329,       // t_HUN_Num_Npref6n
    t_HUN_Num_Npref7n = 330,       // t_HUN_Num_Npref7n
    t_HUN_Num_Npref8n = 331,       // t_HUN_Num_Npref8n
    t_HUN_Num_Npref9n = 332,       // t_HUN_Num_Npref9n
    t_HUN_Num_swVowel = 333,       // t_HUN_Num_swVowel
    t_HUN_Num_swConsonant = 334,   // t_HUN_Num_swConsonant
    t_HUN_Noun_Stem = 335,         // t_HUN_Noun_Stem
    t_HUN_Noun_Acc = 336,          // t_HUN_Noun_Acc
    t_HUN_Noun_swVowel = 337,      // t_HUN_Noun_swVowel
    t_HUN_Noun_swConsonant = 338,  // t_HUN_Noun_swConsonant
    t_HUN_CON_Acc = 339,           // t_HUN_CON_Acc
    t_HUN_Verb_Stem = 340,         // t_HUN_Verb_Stem
    t_HUN_Verb_ConjDefSg2 = 341,   // t_HUN_Verb_ConjDefSg2
    t_HUN_Vbpfx_Stem = 342,        // t_HUN_Vbpfx_Stem
    t_HUN_Noun_Relative = 343,     // t_HUN_Noun_Relative
    t_HUN_Conj_Stem = 344,         // t_HUN_Conj_Stem
    t_HUN_Neg_Stem = 345,          // t_HUN_Neg_Stem
    t_HUN_Noun_Plur = 346,         // t_HUN_Noun_Plur
    t_HUN_Noun_Ine = 347,          // t_HUN_Noun_Ine
    t_HUN_Verb_IndefSg3 = 348,     // t_HUN_Verb_IndefSg3
    t_HUN_Verb_ConjIndefSg2 = 349, // t_HUN_Verb_ConjIndefSg2
    t_HUN_Adj_Stem = 350,          // t_HUN_Adj_Stem
    t_HUN_CON_Sub = 351,           // t_HUN_CON_Sub
    t_HUN_Noun_Sub = 352,          // t_HUN_Noun_Sub
    t_HUN_CON_Ins = 353,           // t_HUN_CON_Ins
    t_HUN_Verb_IndefPl3 = 354,     // t_HUN_Verb_IndefPl3
    t_HUN_Verb_DefSg1 = 355,       // t_HUN_Verb_DefSg1
    t_HUN_Noun_Dat = 356,          // t_HUN_Noun_Dat
    t_HUN_CON_Dat = 357,           // t_HUN_CON_Dat
    t_HUN_Num_Dat = 358,           // t_HUN_Num_Dat
    t_HUN_Noun_Del = 359,          // t_HUN_Noun_Del
    t_HUN_Num_Del = 360,           // t_HUN_Num_Del
    t_HUN_Noun_Pref = 361,         // t_HUN_Noun_Pref
    t_JSON_CON_Stem = 362,         // t_JSON_CON_Stem
    t_JSON_Punct_Stem = 363,       // t_JSON_Punct_Stem
    t_JSON_Punct_Dot = 364,        // t_JSON_Punct_Dot
    t_JSON_Punct_Comma = 365,      // t_JSON_Punct_Comma
    t_JSON_Punct_Colon = 366,      // t_JSON_Punct_Colon
    t_JSON_Punct_Quotes = 367,     // t_JSON_Punct_Quotes
    t_JSON_Punct_OpeningSBracket = 368, // t_JSON_Punct_OpeningSBracket
    t_JSON_Punct_ClosingSBracket = 369, // t_JSON_Punct_ClosingSBracket
    t_JSON_Punct_OpeningCBracket = 370, // t_JSON_Punct_OpeningCBracket
    t_JSON_Punct_ClosingCBracket = 371, // t_JSON_Punct_ClosingCBracket
    t_JSON_Punct_Relative = 372    // t_JSON_Punct_Relative
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 118, ///< Number of tokens.
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
        S_t_HUN_Punct_Stem = 41,                 // t_HUN_Punct_Stem
        S_t_HUN_Punct_FullStop = 42,             // t_HUN_Punct_FullStop
        S_t_HUN_Punct_QuestionMark = 43,         // t_HUN_Punct_QuestionMark
        S_t_HUN_Punct_ExclamationMark = 44,      // t_HUN_Punct_ExclamationMark
        S_t_HUN_Pronoun_Stem = 45,               // t_HUN_Pronoun_Stem
        S_t_HUN_Pronoun_Int = 46,                // t_HUN_Pronoun_Int
        S_t_HUN_Pronoun_Nom = 47,                // t_HUN_Pronoun_Nom
        S_t_HUN_Num_Stem = 48,                   // t_HUN_Num_Stem
        S_t_HUN_Num_Ik = 49,                     // t_HUN_Num_Ik
        S_t_HUN_Num_Par = 50,                    // t_HUN_Num_Par
        S_t_HUN_Num_Npref1 = 51,                 // t_HUN_Num_Npref1
        S_t_HUN_Num_Npref2 = 52,                 // t_HUN_Num_Npref2
        S_t_HUN_Num_Npref3 = 53,                 // t_HUN_Num_Npref3
        S_t_HUN_Num_Npref4 = 54,                 // t_HUN_Num_Npref4
        S_t_HUN_Num_Npref5 = 55,                 // t_HUN_Num_Npref5
        S_t_HUN_Num_Npref6 = 56,                 // t_HUN_Num_Npref6
        S_t_HUN_Num_Npref7 = 57,                 // t_HUN_Num_Npref7
        S_t_HUN_Num_Npref8 = 58,                 // t_HUN_Num_Npref8
        S_t_HUN_Num_Npref9 = 59,                 // t_HUN_Num_Npref9
        S_t_HUN_Num_Npref1nn = 60,               // t_HUN_Num_Npref1nn
        S_t_HUN_Num_Npref1nnn = 61,              // t_HUN_Num_Npref1nnn
        S_t_HUN_Det_Stem = 62,                   // t_HUN_Det_Stem
        S_t_HUN_Det_Def = 63,                    // t_HUN_Det_Def
        S_t_HUN_Det_fwVowel = 64,                // t_HUN_Det_fwVowel
        S_t_HUN_Det_fwConsonant = 65,            // t_HUN_Det_fwConsonant
        S_t_HUN_CON_swVowel = 66,                // t_HUN_CON_swVowel
        S_t_HUN_CON_swConsonant = 67,            // t_HUN_CON_swConsonant
        S_t_HUN_Num_Acc = 68,                    // t_HUN_Num_Acc
        S_t_HUN_Num_Npref1n = 69,                // t_HUN_Num_Npref1n
        S_t_HUN_Num_Npref2n = 70,                // t_HUN_Num_Npref2n
        S_t_HUN_Num_Npref3n = 71,                // t_HUN_Num_Npref3n
        S_t_HUN_Num_Npref4n = 72,                // t_HUN_Num_Npref4n
        S_t_HUN_Num_Npref5n = 73,                // t_HUN_Num_Npref5n
        S_t_HUN_Num_Npref6n = 74,                // t_HUN_Num_Npref6n
        S_t_HUN_Num_Npref7n = 75,                // t_HUN_Num_Npref7n
        S_t_HUN_Num_Npref8n = 76,                // t_HUN_Num_Npref8n
        S_t_HUN_Num_Npref9n = 77,                // t_HUN_Num_Npref9n
        S_t_HUN_Num_swVowel = 78,                // t_HUN_Num_swVowel
        S_t_HUN_Num_swConsonant = 79,            // t_HUN_Num_swConsonant
        S_t_HUN_Noun_Stem = 80,                  // t_HUN_Noun_Stem
        S_t_HUN_Noun_Acc = 81,                   // t_HUN_Noun_Acc
        S_t_HUN_Noun_swVowel = 82,               // t_HUN_Noun_swVowel
        S_t_HUN_Noun_swConsonant = 83,           // t_HUN_Noun_swConsonant
        S_t_HUN_CON_Acc = 84,                    // t_HUN_CON_Acc
        S_t_HUN_Verb_Stem = 85,                  // t_HUN_Verb_Stem
        S_t_HUN_Verb_ConjDefSg2 = 86,            // t_HUN_Verb_ConjDefSg2
        S_t_HUN_Vbpfx_Stem = 87,                 // t_HUN_Vbpfx_Stem
        S_t_HUN_Noun_Relative = 88,              // t_HUN_Noun_Relative
        S_t_HUN_Conj_Stem = 89,                  // t_HUN_Conj_Stem
        S_t_HUN_Neg_Stem = 90,                   // t_HUN_Neg_Stem
        S_t_HUN_Noun_Plur = 91,                  // t_HUN_Noun_Plur
        S_t_HUN_Noun_Ine = 92,                   // t_HUN_Noun_Ine
        S_t_HUN_Verb_IndefSg3 = 93,              // t_HUN_Verb_IndefSg3
        S_t_HUN_Verb_ConjIndefSg2 = 94,          // t_HUN_Verb_ConjIndefSg2
        S_t_HUN_Adj_Stem = 95,                   // t_HUN_Adj_Stem
        S_t_HUN_CON_Sub = 96,                    // t_HUN_CON_Sub
        S_t_HUN_Noun_Sub = 97,                   // t_HUN_Noun_Sub
        S_t_HUN_CON_Ins = 98,                    // t_HUN_CON_Ins
        S_t_HUN_Verb_IndefPl3 = 99,              // t_HUN_Verb_IndefPl3
        S_t_HUN_Verb_DefSg1 = 100,               // t_HUN_Verb_DefSg1
        S_t_HUN_Noun_Dat = 101,                  // t_HUN_Noun_Dat
        S_t_HUN_CON_Dat = 102,                   // t_HUN_CON_Dat
        S_t_HUN_Num_Dat = 103,                   // t_HUN_Num_Dat
        S_t_HUN_Noun_Del = 104,                  // t_HUN_Noun_Del
        S_t_HUN_Num_Del = 105,                   // t_HUN_Num_Del
        S_t_HUN_Noun_Pref = 106,                 // t_HUN_Noun_Pref
        S_t_JSON_CON_Stem = 107,                 // t_JSON_CON_Stem
        S_t_JSON_Punct_Stem = 108,               // t_JSON_Punct_Stem
        S_t_JSON_Punct_Dot = 109,                // t_JSON_Punct_Dot
        S_t_JSON_Punct_Comma = 110,              // t_JSON_Punct_Comma
        S_t_JSON_Punct_Colon = 111,              // t_JSON_Punct_Colon
        S_t_JSON_Punct_Quotes = 112,             // t_JSON_Punct_Quotes
        S_t_JSON_Punct_OpeningSBracket = 113,    // t_JSON_Punct_OpeningSBracket
        S_t_JSON_Punct_ClosingSBracket = 114,    // t_JSON_Punct_ClosingSBracket
        S_t_JSON_Punct_OpeningCBracket = 115,    // t_JSON_Punct_OpeningCBracket
        S_t_JSON_Punct_ClosingCBracket = 116,    // t_JSON_Punct_ClosingCBracket
        S_t_JSON_Punct_Relative = 117,           // t_JSON_Punct_Relative
        S_YYACCEPT = 118,                        // $accept
        S_ENG_1Con = 119,                        // ENG_1Con
        S_ENG_A = 120,                           // ENG_A
        S_ENG_A0NEG = 121,                       // ENG_A0NEG
        S_ENG_ANEG = 122,                        // ENG_ANEG
        S_ENG_ANEG_Stem = 123,                   // ENG_ANEG_Stem
        S_ENG_AP = 124,                          // ENG_AP
        S_ENG_A_Stem = 125,                      // ENG_A_Stem
        S_ENG_Abar1 = 126,                       // ENG_Abar1
        S_ENG_Abar2 = 127,                       // ENG_Abar2
        S_ENG_Adv = 128,                         // ENG_Adv
        S_ENG_AdvP = 129,                        // ENG_AdvP
        S_ENG_Alist = 130,                       // ENG_Alist
        S_ENG_CAP = 131,                         // ENG_CAP
        S_ENG_CNP = 132,                         // ENG_CNP
        S_ENG_CONJ = 133,                        // ENG_CONJ
        S_ENG_CONJA = 134,                       // ENG_CONJA
        S_ENG_CONJ_Stem = 135,                   // ENG_CONJ_Stem
        S_ENG_Con = 136,                         // ENG_Con
        S_ENG_ConjPVP = 137,                     // ENG_ConjPVP
        S_ENG_ConjV = 138,                       // ENG_ConjV
        S_ENG_DP = 139,                          // ENG_DP
        S_ENG_Def_Det = 140,                     // ENG_Def_Det
        S_ENG_Det_stem = 141,                    // ENG_Det_stem
        S_ENG_IVP = 142,                         // ENG_IVP
        S_ENG_IVPConj = 143,                     // ENG_IVPConj
        S_ENG_IVPlist = 144,                     // ENG_IVPlist
        S_ENG_Indef_Det = 145,                   // ENG_Indef_Det
        S_ENG_Indef_Det_a = 146,                 // ENG_Indef_Det_a
        S_ENG_Indef_Det_an = 147,                // ENG_Indef_Det_an
        S_ENG_N = 148,                           // ENG_N
        S_ENG_NP = 149,                          // ENG_NP
        S_ENG_NV = 150,                          // ENG_NV
        S_ENG_NV_Aux = 151,                      // ENG_NV_Aux
        S_ENG_N_Pl = 152,                        // ENG_N_Pl
        S_ENG_N_Pl_0Con = 153,                   // ENG_N_Pl_0Con
        S_ENG_N_Pl_0Con_swC = 154,               // ENG_N_Pl_0Con_swC
        S_ENG_N_Pl_0Con_swV = 155,               // ENG_N_Pl_0Con_swV
        S_ENG_N_Sg = 156,                        // ENG_N_Sg
        S_ENG_N_Sg_0Con = 157,                   // ENG_N_Sg_0Con
        S_ENG_N_Sg_0Con_swC = 158,               // ENG_N_Sg_0Con_swC
        S_ENG_N_Sg_0Con_swV = 159,               // ENG_N_Sg_0Con_swV
        S_ENG_N_Stem = 160,                      // ENG_N_Stem
        S_ENG_N_lfea_Pl = 161,                   // ENG_N_lfea_Pl
        S_ENG_N_lfea_Sg = 162,                   // ENG_N_lfea_Sg
        S_ENG_Num = 163,                         // ENG_Num
        S_ENG_Num_Ord = 164,                     // ENG_Num_Ord
        S_ENG_Num_Pref = 165,                    // ENG_Num_Pref
        S_ENG_Num_Stem = 166,                    // ENG_Num_Stem
        S_ENG_Num_lfea_Ord = 167,                // ENG_Num_lfea_Ord
        S_ENG_PNVPbar = 168,                     // ENG_PNVPbar
        S_ENG_PP = 169,                          // ENG_PP
        S_ENG_PVP = 170,                         // ENG_PVP
        S_ENG_PVPConj = 171,                     // ENG_PVPConj
        S_ENG_PVPbar = 172,                      // ENG_PVPbar
        S_ENG_PVPhead = 173,                     // ENG_PVPhead
        S_ENG_PVPlist = 174,                     // ENG_PVPlist
        S_ENG_PVPlisthead = 175,                 // ENG_PVPlisthead
        S_ENG_Prep = 176,                        // ENG_Prep
        S_ENG_QPro = 177,                        // ENG_QPro
        S_ENG_RC = 178,                          // ENG_RC
        S_ENG_RPro = 179,                        // ENG_RPro
        S_ENG_RPro_lfea_relative = 180,          // ENG_RPro_lfea_relative
        S_ENG_RPro_stem = 181,                   // ENG_RPro_stem
        S_ENG_TP = 182,                          // ENG_TP
        S_ENG_Tense_particle = 183,              // ENG_Tense_particle
        S_ENG_V = 184,                           // ENG_V
        S_ENG_VNEG = 185,                        // ENG_VNEG
        S_ENG_VNEG_Stem = 186,                   // ENG_VNEG_Stem
        S_ENG_VP = 187,                          // ENG_VP
        S_ENG_V_Aux = 188,                       // ENG_V_Aux
        S_ENG_V_Ger = 189,                       // ENG_V_Ger
        S_ENG_V_Stem = 190,                      // ENG_V_Stem
        S_ENG_V_lfea_aux = 191,                  // ENG_V_lfea_aux
        S_ENG_V_lfea_ger = 192,                  // ENG_V_lfea_ger
        S_ENG_Vbar1 = 193,                       // ENG_Vbar1
        S_ENG_Vbar2 = 194,                       // ENG_Vbar2
        S_ENG_Vbar3 = 195,                       // ENG_Vbar3
        S_ENG_Vbar4 = 196,                       // ENG_Vbar4
        S_ENG_Vhead = 197,                       // ENG_Vhead
        S_ENG_Vlisthead = 198,                   // ENG_Vlisthead
        S_ENG_lfea_DefDet = 199,                 // ENG_lfea_DefDet
        S_ENG_lfea_IndefDet = 200,               // ENG_lfea_IndefDet
        S_ENG_lfea_fwConsonant = 201,            // ENG_lfea_fwConsonant
        S_ENG_lfea_fwVowel = 202,                // ENG_lfea_fwVowel
        S_ENG_lfea_swConsonant = 203,            // ENG_lfea_swConsonant
        S_ENG_lfea_swVowel = 204,                // ENG_lfea_swVowel
        S_ENG_nCon = 205,                        // ENG_nCon
        S_HUN_1Con = 206,                        // HUN_1Con
        S_HUN_A0NEG = 207,                       // HUN_A0NEG
        S_HUN_ANEG = 208,                        // HUN_ANEG
        S_HUN_ANP = 209,                         // HUN_ANP
        S_HUN_AN_Acc = 210,                      // HUN_AN_Acc
        S_HUN_AP = 211,                          // HUN_AP
        S_HUN_Abar1 = 212,                       // HUN_Abar1
        S_HUN_Abar1N = 213,                      // HUN_Abar1N
        S_HUN_Abar2 = 214,                       // HUN_Abar2
        S_HUN_Abar2N = 215,                      // HUN_Abar2N
        S_HUN_Abar3 = 216,                       // HUN_Abar3
        S_HUN_Abar3_End = 217,                   // HUN_Abar3_End
        S_HUN_Abar4 = 218,                       // HUN_Abar4
        S_HUN_Adj = 219,                         // HUN_Adj
        S_HUN_Adj_Stem = 220,                    // HUN_Adj_Stem
        S_HUN_Alist = 221,                       // HUN_Alist
        S_HUN_Alist_End = 222,                   // HUN_Alist_End
        S_HUN_Con = 223,                         // HUN_Con
        S_HUN_Con_lfea_Acc = 224,                // HUN_Con_lfea_Acc
        S_HUN_Con_lfea_Dat = 225,                // HUN_Con_lfea_Dat
        S_HUN_Con_lfea_Ins = 226,                // HUN_Con_lfea_Ins
        S_HUN_Con_lfea_Sub = 227,                // HUN_Con_lfea_Sub
        S_HUN_Conj = 228,                        // HUN_Conj
        S_HUN_ConjA = 229,                       // HUN_ConjA
        S_HUN_ConjA_End = 230,                   // HUN_ConjA_End
        S_HUN_ConjAlist = 231,                   // HUN_ConjAlist
        S_HUN_ConjN = 232,                       // HUN_ConjN
        S_HUN_ConjNbar1 = 233,                   // HUN_ConjNbar1
        S_HUN_ConjV = 234,                       // HUN_ConjV
        S_HUN_Conj_Stem = 235,                   // HUN_Conj_Stem
        S_HUN_DP = 236,                          // HUN_DP
        S_HUN_DPbar = 237,                       // HUN_DPbar
        S_HUN_Def_Det = 238,                     // HUN_Def_Det
        S_HUN_Def_Det_a = 239,                   // HUN_Def_Det_a
        S_HUN_Def_Det_az = 240,                  // HUN_Def_Det_az
        S_HUN_Det_stem = 241,                    // HUN_Det_stem
        S_HUN_Empty = 242,                       // HUN_Empty
        S_HUN_INVP = 243,                        // HUN_INVP
        S_HUN_INVPbar = 244,                     // HUN_INVPbar
        S_HUN_INVPbar2 = 245,                    // HUN_INVPbar2
        S_HUN_IVP = 246,                         // HUN_IVP
        S_HUN_IVPConj = 247,                     // HUN_IVPConj
        S_HUN_IVPbar = 248,                      // HUN_IVPbar
        S_HUN_IVPlist = 249,                     // HUN_IVPlist
        S_HUN_ImpVerb = 250,                     // HUN_ImpVerb
        S_HUN_ImpVerbPfx = 251,                  // HUN_ImpVerbPfx
        S_HUN_ImpVerb_N_Acc = 252,               // HUN_ImpVerb_N_Acc
        S_HUN_ImpVerb_N_Dat = 253,               // HUN_ImpVerb_N_Dat
        S_HUN_IndVerb = 254,                     // HUN_IndVerb
        S_HUN_NAbar1 = 255,                      // HUN_NAbar1
        S_HUN_NP = 256,                          // HUN_NP
        S_HUN_N_Acc = 257,                       // HUN_N_Acc
        S_HUN_N_Dat = 258,                       // HUN_N_Dat
        S_HUN_N_Ine = 259,                       // HUN_N_Ine
        S_HUN_N_Ins = 260,                       // HUN_N_Ins
        S_HUN_N_Pl = 261,                        // HUN_N_Pl
        S_HUN_N_Sg = 262,                        // HUN_N_Sg
        S_HUN_N_Sub = 263,                       // HUN_N_Sub
        S_HUN_Neg = 264,                         // HUN_Neg
        S_HUN_Neg_Stem = 265,                    // HUN_Neg_Stem
        S_HUN_Noun_Pref = 266,                   // HUN_Noun_Pref
        S_HUN_Noun_Stem = 267,                   // HUN_Noun_Stem
        S_HUN_Noun_lfea_Acc = 268,               // HUN_Noun_lfea_Acc
        S_HUN_Noun_lfea_Dat = 269,               // HUN_Noun_lfea_Dat
        S_HUN_Noun_lfea_Del = 270,               // HUN_Noun_lfea_Del
        S_HUN_Noun_lfea_Ine = 271,               // HUN_Noun_lfea_Ine
        S_HUN_Noun_lfea_Plur = 272,              // HUN_Noun_lfea_Plur
        S_HUN_Noun_lfea_Relative = 273,          // HUN_Noun_lfea_Relative
        S_HUN_Noun_lfea_Sub = 274,               // HUN_Noun_lfea_Sub
        S_HUN_Num = 275,                         // HUN_Num
        S_HUN_Num_Pref = 276,                    // HUN_Num_Pref
        S_HUN_Num_Stem = 277,                    // HUN_Num_Stem
        S_HUN_Num_lfea_Acc = 278,                // HUN_Num_lfea_Acc
        S_HUN_Num_lfea_Dat = 279,                // HUN_Num_lfea_Dat
        S_HUN_Num_lfea_Del = 280,                // HUN_Num_lfea_Del
        S_HUN_Num_lfea_Ik = 281,                 // HUN_Num_lfea_Ik
        S_HUN_Num_lfea_Par = 282,                // HUN_Num_lfea_Par
        S_HUN_Nums = 283,                        // HUN_Nums
        S_HUN_Pron_Int = 284,                    // HUN_Pron_Int
        S_HUN_Pron_Stem = 285,                   // HUN_Pron_Stem
        S_HUN_Pron_lfea_Int = 286,               // HUN_Pron_lfea_Int
        S_HUN_Pron_lfea_Nom = 287,               // HUN_Pron_lfea_Nom
        S_HUN_Punct = 288,                       // HUN_Punct
        S_HUN_Punct_ExclamationMark = 289,       // HUN_Punct_ExclamationMark
        S_HUN_Punct_FullStop = 290,              // HUN_Punct_FullStop
        S_HUN_Punct_QuestionMark = 291,          // HUN_Punct_QuestionMark
        S_HUN_Punct_Stem = 292,                  // HUN_Punct_Stem
        S_HUN_RC = 293,                          // HUN_RC
        S_HUN_RPro = 294,                        // HUN_RPro
        S_HUN_V = 295,                           // HUN_V
        S_HUN_VP = 296,                          // HUN_VP
        S_HUN_Vbar1 = 297,                       // HUN_Vbar1
        S_HUN_Vbar2 = 298,                       // HUN_Vbar2
        S_HUN_Vbar3 = 299,                       // HUN_Vbar3
        S_HUN_Vbpfx = 300,                       // HUN_Vbpfx
        S_HUN_Verb_lfea_ConjDefSg2 = 301,        // HUN_Verb_lfea_ConjDefSg2
        S_HUN_Verb_lfea_ConjIndefSg2 = 302,      // HUN_Verb_lfea_ConjIndefSg2
        S_HUN_Verb_lfea_DefSg1 = 303,            // HUN_Verb_lfea_DefSg1
        S_HUN_Verb_lfea_InDefSg3 = 304,          // HUN_Verb_lfea_InDefSg3
        S_HUN_Verb_lfea_IndefPl3 = 305,          // HUN_Verb_lfea_IndefPl3
        S_HUN_Verb_stem = 306,                   // HUN_Verb_stem
        S_HUN_Vhead = 307,                       // HUN_Vhead
        S_HUN_Vlisthead = 308,                   // HUN_Vlisthead
        S_HUN_lfea_DefDet = 309,                 // HUN_lfea_DefDet
        S_HUN_lfea_fwConsonant = 310,            // HUN_lfea_fwConsonant
        S_HUN_lfea_fwVowel = 311,                // HUN_lfea_fwVowel
        S_HUN_lfea_swConsonant = 312,            // HUN_lfea_swConsonant
        S_HUN_lfea_swVowel = 313,                // HUN_lfea_swVowel
        S_HUN_nCon = 314,                        // HUN_nCon
        S_JSON_Array = 315,                      // JSON_Array
        S_JSON_CON = 316,                        // JSON_CON
        S_JSON_ClosingCBracket = 317,            // JSON_ClosingCBracket
        S_JSON_ClosingSBracket = 318,            // JSON_ClosingSBracket
        S_JSON_Closing_Key_Value_Pair = 319,     // JSON_Closing_Key_Value_Pair
        S_JSON_Closing_Value_Element = 320,      // JSON_Closing_Value_Element
        S_JSON_Colon = 321,                      // JSON_Colon
        S_JSON_Comma = 322,                      // JSON_Comma
        S_JSON_Dot = 323,                        // JSON_Dot
        S_JSON_Dot_Relative = 324,               // JSON_Dot_Relative
        S_JSON_Dot_lfea_relative = 325,          // JSON_Dot_lfea_relative
        S_JSON_Key = 326,                        // JSON_Key
        S_JSON_Key_Value_List_Element = 327,     // JSON_Key_Value_List_Element
        S_JSON_Key_Value_Pair = 328,             // JSON_Key_Value_Pair
        S_JSON_Number = 329,                     // JSON_Number
        S_JSON_Object = 330,                     // JSON_Object
        S_JSON_Open_Array = 331,                 // JSON_Open_Array
        S_JSON_Open_Object = 332,                // JSON_Open_Object
        S_JSON_Open_String = 333,                // JSON_Open_String
        S_JSON_OpeningCBracket = 334,            // JSON_OpeningCBracket
        S_JSON_OpeningSBracket = 335,            // JSON_OpeningSBracket
        S_JSON_Punct_ClosingCBracket = 336,      // JSON_Punct_ClosingCBracket
        S_JSON_Punct_ClosingSBracket = 337,      // JSON_Punct_ClosingSBracket
        S_JSON_Punct_Colon = 338,                // JSON_Punct_Colon
        S_JSON_Punct_Comma = 339,                // JSON_Punct_Comma
        S_JSON_Punct_Dot = 340,                  // JSON_Punct_Dot
        S_JSON_Punct_OpeningCBracket = 341,      // JSON_Punct_OpeningCBracket
        S_JSON_Punct_OpeningSBracket = 342,      // JSON_Punct_OpeningSBracket
        S_JSON_Punct_Quotes = 343,               // JSON_Punct_Quotes
        S_JSON_Punct_Stem = 344,                 // JSON_Punct_Stem
        S_JSON_Quotes = 345,                     // JSON_Quotes
        S_JSON_String = 346,                     // JSON_String
        S_JSON_Value_List_Element = 347,         // JSON_Value_List_Element
        S_S = 348                                // S
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
      basic_symbol () YY_NOEXCEPT
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
                    YY_RVREF (value_type) v);

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
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
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

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
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
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
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

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

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const short yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const short yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
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

      stack (size_type n = 200) YY_NOEXCEPT
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
        slice (const stack& stack, index_type range) YY_NOEXCEPT
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
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1663,     ///< Last index in yytable_.
      yynnts_ = 231,  ///< Number of nonterminal symbols.
      yyfinal_ = 274 ///< Termination state number.
    };



  };


} // yy
#line 1215 "build/hi_desktop/hi.y.cpp"






// Unqualified %code blocks.
#line 1 "build/hi_desktop/hi.y"

#include "tokensymbols.h"
#line 4 "build/hi_desktop/hi.y"

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
morphan *stemmer=NULL;
lexer *lex=NULL;
interpreter *sparser=NULL;
tokenpaths *token_paths=NULL;
db *db_factory::singleton_instance=NULL;


#line 1257 "build/hi_desktop/hi.y.cpp"


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
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 1330 "build/hi_desktop/hi.y.cpp"

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

  /*---------.
  | symbol.  |
  `---------*/

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
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
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
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
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
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
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
  parser::yypop_ (int n) YY_NOEXCEPT
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
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
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
#line 160 "build/hi_desktop/hi.y"
{
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_1Con->ENG_Con");
yylhs.value=sparser->set_node_info("ENG_1Con",ENG_Con);

}
#line 1791 "build/hi_desktop/hi.y.cpp"
    break;

  case 3: // ENG_A: ENG_A_Stem
#line 168 "build/hi_desktop/hi.y"
{
const node_info& ENG_A_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A->ENG_A_Stem");
yylhs.value=sparser->set_node_info("ENG_A",ENG_A_Stem);

}
#line 1802 "build/hi_desktop/hi.y.cpp"
    break;

  case 4: // ENG_A0NEG: ENG_A
#line 176 "build/hi_desktop/hi.y"
{
const node_info& ENG_A=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A0NEG->ENG_A");
yylhs.value=sparser->set_node_info("ENG_A0NEG",ENG_A);

}
#line 1813 "build/hi_desktop/hi.y.cpp"
    break;

  case 5: // ENG_ANEG: ENG_ANEG_Stem
#line 184 "build/hi_desktop/hi.y"
{
const node_info& ENG_ANEG_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ANEG->ENG_ANEG_Stem");
yylhs.value=sparser->set_node_info("ENG_ANEG",ENG_ANEG_Stem);

}
#line 1824 "build/hi_desktop/hi.y.cpp"
    break;

  case 6: // ENG_ANEG_Stem: t_ENG_ANEG_Stem
#line 192 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ANEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_ANEG_Stem",word);

}
#line 1836 "build/hi_desktop/hi.y.cpp"
    break;

  case 7: // ENG_AP: ENG_Abar1
#line 201 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar1");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Abar1);

}
#line 1847 "build/hi_desktop/hi.y.cpp"
    break;

  case 8: // ENG_AP: ENG_Abar2
#line 208 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar2");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Abar2);

}
#line 1858 "build/hi_desktop/hi.y.cpp"
    break;

  case 9: // ENG_AP: ENG_Alist
#line 215 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Alist");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Alist);

}
#line 1869 "build/hi_desktop/hi.y.cpp"
    break;

  case 10: // ENG_A_Stem: t_ENG_A_Stem
#line 223 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_A_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_A_Stem",word);

}
#line 1881 "build/hi_desktop/hi.y.cpp"
    break;

  case 11: // ENG_Abar1: ENG_A0NEG
#line 232 "build/hi_desktop/hi.y"
{
const node_info& ENG_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_A0NEG");
yylhs.value=sparser->set_node_info("ENG_Abar1",ENG_A0NEG);

}
#line 1892 "build/hi_desktop/hi.y.cpp"
    break;

  case 12: // ENG_Abar1: ENG_ANEG ENG_A
#line 239 "build/hi_desktop/hi.y"
{
const node_info& ENG_ANEG=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_A=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_ANEG ENG_A");
yylhs.value=sparser->combine_nodes("ENG_Abar1",ENG_ANEG,ENG_A);

}
#line 1904 "build/hi_desktop/hi.y.cpp"
    break;

  case 13: // ENG_Abar2: ENG_Abar1 ENG_CONJA
#line 248 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar1 ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Abar1,ENG_CONJA);

}
#line 1916 "build/hi_desktop/hi.y.cpp"
    break;

  case 14: // ENG_Abar2: ENG_Abar2 ENG_CONJA
#line 256 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar2 ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Abar2,ENG_CONJA);

}
#line 1928 "build/hi_desktop/hi.y.cpp"
    break;

  case 15: // ENG_Abar2: ENG_Alist ENG_CONJA
#line 264 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Alist ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Alist,ENG_CONJA);

}
#line 1940 "build/hi_desktop/hi.y.cpp"
    break;

  case 16: // ENG_Adv: t_ENG_ADV_Stem
#line 273 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ADV_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Adv",word);

}
#line 1952 "build/hi_desktop/hi.y.cpp"
    break;

  case 17: // ENG_AdvP: ENG_Adv
#line 282 "build/hi_desktop/hi.y"
{
const node_info& ENG_Adv=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AdvP->ENG_Adv");
yylhs.value=sparser->set_node_info("ENG_AdvP",ENG_Adv);

}
#line 1963 "build/hi_desktop/hi.y.cpp"
    break;

  case 18: // ENG_Alist: ENG_Abar1 ENG_Abar1
#line 290 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar11=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar12=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Abar1 ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_Alist",ENG_Abar11,ENG_Abar12);

}
#line 1975 "build/hi_desktop/hi.y.cpp"
    break;

  case 19: // ENG_Alist: ENG_Alist ENG_Abar1
#line 298 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Alist ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_Alist",ENG_Alist,ENG_Abar1);

}
#line 1987 "build/hi_desktop/hi.y.cpp"
    break;

  case 20: // ENG_CAP: ENG_1Con ENG_N_Pl_0Con_swC
#line 307 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swC");
yylhs.value=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swC);

}
#line 1999 "build/hi_desktop/hi.y.cpp"
    break;

  case 21: // ENG_CAP: ENG_1Con ENG_N_Pl_0Con_swV
#line 315 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swV");
yylhs.value=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swV);

}
#line 2011 "build/hi_desktop/hi.y.cpp"
    break;

  case 22: // ENG_CNP: ENG_AP ENG_N
#line 324 "build/hi_desktop/hi.y"
{
const node_info& ENG_AP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_AP ENG_N");
yylhs.value=sparser->combine_nodes("ENG_CNP",ENG_AP,ENG_N);

}
#line 2023 "build/hi_desktop/hi.y.cpp"
    break;

  case 23: // ENG_CNP: ENG_N
#line 332 "build/hi_desktop/hi.y"
{
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_N");
yylhs.value=sparser->set_node_info("ENG_CNP",ENG_N);

}
#line 2034 "build/hi_desktop/hi.y.cpp"
    break;

  case 24: // ENG_CONJ: ENG_CONJ_Stem
#line 340 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJ->ENG_CONJ_Stem");
yylhs.value=sparser->set_node_info("ENG_CONJ",ENG_CONJ_Stem);

}
#line 2045 "build/hi_desktop/hi.y.cpp"
    break;

  case 25: // ENG_CONJA: ENG_CONJ ENG_Abar1
#line 348 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Abar1);

}
#line 2057 "build/hi_desktop/hi.y.cpp"
    break;

  case 26: // ENG_CONJA: ENG_CONJ ENG_Alist
#line 356 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Alist");
yylhs.value=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Alist);

}
#line 2069 "build/hi_desktop/hi.y.cpp"
    break;

  case 27: // ENG_CONJ_Stem: t_ENG_CONJ_Stem
#line 365 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CONJ_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_CONJ_Stem",word);

}
#line 2081 "build/hi_desktop/hi.y.cpp"
    break;

  case 28: // ENG_Con: t_ENG_CON_Stem
#line 374 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Con",word);

}
#line 2093 "build/hi_desktop/hi.y.cpp"
    break;

  case 29: // ENG_ConjPVP: ENG_CONJ ENG_PVP
#line 383 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjPVP->ENG_CONJ ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_ConjPVP",ENG_CONJ,ENG_PVP);

}
#line 2105 "build/hi_desktop/hi.y.cpp"
    break;

  case 30: // ENG_ConjPVP: ENG_CONJ ENG_PVPlist
#line 391 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjPVP->ENG_CONJ ENG_PVPlist");
yylhs.value=sparser->combine_nodes("ENG_ConjPVP",ENG_CONJ,ENG_PVPlist);

}
#line 2117 "build/hi_desktop/hi.y.cpp"
    break;

  case 31: // ENG_ConjV: ENG_CONJ ENG_IVP
#line 400 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjV->ENG_CONJ ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_ConjV",ENG_CONJ,ENG_IVP);

}
#line 2129 "build/hi_desktop/hi.y.cpp"
    break;

  case 32: // ENG_ConjV: ENG_CONJ ENG_IVPlist
#line 408 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjV->ENG_CONJ ENG_IVPlist");
yylhs.value=sparser->combine_nodes("ENG_ConjV",ENG_CONJ,ENG_IVPlist);

}
#line 2141 "build/hi_desktop/hi.y.cpp"
    break;

  case 33: // ENG_DP: ENG_Def_Det ENG_N
#line 417 "build/hi_desktop/hi.y"
{
const node_info& ENG_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Def_Det ENG_N");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Def_Det,ENG_N);

}
#line 2153 "build/hi_desktop/hi.y.cpp"
    break;

  case 34: // ENG_DP: ENG_Def_Det ENG_Num_Ord
#line 425 "build/hi_desktop/hi.y"
{
const node_info& ENG_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_Ord=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Def_Det ENG_Num_Ord");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Def_Det,ENG_Num_Ord);

}
#line 2165 "build/hi_desktop/hi.y.cpp"
    break;

  case 35: // ENG_DP: ENG_Indef_Det_a ENG_N_Sg_0Con_swC
#line 433 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det_a=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);

}
#line 2177 "build/hi_desktop/hi.y.cpp"
    break;

  case 36: // ENG_DP: ENG_Indef_Det_an ENG_N_Sg_0Con_swV
#line 441 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det_an=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);

}
#line 2189 "build/hi_desktop/hi.y.cpp"
    break;

  case 37: // ENG_Def_Det: ENG_Det_stem ENG_lfea_DefDet
#line 450 "build/hi_desktop/hi.y"
{
const node_info& ENG_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_DefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Def_Det->ENG_Det_stem ENG_lfea_DefDet");
yylhs.value=sparser->combine_nodes("ENG_Def_Det",ENG_Det_stem,ENG_lfea_DefDet);

}
#line 2201 "build/hi_desktop/hi.y.cpp"
    break;

  case 38: // ENG_Det_stem: t_ENG_DET_Stem
#line 459 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Det_stem",word);

}
#line 2213 "build/hi_desktop/hi.y.cpp"
    break;

  case 39: // ENG_IVP: ENG_NV ENG_NP
#line 468 "build/hi_desktop/hi.y"
{
const node_info& ENG_NV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_NV,"ENG_V_Aux","V",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_NP);
}
#line 2225 "build/hi_desktop/hi.y.cpp"
    break;

  case 40: // ENG_IVP: ENG_NV ENG_PP
#line 476 "build/hi_desktop/hi.y"
{
const node_info& ENG_NV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_NV,"ENG_V_Aux","V",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
}
#line 2237 "build/hi_desktop/hi.y.cpp"
    break;

  case 41: // ENG_IVP: ENG_V ENG_AP
#line 484 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_AP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_AP);
}
#line 2249 "build/hi_desktop/hi.y.cpp"
    break;

  case 42: // ENG_IVP: ENG_V ENG_NP
#line 492 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
unsigned int leaf_node_id=sparser->add_feature_to_leaf(ENG_V,"ENG_V_Aux","V",std::string("RCV"));
if(leaf_node_id==0) sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_NP);
}
#line 2262 "build/hi_desktop/hi.y.cpp"
    break;

  case 43: // ENG_IVP: ENG_V ENG_PP
#line 501 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
unsigned int leaf_node_id=sparser->add_feature_to_leaf(ENG_V,"ENG_V_Aux","V",std::string("RCV"));
if(leaf_node_id==0) sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
}
#line 2275 "build/hi_desktop/hi.y.cpp"
    break;

  case 44: // ENG_IVPConj: ENG_IVPConj ENG_ConjV
#line 511 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_IVPConj ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_IVPConj,ENG_ConjV);

}
#line 2287 "build/hi_desktop/hi.y.cpp"
    break;

  case 45: // ENG_IVPConj: ENG_Vhead ENG_ConjV
#line 519 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vhead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_Vhead ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_Vhead,ENG_ConjV);

}
#line 2299 "build/hi_desktop/hi.y.cpp"
    break;

  case 46: // ENG_IVPConj: ENG_Vlisthead ENG_ConjV
#line 527 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_Vlisthead ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_Vlisthead,ENG_ConjV);

}
#line 2311 "build/hi_desktop/hi.y.cpp"
    break;

  case 47: // ENG_IVPlist: ENG_IVP ENG_IVP
#line 536 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVP1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPlist->ENG_IVP ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_IVPlist",ENG_IVP1,ENG_IVP2);

}
#line 2323 "build/hi_desktop/hi.y.cpp"
    break;

  case 48: // ENG_IVPlist: ENG_IVPlist ENG_IVP
#line 544 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPlist->ENG_IVPlist ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_IVPlist",ENG_IVPlist,ENG_IVP);

}
#line 2335 "build/hi_desktop/hi.y.cpp"
    break;

  case 49: // ENG_Indef_Det: ENG_Det_stem ENG_lfea_IndefDet
#line 553 "build/hi_desktop/hi.y"
{
const node_info& ENG_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_IndefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);

}
#line 2347 "build/hi_desktop/hi.y.cpp"
    break;

  case 50: // ENG_Indef_Det_a: ENG_Indef_Det ENG_lfea_fwConsonant
#line 562 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_fwConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);

}
#line 2359 "build/hi_desktop/hi.y.cpp"
    break;

  case 51: // ENG_Indef_Det_an: ENG_Indef_Det ENG_lfea_fwVowel
#line 571 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_fwVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);

}
#line 2371 "build/hi_desktop/hi.y.cpp"
    break;

  case 52: // ENG_N: ENG_N_Pl
#line 580 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Pl");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Pl);

}
#line 2382 "build/hi_desktop/hi.y.cpp"
    break;

  case 53: // ENG_N: ENG_N_Sg
#line 587 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Sg");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Sg);

}
#line 2393 "build/hi_desktop/hi.y.cpp"
    break;

  case 54: // ENG_NP: ENG_CAP
#line 595 "build/hi_desktop/hi.y"
{
const node_info& ENG_CAP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CAP");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_CAP);

}
#line 2404 "build/hi_desktop/hi.y.cpp"
    break;

  case 55: // ENG_NP: ENG_CNP
#line 602 "build/hi_desktop/hi.y"
{
const node_info& ENG_CNP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CNP");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_CNP);

}
#line 2415 "build/hi_desktop/hi.y.cpp"
    break;

  case 56: // ENG_NP: ENG_QPro ENG_CNP
#line 609 "build/hi_desktop/hi.y"
{
const node_info& ENG_QPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CNP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_QPro ENG_CNP");
yylhs.value=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);

}
#line 2427 "build/hi_desktop/hi.y.cpp"
    break;

  case 57: // ENG_NV: ENG_NV_Aux ENG_V_Stem
#line 618 "build/hi_desktop/hi.y"
{
const node_info& ENG_NV_Aux=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_NV_Aux ENG_V_Stem");
yylhs.value=sparser->combine_nodes("ENG_NV",ENG_NV_Aux,ENG_V_Stem);

}
#line 2439 "build/hi_desktop/hi.y.cpp"
    break;

  case 58: // ENG_NV: ENG_V ENG_VNEG
#line 626 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_V ENG_VNEG");
yylhs.value=sparser->combine_nodes("ENG_NV",ENG_V,ENG_VNEG);

}
#line 2451 "build/hi_desktop/hi.y.cpp"
    break;

  case 59: // ENG_NV_Aux: ENG_V_Aux ENG_VNEG
#line 635 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Aux=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV_Aux->ENG_V_Aux ENG_VNEG");
yylhs.value=sparser->combine_nodes("ENG_NV_Aux",ENG_V_Aux,ENG_VNEG);

}
#line 2463 "build/hi_desktop/hi.y.cpp"
    break;

  case 60: // ENG_N_Pl: ENG_N_Pl_0Con_swC
#line 644 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swC);

}
#line 2474 "build/hi_desktop/hi.y.cpp"
    break;

  case 61: // ENG_N_Pl: ENG_N_Pl_0Con_swC ENG_nCon
#line 651 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);

}
#line 2486 "build/hi_desktop/hi.y.cpp"
    break;

  case 62: // ENG_N_Pl: ENG_N_Pl_0Con_swV
#line 659 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swV);

}
#line 2497 "build/hi_desktop/hi.y.cpp"
    break;

  case 63: // ENG_N_Pl: ENG_N_Pl_0Con_swV ENG_nCon
#line 666 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);

}
#line 2509 "build/hi_desktop/hi.y.cpp"
    break;

  case 64: // ENG_N_Pl: ENG_N_Sg ENG_nCon
#line 674 "build/hi_desktop/hi.y"
{
//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in 'list file abc def'
//TODO: Any better solution???
YYERROR;
}
#line 2520 "build/hi_desktop/hi.y.cpp"
    break;

  case 65: // ENG_N_Pl: ENG_nCon
#line 681 "build/hi_desktop/hi.y"
{
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_nCon");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_nCon);

}
#line 2531 "build/hi_desktop/hi.y.cpp"
    break;

  case 66: // ENG_N_Pl_0Con: ENG_N_Stem ENG_N_lfea_Pl
#line 689 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);

}
#line 2543 "build/hi_desktop/hi.y.cpp"
    break;

  case 67: // ENG_N_Pl_0Con_swC: ENG_N_Pl_0Con ENG_lfea_swConsonant
#line 698 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);

}
#line 2555 "build/hi_desktop/hi.y.cpp"
    break;

  case 68: // ENG_N_Pl_0Con_swV: ENG_N_Pl_0Con ENG_lfea_swVowel
#line 707 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);

}
#line 2567 "build/hi_desktop/hi.y.cpp"
    break;

  case 69: // ENG_N_Sg: ENG_1Con
#line 716 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_1Con");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_1Con);

}
#line 2578 "build/hi_desktop/hi.y.cpp"
    break;

  case 70: // ENG_N_Sg: ENG_N_Sg_0Con_swC
#line 723 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swC);

}
#line 2589 "build/hi_desktop/hi.y.cpp"
    break;

  case 71: // ENG_N_Sg: ENG_N_Sg_0Con_swC ENG_1Con
#line 730 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swC,ENG_1Con);

}
#line 2601 "build/hi_desktop/hi.y.cpp"
    break;

  case 72: // ENG_N_Sg: ENG_N_Sg_0Con_swV
#line 738 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swV);

}
#line 2612 "build/hi_desktop/hi.y.cpp"
    break;

  case 73: // ENG_N_Sg: ENG_N_Sg_0Con_swV ENG_1Con
#line 745 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swV,ENG_1Con);

}
#line 2624 "build/hi_desktop/hi.y.cpp"
    break;

  case 74: // ENG_N_Sg_0Con: ENG_N_Stem ENG_N_lfea_Sg
#line 754 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con",ENG_N_Stem,ENG_N_lfea_Sg);

}
#line 2636 "build/hi_desktop/hi.y.cpp"
    break;

  case 75: // ENG_N_Sg_0Con_swC: ENG_N_Sg_0Con ENG_lfea_swConsonant
#line 763 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);

}
#line 2648 "build/hi_desktop/hi.y.cpp"
    break;

  case 76: // ENG_N_Sg_0Con_swV: ENG_N_Sg_0Con ENG_lfea_swVowel
#line 772 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);

}
#line 2660 "build/hi_desktop/hi.y.cpp"
    break;

  case 77: // ENG_N_Stem: t_ENG_N_Stem
#line 781 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_Stem",word);

}
#line 2672 "build/hi_desktop/hi.y.cpp"
    break;

  case 78: // ENG_N_lfea_Pl: t_ENG_N_Pl
#line 790 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Pl);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Pl",word);

}
#line 2684 "build/hi_desktop/hi.y.cpp"
    break;

  case 79: // ENG_N_lfea_Sg: t_ENG_N_Sg
#line 799 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Sg",word);

}
#line 2696 "build/hi_desktop/hi.y.cpp"
    break;

  case 80: // ENG_Num: ENG_Num_Pref ENG_Num
#line 808 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Pref ENG_Num");
yylhs.value=sparser->combine_nodes("ENG_Num",ENG_Num_Pref,ENG_Num);

}
#line 2708 "build/hi_desktop/hi.y.cpp"
    break;

  case 81: // ENG_Num: ENG_Num_Stem
#line 816 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Stem");
yylhs.value=sparser->set_node_info("ENG_Num",ENG_Num_Stem);

}
#line 2719 "build/hi_desktop/hi.y.cpp"
    break;

  case 82: // ENG_Num_Ord: ENG_Num ENG_Num_lfea_Ord
#line 824 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_lfea_Ord=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num_Ord->ENG_Num ENG_Num_lfea_Ord");
yylhs.value=sparser->combine_nodes("ENG_Num_Ord",ENG_Num,ENG_Num_lfea_Ord);

}
#line 2731 "build/hi_desktop/hi.y.cpp"
    break;

  case 83: // ENG_Num_Pref: t_ENG_Num_Npref1n
#line 833 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2743 "build/hi_desktop/hi.y.cpp"
    break;

  case 84: // ENG_Num_Pref: t_ENG_Num_Npref2n
#line 841 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2755 "build/hi_desktop/hi.y.cpp"
    break;

  case 85: // ENG_Num_Pref: t_ENG_Num_Npref3n
#line 849 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2767 "build/hi_desktop/hi.y.cpp"
    break;

  case 86: // ENG_Num_Pref: t_ENG_Num_Npref4n
#line 857 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2779 "build/hi_desktop/hi.y.cpp"
    break;

  case 87: // ENG_Num_Pref: t_ENG_Num_Npref5n
#line 865 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2791 "build/hi_desktop/hi.y.cpp"
    break;

  case 88: // ENG_Num_Pref: t_ENG_Num_Npref6n
#line 873 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2803 "build/hi_desktop/hi.y.cpp"
    break;

  case 89: // ENG_Num_Pref: t_ENG_Num_Npref7n
#line 881 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2815 "build/hi_desktop/hi.y.cpp"
    break;

  case 90: // ENG_Num_Pref: t_ENG_Num_Npref8n
#line 889 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2827 "build/hi_desktop/hi.y.cpp"
    break;

  case 91: // ENG_Num_Pref: t_ENG_Num_Npref9n
#line 897 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2839 "build/hi_desktop/hi.y.cpp"
    break;

  case 92: // ENG_Num_Stem: t_ENG_Num_Stem
#line 906 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Stem",word);

}
#line 2851 "build/hi_desktop/hi.y.cpp"
    break;

  case 93: // ENG_Num_lfea_Ord: t_ENG_Num_Ord
#line 915 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Ord);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_lfea_Ord",word);

}
#line 2863 "build/hi_desktop/hi.y.cpp"
    break;

  case 94: // ENG_PNVPbar: ENG_VNEG ENG_PVPbar
#line 924 "build/hi_desktop/hi.y"
{
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PNVPbar->ENG_VNEG ENG_PVPbar");
yylhs.value=sparser->combine_nodes("ENG_PNVPbar",ENG_VNEG,ENG_PVPbar);

}
#line 2875 "build/hi_desktop/hi.y.cpp"
    break;

  case 95: // ENG_PP: ENG_Prep ENG_NP
#line 933 "build/hi_desktop/hi.y"
{
const node_info& ENG_Prep=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);

}
#line 2887 "build/hi_desktop/hi.y.cpp"
    break;

  case 96: // ENG_PVP: ENG_PNVPbar
#line 942 "build/hi_desktop/hi.y"
{
const node_info& ENG_PNVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVP->ENG_PNVPbar");
yylhs.value=sparser->set_node_info("ENG_PVP",ENG_PNVPbar);

}
#line 2898 "build/hi_desktop/hi.y.cpp"
    break;

  case 97: // ENG_PVP: ENG_PVPbar
#line 949 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVP->ENG_PVPbar");
yylhs.value=sparser->set_node_info("ENG_PVP",ENG_PVPbar);

}
#line 2909 "build/hi_desktop/hi.y.cpp"
    break;

  case 98: // ENG_PVPConj: ENG_PVPConj ENG_ConjPVP
#line 957 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPConj ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPConj,ENG_ConjPVP);

}
#line 2921 "build/hi_desktop/hi.y.cpp"
    break;

  case 99: // ENG_PVPConj: ENG_PVPhead ENG_ConjPVP
#line 965 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPhead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPhead ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPhead,ENG_ConjPVP);

}
#line 2933 "build/hi_desktop/hi.y.cpp"
    break;

  case 100: // ENG_PVPConj: ENG_PVPlisthead ENG_ConjPVP
#line 973 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPlisthead ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPlisthead,ENG_ConjPVP);

}
#line 2945 "build/hi_desktop/hi.y.cpp"
    break;

  case 101: // ENG_PVPbar: ENG_V_Ger ENG_NP
#line 982 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPbar->ENG_V_Ger ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_PVPbar",ENG_V_Ger,ENG_NP);
}
#line 2956 "build/hi_desktop/hi.y.cpp"
    break;

  case 102: // ENG_PVPbar: ENG_V_Ger ENG_PP
#line 989 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPbar->ENG_V_Ger ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_PVPbar",ENG_V_Ger,ENG_PP);
}
#line 2967 "build/hi_desktop/hi.y.cpp"
    break;

  case 103: // ENG_PVPhead: ENG_PVP
#line 997 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPhead->ENG_PVP");
yylhs.value=sparser->set_node_info("ENG_PVPhead",ENG_PVP);

}
#line 2978 "build/hi_desktop/hi.y.cpp"
    break;

  case 104: // ENG_PVPlist: ENG_PVP ENG_PVP
#line 1005 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVP1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlist->ENG_PVP ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_PVPlist",ENG_PVP1,ENG_PVP2);

}
#line 2990 "build/hi_desktop/hi.y.cpp"
    break;

  case 105: // ENG_PVPlist: ENG_PVPlist ENG_PVP
#line 1013 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlist->ENG_PVPlist ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_PVPlist",ENG_PVPlist,ENG_PVP);

}
#line 3002 "build/hi_desktop/hi.y.cpp"
    break;

  case 106: // ENG_PVPlisthead: ENG_PVPlist
#line 1022 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlisthead->ENG_PVPlist");
yylhs.value=sparser->set_node_info("ENG_PVPlisthead",ENG_PVPlist);

}
#line 3013 "build/hi_desktop/hi.y.cpp"
    break;

  case 107: // ENG_Prep: t_ENG_PREP_Stem
#line 1030 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PREP_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Prep",word);

}
#line 3025 "build/hi_desktop/hi.y.cpp"
    break;

  case 108: // ENG_QPro: t_ENG_QPRO_Stem
#line 1039 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_QPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_QPro",word);

}
#line 3037 "build/hi_desktop/hi.y.cpp"
    break;

  case 109: // ENG_RC: ENG_RPro ENG_IVP
#line 1048 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);

}
#line 3049 "build/hi_desktop/hi.y.cpp"
    break;

  case 110: // ENG_RC: ENG_RPro ENG_IVPConj
#line 1056 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVPConj");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVPConj);

}
#line 3061 "build/hi_desktop/hi.y.cpp"
    break;

  case 111: // ENG_RC: ENG_RPro ENG_IVPlist
#line 1064 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVPlist");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVPlist);

}
#line 3073 "build/hi_desktop/hi.y.cpp"
    break;

  case 112: // ENG_RPro: ENG_RPro_stem ENG_RPro_lfea_relative
#line 1073 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RPro_lfea_relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative");
yylhs.value=sparser->combine_nodes("ENG_RPro",ENG_RPro_stem,ENG_RPro_lfea_relative);

}
#line 3085 "build/hi_desktop/hi.y.cpp"
    break;

  case 113: // ENG_RPro_lfea_relative: t_ENG_RPRO_Relative
#line 1082 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_RPro_lfea_relative",word);

}
#line 3097 "build/hi_desktop/hi.y.cpp"
    break;

  case 114: // ENG_RPro_stem: t_ENG_RPRO_Stem
#line 1091 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_RPro_stem",word);

}
#line 3109 "build/hi_desktop/hi.y.cpp"
    break;

  case 115: // ENG_TP: ENG_Tense_particle ENG_V_Stem
#line 1100 "build/hi_desktop/hi.y"
{
const node_info& ENG_Tense_particle=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_Tense_particle ENG_V_Stem");
yylhs.value=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_Stem);

}
#line 3121 "build/hi_desktop/hi.y.cpp"
    break;

  case 116: // ENG_TP: ENG_V_Ger
#line 1108 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_V_Ger");
yylhs.value=sparser->set_node_info("ENG_TP",ENG_V_Ger);

}
#line 3132 "build/hi_desktop/hi.y.cpp"
    break;

  case 117: // ENG_Tense_particle: t_ENG_PAR_Stem
#line 1116 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PAR_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Tense_particle",word);

}
#line 3144 "build/hi_desktop/hi.y.cpp"
    break;

  case 118: // ENG_V: ENG_V_Aux
#line 1125 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Aux=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Aux");
yylhs.value=sparser->set_node_info("ENG_V",ENG_V_Aux);

}
#line 3155 "build/hi_desktop/hi.y.cpp"
    break;

  case 119: // ENG_V: ENG_V_Stem
#line 1132 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");
yylhs.value=sparser->set_node_info("ENG_V",ENG_V_Stem);

}
#line 3166 "build/hi_desktop/hi.y.cpp"
    break;

  case 120: // ENG_VNEG: ENG_VNEG_Stem
#line 1140 "build/hi_desktop/hi.y"
{
const node_info& ENG_VNEG_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VNEG->ENG_VNEG_Stem");
yylhs.value=sparser->set_node_info("ENG_VNEG",ENG_VNEG_Stem);

}
#line 3177 "build/hi_desktop/hi.y.cpp"
    break;

  case 121: // ENG_VNEG_Stem: t_ENG_VNEG_Stem
#line 1148 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_VNEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_VNEG_Stem",word);

}
#line 3189 "build/hi_desktop/hi.y.cpp"
    break;

  case 122: // ENG_VP: ENG_Vbar1
#line 1157 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1");
yylhs.value=sparser->set_node_info("ENG_VP",ENG_Vbar1);

}
#line 3200 "build/hi_desktop/hi.y.cpp"
    break;

  case 123: // ENG_VP: ENG_Vbar1 ENG_AdvP
#line 1164 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AdvP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);

}
#line 3212 "build/hi_desktop/hi.y.cpp"
    break;

  case 124: // ENG_VP: ENG_Vbar1 ENG_PVP
#line 1172 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVP);

}
#line 3224 "build/hi_desktop/hi.y.cpp"
    break;

  case 125: // ENG_VP: ENG_Vbar1 ENG_PVPConj
#line 1180 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVPConj");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVPConj);

}
#line 3236 "build/hi_desktop/hi.y.cpp"
    break;

  case 126: // ENG_VP: ENG_Vbar1 ENG_PVPlist
#line 1188 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVPlist");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVPlist);

}
#line 3248 "build/hi_desktop/hi.y.cpp"
    break;

  case 127: // ENG_VP: ENG_Vbar1 ENG_RC
#line 1196 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_RC");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);

}
#line 3260 "build/hi_desktop/hi.y.cpp"
    break;

  case 128: // ENG_VP: ENG_Vbar2
#line 1204 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2");
yylhs.value=sparser->set_node_info("ENG_VP",ENG_Vbar2);

}
#line 3271 "build/hi_desktop/hi.y.cpp"
    break;

  case 129: // ENG_VP: ENG_Vbar2 ENG_PP
#line 1211 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);

}
#line 3283 "build/hi_desktop/hi.y.cpp"
    break;

  case 130: // ENG_VP: ENG_Vbar2 ENG_RC
#line 1219 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_RC");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);

}
#line 3295 "build/hi_desktop/hi.y.cpp"
    break;

  case 131: // ENG_VP: ENG_Vbar3 ENG_NP
#line 1227 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar3=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar3 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);

}
#line 3307 "build/hi_desktop/hi.y.cpp"
    break;

  case 132: // ENG_VP: ENG_Vbar4 ENG_DP
#line 1235 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar4=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar4 ENG_DP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);

}
#line 3319 "build/hi_desktop/hi.y.cpp"
    break;

  case 133: // ENG_V_Aux: ENG_V_Stem ENG_V_lfea_aux
#line 1244 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_aux=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Aux->ENG_V_Stem ENG_V_lfea_aux");
yylhs.value=sparser->combine_nodes("ENG_V_Aux",ENG_V_Stem,ENG_V_lfea_aux);

}
#line 3331 "build/hi_desktop/hi.y.cpp"
    break;

  case 134: // ENG_V_Ger: ENG_V_Stem ENG_V_lfea_ger
#line 1253 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_ger=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Ger->ENG_V_Stem ENG_V_lfea_ger");
yylhs.value=sparser->combine_nodes("ENG_V_Ger",ENG_V_Stem,ENG_V_lfea_ger);

}
#line 3343 "build/hi_desktop/hi.y.cpp"
    break;

  case 135: // ENG_V_Stem: t_ENG_V_Stem
#line 1262 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_Stem",word);

}
#line 3355 "build/hi_desktop/hi.y.cpp"
    break;

  case 136: // ENG_V_lfea_aux: t_ENG_V_Aux
#line 1271 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Aux);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_aux",word);

}
#line 3367 "build/hi_desktop/hi.y.cpp"
    break;

  case 137: // ENG_V_lfea_ger: t_ENG_V_Gerund
#line 1280 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Gerund);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_ger",word);

}
#line 3379 "build/hi_desktop/hi.y.cpp"
    break;

  case 138: // ENG_Vbar1: ENG_V ENG_NP
#line 1289 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
}
#line 3391 "build/hi_desktop/hi.y.cpp"
    break;

  case 139: // ENG_Vbar2: ENG_Vbar1 ENG_NP
#line 1298 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);

}
#line 3403 "build/hi_desktop/hi.y.cpp"
    break;

  case 140: // ENG_Vbar2: ENG_Vbar1 ENG_PP
#line 1306 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_PP);

}
#line 3415 "build/hi_desktop/hi.y.cpp"
    break;

  case 141: // ENG_Vbar3: ENG_V ENG_AdvP
#line 1315 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AdvP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar3->ENG_V ENG_AdvP");
yylhs.value=sparser->combine_nodes("ENG_Vbar3",ENG_V,ENG_AdvP);

}
#line 3427 "build/hi_desktop/hi.y.cpp"
    break;

  case 142: // ENG_Vbar4: ENG_DP ENG_V
#line 1324 "build/hi_desktop/hi.y"
{
const node_info& ENG_DP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
}
#line 3439 "build/hi_desktop/hi.y.cpp"
    break;

  case 143: // ENG_Vbar4: ENG_TP ENG_V
#line 1332 "build/hi_desktop/hi.y"
{
const node_info& ENG_TP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
}
#line 3451 "build/hi_desktop/hi.y.cpp"
    break;

  case 144: // ENG_Vbar4: ENG_V
#line 1340 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_V");
yylhs.value=sparser->set_node_info("ENG_Vbar4",ENG_V);
}
#line 3462 "build/hi_desktop/hi.y.cpp"
    break;

  case 145: // ENG_Vhead: ENG_IVP
#line 1348 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vhead->ENG_IVP");
yylhs.value=sparser->set_node_info("ENG_Vhead",ENG_IVP);

}
#line 3473 "build/hi_desktop/hi.y.cpp"
    break;

  case 146: // ENG_Vlisthead: ENG_IVPlist
#line 1356 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vlisthead->ENG_IVPlist");
yylhs.value=sparser->set_node_info("ENG_Vlisthead",ENG_IVPlist);

}
#line 3484 "build/hi_desktop/hi.y.cpp"
    break;

  case 147: // ENG_lfea_DefDet: t_ENG_DET_Def
#line 1364 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Def);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_DefDet",word);

}
#line 3496 "build/hi_desktop/hi.y.cpp"
    break;

  case 148: // ENG_lfea_IndefDet: t_ENG_DET_Indef
#line 1373 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Indef);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_IndefDet",word);

}
#line 3508 "build/hi_desktop/hi.y.cpp"
    break;

  case 149: // ENG_lfea_fwConsonant: t_ENG_DET_fwConsonant
#line 1382 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_fwConsonant",word);

}
#line 3520 "build/hi_desktop/hi.y.cpp"
    break;

  case 150: // ENG_lfea_fwVowel: t_ENG_DET_fwVowel
#line 1391 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_fwVowel",word);

}
#line 3532 "build/hi_desktop/hi.y.cpp"
    break;

  case 151: // ENG_lfea_swConsonant: t_ENG_N_swConsonant
#line 1400 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_swConsonant",word);

}
#line 3544 "build/hi_desktop/hi.y.cpp"
    break;

  case 152: // ENG_lfea_swVowel: t_ENG_N_swVowel
#line 1409 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_swVowel",word);

}
#line 3556 "build/hi_desktop/hi.y.cpp"
    break;

  case 153: // ENG_nCon: ENG_1Con ENG_Con
#line 1418 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_1Con ENG_Con");
yylhs.value=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);

}
#line 3568 "build/hi_desktop/hi.y.cpp"
    break;

  case 154: // ENG_nCon: ENG_nCon ENG_Con
#line 1426 "build/hi_desktop/hi.y"
{
const node_info& ENG_nCon=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_nCon ENG_Con");
yylhs.value=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);

}
#line 3580 "build/hi_desktop/hi.y.cpp"
    break;

  case 155: // HUN_1Con: HUN_Con
#line 1435 "build/hi_desktop/hi.y"
{
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_1Con->HUN_Con");
yylhs.value=sparser->set_node_info("HUN_1Con",HUN_Con);

}
#line 3591 "build/hi_desktop/hi.y.cpp"
    break;

  case 156: // HUN_A0NEG: HUN_Adj
#line 1443 "build/hi_desktop/hi.y"
{
const node_info& HUN_Adj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_A0NEG->HUN_Adj");
yylhs.value=sparser->set_node_info("HUN_A0NEG",HUN_Adj);

}
#line 3602 "build/hi_desktop/hi.y.cpp"
    break;

  case 157: // HUN_ANEG: HUN_Neg HUN_Adj
#line 1451 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Adj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ANEG->HUN_Neg HUN_Adj");
yylhs.value=sparser->combine_nodes("HUN_ANEG",HUN_Neg,HUN_Adj);

}
#line 3614 "build/hi_desktop/hi.y.cpp"
    break;

  case 158: // HUN_ANP: HUN_N_Sg HUN_N_Sg
#line 1460 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ANP->HUN_N_Sg HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_ANP",HUN_N_Sg1,HUN_N_Sg2);

}
#line 3626 "build/hi_desktop/hi.y.cpp"
    break;

  case 159: // HUN_AN_Acc: HUN_N_Acc END
#line 1469 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AN_Acc->HUN_N_Acc END");
yylhs.value=sparser->set_node_info("HUN_AN_Acc",HUN_N_Acc);
}
#line 3636 "build/hi_desktop/hi.y.cpp"
    break;

  case 160: // HUN_AP: HUN_Abar3 HUN_N_Acc
#line 1476 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Abar3 HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Abar3,HUN_N_Acc);

}
#line 3648 "build/hi_desktop/hi.y.cpp"
    break;

  case 161: // HUN_AP: HUN_Abar4 HUN_ConjA_End
#line 1484 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjA_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Abar4 HUN_ConjA_End");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Abar4,HUN_ConjA_End);

}
#line 3660 "build/hi_desktop/hi.y.cpp"
    break;

  case 162: // HUN_AP: HUN_Alist HUN_N_Acc
#line 1492 "build/hi_desktop/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Alist HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Alist,HUN_N_Acc);

}
#line 3672 "build/hi_desktop/hi.y.cpp"
    break;

  case 163: // HUN_Abar1: HUN_N_Acc HUN_A0NEG
#line 1501 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Acc HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Acc,HUN_A0NEG);

}
#line 3684 "build/hi_desktop/hi.y.cpp"
    break;

  case 164: // HUN_Abar1: HUN_N_Ins HUN_A0NEG
#line 1509 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Ins HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Ins,HUN_A0NEG);

}
#line 3696 "build/hi_desktop/hi.y.cpp"
    break;

  case 165: // HUN_Abar1: HUN_N_Sub HUN_A0NEG
#line 1517 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Sub HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Sub,HUN_A0NEG);

}
#line 3708 "build/hi_desktop/hi.y.cpp"
    break;

  case 166: // HUN_Abar1N: HUN_N_Acc HUN_ANEG
#line 1526 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Acc HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Acc,HUN_ANEG);

}
#line 3720 "build/hi_desktop/hi.y.cpp"
    break;

  case 167: // HUN_Abar1N: HUN_N_Ins HUN_ANEG
#line 1534 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Ins HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Ins,HUN_ANEG);

}
#line 3732 "build/hi_desktop/hi.y.cpp"
    break;

  case 168: // HUN_Abar1N: HUN_N_Sub HUN_ANEG
#line 1542 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Sub HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Sub,HUN_ANEG);

}
#line 3744 "build/hi_desktop/hi.y.cpp"
    break;

  case 169: // HUN_Abar2: HUN_Abar1
#line 1551 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2->HUN_Abar1");
yylhs.value=sparser->set_node_info("HUN_Abar2",HUN_Abar1);

}
#line 3755 "build/hi_desktop/hi.y.cpp"
    break;

  case 170: // HUN_Abar2N: HUN_Abar1N
#line 1559 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar1N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2N->HUN_Abar1N");
yylhs.value=sparser->set_node_info("HUN_Abar2N",HUN_Abar1N);

}
#line 3766 "build/hi_desktop/hi.y.cpp"
    break;

  case 171: // HUN_Abar2N: HUN_NAbar1
#line 1566 "build/hi_desktop/hi.y"
{
const node_info& HUN_NAbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2N->HUN_NAbar1");
yylhs.value=sparser->set_node_info("HUN_Abar2N",HUN_NAbar1);

}
#line 3777 "build/hi_desktop/hi.y.cpp"
    break;

  case 172: // HUN_Abar3: HUN_Abar2
#line 1574 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3->HUN_Abar2");
yylhs.value=sparser->set_node_info("HUN_Abar3",HUN_Abar2);

}
#line 3788 "build/hi_desktop/hi.y.cpp"
    break;

  case 173: // HUN_Abar3: HUN_Abar2N
#line 1581 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar2N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3->HUN_Abar2N");
yylhs.value=sparser->set_node_info("HUN_Abar3",HUN_Abar2N);

}
#line 3799 "build/hi_desktop/hi.y.cpp"
    break;

  case 174: // HUN_Abar3_End: HUN_Abar3 HUN_AN_Acc
#line 1589 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3_End->HUN_Abar3 HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_Abar3_End",HUN_Abar3,HUN_AN_Acc);

}
#line 3811 "build/hi_desktop/hi.y.cpp"
    break;

  case 175: // HUN_Abar4: HUN_A0NEG
#line 1598 "build/hi_desktop/hi.y"
{
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_A0NEG");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_A0NEG);

}
#line 3822 "build/hi_desktop/hi.y.cpp"
    break;

  case 176: // HUN_Abar4: HUN_ANEG
#line 1605 "build/hi_desktop/hi.y"
{
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_ANEG");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_ANEG);

}
#line 3833 "build/hi_desktop/hi.y.cpp"
    break;

  case 177: // HUN_Abar4: HUN_Abar3
#line 1612 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar3");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_Abar3);

}
#line 3844 "build/hi_desktop/hi.y.cpp"
    break;

  case 178: // HUN_Abar4: HUN_Abar4 HUN_ConjA
#line 1619 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar4 HUN_ConjA");
yylhs.value=sparser->combine_nodes("HUN_Abar4",HUN_Abar4,HUN_ConjA);

}
#line 3856 "build/hi_desktop/hi.y.cpp"
    break;

  case 179: // HUN_Abar4: HUN_Abar4 HUN_ConjAlist
#line 1627 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjAlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar4 HUN_ConjAlist");
yylhs.value=sparser->combine_nodes("HUN_Abar4",HUN_Abar4,HUN_ConjAlist);

}
#line 3868 "build/hi_desktop/hi.y.cpp"
    break;

  case 180: // HUN_Abar4: HUN_Alist
#line 1635 "build/hi_desktop/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Alist");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_Alist);

}
#line 3879 "build/hi_desktop/hi.y.cpp"
    break;

  case 181: // HUN_Adj: HUN_Adj_Stem
#line 1643 "build/hi_desktop/hi.y"
{
const node_info& HUN_Adj_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Adj->HUN_Adj_Stem");
yylhs.value=sparser->set_node_info("HUN_Adj",HUN_Adj_Stem);

}
#line 3890 "build/hi_desktop/hi.y.cpp"
    break;

  case 182: // HUN_Adj_Stem: t_HUN_Adj_Stem
#line 1651 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Adj_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Adj_Stem",word);

}
#line 3902 "build/hi_desktop/hi.y.cpp"
    break;

  case 183: // HUN_Alist: HUN_Abar3 HUN_Abar3
#line 1660 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar31=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar32=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist->HUN_Abar3 HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_Alist",HUN_Abar31,HUN_Abar32);

}
#line 3914 "build/hi_desktop/hi.y.cpp"
    break;

  case 184: // HUN_Alist: HUN_Alist HUN_Abar3
#line 1668 "build/hi_desktop/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist->HUN_Alist HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_Alist",HUN_Alist,HUN_Abar3);

}
#line 3926 "build/hi_desktop/hi.y.cpp"
    break;

  case 185: // HUN_Alist_End: HUN_Alist HUN_AN_Acc
#line 1677 "build/hi_desktop/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist_End->HUN_Alist HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_Alist_End",HUN_Alist,HUN_AN_Acc);

}
#line 3938 "build/hi_desktop/hi.y.cpp"
    break;

  case 186: // HUN_Con: HUN_lfea_swConsonant HUN_Con
#line 1686 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Con->HUN_lfea_swConsonant HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_Con",HUN_lfea_swConsonant,HUN_Con);

}
#line 3950 "build/hi_desktop/hi.y.cpp"
    break;

  case 187: // HUN_Con: HUN_lfea_swVowel HUN_Con
#line 1694 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Con->HUN_lfea_swVowel HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_Con",HUN_lfea_swVowel,HUN_Con);

}
#line 3962 "build/hi_desktop/hi.y.cpp"
    break;

  case 188: // HUN_Con: t_HUN_CON_Stem
#line 1702 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con",word);

}
#line 3974 "build/hi_desktop/hi.y.cpp"
    break;

  case 189: // HUN_Con_lfea_Acc: t_HUN_CON_Acc
#line 1711 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Acc",word);

}
#line 3986 "build/hi_desktop/hi.y.cpp"
    break;

  case 190: // HUN_Con_lfea_Dat: t_HUN_CON_Dat
#line 1720 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Dat",word);

}
#line 3998 "build/hi_desktop/hi.y.cpp"
    break;

  case 191: // HUN_Con_lfea_Ins: t_HUN_CON_Ins
#line 1729 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Ins);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Ins",word);

}
#line 4010 "build/hi_desktop/hi.y.cpp"
    break;

  case 192: // HUN_Con_lfea_Sub: t_HUN_CON_Sub
#line 1738 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Sub);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Sub",word);

}
#line 4022 "build/hi_desktop/hi.y.cpp"
    break;

  case 193: // HUN_Conj: HUN_Conj_Stem
#line 1747 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Conj->HUN_Conj_Stem");
yylhs.value=sparser->set_node_info("HUN_Conj",HUN_Conj_Stem);

}
#line 4033 "build/hi_desktop/hi.y.cpp"
    break;

  case 194: // HUN_ConjA: HUN_Conj HUN_A0NEG
#line 1755 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_A0NEG);

}
#line 4045 "build/hi_desktop/hi.y.cpp"
    break;

  case 195: // HUN_ConjA: HUN_Conj HUN_ANEG
#line 1763 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_ANEG);

}
#line 4057 "build/hi_desktop/hi.y.cpp"
    break;

  case 196: // HUN_ConjA: HUN_Conj HUN_Abar3
#line 1771 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_Abar3);

}
#line 4069 "build/hi_desktop/hi.y.cpp"
    break;

  case 197: // HUN_ConjA: HUN_Conj HUN_Alist
#line 1779 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_Alist");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_Alist);

}
#line 4081 "build/hi_desktop/hi.y.cpp"
    break;

  case 198: // HUN_ConjA_End: HUN_ConjA HUN_AN_Acc
#line 1788 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_AN_Acc);

}
#line 4093 "build/hi_desktop/hi.y.cpp"
    break;

  case 199: // HUN_ConjA_End: HUN_ConjA HUN_Abar3_End
#line 1796 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_Abar3_End");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_Abar3_End);

}
#line 4105 "build/hi_desktop/hi.y.cpp"
    break;

  case 200: // HUN_ConjA_End: HUN_ConjA HUN_Alist_End
#line 1804 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_Alist_End");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_Alist_End);

}
#line 4117 "build/hi_desktop/hi.y.cpp"
    break;

  case 201: // HUN_ConjAlist: HUN_ConjA HUN_Abar3
#line 1813 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjAlist->HUN_ConjA HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_ConjAlist",HUN_ConjA,HUN_Abar3);

}
#line 4129 "build/hi_desktop/hi.y.cpp"
    break;

  case 202: // HUN_ConjAlist: HUN_ConjA HUN_Alist
#line 1821 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjAlist->HUN_ConjA HUN_Alist");
yylhs.value=sparser->combine_nodes("HUN_ConjAlist",HUN_ConjA,HUN_Alist);

}
#line 4141 "build/hi_desktop/hi.y.cpp"
    break;

  case 203: // HUN_ConjN: HUN_N_Sg HUN_ConjNbar1
#line 1830 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjNbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjN->HUN_N_Sg HUN_ConjNbar1");
yylhs.value=sparser->combine_nodes("HUN_ConjN",HUN_N_Sg,HUN_ConjNbar1);

}
#line 4153 "build/hi_desktop/hi.y.cpp"
    break;

  case 204: // HUN_ConjNbar1: HUN_Conj HUN_N_Sg
#line 1839 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjNbar1->HUN_Conj HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_ConjNbar1",HUN_Conj,HUN_N_Sg);

}
#line 4165 "build/hi_desktop/hi.y.cpp"
    break;

  case 205: // HUN_ConjV: HUN_Conj HUN_INVP
#line 1848 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_INVP);

}
#line 4177 "build/hi_desktop/hi.y.cpp"
    break;

  case 206: // HUN_ConjV: HUN_Conj HUN_IVP
#line 1856 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_IVP);

}
#line 4189 "build/hi_desktop/hi.y.cpp"
    break;

  case 207: // HUN_ConjV: HUN_Conj HUN_IVPlist
#line 1864 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_IVPlist");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_IVPlist);

}
#line 4201 "build/hi_desktop/hi.y.cpp"
    break;

  case 208: // HUN_Conj_Stem: t_HUN_Conj_Stem
#line 1873 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Conj_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Conj_Stem",word);

}
#line 4213 "build/hi_desktop/hi.y.cpp"
    break;

  case 209: // HUN_DP: HUN_DPbar HUN_N_Acc
#line 1882 "build/hi_desktop/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Acc);

}
#line 4225 "build/hi_desktop/hi.y.cpp"
    break;

  case 210: // HUN_DP: HUN_DPbar HUN_N_Dat
#line 1890 "build/hi_desktop/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Dat);

}
#line 4237 "build/hi_desktop/hi.y.cpp"
    break;

  case 211: // HUN_DP: HUN_DPbar HUN_N_Ine
#line 1898 "build/hi_desktop/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Ine");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Ine);

}
#line 4249 "build/hi_desktop/hi.y.cpp"
    break;

  case 212: // HUN_DPbar: HUN_Def_Det_a HUN_lfea_swConsonant
#line 1907 "build/hi_desktop/hi.y"
{
const node_info& HUN_Def_Det_a=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_a HUN_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_a,HUN_lfea_swConsonant);

}
#line 4261 "build/hi_desktop/hi.y.cpp"
    break;

  case 213: // HUN_DPbar: HUN_Def_Det_az HUN_lfea_swVowel
#line 1915 "build/hi_desktop/hi.y"
{
const node_info& HUN_Def_Det_az=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_az HUN_lfea_swVowel");
yylhs.value=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_az,HUN_lfea_swVowel);

}
#line 4273 "build/hi_desktop/hi.y.cpp"
    break;

  case 214: // HUN_Def_Det: HUN_Det_stem HUN_lfea_DefDet
#line 1924 "build/hi_desktop/hi.y"
{
const node_info& HUN_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_DefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det->HUN_Det_stem HUN_lfea_DefDet");
yylhs.value=sparser->combine_nodes("HUN_Def_Det",HUN_Det_stem,HUN_lfea_DefDet);

}
#line 4285 "build/hi_desktop/hi.y.cpp"
    break;

  case 215: // HUN_Def_Det_a: HUN_Def_Det HUN_lfea_fwConsonant
#line 1933 "build/hi_desktop/hi.y"
{
const node_info& HUN_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_fwConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det_a->HUN_Def_Det HUN_lfea_fwConsonant");
yylhs.value=sparser->combine_nodes("HUN_Def_Det_a",HUN_Def_Det,HUN_lfea_fwConsonant);

}
#line 4297 "build/hi_desktop/hi.y.cpp"
    break;

  case 216: // HUN_Def_Det_az: HUN_Def_Det HUN_lfea_fwVowel
#line 1942 "build/hi_desktop/hi.y"
{
const node_info& HUN_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_fwVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det_az->HUN_Def_Det HUN_lfea_fwVowel");
yylhs.value=sparser->combine_nodes("HUN_Def_Det_az",HUN_Def_Det,HUN_lfea_fwVowel);

}
#line 4309 "build/hi_desktop/hi.y.cpp"
    break;

  case 217: // HUN_Det_stem: t_HUN_Det_Stem
#line 1951 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Det_stem",word);

}
#line 4321 "build/hi_desktop/hi.y.cpp"
    break;

  case 218: // HUN_Empty: %empty
#line 1960 "build/hi_desktop/hi.y"
{
lexicon empty;
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Empty->%empty");
yylhs.value=sparser->set_node_info("HUN_Empty",empty);
}
#line 4331 "build/hi_desktop/hi.y.cpp"
    break;

  case 219: // HUN_INVP: HUN_NP HUN_INVPbar2
#line 1967 "build/hi_desktop/hi.y"
{
const node_info& HUN_NP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVPbar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_NP HUN_INVPbar2");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_NP,HUN_INVPbar2);

}
#line 4343 "build/hi_desktop/hi.y.cpp"
    break;

  case 220: // HUN_INVP: HUN_Neg HUN_INVPbar
#line 1975 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_Neg HUN_INVPbar");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_Neg,HUN_INVPbar);

}
#line 4355 "build/hi_desktop/hi.y.cpp"
    break;

  case 221: // HUN_INVP: HUN_Neg HUN_IVPbar
#line 1983 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_Neg HUN_IVPbar");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_Neg,HUN_IVPbar);

}
#line 4367 "build/hi_desktop/hi.y.cpp"
    break;

  case 222: // HUN_INVPbar: HUN_V HUN_N_Ins
#line 1992 "build/hi_desktop/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar->HUN_V HUN_N_Ins");
yylhs.value=sparser->combine_nodes("HUN_INVPbar",HUN_V,HUN_N_Ins);
}
#line 4379 "build/hi_desktop/hi.y.cpp"
    break;

  case 223: // HUN_INVPbar: HUN_V HUN_N_Sub
#line 2000 "build/hi_desktop/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar->HUN_V HUN_N_Sub");
yylhs.value=sparser->combine_nodes("HUN_INVPbar",HUN_V,HUN_N_Sub);
}
#line 4391 "build/hi_desktop/hi.y.cpp"
    break;

  case 224: // HUN_INVPbar2: HUN_Neg HUN_V
#line 2009 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar2->HUN_Neg HUN_V");
yylhs.value=sparser->combine_nodes("HUN_INVPbar2",HUN_Neg,HUN_V);
}
#line 4403 "build/hi_desktop/hi.y.cpp"
    break;

  case 225: // HUN_IVP: HUN_IVPbar
#line 2018 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVP->HUN_IVPbar");
yylhs.value=sparser->set_node_info("HUN_IVP",HUN_IVPbar);

}
#line 4414 "build/hi_desktop/hi.y.cpp"
    break;

  case 226: // HUN_IVPConj: HUN_IVPConj HUN_ConjV
#line 2026 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_IVPConj HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_IVPConj,HUN_ConjV);

}
#line 4426 "build/hi_desktop/hi.y.cpp"
    break;

  case 227: // HUN_IVPConj: HUN_Vhead HUN_ConjV
#line 2034 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vhead=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_Vhead HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_Vhead,HUN_ConjV);

}
#line 4438 "build/hi_desktop/hi.y.cpp"
    break;

  case 228: // HUN_IVPConj: HUN_Vlisthead HUN_ConjV
#line 2042 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_Vlisthead HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_Vlisthead,HUN_ConjV);

}
#line 4450 "build/hi_desktop/hi.y.cpp"
    break;

  case 229: // HUN_IVPbar: HUN_N_Acc HUN_V
#line 2051 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Acc HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_V,HUN_N_Acc);
}
#line 4462 "build/hi_desktop/hi.y.cpp"
    break;

  case 230: // HUN_IVPbar: HUN_N_Ins HUN_V
#line 2059 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Ins HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_N_Ins,HUN_V);
}
#line 4474 "build/hi_desktop/hi.y.cpp"
    break;

  case 231: // HUN_IVPbar: HUN_N_Sub HUN_V
#line 2067 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Sub HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_N_Sub,HUN_V);
}
#line 4486 "build/hi_desktop/hi.y.cpp"
    break;

  case 232: // HUN_IVPbar: HUN_V HUN_N_Acc
#line 2075 "build/hi_desktop/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_V HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_V,HUN_N_Acc);
}
#line 4498 "build/hi_desktop/hi.y.cpp"
    break;

  case 233: // HUN_IVPlist: HUN_INVP HUN_INVP
#line 2084 "build/hi_desktop/hi.y"
{
const node_info& HUN_INVP1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_INVP HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_INVP1,HUN_INVP2);

}
#line 4510 "build/hi_desktop/hi.y.cpp"
    break;

  case 234: // HUN_IVPlist: HUN_INVP HUN_IVP
#line 2092 "build/hi_desktop/hi.y"
{
const node_info& HUN_INVP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_INVP HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_INVP,HUN_IVP);

}
#line 4522 "build/hi_desktop/hi.y.cpp"
    break;

  case 235: // HUN_IVPlist: HUN_IVP HUN_INVP
#line 2100 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVP HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVP,HUN_INVP);

}
#line 4534 "build/hi_desktop/hi.y.cpp"
    break;

  case 236: // HUN_IVPlist: HUN_IVP HUN_IVP
#line 2108 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVP1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVP HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVP1,HUN_IVP2);

}
#line 4546 "build/hi_desktop/hi.y.cpp"
    break;

  case 237: // HUN_IVPlist: HUN_IVPlist HUN_INVP
#line 2116 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVPlist HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVPlist,HUN_INVP);

}
#line 4558 "build/hi_desktop/hi.y.cpp"
    break;

  case 238: // HUN_IVPlist: HUN_IVPlist HUN_IVP
#line 2124 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVPlist HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVPlist,HUN_IVP);

}
#line 4570 "build/hi_desktop/hi.y.cpp"
    break;

  case 239: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2
#line 2133 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);
}
#line 4582 "build/hi_desktop/hi.y.cpp"
    break;

  case 240: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_ConjIndefSg2
#line 2141 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_ConjIndefSg2=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjIndefSg2");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjIndefSg2);
}
#line 4594 "build/hi_desktop/hi.y.cpp"
    break;

  case 241: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_DefSg1
#line 2149 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_DefSg1=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_DefSg1");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_DefSg1);
}
#line 4606 "build/hi_desktop/hi.y.cpp"
    break;

  case 242: // HUN_ImpVerbPfx: HUN_ImpVerb HUN_Vbpfx
#line 2158 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Vbpfx=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerbPfx->HUN_ImpVerb HUN_Vbpfx");
yylhs.value=sparser->combine_nodes("HUN_ImpVerbPfx",HUN_ImpVerb,HUN_Vbpfx);

}
#line 4618 "build/hi_desktop/hi.y.cpp"
    break;

  case 243: // HUN_ImpVerb_N_Acc: HUN_ImpVerb HUN_N_Acc
#line 2167 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb_N_Acc->HUN_ImpVerb HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb_N_Acc",HUN_ImpVerb,HUN_N_Acc);

}
#line 4630 "build/hi_desktop/hi.y.cpp"
    break;

  case 244: // HUN_ImpVerb_N_Dat: HUN_ImpVerb HUN_N_Dat
#line 2176 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb_N_Dat->HUN_ImpVerb HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb_N_Dat",HUN_ImpVerb,HUN_N_Dat);

}
#line 4642 "build/hi_desktop/hi.y.cpp"
    break;

  case 245: // HUN_IndVerb: HUN_Verb_stem HUN_Verb_lfea_InDefSg3
#line 2185 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_InDefSg3=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IndVerb->HUN_Verb_stem HUN_Verb_lfea_InDefSg3");
yylhs.value=sparser->combine_nodes("HUN_IndVerb",HUN_Verb_stem,HUN_Verb_lfea_InDefSg3);
}
#line 4654 "build/hi_desktop/hi.y.cpp"
    break;

  case 246: // HUN_NAbar1: HUN_Neg HUN_Abar1
#line 2194 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NAbar1->HUN_Neg HUN_Abar1");
yylhs.value=sparser->combine_nodes("HUN_NAbar1",HUN_Neg,HUN_Abar1);

}
#line 4666 "build/hi_desktop/hi.y.cpp"
    break;

  case 247: // HUN_NP: HUN_N_Acc
#line 2203 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Acc");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Acc);

}
#line 4677 "build/hi_desktop/hi.y.cpp"
    break;

  case 248: // HUN_NP: HUN_N_Ins
#line 2210 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Ins");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Ins);

}
#line 4688 "build/hi_desktop/hi.y.cpp"
    break;

  case 249: // HUN_NP: HUN_N_Sg
#line 2217 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Sg");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Sg);

}
#line 4699 "build/hi_desktop/hi.y.cpp"
    break;

  case 250: // HUN_NP: HUN_N_Sub
#line 2224 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Sub");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Sub);

}
#line 4710 "build/hi_desktop/hi.y.cpp"
    break;

  case 251: // HUN_N_Acc: HUN_ANP HUN_Noun_lfea_Acc
#line 2232 "build/hi_desktop/hi.y"
{
const node_info& HUN_ANP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_ANP HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_ANP,HUN_Noun_lfea_Acc);

}
#line 4722 "build/hi_desktop/hi.y.cpp"
    break;

  case 252: // HUN_N_Acc: HUN_N_Pl HUN_Noun_lfea_Acc
#line 2240 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Pl=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Pl HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Pl,HUN_Noun_lfea_Acc);

}
#line 4734 "build/hi_desktop/hi.y.cpp"
    break;

  case 253: // HUN_N_Acc: HUN_N_Sg HUN_Con_lfea_Acc
#line 2248 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Con_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Con_lfea_Acc);

}
#line 4746 "build/hi_desktop/hi.y.cpp"
    break;

  case 254: // HUN_N_Acc: HUN_N_Sg HUN_Noun_lfea_Acc
#line 2256 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Noun_lfea_Acc);

}
#line 4758 "build/hi_desktop/hi.y.cpp"
    break;

  case 255: // HUN_N_Acc: HUN_Num HUN_Num_lfea_Acc
#line 2264 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_Num HUN_Num_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_Num,HUN_Num_lfea_Acc);

}
#line 4770 "build/hi_desktop/hi.y.cpp"
    break;

  case 256: // HUN_N_Acc: HUN_Nums HUN_Num_lfea_Acc
#line 2272 "build/hi_desktop/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_Nums HUN_Num_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_Nums,HUN_Num_lfea_Acc);

}
#line 4782 "build/hi_desktop/hi.y.cpp"
    break;

  case 257: // HUN_N_Dat: HUN_N_Sg HUN_Con_lfea_Dat
#line 2281 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Con_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Con_lfea_Dat);

}
#line 4794 "build/hi_desktop/hi.y.cpp"
    break;

  case 258: // HUN_N_Dat: HUN_N_Sg HUN_Noun_lfea_Dat
#line 2289 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Noun_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Noun_lfea_Dat);

}
#line 4806 "build/hi_desktop/hi.y.cpp"
    break;

  case 259: // HUN_N_Dat: HUN_N_Sg HUN_Noun_lfea_Del
#line 2297 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Del=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Noun_lfea_Del");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Noun_lfea_Del);

}
#line 4818 "build/hi_desktop/hi.y.cpp"
    break;

  case 260: // HUN_N_Dat: HUN_Num HUN_Num_lfea_Dat
#line 2305 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Num HUN_Num_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Num,HUN_Num_lfea_Dat);

}
#line 4830 "build/hi_desktop/hi.y.cpp"
    break;

  case 261: // HUN_N_Dat: HUN_Num HUN_Num_lfea_Del
#line 2313 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Del=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Num HUN_Num_lfea_Del");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Num,HUN_Num_lfea_Del);

}
#line 4842 "build/hi_desktop/hi.y.cpp"
    break;

  case 262: // HUN_N_Dat: HUN_Nums HUN_Num_lfea_Dat
#line 2321 "build/hi_desktop/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Nums HUN_Num_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Nums,HUN_Num_lfea_Dat);

}
#line 4854 "build/hi_desktop/hi.y.cpp"
    break;

  case 263: // HUN_N_Ine: HUN_N_Pl HUN_Noun_lfea_Ine
#line 2330 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Pl=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ine->HUN_N_Pl HUN_Noun_lfea_Ine");
yylhs.value=sparser->combine_nodes("HUN_N_Ine",HUN_N_Pl,HUN_Noun_lfea_Ine);

}
#line 4866 "build/hi_desktop/hi.y.cpp"
    break;

  case 264: // HUN_N_Ine: HUN_N_Sg HUN_Noun_lfea_Ine
#line 2338 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ine->HUN_N_Sg HUN_Noun_lfea_Ine");
yylhs.value=sparser->combine_nodes("HUN_N_Ine",HUN_N_Sg,HUN_Noun_lfea_Ine);

}
#line 4878 "build/hi_desktop/hi.y.cpp"
    break;

  case 265: // HUN_N_Ins: HUN_N_Sg HUN_Con_lfea_Ins
#line 2347 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ins->HUN_N_Sg HUN_Con_lfea_Ins");
yylhs.value=sparser->combine_nodes("HUN_N_Ins",HUN_N_Sg,HUN_Con_lfea_Ins);

}
#line 4890 "build/hi_desktop/hi.y.cpp"
    break;

  case 266: // HUN_N_Pl: HUN_Noun_Stem HUN_Noun_lfea_Plur
#line 2356 "build/hi_desktop/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Plur=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Pl->HUN_Noun_Stem HUN_Noun_lfea_Plur");
yylhs.value=sparser->combine_nodes("HUN_N_Pl",HUN_Noun_Stem,HUN_Noun_lfea_Plur);

}
#line 4902 "build/hi_desktop/hi.y.cpp"
    break;

  case 267: // HUN_N_Sg: HUN_1Con
#line 2365 "build/hi_desktop/hi.y"
{
const node_info& HUN_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_1Con");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_1Con);

}
#line 4913 "build/hi_desktop/hi.y.cpp"
    break;

  case 268: // HUN_N_Sg: HUN_Noun_Pref HUN_Noun_Stem
#line 2372 "build/hi_desktop/hi.y"
{
const node_info& HUN_Noun_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_Noun_Pref HUN_Noun_Stem");
yylhs.value=sparser->combine_nodes("HUN_N_Sg",HUN_Noun_Pref,HUN_Noun_Stem);

}
#line 4925 "build/hi_desktop/hi.y.cpp"
    break;

  case 269: // HUN_N_Sg: HUN_Noun_Stem
#line 2380 "build/hi_desktop/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_Noun_Stem");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_Noun_Stem);

}
#line 4936 "build/hi_desktop/hi.y.cpp"
    break;

  case 270: // HUN_N_Sg: HUN_nCon
#line 2387 "build/hi_desktop/hi.y"
{
const node_info& HUN_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_nCon");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_nCon);

}
#line 4947 "build/hi_desktop/hi.y.cpp"
    break;

  case 271: // HUN_N_Sub: HUN_N_Sg HUN_Con_lfea_Sub
#line 2395 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Sub=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sub->HUN_N_Sg HUN_Con_lfea_Sub");
yylhs.value=sparser->combine_nodes("HUN_N_Sub",HUN_N_Sg,HUN_Con_lfea_Sub);

}
#line 4959 "build/hi_desktop/hi.y.cpp"
    break;

  case 272: // HUN_N_Sub: HUN_N_Sg HUN_Noun_lfea_Sub
#line 2403 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Sub=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sub->HUN_N_Sg HUN_Noun_lfea_Sub");
yylhs.value=sparser->combine_nodes("HUN_N_Sub",HUN_N_Sg,HUN_Noun_lfea_Sub);

}
#line 4971 "build/hi_desktop/hi.y.cpp"
    break;

  case 273: // HUN_Neg: HUN_Neg_Stem
#line 2412 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Neg->HUN_Neg_Stem");
yylhs.value=sparser->set_node_info("HUN_Neg",HUN_Neg_Stem);

}
#line 4982 "build/hi_desktop/hi.y.cpp"
    break;

  case 274: // HUN_Neg_Stem: t_HUN_Neg_Stem
#line 2420 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Neg_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Neg_Stem",word);

}
#line 4994 "build/hi_desktop/hi.y.cpp"
    break;

  case 275: // HUN_Noun_Pref: t_HUN_Noun_Pref
#line 2429 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Pref);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_Pref",word);

}
#line 5006 "build/hi_desktop/hi.y.cpp"
    break;

  case 276: // HUN_Noun_Stem: HUN_lfea_swConsonant HUN_Noun_Stem
#line 2438 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Noun_Stem->HUN_lfea_swConsonant HUN_Noun_Stem");
yylhs.value=sparser->combine_nodes("HUN_Noun_Stem",HUN_lfea_swConsonant,HUN_Noun_Stem);

}
#line 5018 "build/hi_desktop/hi.y.cpp"
    break;

  case 277: // HUN_Noun_Stem: HUN_lfea_swVowel HUN_Noun_Stem
#line 2446 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Noun_Stem->HUN_lfea_swVowel HUN_Noun_Stem");
yylhs.value=sparser->combine_nodes("HUN_Noun_Stem",HUN_lfea_swVowel,HUN_Noun_Stem);

}
#line 5030 "build/hi_desktop/hi.y.cpp"
    break;

  case 278: // HUN_Noun_Stem: t_HUN_Noun_Stem
#line 2454 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_Stem",word);

}
#line 5042 "build/hi_desktop/hi.y.cpp"
    break;

  case 279: // HUN_Noun_lfea_Acc: t_HUN_Noun_Acc
#line 2463 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Acc",word);

}
#line 5054 "build/hi_desktop/hi.y.cpp"
    break;

  case 280: // HUN_Noun_lfea_Dat: t_HUN_Noun_Dat
#line 2472 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Dat",word);

}
#line 5066 "build/hi_desktop/hi.y.cpp"
    break;

  case 281: // HUN_Noun_lfea_Del: t_HUN_Noun_Del
#line 2481 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Del);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Del",word);

}
#line 5078 "build/hi_desktop/hi.y.cpp"
    break;

  case 282: // HUN_Noun_lfea_Ine: t_HUN_Noun_Ine
#line 2490 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Ine);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Ine",word);

}
#line 5090 "build/hi_desktop/hi.y.cpp"
    break;

  case 283: // HUN_Noun_lfea_Plur: t_HUN_Noun_Plur
#line 2499 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Plur);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Plur",word);

}
#line 5102 "build/hi_desktop/hi.y.cpp"
    break;

  case 284: // HUN_Noun_lfea_Relative: t_HUN_Noun_Relative
#line 2508 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Relative",word);

}
#line 5114 "build/hi_desktop/hi.y.cpp"
    break;

  case 285: // HUN_Noun_lfea_Sub: t_HUN_Noun_Sub
#line 2517 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Sub);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Sub",word);

}
#line 5126 "build/hi_desktop/hi.y.cpp"
    break;

  case 286: // HUN_Num: HUN_Num HUN_Num_lfea_Ik
#line 2526 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Ik=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Ik");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Ik);

}
#line 5138 "build/hi_desktop/hi.y.cpp"
    break;

  case 287: // HUN_Num: HUN_Num HUN_Num_lfea_Par
#line 2534 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Par=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Par");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Par);

}
#line 5150 "build/hi_desktop/hi.y.cpp"
    break;

  case 288: // HUN_Num: HUN_Num_Pref HUN_Num
#line 2542 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num_Pref HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num_Pref,HUN_Num);

}
#line 5162 "build/hi_desktop/hi.y.cpp"
    break;

  case 289: // HUN_Num: HUN_Num_Stem
#line 2550 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num_Stem");
yylhs.value=sparser->set_node_info("HUN_Num",HUN_Num_Stem);

}
#line 5173 "build/hi_desktop/hi.y.cpp"
    break;

  case 290: // HUN_Num: HUN_lfea_swConsonant HUN_Num
#line 2557 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_lfea_swConsonant HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_lfea_swConsonant,HUN_Num);

}
#line 5185 "build/hi_desktop/hi.y.cpp"
    break;

  case 291: // HUN_Num: HUN_lfea_swVowel HUN_Num
#line 2565 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_lfea_swVowel HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_lfea_swVowel,HUN_Num);

}
#line 5197 "build/hi_desktop/hi.y.cpp"
    break;

  case 292: // HUN_Num_Pref: t_HUN_Num_Npref1
#line 2574 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5209 "build/hi_desktop/hi.y.cpp"
    break;

  case 293: // HUN_Num_Pref: t_HUN_Num_Npref1n
#line 2582 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5221 "build/hi_desktop/hi.y.cpp"
    break;

  case 294: // HUN_Num_Pref: t_HUN_Num_Npref1nn
#line 2590 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1nn);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5233 "build/hi_desktop/hi.y.cpp"
    break;

  case 295: // HUN_Num_Pref: t_HUN_Num_Npref1nnn
#line 2598 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1nnn);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5245 "build/hi_desktop/hi.y.cpp"
    break;

  case 296: // HUN_Num_Pref: t_HUN_Num_Npref2
#line 2606 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5257 "build/hi_desktop/hi.y.cpp"
    break;

  case 297: // HUN_Num_Pref: t_HUN_Num_Npref2n
#line 2614 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5269 "build/hi_desktop/hi.y.cpp"
    break;

  case 298: // HUN_Num_Pref: t_HUN_Num_Npref3
#line 2622 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5281 "build/hi_desktop/hi.y.cpp"
    break;

  case 299: // HUN_Num_Pref: t_HUN_Num_Npref3n
#line 2630 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5293 "build/hi_desktop/hi.y.cpp"
    break;

  case 300: // HUN_Num_Pref: t_HUN_Num_Npref4
#line 2638 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref4);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5305 "build/hi_desktop/hi.y.cpp"
    break;

  case 301: // HUN_Num_Pref: t_HUN_Num_Npref4n
#line 2646 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5317 "build/hi_desktop/hi.y.cpp"
    break;

  case 302: // HUN_Num_Pref: t_HUN_Num_Npref5
#line 2654 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref5);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5329 "build/hi_desktop/hi.y.cpp"
    break;

  case 303: // HUN_Num_Pref: t_HUN_Num_Npref5n
#line 2662 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5341 "build/hi_desktop/hi.y.cpp"
    break;

  case 304: // HUN_Num_Pref: t_HUN_Num_Npref6
#line 2670 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref6);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5353 "build/hi_desktop/hi.y.cpp"
    break;

  case 305: // HUN_Num_Pref: t_HUN_Num_Npref6n
#line 2678 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5365 "build/hi_desktop/hi.y.cpp"
    break;

  case 306: // HUN_Num_Pref: t_HUN_Num_Npref7
#line 2686 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref7);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5377 "build/hi_desktop/hi.y.cpp"
    break;

  case 307: // HUN_Num_Pref: t_HUN_Num_Npref7n
#line 2694 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5389 "build/hi_desktop/hi.y.cpp"
    break;

  case 308: // HUN_Num_Pref: t_HUN_Num_Npref8
#line 2702 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref8);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5401 "build/hi_desktop/hi.y.cpp"
    break;

  case 309: // HUN_Num_Pref: t_HUN_Num_Npref8n
#line 2710 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5413 "build/hi_desktop/hi.y.cpp"
    break;

  case 310: // HUN_Num_Pref: t_HUN_Num_Npref9
#line 2718 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref9);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5425 "build/hi_desktop/hi.y.cpp"
    break;

  case 311: // HUN_Num_Pref: t_HUN_Num_Npref9n
#line 2726 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5437 "build/hi_desktop/hi.y.cpp"
    break;

  case 312: // HUN_Num_Stem: t_HUN_Num_Stem
#line 2735 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Stem",word);

}
#line 5449 "build/hi_desktop/hi.y.cpp"
    break;

  case 313: // HUN_Num_lfea_Acc: t_HUN_Num_Acc
#line 2744 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Acc",word);

}
#line 5461 "build/hi_desktop/hi.y.cpp"
    break;

  case 314: // HUN_Num_lfea_Dat: t_HUN_Num_Dat
#line 2753 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Dat",word);

}
#line 5473 "build/hi_desktop/hi.y.cpp"
    break;

  case 315: // HUN_Num_lfea_Del: t_HUN_Num_Del
#line 2762 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Del);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Del",word);

}
#line 5485 "build/hi_desktop/hi.y.cpp"
    break;

  case 316: // HUN_Num_lfea_Ik: t_HUN_Num_Ik
#line 2771 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Ik);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Ik",word);

}
#line 5497 "build/hi_desktop/hi.y.cpp"
    break;

  case 317: // HUN_Num_lfea_Par: t_HUN_Num_Par
#line 2780 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Par);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Par",word);

}
#line 5509 "build/hi_desktop/hi.y.cpp"
    break;

  case 318: // HUN_Nums: HUN_Num HUN_Num
#line 2789 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Nums->HUN_Num HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Nums",HUN_Num1,HUN_Num2);

}
#line 5521 "build/hi_desktop/hi.y.cpp"
    break;

  case 319: // HUN_Nums: HUN_Nums HUN_Num
#line 2797 "build/hi_desktop/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Nums->HUN_Nums HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Nums",HUN_Nums,HUN_Num);

}
#line 5533 "build/hi_desktop/hi.y.cpp"
    break;

  case 320: // HUN_Pron_Int: HUN_Pron_Int HUN_Pron_lfea_Nom
#line 2806 "build/hi_desktop/hi.y"
{
const node_info& HUN_Pron_Int=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Pron_lfea_Nom=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Pron_Int->HUN_Pron_Int HUN_Pron_lfea_Nom");
yylhs.value=sparser->combine_nodes("HUN_Pron_Int",HUN_Pron_Int,HUN_Pron_lfea_Nom);

}
#line 5545 "build/hi_desktop/hi.y.cpp"
    break;

  case 321: // HUN_Pron_Int: HUN_Pron_Stem HUN_Pron_lfea_Int
#line 2814 "build/hi_desktop/hi.y"
{
const node_info& HUN_Pron_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Pron_lfea_Int=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Pron_Int->HUN_Pron_Stem HUN_Pron_lfea_Int");
yylhs.value=sparser->combine_nodes("HUN_Pron_Int",HUN_Pron_Stem,HUN_Pron_lfea_Int);

}
#line 5557 "build/hi_desktop/hi.y.cpp"
    break;

  case 322: // HUN_Pron_Stem: t_HUN_Pronoun_Stem
#line 2823 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Pron_Stem",word);

}
#line 5569 "build/hi_desktop/hi.y.cpp"
    break;

  case 323: // HUN_Pron_lfea_Int: t_HUN_Pronoun_Int
#line 2832 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Int);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Pron_lfea_Int",word);

}
#line 5581 "build/hi_desktop/hi.y.cpp"
    break;

  case 324: // HUN_Pron_lfea_Nom: t_HUN_Pronoun_Nom
#line 2841 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Nom);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Pron_lfea_Nom",word);

}
#line 5593 "build/hi_desktop/hi.y.cpp"
    break;

  case 325: // HUN_Punct: HUN_Punct_Stem HUN_Punct_ExclamationMark
#line 2850 "build/hi_desktop/hi.y"
{
const node_info& HUN_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Punct_ExclamationMark=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_ExclamationMark");
yylhs.value=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_ExclamationMark);

}
#line 5605 "build/hi_desktop/hi.y.cpp"
    break;

  case 326: // HUN_Punct: HUN_Punct_Stem HUN_Punct_FullStop
#line 2858 "build/hi_desktop/hi.y"
{
const node_info& HUN_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Punct_FullStop=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_FullStop");
yylhs.value=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_FullStop);

}
#line 5617 "build/hi_desktop/hi.y.cpp"
    break;

  case 327: // HUN_Punct: HUN_Punct_Stem HUN_Punct_QuestionMark
#line 2866 "build/hi_desktop/hi.y"
{
const node_info& HUN_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Punct_QuestionMark=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_QuestionMark");
yylhs.value=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_QuestionMark);

}
#line 5629 "build/hi_desktop/hi.y.cpp"
    break;

  case 328: // HUN_Punct_ExclamationMark: t_HUN_Punct_ExclamationMark
#line 2875 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_ExclamationMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Punct_ExclamationMark",word);

}
#line 5641 "build/hi_desktop/hi.y.cpp"
    break;

  case 329: // HUN_Punct_FullStop: t_HUN_Punct_FullStop
#line 2884 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_FullStop);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Punct_FullStop",word);

}
#line 5653 "build/hi_desktop/hi.y.cpp"
    break;

  case 330: // HUN_Punct_QuestionMark: t_HUN_Punct_QuestionMark
#line 2893 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_QuestionMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Punct_QuestionMark",word);

}
#line 5665 "build/hi_desktop/hi.y.cpp"
    break;

  case 331: // HUN_Punct_Stem: t_HUN_Punct_Stem
#line 2902 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Punct_Stem",word);

}
#line 5677 "build/hi_desktop/hi.y.cpp"
    break;

  case 332: // HUN_RC: HUN_Conj HUN_N_Sg
#line 2911 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_Conj HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_Conj,HUN_N_Sg);

}
#line 5689 "build/hi_desktop/hi.y.cpp"
    break;

  case 333: // HUN_RC: HUN_RPro HUN_INVP
#line 2919 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_INVP);

}
#line 5701 "build/hi_desktop/hi.y.cpp"
    break;

  case 334: // HUN_RC: HUN_RPro HUN_IVP
#line 2927 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVP);

}
#line 5713 "build/hi_desktop/hi.y.cpp"
    break;

  case 335: // HUN_RC: HUN_RPro HUN_IVPConj
#line 2935 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVPConj");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVPConj);

}
#line 5725 "build/hi_desktop/hi.y.cpp"
    break;

  case 336: // HUN_RC: HUN_RPro HUN_IVPlist
#line 2943 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVPlist");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVPlist);

}
#line 5737 "build/hi_desktop/hi.y.cpp"
    break;

  case 337: // HUN_RPro: HUN_Noun_Stem HUN_Noun_lfea_Relative
#line 2952 "build/hi_desktop/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RPro->HUN_Noun_Stem HUN_Noun_lfea_Relative");
yylhs.value=sparser->combine_nodes("HUN_RPro",HUN_Noun_Stem,HUN_Noun_lfea_Relative);

}
#line 5749 "build/hi_desktop/hi.y.cpp"
    break;

  case 338: // HUN_RPro: HUN_RPro HUN_Noun_lfea_Plur
#line 2960 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Plur=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RPro->HUN_RPro HUN_Noun_lfea_Plur");
yylhs.value=sparser->combine_nodes("HUN_RPro",HUN_RPro,HUN_Noun_lfea_Plur);

}
#line 5761 "build/hi_desktop/hi.y.cpp"
    break;

  case 339: // HUN_V: HUN_Verb_stem HUN_Verb_lfea_IndefPl3
#line 2969 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_IndefPl3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_V->HUN_Verb_stem HUN_Verb_lfea_IndefPl3");
yylhs.value=sparser->combine_nodes("HUN_V",HUN_Verb_stem,HUN_Verb_lfea_IndefPl3);

}
#line 5773 "build/hi_desktop/hi.y.cpp"
    break;

  case 340: // HUN_VP: HUN_ImpVerb HUN_AP
#line 2978 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_AP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_AP);

}
#line 5785 "build/hi_desktop/hi.y.cpp"
    break;

  case 341: // HUN_VP: HUN_ImpVerb HUN_DP
#line 2986 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_DP);

}
#line 5797 "build/hi_desktop/hi.y.cpp"
    break;

  case 342: // HUN_VP: HUN_ImpVerb HUN_Empty
#line 2994 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Empty=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_Empty");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_Empty);

}
#line 5809 "build/hi_desktop/hi.y.cpp"
    break;

  case 343: // HUN_VP: HUN_ImpVerbPfx HUN_DP
#line 3002 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_DP);

}
#line 5821 "build/hi_desktop/hi.y.cpp"
    break;

  case 344: // HUN_VP: HUN_ImpVerbPfx HUN_NP
#line 3010 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_NP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_NP);

}
#line 5833 "build/hi_desktop/hi.y.cpp"
    break;

  case 345: // HUN_VP: HUN_IndVerb HUN_ConjN
#line 3018 "build/hi_desktop/hi.y"
{
const node_info& HUN_IndVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjN=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_ConjN,"Conj","qword",false,true);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_IndVerb HUN_ConjN");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_IndVerb,HUN_ConjN);
}
#line 5845 "build/hi_desktop/hi.y.cpp"
    break;

  case 346: // HUN_VP: HUN_IndVerb HUN_N_Sg
#line 3026 "build/hi_desktop/hi.y"
{
const node_info& HUN_IndVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_IndVerb HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_IndVerb,HUN_N_Sg);

}
#line 5857 "build/hi_desktop/hi.y.cpp"
    break;

  case 347: // HUN_VP: HUN_Neg HUN_ImpVerb
#line 3034 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Neg HUN_ImpVerb");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Neg,HUN_ImpVerb);

}
#line 5869 "build/hi_desktop/hi.y.cpp"
    break;

  case 348: // HUN_VP: HUN_Pron_Int HUN_IndVerb
#line 3042 "build/hi_desktop/hi.y"
{
const node_info& HUN_Pron_Int=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IndVerb=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Pron_Int,"Pronoun",std::string("qword"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Pron_Int HUN_IndVerb");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Pron_Int,HUN_IndVerb);
}
#line 5881 "build/hi_desktop/hi.y.cpp"
    break;

  case 349: // HUN_VP: HUN_Vbar1 HUN_NP
#line 3050 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar1 HUN_NP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar1,HUN_NP);

}
#line 5893 "build/hi_desktop/hi.y.cpp"
    break;

  case 350: // HUN_VP: HUN_Vbar2 HUN_N_Ins
#line 3058 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar2 HUN_N_Ins");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar2,HUN_N_Ins);

}
#line 5905 "build/hi_desktop/hi.y.cpp"
    break;

  case 351: // HUN_VP: HUN_Vbar2 HUN_RC
#line 3066 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar2 HUN_RC");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar2,HUN_RC);

}
#line 5917 "build/hi_desktop/hi.y.cpp"
    break;

  case 352: // HUN_VP: HUN_Vbar3 HUN_RC
#line 3074 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vbar3=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar3 HUN_RC");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar3,HUN_RC);

}
#line 5929 "build/hi_desktop/hi.y.cpp"
    break;

  case 353: // HUN_Vbar1: HUN_ImpVerb HUN_DP
#line 3083 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar1->HUN_ImpVerb HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_Vbar1",HUN_ImpVerb,HUN_DP);

}
#line 5941 "build/hi_desktop/hi.y.cpp"
    break;

  case 354: // HUN_Vbar2: HUN_ImpVerb HUN_N_Acc
#line 3092 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar2->HUN_ImpVerb HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_Vbar2",HUN_ImpVerb,HUN_N_Acc);

}
#line 5953 "build/hi_desktop/hi.y.cpp"
    break;

  case 355: // HUN_Vbar2: HUN_ImpVerb HUN_N_Dat
#line 3100 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar2->HUN_ImpVerb HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_Vbar2",HUN_ImpVerb,HUN_N_Dat);

}
#line 5965 "build/hi_desktop/hi.y.cpp"
    break;

  case 356: // HUN_Vbar3: HUN_ImpVerb_N_Acc HUN_N_Dat
#line 3109 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar3->HUN_ImpVerb_N_Acc HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_Vbar3",HUN_ImpVerb_N_Acc,HUN_N_Dat);

}
#line 5977 "build/hi_desktop/hi.y.cpp"
    break;

  case 357: // HUN_Vbar3: HUN_ImpVerb_N_Dat HUN_N_Acc
#line 3117 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb_N_Dat=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar3->HUN_ImpVerb_N_Dat HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_Vbar3",HUN_ImpVerb_N_Dat,HUN_N_Acc);

}
#line 5989 "build/hi_desktop/hi.y.cpp"
    break;

  case 358: // HUN_Vbpfx: t_HUN_Vbpfx_Stem
#line 3126 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Vbpfx_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Vbpfx",word);

}
#line 6001 "build/hi_desktop/hi.y.cpp"
    break;

  case 359: // HUN_Verb_lfea_ConjDefSg2: t_HUN_Verb_ConjDefSg2
#line 3135 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_ConjDefSg2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_ConjDefSg2",word);

}
#line 6013 "build/hi_desktop/hi.y.cpp"
    break;

  case 360: // HUN_Verb_lfea_ConjIndefSg2: t_HUN_Verb_ConjIndefSg2
#line 3144 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_ConjIndefSg2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_ConjIndefSg2",word);

}
#line 6025 "build/hi_desktop/hi.y.cpp"
    break;

  case 361: // HUN_Verb_lfea_DefSg1: t_HUN_Verb_DefSg1
#line 3153 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_DefSg1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_DefSg1",word);

}
#line 6037 "build/hi_desktop/hi.y.cpp"
    break;

  case 362: // HUN_Verb_lfea_InDefSg3: t_HUN_Verb_IndefSg3
#line 3162 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_IndefSg3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_InDefSg3",word);

}
#line 6049 "build/hi_desktop/hi.y.cpp"
    break;

  case 363: // HUN_Verb_lfea_IndefPl3: t_HUN_Verb_IndefPl3
#line 3171 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_IndefPl3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_IndefPl3",word);

}
#line 6061 "build/hi_desktop/hi.y.cpp"
    break;

  case 364: // HUN_Verb_stem: t_HUN_Verb_Stem
#line 3180 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_stem",word);

}
#line 6073 "build/hi_desktop/hi.y.cpp"
    break;

  case 365: // HUN_Vhead: HUN_INVP
#line 3189 "build/hi_desktop/hi.y"
{
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vhead->HUN_INVP");
yylhs.value=sparser->set_node_info("HUN_Vhead",HUN_INVP);

}
#line 6084 "build/hi_desktop/hi.y.cpp"
    break;

  case 366: // HUN_Vhead: HUN_IVP
#line 3196 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vhead->HUN_IVP");
yylhs.value=sparser->set_node_info("HUN_Vhead",HUN_IVP);

}
#line 6095 "build/hi_desktop/hi.y.cpp"
    break;

  case 367: // HUN_Vlisthead: HUN_IVPlist
#line 3204 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vlisthead->HUN_IVPlist");
yylhs.value=sparser->set_node_info("HUN_Vlisthead",HUN_IVPlist);

}
#line 6106 "build/hi_desktop/hi.y.cpp"
    break;

  case 368: // HUN_lfea_DefDet: t_HUN_Det_Def
#line 3212 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_Def);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_DefDet",word);

}
#line 6118 "build/hi_desktop/hi.y.cpp"
    break;

  case 369: // HUN_lfea_fwConsonant: t_HUN_Det_fwConsonant
#line 3221 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_fwConsonant",word);

}
#line 6130 "build/hi_desktop/hi.y.cpp"
    break;

  case 370: // HUN_lfea_fwVowel: t_HUN_Det_fwVowel
#line 3230 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_fwVowel",word);

}
#line 6142 "build/hi_desktop/hi.y.cpp"
    break;

  case 371: // HUN_lfea_swConsonant: t_HUN_CON_swConsonant
#line 3239 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 6154 "build/hi_desktop/hi.y.cpp"
    break;

  case 372: // HUN_lfea_swConsonant: t_HUN_Noun_swConsonant
#line 3247 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 6166 "build/hi_desktop/hi.y.cpp"
    break;

  case 373: // HUN_lfea_swConsonant: t_HUN_Num_swConsonant
#line 3255 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 6178 "build/hi_desktop/hi.y.cpp"
    break;

  case 374: // HUN_lfea_swVowel: t_HUN_CON_swVowel
#line 3264 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 6190 "build/hi_desktop/hi.y.cpp"
    break;

  case 375: // HUN_lfea_swVowel: t_HUN_Noun_swVowel
#line 3272 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 6202 "build/hi_desktop/hi.y.cpp"
    break;

  case 376: // HUN_lfea_swVowel: t_HUN_Num_swVowel
#line 3280 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 6214 "build/hi_desktop/hi.y.cpp"
    break;

  case 377: // HUN_nCon: HUN_1Con HUN_Con
#line 3289 "build/hi_desktop/hi.y"
{
const node_info& HUN_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_nCon->HUN_1Con HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_nCon",HUN_1Con,HUN_Con);

}
#line 6226 "build/hi_desktop/hi.y.cpp"
    break;

  case 378: // HUN_nCon: HUN_nCon HUN_Con
#line 3297 "build/hi_desktop/hi.y"
{
const node_info& HUN_nCon=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_nCon->HUN_nCon HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_nCon",HUN_nCon,HUN_Con);

}
#line 6238 "build/hi_desktop/hi.y.cpp"
    break;

  case 379: // JSON_Array: JSON_Open_Array JSON_Closing_Value_Element
#line 3306 "build/hi_desktop/hi.y"
{
const node_info& JSON_Open_Array=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Closing_Value_Element=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Array->JSON_Open_Array JSON_Closing_Value_Element");
yylhs.value=sparser->combine_nodes("JSON_Array",JSON_Open_Array,JSON_Closing_Value_Element);

}
#line 6250 "build/hi_desktop/hi.y.cpp"
    break;

  case 380: // JSON_CON: t_JSON_CON_Stem
#line 3315 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_CON",word);

}
#line 6262 "build/hi_desktop/hi.y.cpp"
    break;

  case 381: // JSON_ClosingCBracket: JSON_Punct_Stem JSON_Punct_ClosingCBracket
#line 3324 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_ClosingCBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_ClosingCBracket->JSON_Punct_Stem JSON_Punct_ClosingCBracket");
yylhs.value=sparser->combine_nodes("JSON_ClosingCBracket",JSON_Punct_Stem,JSON_Punct_ClosingCBracket);

}
#line 6274 "build/hi_desktop/hi.y.cpp"
    break;

  case 382: // JSON_ClosingSBracket: JSON_Punct_Stem JSON_Punct_ClosingSBracket
#line 3333 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_ClosingSBracket->JSON_Punct_Stem JSON_Punct_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_ClosingSBracket",JSON_Punct_Stem,JSON_Punct_ClosingSBracket);

}
#line 6286 "build/hi_desktop/hi.y.cpp"
    break;

  case 383: // JSON_Closing_Key_Value_Pair: JSON_Key_Value_Pair JSON_ClosingCBracket
#line 3342 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key_Value_Pair=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingCBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Key_Value_Pair->JSON_Key_Value_Pair JSON_ClosingCBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Key_Value_Pair",JSON_Key_Value_Pair,JSON_ClosingCBracket);

}
#line 6298 "build/hi_desktop/hi.y.cpp"
    break;

  case 384: // JSON_Closing_Value_Element: JSON_Array JSON_ClosingSBracket
#line 3351 "build/hi_desktop/hi.y"
{
const node_info& JSON_Array=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_Array JSON_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_Array,JSON_ClosingSBracket);

}
#line 6310 "build/hi_desktop/hi.y.cpp"
    break;

  case 385: // JSON_Closing_Value_Element: JSON_Dot_Relative JSON_ClosingSBracket
#line 3359 "build/hi_desktop/hi.y"
{
const node_info& JSON_Dot_Relative=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_Dot_Relative JSON_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_Dot_Relative,JSON_ClosingSBracket);

}
#line 6322 "build/hi_desktop/hi.y.cpp"
    break;

  case 386: // JSON_Closing_Value_Element: JSON_Number JSON_ClosingSBracket
#line 3367 "build/hi_desktop/hi.y"
{
const node_info& JSON_Number=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_Number JSON_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_Number,JSON_ClosingSBracket);

}
#line 6334 "build/hi_desktop/hi.y.cpp"
    break;

  case 387: // JSON_Closing_Value_Element: JSON_String JSON_ClosingSBracket
#line 3375 "build/hi_desktop/hi.y"
{
const node_info& JSON_String=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_String JSON_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_String,JSON_ClosingSBracket);

}
#line 6346 "build/hi_desktop/hi.y.cpp"
    break;

  case 388: // JSON_Colon: JSON_Punct_Stem JSON_Punct_Colon
#line 3384 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_Colon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Colon->JSON_Punct_Stem JSON_Punct_Colon");
yylhs.value=sparser->combine_nodes("JSON_Colon",JSON_Punct_Stem,JSON_Punct_Colon);

}
#line 6358 "build/hi_desktop/hi.y.cpp"
    break;

  case 389: // JSON_Comma: JSON_Punct_Stem JSON_Punct_Comma
#line 3393 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Comma->JSON_Punct_Stem JSON_Punct_Comma");
yylhs.value=sparser->combine_nodes("JSON_Comma",JSON_Punct_Stem,JSON_Punct_Comma);

}
#line 6370 "build/hi_desktop/hi.y.cpp"
    break;

  case 390: // JSON_Dot: JSON_Punct_Stem JSON_Punct_Dot
#line 3402 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_Dot=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Dot->JSON_Punct_Stem JSON_Punct_Dot");
yylhs.value=sparser->combine_nodes("JSON_Dot",JSON_Punct_Stem,JSON_Punct_Dot);

}
#line 6382 "build/hi_desktop/hi.y.cpp"
    break;

  case 391: // JSON_Dot_Relative: JSON_Dot JSON_Dot_lfea_relative
#line 3411 "build/hi_desktop/hi.y"
{
const node_info& JSON_Dot=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Dot_lfea_relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Dot_Relative->JSON_Dot JSON_Dot_lfea_relative");
yylhs.value=sparser->combine_nodes("JSON_Dot_Relative",JSON_Dot,JSON_Dot_lfea_relative);

}
#line 6394 "build/hi_desktop/hi.y.cpp"
    break;

  case 392: // JSON_Dot_lfea_relative: t_JSON_Punct_Relative
#line 3420 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Dot_lfea_relative",word);

}
#line 6406 "build/hi_desktop/hi.y.cpp"
    break;

  case 393: // JSON_Key: JSON_String JSON_Colon
#line 3429 "build/hi_desktop/hi.y"
{
const node_info& JSON_String=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Colon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key->JSON_String JSON_Colon");
yylhs.value=sparser->combine_nodes("JSON_Key",JSON_String,JSON_Colon);

}
#line 6418 "build/hi_desktop/hi.y.cpp"
    break;

  case 394: // JSON_Key_Value_List_Element: JSON_Key_Value_Pair JSON_Comma
#line 3438 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key_Value_Pair=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_List_Element->JSON_Key_Value_Pair JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Key_Value_List_Element",JSON_Key_Value_Pair,JSON_Comma);

}
#line 6430 "build/hi_desktop/hi.y.cpp"
    break;

  case 395: // JSON_Key_Value_Pair: JSON_Key JSON_Array
#line 3447 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Array=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_Array");
yylhs.value=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_Array);

}
#line 6442 "build/hi_desktop/hi.y.cpp"
    break;

  case 396: // JSON_Key_Value_Pair: JSON_Key JSON_Dot_Relative
#line 3455 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Dot_Relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_Dot_Relative");
yylhs.value=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_Dot_Relative);

}
#line 6454 "build/hi_desktop/hi.y.cpp"
    break;

  case 397: // JSON_Key_Value_Pair: JSON_Key JSON_Number
#line 3463 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Number=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_Number");
yylhs.value=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_Number);

}
#line 6466 "build/hi_desktop/hi.y.cpp"
    break;

  case 398: // JSON_Key_Value_Pair: JSON_Key JSON_String
#line 3471 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_String=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_String");
yylhs.value=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_String);

}
#line 6478 "build/hi_desktop/hi.y.cpp"
    break;

  case 399: // JSON_Number: JSON_CON
#line 3480 "build/hi_desktop/hi.y"
{
const node_info& JSON_CON=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Number->JSON_CON");
yylhs.value=sparser->set_node_info("JSON_Number",JSON_CON);

}
#line 6489 "build/hi_desktop/hi.y.cpp"
    break;

  case 400: // JSON_Object: JSON_Open_Object JSON_Closing_Key_Value_Pair
#line 3488 "build/hi_desktop/hi.y"
{
const node_info& JSON_Open_Object=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Closing_Key_Value_Pair=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(JSON_Open_Object,"Punct",std::string("main_verb"));
sparser->add_feature_to_leaf(JSON_Open_Object,"main_verb",std::string("indicative"),true);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Object->JSON_Open_Object JSON_Closing_Key_Value_Pair");
yylhs.value=sparser->combine_nodes("JSON_Object",JSON_Open_Object,JSON_Closing_Key_Value_Pair);
const node_info& JSON_Object=sparser->get_node_info(yylhs.value);
sparser->add_feature_to_leaf(JSON_Object,"JSON_Open_Object","Punct",std::string("json_obj"),false,true);
}
#line 6504 "build/hi_desktop/hi.y.cpp"
    break;

  case 401: // JSON_Open_Array: JSON_Open_Array JSON_Value_List_Element
#line 3500 "build/hi_desktop/hi.y"
{
const node_info& JSON_Open_Array=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Value_List_Element=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_Array->JSON_Open_Array JSON_Value_List_Element");
yylhs.value=sparser->combine_nodes("JSON_Open_Array",JSON_Open_Array,JSON_Value_List_Element);

}
#line 6516 "build/hi_desktop/hi.y.cpp"
    break;

  case 402: // JSON_Open_Array: JSON_OpeningSBracket
#line 3508 "build/hi_desktop/hi.y"
{
const node_info& JSON_OpeningSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_Array->JSON_OpeningSBracket");
yylhs.value=sparser->set_node_info("JSON_Open_Array",JSON_OpeningSBracket);

}
#line 6527 "build/hi_desktop/hi.y.cpp"
    break;

  case 403: // JSON_Open_Object: JSON_Open_Object JSON_Key_Value_List_Element
#line 3516 "build/hi_desktop/hi.y"
{
const node_info& JSON_Open_Object=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Key_Value_List_Element=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_Object->JSON_Open_Object JSON_Key_Value_List_Element");
yylhs.value=sparser->combine_nodes("JSON_Open_Object",JSON_Open_Object,JSON_Key_Value_List_Element);

}
#line 6539 "build/hi_desktop/hi.y.cpp"
    break;

  case 404: // JSON_Open_Object: JSON_OpeningCBracket
#line 3524 "build/hi_desktop/hi.y"
{
const node_info& JSON_OpeningCBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_Object->JSON_OpeningCBracket");
yylhs.value=sparser->set_node_info("JSON_Open_Object",JSON_OpeningCBracket);

}
#line 6550 "build/hi_desktop/hi.y.cpp"
    break;

  case 405: // JSON_Open_String: JSON_Quotes HUN_N_Sg
#line 3532 "build/hi_desktop/hi.y"
{
const node_info& JSON_Quotes=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_N_Sg,"Noun",std::string("json_key"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_String->JSON_Quotes HUN_N_Sg");
yylhs.value=sparser->combine_nodes("JSON_Open_String",JSON_Quotes,HUN_N_Sg);
}
#line 6562 "build/hi_desktop/hi.y.cpp"
    break;

  case 406: // JSON_Open_String: JSON_Quotes JSON_CON
#line 3540 "build/hi_desktop/hi.y"
{
const node_info& JSON_Quotes=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_CON=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_String->JSON_Quotes JSON_CON");
yylhs.value=sparser->combine_nodes("JSON_Open_String",JSON_Quotes,JSON_CON);

}
#line 6574 "build/hi_desktop/hi.y.cpp"
    break;

  case 407: // JSON_OpeningCBracket: JSON_Punct_Stem JSON_Punct_OpeningCBracket
#line 3549 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_OpeningCBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_OpeningCBracket->JSON_Punct_Stem JSON_Punct_OpeningCBracket");
yylhs.value=sparser->combine_nodes("JSON_OpeningCBracket",JSON_Punct_Stem,JSON_Punct_OpeningCBracket);

}
#line 6586 "build/hi_desktop/hi.y.cpp"
    break;

  case 408: // JSON_OpeningSBracket: JSON_Punct_Stem JSON_Punct_OpeningSBracket
#line 3558 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_OpeningSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_OpeningSBracket->JSON_Punct_Stem JSON_Punct_OpeningSBracket");
yylhs.value=sparser->combine_nodes("JSON_OpeningSBracket",JSON_Punct_Stem,JSON_Punct_OpeningSBracket);

}
#line 6598 "build/hi_desktop/hi.y.cpp"
    break;

  case 409: // JSON_Punct_ClosingCBracket: t_JSON_Punct_ClosingCBracket
#line 3567 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_ClosingCBracket);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_ClosingCBracket",word);

}
#line 6610 "build/hi_desktop/hi.y.cpp"
    break;

  case 410: // JSON_Punct_ClosingSBracket: t_JSON_Punct_ClosingSBracket
#line 3576 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_ClosingSBracket);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_ClosingSBracket",word);

}
#line 6622 "build/hi_desktop/hi.y.cpp"
    break;

  case 411: // JSON_Punct_Colon: t_JSON_Punct_Colon
#line 3585 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Colon);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Colon",word);

}
#line 6634 "build/hi_desktop/hi.y.cpp"
    break;

  case 412: // JSON_Punct_Comma: t_JSON_Punct_Comma
#line 3594 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Comma);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Comma",word);

}
#line 6646 "build/hi_desktop/hi.y.cpp"
    break;

  case 413: // JSON_Punct_Dot: t_JSON_Punct_Dot
#line 3603 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Dot);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Dot",word);

}
#line 6658 "build/hi_desktop/hi.y.cpp"
    break;

  case 414: // JSON_Punct_OpeningCBracket: t_JSON_Punct_OpeningCBracket
#line 3612 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_OpeningCBracket);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_OpeningCBracket",word);

}
#line 6670 "build/hi_desktop/hi.y.cpp"
    break;

  case 415: // JSON_Punct_OpeningSBracket: t_JSON_Punct_OpeningSBracket
#line 3621 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_OpeningSBracket);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_OpeningSBracket",word);

}
#line 6682 "build/hi_desktop/hi.y.cpp"
    break;

  case 416: // JSON_Punct_Quotes: t_JSON_Punct_Quotes
#line 3630 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Quotes);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Quotes",word);

}
#line 6694 "build/hi_desktop/hi.y.cpp"
    break;

  case 417: // JSON_Punct_Stem: t_JSON_Punct_Stem
#line 3639 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Stem",word);

}
#line 6706 "build/hi_desktop/hi.y.cpp"
    break;

  case 418: // JSON_Quotes: JSON_Punct_Stem JSON_Punct_Quotes
#line 3648 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_Quotes=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Quotes->JSON_Punct_Stem JSON_Punct_Quotes");
yylhs.value=sparser->combine_nodes("JSON_Quotes",JSON_Punct_Stem,JSON_Punct_Quotes);

}
#line 6718 "build/hi_desktop/hi.y.cpp"
    break;

  case 419: // JSON_String: JSON_Open_String JSON_Quotes
#line 3657 "build/hi_desktop/hi.y"
{
const node_info& JSON_Open_String=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Quotes=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_String->JSON_Open_String JSON_Quotes");
yylhs.value=sparser->combine_nodes("JSON_String",JSON_Open_String,JSON_Quotes);

}
#line 6730 "build/hi_desktop/hi.y.cpp"
    break;

  case 420: // JSON_Value_List_Element: JSON_Array JSON_Comma
#line 3666 "build/hi_desktop/hi.y"
{
const node_info& JSON_Array=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_Array JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Value_List_Element",JSON_Array,JSON_Comma);

}
#line 6742 "build/hi_desktop/hi.y.cpp"
    break;

  case 421: // JSON_Value_List_Element: JSON_Dot_Relative JSON_Comma
#line 3674 "build/hi_desktop/hi.y"
{
const node_info& JSON_Dot_Relative=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_Dot_Relative JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Value_List_Element",JSON_Dot_Relative,JSON_Comma);

}
#line 6754 "build/hi_desktop/hi.y.cpp"
    break;

  case 422: // JSON_Value_List_Element: JSON_Number JSON_Comma
#line 3682 "build/hi_desktop/hi.y"
{
const node_info& JSON_Number=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_Number JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Value_List_Element",JSON_Number,JSON_Comma);

}
#line 6766 "build/hi_desktop/hi.y.cpp"
    break;

  case 423: // JSON_Value_List_Element: JSON_String JSON_Comma
#line 3690 "build/hi_desktop/hi.y"
{
const node_info& JSON_String=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_String JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Value_List_Element",JSON_String,JSON_Comma);

}
#line 6778 "build/hi_desktop/hi.y.cpp"
    break;

  case 424: // S: ENG_VP
#line 3699 "build/hi_desktop/hi.y"
{
const node_info& ENG_VP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP");
yylhs.value=sparser->set_node_info("S",ENG_VP);

}
#line 6789 "build/hi_desktop/hi.y.cpp"
    break;

  case 425: // S: HUN_VP HUN_Punct
#line 3706 "build/hi_desktop/hi.y"
{
const node_info& HUN_VP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Punct=sparser->get_node_info(yystack_[0].value);
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
yylhs.value=sparser->combine_nodes("S",HUN_VP,HUN_Punct);
}
#line 6820 "build/hi_desktop/hi.y.cpp"
    break;

  case 426: // S: JSON_Object
#line 3733 "build/hi_desktop/hi.y"
{
const node_info& JSON_Object=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->JSON_Object");
yylhs.value=sparser->set_node_info("S",JSON_Object);

}
#line 6831 "build/hi_desktop/hi.y.cpp"
    break;


#line 6835 "build/hi_desktop/hi.y.cpp"

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

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
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


  const short parser::yypact_ninf_ = -357;

  const short parser::yytable_ninf_ = -368;

  const short
  parser::yypact_[] =
  {
      38,  -357,  -357,  -357,  -357,  -357,  -357,  -357,    31,   540,
      50,   209,    44,    44,    31,    31,   368,  -357,  -357,  -357,
      92,  1646,   181,   497,    53,   633,   986,  1165,  1165,   317,
      19,  -357,   -10,   104,   128,  1165,   145,  1185,    49,  -357,
      14,  -357,    15,   237,  -357,   161,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,   244,  -357,
    -357,  -357,   286,   244,   244,   244,   286,   244,   244,   309,
     236,  -357,   622,  -357,   244,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,   267,  -357,   292,   316,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,   214,  -357,  -357,   327,  -357,   214,
    -357,    84,   319,  -357,  -357,    84,  -357,  -357,  -357,  -357,
     254,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,    91,   319,  -357,   319,   113,   319,   497,  -357,
      31,   326,    31,  -357,   579,   332,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,   233,  -357,  -357,   280,  -357,  -357,  -357,
    -357,  -357,  1027,   274,  -357,  -357,  1027,  -357,   335,  1165,
     259,    54,    58,   345,  -357,  -357,   124,   322,    37,   280,
    1206,    37,  1068,   597,   307,  1272,  1565,  -357,  1352,  -357,
    1463,  1463,   233,  -357,  -357,  -357,  -357,   369,  -357,  1499,
    1532,  -357,   152,  -357,  1312,  1390,  -357,   561,  -357,   274,
      32,    32,  -357,    76,  -357,  -357,  -357,   323,  -357,  -357,
    -357,  -357,   324,  -357,  -357,   317,  -357,  -357,   336,   343,
    -357,   698,   343,  -357,   597,   597,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,   239,  -357,    14,    14,   312,
     215,    14,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
     244,   244,   244,   244,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,   425,  -357,
    -357,  -357,  -357,    89,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,   250,  -357,  -357,  -357,  -357,  -357,    46,   319,   174,
     579,    31,   156,   421,   319,   319,  -357,  -357,  -357,  -357,
    -357,  -357,   233,   233,  -357,  -357,  -357,    37,   369,  1165,
     889,  1027,  -357,  -357,  -357,    37,  -357,  -357,  -357,    87,
    1213,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,   348,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,   348,   348,   348,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,   302,  -357,  -357,  -357,
    -357,  -357,  1565,  1565,   302,   302,  -357,  -357,  -357,  -357,
     302,  -357,  -357,   302,  -357,   317,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,   757,   801,   274,  -357,
     845,   354,    19,    19,    19,  1124,  -357,  1165,   339,   274,
     274,  -357,  -357,  -357,   328,  -357,  -357,   239,  -357,   265,
    -357,  -357,  -357,   -14,  -357,  -357,  -357,  -357,  -357,  -357,
     346,    89,    89,   250,   250,  -357,    31,  -357,  -357,  -357,
    -357,  -357,   214,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  1425,  1425,    37,  -357,  1027,  -357,  1027,  -357,    36,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,   945,  -357,
    -357,  -357,  -357,    19,  -357,  -357,  -357,  -357,  -357,    19,
      19,    19,  1165,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
      14,  -357,    14,    14,    14,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,    31,    31,  -357,  -357,
    -357,   945,   945,   945,  -357,  -357,  -357,  -357,  -357,   158,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357
  };

  const short
  parser::yydefact_[] =
  {
       0,    38,   135,   117,   322,   364,   274,   417,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   424,   118,   116,
     119,   122,   128,     0,     0,   218,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,     0,     0,     0,   426,
       0,   404,     0,     0,   142,   119,    28,    77,    92,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    69,     2,
      33,    52,     0,    60,    62,    53,     0,    70,    72,     0,
       0,    34,     0,    81,    65,   148,   147,    37,    49,   150,
     149,    50,    51,     0,    35,     0,     0,    36,   143,   115,
      10,    16,   108,     6,    69,     4,    11,     0,     5,     0,
       3,     7,     8,    17,   141,     9,    54,    55,    23,   138,
       0,   136,   137,   133,   134,   107,   114,   121,   123,   139,
      96,   140,   103,   125,    97,     0,   106,     0,     0,   127,
       0,     0,     0,   120,     0,     0,   129,   130,   131,   132,
     188,   312,   292,   296,   298,   300,   302,   304,   306,   308,
     310,   294,   295,   217,   374,   371,   293,   297,   299,   301,
     303,   305,   307,   309,   311,   376,   373,   278,   375,   372,
     358,   182,   275,   267,   175,   176,     0,   340,   169,   170,
     172,   173,   177,     0,   156,   181,   180,   155,   353,     0,
       0,     0,     0,     0,   342,   171,   243,   244,     0,     0,
       0,     0,     0,     0,   269,     0,     0,   289,     0,   242,
       0,     0,   270,   343,   344,   247,   248,   249,   250,     0,
       0,   356,     0,   269,     0,     0,   357,     0,   345,   346,
       0,     0,   347,     0,   324,   348,   320,     0,   323,   321,
     331,   425,     0,   349,   208,     0,   193,   350,     0,   269,
     351,     0,     0,   352,     0,     0,   359,   362,   360,   361,
     239,   240,   241,   245,   400,     0,   403,     0,     0,     0,
       0,     0,   414,   407,     1,   153,   152,   151,    67,    68,
       0,    61,    63,    64,    75,    76,    71,    73,    78,    79,
      66,    74,    93,    82,    80,   154,    20,    21,     0,    12,
      22,    27,    18,     0,    13,    24,    14,    19,    15,    56,
     104,     0,    98,    99,   105,   100,    95,   109,   110,   111,
       0,     0,     0,   118,     0,     0,   113,   112,    94,   101,
     102,   377,     0,     0,   279,   251,   183,   160,     0,     0,
       0,   178,   161,   179,   184,   162,   209,   210,   211,     0,
       0,   370,   369,   215,   216,   212,   213,   368,   214,   163,
     166,     0,   164,   167,   252,   189,   192,   285,   191,   280,
     190,   281,   253,   257,   265,   271,   158,   254,   258,   259,
     272,   165,   168,   246,   157,     0,     0,     0,   268,   283,
     266,   316,   317,   313,   314,   315,   318,   255,   260,   261,
     286,   287,     0,     0,   288,   319,   256,   262,   186,   276,
     290,   187,   277,   291,   378,     0,   203,   329,   330,   328,
     325,   326,   327,   332,   284,   337,   333,   334,   335,   225,
     336,     0,   247,   248,   250,     0,   338,     0,     0,     0,
       0,   380,   395,   399,     0,   396,   397,     0,   402,     0,
     398,   383,   394,     0,   419,   416,   418,   405,   406,   393,
       0,    25,    26,    29,    30,    47,     0,    44,    48,    39,
      40,    57,    41,    42,    43,    58,    59,    45,    46,   194,
     195,   196,   197,     0,   198,   201,   199,   202,   200,     0,
     282,   263,   264,   204,   233,   234,   235,   236,     0,   226,
     237,   238,   219,     0,   229,   230,   231,   220,   221,     0,
       0,     0,     0,   232,   363,   339,   227,   228,   392,   391,
       0,   379,     0,     0,     0,   401,   413,   415,   390,   408,
     412,   409,   381,   389,   411,   388,    31,    32,   174,   185,
     159,   205,   206,   207,   224,   222,   223,   384,   420,     0,
     385,   421,   386,   422,   387,   423,   410,   382
  };

  const short
  parser::yypgoto_[] =
  {
    -357,    -2,   349,  -357,  -357,  -357,   132,  -357,   -70,  -357,
    -357,   437,   157,  -357,   353,   -33,    78,  -357,     6,   117,
      64,   435,  -357,  -357,  -112,  -357,     3,  -357,  -357,  -357,
      -4,    17,  -357,  -357,  -357,  -357,   370,   378,  -357,   381,
     459,   468,    40,  -357,  -357,   411,  -357,  -357,  -357,  -357,
    -357,     7,    -9,  -357,   352,  -357,   175,  -357,  -357,  -357,
     465,  -357,  -357,  -357,  -357,  -357,   144,    81,  -357,  -357,
     296,   488,    39,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,   432,   434,   377,  -357,     0,
       2,  -357,  -157,  -357,  -183,  -357,  -357,  -357,    -8,  -357,
    -357,  -174,  -357,    86,  -357,   -92,  -357,  -357,  -357,  -357,
      10,  -357,  -357,  -357,  -357,  -357,   -21,  -357,   472,  -357,
    -357,  -357,  -357,  -357,  -357,  -184,  -357,  -357,  -178,  -357,
      70,    11,   480,  -357,  -357,  -357,   479,  -357,   122,    -5,
      21,  -357,   -20,   330,   -25,   -13,     8,  -357,  -357,     5,
    -131,  -357,  -357,   162,   262,  -357,  -357,    59,  -357,  -357,
    -138,  -151,  -357,  -357,  -357,    -1,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,   478,  -357,  -356,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,    55,  -357,
    -357,  -357,  -357,  -357,   333,   392,  -357,    73,   255,  -357,
    -142,  -357,  -357,  -357,  -217,  -357,    79,  -357,  -357,  -357,
    -357,    80,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,     9,   263,  -251,  -357,
    -357
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   303,   304,   305,    59,   312,
     467,     8,     9,    10,   465,   318,   319,    11,    12,    13,
     108,   109,   320,   321,    61,    62,    63,    64,    65,    66,
      67,    68,    69,   290,   291,    70,    71,    72,    73,   293,
     120,   121,   310,   123,   124,   125,   126,   127,   128,   110,
     129,   130,   327,   131,    14,    15,   322,   132,   133,    17,
     323,   134,    45,   113,   114,    21,    22,    23,    24,   324,
     325,    77,    78,    81,    82,   284,   285,    74,   173,   359,
     360,   176,   484,   177,   178,   179,   180,   181,   336,   486,
     183,   184,   185,   186,   488,   187,   372,   373,   374,   375,
     498,   341,   342,   343,   228,   416,   499,   246,   188,   189,
     190,   191,   192,   193,   194,   494,   507,   502,   495,   428,
     429,   430,    25,    26,    27,    28,    29,   195,   431,   432,
     197,   348,   198,   199,   338,   201,   435,    31,   203,   204,
     377,   378,   379,   491,   390,   425,   380,   219,   206,   207,
     397,   398,   399,   400,   401,   220,    32,    33,   239,   236,
     241,   420,   421,   422,   242,   250,   251,   437,    34,    35,
      36,    37,   209,   260,   261,   262,   263,   515,   438,   439,
     440,   358,   353,   354,   210,   211,   212,   442,   443,   451,
     547,   264,   521,   459,   452,   444,   445,   519,   265,   266,
     267,   446,    39,   447,    40,   268,    41,   448,   532,   557,
     535,   533,   528,   273,   529,   456,   549,   270,   271,   525,
      43
  };

  const short
  parser::yytable_[] =
  {
     200,   217,   222,   227,   229,    60,   216,    58,    30,    42,
     217,   248,   122,   218,   450,   216,   247,   182,   317,   383,
     196,   215,   218,   226,   208,   174,   225,   175,   384,   136,
     215,   302,   223,   202,   223,   307,   540,   234,   119,    20,
     138,   249,   252,     2,     1,   335,   245,   245,   221,   269,
       2,    47,    85,    85,    89,    38,     3,   407,     2,     1,
     135,   280,   280,   280,   275,   286,   287,   426,   364,    75,
     406,  -145,   140,   427,   407,     5,   504,   505,   506,   512,
     295,   331,   406,     4,   205,   233,   224,   237,    90,    76,
     311,  -124,   311,    90,   311,   300,   530,    58,   154,   155,
     275,    93,   531,     2,     5,   111,    93,   117,    58,   301,
     165,   166,   167,  -126,   168,   169,   112,   314,   408,   411,
     414,   155,     7,     5,   154,     2,     6,     6,     6,   117,
     272,   171,   171,   166,   298,   256,   165,   169,   408,   411,
     168,   330,   257,   258,    16,   316,     7,   544,   214,   259,
     238,   329,    44,   504,   505,   506,   383,   243,    88,    46,
      90,   135,   256,    47,   350,   135,   115,    92,   334,   240,
     258,   135,   117,    93,   111,   376,   259,   337,   344,   490,
     306,   345,   386,   308,   346,   140,     2,   384,   208,   387,
     339,   115,   376,   340,   339,   116,   524,   385,   362,  -146,
     363,   381,   376,   382,   361,   223,   361,   468,   388,   361,
     347,   154,   155,  -354,     6,   409,   412,    46,   364,   171,
     423,    47,   223,   165,   166,   167,   217,   168,   169,    79,
      80,   433,   223,   461,   244,   409,   412,   274,   434,   415,
     408,   411,   313,   496,   315,   457,   500,    46,   205,   497,
     223,   172,   501,   369,   370,   140,   371,    46,    90,   409,
     412,    47,     2,   292,   396,   404,   117,   405,   530,   410,
     413,    93,   556,   140,   449,   223,   453,   269,   396,   405,
     460,   154,   155,   396,   405,   466,   275,   295,   295,   295,
     277,   466,   466,   165,   166,   167,    18,   168,   169,   154,
     155,   289,   463,   548,    18,   551,   553,   555,   276,   277,
      18,   165,   166,   376,   541,   168,   169,   288,   289,   386,
     542,   172,   441,   351,   352,   376,   387,   470,   538,   474,
     539,    90,   481,   485,   385,   483,   489,   469,   276,   473,
     479,   326,   480,   223,   301,   361,   441,     7,   202,   339,
     135,   391,   392,   361,   536,   223,   112,   140,   496,   500,
     471,   334,   230,   244,   497,   501,   417,   418,   419,   230,
     254,    46,    90,    91,   526,    47,  -341,   455,   527,    92,
     550,   552,   554,   154,   155,    93,   362,   381,   477,   478,
     493,   302,   307,    83,    86,   165,   166,   167,   389,   168,
     169,   217,   217,   475,   476,   217,   433,   433,   357,   140,
     433,  -355,   227,   434,   434,   510,   257,   434,   516,   517,
     223,   231,   511,   172,   455,   468,   482,   487,   231,   255,
     509,   424,   513,   288,   368,   154,   155,   117,   514,   503,
     281,   282,   283,   171,     6,   518,   299,   165,   166,   167,
     334,   168,   169,   365,   472,   314,   449,   534,   118,   139,
     462,   410,   413,   309,   296,   366,   367,   368,   300,   537,
      58,    84,   297,   217,   344,   172,   483,   483,   433,   344,
     489,    87,   489,   294,   328,   434,   464,   137,    19,   339,
     339,   361,   545,   339,   278,   339,   279,   361,   213,   546,
      46,    90,   135,   135,    47,   508,   332,   513,    92,   543,
     232,   235,   492,   436,    93,   253,   217,   217,   217,   349,
     520,   433,   433,   433,   355,   458,   522,   523,   434,   434,
     434,   454,     0,   230,     0,     0,   254,     0,   402,   402,
       0,   402,     0,    46,     0,   332,     0,    47,     0,     0,
     230,     0,   402,   402,     0,     0,     0,   402,   402,     0,
     230,     0,     0,   230,   230,   333,    48,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,   230,     0,
       0,     0,    46,    90,   356,     0,    47,   254,   254,   115,
      92,     0,   231,     0,     0,   255,    93,   403,   403,     0,
     403,   140,     0,   230,   333,     0,     0,     0,     0,   231,
       0,   403,   403,     0,     0,     0,   403,   403,     0,   231,
       0,     0,   231,   231,     0,     0,     0,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,   231,     0,   165,
     166,   167,   334,   168,   169,   365,   255,   255,    48,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,   231,   154,   155,   332,   332,   172,     0,     0,
       0,   230,     0,   140,     0,   165,   166,   167,     0,   168,
     169,   141,     0,   230,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,   154,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,   168,   169,     0,     0,     0,
     170,     0,     0,     6,   333,   333,     0,     0,   171,     0,
     231,     0,     0,     0,     0,   402,   402,     0,   140,   172,
       0,     0,   231,     0,     0,     0,   141,     0,   230,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,   154,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,     0,
     168,   169,     0,     5,     0,     0,     0,     0,     6,   389,
       0,     0,     0,     0,   403,   403,     0,   140,     0,     0,
       0,     0,     0,     0,   172,   141,     0,   231,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,   168,
     169,   140,     5,     0,     0,     0,  -365,     6,     0,   141,
       0,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   172,     0,     0,     0,   154,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   168,   169,   140,     5,     0,     0,     0,
    -366,     6,     0,   141,     0,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   172,     0,     0,
       0,   154,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,   168,   169,   140,
       5,     0,     0,     0,  -367,     6,     0,   141,     0,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   172,     0,     0,     0,   154,   155,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,     0,   171,   140,     0,     0,     0,     0,
       0,     0,     0,   141,     0,   172,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,   154,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   140,   168,   169,     0,
       5,     0,     0,     0,   141,     6,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   172,   154,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   140,   168,   169,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,   172,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   140,   168,
     169,     0,     0,     0,     0,     0,   141,     6,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,   172,   154,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,     0,
     168,   169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   140,     0,     0,     0,     0,     0,
       0,     0,   141,     0,   172,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
     154,   155,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   140,   168,   169,     0,     5,
       0,     0,     0,   141,     0,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     172,   154,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   140,   168,   169,     0,
       0,   154,   155,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,     0,   168,   169,     0,
       0,   172,   154,   155,   244,     0,     0,     0,     0,   154,
     155,     0,     0,     0,   165,   166,   167,   334,   168,   169,
     365,   165,   166,   167,   334,   168,   169,   365,     0,     0,
       0,     0,   366,   367,   368,   490,     0,   369,   370,     0,
     371,     0,   172,     0,   369,   370,     0,   371,     0,   172,
     141,   391,   392,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,   154,   155,
     393,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,     0,   168,   169,     0,     0,     0,     0,
     141,   391,   392,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   394,     0,   395,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,     0,   168,   169,     0,     0,     0,     0,
     141,     0,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   394,     0,   395,   154,   155,
     393,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,     0,   168,   169,     0,     0,   141,     0,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   394,   154,   155,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       0,     0,   168,   169,     0,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,   394,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   140,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,     0,     0,     0,   154,
     155,   172,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,   168,   169,   141,   391,   392,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,   154,   155,   393,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
     141,   168,   169,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,   154,   155,
     393,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,   141,   168,   169,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,   154,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,   168,   169,    46,
      90,    91,     0,    47,     0,     0,   115,    92,     2,     0,
     116,     0,   117,    93
  };

  const short
  parser::yycheck_[] =
  {
      25,    26,    27,    28,    29,     9,    26,     9,     0,     0,
      35,    36,    21,    26,   265,    35,    36,    25,   130,   202,
      25,    26,    35,    28,    25,    25,    27,    25,   202,    22,
      35,   101,    27,    25,    29,   105,     0,    47,    21,     0,
      23,    36,    37,    12,     6,   176,    36,    37,    27,    40,
      12,     7,    12,    13,    15,     0,    18,   208,    12,     6,
      21,    63,    64,    65,    58,    67,    68,   251,   199,    19,
     208,    25,    40,   251,   225,    85,   432,   433,   434,   435,
      74,   173,   220,    45,    25,    30,    27,    32,     4,    39,
     123,     0,   125,     4,   127,    99,   110,    99,    66,    67,
      94,    17,   116,    12,    85,    13,    17,    16,   110,    25,
      78,    79,    80,     0,    82,    83,    24,   126,   210,   211,
     212,    67,   108,    85,    66,    12,    90,    90,    90,    16,
     115,    95,    95,    79,    94,    86,    78,    83,   230,   231,
      82,   134,    93,    94,     0,   128,   108,   503,    26,   100,
      46,   134,     8,   509,   510,   511,   339,    35,    14,     3,
       4,   122,    86,     7,   189,   126,    10,    11,    81,    41,
      94,   132,    16,    17,    13,   200,   100,   182,   186,    92,
     102,   186,   202,   105,   189,    40,    12,   361,   189,   202,
     182,    10,   217,   183,   186,    14,   447,   202,   198,    25,
     198,   201,   227,   201,   196,   200,   198,   319,   203,   201,
     189,    66,    67,    89,    90,   210,   211,     3,   349,    95,
     245,     7,   217,    78,    79,    80,   251,    82,    83,    20,
      21,   251,   227,   303,    89,   230,   231,     0,   251,   229,
     332,   333,   125,   427,   127,   270,   430,     3,   189,   427,
     245,   106,   430,   101,   102,    40,   104,     3,     4,   254,
     255,     7,    12,    27,   205,   206,    16,   208,   110,   210,
     211,    17,   114,    40,   265,   270,   267,   268,   219,   220,
     271,    66,    67,   224,   225,   318,   280,   281,   282,   283,
      23,   324,   325,    78,    79,    80,     0,    82,    83,    66,
      67,     9,   311,   520,     8,   522,   523,   524,    22,    23,
      14,    78,    79,   338,   498,    82,    83,     8,     9,   339,
     498,   106,   107,    64,    65,   350,   339,   320,   485,   322,
     487,     4,   340,   341,   339,   340,   341,   320,    22,   322,
     340,    15,   340,   338,    25,   337,   107,   108,   340,   341,
     311,    49,    50,   345,   466,   350,    24,    40,   542,   543,
     321,    81,    29,    89,   542,   543,    42,    43,    44,    36,
      37,     3,     4,     5,   109,     7,    41,   112,   113,    11,
     522,   523,   524,    66,    67,    17,   386,   387,   324,   325,
     415,   461,   462,    12,    13,    78,    79,    80,    91,    82,
      83,   426,   427,   322,   323,   430,   426,   427,    63,    40,
     430,    89,   437,   426,   427,   435,    93,   430,   439,   440,
     415,    29,   435,   106,   112,   537,   340,   341,    36,    37,
     435,    88,   437,     8,    98,    66,    67,    16,    99,   431,
      63,    64,    65,    95,    90,   117,    97,    78,    79,    80,
      81,    82,    83,    84,   322,   464,   447,   111,    21,    24,
     303,   402,   403,   110,    94,    96,    97,    98,   472,   466,
     472,    12,    94,   498,   482,   106,   481,   482,   498,   487,
     485,    13,   487,    72,   132,   498,   311,    22,     0,   481,
     482,   483,   512,   485,    62,   487,    62,   489,    26,   512,
       3,     4,   463,   464,     7,   435,   173,   512,    11,   498,
      30,    32,   350,   251,    17,    37,   541,   542,   543,   189,
     447,   541,   542,   543,   191,   270,   447,   447,   541,   542,
     543,   268,    -1,   200,    -1,    -1,   203,    -1,   205,   206,
      -1,   208,    -1,     3,    -1,   212,    -1,     7,    -1,    -1,
     217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,    -1,
     227,    -1,    -1,   230,   231,   173,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,   245,    -1,
      -1,    -1,     3,     4,   192,    -1,     7,   254,   255,    10,
      11,    -1,   200,    -1,    -1,   203,    17,   205,   206,    -1,
     208,    40,    -1,   270,   212,    -1,    -1,    -1,    -1,   217,
      -1,   219,   220,    -1,    -1,    -1,   224,   225,    -1,   227,
      -1,    -1,   230,   231,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    78,
      79,    80,    81,    82,    83,    84,   254,   255,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,   270,    66,    67,   332,   333,   106,    -1,    -1,
      -1,   338,    -1,    40,    -1,    78,    79,    80,    -1,    82,
      83,    48,    -1,   350,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,    -1,    -1,    -1,
      87,    -1,    -1,    90,   332,   333,    -1,    -1,    95,    -1,
     338,    -1,    -1,    -1,    -1,   402,   403,    -1,    40,   106,
      -1,    -1,   350,    -1,    -1,    -1,    48,    -1,   415,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,    91,
      -1,    -1,    -1,    -1,   402,   403,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    48,    -1,   415,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    82,
      83,    40,    85,    -1,    -1,    -1,    89,    90,    -1,    48,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   106,    -1,    -1,    -1,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    82,    83,    40,    85,    -1,    -1,    -1,
      89,    90,    -1,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   106,    -1,    -1,
      -1,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    82,    83,    40,
      85,    -1,    -1,    -1,    89,    90,    -1,    48,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   106,    -1,    -1,    -1,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    95,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,   106,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    40,    82,    83,    -1,
      85,    -1,    -1,    -1,    48,    90,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,   106,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    40,    82,    83,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,   106,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    40,    82,
      83,    -1,    -1,    -1,    -1,    -1,    48,    90,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,   106,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,   106,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    40,    82,    83,    -1,    85,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
     106,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    40,    82,    83,    -1,
      -1,    66,    67,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    -1,    82,    83,    -1,
      -1,   106,    66,    67,    89,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    96,    97,    98,    92,    -1,   101,   102,    -1,
     104,    -1,   106,    -1,   101,   102,    -1,   104,    -1,   106,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,   103,    -1,   105,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,   103,    -1,   105,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    82,    83,    -1,    -1,    48,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,   103,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    82,    83,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,   106,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      48,    82,    83,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    48,    82,    83,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    82,    83,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    11,    12,    -1,
      14,    -1,    16,    17
  };

  const short
  parser::yystos_[] =
  {
       0,     6,    12,    18,    45,    85,    90,   108,   139,   140,
     141,   145,   146,   147,   182,   183,   184,   187,   188,   189,
     190,   193,   194,   195,   196,   250,   251,   252,   253,   254,
     264,   265,   284,   285,   296,   297,   298,   299,   306,   330,
     332,   334,   344,   348,   184,   190,     3,     7,    26,    28,
      29,    30,    31,    32,    33,    34,    35,    36,   119,   136,
     148,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     163,   164,   165,   166,   205,    19,    39,   199,   200,    20,
      21,   201,   202,   157,   158,   160,   157,   159,   184,   190,
       4,     5,    11,    17,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   148,   149,
     177,    13,    24,   191,   192,    10,    14,    16,   129,   149,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   178,
     179,   181,   185,   186,   189,   190,   169,   178,   149,   139,
      40,    48,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    66,    67,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    82,    83,
      87,    95,   106,   206,   207,   208,   209,   211,   212,   213,
     214,   215,   216,   218,   219,   220,   221,   223,   236,   237,
     238,   239,   240,   241,   242,   255,   257,   258,   260,   261,
     262,   263,   264,   266,   267,   275,   276,   277,   283,   300,
     312,   313,   314,   236,   256,   257,   260,   262,   263,   275,
     283,   258,   262,   267,   275,   283,   257,   262,   232,   262,
     312,   313,   250,   306,    47,   254,   287,   306,    46,   286,
      41,   288,   292,   256,    89,   228,   235,   260,   262,   267,
     293,   294,   267,   293,   312,   313,    86,    93,    94,   100,
     301,   302,   303,   304,   319,   326,   327,   328,   333,   344,
     345,   346,   115,   341,     0,   136,    22,    23,   203,   204,
     119,   205,   205,   205,   203,   204,   119,   119,     8,     9,
     161,   162,    27,   167,   163,   136,   154,   155,   160,   120,
     148,    25,   126,   133,   134,   135,   134,   126,   134,   132,
     170,   133,   137,   137,   170,   137,   149,   142,   143,   144,
     150,   151,   184,   188,   197,   198,    15,   180,   172,   149,
     169,   223,   312,   313,    81,   268,   216,   257,   262,   264,
     228,   229,   230,   231,   216,   257,   257,   258,   259,   261,
     262,    64,    65,   310,   311,   312,   313,    63,   309,   207,
     208,   264,   207,   208,   268,    84,    96,    97,    98,   101,
     102,   104,   224,   225,   226,   227,   262,   268,   269,   270,
     274,   207,   208,   212,   219,   257,   260,   263,   267,    91,
     272,    49,    50,    68,   103,   105,   275,   278,   279,   280,
     281,   282,   312,   313,   275,   275,   278,   279,   223,   267,
     275,   223,   267,   275,   223,   228,   233,    42,    43,    44,
     289,   290,   291,   262,    88,   273,   243,   246,   247,   248,
     249,   256,   257,   260,   263,   264,   272,   295,   306,   307,
     308,   107,   315,   316,   323,   324,   329,   331,   335,   344,
     346,   317,   322,   344,   345,   112,   343,   262,   316,   321,
     344,   126,   130,   170,   174,   142,   133,   138,   142,   149,
     169,   190,   124,   149,   169,   185,   185,   138,   138,   207,
     208,   216,   221,   257,   210,   216,   217,   221,   222,   257,
      92,   271,   271,   262,   243,   246,   243,   246,   228,   234,
     243,   246,   245,   264,   295,   295,   295,   244,   248,   257,
     260,   263,   295,   257,    99,   305,   234,   234,   117,   325,
     315,   320,   324,   329,   346,   347,   109,   113,   340,   342,
     110,   116,   336,   339,   111,   338,   142,   144,   210,   210,
       0,   243,   246,   249,   295,   260,   263,   318,   322,   344,
     318,   322,   318,   322,   318,   322,   114,   337
  };

  const short
  parser::yyr1_[] =
  {
       0,   118,   119,   120,   121,   122,   123,   124,   124,   124,
     125,   126,   126,   127,   127,   127,   128,   129,   130,   130,
     131,   131,   132,   132,   133,   134,   134,   135,   136,   137,
     137,   138,   138,   139,   139,   139,   139,   140,   141,   142,
     142,   142,   142,   142,   143,   143,   143,   144,   144,   145,
     146,   147,   148,   148,   149,   149,   149,   150,   150,   151,
     152,   152,   152,   152,   152,   152,   153,   154,   155,   156,
     156,   156,   156,   156,   157,   158,   159,   160,   161,   162,
     163,   163,   164,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   166,   167,   168,   169,   170,   170,   171,   171,
     171,   172,   172,   173,   174,   174,   175,   176,   177,   178,
     178,   178,   179,   180,   181,   182,   182,   183,   184,   184,
     185,   186,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   188,   189,   190,   191,   192,   193,   194,
     194,   195,   196,   196,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   205,   206,   207,   208,   209,   210,
     211,   211,   211,   212,   212,   212,   213,   213,   213,   214,
     215,   215,   216,   216,   217,   218,   218,   218,   218,   218,
     218,   219,   220,   221,   221,   222,   223,   223,   223,   224,
     225,   226,   227,   228,   229,   229,   229,   229,   230,   230,
     230,   231,   231,   232,   233,   234,   234,   234,   235,   236,
     236,   236,   237,   237,   238,   239,   240,   241,   242,   243,
     243,   243,   244,   244,   245,   246,   247,   247,   247,   248,
     248,   248,   248,   249,   249,   249,   249,   249,   249,   250,
     250,   250,   251,   252,   253,   254,   255,   256,   256,   256,
     256,   257,   257,   257,   257,   257,   257,   258,   258,   258,
     258,   258,   258,   259,   259,   260,   261,   262,   262,   262,
     262,   263,   263,   264,   265,   266,   267,   267,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   275,   275,   275,
     275,   275,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   277,   278,   279,   280,   281,   282,   283,   283,
     284,   284,   285,   286,   287,   288,   288,   288,   289,   290,
     291,   292,   293,   293,   293,   293,   293,   294,   294,   295,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   297,   298,   298,   299,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   307,   308,   309,   310,
     311,   312,   312,   312,   313,   313,   313,   314,   314,   315,
     316,   317,   318,   319,   320,   320,   320,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   328,   328,   328,   329,
     330,   331,   331,   332,   332,   333,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   347,   347,   347,   348,   348,   348
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
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     0,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     1
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
  "t_HUN_CON_Stem", "t_HUN_Punct_Stem", "t_HUN_Punct_FullStop",
  "t_HUN_Punct_QuestionMark", "t_HUN_Punct_ExclamationMark",
  "t_HUN_Pronoun_Stem", "t_HUN_Pronoun_Int", "t_HUN_Pronoun_Nom",
  "t_HUN_Num_Stem", "t_HUN_Num_Ik", "t_HUN_Num_Par", "t_HUN_Num_Npref1",
  "t_HUN_Num_Npref2", "t_HUN_Num_Npref3", "t_HUN_Num_Npref4",
  "t_HUN_Num_Npref5", "t_HUN_Num_Npref6", "t_HUN_Num_Npref7",
  "t_HUN_Num_Npref8", "t_HUN_Num_Npref9", "t_HUN_Num_Npref1nn",
  "t_HUN_Num_Npref1nnn", "t_HUN_Det_Stem", "t_HUN_Det_Def",
  "t_HUN_Det_fwVowel", "t_HUN_Det_fwConsonant", "t_HUN_CON_swVowel",
  "t_HUN_CON_swConsonant", "t_HUN_Num_Acc", "t_HUN_Num_Npref1n",
  "t_HUN_Num_Npref2n", "t_HUN_Num_Npref3n", "t_HUN_Num_Npref4n",
  "t_HUN_Num_Npref5n", "t_HUN_Num_Npref6n", "t_HUN_Num_Npref7n",
  "t_HUN_Num_Npref8n", "t_HUN_Num_Npref9n", "t_HUN_Num_swVowel",
  "t_HUN_Num_swConsonant", "t_HUN_Noun_Stem", "t_HUN_Noun_Acc",
  "t_HUN_Noun_swVowel", "t_HUN_Noun_swConsonant", "t_HUN_CON_Acc",
  "t_HUN_Verb_Stem", "t_HUN_Verb_ConjDefSg2", "t_HUN_Vbpfx_Stem",
  "t_HUN_Noun_Relative", "t_HUN_Conj_Stem", "t_HUN_Neg_Stem",
  "t_HUN_Noun_Plur", "t_HUN_Noun_Ine", "t_HUN_Verb_IndefSg3",
  "t_HUN_Verb_ConjIndefSg2", "t_HUN_Adj_Stem", "t_HUN_CON_Sub",
  "t_HUN_Noun_Sub", "t_HUN_CON_Ins", "t_HUN_Verb_IndefPl3",
  "t_HUN_Verb_DefSg1", "t_HUN_Noun_Dat", "t_HUN_CON_Dat", "t_HUN_Num_Dat",
  "t_HUN_Noun_Del", "t_HUN_Num_Del", "t_HUN_Noun_Pref", "t_JSON_CON_Stem",
  "t_JSON_Punct_Stem", "t_JSON_Punct_Dot", "t_JSON_Punct_Comma",
  "t_JSON_Punct_Colon", "t_JSON_Punct_Quotes",
  "t_JSON_Punct_OpeningSBracket", "t_JSON_Punct_ClosingSBracket",
  "t_JSON_Punct_OpeningCBracket", "t_JSON_Punct_ClosingCBracket",
  "t_JSON_Punct_Relative", "$accept", "ENG_1Con", "ENG_A", "ENG_A0NEG",
  "ENG_ANEG", "ENG_ANEG_Stem", "ENG_AP", "ENG_A_Stem", "ENG_Abar1",
  "ENG_Abar2", "ENG_Adv", "ENG_AdvP", "ENG_Alist", "ENG_CAP", "ENG_CNP",
  "ENG_CONJ", "ENG_CONJA", "ENG_CONJ_Stem", "ENG_Con", "ENG_ConjPVP",
  "ENG_ConjV", "ENG_DP", "ENG_Def_Det", "ENG_Det_stem", "ENG_IVP",
  "ENG_IVPConj", "ENG_IVPlist", "ENG_Indef_Det", "ENG_Indef_Det_a",
  "ENG_Indef_Det_an", "ENG_N", "ENG_NP", "ENG_NV", "ENG_NV_Aux",
  "ENG_N_Pl", "ENG_N_Pl_0Con", "ENG_N_Pl_0Con_swC", "ENG_N_Pl_0Con_swV",
  "ENG_N_Sg", "ENG_N_Sg_0Con", "ENG_N_Sg_0Con_swC", "ENG_N_Sg_0Con_swV",
  "ENG_N_Stem", "ENG_N_lfea_Pl", "ENG_N_lfea_Sg", "ENG_Num", "ENG_Num_Ord",
  "ENG_Num_Pref", "ENG_Num_Stem", "ENG_Num_lfea_Ord", "ENG_PNVPbar",
  "ENG_PP", "ENG_PVP", "ENG_PVPConj", "ENG_PVPbar", "ENG_PVPhead",
  "ENG_PVPlist", "ENG_PVPlisthead", "ENG_Prep", "ENG_QPro", "ENG_RC",
  "ENG_RPro", "ENG_RPro_lfea_relative", "ENG_RPro_stem", "ENG_TP",
  "ENG_Tense_particle", "ENG_V", "ENG_VNEG", "ENG_VNEG_Stem", "ENG_VP",
  "ENG_V_Aux", "ENG_V_Ger", "ENG_V_Stem", "ENG_V_lfea_aux",
  "ENG_V_lfea_ger", "ENG_Vbar1", "ENG_Vbar2", "ENG_Vbar3", "ENG_Vbar4",
  "ENG_Vhead", "ENG_Vlisthead", "ENG_lfea_DefDet", "ENG_lfea_IndefDet",
  "ENG_lfea_fwConsonant", "ENG_lfea_fwVowel", "ENG_lfea_swConsonant",
  "ENG_lfea_swVowel", "ENG_nCon", "HUN_1Con", "HUN_A0NEG", "HUN_ANEG",
  "HUN_ANP", "HUN_AN_Acc", "HUN_AP", "HUN_Abar1", "HUN_Abar1N",
  "HUN_Abar2", "HUN_Abar2N", "HUN_Abar3", "HUN_Abar3_End", "HUN_Abar4",
  "HUN_Adj", "HUN_Adj_Stem", "HUN_Alist", "HUN_Alist_End", "HUN_Con",
  "HUN_Con_lfea_Acc", "HUN_Con_lfea_Dat", "HUN_Con_lfea_Ins",
  "HUN_Con_lfea_Sub", "HUN_Conj", "HUN_ConjA", "HUN_ConjA_End",
  "HUN_ConjAlist", "HUN_ConjN", "HUN_ConjNbar1", "HUN_ConjV",
  "HUN_Conj_Stem", "HUN_DP", "HUN_DPbar", "HUN_Def_Det", "HUN_Def_Det_a",
  "HUN_Def_Det_az", "HUN_Det_stem", "HUN_Empty", "HUN_INVP", "HUN_INVPbar",
  "HUN_INVPbar2", "HUN_IVP", "HUN_IVPConj", "HUN_IVPbar", "HUN_IVPlist",
  "HUN_ImpVerb", "HUN_ImpVerbPfx", "HUN_ImpVerb_N_Acc",
  "HUN_ImpVerb_N_Dat", "HUN_IndVerb", "HUN_NAbar1", "HUN_NP", "HUN_N_Acc",
  "HUN_N_Dat", "HUN_N_Ine", "HUN_N_Ins", "HUN_N_Pl", "HUN_N_Sg",
  "HUN_N_Sub", "HUN_Neg", "HUN_Neg_Stem", "HUN_Noun_Pref", "HUN_Noun_Stem",
  "HUN_Noun_lfea_Acc", "HUN_Noun_lfea_Dat", "HUN_Noun_lfea_Del",
  "HUN_Noun_lfea_Ine", "HUN_Noun_lfea_Plur", "HUN_Noun_lfea_Relative",
  "HUN_Noun_lfea_Sub", "HUN_Num", "HUN_Num_Pref", "HUN_Num_Stem",
  "HUN_Num_lfea_Acc", "HUN_Num_lfea_Dat", "HUN_Num_lfea_Del",
  "HUN_Num_lfea_Ik", "HUN_Num_lfea_Par", "HUN_Nums", "HUN_Pron_Int",
  "HUN_Pron_Stem", "HUN_Pron_lfea_Int", "HUN_Pron_lfea_Nom", "HUN_Punct",
  "HUN_Punct_ExclamationMark", "HUN_Punct_FullStop",
  "HUN_Punct_QuestionMark", "HUN_Punct_Stem", "HUN_RC", "HUN_RPro",
  "HUN_V", "HUN_VP", "HUN_Vbar1", "HUN_Vbar2", "HUN_Vbar3", "HUN_Vbpfx",
  "HUN_Verb_lfea_ConjDefSg2", "HUN_Verb_lfea_ConjIndefSg2",
  "HUN_Verb_lfea_DefSg1", "HUN_Verb_lfea_InDefSg3",
  "HUN_Verb_lfea_IndefPl3", "HUN_Verb_stem", "HUN_Vhead", "HUN_Vlisthead",
  "HUN_lfea_DefDet", "HUN_lfea_fwConsonant", "HUN_lfea_fwVowel",
  "HUN_lfea_swConsonant", "HUN_lfea_swVowel", "HUN_nCon", "JSON_Array",
  "JSON_CON", "JSON_ClosingCBracket", "JSON_ClosingSBracket",
  "JSON_Closing_Key_Value_Pair", "JSON_Closing_Value_Element",
  "JSON_Colon", "JSON_Comma", "JSON_Dot", "JSON_Dot_Relative",
  "JSON_Dot_lfea_relative", "JSON_Key", "JSON_Key_Value_List_Element",
  "JSON_Key_Value_Pair", "JSON_Number", "JSON_Object", "JSON_Open_Array",
  "JSON_Open_Object", "JSON_Open_String", "JSON_OpeningCBracket",
  "JSON_OpeningSBracket", "JSON_Punct_ClosingCBracket",
  "JSON_Punct_ClosingSBracket", "JSON_Punct_Colon", "JSON_Punct_Comma",
  "JSON_Punct_Dot", "JSON_Punct_OpeningCBracket",
  "JSON_Punct_OpeningSBracket", "JSON_Punct_Quotes", "JSON_Punct_Stem",
  "JSON_Quotes", "JSON_String", "JSON_Value_List_Element", "S", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   159,   159,   167,   175,   183,   191,   200,   207,   214,
     222,   231,   238,   247,   255,   263,   272,   281,   289,   297,
     306,   314,   323,   331,   339,   347,   355,   364,   373,   382,
     390,   399,   407,   416,   424,   432,   440,   449,   458,   467,
     475,   483,   491,   500,   510,   518,   526,   535,   543,   552,
     561,   570,   579,   586,   594,   601,   608,   617,   625,   634,
     643,   650,   658,   665,   673,   680,   688,   697,   706,   715,
     722,   729,   737,   744,   753,   762,   771,   780,   789,   798,
     807,   815,   823,   832,   840,   848,   856,   864,   872,   880,
     888,   896,   905,   914,   923,   932,   941,   948,   956,   964,
     972,   981,   988,   996,  1004,  1012,  1021,  1029,  1038,  1047,
    1055,  1063,  1072,  1081,  1090,  1099,  1107,  1115,  1124,  1131,
    1139,  1147,  1156,  1163,  1171,  1179,  1187,  1195,  1203,  1210,
    1218,  1226,  1234,  1243,  1252,  1261,  1270,  1279,  1288,  1297,
    1305,  1314,  1323,  1331,  1339,  1347,  1355,  1363,  1372,  1381,
    1390,  1399,  1408,  1417,  1425,  1434,  1442,  1450,  1459,  1468,
    1475,  1483,  1491,  1500,  1508,  1516,  1525,  1533,  1541,  1550,
    1558,  1565,  1573,  1580,  1588,  1597,  1604,  1611,  1618,  1626,
    1634,  1642,  1650,  1659,  1667,  1676,  1685,  1693,  1701,  1710,
    1719,  1728,  1737,  1746,  1754,  1762,  1770,  1778,  1787,  1795,
    1803,  1812,  1820,  1829,  1838,  1847,  1855,  1863,  1872,  1881,
    1889,  1897,  1906,  1914,  1923,  1932,  1941,  1950,  1959,  1966,
    1974,  1982,  1991,  1999,  2008,  2017,  2025,  2033,  2041,  2050,
    2058,  2066,  2074,  2083,  2091,  2099,  2107,  2115,  2123,  2132,
    2140,  2148,  2157,  2166,  2175,  2184,  2193,  2202,  2209,  2216,
    2223,  2231,  2239,  2247,  2255,  2263,  2271,  2280,  2288,  2296,
    2304,  2312,  2320,  2329,  2337,  2346,  2355,  2364,  2371,  2379,
    2386,  2394,  2402,  2411,  2419,  2428,  2437,  2445,  2453,  2462,
    2471,  2480,  2489,  2498,  2507,  2516,  2525,  2533,  2541,  2549,
    2556,  2564,  2573,  2581,  2589,  2597,  2605,  2613,  2621,  2629,
    2637,  2645,  2653,  2661,  2669,  2677,  2685,  2693,  2701,  2709,
    2717,  2725,  2734,  2743,  2752,  2761,  2770,  2779,  2788,  2796,
    2805,  2813,  2822,  2831,  2840,  2849,  2857,  2865,  2874,  2883,
    2892,  2901,  2910,  2918,  2926,  2934,  2942,  2951,  2959,  2968,
    2977,  2985,  2993,  3001,  3009,  3017,  3025,  3033,  3041,  3049,
    3057,  3065,  3073,  3082,  3091,  3099,  3108,  3116,  3125,  3134,
    3143,  3152,  3161,  3170,  3179,  3188,  3195,  3203,  3211,  3220,
    3229,  3238,  3246,  3254,  3263,  3271,  3279,  3288,  3296,  3305,
    3314,  3323,  3332,  3341,  3350,  3358,  3366,  3374,  3383,  3392,
    3401,  3410,  3419,  3428,  3437,  3446,  3454,  3462,  3470,  3479,
    3487,  3499,  3507,  3515,  3523,  3531,  3539,  3548,  3557,  3566,
    3575,  3584,  3593,  3602,  3611,  3620,  3629,  3638,  3647,  3656,
    3665,  3673,  3681,  3689,  3698,  3705,  3732
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
  parser::yytranslate_ (int t) YY_NOEXCEPT
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117
    };
    // Last valid token kind.
    const int code_max = 372;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 8111 "build/hi_desktop/hi.y.cpp"

#line 3739 "build/hi_desktop/hi.y"

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
			}
			locale=std::locale();
			transgraph::clear_node_functor_map();
			if(modified_human_input.empty()==true){
				lex=new lexer(human_input,language,locale,false,token_paths);
				token_paths->assign_lexer(lex);
			}
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"lexer started");
			sparser=new interpreter(toa);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"interpreter started");
			bool delete_lexer=true;
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
				if(crh>0){
					if(modified_human_input.empty()==true){
						modified_human_input=token_paths->add_context_reference_word(crh,human_input,main_verb_lexeme);
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
									modified_human_input=token_paths->modify_human_input(word,human_input);
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
								modified_human_input=human_input;
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
										modified_human_input=token_paths->modify_human_input(word,human_input);
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
									modified_human_input=human_input;
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
	try{
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
	}
	catch(std::runtime_error& exception){//Catch underived exceptions thrown with string based messages
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"runtime error:"+std::string(exception.what()));
		return NULL;
	}
	catch(...){
		logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"unexpected error ...");
		return NULL;
	}
	return analysischr;
}
#ifdef __EMSCRIPTEN__
}
#endif
