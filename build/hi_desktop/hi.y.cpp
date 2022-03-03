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
#line 170 "build/hi_desktop/hi.y.cpp"




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
    t_ENG_Punct_Stem = 260,        // t_ENG_Punct_Stem
    t_ENG_Punct_FullStop = 261,    // t_ENG_Punct_FullStop
    t_ENG_Punct_QuestionMark = 262, // t_ENG_Punct_QuestionMark
    t_ENG_Punct_ExclamationMark = 263, // t_ENG_Punct_ExclamationMark
    t_ENG_ADV_Stem = 264,          // t_ENG_ADV_Stem
    t_ENG_DET_Stem = 265,          // t_ENG_DET_Stem
    t_ENG_N_Stem = 266,            // t_ENG_N_Stem
    t_ENG_N_Pl = 267,              // t_ENG_N_Pl
    t_ENG_N_Sg = 268,              // t_ENG_N_Sg
    t_ENG_PREP_Stem = 269,         // t_ENG_PREP_Stem
    t_ENG_QPRO_Stem = 270,         // t_ENG_QPRO_Stem
    t_ENG_V_Stem = 271,            // t_ENG_V_Stem
    t_ENG_V_Aux = 272,             // t_ENG_V_Aux
    t_ENG_RPRO_Stem = 273,         // t_ENG_RPRO_Stem
    t_ENG_RPRO_Relative = 274,     // t_ENG_RPRO_Relative
    t_ENG_VNEG_Stem = 275,         // t_ENG_VNEG_Stem
    t_ENG_ANEG_Stem = 276,         // t_ENG_ANEG_Stem
    t_ENG_PAR_Stem = 277,          // t_ENG_PAR_Stem
    t_ENG_DET_Indef = 278,         // t_ENG_DET_Indef
    t_ENG_DET_fwVowel = 279,       // t_ENG_DET_fwVowel
    t_ENG_DET_fwConsonant = 280,   // t_ENG_DET_fwConsonant
    t_ENG_N_swVowel = 281,         // t_ENG_N_swVowel
    t_ENG_N_swConsonant = 282,     // t_ENG_N_swConsonant
    t_ENG_V_Gerund = 283,          // t_ENG_V_Gerund
    t_ENG_CONJ_Stem = 284          // t_ENG_CONJ_Stem
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
        YYNTOKENS = 30, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_t_ENG_CON_Stem = 3,                    // t_ENG_CON_Stem
        S_t_ENG_A_Stem = 4,                      // t_ENG_A_Stem
        S_t_ENG_Punct_Stem = 5,                  // t_ENG_Punct_Stem
        S_t_ENG_Punct_FullStop = 6,              // t_ENG_Punct_FullStop
        S_t_ENG_Punct_QuestionMark = 7,          // t_ENG_Punct_QuestionMark
        S_t_ENG_Punct_ExclamationMark = 8,       // t_ENG_Punct_ExclamationMark
        S_t_ENG_ADV_Stem = 9,                    // t_ENG_ADV_Stem
        S_t_ENG_DET_Stem = 10,                   // t_ENG_DET_Stem
        S_t_ENG_N_Stem = 11,                     // t_ENG_N_Stem
        S_t_ENG_N_Pl = 12,                       // t_ENG_N_Pl
        S_t_ENG_N_Sg = 13,                       // t_ENG_N_Sg
        S_t_ENG_PREP_Stem = 14,                  // t_ENG_PREP_Stem
        S_t_ENG_QPRO_Stem = 15,                  // t_ENG_QPRO_Stem
        S_t_ENG_V_Stem = 16,                     // t_ENG_V_Stem
        S_t_ENG_V_Aux = 17,                      // t_ENG_V_Aux
        S_t_ENG_RPRO_Stem = 18,                  // t_ENG_RPRO_Stem
        S_t_ENG_RPRO_Relative = 19,              // t_ENG_RPRO_Relative
        S_t_ENG_VNEG_Stem = 20,                  // t_ENG_VNEG_Stem
        S_t_ENG_ANEG_Stem = 21,                  // t_ENG_ANEG_Stem
        S_t_ENG_PAR_Stem = 22,                   // t_ENG_PAR_Stem
        S_t_ENG_DET_Indef = 23,                  // t_ENG_DET_Indef
        S_t_ENG_DET_fwVowel = 24,                // t_ENG_DET_fwVowel
        S_t_ENG_DET_fwConsonant = 25,            // t_ENG_DET_fwConsonant
        S_t_ENG_N_swVowel = 26,                  // t_ENG_N_swVowel
        S_t_ENG_N_swConsonant = 27,              // t_ENG_N_swConsonant
        S_t_ENG_V_Gerund = 28,                   // t_ENG_V_Gerund
        S_t_ENG_CONJ_Stem = 29,                  // t_ENG_CONJ_Stem
        S_YYACCEPT = 30,                         // $accept
        S_ENG_1Con = 31,                         // ENG_1Con
        S_ENG_A = 32,                            // ENG_A
        S_ENG_A0NEG = 33,                        // ENG_A0NEG
        S_ENG_ANEG = 34,                         // ENG_ANEG
        S_ENG_ANEG_Stem = 35,                    // ENG_ANEG_Stem
        S_ENG_AP = 36,                           // ENG_AP
        S_ENG_A_Stem = 37,                       // ENG_A_Stem
        S_ENG_Abar1 = 38,                        // ENG_Abar1
        S_ENG_Abar2 = 39,                        // ENG_Abar2
        S_ENG_Adv = 40,                          // ENG_Adv
        S_ENG_AdvP = 41,                         // ENG_AdvP
        S_ENG_Ahead = 42,                        // ENG_Ahead
        S_ENG_Alist = 43,                        // ENG_Alist
        S_ENG_CAP = 44,                          // ENG_CAP
        S_ENG_CNP = 45,                          // ENG_CNP
        S_ENG_CONJ = 46,                         // ENG_CONJ
        S_ENG_CONJA = 47,                        // ENG_CONJA
        S_ENG_CONJ_Stem = 48,                    // ENG_CONJ_Stem
        S_ENG_Con = 49,                          // ENG_Con
        S_ENG_DP = 50,                           // ENG_DP
        S_ENG_Det_stem = 51,                     // ENG_Det_stem
        S_ENG_IVP = 52,                          // ENG_IVP
        S_ENG_Indef_Det = 53,                    // ENG_Indef_Det
        S_ENG_Indef_Det_a = 54,                  // ENG_Indef_Det_a
        S_ENG_Indef_Det_an = 55,                 // ENG_Indef_Det_an
        S_ENG_N = 56,                            // ENG_N
        S_ENG_NP = 57,                           // ENG_NP
        S_ENG_NV = 58,                           // ENG_NV
        S_ENG_N_Pl = 59,                         // ENG_N_Pl
        S_ENG_N_Pl_0Con = 60,                    // ENG_N_Pl_0Con
        S_ENG_N_Pl_0Con_swC = 61,                // ENG_N_Pl_0Con_swC
        S_ENG_N_Pl_0Con_swV = 62,                // ENG_N_Pl_0Con_swV
        S_ENG_N_Sg = 63,                         // ENG_N_Sg
        S_ENG_N_Sg_0Con = 64,                    // ENG_N_Sg_0Con
        S_ENG_N_Sg_0Con_swC = 65,                // ENG_N_Sg_0Con_swC
        S_ENG_N_Sg_0Con_swV = 66,                // ENG_N_Sg_0Con_swV
        S_ENG_N_Stem = 67,                       // ENG_N_Stem
        S_ENG_N_lfea_Pl = 68,                    // ENG_N_lfea_Pl
        S_ENG_N_lfea_Sg = 69,                    // ENG_N_lfea_Sg
        S_ENG_PP = 70,                           // ENG_PP
        S_ENG_Prep = 71,                         // ENG_Prep
        S_ENG_Punct = 72,                        // ENG_Punct
        S_ENG_Punct_FullStop = 73,               // ENG_Punct_FullStop
        S_ENG_Punct_Stem = 74,                   // ENG_Punct_Stem
        S_ENG_QPro = 75,                         // ENG_QPro
        S_ENG_RC = 76,                           // ENG_RC
        S_ENG_RPro = 77,                         // ENG_RPro
        S_ENG_RPro_lfea_relative = 78,           // ENG_RPro_lfea_relative
        S_ENG_RPro_stem = 79,                    // ENG_RPro_stem
        S_ENG_TP = 80,                           // ENG_TP
        S_ENG_Tense_particle = 81,               // ENG_Tense_particle
        S_ENG_V = 82,                            // ENG_V
        S_ENG_VNEG = 83,                         // ENG_VNEG
        S_ENG_VNEG_Stem = 84,                    // ENG_VNEG_Stem
        S_ENG_VP = 85,                           // ENG_VP
        S_ENG_VP_Int = 86,                       // ENG_VP_Int
        S_ENG_V_Stem = 87,                       // ENG_V_Stem
        S_ENG_V_ger = 88,                        // ENG_V_ger
        S_ENG_V_lfea_aux = 89,                   // ENG_V_lfea_aux
        S_ENG_V_lfea_ger = 90,                   // ENG_V_lfea_ger
        S_ENG_Vbar1 = 91,                        // ENG_Vbar1
        S_ENG_Vbar1_Ind = 92,                    // ENG_Vbar1_Ind
        S_ENG_Vbar2 = 93,                        // ENG_Vbar2
        S_ENG_Vbar3 = 94,                        // ENG_Vbar3
        S_ENG_Vbar4 = 95,                        // ENG_Vbar4
        S_ENG_lfea_IndefDet = 96,                // ENG_lfea_IndefDet
        S_ENG_lfea_fwConsonant = 97,             // ENG_lfea_fwConsonant
        S_ENG_lfea_fwVowel = 98,                 // ENG_lfea_fwVowel
        S_ENG_lfea_swConsonant = 99,             // ENG_lfea_swConsonant
        S_ENG_lfea_swVowel = 100,                // ENG_lfea_swVowel
        S_ENG_nCon = 101,                        // ENG_nCon
        S_S = 102                                // S
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
    typedef unsigned char state_type;

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

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

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
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

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
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

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
      yylast_ = 135,     ///< Last index in yytable_.
      yynnts_ = 73,  ///< Number of nonterminal symbols.
      yyfinal_ = 106 ///< Termination state number.
    };



  };


} // yy
#line 865 "build/hi_desktop/hi.y.cpp"






// Unqualified %code blocks.
#line 1 "build/hi_desktop/hi.y"

#include "tokensymbols.h"
#line 4 "build/hi_desktop/hi.y"

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


#line 906 "build/hi_desktop/hi.y.cpp"


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
#line 979 "build/hi_desktop/hi.y.cpp"

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
#line 68 "build/hi_desktop/hi.y"
{
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_1Con->ENG_Con");
yylhs.value=sparser->set_node_info("ENG_1Con",ENG_Con);

}
#line 1434 "build/hi_desktop/hi.y.cpp"
    break;

  case 3: // ENG_A: ENG_A_Stem
#line 76 "build/hi_desktop/hi.y"
{
const node_info& ENG_A_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A->ENG_A_Stem");
yylhs.value=sparser->set_node_info("ENG_A",ENG_A_Stem);

}
#line 1445 "build/hi_desktop/hi.y.cpp"
    break;

  case 4: // ENG_A0NEG: ENG_A
#line 84 "build/hi_desktop/hi.y"
{
const node_info& ENG_A=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_A0NEG->ENG_A");
yylhs.value=sparser->set_node_info("ENG_A0NEG",ENG_A);

}
#line 1456 "build/hi_desktop/hi.y.cpp"
    break;

  case 5: // ENG_ANEG: ENG_ANEG_Stem
#line 92 "build/hi_desktop/hi.y"
{
const node_info& ENG_ANEG_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_ANEG->ENG_ANEG_Stem");
yylhs.value=sparser->set_node_info("ENG_ANEG",ENG_ANEG_Stem);

}
#line 1467 "build/hi_desktop/hi.y.cpp"
    break;

  case 6: // ENG_ANEG_Stem: t_ENG_ANEG_Stem
#line 100 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ANEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_ANEG_Stem",word);

}
#line 1479 "build/hi_desktop/hi.y.cpp"
    break;

  case 7: // ENG_AP: ENG_Abar1
#line 109 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar1");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Abar1);

}
#line 1490 "build/hi_desktop/hi.y.cpp"
    break;

  case 8: // ENG_AP: ENG_Abar2
#line 116 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Abar2");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Abar2);

}
#line 1501 "build/hi_desktop/hi.y.cpp"
    break;

  case 9: // ENG_AP: ENG_Alist
#line 123 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AP->ENG_Alist");
yylhs.value=sparser->set_node_info("ENG_AP",ENG_Alist);

}
#line 1512 "build/hi_desktop/hi.y.cpp"
    break;

  case 10: // ENG_A_Stem: t_ENG_A_Stem
#line 131 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_A_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_A_Stem",word);

}
#line 1524 "build/hi_desktop/hi.y.cpp"
    break;

  case 11: // ENG_Abar1: ENG_A0NEG
#line 140 "build/hi_desktop/hi.y"
{
const node_info& ENG_A0NEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_A0NEG");
yylhs.value=sparser->set_node_info("ENG_Abar1",ENG_A0NEG);

}
#line 1535 "build/hi_desktop/hi.y.cpp"
    break;

  case 12: // ENG_Abar1: ENG_ANEG ENG_A
#line 147 "build/hi_desktop/hi.y"
{
const node_info& ENG_ANEG=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_A=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar1->ENG_ANEG ENG_A");
yylhs.value=sparser->combine_nodes("ENG_Abar1",ENG_ANEG,ENG_A);

}
#line 1547 "build/hi_desktop/hi.y.cpp"
    break;

  case 13: // ENG_Abar2: ENG_Abar2 ENG_CONJA
#line 156 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Abar2 ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Abar2,ENG_CONJA);

}
#line 1559 "build/hi_desktop/hi.y.cpp"
    break;

  case 14: // ENG_Abar2: ENG_Ahead ENG_CONJA
#line 164 "build/hi_desktop/hi.y"
{
const node_info& ENG_Ahead=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Ahead ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Ahead,ENG_CONJA);

}
#line 1571 "build/hi_desktop/hi.y.cpp"
    break;

  case 15: // ENG_Abar2: ENG_Alist ENG_CONJA
#line 172 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CONJA=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Abar2->ENG_Alist ENG_CONJA");
yylhs.value=sparser->combine_nodes("ENG_Abar2",ENG_Alist,ENG_CONJA);

}
#line 1583 "build/hi_desktop/hi.y.cpp"
    break;

  case 16: // ENG_Adv: t_ENG_ADV_Stem
#line 181 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_ADV_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Adv",word);

}
#line 1595 "build/hi_desktop/hi.y.cpp"
    break;

  case 17: // ENG_AdvP: ENG_Adv
#line 190 "build/hi_desktop/hi.y"
{
const node_info& ENG_Adv=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_AdvP->ENG_Adv");
yylhs.value=sparser->set_node_info("ENG_AdvP",ENG_Adv);

}
#line 1606 "build/hi_desktop/hi.y.cpp"
    break;

  case 18: // ENG_Ahead: ENG_Abar1
#line 198 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Ahead->ENG_Abar1");
yylhs.value=sparser->set_node_info("ENG_Ahead",ENG_Abar1);

}
#line 1617 "build/hi_desktop/hi.y.cpp"
    break;

  case 19: // ENG_Alist: ENG_Abar1 ENG_Abar1
#line 206 "build/hi_desktop/hi.y"
{
const node_info& ENG_Abar11=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar12=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Abar1 ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_Alist",ENG_Abar11,ENG_Abar12);

}
#line 1629 "build/hi_desktop/hi.y.cpp"
    break;

  case 20: // ENG_Alist: ENG_Alist ENG_Abar1
#line 214 "build/hi_desktop/hi.y"
{
const node_info& ENG_Alist=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Alist->ENG_Alist ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_Alist",ENG_Alist,ENG_Abar1);

}
#line 1641 "build/hi_desktop/hi.y.cpp"
    break;

  case 21: // ENG_CAP: ENG_1Con ENG_N_Pl_0Con_swC
#line 223 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swC");
yylhs.value=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swC);

}
#line 1653 "build/hi_desktop/hi.y.cpp"
    break;

  case 22: // ENG_CAP: ENG_1Con ENG_N_Pl_0Con_swV
#line 231 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CAP->ENG_1Con ENG_N_Pl_0Con_swV");
yylhs.value=sparser->combine_nodes("ENG_CAP",ENG_1Con,ENG_N_Pl_0Con_swV);

}
#line 1665 "build/hi_desktop/hi.y.cpp"
    break;

  case 23: // ENG_CNP: ENG_AP ENG_N
#line 240 "build/hi_desktop/hi.y"
{
const node_info& ENG_AP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_AP ENG_N");
yylhs.value=sparser->combine_nodes("ENG_CNP",ENG_AP,ENG_N);

}
#line 1677 "build/hi_desktop/hi.y.cpp"
    break;

  case 24: // ENG_CNP: ENG_N
#line 248 "build/hi_desktop/hi.y"
{
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CNP->ENG_N");
yylhs.value=sparser->set_node_info("ENG_CNP",ENG_N);

}
#line 1688 "build/hi_desktop/hi.y.cpp"
    break;

  case 25: // ENG_CONJ: ENG_CONJ_Stem
#line 256 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJ->ENG_CONJ_Stem");
yylhs.value=sparser->set_node_info("ENG_CONJ",ENG_CONJ_Stem);

}
#line 1699 "build/hi_desktop/hi.y.cpp"
    break;

  case 26: // ENG_CONJA: ENG_CONJ ENG_Abar1
#line 264 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Abar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Abar1");
yylhs.value=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Abar1);

}
#line 1711 "build/hi_desktop/hi.y.cpp"
    break;

  case 27: // ENG_CONJA: ENG_CONJ ENG_Alist
#line 272 "build/hi_desktop/hi.y"
{
const node_info& ENG_CONJ=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Alist=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CONJA->ENG_CONJ ENG_Alist");
yylhs.value=sparser->combine_nodes("ENG_CONJA",ENG_CONJ,ENG_Alist);

}
#line 1723 "build/hi_desktop/hi.y.cpp"
    break;

  case 28: // ENG_CONJ_Stem: t_ENG_CONJ_Stem
#line 281 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CONJ_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_CONJ_Stem",word);

}
#line 1735 "build/hi_desktop/hi.y.cpp"
    break;

  case 29: // ENG_Con: t_ENG_CON_Stem
#line 290 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Con",word);

}
#line 1747 "build/hi_desktop/hi.y.cpp"
    break;

  case 30: // ENG_DP: ENG_Indef_Det_a ENG_N_Sg_0Con_swC
#line 299 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det_a=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_a ENG_N_Sg_0Con_swC");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_a,ENG_N_Sg_0Con_swC);

}
#line 1759 "build/hi_desktop/hi.y.cpp"
    break;

  case 31: // ENG_DP: ENG_Indef_Det_an ENG_N_Sg_0Con_swV
#line 307 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det_an=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_Indef_Det_an ENG_N_Sg_0Con_swV");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_Indef_Det_an,ENG_N_Sg_0Con_swV);

}
#line 1771 "build/hi_desktop/hi.y.cpp"
    break;

  case 32: // ENG_Det_stem: t_ENG_DET_Stem
#line 316 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Det_stem",word);

}
#line 1783 "build/hi_desktop/hi.y.cpp"
    break;

  case 33: // ENG_IVP: ENG_NV ENG_PP
#line 325 "build/hi_desktop/hi.y"
{
const node_info& ENG_NV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_NV,"V","RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_NV ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_NV,ENG_PP);
}
#line 1795 "build/hi_desktop/hi.y.cpp"
    break;

  case 34: // ENG_IVP: ENG_V ENG_AP
#line 333 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_AP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_AP);
}
#line 1807 "build/hi_desktop/hi.y.cpp"
    break;

  case 35: // ENG_IVP: ENG_V ENG_PP
#line 341 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"RCV");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_IVP->ENG_V ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_IVP",ENG_V,ENG_PP);
}
#line 1819 "build/hi_desktop/hi.y.cpp"
    break;

  case 36: // ENG_Indef_Det: ENG_Det_stem ENG_lfea_IndefDet
#line 350 "build/hi_desktop/hi.y"
{
const node_info& ENG_Det_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_IndefDet=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det->ENG_Det_stem ENG_lfea_IndefDet");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det",ENG_Det_stem,ENG_lfea_IndefDet);

}
#line 1831 "build/hi_desktop/hi.y.cpp"
    break;

  case 37: // ENG_Indef_Det_a: ENG_Indef_Det ENG_lfea_fwConsonant
#line 359 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_fwConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_a->ENG_Indef_Det ENG_lfea_fwConsonant");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det_a",ENG_Indef_Det,ENG_lfea_fwConsonant);

}
#line 1843 "build/hi_desktop/hi.y.cpp"
    break;

  case 38: // ENG_Indef_Det_an: ENG_Indef_Det ENG_lfea_fwVowel
#line 368 "build/hi_desktop/hi.y"
{
const node_info& ENG_Indef_Det=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_fwVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Indef_Det_an->ENG_Indef_Det ENG_lfea_fwVowel");
yylhs.value=sparser->combine_nodes("ENG_Indef_Det_an",ENG_Indef_Det,ENG_lfea_fwVowel);

}
#line 1855 "build/hi_desktop/hi.y.cpp"
    break;

  case 39: // ENG_N: ENG_N_Pl
#line 377 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Pl");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Pl);

}
#line 1866 "build/hi_desktop/hi.y.cpp"
    break;

  case 40: // ENG_N: ENG_N_Sg
#line 384 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Sg");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Sg);

}
#line 1877 "build/hi_desktop/hi.y.cpp"
    break;

  case 41: // ENG_NP: ENG_CAP
#line 392 "build/hi_desktop/hi.y"
{
const node_info& ENG_CAP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CAP");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_CAP);

}
#line 1888 "build/hi_desktop/hi.y.cpp"
    break;

  case 42: // ENG_NP: ENG_CNP
#line 399 "build/hi_desktop/hi.y"
{
const node_info& ENG_CNP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_CNP");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_CNP);

}
#line 1899 "build/hi_desktop/hi.y.cpp"
    break;

  case 43: // ENG_NP: ENG_QPro ENG_CNP
#line 406 "build/hi_desktop/hi.y"
{
const node_info& ENG_QPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CNP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_QPro ENG_CNP");
yylhs.value=sparser->combine_nodes("ENG_NP",ENG_QPro,ENG_CNP);

}
#line 1911 "build/hi_desktop/hi.y.cpp"
    break;

  case 44: // ENG_NV: ENG_V ENG_VNEG
#line 415 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_VNEG=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NV->ENG_V ENG_VNEG");
yylhs.value=sparser->combine_nodes("ENG_NV",ENG_V,ENG_VNEG);

}
#line 1923 "build/hi_desktop/hi.y.cpp"
    break;

  case 45: // ENG_N_Pl: ENG_N_Pl_0Con_swC
#line 424 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swC);

}
#line 1934 "build/hi_desktop/hi.y.cpp"
    break;

  case 46: // ENG_N_Pl: ENG_N_Pl_0Con_swC ENG_nCon
#line 431 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swC=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swC ENG_nCon");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swC,ENG_nCon);

}
#line 1946 "build/hi_desktop/hi.y.cpp"
    break;

  case 47: // ENG_N_Pl: ENG_N_Pl_0Con_swV
#line 439 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_N_Pl_0Con_swV);

}
#line 1957 "build/hi_desktop/hi.y.cpp"
    break;

  case 48: // ENG_N_Pl: ENG_N_Pl_0Con_swV ENG_nCon
#line 446 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con_swV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Pl_0Con_swV ENG_nCon");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Pl_0Con_swV,ENG_nCon);

}
#line 1969 "build/hi_desktop/hi.y.cpp"
    break;

  case 49: // ENG_N_Pl: ENG_N_Sg ENG_nCon
#line 454 "build/hi_desktop/hi.y"
{
//Exploit read ahead triggered by the shift/reduce conflict due to this very rule and return error to make sure
//that a singular noun cannot combine with more than one constant like in 'list file abc def'
//TODO: Any better solution???
YYERROR;
}
#line 1980 "build/hi_desktop/hi.y.cpp"
    break;

  case 50: // ENG_N_Pl: ENG_nCon
#line 461 "build/hi_desktop/hi.y"
{
const node_info& ENG_nCon=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_nCon");
yylhs.value=sparser->set_node_info("ENG_N_Pl",ENG_nCon);

}
#line 1991 "build/hi_desktop/hi.y.cpp"
    break;

  case 51: // ENG_N_Pl_0Con: ENG_N_Stem ENG_N_lfea_Pl
#line 469 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con->ENG_N_Stem ENG_N_lfea_Pl");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con",ENG_N_Stem,ENG_N_lfea_Pl);

}
#line 2003 "build/hi_desktop/hi.y.cpp"
    break;

  case 52: // ENG_N_Pl_0Con_swC: ENG_N_Pl_0Con ENG_lfea_swConsonant
#line 478 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swC->ENG_N_Pl_0Con ENG_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con_swC",ENG_N_Pl_0Con,ENG_lfea_swConsonant);

}
#line 2015 "build/hi_desktop/hi.y.cpp"
    break;

  case 53: // ENG_N_Pl_0Con_swV: ENG_N_Pl_0Con ENG_lfea_swVowel
#line 487 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl_0Con_swV->ENG_N_Pl_0Con ENG_lfea_swVowel");
yylhs.value=sparser->combine_nodes("ENG_N_Pl_0Con_swV",ENG_N_Pl_0Con,ENG_lfea_swVowel);

}
#line 2027 "build/hi_desktop/hi.y.cpp"
    break;

  case 54: // ENG_N_Sg: ENG_1Con
#line 496 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_1Con");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_1Con);

}
#line 2038 "build/hi_desktop/hi.y.cpp"
    break;

  case 55: // ENG_N_Sg: ENG_N_Sg_0Con_swC
#line 503 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swC);

}
#line 2049 "build/hi_desktop/hi.y.cpp"
    break;

  case 56: // ENG_N_Sg: ENG_N_Sg_0Con_swC ENG_1Con
#line 510 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swC=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swC ENG_1Con");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swC,ENG_1Con);

}
#line 2061 "build/hi_desktop/hi.y.cpp"
    break;

  case 57: // ENG_N_Sg: ENG_N_Sg_0Con_swV
#line 518 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_N_Sg_0Con_swV);

}
#line 2072 "build/hi_desktop/hi.y.cpp"
    break;

  case 58: // ENG_N_Sg: ENG_N_Sg_0Con_swV ENG_1Con
#line 525 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con_swV=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_1Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Sg_0Con_swV ENG_1Con");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Sg_0Con_swV,ENG_1Con);

}
#line 2084 "build/hi_desktop/hi.y.cpp"
    break;

  case 59: // ENG_N_Sg_0Con: ENG_N_Stem ENG_N_lfea_Sg
#line 534 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con->ENG_N_Stem ENG_N_lfea_Sg");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con",ENG_N_Stem,ENG_N_lfea_Sg);

}
#line 2096 "build/hi_desktop/hi.y.cpp"
    break;

  case 60: // ENG_N_Sg_0Con_swC: ENG_N_Sg_0Con ENG_lfea_swConsonant
#line 543 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swConsonant=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swC->ENG_N_Sg_0Con ENG_lfea_swConsonant");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con_swC",ENG_N_Sg_0Con,ENG_lfea_swConsonant);

}
#line 2108 "build/hi_desktop/hi.y.cpp"
    break;

  case 61: // ENG_N_Sg_0Con_swV: ENG_N_Sg_0Con ENG_lfea_swVowel
#line 552 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg_0Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_lfea_swVowel=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg_0Con_swV->ENG_N_Sg_0Con ENG_lfea_swVowel");
yylhs.value=sparser->combine_nodes("ENG_N_Sg_0Con_swV",ENG_N_Sg_0Con,ENG_lfea_swVowel);

}
#line 2120 "build/hi_desktop/hi.y.cpp"
    break;

  case 62: // ENG_N_Stem: t_ENG_N_Stem
#line 561 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_Stem",word);

}
#line 2132 "build/hi_desktop/hi.y.cpp"
    break;

  case 63: // ENG_N_lfea_Pl: t_ENG_N_Pl
#line 570 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Pl);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Pl",word);

}
#line 2144 "build/hi_desktop/hi.y.cpp"
    break;

  case 64: // ENG_N_lfea_Sg: t_ENG_N_Sg
#line 579 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Sg",word);

}
#line 2156 "build/hi_desktop/hi.y.cpp"
    break;

  case 65: // ENG_PP: ENG_Prep ENG_NP
#line 588 "build/hi_desktop/hi.y"
{
const node_info& ENG_Prep=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_Prep ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_PP",ENG_Prep,ENG_NP);

}
#line 2168 "build/hi_desktop/hi.y.cpp"
    break;

  case 66: // ENG_Prep: t_ENG_PREP_Stem
#line 597 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PREP_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Prep",word);

}
#line 2180 "build/hi_desktop/hi.y.cpp"
    break;

  case 67: // ENG_Punct: ENG_Punct_Stem ENG_Punct_FullStop
#line 606 "build/hi_desktop/hi.y"
{
const node_info& ENG_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Punct_FullStop=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct->ENG_Punct_Stem ENG_Punct_FullStop");
yylhs.value=sparser->combine_nodes("ENG_Punct",ENG_Punct_Stem,ENG_Punct_FullStop);

}
#line 2192 "build/hi_desktop/hi.y.cpp"
    break;

  case 68: // ENG_Punct_FullStop: t_ENG_Punct_FullStop
#line 615 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_FullStop);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Punct_FullStop",word);

}
#line 2204 "build/hi_desktop/hi.y.cpp"
    break;

  case 69: // ENG_Punct_Stem: t_ENG_Punct_Stem
#line 624 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Punct_Stem",word);

}
#line 2216 "build/hi_desktop/hi.y.cpp"
    break;

  case 70: // ENG_QPro: t_ENG_QPRO_Stem
#line 633 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_QPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_QPro",word);

}
#line 2228 "build/hi_desktop/hi.y.cpp"
    break;

  case 71: // ENG_RC: ENG_RPro ENG_IVP
#line 642 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_IVP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RC->ENG_RPro ENG_IVP");
yylhs.value=sparser->combine_nodes("ENG_RC",ENG_RPro,ENG_IVP);

}
#line 2240 "build/hi_desktop/hi.y.cpp"
    break;

  case 72: // ENG_RPro: ENG_RPro_stem ENG_RPro_lfea_relative
#line 651 "build/hi_desktop/hi.y"
{
const node_info& ENG_RPro_stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RPro_lfea_relative=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_RPro->ENG_RPro_stem ENG_RPro_lfea_relative");
yylhs.value=sparser->combine_nodes("ENG_RPro",ENG_RPro_stem,ENG_RPro_lfea_relative);

}
#line 2252 "build/hi_desktop/hi.y.cpp"
    break;

  case 73: // ENG_RPro_lfea_relative: t_ENG_RPRO_Relative
#line 660 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Relative);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_RPro_lfea_relative",word);

}
#line 2264 "build/hi_desktop/hi.y.cpp"
    break;

  case 74: // ENG_RPro_stem: t_ENG_RPRO_Stem
#line 669 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_RPRO_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_RPro_stem",word);

}
#line 2276 "build/hi_desktop/hi.y.cpp"
    break;

  case 75: // ENG_TP: ENG_Tense_particle ENG_V_Stem
#line 678 "build/hi_desktop/hi.y"
{
const node_info& ENG_Tense_particle=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_Tense_particle ENG_V_Stem");
yylhs.value=sparser->combine_nodes("ENG_TP",ENG_Tense_particle,ENG_V_Stem);

}
#line 2288 "build/hi_desktop/hi.y.cpp"
    break;

  case 76: // ENG_TP: ENG_V_ger
#line 686 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_ger=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_TP->ENG_V_ger");
yylhs.value=sparser->set_node_info("ENG_TP",ENG_V_ger);

}
#line 2299 "build/hi_desktop/hi.y.cpp"
    break;

  case 77: // ENG_Tense_particle: t_ENG_PAR_Stem
#line 694 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PAR_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Tense_particle",word);

}
#line 2311 "build/hi_desktop/hi.y.cpp"
    break;

  case 78: // ENG_V: ENG_V_Stem
#line 703 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");
yylhs.value=sparser->set_node_info("ENG_V",ENG_V_Stem);

}
#line 2322 "build/hi_desktop/hi.y.cpp"
    break;

  case 79: // ENG_V: ENG_V_Stem ENG_V_lfea_aux
#line 710 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_aux=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem ENG_V_lfea_aux");
yylhs.value=sparser->combine_nodes("ENG_V",ENG_V_Stem,ENG_V_lfea_aux);

}
#line 2334 "build/hi_desktop/hi.y.cpp"
    break;

  case 80: // ENG_VNEG: ENG_VNEG_Stem
#line 719 "build/hi_desktop/hi.y"
{
const node_info& ENG_VNEG_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VNEG->ENG_VNEG_Stem");
yylhs.value=sparser->set_node_info("ENG_VNEG",ENG_VNEG_Stem);

}
#line 2345 "build/hi_desktop/hi.y.cpp"
    break;

  case 81: // ENG_VNEG_Stem: t_ENG_VNEG_Stem
#line 727 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_VNEG_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_VNEG_Stem",word);

}
#line 2357 "build/hi_desktop/hi.y.cpp"
    break;

  case 82: // ENG_VP: ENG_Vbar1
#line 736 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1");
yylhs.value=sparser->set_node_info("ENG_VP",ENG_Vbar1);

}
#line 2368 "build/hi_desktop/hi.y.cpp"
    break;

  case 83: // ENG_VP: ENG_Vbar1 ENG_AdvP
#line 743 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AdvP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_AdvP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_AdvP);

}
#line 2380 "build/hi_desktop/hi.y.cpp"
    break;

  case 84: // ENG_VP: ENG_Vbar1 ENG_RC
#line 751 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1 ENG_RC");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1,ENG_RC);

}
#line 2392 "build/hi_desktop/hi.y.cpp"
    break;

  case 85: // ENG_VP: ENG_Vbar1_Ind ENG_AP
#line 759 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1_Ind=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1_Ind ENG_AP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1_Ind,ENG_AP);

}
#line 2404 "build/hi_desktop/hi.y.cpp"
    break;

  case 86: // ENG_VP: ENG_Vbar1_Ind ENG_DP
#line 767 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1_Ind=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar1_Ind ENG_DP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar1_Ind,ENG_DP);

}
#line 2416 "build/hi_desktop/hi.y.cpp"
    break;

  case 87: // ENG_VP: ENG_Vbar2
#line 775 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2");
yylhs.value=sparser->set_node_info("ENG_VP",ENG_Vbar2);

}
#line 2427 "build/hi_desktop/hi.y.cpp"
    break;

  case 88: // ENG_VP: ENG_Vbar2 ENG_PP
#line 782 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_PP);

}
#line 2439 "build/hi_desktop/hi.y.cpp"
    break;

  case 89: // ENG_VP: ENG_Vbar2 ENG_RC
#line 790 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_RC=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar2 ENG_RC");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar2,ENG_RC);

}
#line 2451 "build/hi_desktop/hi.y.cpp"
    break;

  case 90: // ENG_VP: ENG_Vbar3 ENG_NP
#line 798 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar3=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar3 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar3,ENG_NP);

}
#line 2463 "build/hi_desktop/hi.y.cpp"
    break;

  case 91: // ENG_VP: ENG_Vbar4 ENG_DP
#line 806 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar4=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP->ENG_Vbar4 ENG_DP");
yylhs.value=sparser->combine_nodes("ENG_VP",ENG_Vbar4,ENG_DP);

}
#line 2475 "build/hi_desktop/hi.y.cpp"
    break;

  case 92: // ENG_VP_Int: ENG_Vbar1 ENG_AP
#line 815 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_Vbar1,"V","interrogative",true);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Int->ENG_Vbar1 ENG_AP");
yylhs.value=sparser->combine_nodes("ENG_VP_Int",ENG_Vbar1,ENG_AP);
}
#line 2487 "build/hi_desktop/hi.y.cpp"
    break;

  case 93: // ENG_V_Stem: t_ENG_V_Stem
#line 824 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_Stem",word);

}
#line 2499 "build/hi_desktop/hi.y.cpp"
    break;

  case 94: // ENG_V_ger: ENG_V_Stem ENG_V_lfea_ger
#line 833 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_ger=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_ger->ENG_V_Stem ENG_V_lfea_ger");
yylhs.value=sparser->combine_nodes("ENG_V_ger",ENG_V_Stem,ENG_V_lfea_ger);

}
#line 2511 "build/hi_desktop/hi.y.cpp"
    break;

  case 95: // ENG_V_lfea_aux: t_ENG_V_Aux
#line 842 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Aux);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_aux",word);

}
#line 2523 "build/hi_desktop/hi.y.cpp"
    break;

  case 96: // ENG_V_lfea_ger: t_ENG_V_Gerund
#line 851 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Gerund);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_ger",word);

}
#line 2535 "build/hi_desktop/hi.y.cpp"
    break;

  case 97: // ENG_Vbar1: ENG_V ENG_NP
#line 860 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar1->ENG_V ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_Vbar1",ENG_V,ENG_NP);
}
#line 2547 "build/hi_desktop/hi.y.cpp"
    break;

  case 98: // ENG_Vbar1_Ind: ENG_N_Sg ENG_V
#line 869 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar1_Ind->ENG_N_Sg ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar1_Ind",ENG_V,ENG_N_Sg);
}
#line 2559 "build/hi_desktop/hi.y.cpp"
    break;

  case 99: // ENG_Vbar2: ENG_Vbar1 ENG_NP
#line 878 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_NP);

}
#line 2571 "build/hi_desktop/hi.y.cpp"
    break;

  case 100: // ENG_Vbar2: ENG_Vbar1 ENG_PP
#line 886 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar2->ENG_Vbar1 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_Vbar2",ENG_Vbar1,ENG_PP);

}
#line 2583 "build/hi_desktop/hi.y.cpp"
    break;

  case 101: // ENG_Vbar3: ENG_V ENG_AdvP
#line 895 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_AdvP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar3->ENG_V ENG_AdvP");
yylhs.value=sparser->combine_nodes("ENG_Vbar3",ENG_V,ENG_AdvP);

}
#line 2595 "build/hi_desktop/hi.y.cpp"
    break;

  case 102: // ENG_Vbar4: ENG_DP ENG_V
#line 904 "build/hi_desktop/hi.y"
{
const node_info& ENG_DP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_DP ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_DP);
}
#line 2607 "build/hi_desktop/hi.y.cpp"
    break;

  case 103: // ENG_Vbar4: ENG_TP ENG_V
#line 912 "build/hi_desktop/hi.y"
{
const node_info& ENG_TP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(ENG_V,"main_verb");
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Vbar4->ENG_TP ENG_V");
yylhs.value=sparser->combine_nodes("ENG_Vbar4",ENG_V,ENG_TP);
}
#line 2619 "build/hi_desktop/hi.y.cpp"
    break;

  case 104: // ENG_lfea_IndefDet: t_ENG_DET_Indef
#line 921 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Indef);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_IndefDet",word);

}
#line 2631 "build/hi_desktop/hi.y.cpp"
    break;

  case 105: // ENG_lfea_fwConsonant: t_ENG_DET_fwConsonant
#line 930 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_fwConsonant",word);

}
#line 2643 "build/hi_desktop/hi.y.cpp"
    break;

  case 106: // ENG_lfea_fwVowel: t_ENG_DET_fwVowel
#line 939 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_fwVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_fwVowel",word);

}
#line 2655 "build/hi_desktop/hi.y.cpp"
    break;

  case 107: // ENG_lfea_swConsonant: t_ENG_N_swConsonant
#line 948 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swConsonant);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_swConsonant",word);

}
#line 2667 "build/hi_desktop/hi.y.cpp"
    break;

  case 108: // ENG_lfea_swVowel: t_ENG_N_swVowel
#line 957 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_swVowel);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_lfea_swVowel",word);

}
#line 2679 "build/hi_desktop/hi.y.cpp"
    break;

  case 109: // ENG_nCon: ENG_1Con ENG_Con
#line 966 "build/hi_desktop/hi.y"
{
const node_info& ENG_1Con=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_1Con ENG_Con");
yylhs.value=sparser->combine_nodes("ENG_nCon",ENG_1Con,ENG_Con);

}
#line 2691 "build/hi_desktop/hi.y.cpp"
    break;

  case 110: // ENG_nCon: ENG_nCon ENG_Con
#line 974 "build/hi_desktop/hi.y"
{
const node_info& ENG_nCon=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Con=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_nCon->ENG_nCon ENG_Con");
yylhs.value=sparser->combine_nodes("ENG_nCon",ENG_nCon,ENG_Con);

}
#line 2703 "build/hi_desktop/hi.y.cpp"
    break;

  case 111: // S: ENG_VP ENG_Punct
#line 983 "build/hi_desktop/hi.y"
{
const node_info& ENG_VP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Punct=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP ENG_Punct");
yylhs.value=sparser->combine_nodes("S",ENG_VP,ENG_Punct);

}
#line 2715 "build/hi_desktop/hi.y.cpp"
    break;

  case 112: // S: ENG_VP_Int
#line 991 "build/hi_desktop/hi.y"
{
const node_info& ENG_VP_Int=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"S->ENG_VP_Int");
yylhs.value=sparser->set_node_info("S",ENG_VP_Int);

}
#line 2726 "build/hi_desktop/hi.y.cpp"
    break;


#line 2730 "build/hi_desktop/hi.y.cpp"

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


  const signed char parser::yypact_ninf_ = -58;

  const signed char parser::yytable_ninf_ = -19;

  const signed char
  parser::yypact_[] =
  {
      21,   -58,   -58,   -58,   -58,   -58,   -58,   -58,    -4,     7,
      51,    14,    14,    -4,    36,    47,    47,    27,    -4,    -4,
      86,    48,   -58,    -2,   -58,    43,    17,    37,    88,    58,
      77,   -58,    65,   -58,   -58,   -58,   -58,   -58,   -58,    69,
     -58,    76,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,    31,   -58,
     -58,    96,   -58,    31,   -58,    12,    79,   -58,   -58,    79,
      15,   -58,   -58,   -58,   -58,   -58,    36,    47,    47,    47,
      74,    45,    47,   -58,   -58,   100,   -58,   -58,   -58,   -58,
     -58,   -58,    31,   -58,   -58,   -58,    88,   -58,    -4,   101,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     109,   -58,    47,   -58,   -58,   -58,    24,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,    47,    47,    47,    47,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   108,    84,   -58,   -58,
      24,    24,   -58,   -58,   -58,   -58,   -58,   -58
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    29,    32,    62,    93,    77,    54,     2,     0,     0,
       0,     0,     0,     0,     0,    55,    57,     0,     0,     0,
       0,     0,   112,    78,    76,    82,     0,    87,     0,     0,
       0,   102,    78,   104,    36,   106,   105,    37,    38,     0,
      30,     0,    31,    98,   108,   107,    60,    61,    56,    58,
      64,    59,   103,    75,    10,    16,    70,     6,    54,     4,
      11,     0,     5,     0,     3,     7,     8,    17,   101,     0,
       9,    41,    42,    24,    97,    39,     0,    45,    47,    40,
       0,     0,    50,    69,   111,     0,    95,    96,    79,    94,
      66,    74,    92,    83,    99,   100,     0,    84,     0,     0,
      85,    86,    88,    89,    90,    91,     1,   109,    21,    22,
       0,    12,    54,    23,    19,    28,     0,    13,    25,    14,
      20,    15,    52,    53,     0,    46,    48,    49,    63,    51,
      43,   110,    68,    67,    65,    71,     0,     0,    73,    72,
      26,    27,    33,    81,    34,    35,    44,    80
  };

  const short
  parser::yypgoto_[] =
  {
     -58,     2,    62,   -58,   -58,   -58,   -25,   -58,   -56,   -58,
     -58,   102,   -58,     8,   -58,    44,   -58,    49,   -58,   -53,
      41,   -58,   -58,   -58,   -58,   -58,   -57,   -18,   -58,   -58,
     -58,    68,    70,   129,    99,   119,   120,    11,   -58,   -58,
     -23,   -58,   -58,   -58,   -58,   -58,   104,   -58,   -58,   -58,
     -58,   -58,    -5,   -58,   -58,   -58,   -58,    20,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,    57,
      59,    38,   -58
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,   116,   117,   118,     7,
       8,     9,   135,    10,    11,    12,    73,    74,   136,    75,
      76,    77,    78,    79,    14,    15,    16,    80,   129,    51,
      95,    96,    84,   133,    85,    81,    97,    98,   139,    99,
      18,    19,    20,   146,   147,    21,    22,    32,    24,    88,
      89,    25,    26,    27,    28,    29,    34,    37,    38,    46,
      47,    82,    30
  };

  const short
  parser::yytable_[] =
  {
      92,   100,     6,    31,   102,   107,   113,    94,    43,   114,
     104,    17,     4,    52,   120,    86,    54,    48,    49,    54,
      23,    54,    17,    17,     1,     3,    87,     2,    54,   131,
      33,     2,     3,    57,     1,   113,    57,     4,    57,    53,
      50,   -18,     3,     5,   115,    57,     1,    54,     1,    54,
       1,    90,    55,    83,     3,    91,     3,    90,    56,   107,
     140,    91,    44,    45,    57,   112,    57,   101,     2,   110,
     105,   107,   131,   131,   131,    35,    36,   106,   134,   124,
     124,   124,    86,   112,   114,   120,   128,    50,    54,     1,
      54,     1,    54,   137,   112,    55,    45,     3,    90,     3,
      54,    56,    44,    56,   143,    57,   132,    57,   115,    57,
      39,    41,   144,   142,   145,   125,   126,   127,   119,   121,
     138,   128,    90,   111,   141,   130,   108,    93,   109,    13,
      40,   103,    42,   122,     0,   123
  };

  const short
  parser::yycheck_[] =
  {
      25,    26,     0,     8,    27,    58,    63,    25,    13,    65,
      28,     0,    16,    18,    70,    17,     4,    15,    16,     4,
       0,     4,    11,    12,     3,    11,    28,    10,     4,    82,
      23,    10,    11,    21,     3,    92,    21,    16,    21,    19,
      13,    29,    11,    22,    29,    21,     3,     4,     3,     4,
       3,    14,     9,     5,    11,    18,    11,    14,    15,   112,
     116,    18,    26,    27,    21,    63,    21,    26,    10,    58,
      29,   124,   125,   126,   127,    24,    25,     0,    96,    77,
      78,    79,    17,    81,   140,   141,    12,    13,     4,     3,
       4,     3,     4,    98,    92,     9,    27,    11,    14,    11,
       4,    15,    26,    15,    20,    21,     6,    21,    29,    21,
      11,    12,   137,   136,   137,    77,    78,    79,    69,    70,
      19,    12,    14,    61,   116,    81,    58,    25,    58,     0,
      11,    27,    12,    76,    -1,    76
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    10,    11,    16,    22,    31,    49,    50,    51,
      53,    54,    55,    63,    64,    65,    66,    67,    80,    81,
      82,    85,    86,    87,    88,    91,    92,    93,    94,    95,
     102,    82,    87,    23,    96,    24,    25,    97,    98,    64,
      65,    64,    66,    82,    26,    27,    99,   100,    31,    31,
      13,    69,    82,    87,     4,     9,    15,    21,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    56,    57,    59,    60,    61,    62,    63,
      67,    75,   101,     5,    72,    74,    17,    28,    89,    90,
      14,    18,    36,    41,    57,    70,    71,    76,    77,    79,
      36,    50,    70,    76,    57,    50,     0,    49,    61,    62,
      67,    32,    31,    56,    38,    29,    46,    47,    48,    47,
      38,    47,    99,   100,    31,   101,   101,   101,    12,    68,
      45,    49,     6,    73,    57,    52,    58,    82,    19,    78,
      38,    43,    70,    20,    36,    70,    83,    84
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    30,    31,    32,    33,    34,    35,    36,    36,    36,
      37,    38,    38,    39,    39,    39,    40,    41,    42,    43,
      43,    44,    44,    45,    45,    46,    47,    47,    48,    49,
      50,    50,    51,    52,    52,    52,    53,    54,    55,    56,
      56,    57,    57,    57,    58,    59,    59,    59,    59,    59,
      59,    60,    61,    62,    63,    63,    63,    63,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    80,    81,    82,    82,
      83,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      93,    94,    95,    95,    96,    97,    98,    99,   100,   101,
     101,   102,   102
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     2,     1,     1,     2,     2,     1,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     2,     1,     2,     1,     2,     2,
       1,     2,     2,     2,     1,     1,     2,     1,     2,     2,
       2,     2,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     1,     1,     2,
       1,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     2,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "t_ENG_CON_Stem", "t_ENG_A_Stem",
  "t_ENG_Punct_Stem", "t_ENG_Punct_FullStop", "t_ENG_Punct_QuestionMark",
  "t_ENG_Punct_ExclamationMark", "t_ENG_ADV_Stem", "t_ENG_DET_Stem",
  "t_ENG_N_Stem", "t_ENG_N_Pl", "t_ENG_N_Sg", "t_ENG_PREP_Stem",
  "t_ENG_QPRO_Stem", "t_ENG_V_Stem", "t_ENG_V_Aux", "t_ENG_RPRO_Stem",
  "t_ENG_RPRO_Relative", "t_ENG_VNEG_Stem", "t_ENG_ANEG_Stem",
  "t_ENG_PAR_Stem", "t_ENG_DET_Indef", "t_ENG_DET_fwVowel",
  "t_ENG_DET_fwConsonant", "t_ENG_N_swVowel", "t_ENG_N_swConsonant",
  "t_ENG_V_Gerund", "t_ENG_CONJ_Stem", "$accept", "ENG_1Con", "ENG_A",
  "ENG_A0NEG", "ENG_ANEG", "ENG_ANEG_Stem", "ENG_AP", "ENG_A_Stem",
  "ENG_Abar1", "ENG_Abar2", "ENG_Adv", "ENG_AdvP", "ENG_Ahead",
  "ENG_Alist", "ENG_CAP", "ENG_CNP", "ENG_CONJ", "ENG_CONJA",
  "ENG_CONJ_Stem", "ENG_Con", "ENG_DP", "ENG_Det_stem", "ENG_IVP",
  "ENG_Indef_Det", "ENG_Indef_Det_a", "ENG_Indef_Det_an", "ENG_N",
  "ENG_NP", "ENG_NV", "ENG_N_Pl", "ENG_N_Pl_0Con", "ENG_N_Pl_0Con_swC",
  "ENG_N_Pl_0Con_swV", "ENG_N_Sg", "ENG_N_Sg_0Con", "ENG_N_Sg_0Con_swC",
  "ENG_N_Sg_0Con_swV", "ENG_N_Stem", "ENG_N_lfea_Pl", "ENG_N_lfea_Sg",
  "ENG_PP", "ENG_Prep", "ENG_Punct", "ENG_Punct_FullStop",
  "ENG_Punct_Stem", "ENG_QPro", "ENG_RC", "ENG_RPro",
  "ENG_RPro_lfea_relative", "ENG_RPro_stem", "ENG_TP",
  "ENG_Tense_particle", "ENG_V", "ENG_VNEG", "ENG_VNEG_Stem", "ENG_VP",
  "ENG_VP_Int", "ENG_V_Stem", "ENG_V_ger", "ENG_V_lfea_aux",
  "ENG_V_lfea_ger", "ENG_Vbar1", "ENG_Vbar1_Ind", "ENG_Vbar2", "ENG_Vbar3",
  "ENG_Vbar4", "ENG_lfea_IndefDet", "ENG_lfea_fwConsonant",
  "ENG_lfea_fwVowel", "ENG_lfea_swConsonant", "ENG_lfea_swVowel",
  "ENG_nCon", "S", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    67,    67,    75,    83,    91,    99,   108,   115,   122,
     130,   139,   146,   155,   163,   171,   180,   189,   197,   205,
     213,   222,   230,   239,   247,   255,   263,   271,   280,   289,
     298,   306,   315,   324,   332,   340,   349,   358,   367,   376,
     383,   391,   398,   405,   414,   423,   430,   438,   445,   453,
     460,   468,   477,   486,   495,   502,   509,   517,   524,   533,
     542,   551,   560,   569,   578,   587,   596,   605,   614,   623,
     632,   641,   650,   659,   668,   677,   685,   693,   702,   709,
     718,   726,   735,   742,   750,   758,   766,   774,   781,   789,
     797,   805,   814,   823,   832,   841,   850,   859,   868,   877,
     885,   894,   903,   911,   920,   929,   938,   947,   956,   965,
     973,   982,   990
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
      25,    26,    27,    28,    29
    };
    // Last valid token kind.
    const int code_max = 284;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 3370 "build/hi_desktop/hi.y.cpp"

#line 997 "build/hi_desktop/hi.y"

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
            else if(toa&HI_SEMANTICS){
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
