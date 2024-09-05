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
    t_JSON_Punct_Hash = 364,       // t_JSON_Punct_Hash
    t_JSON_Punct_Comma = 365,      // t_JSON_Punct_Comma
    t_JSON_Punct_Colon = 366,      // t_JSON_Punct_Colon
    t_JSON_Punct_Quotes = 367,     // t_JSON_Punct_Quotes
    t_JSON_Punct_OpeningSBracket = 368, // t_JSON_Punct_OpeningSBracket
    t_JSON_Punct_ClosingSBracket = 369, // t_JSON_Punct_ClosingSBracket
    t_JSON_Punct_Relative = 370    // t_JSON_Punct_Relative
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
        YYNTOKENS = 116, ///< Number of tokens.
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
        S_t_JSON_Punct_Hash = 109,               // t_JSON_Punct_Hash
        S_t_JSON_Punct_Comma = 110,              // t_JSON_Punct_Comma
        S_t_JSON_Punct_Colon = 111,              // t_JSON_Punct_Colon
        S_t_JSON_Punct_Quotes = 112,             // t_JSON_Punct_Quotes
        S_t_JSON_Punct_OpeningSBracket = 113,    // t_JSON_Punct_OpeningSBracket
        S_t_JSON_Punct_ClosingSBracket = 114,    // t_JSON_Punct_ClosingSBracket
        S_t_JSON_Punct_Relative = 115,           // t_JSON_Punct_Relative
        S_YYACCEPT = 116,                        // $accept
        S_ENG_1Con = 117,                        // ENG_1Con
        S_ENG_A = 118,                           // ENG_A
        S_ENG_A0NEG = 119,                       // ENG_A0NEG
        S_ENG_ANEG = 120,                        // ENG_ANEG
        S_ENG_ANEG_Stem = 121,                   // ENG_ANEG_Stem
        S_ENG_AP = 122,                          // ENG_AP
        S_ENG_A_Stem = 123,                      // ENG_A_Stem
        S_ENG_Abar1 = 124,                       // ENG_Abar1
        S_ENG_Abar2 = 125,                       // ENG_Abar2
        S_ENG_Adv = 126,                         // ENG_Adv
        S_ENG_AdvP = 127,                        // ENG_AdvP
        S_ENG_Alist = 128,                       // ENG_Alist
        S_ENG_CAP = 129,                         // ENG_CAP
        S_ENG_CNP = 130,                         // ENG_CNP
        S_ENG_CONJ = 131,                        // ENG_CONJ
        S_ENG_CONJA = 132,                       // ENG_CONJA
        S_ENG_CONJ_Stem = 133,                   // ENG_CONJ_Stem
        S_ENG_Con = 134,                         // ENG_Con
        S_ENG_ConjPVP = 135,                     // ENG_ConjPVP
        S_ENG_ConjV = 136,                       // ENG_ConjV
        S_ENG_DP = 137,                          // ENG_DP
        S_ENG_Def_Det = 138,                     // ENG_Def_Det
        S_ENG_Det_stem = 139,                    // ENG_Det_stem
        S_ENG_IVP = 140,                         // ENG_IVP
        S_ENG_IVPConj = 141,                     // ENG_IVPConj
        S_ENG_IVPlist = 142,                     // ENG_IVPlist
        S_ENG_Indef_Det = 143,                   // ENG_Indef_Det
        S_ENG_Indef_Det_a = 144,                 // ENG_Indef_Det_a
        S_ENG_Indef_Det_an = 145,                // ENG_Indef_Det_an
        S_ENG_N = 146,                           // ENG_N
        S_ENG_NP = 147,                          // ENG_NP
        S_ENG_NV = 148,                          // ENG_NV
        S_ENG_NV_Aux = 149,                      // ENG_NV_Aux
        S_ENG_N_Pl = 150,                        // ENG_N_Pl
        S_ENG_N_Pl_0Con = 151,                   // ENG_N_Pl_0Con
        S_ENG_N_Pl_0Con_swC = 152,               // ENG_N_Pl_0Con_swC
        S_ENG_N_Pl_0Con_swV = 153,               // ENG_N_Pl_0Con_swV
        S_ENG_N_Sg = 154,                        // ENG_N_Sg
        S_ENG_N_Sg_0Con = 155,                   // ENG_N_Sg_0Con
        S_ENG_N_Sg_0Con_swC = 156,               // ENG_N_Sg_0Con_swC
        S_ENG_N_Sg_0Con_swV = 157,               // ENG_N_Sg_0Con_swV
        S_ENG_N_Stem = 158,                      // ENG_N_Stem
        S_ENG_N_lfea_Pl = 159,                   // ENG_N_lfea_Pl
        S_ENG_N_lfea_Sg = 160,                   // ENG_N_lfea_Sg
        S_ENG_Num = 161,                         // ENG_Num
        S_ENG_Num_Ord = 162,                     // ENG_Num_Ord
        S_ENG_Num_Pref = 163,                    // ENG_Num_Pref
        S_ENG_Num_Stem = 164,                    // ENG_Num_Stem
        S_ENG_Num_lfea_Ord = 165,                // ENG_Num_lfea_Ord
        S_ENG_PNVPbar = 166,                     // ENG_PNVPbar
        S_ENG_PP = 167,                          // ENG_PP
        S_ENG_PVP = 168,                         // ENG_PVP
        S_ENG_PVPConj = 169,                     // ENG_PVPConj
        S_ENG_PVPbar = 170,                      // ENG_PVPbar
        S_ENG_PVPhead = 171,                     // ENG_PVPhead
        S_ENG_PVPlist = 172,                     // ENG_PVPlist
        S_ENG_PVPlisthead = 173,                 // ENG_PVPlisthead
        S_ENG_Prep = 174,                        // ENG_Prep
        S_ENG_QPro = 175,                        // ENG_QPro
        S_ENG_RC = 176,                          // ENG_RC
        S_ENG_RPro = 177,                        // ENG_RPro
        S_ENG_RPro_lfea_relative = 178,          // ENG_RPro_lfea_relative
        S_ENG_RPro_stem = 179,                   // ENG_RPro_stem
        S_ENG_TP = 180,                          // ENG_TP
        S_ENG_Tense_particle = 181,              // ENG_Tense_particle
        S_ENG_V = 182,                           // ENG_V
        S_ENG_VNEG = 183,                        // ENG_VNEG
        S_ENG_VNEG_Stem = 184,                   // ENG_VNEG_Stem
        S_ENG_VP = 185,                          // ENG_VP
        S_ENG_V_Aux = 186,                       // ENG_V_Aux
        S_ENG_V_Ger = 187,                       // ENG_V_Ger
        S_ENG_V_Stem = 188,                      // ENG_V_Stem
        S_ENG_V_lfea_aux = 189,                  // ENG_V_lfea_aux
        S_ENG_V_lfea_ger = 190,                  // ENG_V_lfea_ger
        S_ENG_Vbar1 = 191,                       // ENG_Vbar1
        S_ENG_Vbar2 = 192,                       // ENG_Vbar2
        S_ENG_Vbar3 = 193,                       // ENG_Vbar3
        S_ENG_Vbar4 = 194,                       // ENG_Vbar4
        S_ENG_Vhead = 195,                       // ENG_Vhead
        S_ENG_Vlisthead = 196,                   // ENG_Vlisthead
        S_ENG_lfea_DefDet = 197,                 // ENG_lfea_DefDet
        S_ENG_lfea_IndefDet = 198,               // ENG_lfea_IndefDet
        S_ENG_lfea_fwConsonant = 199,            // ENG_lfea_fwConsonant
        S_ENG_lfea_fwVowel = 200,                // ENG_lfea_fwVowel
        S_ENG_lfea_swConsonant = 201,            // ENG_lfea_swConsonant
        S_ENG_lfea_swVowel = 202,                // ENG_lfea_swVowel
        S_ENG_nCon = 203,                        // ENG_nCon
        S_HUN_1Con = 204,                        // HUN_1Con
        S_HUN_A0NEG = 205,                       // HUN_A0NEG
        S_HUN_ANEG = 206,                        // HUN_ANEG
        S_HUN_ANP = 207,                         // HUN_ANP
        S_HUN_AN_Acc = 208,                      // HUN_AN_Acc
        S_HUN_AP = 209,                          // HUN_AP
        S_HUN_Abar1 = 210,                       // HUN_Abar1
        S_HUN_Abar1N = 211,                      // HUN_Abar1N
        S_HUN_Abar2 = 212,                       // HUN_Abar2
        S_HUN_Abar2N = 213,                      // HUN_Abar2N
        S_HUN_Abar3 = 214,                       // HUN_Abar3
        S_HUN_Abar3_End = 215,                   // HUN_Abar3_End
        S_HUN_Abar4 = 216,                       // HUN_Abar4
        S_HUN_Adj = 217,                         // HUN_Adj
        S_HUN_Adj_Stem = 218,                    // HUN_Adj_Stem
        S_HUN_Alist = 219,                       // HUN_Alist
        S_HUN_Alist_End = 220,                   // HUN_Alist_End
        S_HUN_Con = 221,                         // HUN_Con
        S_HUN_Con_lfea_Acc = 222,                // HUN_Con_lfea_Acc
        S_HUN_Con_lfea_Dat = 223,                // HUN_Con_lfea_Dat
        S_HUN_Con_lfea_Ins = 224,                // HUN_Con_lfea_Ins
        S_HUN_Con_lfea_Sub = 225,                // HUN_Con_lfea_Sub
        S_HUN_Conj = 226,                        // HUN_Conj
        S_HUN_ConjA = 227,                       // HUN_ConjA
        S_HUN_ConjA_End = 228,                   // HUN_ConjA_End
        S_HUN_ConjAlist = 229,                   // HUN_ConjAlist
        S_HUN_ConjN = 230,                       // HUN_ConjN
        S_HUN_ConjNbar1 = 231,                   // HUN_ConjNbar1
        S_HUN_ConjV = 232,                       // HUN_ConjV
        S_HUN_Conj_Stem = 233,                   // HUN_Conj_Stem
        S_HUN_DP = 234,                          // HUN_DP
        S_HUN_DPbar = 235,                       // HUN_DPbar
        S_HUN_Def_Det = 236,                     // HUN_Def_Det
        S_HUN_Def_Det_a = 237,                   // HUN_Def_Det_a
        S_HUN_Def_Det_az = 238,                  // HUN_Def_Det_az
        S_HUN_Det_stem = 239,                    // HUN_Det_stem
        S_HUN_Empty = 240,                       // HUN_Empty
        S_HUN_INVP = 241,                        // HUN_INVP
        S_HUN_INVPbar = 242,                     // HUN_INVPbar
        S_HUN_INVPbar2 = 243,                    // HUN_INVPbar2
        S_HUN_IVP = 244,                         // HUN_IVP
        S_HUN_IVPConj = 245,                     // HUN_IVPConj
        S_HUN_IVPbar = 246,                      // HUN_IVPbar
        S_HUN_IVPlist = 247,                     // HUN_IVPlist
        S_HUN_ImpVerb = 248,                     // HUN_ImpVerb
        S_HUN_ImpVerbPfx = 249,                  // HUN_ImpVerbPfx
        S_HUN_ImpVerb_N_Acc = 250,               // HUN_ImpVerb_N_Acc
        S_HUN_ImpVerb_N_Dat = 251,               // HUN_ImpVerb_N_Dat
        S_HUN_IndVerb = 252,                     // HUN_IndVerb
        S_HUN_NAbar1 = 253,                      // HUN_NAbar1
        S_HUN_NP = 254,                          // HUN_NP
        S_HUN_N_Acc = 255,                       // HUN_N_Acc
        S_HUN_N_Dat = 256,                       // HUN_N_Dat
        S_HUN_N_Ine = 257,                       // HUN_N_Ine
        S_HUN_N_Ins = 258,                       // HUN_N_Ins
        S_HUN_N_Pl = 259,                        // HUN_N_Pl
        S_HUN_N_Sg = 260,                        // HUN_N_Sg
        S_HUN_N_Sub = 261,                       // HUN_N_Sub
        S_HUN_Neg = 262,                         // HUN_Neg
        S_HUN_Neg_Stem = 263,                    // HUN_Neg_Stem
        S_HUN_Noun_Pref = 264,                   // HUN_Noun_Pref
        S_HUN_Noun_Stem = 265,                   // HUN_Noun_Stem
        S_HUN_Noun_lfea_Acc = 266,               // HUN_Noun_lfea_Acc
        S_HUN_Noun_lfea_Dat = 267,               // HUN_Noun_lfea_Dat
        S_HUN_Noun_lfea_Del = 268,               // HUN_Noun_lfea_Del
        S_HUN_Noun_lfea_Ine = 269,               // HUN_Noun_lfea_Ine
        S_HUN_Noun_lfea_Plur = 270,              // HUN_Noun_lfea_Plur
        S_HUN_Noun_lfea_Relative = 271,          // HUN_Noun_lfea_Relative
        S_HUN_Noun_lfea_Sub = 272,               // HUN_Noun_lfea_Sub
        S_HUN_Num = 273,                         // HUN_Num
        S_HUN_Num_Pref = 274,                    // HUN_Num_Pref
        S_HUN_Num_Stem = 275,                    // HUN_Num_Stem
        S_HUN_Num_lfea_Acc = 276,                // HUN_Num_lfea_Acc
        S_HUN_Num_lfea_Dat = 277,                // HUN_Num_lfea_Dat
        S_HUN_Num_lfea_Del = 278,                // HUN_Num_lfea_Del
        S_HUN_Num_lfea_Ik = 279,                 // HUN_Num_lfea_Ik
        S_HUN_Num_lfea_Par = 280,                // HUN_Num_lfea_Par
        S_HUN_Nums = 281,                        // HUN_Nums
        S_HUN_Pron_Int = 282,                    // HUN_Pron_Int
        S_HUN_Pron_Stem = 283,                   // HUN_Pron_Stem
        S_HUN_Pron_lfea_Int = 284,               // HUN_Pron_lfea_Int
        S_HUN_Pron_lfea_Nom = 285,               // HUN_Pron_lfea_Nom
        S_HUN_Punct = 286,                       // HUN_Punct
        S_HUN_Punct_ExclamationMark = 287,       // HUN_Punct_ExclamationMark
        S_HUN_Punct_FullStop = 288,              // HUN_Punct_FullStop
        S_HUN_Punct_QuestionMark = 289,          // HUN_Punct_QuestionMark
        S_HUN_Punct_Stem = 290,                  // HUN_Punct_Stem
        S_HUN_RC = 291,                          // HUN_RC
        S_HUN_RPro = 292,                        // HUN_RPro
        S_HUN_V = 293,                           // HUN_V
        S_HUN_VP = 294,                          // HUN_VP
        S_HUN_Vbar1 = 295,                       // HUN_Vbar1
        S_HUN_Vbar2 = 296,                       // HUN_Vbar2
        S_HUN_Vbar3 = 297,                       // HUN_Vbar3
        S_HUN_Vbpfx = 298,                       // HUN_Vbpfx
        S_HUN_Verb_lfea_ConjDefSg2 = 299,        // HUN_Verb_lfea_ConjDefSg2
        S_HUN_Verb_lfea_ConjIndefSg2 = 300,      // HUN_Verb_lfea_ConjIndefSg2
        S_HUN_Verb_lfea_DefSg1 = 301,            // HUN_Verb_lfea_DefSg1
        S_HUN_Verb_lfea_InDefSg3 = 302,          // HUN_Verb_lfea_InDefSg3
        S_HUN_Verb_lfea_IndefPl3 = 303,          // HUN_Verb_lfea_IndefPl3
        S_HUN_Verb_stem = 304,                   // HUN_Verb_stem
        S_HUN_Vhead = 305,                       // HUN_Vhead
        S_HUN_Vlisthead = 306,                   // HUN_Vlisthead
        S_HUN_lfea_DefDet = 307,                 // HUN_lfea_DefDet
        S_HUN_lfea_fwConsonant = 308,            // HUN_lfea_fwConsonant
        S_HUN_lfea_fwVowel = 309,                // HUN_lfea_fwVowel
        S_HUN_lfea_swConsonant = 310,            // HUN_lfea_swConsonant
        S_HUN_lfea_swVowel = 311,                // HUN_lfea_swVowel
        S_HUN_nCon = 312,                        // HUN_nCon
        S_JSON_Array = 313,                      // JSON_Array
        S_JSON_CON = 314,                        // JSON_CON
        S_JSON_ClosingSBracket = 315,            // JSON_ClosingSBracket
        S_JSON_Closing_Value_Element = 316,      // JSON_Closing_Value_Element
        S_JSON_Colon = 317,                      // JSON_Colon
        S_JSON_Comma = 318,                      // JSON_Comma
        S_JSON_Hash = 319,                       // JSON_Hash
        S_JSON_Hash_Ref = 320,                   // JSON_Hash_Ref
        S_JSON_Hash_Relative = 321,              // JSON_Hash_Relative
        S_JSON_Hash_lfea_relative = 322,         // JSON_Hash_lfea_relative
        S_JSON_Key = 323,                        // JSON_Key
        S_JSON_Key_Value_Pair = 324,             // JSON_Key_Value_Pair
        S_JSON_Open_Array = 325,                 // JSON_Open_Array
        S_JSON_Open_String = 326,                // JSON_Open_String
        S_JSON_OpeningSBracket = 327,            // JSON_OpeningSBracket
        S_JSON_Punct_ClosingSBracket = 328,      // JSON_Punct_ClosingSBracket
        S_JSON_Punct_Colon = 329,                // JSON_Punct_Colon
        S_JSON_Punct_Comma = 330,                // JSON_Punct_Comma
        S_JSON_Punct_Hash = 331,                 // JSON_Punct_Hash
        S_JSON_Punct_OpeningSBracket = 332,      // JSON_Punct_OpeningSBracket
        S_JSON_Punct_Quotes = 333,               // JSON_Punct_Quotes
        S_JSON_Punct_Stem = 334,                 // JSON_Punct_Stem
        S_JSON_Quotes = 335,                     // JSON_Quotes
        S_JSON_String = 336,                     // JSON_String
        S_JSON_Value = 337,                      // JSON_Value
        S_JSON_Value_List_Element = 338,         // JSON_Value_List_Element
        S_S = 339                                // S
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
      yylast_ = 1692,     ///< Last index in yytable_.
      yynnts_ = 224,  ///< Number of nonterminal symbols.
      yyfinal_ = 284 ///< Termination state number.
    };



  };


} // yy
#line 1204 "build/hi_desktop/hi.y.cpp"






// Unqualified %code blocks.
#line 1 "build/hi_desktop/hi.y"

#include "tokensymbols.h"
#line 4 "build/hi_desktop/hi.y"

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

#line 1249 "build/hi_desktop/hi.y.cpp"


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
#line 1322 "build/hi_desktop/hi.y.cpp"

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
#line 161 "build/hi_desktop/hi.y"
{
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_1Con->ENG_Con");
yylhs.value=sparser->set_node_info("ENG_1Con",ENG_Con);

}
#line 1783 "build/hi_desktop/hi.y.cpp"
    break;

  case 3: // ENG_A: ENG_A_Stem
#line 169 "build/hi_desktop/hi.y"
{
const node_info& ENG_A_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A->ENG_A_Stem");
yylhs.value=sparser->set_node_info("ENG_A",ENG_A_Stem);

}
#line 1794 "build/hi_desktop/hi.y.cpp"
    break;

  case 4: // ENG_A0NEG: ENG_A
#line 177 "build/hi_desktop/hi.y"
{
const node_info& ENG_A=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A0NEG->ENG_A");
yylhs.value=sparser->set_node_info("ENG_A0NEG",ENG_A);

}
#line 1805 "build/hi_desktop/hi.y.cpp"
    break;

  case 5: // ENG_ANEG: ENG_ANEG_Stem
#line 185 "build/hi_desktop/hi.y"
{
const node_info& ENG_ANEG_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ANEG->ENG_ANEG_Stem");
yylhs.value=sparser->set_node_info("ENG_ANEG",ENG_ANEG_Stem);

}
#line 1816 "build/hi_desktop/hi.y.cpp"
    break;

  case 6: // ENG_ANEG_Stem: t_ENG_ANEG_Stem
#line 193 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ANEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_ANEG_Stem",word);

}
#line 1828 "build/hi_desktop/hi.y.cpp"
    break;

  case 7: // ENG_AP: ENG_Abar1
#line 202 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar1");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Abar1);

}
#line 1839 "build/hi_desktop/hi.y.cpp"
    break;

  case 8: // ENG_AP: ENG_Abar2
#line 209 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar2");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Abar2);

}
#line 1850 "build/hi_desktop/hi.y.cpp"
    break;

  case 9: // ENG_AP: ENG_Alist
#line 216 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Alist");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Alist);

}
#line 1861 "build/hi_desktop/hi.y.cpp"
    break;

  case 10: // ENG_A_Stem: t_ENG_A_Stem
#line 224 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_A_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_A_Stem",word);

}
#line 1873 "build/hi_desktop/hi.y.cpp"
    break;

  case 11: // ENG_Abar1: ENG_A0NEG
#line 233 "build/hi_desktop/hi.y"
{
const node_info& ENG_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_A0NEG");
yylhs.value=sparser->set_node_info("ENG_Abar1",ENG_A0NEG);

}
#line 1884 "build/hi_desktop/hi.y.cpp"
    break;

  case 12: // ENG_Abar1: ENG_ANEG ENG_A
#line 240 "build/hi_desktop/hi.y"
{
const node_info& ENG_ANEG=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_A=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_ANEG ENG_A");
yylhs.value=sparser->combine_nodes("ENG_Abar1",ENG_ANEG,ENG_A);

}
#line 1896 "build/hi_desktop/hi.y.cpp"
    break;

  case 13: // ENG_Abar2: ENG_Abar1 ENG_CONJA
#line 249 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar1 ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Abar1,ENG_CONJA);

}
#line 1908 "build/hi_desktop/hi.y.cpp"
    break;

  case 14: // ENG_Abar2: ENG_Abar2 ENG_CONJA
#line 257 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar2 ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Abar2,ENG_CONJA);

}
#line 1920 "build/hi_desktop/hi.y.cpp"
    break;

  case 15: // ENG_Abar2: ENG_Alist ENG_CONJA
#line 265 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Alist ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Alist,ENG_CONJA);

}
#line 1932 "build/hi_desktop/hi.y.cpp"
    break;

  case 16: // ENG_Adv: t_ENG_ADV_Stem
#line 274 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ADV_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Adv",word);

}
#line 1944 "build/hi_desktop/hi.y.cpp"
    break;

  case 17: // ENG_AdvP: ENG_Adv
#line 283 "build/hi_desktop/hi.y"
{
const node_info& ENG_Adv=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AdvP->ENG_Adv");
yylhs.value=sparser->set_node_info("ENG_AdvP",ENG_Adv);

}
#line 1955 "build/hi_desktop/hi.y.cpp"
    break;

  case 18: // ENG_Alist: ENG_Abar1 ENG_Abar1
#line 291 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar11=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar12=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Abar1 ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_Alist",ENG_Abar11,ENG_Abar12);

}
#line 1967 "build/hi_desktop/hi.y.cpp"
    break;

  case 19: // ENG_Alist: ENG_Alist ENG_Abar1
#line 299 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Alist ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_Alist",ENG_Alist,ENG_Abar1);

}
#line 1979 "build/hi_desktop/hi.y.cpp"
    break;

  case 20: // ENG_CAP: ENG_1Con ENG_N_Pl_0Con_swC
#line 308 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swC");
yylhs.value=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swC);

}
#line 1991 "build/hi_desktop/hi.y.cpp"
    break;

  case 21: // ENG_CAP: ENG_1Con ENG_N_Pl_0Con_swV
#line 316 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swV");
yylhs.value=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swV);

}
#line 2003 "build/hi_desktop/hi.y.cpp"
    break;

  case 22: // ENG_CNP: ENG_AP ENG_N
#line 325 "build/hi_desktop/hi.y"
{
const node_info& ENG_AP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_AP ENG_N");
yylhs.value=sparser->combine_nodes("ENG_CNP",ENG_AP,ENG_N);

}
#line 2015 "build/hi_desktop/hi.y.cpp"
    break;

  case 23: // ENG_CNP: ENG_N
#line 333 "build/hi_desktop/hi.y"
{
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_N");
yylhs.value=sparser->set_node_info("ENG_CNP",ENG_N);

}
#line 2026 "build/hi_desktop/hi.y.cpp"
    break;

  case 24: // ENG_CONJ: ENG_CONJ_Stem
#line 341 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJ->ENG_CONJ_Stem");
yylhs.value=sparser->set_node_info("ENG_CONJ",ENG_CONJ_Stem);

}
#line 2037 "build/hi_desktop/hi.y.cpp"
    break;

  case 25: // ENG_CONJA: ENG_CONJ ENG_Abar1
#line 349 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Abar1);

}
#line 2049 "build/hi_desktop/hi.y.cpp"
    break;

  case 26: // ENG_CONJA: ENG_CONJ ENG_Alist
#line 357 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Alist");
yylhs.value=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Alist);

}
#line 2061 "build/hi_desktop/hi.y.cpp"
    break;

  case 27: // ENG_CONJ_Stem: t_ENG_CONJ_Stem
#line 366 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CONJ_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_CONJ_Stem",word);

}
#line 2073 "build/hi_desktop/hi.y.cpp"
    break;

  case 28: // ENG_Con: t_ENG_CON_Stem
#line 375 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Con",word);

}
#line 2085 "build/hi_desktop/hi.y.cpp"
    break;

  case 29: // ENG_ConjPVP: ENG_CONJ ENG_PVP
#line 384 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjPVP->ENG_CONJ ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_ConjPVP",ENG_CONJ,ENG_PVP);

}
#line 2097 "build/hi_desktop/hi.y.cpp"
    break;

  case 30: // ENG_ConjPVP: ENG_CONJ ENG_PVPlist
#line 392 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjPVP->ENG_CONJ ENG_PVPlist");
yylhs.value=sparser->combine_nodes("ENG_ConjPVP",ENG_CONJ,ENG_PVPlist);

}
#line 2109 "build/hi_desktop/hi.y.cpp"
    break;

  case 31: // ENG_ConjV: ENG_CONJ ENG_IVP
#line 401 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjV->ENG_CONJ ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_ConjV",ENG_CONJ,ENG_IVP);

}
#line 2121 "build/hi_desktop/hi.y.cpp"
    break;

  case 32: // ENG_ConjV: ENG_CONJ ENG_IVPlist
#line 409 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ConjV->ENG_CONJ ENG_IVPlist");
yylhs.value=sparser->combine_nodes("ENG_ConjV",ENG_CONJ,ENG_IVPlist);

}
#line 2133 "build/hi_desktop/hi.y.cpp"
    break;

  case 33: // ENG_DP: ENG_Def_Det ENG_N
#line 418 "build/hi_desktop/hi.y"
{
const node_info& ENG_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Def_Det ENG_N");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Def_Det,ENG_N);

}
#line 2145 "build/hi_desktop/hi.y.cpp"
    break;

  case 34: // ENG_DP: ENG_Def_Det ENG_Num_Ord
#line 426 "build/hi_desktop/hi.y"
{
const node_info& ENG_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_Ord=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Def_Det ENG_Num_Ord");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Def_Det,ENG_Num_Ord);

}
#line 2157 "build/hi_desktop/hi.y.cpp"
    break;

  case 35: // ENG_DP: ENG_Indef_Det_a ENG_N_Sg_0Con_swC
#line 434 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det_a=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);

}
#line 2169 "build/hi_desktop/hi.y.cpp"
    break;

  case 36: // ENG_DP: ENG_Indef_Det_an ENG_N_Sg_0Con_swV
#line 442 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det_an=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);

}
#line 2181 "build/hi_desktop/hi.y.cpp"
    break;

  case 37: // ENG_Def_Det: ENG_Det_stem ENG_lfea_DefDet
#line 451 "build/hi_desktop/hi.y"
{
const node_info& ENG_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_DefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Def_Det->ENG_Det_stem ENG_lfea_DefDet");
yylhs.value=sparser->combine_nodes("ENG_Def_Det",ENG_Det_stem,ENG_lfea_DefDet);

}
#line 2193 "build/hi_desktop/hi.y.cpp"
    break;

  case 38: // ENG_Det_stem: t_ENG_DET_Stem
#line 460 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Det_stem",word);

}
#line 2205 "build/hi_desktop/hi.y.cpp"
    break;

  case 39: // ENG_IVP: ENG_NV ENG_NP
#line 469 "build/hi_desktop/hi.y"
{
const node_info& ENG_NV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_NV,"ENG_V_Aux","V",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_NP);
}
#line 2217 "build/hi_desktop/hi.y.cpp"
    break;

  case 40: // ENG_IVP: ENG_NV ENG_PP
#line 477 "build/hi_desktop/hi.y"
{
const node_info& ENG_NV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_NV,"ENG_V_Aux","V",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
}
#line 2229 "build/hi_desktop/hi.y.cpp"
    break;

  case 41: // ENG_IVP: ENG_V ENG_AP
#line 485 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_AP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_AP);
}
#line 2241 "build/hi_desktop/hi.y.cpp"
    break;

  case 42: // ENG_IVP: ENG_V ENG_NP
#line 493 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
unsigned int leaf_node_id=sparser->add_feature_to_leaf(ENG_V,"ENG_V_Aux","V",std::string("RCV"));
if(leaf_node_id==0) sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_NP);
}
#line 2254 "build/hi_desktop/hi.y.cpp"
    break;

  case 43: // ENG_IVP: ENG_V ENG_PP
#line 502 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
unsigned int leaf_node_id=sparser->add_feature_to_leaf(ENG_V,"ENG_V_Aux","V",std::string("RCV"));
if(leaf_node_id==0) sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
}
#line 2267 "build/hi_desktop/hi.y.cpp"
    break;

  case 44: // ENG_IVPConj: ENG_IVPConj ENG_ConjV
#line 512 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_IVPConj ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_IVPConj,ENG_ConjV);

}
#line 2279 "build/hi_desktop/hi.y.cpp"
    break;

  case 45: // ENG_IVPConj: ENG_Vhead ENG_ConjV
#line 520 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vhead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_Vhead ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_Vhead,ENG_ConjV);

}
#line 2291 "build/hi_desktop/hi.y.cpp"
    break;

  case 46: // ENG_IVPConj: ENG_Vlisthead ENG_ConjV
#line 528 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPConj->ENG_Vlisthead ENG_ConjV");
yylhs.value=sparser->combine_nodes("ENG_IVPConj",ENG_Vlisthead,ENG_ConjV);

}
#line 2303 "build/hi_desktop/hi.y.cpp"
    break;

  case 47: // ENG_IVPlist: ENG_IVP ENG_IVP
#line 537 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVP1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPlist->ENG_IVP ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_IVPlist",ENG_IVP1,ENG_IVP2);

}
#line 2315 "build/hi_desktop/hi.y.cpp"
    break;

  case 48: // ENG_IVPlist: ENG_IVPlist ENG_IVP
#line 545 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVPlist->ENG_IVPlist ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_IVPlist",ENG_IVPlist,ENG_IVP);

}
#line 2327 "build/hi_desktop/hi.y.cpp"
    break;

  case 49: // ENG_Indef_Det: ENG_Det_stem ENG_lfea_IndefDet
#line 554 "build/hi_desktop/hi.y"
{
const node_info& ENG_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_IndefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);

}
#line 2339 "build/hi_desktop/hi.y.cpp"
    break;

  case 50: // ENG_Indef_Det_a: ENG_Indef_Det ENG_lfea_fwConsonant
#line 563 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_fwConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);

}
#line 2351 "build/hi_desktop/hi.y.cpp"
    break;

  case 51: // ENG_Indef_Det_an: ENG_Indef_Det ENG_lfea_fwVowel
#line 572 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_fwVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);

}
#line 2363 "build/hi_desktop/hi.y.cpp"
    break;

  case 52: // ENG_N: ENG_N_Pl
#line 581 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Pl");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Pl);

}
#line 2374 "build/hi_desktop/hi.y.cpp"
    break;

  case 53: // ENG_N: ENG_N_Sg
#line 588 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Sg");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Sg);

}
#line 2385 "build/hi_desktop/hi.y.cpp"
    break;

  case 54: // ENG_NP: ENG_CAP
#line 596 "build/hi_desktop/hi.y"
{
const node_info& ENG_CAP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CAP");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_CAP);

}
#line 2396 "build/hi_desktop/hi.y.cpp"
    break;

  case 55: // ENG_NP: ENG_CNP
#line 603 "build/hi_desktop/hi.y"
{
const node_info& ENG_CNP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CNP");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_CNP);

}
#line 2407 "build/hi_desktop/hi.y.cpp"
    break;

  case 56: // ENG_NP: ENG_QPro ENG_CNP
#line 610 "build/hi_desktop/hi.y"
{
const node_info& ENG_QPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CNP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_QPro ENG_CNP");
yylhs.value=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);

}
#line 2419 "build/hi_desktop/hi.y.cpp"
    break;

  case 57: // ENG_NV: ENG_NV_Aux ENG_V_Stem
#line 619 "build/hi_desktop/hi.y"
{
const node_info& ENG_NV_Aux=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_NV_Aux ENG_V_Stem");
yylhs.value=sparser->combine_nodes("ENG_NV",ENG_NV_Aux,ENG_V_Stem);

}
#line 2431 "build/hi_desktop/hi.y.cpp"
    break;

  case 58: // ENG_NV: ENG_V ENG_VNEG
#line 627 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_V ENG_VNEG");
yylhs.value=sparser->combine_nodes("ENG_NV",ENG_V,ENG_VNEG);

}
#line 2443 "build/hi_desktop/hi.y.cpp"
    break;

  case 59: // ENG_NV_Aux: ENG_V_Aux ENG_VNEG
#line 636 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Aux=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV_Aux->ENG_V_Aux ENG_VNEG");
yylhs.value=sparser->combine_nodes("ENG_NV_Aux",ENG_V_Aux,ENG_VNEG);

}
#line 2455 "build/hi_desktop/hi.y.cpp"
    break;

  case 60: // ENG_N_Pl: ENG_N_Pl_0Con_swC
#line 645 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swC);

}
#line 2466 "build/hi_desktop/hi.y.cpp"
    break;

  case 61: // ENG_N_Pl: ENG_N_Pl_0Con_swC ENG_nCon
#line 652 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);

}
#line 2478 "build/hi_desktop/hi.y.cpp"
    break;

  case 62: // ENG_N_Pl: ENG_N_Pl_0Con_swV
#line 660 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swV);

}
#line 2489 "build/hi_desktop/hi.y.cpp"
    break;

  case 63: // ENG_N_Pl: ENG_N_Pl_0Con_swV ENG_nCon
#line 667 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);

}
#line 2501 "build/hi_desktop/hi.y.cpp"
    break;

  case 64: // ENG_N_Pl: ENG_N_Sg ENG_nCon
#line 675 "build/hi_desktop/hi.y"
{
//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in 'list file abc def'
//TODO: Any better solution???
YYERROR;
}
#line 2512 "build/hi_desktop/hi.y.cpp"
    break;

  case 65: // ENG_N_Pl: ENG_nCon
#line 682 "build/hi_desktop/hi.y"
{
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_nCon");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_nCon);

}
#line 2523 "build/hi_desktop/hi.y.cpp"
    break;

  case 66: // ENG_N_Pl_0Con: ENG_N_Stem ENG_N_lfea_Pl
#line 690 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);

}
#line 2535 "build/hi_desktop/hi.y.cpp"
    break;

  case 67: // ENG_N_Pl_0Con_swC: ENG_N_Pl_0Con ENG_lfea_swConsonant
#line 699 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);

}
#line 2547 "build/hi_desktop/hi.y.cpp"
    break;

  case 68: // ENG_N_Pl_0Con_swV: ENG_N_Pl_0Con ENG_lfea_swVowel
#line 708 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);

}
#line 2559 "build/hi_desktop/hi.y.cpp"
    break;

  case 69: // ENG_N_Sg: ENG_1Con
#line 717 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_1Con");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_1Con);

}
#line 2570 "build/hi_desktop/hi.y.cpp"
    break;

  case 70: // ENG_N_Sg: ENG_N_Sg_0Con_swC
#line 724 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swC);

}
#line 2581 "build/hi_desktop/hi.y.cpp"
    break;

  case 71: // ENG_N_Sg: ENG_N_Sg_0Con_swC ENG_1Con
#line 731 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swC,ENG_1Con);

}
#line 2593 "build/hi_desktop/hi.y.cpp"
    break;

  case 72: // ENG_N_Sg: ENG_N_Sg_0Con_swV
#line 739 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swV);

}
#line 2604 "build/hi_desktop/hi.y.cpp"
    break;

  case 73: // ENG_N_Sg: ENG_N_Sg_0Con_swV ENG_1Con
#line 746 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swV,ENG_1Con);

}
#line 2616 "build/hi_desktop/hi.y.cpp"
    break;

  case 74: // ENG_N_Sg_0Con: ENG_N_Stem ENG_N_lfea_Sg
#line 755 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con",ENG_N_Stem,ENG_N_lfea_Sg);

}
#line 2628 "build/hi_desktop/hi.y.cpp"
    break;

  case 75: // ENG_N_Sg_0Con_swC: ENG_N_Sg_0Con ENG_lfea_swConsonant
#line 764 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);

}
#line 2640 "build/hi_desktop/hi.y.cpp"
    break;

  case 76: // ENG_N_Sg_0Con_swV: ENG_N_Sg_0Con ENG_lfea_swVowel
#line 773 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);

}
#line 2652 "build/hi_desktop/hi.y.cpp"
    break;

  case 77: // ENG_N_Stem: t_ENG_N_Stem
#line 782 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_Stem",word);

}
#line 2664 "build/hi_desktop/hi.y.cpp"
    break;

  case 78: // ENG_N_lfea_Pl: t_ENG_N_Pl
#line 791 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Pl);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Pl",word);

}
#line 2676 "build/hi_desktop/hi.y.cpp"
    break;

  case 79: // ENG_N_lfea_Sg: t_ENG_N_Sg
#line 800 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Sg",word);

}
#line 2688 "build/hi_desktop/hi.y.cpp"
    break;

  case 80: // ENG_Num: ENG_Num_Pref ENG_Num
#line 809 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Pref ENG_Num");
yylhs.value=sparser->combine_nodes("ENG_Num",ENG_Num_Pref,ENG_Num);

}
#line 2700 "build/hi_desktop/hi.y.cpp"
    break;

  case 81: // ENG_Num: ENG_Num_Stem
#line 817 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Stem");
yylhs.value=sparser->set_node_info("ENG_Num",ENG_Num_Stem);

}
#line 2711 "build/hi_desktop/hi.y.cpp"
    break;

  case 82: // ENG_Num_Ord: ENG_Num ENG_Num_lfea_Ord
#line 825 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_lfea_Ord=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num_Ord->ENG_Num ENG_Num_lfea_Ord");
yylhs.value=sparser->combine_nodes("ENG_Num_Ord",ENG_Num,ENG_Num_lfea_Ord);

}
#line 2723 "build/hi_desktop/hi.y.cpp"
    break;

  case 83: // ENG_Num_Pref: t_ENG_Num_Npref1n
#line 834 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2735 "build/hi_desktop/hi.y.cpp"
    break;

  case 84: // ENG_Num_Pref: t_ENG_Num_Npref2n
#line 842 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2747 "build/hi_desktop/hi.y.cpp"
    break;

  case 85: // ENG_Num_Pref: t_ENG_Num_Npref3n
#line 850 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2759 "build/hi_desktop/hi.y.cpp"
    break;

  case 86: // ENG_Num_Pref: t_ENG_Num_Npref4n
#line 858 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2771 "build/hi_desktop/hi.y.cpp"
    break;

  case 87: // ENG_Num_Pref: t_ENG_Num_Npref5n
#line 866 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2783 "build/hi_desktop/hi.y.cpp"
    break;

  case 88: // ENG_Num_Pref: t_ENG_Num_Npref6n
#line 874 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2795 "build/hi_desktop/hi.y.cpp"
    break;

  case 89: // ENG_Num_Pref: t_ENG_Num_Npref7n
#line 882 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2807 "build/hi_desktop/hi.y.cpp"
    break;

  case 90: // ENG_Num_Pref: t_ENG_Num_Npref8n
#line 890 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2819 "build/hi_desktop/hi.y.cpp"
    break;

  case 91: // ENG_Num_Pref: t_ENG_Num_Npref9n
#line 898 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 2831 "build/hi_desktop/hi.y.cpp"
    break;

  case 92: // ENG_Num_Stem: t_ENG_Num_Stem
#line 907 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Stem",word);

}
#line 2843 "build/hi_desktop/hi.y.cpp"
    break;

  case 93: // ENG_Num_lfea_Ord: t_ENG_Num_Ord
#line 916 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Ord);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_lfea_Ord",word);

}
#line 2855 "build/hi_desktop/hi.y.cpp"
    break;

  case 94: // ENG_PNVPbar: ENG_VNEG ENG_PVPbar
#line 925 "build/hi_desktop/hi.y"
{
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PNVPbar->ENG_VNEG ENG_PVPbar");
yylhs.value=sparser->combine_nodes("ENG_PNVPbar",ENG_VNEG,ENG_PVPbar);

}
#line 2867 "build/hi_desktop/hi.y.cpp"
    break;

  case 95: // ENG_PP: ENG_Prep ENG_NP
#line 934 "build/hi_desktop/hi.y"
{
const node_info& ENG_Prep=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);

}
#line 2879 "build/hi_desktop/hi.y.cpp"
    break;

  case 96: // ENG_PVP: ENG_PNVPbar
#line 943 "build/hi_desktop/hi.y"
{
const node_info& ENG_PNVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVP->ENG_PNVPbar");
yylhs.value=sparser->set_node_info("ENG_PVP",ENG_PNVPbar);

}
#line 2890 "build/hi_desktop/hi.y.cpp"
    break;

  case 97: // ENG_PVP: ENG_PVPbar
#line 950 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVP->ENG_PVPbar");
yylhs.value=sparser->set_node_info("ENG_PVP",ENG_PVPbar);

}
#line 2901 "build/hi_desktop/hi.y.cpp"
    break;

  case 98: // ENG_PVPConj: ENG_PVPConj ENG_ConjPVP
#line 958 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPConj ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPConj,ENG_ConjPVP);

}
#line 2913 "build/hi_desktop/hi.y.cpp"
    break;

  case 99: // ENG_PVPConj: ENG_PVPhead ENG_ConjPVP
#line 966 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPhead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPhead ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPhead,ENG_ConjPVP);

}
#line 2925 "build/hi_desktop/hi.y.cpp"
    break;

  case 100: // ENG_PVPConj: ENG_PVPlisthead ENG_ConjPVP
#line 974 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_ConjPVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPConj->ENG_PVPlisthead ENG_ConjPVP");
yylhs.value=sparser->combine_nodes("ENG_PVPConj",ENG_PVPlisthead,ENG_ConjPVP);

}
#line 2937 "build/hi_desktop/hi.y.cpp"
    break;

  case 101: // ENG_PVPbar: ENG_V_Ger ENG_NP
#line 983 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPbar->ENG_V_Ger ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_PVPbar",ENG_V_Ger,ENG_NP);
}
#line 2948 "build/hi_desktop/hi.y.cpp"
    break;

  case 102: // ENG_PVPbar: ENG_V_Ger ENG_PP
#line 990 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPbar->ENG_V_Ger ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_PVPbar",ENG_V_Ger,ENG_PP);
}
#line 2959 "build/hi_desktop/hi.y.cpp"
    break;

  case 103: // ENG_PVPhead: ENG_PVP
#line 998 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPhead->ENG_PVP");
yylhs.value=sparser->set_node_info("ENG_PVPhead",ENG_PVP);

}
#line 2970 "build/hi_desktop/hi.y.cpp"
    break;

  case 104: // ENG_PVPlist: ENG_PVP ENG_PVP
#line 1006 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVP1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlist->ENG_PVP ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_PVPlist",ENG_PVP1,ENG_PVP2);

}
#line 2982 "build/hi_desktop/hi.y.cpp"
    break;

  case 105: // ENG_PVPlist: ENG_PVPlist ENG_PVP
#line 1014 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlist->ENG_PVPlist ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_PVPlist",ENG_PVPlist,ENG_PVP);

}
#line 2994 "build/hi_desktop/hi.y.cpp"
    break;

  case 106: // ENG_PVPlisthead: ENG_PVPlist
#line 1023 "build/hi_desktop/hi.y"
{
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PVPlisthead->ENG_PVPlist");
yylhs.value=sparser->set_node_info("ENG_PVPlisthead",ENG_PVPlist);

}
#line 3005 "build/hi_desktop/hi.y.cpp"
    break;

  case 107: // ENG_Prep: t_ENG_PREP_Stem
#line 1031 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PREP_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Prep",word);

}
#line 3017 "build/hi_desktop/hi.y.cpp"
    break;

  case 108: // ENG_QPro: t_ENG_QPRO_Stem
#line 1040 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_QPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_QPro",word);

}
#line 3029 "build/hi_desktop/hi.y.cpp"
    break;

  case 109: // ENG_RC: ENG_RPro ENG_IVP
#line 1049 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);

}
#line 3041 "build/hi_desktop/hi.y.cpp"
    break;

  case 110: // ENG_RC: ENG_RPro ENG_IVPConj
#line 1057 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVPConj");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVPConj);

}
#line 3053 "build/hi_desktop/hi.y.cpp"
    break;

  case 111: // ENG_RC: ENG_RPro ENG_IVPlist
#line 1065 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVPlist");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVPlist);

}
#line 3065 "build/hi_desktop/hi.y.cpp"
    break;

  case 112: // ENG_RPro: ENG_RPro_stem ENG_RPro_lfea_relative
#line 1074 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RPro_lfea_relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative");
yylhs.value=sparser->combine_nodes("ENG_RPro",ENG_RPro_stem,ENG_RPro_lfea_relative);

}
#line 3077 "build/hi_desktop/hi.y.cpp"
    break;

  case 113: // ENG_RPro_lfea_relative: t_ENG_RPRO_Relative
#line 1083 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_RPro_lfea_relative",word);

}
#line 3089 "build/hi_desktop/hi.y.cpp"
    break;

  case 114: // ENG_RPro_stem: t_ENG_RPRO_Stem
#line 1092 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_RPro_stem",word);

}
#line 3101 "build/hi_desktop/hi.y.cpp"
    break;

  case 115: // ENG_TP: ENG_Tense_particle ENG_V_Stem
#line 1101 "build/hi_desktop/hi.y"
{
const node_info& ENG_Tense_particle=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_Tense_particle ENG_V_Stem");
yylhs.value=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_Stem);

}
#line 3113 "build/hi_desktop/hi.y.cpp"
    break;

  case 116: // ENG_TP: ENG_V_Ger
#line 1109 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Ger=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_V_Ger");
yylhs.value=sparser->set_node_info("ENG_TP",ENG_V_Ger);

}
#line 3124 "build/hi_desktop/hi.y.cpp"
    break;

  case 117: // ENG_Tense_particle: t_ENG_PAR_Stem
#line 1117 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PAR_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Tense_particle",word);

}
#line 3136 "build/hi_desktop/hi.y.cpp"
    break;

  case 118: // ENG_V: ENG_V_Aux
#line 1126 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Aux=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Aux");
yylhs.value=sparser->set_node_info("ENG_V",ENG_V_Aux);

}
#line 3147 "build/hi_desktop/hi.y.cpp"
    break;

  case 119: // ENG_V: ENG_V_Stem
#line 1133 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");
yylhs.value=sparser->set_node_info("ENG_V",ENG_V_Stem);

}
#line 3158 "build/hi_desktop/hi.y.cpp"
    break;

  case 120: // ENG_VNEG: ENG_VNEG_Stem
#line 1141 "build/hi_desktop/hi.y"
{
const node_info& ENG_VNEG_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VNEG->ENG_VNEG_Stem");
yylhs.value=sparser->set_node_info("ENG_VNEG",ENG_VNEG_Stem);

}
#line 3169 "build/hi_desktop/hi.y.cpp"
    break;

  case 121: // ENG_VNEG_Stem: t_ENG_VNEG_Stem
#line 1149 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_VNEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_VNEG_Stem",word);

}
#line 3181 "build/hi_desktop/hi.y.cpp"
    break;

  case 122: // ENG_VP: ENG_Vbar1
#line 1158 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1");
yylhs.value=sparser->set_node_info("ENG_VP",ENG_Vbar1);

}
#line 3192 "build/hi_desktop/hi.y.cpp"
    break;

  case 123: // ENG_VP: ENG_Vbar1 ENG_AdvP
#line 1165 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AdvP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);

}
#line 3204 "build/hi_desktop/hi.y.cpp"
    break;

  case 124: // ENG_VP: ENG_Vbar1 ENG_PVP
#line 1173 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVP);

}
#line 3216 "build/hi_desktop/hi.y.cpp"
    break;

  case 125: // ENG_VP: ENG_Vbar1 ENG_PVPConj
#line 1181 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVPConj");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVPConj);

}
#line 3228 "build/hi_desktop/hi.y.cpp"
    break;

  case 126: // ENG_VP: ENG_Vbar1 ENG_PVPlist
#line 1189 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_PVPlist");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_PVPlist);

}
#line 3240 "build/hi_desktop/hi.y.cpp"
    break;

  case 127: // ENG_VP: ENG_Vbar1 ENG_RC
#line 1197 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_RC");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);

}
#line 3252 "build/hi_desktop/hi.y.cpp"
    break;

  case 128: // ENG_VP: ENG_Vbar2
#line 1205 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2");
yylhs.value=sparser->set_node_info("ENG_VP",ENG_Vbar2);

}
#line 3263 "build/hi_desktop/hi.y.cpp"
    break;

  case 129: // ENG_VP: ENG_Vbar2 ENG_PP
#line 1212 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);

}
#line 3275 "build/hi_desktop/hi.y.cpp"
    break;

  case 130: // ENG_VP: ENG_Vbar2 ENG_RC
#line 1220 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_RC");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);

}
#line 3287 "build/hi_desktop/hi.y.cpp"
    break;

  case 131: // ENG_VP: ENG_Vbar3 ENG_NP
#line 1228 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar3=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar3 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);

}
#line 3299 "build/hi_desktop/hi.y.cpp"
    break;

  case 132: // ENG_VP: ENG_Vbar4 ENG_DP
#line 1236 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar4=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar4 ENG_DP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);

}
#line 3311 "build/hi_desktop/hi.y.cpp"
    break;

  case 133: // ENG_V_Aux: ENG_V_Stem ENG_V_lfea_aux
#line 1245 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_aux=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Aux->ENG_V_Stem ENG_V_lfea_aux");
yylhs.value=sparser->combine_nodes("ENG_V_Aux",ENG_V_Stem,ENG_V_lfea_aux);

}
#line 3323 "build/hi_desktop/hi.y.cpp"
    break;

  case 134: // ENG_V_Ger: ENG_V_Stem ENG_V_lfea_ger
#line 1254 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_ger=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Ger->ENG_V_Stem ENG_V_lfea_ger");
yylhs.value=sparser->combine_nodes("ENG_V_Ger",ENG_V_Stem,ENG_V_lfea_ger);

}
#line 3335 "build/hi_desktop/hi.y.cpp"
    break;

  case 135: // ENG_V_Stem: t_ENG_V_Stem
#line 1263 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_Stem",word);

}
#line 3347 "build/hi_desktop/hi.y.cpp"
    break;

  case 136: // ENG_V_lfea_aux: t_ENG_V_Aux
#line 1272 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Aux);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_aux",word);

}
#line 3359 "build/hi_desktop/hi.y.cpp"
    break;

  case 137: // ENG_V_lfea_ger: t_ENG_V_Gerund
#line 1281 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Gerund);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_ger",word);

}
#line 3371 "build/hi_desktop/hi.y.cpp"
    break;

  case 138: // ENG_Vbar1: ENG_V ENG_NP
#line 1290 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
}
#line 3383 "build/hi_desktop/hi.y.cpp"
    break;

  case 139: // ENG_Vbar2: ENG_Vbar1 ENG_NP
#line 1299 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);

}
#line 3395 "build/hi_desktop/hi.y.cpp"
    break;

  case 140: // ENG_Vbar2: ENG_Vbar1 ENG_PP
#line 1307 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_PP);

}
#line 3407 "build/hi_desktop/hi.y.cpp"
    break;

  case 141: // ENG_Vbar3: ENG_V ENG_AdvP
#line 1316 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AdvP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar3->ENG_V ENG_AdvP");
yylhs.value=sparser->combine_nodes("ENG_Vbar3",ENG_V,ENG_AdvP);

}
#line 3419 "build/hi_desktop/hi.y.cpp"
    break;

  case 142: // ENG_Vbar4: ENG_DP ENG_V
#line 1325 "build/hi_desktop/hi.y"
{
const node_info& ENG_DP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
}
#line 3431 "build/hi_desktop/hi.y.cpp"
    break;

  case 143: // ENG_Vbar4: ENG_TP ENG_V
#line 1333 "build/hi_desktop/hi.y"
{
const node_info& ENG_TP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
}
#line 3443 "build/hi_desktop/hi.y.cpp"
    break;

  case 144: // ENG_Vbar4: ENG_V
#line 1341 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_V");
yylhs.value=sparser->set_node_info("ENG_Vbar4",ENG_V);
}
#line 3454 "build/hi_desktop/hi.y.cpp"
    break;

  case 145: // ENG_Vhead: ENG_IVP
#line 1349 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vhead->ENG_IVP");
yylhs.value=sparser->set_node_info("ENG_Vhead",ENG_IVP);

}
#line 3465 "build/hi_desktop/hi.y.cpp"
    break;

  case 146: // ENG_Vlisthead: ENG_IVPlist
#line 1357 "build/hi_desktop/hi.y"
{
const node_info& ENG_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vlisthead->ENG_IVPlist");
yylhs.value=sparser->set_node_info("ENG_Vlisthead",ENG_IVPlist);

}
#line 3476 "build/hi_desktop/hi.y.cpp"
    break;

  case 147: // ENG_lfea_DefDet: t_ENG_DET_Def
#line 1365 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Def);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_DefDet",word);

}
#line 3488 "build/hi_desktop/hi.y.cpp"
    break;

  case 148: // ENG_lfea_IndefDet: t_ENG_DET_Indef
#line 1374 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Indef);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_IndefDet",word);

}
#line 3500 "build/hi_desktop/hi.y.cpp"
    break;

  case 149: // ENG_lfea_fwConsonant: t_ENG_DET_fwConsonant
#line 1383 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_fwConsonant",word);

}
#line 3512 "build/hi_desktop/hi.y.cpp"
    break;

  case 150: // ENG_lfea_fwVowel: t_ENG_DET_fwVowel
#line 1392 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_fwVowel",word);

}
#line 3524 "build/hi_desktop/hi.y.cpp"
    break;

  case 151: // ENG_lfea_swConsonant: t_ENG_N_swConsonant
#line 1401 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_swConsonant",word);

}
#line 3536 "build/hi_desktop/hi.y.cpp"
    break;

  case 152: // ENG_lfea_swVowel: t_ENG_N_swVowel
#line 1410 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_swVowel",word);

}
#line 3548 "build/hi_desktop/hi.y.cpp"
    break;

  case 153: // ENG_nCon: ENG_1Con ENG_Con
#line 1419 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_1Con ENG_Con");
yylhs.value=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);

}
#line 3560 "build/hi_desktop/hi.y.cpp"
    break;

  case 154: // ENG_nCon: ENG_nCon ENG_Con
#line 1427 "build/hi_desktop/hi.y"
{
const node_info& ENG_nCon=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_nCon ENG_Con");
yylhs.value=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);

}
#line 3572 "build/hi_desktop/hi.y.cpp"
    break;

  case 155: // HUN_1Con: HUN_Con
#line 1436 "build/hi_desktop/hi.y"
{
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_1Con->HUN_Con");
yylhs.value=sparser->set_node_info("HUN_1Con",HUN_Con);

}
#line 3583 "build/hi_desktop/hi.y.cpp"
    break;

  case 156: // HUN_A0NEG: HUN_Adj
#line 1444 "build/hi_desktop/hi.y"
{
const node_info& HUN_Adj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_A0NEG->HUN_Adj");
yylhs.value=sparser->set_node_info("HUN_A0NEG",HUN_Adj);

}
#line 3594 "build/hi_desktop/hi.y.cpp"
    break;

  case 157: // HUN_ANEG: HUN_Neg HUN_Adj
#line 1452 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Adj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ANEG->HUN_Neg HUN_Adj");
yylhs.value=sparser->combine_nodes("HUN_ANEG",HUN_Neg,HUN_Adj);

}
#line 3606 "build/hi_desktop/hi.y.cpp"
    break;

  case 158: // HUN_ANP: HUN_N_Sg HUN_N_Sg
#line 1461 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ANP->HUN_N_Sg HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_ANP",HUN_N_Sg1,HUN_N_Sg2);

}
#line 3618 "build/hi_desktop/hi.y.cpp"
    break;

  case 159: // HUN_AN_Acc: HUN_N_Acc END
#line 1470 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AN_Acc->HUN_N_Acc END");
yylhs.value=sparser->set_node_info("HUN_AN_Acc",HUN_N_Acc);
}
#line 3628 "build/hi_desktop/hi.y.cpp"
    break;

  case 160: // HUN_AP: HUN_Abar3 HUN_N_Acc
#line 1477 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Abar3 HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Abar3,HUN_N_Acc);

}
#line 3640 "build/hi_desktop/hi.y.cpp"
    break;

  case 161: // HUN_AP: HUN_Abar4 HUN_ConjA_End
#line 1485 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjA_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Abar4 HUN_ConjA_End");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Abar4,HUN_ConjA_End);

}
#line 3652 "build/hi_desktop/hi.y.cpp"
    break;

  case 162: // HUN_AP: HUN_Alist HUN_N_Acc
#line 1493 "build/hi_desktop/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_AP->HUN_Alist HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_AP",HUN_Alist,HUN_N_Acc);

}
#line 3664 "build/hi_desktop/hi.y.cpp"
    break;

  case 163: // HUN_Abar1: HUN_N_Acc HUN_A0NEG
#line 1502 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Acc HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Acc,HUN_A0NEG);

}
#line 3676 "build/hi_desktop/hi.y.cpp"
    break;

  case 164: // HUN_Abar1: HUN_N_Ins HUN_A0NEG
#line 1510 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Ins HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Ins,HUN_A0NEG);

}
#line 3688 "build/hi_desktop/hi.y.cpp"
    break;

  case 165: // HUN_Abar1: HUN_N_Sub HUN_A0NEG
#line 1518 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1->HUN_N_Sub HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1",HUN_N_Sub,HUN_A0NEG);

}
#line 3700 "build/hi_desktop/hi.y.cpp"
    break;

  case 166: // HUN_Abar1N: HUN_N_Acc HUN_ANEG
#line 1527 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Acc HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Acc,HUN_ANEG);

}
#line 3712 "build/hi_desktop/hi.y.cpp"
    break;

  case 167: // HUN_Abar1N: HUN_N_Ins HUN_ANEG
#line 1535 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Ins HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Ins,HUN_ANEG);

}
#line 3724 "build/hi_desktop/hi.y.cpp"
    break;

  case 168: // HUN_Abar1N: HUN_N_Sub HUN_ANEG
#line 1543 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar1N->HUN_N_Sub HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_Abar1N",HUN_N_Sub,HUN_ANEG);

}
#line 3736 "build/hi_desktop/hi.y.cpp"
    break;

  case 169: // HUN_Abar2: HUN_Abar1
#line 1552 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2->HUN_Abar1");
yylhs.value=sparser->set_node_info("HUN_Abar2",HUN_Abar1);

}
#line 3747 "build/hi_desktop/hi.y.cpp"
    break;

  case 170: // HUN_Abar2N: HUN_Abar1N
#line 1560 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar1N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2N->HUN_Abar1N");
yylhs.value=sparser->set_node_info("HUN_Abar2N",HUN_Abar1N);

}
#line 3758 "build/hi_desktop/hi.y.cpp"
    break;

  case 171: // HUN_Abar2N: HUN_NAbar1
#line 1567 "build/hi_desktop/hi.y"
{
const node_info& HUN_NAbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar2N->HUN_NAbar1");
yylhs.value=sparser->set_node_info("HUN_Abar2N",HUN_NAbar1);

}
#line 3769 "build/hi_desktop/hi.y.cpp"
    break;

  case 172: // HUN_Abar3: HUN_Abar2
#line 1575 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3->HUN_Abar2");
yylhs.value=sparser->set_node_info("HUN_Abar3",HUN_Abar2);

}
#line 3780 "build/hi_desktop/hi.y.cpp"
    break;

  case 173: // HUN_Abar3: HUN_Abar2N
#line 1582 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar2N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3->HUN_Abar2N");
yylhs.value=sparser->set_node_info("HUN_Abar3",HUN_Abar2N);

}
#line 3791 "build/hi_desktop/hi.y.cpp"
    break;

  case 174: // HUN_Abar3_End: HUN_Abar3 HUN_AN_Acc
#line 1590 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar3_End->HUN_Abar3 HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_Abar3_End",HUN_Abar3,HUN_AN_Acc);

}
#line 3803 "build/hi_desktop/hi.y.cpp"
    break;

  case 175: // HUN_Abar4: HUN_A0NEG
#line 1599 "build/hi_desktop/hi.y"
{
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_A0NEG");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_A0NEG);

}
#line 3814 "build/hi_desktop/hi.y.cpp"
    break;

  case 176: // HUN_Abar4: HUN_ANEG
#line 1606 "build/hi_desktop/hi.y"
{
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_ANEG");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_ANEG);

}
#line 3825 "build/hi_desktop/hi.y.cpp"
    break;

  case 177: // HUN_Abar4: HUN_Abar3
#line 1613 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar3");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_Abar3);

}
#line 3836 "build/hi_desktop/hi.y.cpp"
    break;

  case 178: // HUN_Abar4: HUN_Abar4 HUN_ConjA
#line 1620 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar4 HUN_ConjA");
yylhs.value=sparser->combine_nodes("HUN_Abar4",HUN_Abar4,HUN_ConjA);

}
#line 3848 "build/hi_desktop/hi.y.cpp"
    break;

  case 179: // HUN_Abar4: HUN_Abar4 HUN_ConjAlist
#line 1628 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar4=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjAlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Abar4 HUN_ConjAlist");
yylhs.value=sparser->combine_nodes("HUN_Abar4",HUN_Abar4,HUN_ConjAlist);

}
#line 3860 "build/hi_desktop/hi.y.cpp"
    break;

  case 180: // HUN_Abar4: HUN_Alist
#line 1636 "build/hi_desktop/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Abar4->HUN_Alist");
yylhs.value=sparser->set_node_info("HUN_Abar4",HUN_Alist);

}
#line 3871 "build/hi_desktop/hi.y.cpp"
    break;

  case 181: // HUN_Adj: HUN_Adj_Stem
#line 1644 "build/hi_desktop/hi.y"
{
const node_info& HUN_Adj_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Adj->HUN_Adj_Stem");
yylhs.value=sparser->set_node_info("HUN_Adj",HUN_Adj_Stem);

}
#line 3882 "build/hi_desktop/hi.y.cpp"
    break;

  case 182: // HUN_Adj_Stem: t_HUN_Adj_Stem
#line 1652 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Adj_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Adj_Stem",word);

}
#line 3894 "build/hi_desktop/hi.y.cpp"
    break;

  case 183: // HUN_Alist: HUN_Abar3 HUN_Abar3
#line 1661 "build/hi_desktop/hi.y"
{
const node_info& HUN_Abar31=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar32=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist->HUN_Abar3 HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_Alist",HUN_Abar31,HUN_Abar32);

}
#line 3906 "build/hi_desktop/hi.y.cpp"
    break;

  case 184: // HUN_Alist: HUN_Alist HUN_Abar3
#line 1669 "build/hi_desktop/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist->HUN_Alist HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_Alist",HUN_Alist,HUN_Abar3);

}
#line 3918 "build/hi_desktop/hi.y.cpp"
    break;

  case 185: // HUN_Alist_End: HUN_Alist HUN_AN_Acc
#line 1678 "build/hi_desktop/hi.y"
{
const node_info& HUN_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Alist_End->HUN_Alist HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_Alist_End",HUN_Alist,HUN_AN_Acc);

}
#line 3930 "build/hi_desktop/hi.y.cpp"
    break;

  case 186: // HUN_Con: HUN_lfea_swConsonant HUN_Con
#line 1687 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Con->HUN_lfea_swConsonant HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_Con",HUN_lfea_swConsonant,HUN_Con);

}
#line 3942 "build/hi_desktop/hi.y.cpp"
    break;

  case 187: // HUN_Con: HUN_lfea_swVowel HUN_Con
#line 1695 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Con->HUN_lfea_swVowel HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_Con",HUN_lfea_swVowel,HUN_Con);

}
#line 3954 "build/hi_desktop/hi.y.cpp"
    break;

  case 188: // HUN_Con: t_HUN_CON_Stem
#line 1703 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con",word);

}
#line 3966 "build/hi_desktop/hi.y.cpp"
    break;

  case 189: // HUN_Con_lfea_Acc: t_HUN_CON_Acc
#line 1712 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Acc",word);

}
#line 3978 "build/hi_desktop/hi.y.cpp"
    break;

  case 190: // HUN_Con_lfea_Dat: t_HUN_CON_Dat
#line 1721 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Dat",word);

}
#line 3990 "build/hi_desktop/hi.y.cpp"
    break;

  case 191: // HUN_Con_lfea_Ins: t_HUN_CON_Ins
#line 1730 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Ins);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Ins",word);

}
#line 4002 "build/hi_desktop/hi.y.cpp"
    break;

  case 192: // HUN_Con_lfea_Sub: t_HUN_CON_Sub
#line 1739 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_Sub);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Con_lfea_Sub",word);

}
#line 4014 "build/hi_desktop/hi.y.cpp"
    break;

  case 193: // HUN_Conj: HUN_Conj_Stem
#line 1748 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Conj->HUN_Conj_Stem");
yylhs.value=sparser->set_node_info("HUN_Conj",HUN_Conj_Stem);

}
#line 4025 "build/hi_desktop/hi.y.cpp"
    break;

  case 194: // HUN_ConjA: HUN_Conj HUN_A0NEG
#line 1756 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_A0NEG");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_A0NEG);

}
#line 4037 "build/hi_desktop/hi.y.cpp"
    break;

  case 195: // HUN_ConjA: HUN_Conj HUN_ANEG
#line 1764 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ANEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_ANEG");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_ANEG);

}
#line 4049 "build/hi_desktop/hi.y.cpp"
    break;

  case 196: // HUN_ConjA: HUN_Conj HUN_Abar3
#line 1772 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_Abar3);

}
#line 4061 "build/hi_desktop/hi.y.cpp"
    break;

  case 197: // HUN_ConjA: HUN_Conj HUN_Alist
#line 1780 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA->HUN_Conj HUN_Alist");
yylhs.value=sparser->combine_nodes("HUN_ConjA",HUN_Conj,HUN_Alist);

}
#line 4073 "build/hi_desktop/hi.y.cpp"
    break;

  case 198: // HUN_ConjA_End: HUN_ConjA HUN_AN_Acc
#line 1789 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AN_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_AN_Acc");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_AN_Acc);

}
#line 4085 "build/hi_desktop/hi.y.cpp"
    break;

  case 199: // HUN_ConjA_End: HUN_ConjA HUN_Abar3_End
#line 1797 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_Abar3_End");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_Abar3_End);

}
#line 4097 "build/hi_desktop/hi.y.cpp"
    break;

  case 200: // HUN_ConjA_End: HUN_ConjA HUN_Alist_End
#line 1805 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist_End=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjA_End->HUN_ConjA HUN_Alist_End");
yylhs.value=sparser->combine_nodes("HUN_ConjA_End",HUN_ConjA,HUN_Alist_End);

}
#line 4109 "build/hi_desktop/hi.y.cpp"
    break;

  case 201: // HUN_ConjAlist: HUN_ConjA HUN_Abar3
#line 1814 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjAlist->HUN_ConjA HUN_Abar3");
yylhs.value=sparser->combine_nodes("HUN_ConjAlist",HUN_ConjA,HUN_Abar3);

}
#line 4121 "build/hi_desktop/hi.y.cpp"
    break;

  case 202: // HUN_ConjAlist: HUN_ConjA HUN_Alist
#line 1822 "build/hi_desktop/hi.y"
{
const node_info& HUN_ConjA=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjAlist->HUN_ConjA HUN_Alist");
yylhs.value=sparser->combine_nodes("HUN_ConjAlist",HUN_ConjA,HUN_Alist);

}
#line 4133 "build/hi_desktop/hi.y.cpp"
    break;

  case 203: // HUN_ConjN: HUN_N_Sg HUN_ConjNbar1
#line 1831 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjNbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjN->HUN_N_Sg HUN_ConjNbar1");
yylhs.value=sparser->combine_nodes("HUN_ConjN",HUN_N_Sg,HUN_ConjNbar1);

}
#line 4145 "build/hi_desktop/hi.y.cpp"
    break;

  case 204: // HUN_ConjNbar1: HUN_Conj HUN_N_Sg
#line 1840 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjNbar1->HUN_Conj HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_ConjNbar1",HUN_Conj,HUN_N_Sg);

}
#line 4157 "build/hi_desktop/hi.y.cpp"
    break;

  case 205: // HUN_ConjV: HUN_Conj HUN_INVP
#line 1849 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_INVP);

}
#line 4169 "build/hi_desktop/hi.y.cpp"
    break;

  case 206: // HUN_ConjV: HUN_Conj HUN_IVP
#line 1857 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_IVP);

}
#line 4181 "build/hi_desktop/hi.y.cpp"
    break;

  case 207: // HUN_ConjV: HUN_Conj HUN_IVPlist
#line 1865 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ConjV->HUN_Conj HUN_IVPlist");
yylhs.value=sparser->combine_nodes("HUN_ConjV",HUN_Conj,HUN_IVPlist);

}
#line 4193 "build/hi_desktop/hi.y.cpp"
    break;

  case 208: // HUN_Conj_Stem: t_HUN_Conj_Stem
#line 1874 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Conj_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Conj_Stem",word);

}
#line 4205 "build/hi_desktop/hi.y.cpp"
    break;

  case 209: // HUN_DP: HUN_DPbar HUN_N_Acc
#line 1883 "build/hi_desktop/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Acc);

}
#line 4217 "build/hi_desktop/hi.y.cpp"
    break;

  case 210: // HUN_DP: HUN_DPbar HUN_N_Dat
#line 1891 "build/hi_desktop/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Dat);

}
#line 4229 "build/hi_desktop/hi.y.cpp"
    break;

  case 211: // HUN_DP: HUN_DPbar HUN_N_Ine
#line 1899 "build/hi_desktop/hi.y"
{
const node_info& HUN_DPbar=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DP->HUN_DPbar HUN_N_Ine");
yylhs.value=sparser->combine_nodes("HUN_DP",HUN_DPbar,HUN_N_Ine);

}
#line 4241 "build/hi_desktop/hi.y.cpp"
    break;

  case 212: // HUN_DPbar: HUN_Def_Det_a HUN_lfea_swConsonant
#line 1908 "build/hi_desktop/hi.y"
{
const node_info& HUN_Def_Det_a=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_a HUN_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_a,HUN_lfea_swConsonant);

}
#line 4253 "build/hi_desktop/hi.y.cpp"
    break;

  case 213: // HUN_DPbar: HUN_Def_Det_az HUN_lfea_swVowel
#line 1916 "build/hi_desktop/hi.y"
{
const node_info& HUN_Def_Det_az=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_DPbar->HUN_Def_Det_az HUN_lfea_swVowel");
yylhs.value=sparser->combine_nodes("HUN_DPbar",HUN_Def_Det_az,HUN_lfea_swVowel);

}
#line 4265 "build/hi_desktop/hi.y.cpp"
    break;

  case 214: // HUN_Def_Det: HUN_Det_stem HUN_lfea_DefDet
#line 1925 "build/hi_desktop/hi.y"
{
const node_info& HUN_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_DefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det->HUN_Det_stem HUN_lfea_DefDet");
yylhs.value=sparser->combine_nodes("HUN_Def_Det",HUN_Det_stem,HUN_lfea_DefDet);

}
#line 4277 "build/hi_desktop/hi.y.cpp"
    break;

  case 215: // HUN_Def_Det_a: HUN_Def_Det HUN_lfea_fwConsonant
#line 1934 "build/hi_desktop/hi.y"
{
const node_info& HUN_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_fwConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det_a->HUN_Def_Det HUN_lfea_fwConsonant");
yylhs.value=sparser->combine_nodes("HUN_Def_Det_a",HUN_Def_Det,HUN_lfea_fwConsonant);

}
#line 4289 "build/hi_desktop/hi.y.cpp"
    break;

  case 216: // HUN_Def_Det_az: HUN_Def_Det HUN_lfea_fwVowel
#line 1943 "build/hi_desktop/hi.y"
{
const node_info& HUN_Def_Det=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_lfea_fwVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Def_Det_az->HUN_Def_Det HUN_lfea_fwVowel");
yylhs.value=sparser->combine_nodes("HUN_Def_Det_az",HUN_Def_Det,HUN_lfea_fwVowel);

}
#line 4301 "build/hi_desktop/hi.y.cpp"
    break;

  case 217: // HUN_Det_stem: t_HUN_Det_Stem
#line 1952 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Det_stem",word);

}
#line 4313 "build/hi_desktop/hi.y.cpp"
    break;

  case 218: // HUN_Empty: %empty
#line 1961 "build/hi_desktop/hi.y"
{
lexicon empty;
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Empty->%empty");
yylhs.value=sparser->set_node_info("HUN_Empty",empty);
}
#line 4323 "build/hi_desktop/hi.y.cpp"
    break;

  case 219: // HUN_INVP: HUN_NP HUN_INVPbar2
#line 1968 "build/hi_desktop/hi.y"
{
const node_info& HUN_NP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVPbar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_NP HUN_INVPbar2");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_NP,HUN_INVPbar2);

}
#line 4335 "build/hi_desktop/hi.y.cpp"
    break;

  case 220: // HUN_INVP: HUN_Neg HUN_INVPbar
#line 1976 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_Neg HUN_INVPbar");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_Neg,HUN_INVPbar);

}
#line 4347 "build/hi_desktop/hi.y.cpp"
    break;

  case 221: // HUN_INVP: HUN_Neg HUN_IVPbar
#line 1984 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVP->HUN_Neg HUN_IVPbar");
yylhs.value=sparser->combine_nodes("HUN_INVP",HUN_Neg,HUN_IVPbar);

}
#line 4359 "build/hi_desktop/hi.y.cpp"
    break;

  case 222: // HUN_INVPbar: HUN_V HUN_N_Ins
#line 1993 "build/hi_desktop/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar->HUN_V HUN_N_Ins");
yylhs.value=sparser->combine_nodes("HUN_INVPbar",HUN_V,HUN_N_Ins);
}
#line 4371 "build/hi_desktop/hi.y.cpp"
    break;

  case 223: // HUN_INVPbar: HUN_V HUN_N_Sub
#line 2001 "build/hi_desktop/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar->HUN_V HUN_N_Sub");
yylhs.value=sparser->combine_nodes("HUN_INVPbar",HUN_V,HUN_N_Sub);
}
#line 4383 "build/hi_desktop/hi.y.cpp"
    break;

  case 224: // HUN_INVPbar2: HUN_Neg HUN_V
#line 2010 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_INVPbar2->HUN_Neg HUN_V");
yylhs.value=sparser->combine_nodes("HUN_INVPbar2",HUN_Neg,HUN_V);
}
#line 4395 "build/hi_desktop/hi.y.cpp"
    break;

  case 225: // HUN_IVP: HUN_IVPbar
#line 2019 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPbar=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVP->HUN_IVPbar");
yylhs.value=sparser->set_node_info("HUN_IVP",HUN_IVPbar);

}
#line 4406 "build/hi_desktop/hi.y.cpp"
    break;

  case 226: // HUN_IVPConj: HUN_IVPConj HUN_ConjV
#line 2027 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPConj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_IVPConj HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_IVPConj,HUN_ConjV);

}
#line 4418 "build/hi_desktop/hi.y.cpp"
    break;

  case 227: // HUN_IVPConj: HUN_Vhead HUN_ConjV
#line 2035 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vhead=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_Vhead HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_Vhead,HUN_ConjV);

}
#line 4430 "build/hi_desktop/hi.y.cpp"
    break;

  case 228: // HUN_IVPConj: HUN_Vlisthead HUN_ConjV
#line 2043 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vlisthead=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPConj->HUN_Vlisthead HUN_ConjV");
yylhs.value=sparser->combine_nodes("HUN_IVPConj",HUN_Vlisthead,HUN_ConjV);

}
#line 4442 "build/hi_desktop/hi.y.cpp"
    break;

  case 229: // HUN_IVPbar: HUN_N_Acc HUN_V
#line 2052 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Acc HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_V,HUN_N_Acc);
}
#line 4454 "build/hi_desktop/hi.y.cpp"
    break;

  case 230: // HUN_IVPbar: HUN_N_Ins HUN_V
#line 2060 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Ins HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_N_Ins,HUN_V);
}
#line 4466 "build/hi_desktop/hi.y.cpp"
    break;

  case 231: // HUN_IVPbar: HUN_N_Sub HUN_V
#line 2068 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_N_Sub HUN_V");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_N_Sub,HUN_V);
}
#line 4478 "build/hi_desktop/hi.y.cpp"
    break;

  case 232: // HUN_IVPbar: HUN_V HUN_N_Acc
#line 2076 "build/hi_desktop/hi.y"
{
const node_info& HUN_V=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_V,"Verb",std::string("RCV"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPbar->HUN_V HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_IVPbar",HUN_V,HUN_N_Acc);
}
#line 4490 "build/hi_desktop/hi.y.cpp"
    break;

  case 233: // HUN_IVPlist: HUN_INVP HUN_INVP
#line 2085 "build/hi_desktop/hi.y"
{
const node_info& HUN_INVP1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_INVP HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_INVP1,HUN_INVP2);

}
#line 4502 "build/hi_desktop/hi.y.cpp"
    break;

  case 234: // HUN_IVPlist: HUN_INVP HUN_IVP
#line 2093 "build/hi_desktop/hi.y"
{
const node_info& HUN_INVP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_INVP HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_INVP,HUN_IVP);

}
#line 4514 "build/hi_desktop/hi.y.cpp"
    break;

  case 235: // HUN_IVPlist: HUN_IVP HUN_INVP
#line 2101 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVP HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVP,HUN_INVP);

}
#line 4526 "build/hi_desktop/hi.y.cpp"
    break;

  case 236: // HUN_IVPlist: HUN_IVP HUN_IVP
#line 2109 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVP1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVP HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVP1,HUN_IVP2);

}
#line 4538 "build/hi_desktop/hi.y.cpp"
    break;

  case 237: // HUN_IVPlist: HUN_IVPlist HUN_INVP
#line 2117 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVPlist HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVPlist,HUN_INVP);

}
#line 4550 "build/hi_desktop/hi.y.cpp"
    break;

  case 238: // HUN_IVPlist: HUN_IVPlist HUN_IVP
#line 2125 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IVPlist->HUN_IVPlist HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_IVPlist",HUN_IVPlist,HUN_IVP);

}
#line 4562 "build/hi_desktop/hi.y.cpp"
    break;

  case 239: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2
#line 2134 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_ConjDefSg2=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjDefSg2");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjDefSg2);
}
#line 4574 "build/hi_desktop/hi.y.cpp"
    break;

  case 240: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_ConjIndefSg2
#line 2142 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_ConjIndefSg2=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_ConjIndefSg2");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_ConjIndefSg2);
}
#line 4586 "build/hi_desktop/hi.y.cpp"
    break;

  case 241: // HUN_ImpVerb: HUN_Verb_stem HUN_Verb_lfea_DefSg1
#line 2150 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_DefSg1=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb->HUN_Verb_stem HUN_Verb_lfea_DefSg1");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb",HUN_Verb_stem,HUN_Verb_lfea_DefSg1);
}
#line 4598 "build/hi_desktop/hi.y.cpp"
    break;

  case 242: // HUN_ImpVerbPfx: HUN_ImpVerb HUN_Vbpfx
#line 2159 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Vbpfx=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerbPfx->HUN_ImpVerb HUN_Vbpfx");
yylhs.value=sparser->combine_nodes("HUN_ImpVerbPfx",HUN_ImpVerb,HUN_Vbpfx);

}
#line 4610 "build/hi_desktop/hi.y.cpp"
    break;

  case 243: // HUN_ImpVerb_N_Acc: HUN_ImpVerb HUN_N_Acc
#line 2168 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb_N_Acc->HUN_ImpVerb HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb_N_Acc",HUN_ImpVerb,HUN_N_Acc);

}
#line 4622 "build/hi_desktop/hi.y.cpp"
    break;

  case 244: // HUN_ImpVerb_N_Dat: HUN_ImpVerb HUN_N_Dat
#line 2177 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_ImpVerb_N_Dat->HUN_ImpVerb HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_ImpVerb_N_Dat",HUN_ImpVerb,HUN_N_Dat);

}
#line 4634 "build/hi_desktop/hi.y.cpp"
    break;

  case 245: // HUN_IndVerb: HUN_Verb_stem HUN_Verb_lfea_InDefSg3
#line 2186 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_InDefSg3=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Verb_stem,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_IndVerb->HUN_Verb_stem HUN_Verb_lfea_InDefSg3");
yylhs.value=sparser->combine_nodes("HUN_IndVerb",HUN_Verb_stem,HUN_Verb_lfea_InDefSg3);
}
#line 4646 "build/hi_desktop/hi.y.cpp"
    break;

  case 246: // HUN_NAbar1: HUN_Neg HUN_Abar1
#line 2195 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NAbar1->HUN_Neg HUN_Abar1");
yylhs.value=sparser->combine_nodes("HUN_NAbar1",HUN_Neg,HUN_Abar1);

}
#line 4658 "build/hi_desktop/hi.y.cpp"
    break;

  case 247: // HUN_NP: HUN_N_Acc
#line 2204 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Acc");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Acc);

}
#line 4669 "build/hi_desktop/hi.y.cpp"
    break;

  case 248: // HUN_NP: HUN_N_Ins
#line 2211 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Ins");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Ins);

}
#line 4680 "build/hi_desktop/hi.y.cpp"
    break;

  case 249: // HUN_NP: HUN_N_Sg
#line 2218 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Sg");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Sg);

}
#line 4691 "build/hi_desktop/hi.y.cpp"
    break;

  case 250: // HUN_NP: HUN_N_Sub
#line 2225 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sub=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_NP->HUN_N_Sub");
yylhs.value=sparser->set_node_info("HUN_NP",HUN_N_Sub);

}
#line 4702 "build/hi_desktop/hi.y.cpp"
    break;

  case 251: // HUN_N_Acc: HUN_ANP HUN_Noun_lfea_Acc
#line 2233 "build/hi_desktop/hi.y"
{
const node_info& HUN_ANP=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_ANP HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_ANP,HUN_Noun_lfea_Acc);

}
#line 4714 "build/hi_desktop/hi.y.cpp"
    break;

  case 252: // HUN_N_Acc: HUN_N_Pl HUN_Noun_lfea_Acc
#line 2241 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Pl=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Pl HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Pl,HUN_Noun_lfea_Acc);

}
#line 4726 "build/hi_desktop/hi.y.cpp"
    break;

  case 253: // HUN_N_Acc: HUN_N_Sg HUN_Con_lfea_Acc
#line 2249 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Con_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Con_lfea_Acc);

}
#line 4738 "build/hi_desktop/hi.y.cpp"
    break;

  case 254: // HUN_N_Acc: HUN_N_Sg HUN_Noun_lfea_Acc
#line 2257 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_N_Sg HUN_Noun_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_N_Sg,HUN_Noun_lfea_Acc);

}
#line 4750 "build/hi_desktop/hi.y.cpp"
    break;

  case 255: // HUN_N_Acc: HUN_Num HUN_Num_lfea_Acc
#line 2265 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_Num HUN_Num_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_Num,HUN_Num_lfea_Acc);

}
#line 4762 "build/hi_desktop/hi.y.cpp"
    break;

  case 256: // HUN_N_Acc: HUN_Nums HUN_Num_lfea_Acc
#line 2273 "build/hi_desktop/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Acc->HUN_Nums HUN_Num_lfea_Acc");
yylhs.value=sparser->combine_nodes("HUN_N_Acc",HUN_Nums,HUN_Num_lfea_Acc);

}
#line 4774 "build/hi_desktop/hi.y.cpp"
    break;

  case 257: // HUN_N_Dat: HUN_N_Sg HUN_Con_lfea_Dat
#line 2282 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Con_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Con_lfea_Dat);

}
#line 4786 "build/hi_desktop/hi.y.cpp"
    break;

  case 258: // HUN_N_Dat: HUN_N_Sg HUN_Noun_lfea_Dat
#line 2290 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Noun_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Noun_lfea_Dat);

}
#line 4798 "build/hi_desktop/hi.y.cpp"
    break;

  case 259: // HUN_N_Dat: HUN_N_Sg HUN_Noun_lfea_Del
#line 2298 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Del=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_N_Sg HUN_Noun_lfea_Del");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_N_Sg,HUN_Noun_lfea_Del);

}
#line 4810 "build/hi_desktop/hi.y.cpp"
    break;

  case 260: // HUN_N_Dat: HUN_Num HUN_Num_lfea_Dat
#line 2306 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Num HUN_Num_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Num,HUN_Num_lfea_Dat);

}
#line 4822 "build/hi_desktop/hi.y.cpp"
    break;

  case 261: // HUN_N_Dat: HUN_Num HUN_Num_lfea_Del
#line 2314 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Del=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Num HUN_Num_lfea_Del");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Num,HUN_Num_lfea_Del);

}
#line 4834 "build/hi_desktop/hi.y.cpp"
    break;

  case 262: // HUN_N_Dat: HUN_Nums HUN_Num_lfea_Dat
#line 2322 "build/hi_desktop/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Dat->HUN_Nums HUN_Num_lfea_Dat");
yylhs.value=sparser->combine_nodes("HUN_N_Dat",HUN_Nums,HUN_Num_lfea_Dat);

}
#line 4846 "build/hi_desktop/hi.y.cpp"
    break;

  case 263: // HUN_N_Ine: HUN_N_Pl HUN_Noun_lfea_Ine
#line 2331 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Pl=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ine->HUN_N_Pl HUN_Noun_lfea_Ine");
yylhs.value=sparser->combine_nodes("HUN_N_Ine",HUN_N_Pl,HUN_Noun_lfea_Ine);

}
#line 4858 "build/hi_desktop/hi.y.cpp"
    break;

  case 264: // HUN_N_Ine: HUN_N_Sg HUN_Noun_lfea_Ine
#line 2339 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Ine=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ine->HUN_N_Sg HUN_Noun_lfea_Ine");
yylhs.value=sparser->combine_nodes("HUN_N_Ine",HUN_N_Sg,HUN_Noun_lfea_Ine);

}
#line 4870 "build/hi_desktop/hi.y.cpp"
    break;

  case 265: // HUN_N_Ins: HUN_N_Sg HUN_Con_lfea_Ins
#line 2348 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Ins->HUN_N_Sg HUN_Con_lfea_Ins");
yylhs.value=sparser->combine_nodes("HUN_N_Ins",HUN_N_Sg,HUN_Con_lfea_Ins);

}
#line 4882 "build/hi_desktop/hi.y.cpp"
    break;

  case 266: // HUN_N_Pl: HUN_Noun_Stem HUN_Noun_lfea_Plur
#line 2357 "build/hi_desktop/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Plur=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Pl->HUN_Noun_Stem HUN_Noun_lfea_Plur");
yylhs.value=sparser->combine_nodes("HUN_N_Pl",HUN_Noun_Stem,HUN_Noun_lfea_Plur);

}
#line 4894 "build/hi_desktop/hi.y.cpp"
    break;

  case 267: // HUN_N_Sg: HUN_1Con
#line 2366 "build/hi_desktop/hi.y"
{
const node_info& HUN_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_1Con");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_1Con);

}
#line 4905 "build/hi_desktop/hi.y.cpp"
    break;

  case 268: // HUN_N_Sg: HUN_Noun_Pref HUN_Noun_Stem
#line 2373 "build/hi_desktop/hi.y"
{
const node_info& HUN_Noun_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_Noun_Pref HUN_Noun_Stem");
yylhs.value=sparser->combine_nodes("HUN_N_Sg",HUN_Noun_Pref,HUN_Noun_Stem);

}
#line 4917 "build/hi_desktop/hi.y.cpp"
    break;

  case 269: // HUN_N_Sg: HUN_Noun_Stem
#line 2381 "build/hi_desktop/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_Noun_Stem");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_Noun_Stem);

}
#line 4928 "build/hi_desktop/hi.y.cpp"
    break;

  case 270: // HUN_N_Sg: HUN_nCon
#line 2388 "build/hi_desktop/hi.y"
{
const node_info& HUN_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sg->HUN_nCon");
yylhs.value=sparser->set_node_info("HUN_N_Sg",HUN_nCon);

}
#line 4939 "build/hi_desktop/hi.y.cpp"
    break;

  case 271: // HUN_N_Sub: HUN_N_Sg HUN_Con_lfea_Sub
#line 2396 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con_lfea_Sub=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sub->HUN_N_Sg HUN_Con_lfea_Sub");
yylhs.value=sparser->combine_nodes("HUN_N_Sub",HUN_N_Sg,HUN_Con_lfea_Sub);

}
#line 4951 "build/hi_desktop/hi.y.cpp"
    break;

  case 272: // HUN_N_Sub: HUN_N_Sg HUN_Noun_lfea_Sub
#line 2404 "build/hi_desktop/hi.y"
{
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Sub=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_N_Sub->HUN_N_Sg HUN_Noun_lfea_Sub");
yylhs.value=sparser->combine_nodes("HUN_N_Sub",HUN_N_Sg,HUN_Noun_lfea_Sub);

}
#line 4963 "build/hi_desktop/hi.y.cpp"
    break;

  case 273: // HUN_Neg: HUN_Neg_Stem
#line 2413 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Neg->HUN_Neg_Stem");
yylhs.value=sparser->set_node_info("HUN_Neg",HUN_Neg_Stem);

}
#line 4974 "build/hi_desktop/hi.y.cpp"
    break;

  case 274: // HUN_Neg_Stem: t_HUN_Neg_Stem
#line 2421 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Neg_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Neg_Stem",word);

}
#line 4986 "build/hi_desktop/hi.y.cpp"
    break;

  case 275: // HUN_Noun_Pref: t_HUN_Noun_Pref
#line 2430 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Pref);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_Pref",word);

}
#line 4998 "build/hi_desktop/hi.y.cpp"
    break;

  case 276: // HUN_Noun_Stem: HUN_lfea_swConsonant HUN_Noun_Stem
#line 2439 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Noun_Stem->HUN_lfea_swConsonant HUN_Noun_Stem");
yylhs.value=sparser->combine_nodes("HUN_Noun_Stem",HUN_lfea_swConsonant,HUN_Noun_Stem);

}
#line 5010 "build/hi_desktop/hi.y.cpp"
    break;

  case 277: // HUN_Noun_Stem: HUN_lfea_swVowel HUN_Noun_Stem
#line 2447 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Noun_Stem->HUN_lfea_swVowel HUN_Noun_Stem");
yylhs.value=sparser->combine_nodes("HUN_Noun_Stem",HUN_lfea_swVowel,HUN_Noun_Stem);

}
#line 5022 "build/hi_desktop/hi.y.cpp"
    break;

  case 278: // HUN_Noun_Stem: t_HUN_Noun_Stem
#line 2455 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_Stem",word);

}
#line 5034 "build/hi_desktop/hi.y.cpp"
    break;

  case 279: // HUN_Noun_lfea_Acc: t_HUN_Noun_Acc
#line 2464 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Acc",word);

}
#line 5046 "build/hi_desktop/hi.y.cpp"
    break;

  case 280: // HUN_Noun_lfea_Dat: t_HUN_Noun_Dat
#line 2473 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Dat",word);

}
#line 5058 "build/hi_desktop/hi.y.cpp"
    break;

  case 281: // HUN_Noun_lfea_Del: t_HUN_Noun_Del
#line 2482 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Del);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Del",word);

}
#line 5070 "build/hi_desktop/hi.y.cpp"
    break;

  case 282: // HUN_Noun_lfea_Ine: t_HUN_Noun_Ine
#line 2491 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Ine);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Ine",word);

}
#line 5082 "build/hi_desktop/hi.y.cpp"
    break;

  case 283: // HUN_Noun_lfea_Plur: t_HUN_Noun_Plur
#line 2500 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Plur);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Plur",word);

}
#line 5094 "build/hi_desktop/hi.y.cpp"
    break;

  case 284: // HUN_Noun_lfea_Relative: t_HUN_Noun_Relative
#line 2509 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Relative",word);

}
#line 5106 "build/hi_desktop/hi.y.cpp"
    break;

  case 285: // HUN_Noun_lfea_Sub: t_HUN_Noun_Sub
#line 2518 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_Sub);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Noun_lfea_Sub",word);

}
#line 5118 "build/hi_desktop/hi.y.cpp"
    break;

  case 286: // HUN_Num: HUN_Num HUN_Num_lfea_Ik
#line 2527 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Ik=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Ik");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Ik);

}
#line 5130 "build/hi_desktop/hi.y.cpp"
    break;

  case 287: // HUN_Num: HUN_Num HUN_Num_lfea_Par
#line 2535 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num_lfea_Par=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num HUN_Num_lfea_Par");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num,HUN_Num_lfea_Par);

}
#line 5142 "build/hi_desktop/hi.y.cpp"
    break;

  case 288: // HUN_Num: HUN_Num_Pref HUN_Num
#line 2543 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num_Pref HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_Num_Pref,HUN_Num);

}
#line 5154 "build/hi_desktop/hi.y.cpp"
    break;

  case 289: // HUN_Num: HUN_Num_Stem
#line 2551 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_Num_Stem");
yylhs.value=sparser->set_node_info("HUN_Num",HUN_Num_Stem);

}
#line 5165 "build/hi_desktop/hi.y.cpp"
    break;

  case 290: // HUN_Num: HUN_lfea_swConsonant HUN_Num
#line 2558 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swConsonant=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_lfea_swConsonant HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_lfea_swConsonant,HUN_Num);

}
#line 5177 "build/hi_desktop/hi.y.cpp"
    break;

  case 291: // HUN_Num: HUN_lfea_swVowel HUN_Num
#line 2566 "build/hi_desktop/hi.y"
{
const node_info& HUN_lfea_swVowel=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Num->HUN_lfea_swVowel HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Num",HUN_lfea_swVowel,HUN_Num);

}
#line 5189 "build/hi_desktop/hi.y.cpp"
    break;

  case 292: // HUN_Num_Pref: t_HUN_Num_Npref1
#line 2575 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5201 "build/hi_desktop/hi.y.cpp"
    break;

  case 293: // HUN_Num_Pref: t_HUN_Num_Npref1n
#line 2583 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5213 "build/hi_desktop/hi.y.cpp"
    break;

  case 294: // HUN_Num_Pref: t_HUN_Num_Npref1nn
#line 2591 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1nn);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5225 "build/hi_desktop/hi.y.cpp"
    break;

  case 295: // HUN_Num_Pref: t_HUN_Num_Npref1nnn
#line 2599 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref1nnn);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5237 "build/hi_desktop/hi.y.cpp"
    break;

  case 296: // HUN_Num_Pref: t_HUN_Num_Npref2
#line 2607 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5249 "build/hi_desktop/hi.y.cpp"
    break;

  case 297: // HUN_Num_Pref: t_HUN_Num_Npref2n
#line 2615 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5261 "build/hi_desktop/hi.y.cpp"
    break;

  case 298: // HUN_Num_Pref: t_HUN_Num_Npref3
#line 2623 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5273 "build/hi_desktop/hi.y.cpp"
    break;

  case 299: // HUN_Num_Pref: t_HUN_Num_Npref3n
#line 2631 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5285 "build/hi_desktop/hi.y.cpp"
    break;

  case 300: // HUN_Num_Pref: t_HUN_Num_Npref4
#line 2639 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref4);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5297 "build/hi_desktop/hi.y.cpp"
    break;

  case 301: // HUN_Num_Pref: t_HUN_Num_Npref4n
#line 2647 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5309 "build/hi_desktop/hi.y.cpp"
    break;

  case 302: // HUN_Num_Pref: t_HUN_Num_Npref5
#line 2655 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref5);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5321 "build/hi_desktop/hi.y.cpp"
    break;

  case 303: // HUN_Num_Pref: t_HUN_Num_Npref5n
#line 2663 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5333 "build/hi_desktop/hi.y.cpp"
    break;

  case 304: // HUN_Num_Pref: t_HUN_Num_Npref6
#line 2671 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref6);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5345 "build/hi_desktop/hi.y.cpp"
    break;

  case 305: // HUN_Num_Pref: t_HUN_Num_Npref6n
#line 2679 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5357 "build/hi_desktop/hi.y.cpp"
    break;

  case 306: // HUN_Num_Pref: t_HUN_Num_Npref7
#line 2687 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref7);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5369 "build/hi_desktop/hi.y.cpp"
    break;

  case 307: // HUN_Num_Pref: t_HUN_Num_Npref7n
#line 2695 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5381 "build/hi_desktop/hi.y.cpp"
    break;

  case 308: // HUN_Num_Pref: t_HUN_Num_Npref8
#line 2703 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref8);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5393 "build/hi_desktop/hi.y.cpp"
    break;

  case 309: // HUN_Num_Pref: t_HUN_Num_Npref8n
#line 2711 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5405 "build/hi_desktop/hi.y.cpp"
    break;

  case 310: // HUN_Num_Pref: t_HUN_Num_Npref9
#line 2719 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref9);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5417 "build/hi_desktop/hi.y.cpp"
    break;

  case 311: // HUN_Num_Pref: t_HUN_Num_Npref9n
#line 2727 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Pref",word);

}
#line 5429 "build/hi_desktop/hi.y.cpp"
    break;

  case 312: // HUN_Num_Stem: t_HUN_Num_Stem
#line 2736 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_Stem",word);

}
#line 5441 "build/hi_desktop/hi.y.cpp"
    break;

  case 313: // HUN_Num_lfea_Acc: t_HUN_Num_Acc
#line 2745 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Acc);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Acc",word);

}
#line 5453 "build/hi_desktop/hi.y.cpp"
    break;

  case 314: // HUN_Num_lfea_Dat: t_HUN_Num_Dat
#line 2754 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Dat);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Dat",word);

}
#line 5465 "build/hi_desktop/hi.y.cpp"
    break;

  case 315: // HUN_Num_lfea_Del: t_HUN_Num_Del
#line 2763 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Del);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Del",word);

}
#line 5477 "build/hi_desktop/hi.y.cpp"
    break;

  case 316: // HUN_Num_lfea_Ik: t_HUN_Num_Ik
#line 2772 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Ik);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Ik",word);

}
#line 5489 "build/hi_desktop/hi.y.cpp"
    break;

  case 317: // HUN_Num_lfea_Par: t_HUN_Num_Par
#line 2781 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_Par);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Num_lfea_Par",word);

}
#line 5501 "build/hi_desktop/hi.y.cpp"
    break;

  case 318: // HUN_Nums: HUN_Num HUN_Num
#line 2790 "build/hi_desktop/hi.y"
{
const node_info& HUN_Num1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Nums->HUN_Num HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Nums",HUN_Num1,HUN_Num2);

}
#line 5513 "build/hi_desktop/hi.y.cpp"
    break;

  case 319: // HUN_Nums: HUN_Nums HUN_Num
#line 2798 "build/hi_desktop/hi.y"
{
const node_info& HUN_Nums=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Nums->HUN_Nums HUN_Num");
yylhs.value=sparser->combine_nodes("HUN_Nums",HUN_Nums,HUN_Num);

}
#line 5525 "build/hi_desktop/hi.y.cpp"
    break;

  case 320: // HUN_Pron_Int: HUN_Pron_Int HUN_Pron_lfea_Nom
#line 2807 "build/hi_desktop/hi.y"
{
const node_info& HUN_Pron_Int=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Pron_lfea_Nom=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Pron_Int->HUN_Pron_Int HUN_Pron_lfea_Nom");
yylhs.value=sparser->combine_nodes("HUN_Pron_Int",HUN_Pron_Int,HUN_Pron_lfea_Nom);

}
#line 5537 "build/hi_desktop/hi.y.cpp"
    break;

  case 321: // HUN_Pron_Int: HUN_Pron_Stem HUN_Pron_lfea_Int
#line 2815 "build/hi_desktop/hi.y"
{
const node_info& HUN_Pron_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Pron_lfea_Int=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Pron_Int->HUN_Pron_Stem HUN_Pron_lfea_Int");
yylhs.value=sparser->combine_nodes("HUN_Pron_Int",HUN_Pron_Stem,HUN_Pron_lfea_Int);

}
#line 5549 "build/hi_desktop/hi.y.cpp"
    break;

  case 322: // HUN_Pron_Stem: t_HUN_Pronoun_Stem
#line 2824 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Pron_Stem",word);

}
#line 5561 "build/hi_desktop/hi.y.cpp"
    break;

  case 323: // HUN_Pron_lfea_Int: t_HUN_Pronoun_Int
#line 2833 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Int);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Pron_lfea_Int",word);

}
#line 5573 "build/hi_desktop/hi.y.cpp"
    break;

  case 324: // HUN_Pron_lfea_Nom: t_HUN_Pronoun_Nom
#line 2842 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Pronoun_Nom);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Pron_lfea_Nom",word);

}
#line 5585 "build/hi_desktop/hi.y.cpp"
    break;

  case 325: // HUN_Punct: HUN_Punct_Stem HUN_Punct_ExclamationMark
#line 2851 "build/hi_desktop/hi.y"
{
const node_info& HUN_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Punct_ExclamationMark=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_ExclamationMark");
yylhs.value=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_ExclamationMark);

}
#line 5597 "build/hi_desktop/hi.y.cpp"
    break;

  case 326: // HUN_Punct: HUN_Punct_Stem HUN_Punct_FullStop
#line 2859 "build/hi_desktop/hi.y"
{
const node_info& HUN_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Punct_FullStop=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_FullStop");
yylhs.value=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_FullStop);

}
#line 5609 "build/hi_desktop/hi.y.cpp"
    break;

  case 327: // HUN_Punct: HUN_Punct_Stem HUN_Punct_QuestionMark
#line 2867 "build/hi_desktop/hi.y"
{
const node_info& HUN_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Punct_QuestionMark=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Punct->HUN_Punct_Stem HUN_Punct_QuestionMark");
yylhs.value=sparser->combine_nodes("HUN_Punct",HUN_Punct_Stem,HUN_Punct_QuestionMark);

}
#line 5621 "build/hi_desktop/hi.y.cpp"
    break;

  case 328: // HUN_Punct_ExclamationMark: t_HUN_Punct_ExclamationMark
#line 2876 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_ExclamationMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Punct_ExclamationMark",word);

}
#line 5633 "build/hi_desktop/hi.y.cpp"
    break;

  case 329: // HUN_Punct_FullStop: t_HUN_Punct_FullStop
#line 2885 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_FullStop);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Punct_FullStop",word);

}
#line 5645 "build/hi_desktop/hi.y.cpp"
    break;

  case 330: // HUN_Punct_QuestionMark: t_HUN_Punct_QuestionMark
#line 2894 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_QuestionMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Punct_QuestionMark",word);

}
#line 5657 "build/hi_desktop/hi.y.cpp"
    break;

  case 331: // HUN_Punct_Stem: t_HUN_Punct_Stem
#line 2903 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Punct_Stem",word);

}
#line 5669 "build/hi_desktop/hi.y.cpp"
    break;

  case 332: // HUN_RC: HUN_Conj HUN_N_Sg
#line 2912 "build/hi_desktop/hi.y"
{
const node_info& HUN_Conj=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_Conj HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_Conj,HUN_N_Sg);

}
#line 5681 "build/hi_desktop/hi.y.cpp"
    break;

  case 333: // HUN_RC: HUN_RPro HUN_INVP
#line 2920 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_INVP");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_INVP);

}
#line 5693 "build/hi_desktop/hi.y.cpp"
    break;

  case 334: // HUN_RC: HUN_RPro HUN_IVP
#line 2928 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVP");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVP);

}
#line 5705 "build/hi_desktop/hi.y.cpp"
    break;

  case 335: // HUN_RC: HUN_RPro HUN_IVPConj
#line 2936 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPConj=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVPConj");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVPConj);

}
#line 5717 "build/hi_desktop/hi.y.cpp"
    break;

  case 336: // HUN_RC: HUN_RPro HUN_IVPlist
#line 2944 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RC->HUN_RPro HUN_IVPlist");
yylhs.value=sparser->combine_nodes("HUN_RC",HUN_RPro,HUN_IVPlist);

}
#line 5729 "build/hi_desktop/hi.y.cpp"
    break;

  case 337: // HUN_RPro: HUN_Noun_Stem HUN_Noun_lfea_Relative
#line 2953 "build/hi_desktop/hi.y"
{
const node_info& HUN_Noun_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RPro->HUN_Noun_Stem HUN_Noun_lfea_Relative");
yylhs.value=sparser->combine_nodes("HUN_RPro",HUN_Noun_Stem,HUN_Noun_lfea_Relative);

}
#line 5741 "build/hi_desktop/hi.y.cpp"
    break;

  case 338: // HUN_RPro: HUN_RPro HUN_Noun_lfea_Plur
#line 2961 "build/hi_desktop/hi.y"
{
const node_info& HUN_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Noun_lfea_Plur=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_RPro->HUN_RPro HUN_Noun_lfea_Plur");
yylhs.value=sparser->combine_nodes("HUN_RPro",HUN_RPro,HUN_Noun_lfea_Plur);

}
#line 5753 "build/hi_desktop/hi.y.cpp"
    break;

  case 339: // HUN_V: HUN_Verb_stem HUN_Verb_lfea_IndefPl3
#line 2970 "build/hi_desktop/hi.y"
{
const node_info& HUN_Verb_stem=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Verb_lfea_IndefPl3=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_V->HUN_Verb_stem HUN_Verb_lfea_IndefPl3");
yylhs.value=sparser->combine_nodes("HUN_V",HUN_Verb_stem,HUN_Verb_lfea_IndefPl3);

}
#line 5765 "build/hi_desktop/hi.y.cpp"
    break;

  case 340: // HUN_VP: HUN_ImpVerb HUN_AP
#line 2979 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_AP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_AP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_AP);

}
#line 5777 "build/hi_desktop/hi.y.cpp"
    break;

  case 341: // HUN_VP: HUN_ImpVerb HUN_DP
#line 2987 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_DP);

}
#line 5789 "build/hi_desktop/hi.y.cpp"
    break;

  case 342: // HUN_VP: HUN_ImpVerb HUN_Empty
#line 2995 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Empty=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerb HUN_Empty");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerb,HUN_Empty);

}
#line 5801 "build/hi_desktop/hi.y.cpp"
    break;

  case 343: // HUN_VP: HUN_ImpVerbPfx HUN_DP
#line 3003 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_DP);

}
#line 5813 "build/hi_desktop/hi.y.cpp"
    break;

  case 344: // HUN_VP: HUN_ImpVerbPfx HUN_NP
#line 3011 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerbPfx=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_ImpVerbPfx HUN_NP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_ImpVerbPfx,HUN_NP);

}
#line 5825 "build/hi_desktop/hi.y.cpp"
    break;

  case 345: // HUN_VP: HUN_IndVerb HUN_ConjN
#line 3019 "build/hi_desktop/hi.y"
{
const node_info& HUN_IndVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ConjN=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_ConjN,"Conj","qword",false,true);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_IndVerb HUN_ConjN");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_IndVerb,HUN_ConjN);
}
#line 5837 "build/hi_desktop/hi.y.cpp"
    break;

  case 346: // HUN_VP: HUN_IndVerb HUN_N_Sg
#line 3027 "build/hi_desktop/hi.y"
{
const node_info& HUN_IndVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_IndVerb HUN_N_Sg");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_IndVerb,HUN_N_Sg);

}
#line 5849 "build/hi_desktop/hi.y.cpp"
    break;

  case 347: // HUN_VP: HUN_Neg HUN_ImpVerb
#line 3035 "build/hi_desktop/hi.y"
{
const node_info& HUN_Neg=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Neg HUN_ImpVerb");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Neg,HUN_ImpVerb);

}
#line 5861 "build/hi_desktop/hi.y.cpp"
    break;

  case 348: // HUN_VP: HUN_Pron_Int HUN_IndVerb
#line 3043 "build/hi_desktop/hi.y"
{
const node_info& HUN_Pron_Int=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_IndVerb=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_Pron_Int,"Pronoun",std::string("qword"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Pron_Int HUN_IndVerb");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Pron_Int,HUN_IndVerb);
}
#line 5873 "build/hi_desktop/hi.y.cpp"
    break;

  case 349: // HUN_VP: HUN_Vbar1 HUN_NP
#line 3051 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar1 HUN_NP");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar1,HUN_NP);

}
#line 5885 "build/hi_desktop/hi.y.cpp"
    break;

  case 350: // HUN_VP: HUN_Vbar2 HUN_N_Ins
#line 3059 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Ins=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar2 HUN_N_Ins");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar2,HUN_N_Ins);

}
#line 5897 "build/hi_desktop/hi.y.cpp"
    break;

  case 351: // HUN_VP: HUN_Vbar2 HUN_RC
#line 3067 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar2 HUN_RC");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar2,HUN_RC);

}
#line 5909 "build/hi_desktop/hi.y.cpp"
    break;

  case 352: // HUN_VP: HUN_Vbar3 HUN_RC
#line 3075 "build/hi_desktop/hi.y"
{
const node_info& HUN_Vbar3=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_VP->HUN_Vbar3 HUN_RC");
yylhs.value=sparser->combine_nodes("HUN_VP",HUN_Vbar3,HUN_RC);

}
#line 5921 "build/hi_desktop/hi.y.cpp"
    break;

  case 353: // HUN_Vbar1: HUN_ImpVerb HUN_DP
#line 3084 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar1->HUN_ImpVerb HUN_DP");
yylhs.value=sparser->combine_nodes("HUN_Vbar1",HUN_ImpVerb,HUN_DP);

}
#line 5933 "build/hi_desktop/hi.y.cpp"
    break;

  case 354: // HUN_Vbar2: HUN_ImpVerb HUN_N_Acc
#line 3093 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar2->HUN_ImpVerb HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_Vbar2",HUN_ImpVerb,HUN_N_Acc);

}
#line 5945 "build/hi_desktop/hi.y.cpp"
    break;

  case 355: // HUN_Vbar2: HUN_ImpVerb HUN_N_Dat
#line 3101 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar2->HUN_ImpVerb HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_Vbar2",HUN_ImpVerb,HUN_N_Dat);

}
#line 5957 "build/hi_desktop/hi.y.cpp"
    break;

  case 356: // HUN_Vbar3: HUN_ImpVerb_N_Acc HUN_N_Dat
#line 3110 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb_N_Acc=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Dat=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar3->HUN_ImpVerb_N_Acc HUN_N_Dat");
yylhs.value=sparser->combine_nodes("HUN_Vbar3",HUN_ImpVerb_N_Acc,HUN_N_Dat);

}
#line 5969 "build/hi_desktop/hi.y.cpp"
    break;

  case 357: // HUN_Vbar3: HUN_ImpVerb_N_Dat HUN_N_Acc
#line 3118 "build/hi_desktop/hi.y"
{
const node_info& HUN_ImpVerb_N_Dat=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Acc=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vbar3->HUN_ImpVerb_N_Dat HUN_N_Acc");
yylhs.value=sparser->combine_nodes("HUN_Vbar3",HUN_ImpVerb_N_Dat,HUN_N_Acc);

}
#line 5981 "build/hi_desktop/hi.y.cpp"
    break;

  case 358: // HUN_Vbpfx: t_HUN_Vbpfx_Stem
#line 3127 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Vbpfx_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Vbpfx",word);

}
#line 5993 "build/hi_desktop/hi.y.cpp"
    break;

  case 359: // HUN_Verb_lfea_ConjDefSg2: t_HUN_Verb_ConjDefSg2
#line 3136 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_ConjDefSg2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_ConjDefSg2",word);

}
#line 6005 "build/hi_desktop/hi.y.cpp"
    break;

  case 360: // HUN_Verb_lfea_ConjIndefSg2: t_HUN_Verb_ConjIndefSg2
#line 3145 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_ConjIndefSg2);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_ConjIndefSg2",word);

}
#line 6017 "build/hi_desktop/hi.y.cpp"
    break;

  case 361: // HUN_Verb_lfea_DefSg1: t_HUN_Verb_DefSg1
#line 3154 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_DefSg1);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_DefSg1",word);

}
#line 6029 "build/hi_desktop/hi.y.cpp"
    break;

  case 362: // HUN_Verb_lfea_InDefSg3: t_HUN_Verb_IndefSg3
#line 3163 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_IndefSg3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_InDefSg3",word);

}
#line 6041 "build/hi_desktop/hi.y.cpp"
    break;

  case 363: // HUN_Verb_lfea_IndefPl3: t_HUN_Verb_IndefPl3
#line 3172 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_IndefPl3);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_lfea_IndefPl3",word);

}
#line 6053 "build/hi_desktop/hi.y.cpp"
    break;

  case 364: // HUN_Verb_stem: t_HUN_Verb_Stem
#line 3181 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Verb_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_Verb_stem",word);

}
#line 6065 "build/hi_desktop/hi.y.cpp"
    break;

  case 365: // HUN_Vhead: HUN_INVP
#line 3190 "build/hi_desktop/hi.y"
{
const node_info& HUN_INVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vhead->HUN_INVP");
yylhs.value=sparser->set_node_info("HUN_Vhead",HUN_INVP);

}
#line 6076 "build/hi_desktop/hi.y.cpp"
    break;

  case 366: // HUN_Vhead: HUN_IVP
#line 3197 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vhead->HUN_IVP");
yylhs.value=sparser->set_node_info("HUN_Vhead",HUN_IVP);

}
#line 6087 "build/hi_desktop/hi.y.cpp"
    break;

  case 367: // HUN_Vlisthead: HUN_IVPlist
#line 3205 "build/hi_desktop/hi.y"
{
const node_info& HUN_IVPlist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_Vlisthead->HUN_IVPlist");
yylhs.value=sparser->set_node_info("HUN_Vlisthead",HUN_IVPlist);

}
#line 6098 "build/hi_desktop/hi.y.cpp"
    break;

  case 368: // HUN_lfea_DefDet: t_HUN_Det_Def
#line 3213 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_Def);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_DefDet",word);

}
#line 6110 "build/hi_desktop/hi.y.cpp"
    break;

  case 369: // HUN_lfea_fwConsonant: t_HUN_Det_fwConsonant
#line 3222 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_fwConsonant",word);

}
#line 6122 "build/hi_desktop/hi.y.cpp"
    break;

  case 370: // HUN_lfea_fwVowel: t_HUN_Det_fwVowel
#line 3231 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Det_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_fwVowel",word);

}
#line 6134 "build/hi_desktop/hi.y.cpp"
    break;

  case 371: // HUN_lfea_swConsonant: t_HUN_CON_swConsonant
#line 3240 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 6146 "build/hi_desktop/hi.y.cpp"
    break;

  case 372: // HUN_lfea_swConsonant: t_HUN_Noun_swConsonant
#line 3248 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 6158 "build/hi_desktop/hi.y.cpp"
    break;

  case 373: // HUN_lfea_swConsonant: t_HUN_Num_swConsonant
#line 3256 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swConsonant",word);

}
#line 6170 "build/hi_desktop/hi.y.cpp"
    break;

  case 374: // HUN_lfea_swVowel: t_HUN_CON_swVowel
#line 3265 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_CON_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 6182 "build/hi_desktop/hi.y.cpp"
    break;

  case 375: // HUN_lfea_swVowel: t_HUN_Noun_swVowel
#line 3273 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Noun_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 6194 "build/hi_desktop/hi.y.cpp"
    break;

  case 376: // HUN_lfea_swVowel: t_HUN_Num_swVowel
#line 3281 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_HUN_Num_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("HUN_lfea_swVowel",word);

}
#line 6206 "build/hi_desktop/hi.y.cpp"
    break;

  case 377: // HUN_nCon: HUN_1Con HUN_Con
#line 3290 "build/hi_desktop/hi.y"
{
const node_info& HUN_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_nCon->HUN_1Con HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_nCon",HUN_1Con,HUN_Con);

}
#line 6218 "build/hi_desktop/hi.y.cpp"
    break;

  case 378: // HUN_nCon: HUN_nCon HUN_Con
#line 3298 "build/hi_desktop/hi.y"
{
const node_info& HUN_nCon=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"HUN_nCon->HUN_nCon HUN_Con");
yylhs.value=sparser->combine_nodes("HUN_nCon",HUN_nCon,HUN_Con);

}
#line 6230 "build/hi_desktop/hi.y.cpp"
    break;

  case 379: // JSON_Array: JSON_Open_Array JSON_Closing_Value_Element
#line 3307 "build/hi_desktop/hi.y"
{
const node_info& JSON_Open_Array=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Closing_Value_Element=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Array->JSON_Open_Array JSON_Closing_Value_Element");
yylhs.value=sparser->combine_nodes("JSON_Array",JSON_Open_Array,JSON_Closing_Value_Element);

}
#line 6242 "build/hi_desktop/hi.y.cpp"
    break;

  case 380: // JSON_CON: t_JSON_CON_Stem
#line 3316 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_CON",word);

}
#line 6254 "build/hi_desktop/hi.y.cpp"
    break;

  case 381: // JSON_ClosingSBracket: JSON_Punct_Stem JSON_Punct_ClosingSBracket
#line 3325 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_ClosingSBracket->JSON_Punct_Stem JSON_Punct_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_ClosingSBracket",JSON_Punct_Stem,JSON_Punct_ClosingSBracket);

}
#line 6266 "build/hi_desktop/hi.y.cpp"
    break;

  case 382: // JSON_Closing_Value_Element: JSON_Array JSON_ClosingSBracket
#line 3334 "build/hi_desktop/hi.y"
{
const node_info& JSON_Array=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_Array JSON_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_Array,JSON_ClosingSBracket);

}
#line 6278 "build/hi_desktop/hi.y.cpp"
    break;

  case 383: // JSON_Closing_Value_Element: JSON_CON JSON_ClosingSBracket
#line 3342 "build/hi_desktop/hi.y"
{
const node_info& JSON_CON=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_CON JSON_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_CON,JSON_ClosingSBracket);

}
#line 6290 "build/hi_desktop/hi.y.cpp"
    break;

  case 384: // JSON_Closing_Value_Element: JSON_Hash_Ref JSON_ClosingSBracket
#line 3350 "build/hi_desktop/hi.y"
{
const node_info& JSON_Hash_Ref=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_Hash_Ref JSON_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_Hash_Ref,JSON_ClosingSBracket);

}
#line 6302 "build/hi_desktop/hi.y.cpp"
    break;

  case 385: // JSON_Closing_Value_Element: JSON_String JSON_ClosingSBracket
#line 3358 "build/hi_desktop/hi.y"
{
const node_info& JSON_String=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_ClosingSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Closing_Value_Element->JSON_String JSON_ClosingSBracket");
yylhs.value=sparser->combine_nodes("JSON_Closing_Value_Element",JSON_String,JSON_ClosingSBracket);

}
#line 6314 "build/hi_desktop/hi.y.cpp"
    break;

  case 386: // JSON_Colon: JSON_Punct_Stem JSON_Punct_Colon
#line 3367 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_Colon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Colon->JSON_Punct_Stem JSON_Punct_Colon");
yylhs.value=sparser->combine_nodes("JSON_Colon",JSON_Punct_Stem,JSON_Punct_Colon);

}
#line 6326 "build/hi_desktop/hi.y.cpp"
    break;

  case 387: // JSON_Comma: JSON_Punct_Stem JSON_Punct_Comma
#line 3376 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Comma->JSON_Punct_Stem JSON_Punct_Comma");
yylhs.value=sparser->combine_nodes("JSON_Comma",JSON_Punct_Stem,JSON_Punct_Comma);

}
#line 6338 "build/hi_desktop/hi.y.cpp"
    break;

  case 388: // JSON_Hash: JSON_Punct_Stem JSON_Punct_Hash
#line 3385 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_Hash=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Hash->JSON_Punct_Stem JSON_Punct_Hash");
yylhs.value=sparser->combine_nodes("JSON_Hash",JSON_Punct_Stem,JSON_Punct_Hash);

}
#line 6350 "build/hi_desktop/hi.y.cpp"
    break;

  case 389: // JSON_Hash_Ref: JSON_Hash_Relative JSON_CON
#line 3394 "build/hi_desktop/hi.y"
{
const node_info& JSON_Hash_Relative=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_CON=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Hash_Ref->JSON_Hash_Relative JSON_CON");
yylhs.value=sparser->combine_nodes("JSON_Hash_Ref",JSON_Hash_Relative,JSON_CON);

}
#line 6362 "build/hi_desktop/hi.y.cpp"
    break;

  case 390: // JSON_Hash_Relative: JSON_Hash JSON_Hash_lfea_relative
#line 3403 "build/hi_desktop/hi.y"
{
const node_info& JSON_Hash=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Hash_lfea_relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Hash_Relative->JSON_Hash JSON_Hash_lfea_relative");
yylhs.value=sparser->combine_nodes("JSON_Hash_Relative",JSON_Hash,JSON_Hash_lfea_relative);

}
#line 6374 "build/hi_desktop/hi.y.cpp"
    break;

  case 391: // JSON_Hash_lfea_relative: t_JSON_Punct_Relative
#line 3412 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Hash_lfea_relative",word);

}
#line 6386 "build/hi_desktop/hi.y.cpp"
    break;

  case 392: // JSON_Key: JSON_String JSON_Colon
#line 3421 "build/hi_desktop/hi.y"
{
const node_info& JSON_String=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Colon=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(JSON_Colon,"Punct",std::string("main_verb"));
sparser->add_feature_to_leaf(JSON_Colon,"main_verb",std::string("indicative"),true);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key->JSON_String JSON_Colon");
yylhs.value=sparser->combine_nodes("JSON_Key",JSON_String,JSON_Colon);
}
#line 6399 "build/hi_desktop/hi.y.cpp"
    break;

  case 393: // JSON_Key_Value_Pair: JSON_Key JSON_Hash_Ref
#line 3431 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Hash_Ref=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_Hash_Ref");
yylhs.value=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_Hash_Ref);

}
#line 6411 "build/hi_desktop/hi.y.cpp"
    break;

  case 394: // JSON_Key_Value_Pair: JSON_Key JSON_Value
#line 3439 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Value=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Key_Value_Pair->JSON_Key JSON_Value");
yylhs.value=sparser->combine_nodes("JSON_Key_Value_Pair",JSON_Key,JSON_Value);
const node_info& JSON_Key_Value_Pair=sparser->get_node_info(yylhs.value);
sparser->add_feature_to_leaf(JSON_Key_Value_Pair,"JSON_Colon","Punct",std::string("json_key_value"),false,true);
}
#line 6424 "build/hi_desktop/hi.y.cpp"
    break;

  case 395: // JSON_Open_Array: JSON_Open_Array JSON_Value_List_Element
#line 3449 "build/hi_desktop/hi.y"
{
const node_info& JSON_Open_Array=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Value_List_Element=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_Array->JSON_Open_Array JSON_Value_List_Element");
yylhs.value=sparser->combine_nodes("JSON_Open_Array",JSON_Open_Array,JSON_Value_List_Element);

}
#line 6436 "build/hi_desktop/hi.y.cpp"
    break;

  case 396: // JSON_Open_Array: JSON_OpeningSBracket
#line 3457 "build/hi_desktop/hi.y"
{
const node_info& JSON_OpeningSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_Array->JSON_OpeningSBracket");
yylhs.value=sparser->set_node_info("JSON_Open_Array",JSON_OpeningSBracket);

}
#line 6447 "build/hi_desktop/hi.y.cpp"
    break;

  case 397: // JSON_Open_String: JSON_Quotes HUN_N_Sg
#line 3465 "build/hi_desktop/hi.y"
{
const node_info& JSON_Quotes=sparser->get_node_info(yystack_[1].value);
const node_info& HUN_N_Sg=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(HUN_N_Sg,"Noun",std::string("json_key"));
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_String->JSON_Quotes HUN_N_Sg");
yylhs.value=sparser->combine_nodes("JSON_Open_String",JSON_Quotes,HUN_N_Sg);
}
#line 6459 "build/hi_desktop/hi.y.cpp"
    break;

  case 398: // JSON_Open_String: JSON_Quotes JSON_CON
#line 3473 "build/hi_desktop/hi.y"
{
const node_info& JSON_Quotes=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_CON=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Open_String->JSON_Quotes JSON_CON");
yylhs.value=sparser->combine_nodes("JSON_Open_String",JSON_Quotes,JSON_CON);

}
#line 6471 "build/hi_desktop/hi.y.cpp"
    break;

  case 399: // JSON_OpeningSBracket: JSON_Punct_Stem JSON_Punct_OpeningSBracket
#line 3482 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_OpeningSBracket=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_OpeningSBracket->JSON_Punct_Stem JSON_Punct_OpeningSBracket");
yylhs.value=sparser->combine_nodes("JSON_OpeningSBracket",JSON_Punct_Stem,JSON_Punct_OpeningSBracket);

}
#line 6483 "build/hi_desktop/hi.y.cpp"
    break;

  case 400: // JSON_Punct_ClosingSBracket: t_JSON_Punct_ClosingSBracket
#line 3491 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_ClosingSBracket);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_ClosingSBracket",word);

}
#line 6495 "build/hi_desktop/hi.y.cpp"
    break;

  case 401: // JSON_Punct_Colon: t_JSON_Punct_Colon
#line 3500 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Colon);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Colon",word);

}
#line 6507 "build/hi_desktop/hi.y.cpp"
    break;

  case 402: // JSON_Punct_Comma: t_JSON_Punct_Comma
#line 3509 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Comma);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Comma",word);

}
#line 6519 "build/hi_desktop/hi.y.cpp"
    break;

  case 403: // JSON_Punct_Hash: t_JSON_Punct_Hash
#line 3518 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Hash);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Hash",word);

}
#line 6531 "build/hi_desktop/hi.y.cpp"
    break;

  case 404: // JSON_Punct_OpeningSBracket: t_JSON_Punct_OpeningSBracket
#line 3527 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_OpeningSBracket);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_OpeningSBracket",word);

}
#line 6543 "build/hi_desktop/hi.y.cpp"
    break;

  case 405: // JSON_Punct_Quotes: t_JSON_Punct_Quotes
#line 3536 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Quotes);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Quotes",word);

}
#line 6555 "build/hi_desktop/hi.y.cpp"
    break;

  case 406: // JSON_Punct_Stem: t_JSON_Punct_Stem
#line 3545 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_JSON_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("JSON_Punct_Stem",word);

}
#line 6567 "build/hi_desktop/hi.y.cpp"
    break;

  case 407: // JSON_Quotes: JSON_Punct_Stem JSON_Punct_Quotes
#line 3554 "build/hi_desktop/hi.y"
{
const node_info& JSON_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Punct_Quotes=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Quotes->JSON_Punct_Stem JSON_Punct_Quotes");
yylhs.value=sparser->combine_nodes("JSON_Quotes",JSON_Punct_Stem,JSON_Punct_Quotes);

}
#line 6579 "build/hi_desktop/hi.y.cpp"
    break;

  case 408: // JSON_String: JSON_Open_String JSON_Quotes
#line 3563 "build/hi_desktop/hi.y"
{
const node_info& JSON_Open_String=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Quotes=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_String->JSON_Open_String JSON_Quotes");
yylhs.value=sparser->combine_nodes("JSON_String",JSON_Open_String,JSON_Quotes);

}
#line 6591 "build/hi_desktop/hi.y.cpp"
    break;

  case 409: // JSON_Value: JSON_Array
#line 3572 "build/hi_desktop/hi.y"
{
const node_info& JSON_Array=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value->JSON_Array");
yylhs.value=sparser->set_node_info("JSON_Value",JSON_Array);

}
#line 6602 "build/hi_desktop/hi.y.cpp"
    break;

  case 410: // JSON_Value: JSON_CON
#line 3579 "build/hi_desktop/hi.y"
{
const node_info& JSON_CON=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value->JSON_CON");
yylhs.value=sparser->set_node_info("JSON_Value",JSON_CON);

}
#line 6613 "build/hi_desktop/hi.y.cpp"
    break;

  case 411: // JSON_Value: JSON_String
#line 3586 "build/hi_desktop/hi.y"
{
const node_info& JSON_String=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value->JSON_String");
yylhs.value=sparser->set_node_info("JSON_Value",JSON_String);

}
#line 6624 "build/hi_desktop/hi.y.cpp"
    break;

  case 412: // JSON_Value_List_Element: JSON_Array JSON_Comma
#line 3594 "build/hi_desktop/hi.y"
{
const node_info& JSON_Array=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_Array JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Value_List_Element",JSON_Array,JSON_Comma);

}
#line 6636 "build/hi_desktop/hi.y.cpp"
    break;

  case 413: // JSON_Value_List_Element: JSON_CON JSON_Comma
#line 3602 "build/hi_desktop/hi.y"
{
const node_info& JSON_CON=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_CON JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Value_List_Element",JSON_CON,JSON_Comma);

}
#line 6648 "build/hi_desktop/hi.y.cpp"
    break;

  case 414: // JSON_Value_List_Element: JSON_Hash_Ref JSON_Comma
#line 3610 "build/hi_desktop/hi.y"
{
const node_info& JSON_Hash_Ref=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_Hash_Ref JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Value_List_Element",JSON_Hash_Ref,JSON_Comma);

}
#line 6660 "build/hi_desktop/hi.y.cpp"
    break;

  case 415: // JSON_Value_List_Element: JSON_String JSON_Comma
#line 3618 "build/hi_desktop/hi.y"
{
const node_info& JSON_String=sparser->get_node_info(yystack_[1].value);
const node_info& JSON_Comma=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"JSON_Value_List_Element->JSON_String JSON_Comma");
yylhs.value=sparser->combine_nodes("JSON_Value_List_Element",JSON_String,JSON_Comma);

}
#line 6672 "build/hi_desktop/hi.y.cpp"
    break;

  case 416: // S: ENG_VP
#line 3627 "build/hi_desktop/hi.y"
{
const node_info& ENG_VP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP");
yylhs.value=sparser->set_node_info("S",ENG_VP);

}
#line 6683 "build/hi_desktop/hi.y.cpp"
    break;

  case 417: // S: HUN_VP HUN_Punct
#line 3634 "build/hi_desktop/hi.y"
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
#line 6714 "build/hi_desktop/hi.y.cpp"
    break;

  case 418: // S: JSON_Key_Value_Pair
#line 3661 "build/hi_desktop/hi.y"
{
const node_info& JSON_Key_Value_Pair=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->JSON_Key_Value_Pair");
yylhs.value=sparser->set_node_info("S",JSON_Key_Value_Pair);

}
#line 6725 "build/hi_desktop/hi.y.cpp"
    break;


#line 6729 "build/hi_desktop/hi.y.cpp"

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


  const short parser::yypact_ninf_ = -362;

  const short parser::yytable_ninf_ = -368;

  const short
  parser::yypact_[] =
  {
      89,  -362,  -362,  -362,  -362,  -362,  -362,  -362,    33,   536,
      40,    82,   135,   135,    33,    33,   165,  -362,  -362,  -362,
     136,  1268,   130,   240,   142,   638,  1008,  1187,  1187,   386,
     -33,  -362,     4,   110,   137,  1187,   511,   216,   295,    92,
    -362,    63,   105,    79,    63,   230,  -362,   228,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
     252,  -362,  -362,  -362,   201,   252,   252,   252,   201,   252,
     252,   322,   234,  -362,  1148,  -362,   252,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   248,  -362,   269,   262,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,   245,  -362,  -362,   306,
    -362,   245,  -362,    81,   300,  -362,  -362,    81,  -362,  -362,
    -362,  -362,   373,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,    93,   300,  -362,   300,   113,   300,
     240,  -362,    33,   332,    33,  -362,   317,   338,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,    48,  -362,  -362,   303,  -362,
    -362,  -362,  -362,  -362,  1049,   298,  -362,  -362,  1049,  -362,
     355,  1187,   289,    53,    57,   345,  -362,  -362,   198,   325,
     117,   303,   561,   117,  1090,   319,   340,  1316,  1609,  -362,
    1396,  -362,  1507,  1507,    48,  -362,  -362,  -362,  -362,  1257,
    -362,  1543,  1576,  -362,    20,  -362,  1356,  1434,  -362,   235,
    -362,   298,   327,   327,  -362,    18,  -362,  -362,  -362,   346,
    -362,  -362,  -362,  -362,   247,  -362,  -362,   386,  -362,  -362,
     320,   357,  -362,   714,   357,  -362,   319,   319,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,   333,
    -362,   343,    92,  -362,   195,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,   344,  -362,  -362,  -362,  -362,  -362,  -362,
     252,   252,   252,   252,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,   443,  -362,
    -362,  -362,  -362,   134,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,   310,  -362,  -362,  -362,  -362,  -362,   140,   300,   177,
     317,    33,   719,   438,   300,   300,  -362,  -362,  -362,  -362,
    -362,  -362,    48,    48,  -362,  -362,  -362,   117,  1257,  1187,
     911,  1049,  -362,  -362,  -362,   117,  -362,  -362,  -362,    83,
    1228,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,   361,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   361,   361,   361,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,   329,  -362,  -362,  -362,
    -362,  -362,  1609,  1609,   329,   329,  -362,  -362,  -362,  -362,
     329,  -362,  -362,   329,  -362,   386,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,   779,   823,   298,  -362,
     867,   370,   -33,   -33,   -33,  1146,  -362,  1187,   362,   298,
     298,  -362,  -362,  -362,    63,    63,  -362,    63,    63,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,   134,   134,   310,   310,
    -362,    33,  -362,  -362,  -362,  -362,  -362,   245,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  1469,  1469,   117,  -362,
    1049,  -362,  1049,  -362,    38,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,   967,  -362,  -362,  -362,  -362,   -33,  -362,
    -362,  -362,  -362,  -362,   -33,   -33,   -33,  1187,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   242,  -362,  -362,  -362,  -362,
    -362,  -362,    33,    33,  -362,  -362,  -362,   967,   967,   967,
    -362,  -362,  -362,  -362,  -362,  -362,  -362
  };

  const short
  parser::yydefact_[] =
  {
       0,    38,   135,   117,   322,   364,   274,   406,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   416,   118,   116,
     119,   122,   128,     0,     0,   218,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,   142,   119,    28,    77,
      92,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      69,     2,    33,    52,     0,    60,    62,    53,     0,    70,
      72,     0,     0,    34,     0,    81,    65,   148,   147,    37,
      49,   150,   149,    50,    51,     0,    35,     0,     0,    36,
     143,   115,    10,    16,   108,     6,    69,     4,    11,     0,
       5,     0,     3,     7,     8,    17,   141,     9,    54,    55,
      23,   138,     0,   136,   137,   133,   134,   107,   114,   121,
     123,   139,    96,   140,   103,   125,    97,     0,   106,     0,
       0,   127,     0,     0,     0,   120,     0,     0,   129,   130,
     131,   132,   188,   312,   292,   296,   298,   300,   302,   304,
     306,   308,   310,   294,   295,   217,   374,   371,   293,   297,
     299,   301,   303,   305,   307,   309,   311,   376,   373,   278,
     375,   372,   358,   182,   275,   267,   175,   176,     0,   340,
     169,   170,   172,   173,   177,     0,   156,   181,   180,   155,
     353,     0,     0,     0,     0,     0,   342,   171,   243,   244,
       0,     0,     0,     0,     0,     0,   269,     0,     0,   289,
       0,   242,     0,     0,   270,   343,   344,   247,   248,   249,
     250,     0,     0,   356,     0,   269,     0,     0,   357,     0,
     345,   346,     0,     0,   347,     0,   324,   348,   320,     0,
     323,   321,   331,   417,     0,   349,   208,     0,   193,   350,
       0,   269,   351,     0,     0,   352,     0,     0,   359,   362,
     360,   361,   239,   240,   241,   245,   380,   409,   410,     0,
     393,     0,     0,   396,     0,   411,   394,   408,   405,   407,
     397,   398,   392,     0,     1,   153,   152,   151,    67,    68,
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
       0,   391,   390,   389,     0,     0,   379,     0,     0,   395,
     403,   404,   388,   399,   401,   386,    25,    26,    29,    30,
      47,     0,    44,    48,    39,    40,    57,    41,    42,    43,
      58,    59,    45,    46,   194,   195,   196,   197,     0,   198,
     201,   199,   202,   200,     0,   282,   263,   264,   204,   233,
     234,   235,   236,     0,   226,   237,   238,   219,     0,   229,
     230,   231,   220,   221,     0,     0,     0,     0,   232,   363,
     339,   227,   228,   382,   412,     0,   383,   413,   384,   414,
     385,   415,    31,    32,   174,   185,   159,   205,   206,   207,
     224,   222,   223,   402,   400,   381,   387
  };

  const short
  parser::yypgoto_[] =
  {
    -362,    -4,   364,  -362,  -362,  -362,   138,  -362,   -84,  -362,
    -362,   441,   154,  -362,   359,   -49,   -30,  -362,   -28,   211,
      34,   448,  -362,  -362,  -120,  -362,     3,  -362,  -362,  -362,
      -2,     7,  -362,  -362,  -362,  -362,   380,   381,  -362,   391,
     468,   469,    45,  -362,  -362,   407,  -362,  -362,  -362,  -362,
    -362,    14,   -12,  -362,   353,  -362,   167,  -362,  -362,  -362,
     471,  -362,  -362,  -362,  -362,  -362,   266,   102,  -362,  -362,
     292,   499,    39,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   437,   442,   363,  -362,    -5,
      16,  -362,   -71,  -362,  -161,  -362,  -362,  -362,    -8,  -362,
    -362,  -190,  -362,    86,  -362,  -122,  -362,  -362,  -362,  -362,
      50,  -362,  -362,  -362,  -362,  -362,    -7,  -362,   479,  -362,
    -362,  -362,  -362,  -362,  -362,  -227,  -362,  -362,  -206,  -362,
      65,     6,   481,  -362,  -362,  -362,   483,  -362,   179,    -1,
       2,  -362,   -20,   331,   -25,   -13,     8,  -362,  -362,    13,
    -132,  -362,  -362,   160,   270,  -362,  -362,    46,  -362,  -362,
    -155,  -110,  -362,  -362,  -362,    10,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   490,  -362,  -361,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,    64,  -362,
    -362,  -362,  -362,  -362,   328,   404,  -362,   256,   -22,  -219,
    -362,  -362,   -83,  -362,   257,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,    31,   491,
       5,  -362,  -362,  -362
  };

  const short
  parser::yydefgoto_[] =
  {
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   313,   314,   315,    61,   322,
     472,     8,     9,    10,   470,   328,   329,    11,    12,    13,
     110,   111,   330,   331,    63,    64,    65,    66,    67,    68,
      69,    70,    71,   300,   301,    72,    73,    74,    75,   303,
     122,   123,   320,   125,   126,   127,   128,   129,   130,   112,
     131,   132,   337,   133,    14,    15,   332,   134,   135,    17,
     333,   136,    47,   115,   116,    21,    22,    23,    24,   334,
     335,    79,    80,    83,    84,   294,   295,    76,   175,   369,
     370,   178,   489,   179,   180,   181,   182,   183,   346,   491,
     185,   186,   187,   188,   493,   189,   382,   383,   384,   385,
     503,   351,   352,   353,   230,   426,   504,   248,   190,   191,
     192,   193,   194,   195,   196,   499,   512,   507,   500,   438,
     439,   440,    25,    26,    27,    28,    29,   197,   441,   442,
     199,   358,   200,   201,   348,   203,   445,    31,   205,   206,
     387,   388,   389,   496,   400,   435,   390,   221,   208,   209,
     407,   408,   409,   410,   411,   222,    32,    33,   241,   238,
     243,   430,   431,   432,   244,   252,   253,   447,    34,    35,
      36,    37,   211,   262,   263,   264,   265,   520,   448,   449,
     450,   368,   363,   364,   212,   213,   214,   267,   268,   523,
     456,   282,   524,   269,   270,   271,   452,    39,    40,   272,
      41,   273,   545,   465,   546,   462,   463,   279,   525,    43,
      44,   276,   459,    45
  };

  const short
  parser::yytable_[] =
  {
     202,   219,   224,   229,   231,    60,   218,    62,    30,   124,
     219,   250,   327,   220,   394,   218,   249,   184,   280,   312,
     176,   281,   220,   317,   198,   217,   436,   228,   121,   223,
     140,    42,   285,   204,   217,   210,   138,   227,   536,    20,
     225,   177,   225,   393,   275,     2,   345,   437,   305,   251,
     254,   236,     5,   341,    91,   416,   225,    87,    87,    77,
     137,   290,   290,   290,    38,   296,   297,   416,   285,   374,
     274,   207,    42,   226,   316,   283,   321,   318,   321,    78,
     321,   509,   510,   511,   517,    92,   247,   247,   142,     5,
     418,   421,   424,  -124,   235,     1,   239,    60,    95,   310,
     417,     2,    81,    82,   258,     2,   311,     3,    60,   119,
     418,   421,   260,  -126,   156,   157,   324,   417,   261,   142,
     157,   379,   380,   156,   381,     2,   167,   168,     6,   119,
     170,   171,   168,   173,     4,   167,   171,   326,    92,   170,
     117,   308,    49,   339,   118,   156,   157,   540,     1,   113,
     340,    95,     2,   509,   510,   511,   240,   167,   168,   169,
     114,   170,   171,   137,   344,  -145,   360,   137,    48,    92,
      93,     7,    49,   137,     5,   495,    94,   386,   242,     6,
     354,   394,    95,   347,   396,   174,   266,   355,   393,     2,
     356,   397,   349,   357,   386,   372,   349,     7,   391,   266,
       7,   210,  -146,   395,   386,   216,   371,     6,   371,   473,
     501,   371,   173,   505,   245,   225,   373,   278,   398,   392,
     418,   421,   433,   286,   287,   419,   422,   374,   219,   466,
     284,   502,   225,   443,   506,   350,   526,   207,   528,   530,
     444,   113,   225,    48,    92,   419,   422,    49,    48,   453,
     455,    94,    49,   406,   414,    48,   415,    95,   420,   423,
     225,   302,   285,   305,   305,   305,    16,   406,   415,   419,
     422,   287,   406,   415,    46,   142,   537,   458,   299,   471,
      90,   425,   156,   157,   286,   471,   471,  -354,     6,   427,
     428,   429,    18,   173,   167,   168,   169,   538,   170,   171,
      18,   156,   157,   274,   460,   246,    18,   278,   461,   468,
      92,   501,   505,   167,   168,   169,   344,   170,   171,   375,
      48,    92,     2,   386,    49,   311,   119,   117,    94,   396,
     298,   299,   502,   506,    95,   386,   397,   474,   323,   478,
     325,   174,   486,   490,   475,   484,   479,   336,   395,   488,
     494,   532,   543,   361,   362,   371,   544,   232,   204,   349,
     137,   225,   114,   371,   232,   256,   485,   142,   482,   483,
     476,   232,   527,   225,   529,   531,    48,    92,   401,   402,
      49,   258,   312,   317,   344,   156,   157,   246,   259,   260,
      95,   372,   391,   156,   157,   261,  -341,   167,   168,   169,
     498,   170,   171,    85,    88,   167,   168,   169,   367,   170,
     171,   219,   219,   473,  -355,   219,   443,   443,   378,   534,
     443,   535,   229,   444,   444,   515,   142,   444,   291,   292,
     293,   399,   516,   233,   480,   481,   487,   492,   225,   259,
     233,   257,   521,   522,   514,   434,   518,   233,   451,   508,
     266,   298,   156,   157,   119,   464,   173,   324,   420,   423,
       6,   519,   120,   309,   167,   168,   169,   467,   170,   171,
     477,   319,   141,    60,   533,   310,   306,   307,   219,   354,
      86,   304,    89,   443,   354,   488,   488,   338,   469,   494,
     444,   494,   174,   139,   349,   349,   371,   541,   349,    19,
     349,   288,   371,   342,   542,   215,   289,   137,   137,   539,
     513,   234,   219,   219,   219,   237,   518,   443,   443,   443,
     497,   365,   359,   446,   444,   444,   444,   255,   454,   457,
     232,     0,   277,   256,     0,   412,   412,     0,   412,    48,
       0,     0,   342,    49,     0,     0,     0,   232,     0,   412,
     412,   142,     0,     0,   412,   412,     0,   232,     0,     0,
     232,   232,    50,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,   232,     0,   156,   157,   343,
       0,     0,     0,     0,   256,   256,     0,     0,     0,   167,
     168,   169,     0,   170,   171,     0,     0,     0,   366,     0,
     246,   142,     0,     0,     0,     0,   233,     0,     0,   257,
       0,   413,   413,     0,   413,     0,     0,   174,   343,     0,
       0,     0,     0,   233,     0,   413,   413,   156,   157,     0,
     413,   413,     0,   233,     0,     0,   233,   233,     0,   167,
     168,   169,   344,   170,   171,   375,     0,     0,     0,     0,
       0,   233,     0,     0,     0,     0,     0,   376,   377,   378,
     257,   257,   379,   380,     0,   381,     0,   174,     0,     0,
     342,   342,     0,     0,     0,     0,   232,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,     0,   232,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,     0,     0,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,     0,
     170,   171,    48,    92,     0,   172,    49,     0,     6,   117,
      94,     0,     0,   173,     0,   119,    95,     0,     0,     0,
     412,   412,     0,     0,   174,     0,   343,   343,     0,     0,
       0,     0,   233,   232,   142,     0,     0,     0,     0,     0,
       0,     0,   143,     0,   233,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,     0,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,   170,   171,     0,     5,
       0,     0,     0,     0,     6,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   413,   413,     0,   142,
     174,     0,     0,     0,     0,     0,     0,   143,     0,   233,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,   156,   157,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,   170,   171,   142,     5,     0,     0,     0,  -365,     6,
       0,   143,     0,     0,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   174,     0,     0,     0,   156,
     157,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,   170,   171,   142,     5,     0,
       0,     0,  -366,     6,     0,   143,     0,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   174,
       0,     0,     0,   156,   157,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,   170,
     171,   142,     5,     0,     0,     0,  -367,     6,     0,   143,
       0,     0,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   174,     0,     0,     0,   156,   157,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,     0,   170,   171,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,   173,   142,     0,     0,
       0,     0,     0,     0,     0,   143,     0,   174,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     0,   156,   157,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   142,   170,
     171,     0,     5,     0,     0,     0,   143,     6,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,     0,   174,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   142,
     170,   171,     0,     0,     0,     0,     0,   143,     0,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,   174,   156,   157,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     142,   170,   171,     0,     0,     0,     0,     0,   143,     6,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   174,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,   170,   171,    50,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   173,   142,     0,     0,     0,
       0,     0,     0,     0,   143,     0,   174,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   142,   170,   171,
       0,     5,     0,     0,     0,   143,     0,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,   174,   156,   157,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   142,   170,
     171,    48,    92,    93,     0,    49,     0,     0,   117,    94,
       2,     0,   118,     0,   119,    95,     0,     0,     0,     0,
       0,     0,     0,   174,   156,   157,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   168,   169,   344,
     170,   171,   375,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,   156,   157,     0,     0,     0,     0,   379,
     380,     0,   381,     0,   174,   167,   168,   169,   344,   170,
     171,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376,   377,   378,     0,     0,     0,     0,
       0,     0,     0,   174,   143,   401,   402,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,   156,   157,   403,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,   170,   171,
       0,     0,     0,     0,   143,   401,   402,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   404,
       0,   405,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,   170,   171,
       0,     0,     0,     0,   143,     0,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   404,
       0,   405,   156,   157,   403,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,   170,   171,
       0,     0,   143,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,   404,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     0,     0,   170,   171,     0,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,     0,   404,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   142,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     0,   156,   157,   174,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,   170,
     171,   143,   401,   402,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,     0,   156,
     157,   403,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,   143,   170,   171,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,   156,   157,   403,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,   143,   170,   171,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,   156,   157,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
       0,   170,   171
  };

  const short
  parser::yycheck_[] =
  {
      25,    26,    27,    28,    29,     9,    26,     9,     0,    21,
      35,    36,   132,    26,   204,    35,    36,    25,    43,   103,
      25,    43,    35,   107,    25,    26,   253,    28,    21,    27,
      23,     0,    60,    25,    35,    25,    22,    27,     0,     0,
      27,    25,    29,   204,    39,    12,   178,   253,    76,    36,
      37,    47,    85,   175,    15,   210,    43,    12,    13,    19,
      21,    65,    66,    67,     0,    69,    70,   222,    96,   201,
      39,    25,    41,    27,   104,    44,   125,   107,   127,    39,
     129,   442,   443,   444,   445,     4,    36,    37,    40,    85,
     212,   213,   214,     0,    30,     6,    32,   101,    17,   101,
     210,    12,    20,    21,    86,    12,    25,    18,   112,    16,
     232,   233,    94,     0,    66,    67,   128,   227,   100,    40,
      67,   101,   102,    66,   104,    12,    78,    79,    90,    16,
      82,    83,    79,    95,    45,    78,    83,   130,     4,    82,
      10,    96,     7,   136,    14,    66,    67,   508,     6,    13,
     136,    17,    12,   514,   515,   516,    46,    78,    79,    80,
      24,    82,    83,   124,    81,    25,   191,   128,     3,     4,
       5,   108,     7,   134,    85,    92,    11,   202,    41,    90,
     188,   371,    17,   184,   204,   106,   107,   188,   349,    12,
     191,   204,   184,   191,   219,   200,   188,   108,   203,   107,
     108,   191,    25,   204,   229,    26,   198,    90,   200,   329,
     437,   203,    95,   440,    35,   202,   200,   112,   205,   203,
     342,   343,   247,    22,    23,   212,   213,   359,   253,   313,
       0,   437,   219,   253,   440,   185,   455,   191,   457,   458,
     253,    13,   229,     3,     4,   232,   233,     7,     3,   271,
     272,    11,     7,   207,   208,     3,   210,    17,   212,   213,
     247,    27,   290,   291,   292,   293,     0,   221,   222,   256,
     257,    23,   226,   227,     8,    40,   503,   272,     9,   328,
      14,   231,    66,    67,    22,   334,   335,    89,    90,    42,
      43,    44,     0,    95,    78,    79,    80,   503,    82,    83,
       8,    66,    67,   272,   109,    89,    14,   112,   113,   321,
       4,   538,   539,    78,    79,    80,    81,    82,    83,    84,
       3,     4,    12,   348,     7,    25,    16,    10,    11,   349,
       8,     9,   538,   539,    17,   360,   349,   330,   127,   332,
     129,   106,   350,   351,   330,   350,   332,    15,   349,   350,
     351,   471,   110,    64,    65,   347,   114,    29,   350,   351,
     321,   348,    24,   355,    36,    37,   350,    40,   334,   335,
     331,    43,   455,   360,   457,   458,     3,     4,    49,    50,
       7,    86,   466,   467,    81,    66,    67,    89,    93,    94,
      17,   396,   397,    66,    67,   100,    41,    78,    79,    80,
     425,    82,    83,    12,    13,    78,    79,    80,    63,    82,
      83,   436,   437,   533,    89,   440,   436,   437,    98,   490,
     440,   492,   447,   436,   437,   445,    40,   440,    65,    66,
      67,    91,   445,    29,   332,   333,   350,   351,   425,    93,
      36,    37,   449,   450,   445,    88,   447,    43,   115,   441,
     107,     8,    66,    67,    16,   111,    95,   469,   412,   413,
      90,    99,    21,    99,    78,    79,    80,   313,    82,    83,
     332,   112,    24,   477,   471,   477,    96,    96,   503,   487,
      12,    74,    13,   503,   492,   486,   487,   134,   321,   490,
     503,   492,   106,    22,   486,   487,   488,   517,   490,     0,
     492,    64,   494,   175,   517,    26,    64,   468,   469,   503,
     445,    30,   537,   538,   539,    32,   517,   537,   538,   539,
     360,   193,   191,   253,   537,   538,   539,    37,   272,   272,
     202,    -1,    41,   205,    -1,   207,   208,    -1,   210,     3,
      -1,    -1,   214,     7,    -1,    -1,    -1,   219,    -1,   221,
     222,    40,    -1,    -1,   226,   227,    -1,   229,    -1,    -1,
     232,   233,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   247,    -1,    66,    67,   175,
      -1,    -1,    -1,    -1,   256,   257,    -1,    -1,    -1,    78,
      79,    80,    -1,    82,    83,    -1,    -1,    -1,   194,    -1,
      89,    40,    -1,    -1,    -1,    -1,   202,    -1,    -1,   205,
      -1,   207,   208,    -1,   210,    -1,    -1,   106,   214,    -1,
      -1,    -1,    -1,   219,    -1,   221,   222,    66,    67,    -1,
     226,   227,    -1,   229,    -1,    -1,   232,   233,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
     256,   257,   101,   102,    -1,   104,    -1,   106,    -1,    -1,
     342,   343,    -1,    -1,    -1,    -1,   348,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,   360,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    83,     3,     4,    -1,    87,     7,    -1,    90,    10,
      11,    -1,    -1,    95,    -1,    16,    17,    -1,    -1,    -1,
     412,   413,    -1,    -1,   106,    -1,   342,   343,    -1,    -1,
      -1,    -1,   348,   425,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,   360,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    82,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   412,   413,    -1,    40,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,   425,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    82,    83,    40,    85,    -1,    -1,    -1,    89,    90,
      -1,    48,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   106,    -1,    -1,    -1,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,    40,    85,    -1,
      -1,    -1,    89,    90,    -1,    48,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   106,
      -1,    -1,    -1,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    82,
      83,    40,    85,    -1,    -1,    -1,    89,    90,    -1,    48,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   106,    -1,    -1,    -1,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    95,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,   106,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    40,    82,
      83,    -1,    85,    -1,    -1,    -1,    48,    90,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,   106,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    40,
      82,    83,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,   106,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      40,    82,    83,    -1,    -1,    -1,    -1,    -1,    48,    90,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,   106,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    82,    83,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    95,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,   106,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    40,    82,    83,
      -1,    85,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,   106,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    40,    82,
      83,     3,     4,     5,    -1,     7,    -1,    -1,    10,    11,
      12,    -1,    14,    -1,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    66,    67,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,   101,
     102,    -1,   104,    -1,   106,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,   103,
      -1,   105,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,   103,
      -1,   105,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    82,    83,
      -1,    -1,    48,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,   103,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    82,    83,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,   103,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,   106,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    82,
      83,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    48,    82,    83,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    48,    82,    83,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    82,    83
  };

  const short
  parser::yystos_[] =
  {
       0,     6,    12,    18,    45,    85,    90,   108,   137,   138,
     139,   143,   144,   145,   180,   181,   182,   185,   186,   187,
     188,   191,   192,   193,   194,   248,   249,   250,   251,   252,
     262,   263,   282,   283,   294,   295,   296,   297,   304,   323,
     324,   326,   334,   335,   336,   339,   182,   188,     3,     7,
      26,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     117,   134,   146,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   161,   162,   163,   164,   203,    19,    39,   197,
     198,    20,    21,   199,   200,   155,   156,   158,   155,   157,
     182,   188,     4,     5,    11,    17,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     146,   147,   175,    13,    24,   189,   190,    10,    14,    16,
     127,   147,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   176,   177,   179,   183,   184,   187,   188,   167,   176,
     147,   137,    40,    48,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    66,    67,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      82,    83,    87,    95,   106,   204,   205,   206,   207,   209,
     210,   211,   212,   213,   214,   216,   217,   218,   219,   221,
     234,   235,   236,   237,   238,   239,   240,   253,   255,   256,
     258,   259,   260,   261,   262,   264,   265,   273,   274,   275,
     281,   298,   310,   311,   312,   234,   254,   255,   258,   260,
     261,   273,   281,   256,   260,   265,   273,   281,   255,   260,
     230,   260,   310,   311,   248,   304,    47,   252,   285,   304,
      46,   284,    41,   286,   290,   254,    89,   226,   233,   258,
     260,   265,   291,   292,   265,   291,   310,   311,    86,    93,
      94,   100,   299,   300,   301,   302,   107,   313,   314,   319,
     320,   321,   325,   327,   334,   336,   337,   335,   112,   333,
     260,   314,   317,   334,     0,   134,    22,    23,   201,   202,
     117,   203,   203,   203,   201,   202,   117,   117,     8,     9,
     159,   160,    27,   165,   161,   134,   152,   153,   158,   118,
     146,    25,   124,   131,   132,   133,   132,   124,   132,   130,
     168,   131,   135,   135,   168,   135,   147,   140,   141,   142,
     148,   149,   182,   186,   195,   196,    15,   178,   170,   147,
     167,   221,   310,   311,    81,   266,   214,   255,   260,   262,
     226,   227,   228,   229,   214,   255,   255,   256,   257,   259,
     260,    64,    65,   308,   309,   310,   311,    63,   307,   205,
     206,   262,   205,   206,   266,    84,    96,    97,    98,   101,
     102,   104,   222,   223,   224,   225,   260,   266,   267,   268,
     272,   205,   206,   210,   217,   255,   258,   261,   265,    91,
     270,    49,    50,    68,   103,   105,   273,   276,   277,   278,
     279,   280,   310,   311,   273,   273,   276,   277,   221,   265,
     273,   221,   265,   273,   221,   226,   231,    42,    43,    44,
     287,   288,   289,   260,    88,   271,   241,   244,   245,   246,
     247,   254,   255,   258,   261,   262,   270,   293,   304,   305,
     306,   115,   322,   314,   313,   314,   316,   320,   336,   338,
     109,   113,   331,   332,   111,   329,   124,   128,   168,   172,
     140,   131,   136,   140,   147,   167,   188,   122,   147,   167,
     183,   183,   136,   136,   205,   206,   214,   219,   255,   208,
     214,   215,   219,   220,   255,    92,   269,   269,   260,   241,
     244,   241,   244,   226,   232,   241,   244,   243,   262,   293,
     293,   293,   242,   246,   255,   258,   261,   293,   255,    99,
     303,   232,   232,   315,   318,   334,   315,   318,   315,   318,
     315,   318,   140,   142,   208,   208,     0,   241,   244,   247,
     293,   258,   261,   110,   114,   328,   330
  };

  const short
  parser::yyr1_[] =
  {
       0,   116,   117,   118,   119,   120,   121,   122,   122,   122,
     123,   124,   124,   125,   125,   125,   126,   127,   128,   128,
     129,   129,   130,   130,   131,   132,   132,   133,   134,   135,
     135,   136,   136,   137,   137,   137,   137,   138,   139,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   143,
     144,   145,   146,   146,   147,   147,   147,   148,   148,   149,
     150,   150,   150,   150,   150,   150,   151,   152,   153,   154,
     154,   154,   154,   154,   155,   156,   157,   158,   159,   160,
     161,   161,   162,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   164,   165,   166,   167,   168,   168,   169,   169,
     169,   170,   170,   171,   172,   172,   173,   174,   175,   176,
     176,   176,   177,   178,   179,   180,   180,   181,   182,   182,
     183,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   186,   187,   188,   189,   190,   191,   192,
     192,   193,   194,   194,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   203,   204,   205,   206,   207,   208,
     209,   209,   209,   210,   210,   210,   211,   211,   211,   212,
     213,   213,   214,   214,   215,   216,   216,   216,   216,   216,
     216,   217,   218,   219,   219,   220,   221,   221,   221,   222,
     223,   224,   225,   226,   227,   227,   227,   227,   228,   228,
     228,   229,   229,   230,   231,   232,   232,   232,   233,   234,
     234,   234,   235,   235,   236,   237,   238,   239,   240,   241,
     241,   241,   242,   242,   243,   244,   245,   245,   245,   246,
     246,   246,   246,   247,   247,   247,   247,   247,   247,   248,
     248,   248,   249,   250,   251,   252,   253,   254,   254,   254,
     254,   255,   255,   255,   255,   255,   255,   256,   256,   256,
     256,   256,   256,   257,   257,   258,   259,   260,   260,   260,
     260,   261,   261,   262,   263,   264,   265,   265,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   273,   273,   273,
     273,   273,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   275,   276,   277,   278,   279,   280,   281,   281,
     282,   282,   283,   284,   285,   286,   286,   286,   287,   288,
     289,   290,   291,   291,   291,   291,   291,   292,   292,   293,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   295,   296,   296,   297,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   305,   306,   307,   308,
     309,   310,   310,   310,   311,   311,   311,   312,   312,   313,
     314,   315,   316,   316,   316,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   324,   325,   325,   326,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     337,   337,   338,   338,   338,   338,   339,   339,   339
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
       2,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     2,     2,     2,     2,     1,     2,     1
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
  "t_JSON_Punct_Stem", "t_JSON_Punct_Hash", "t_JSON_Punct_Comma",
  "t_JSON_Punct_Colon", "t_JSON_Punct_Quotes",
  "t_JSON_Punct_OpeningSBracket", "t_JSON_Punct_ClosingSBracket",
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
  "JSON_CON", "JSON_ClosingSBracket", "JSON_Closing_Value_Element",
  "JSON_Colon", "JSON_Comma", "JSON_Hash", "JSON_Hash_Ref",
  "JSON_Hash_Relative", "JSON_Hash_lfea_relative", "JSON_Key",
  "JSON_Key_Value_Pair", "JSON_Open_Array", "JSON_Open_String",
  "JSON_OpeningSBracket", "JSON_Punct_ClosingSBracket", "JSON_Punct_Colon",
  "JSON_Punct_Comma", "JSON_Punct_Hash", "JSON_Punct_OpeningSBracket",
  "JSON_Punct_Quotes", "JSON_Punct_Stem", "JSON_Quotes", "JSON_String",
  "JSON_Value", "JSON_Value_List_Element", "S", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   160,   160,   168,   176,   184,   192,   201,   208,   215,
     223,   232,   239,   248,   256,   264,   273,   282,   290,   298,
     307,   315,   324,   332,   340,   348,   356,   365,   374,   383,
     391,   400,   408,   417,   425,   433,   441,   450,   459,   468,
     476,   484,   492,   501,   511,   519,   527,   536,   544,   553,
     562,   571,   580,   587,   595,   602,   609,   618,   626,   635,
     644,   651,   659,   666,   674,   681,   689,   698,   707,   716,
     723,   730,   738,   745,   754,   763,   772,   781,   790,   799,
     808,   816,   824,   833,   841,   849,   857,   865,   873,   881,
     889,   897,   906,   915,   924,   933,   942,   949,   957,   965,
     973,   982,   989,   997,  1005,  1013,  1022,  1030,  1039,  1048,
    1056,  1064,  1073,  1082,  1091,  1100,  1108,  1116,  1125,  1132,
    1140,  1148,  1157,  1164,  1172,  1180,  1188,  1196,  1204,  1211,
    1219,  1227,  1235,  1244,  1253,  1262,  1271,  1280,  1289,  1298,
    1306,  1315,  1324,  1332,  1340,  1348,  1356,  1364,  1373,  1382,
    1391,  1400,  1409,  1418,  1426,  1435,  1443,  1451,  1460,  1469,
    1476,  1484,  1492,  1501,  1509,  1517,  1526,  1534,  1542,  1551,
    1559,  1566,  1574,  1581,  1589,  1598,  1605,  1612,  1619,  1627,
    1635,  1643,  1651,  1660,  1668,  1677,  1686,  1694,  1702,  1711,
    1720,  1729,  1738,  1747,  1755,  1763,  1771,  1779,  1788,  1796,
    1804,  1813,  1821,  1830,  1839,  1848,  1856,  1864,  1873,  1882,
    1890,  1898,  1907,  1915,  1924,  1933,  1942,  1951,  1960,  1967,
    1975,  1983,  1992,  2000,  2009,  2018,  2026,  2034,  2042,  2051,
    2059,  2067,  2075,  2084,  2092,  2100,  2108,  2116,  2124,  2133,
    2141,  2149,  2158,  2167,  2176,  2185,  2194,  2203,  2210,  2217,
    2224,  2232,  2240,  2248,  2256,  2264,  2272,  2281,  2289,  2297,
    2305,  2313,  2321,  2330,  2338,  2347,  2356,  2365,  2372,  2380,
    2387,  2395,  2403,  2412,  2420,  2429,  2438,  2446,  2454,  2463,
    2472,  2481,  2490,  2499,  2508,  2517,  2526,  2534,  2542,  2550,
    2557,  2565,  2574,  2582,  2590,  2598,  2606,  2614,  2622,  2630,
    2638,  2646,  2654,  2662,  2670,  2678,  2686,  2694,  2702,  2710,
    2718,  2726,  2735,  2744,  2753,  2762,  2771,  2780,  2789,  2797,
    2806,  2814,  2823,  2832,  2841,  2850,  2858,  2866,  2875,  2884,
    2893,  2902,  2911,  2919,  2927,  2935,  2943,  2952,  2960,  2969,
    2978,  2986,  2994,  3002,  3010,  3018,  3026,  3034,  3042,  3050,
    3058,  3066,  3074,  3083,  3092,  3100,  3109,  3117,  3126,  3135,
    3144,  3153,  3162,  3171,  3180,  3189,  3196,  3204,  3212,  3221,
    3230,  3239,  3247,  3255,  3264,  3272,  3280,  3289,  3297,  3306,
    3315,  3324,  3333,  3341,  3349,  3357,  3366,  3375,  3384,  3393,
    3402,  3411,  3420,  3430,  3438,  3448,  3456,  3464,  3472,  3481,
    3490,  3499,  3508,  3517,  3526,  3535,  3544,  3553,  3562,  3571,
    3578,  3585,  3593,  3601,  3609,  3617,  3626,  3633,  3660
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
     115
    };
    // Last valid token kind.
    const int code_max = 370;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 7999 "build/hi_desktop/hi.y.cpp"

#line 3667 "build/hi_desktop/hi.y"

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
