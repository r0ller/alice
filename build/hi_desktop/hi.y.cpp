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
    t_ENG_CON_3sg = 259,           // t_ENG_CON_3sg
    t_ENG_CON_GEN = 260,           // t_ENG_CON_GEN
    t_ENG_DET_Stem = 261,          // t_ENG_DET_Stem
    t_ENG_N_Stem = 262,            // t_ENG_N_Stem
    t_ENG_N_Pl = 263,              // t_ENG_N_Pl
    t_ENG_N_Sg = 264,              // t_ENG_N_Sg
    t_ENG_PREP_Stem = 265,         // t_ENG_PREP_Stem
    t_ENG_PRON_Stem = 266,         // t_ENG_PRON_Stem
    t_ENG_PRON_wh = 267,           // t_ENG_PRON_wh
    t_ENG_V_Stem = 268,            // t_ENG_V_Stem
    t_ENG_V_3sg = 269,             // t_ENG_V_3sg
    t_ENG_V_Aux = 270,             // t_ENG_V_Aux
    t_ENG_Num_Stem = 271,          // t_ENG_Num_Stem
    t_ENG_Num_Nom = 272,           // t_ENG_Num_Nom
    t_ENG_Num_Ord = 273,           // t_ENG_Num_Ord
    t_ENG_Num_Npref1n = 274,       // t_ENG_Num_Npref1n
    t_ENG_Num_Npref2n = 275,       // t_ENG_Num_Npref2n
    t_ENG_Num_Npref3n = 276,       // t_ENG_Num_Npref3n
    t_ENG_Num_Npref4n = 277,       // t_ENG_Num_Npref4n
    t_ENG_Num_Npref5n = 278,       // t_ENG_Num_Npref5n
    t_ENG_Num_Npref6n = 279,       // t_ENG_Num_Npref6n
    t_ENG_Num_Npref7n = 280,       // t_ENG_Num_Npref7n
    t_ENG_Num_Npref8n = 281,       // t_ENG_Num_Npref8n
    t_ENG_Num_Npref9n = 282,       // t_ENG_Num_Npref9n
    t_ENG_Punct_Stem = 283,        // t_ENG_Punct_Stem
    t_ENG_Punct_FullStop = 284,    // t_ENG_Punct_FullStop
    t_ENG_Punct_QuestionMark = 285, // t_ENG_Punct_QuestionMark
    t_ENG_Punct_ExclamationMark = 286 // t_ENG_Punct_ExclamationMark
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
        YYNTOKENS = 32, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_t_ENG_CON_Stem = 3,                    // t_ENG_CON_Stem
        S_t_ENG_CON_3sg = 4,                     // t_ENG_CON_3sg
        S_t_ENG_CON_GEN = 5,                     // t_ENG_CON_GEN
        S_t_ENG_DET_Stem = 6,                    // t_ENG_DET_Stem
        S_t_ENG_N_Stem = 7,                      // t_ENG_N_Stem
        S_t_ENG_N_Pl = 8,                        // t_ENG_N_Pl
        S_t_ENG_N_Sg = 9,                        // t_ENG_N_Sg
        S_t_ENG_PREP_Stem = 10,                  // t_ENG_PREP_Stem
        S_t_ENG_PRON_Stem = 11,                  // t_ENG_PRON_Stem
        S_t_ENG_PRON_wh = 12,                    // t_ENG_PRON_wh
        S_t_ENG_V_Stem = 13,                     // t_ENG_V_Stem
        S_t_ENG_V_3sg = 14,                      // t_ENG_V_3sg
        S_t_ENG_V_Aux = 15,                      // t_ENG_V_Aux
        S_t_ENG_Num_Stem = 16,                   // t_ENG_Num_Stem
        S_t_ENG_Num_Nom = 17,                    // t_ENG_Num_Nom
        S_t_ENG_Num_Ord = 18,                    // t_ENG_Num_Ord
        S_t_ENG_Num_Npref1n = 19,                // t_ENG_Num_Npref1n
        S_t_ENG_Num_Npref2n = 20,                // t_ENG_Num_Npref2n
        S_t_ENG_Num_Npref3n = 21,                // t_ENG_Num_Npref3n
        S_t_ENG_Num_Npref4n = 22,                // t_ENG_Num_Npref4n
        S_t_ENG_Num_Npref5n = 23,                // t_ENG_Num_Npref5n
        S_t_ENG_Num_Npref6n = 24,                // t_ENG_Num_Npref6n
        S_t_ENG_Num_Npref7n = 25,                // t_ENG_Num_Npref7n
        S_t_ENG_Num_Npref8n = 26,                // t_ENG_Num_Npref8n
        S_t_ENG_Num_Npref9n = 27,                // t_ENG_Num_Npref9n
        S_t_ENG_Punct_Stem = 28,                 // t_ENG_Punct_Stem
        S_t_ENG_Punct_FullStop = 29,             // t_ENG_Punct_FullStop
        S_t_ENG_Punct_QuestionMark = 30,         // t_ENG_Punct_QuestionMark
        S_t_ENG_Punct_ExclamationMark = 31,      // t_ENG_Punct_ExclamationMark
        S_YYACCEPT = 32,                         // $accept
        S_ENG_1CON = 33,                         // ENG_1CON
        S_ENG_CON = 34,                          // ENG_CON
        S_ENG_CON_3sgGEN = 35,                   // ENG_CON_3sgGEN
        S_ENG_CON_GEN = 36,                      // ENG_CON_GEN
        S_ENG_CON_lfea_3sg = 37,                 // ENG_CON_lfea_3sg
        S_ENG_CON_lfea_GEN = 38,                 // ENG_CON_lfea_GEN
        S_ENG_DET_Stem = 39,                     // ENG_DET_Stem
        S_ENG_DP = 40,                           // ENG_DP
        S_ENG_N = 41,                            // ENG_N
        S_ENG_NP = 42,                           // ENG_NP
        S_ENG_N_Pl = 43,                         // ENG_N_Pl
        S_ENG_N_Sg = 44,                         // ENG_N_Sg
        S_ENG_N_Stem = 45,                       // ENG_N_Stem
        S_ENG_N_lfea_Pl = 46,                    // ENG_N_lfea_Pl
        S_ENG_N_lfea_Sg = 47,                    // ENG_N_lfea_Sg
        S_ENG_Num = 48,                          // ENG_Num
        S_ENG_Num_Nom = 49,                      // ENG_Num_Nom
        S_ENG_Num_Ord = 50,                      // ENG_Num_Ord
        S_ENG_Num_Pref = 51,                     // ENG_Num_Pref
        S_ENG_Num_Stem = 52,                     // ENG_Num_Stem
        S_ENG_Num_lfea_Nom = 53,                 // ENG_Num_lfea_Nom
        S_ENG_Num_lfea_Ord = 54,                 // ENG_Num_lfea_Ord
        S_ENG_PP = 55,                           // ENG_PP
        S_ENG_PREP = 56,                         // ENG_PREP
        S_ENG_PREP_Stem = 57,                    // ENG_PREP_Stem
        S_ENG_PRON_Stem = 58,                    // ENG_PRON_Stem
        S_ENG_PRON_lfea_wh = 59,                 // ENG_PRON_lfea_wh
        S_ENG_PRON_qw = 60,                      // ENG_PRON_qw
        S_ENG_Punct_ExclamationMark = 61,        // ENG_Punct_ExclamationMark
        S_ENG_Punct_FullStop = 62,               // ENG_Punct_FullStop
        S_ENG_Punct_Imp = 63,                    // ENG_Punct_Imp
        S_ENG_Punct_Ind = 64,                    // ENG_Punct_Ind
        S_ENG_Punct_Int = 65,                    // ENG_Punct_Int
        S_ENG_Punct_QuestionMark = 66,           // ENG_Punct_QuestionMark
        S_ENG_Punct_Stem = 67,                   // ENG_Punct_Stem
        S_ENG_V = 68,                            // ENG_V
        S_ENG_VP_Imp = 69,                       // ENG_VP_Imp
        S_ENG_VP_Ind = 70,                       // ENG_VP_Ind
        S_ENG_VP_Int = 71,                       // ENG_VP_Int
        S_ENG_V_Aux = 72,                        // ENG_V_Aux
        S_ENG_V_Stem = 73,                       // ENG_V_Stem
        S_ENG_V_lfea_3sg = 74,                   // ENG_V_lfea_3sg
        S_ENG_V_lfea_Aux = 75,                   // ENG_V_lfea_Aux
        S_ENG_Vbar1 = 76,                        // ENG_Vbar1
        S_ENG_Vbar2 = 77,                        // ENG_Vbar2
        S_ENG_Vbar3 = 78,                        // ENG_Vbar3
        S_S = 79                                 // S
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
    typedef signed char state_type;

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

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

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
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

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
      yylast_ = 62,     ///< Last index in yytable_.
      yynnts_ = 48,  ///< Number of nonterminal symbols.
      yyfinal_ = 52 ///< Termination state number.
    };



  };


} // yy
#line 860 "build/hi_desktop/hi.y.cpp"






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


#line 901 "build/hi_desktop/hi.y.cpp"


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
#line 974 "build/hi_desktop/hi.y.cpp"

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
  case 2: // ENG_1CON: ENG_CON
#line 70 "build/hi_desktop/hi.y"
{
const node_info& ENG_CON=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_1CON->ENG_CON");
yylhs.value=sparser->set_node_info("ENG_1CON",ENG_CON);

}
#line 1435 "build/hi_desktop/hi.y.cpp"
    break;

  case 3: // ENG_CON: t_ENG_CON_Stem
#line 78 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_CON",word);

}
#line 1447 "build/hi_desktop/hi.y.cpp"
    break;

  case 4: // ENG_CON_3sgGEN: ENG_CON_lfea_3sg ENG_CON_lfea_GEN
#line 87 "build/hi_desktop/hi.y"
{
const node_info& ENG_CON_lfea_3sg=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CON_lfea_GEN=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CON_3sgGEN->ENG_CON_lfea_3sg ENG_CON_lfea_GEN");
yylhs.value=sparser->combine_nodes("ENG_CON_3sgGEN",ENG_CON_lfea_3sg,ENG_CON_lfea_GEN);

}
#line 1459 "build/hi_desktop/hi.y.cpp"
    break;

  case 5: // ENG_CON_GEN: ENG_CON ENG_CON_3sgGEN
#line 96 "build/hi_desktop/hi.y"
{
const node_info& ENG_CON=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_CON_3sgGEN=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_CON_GEN->ENG_CON ENG_CON_3sgGEN");
yylhs.value=sparser->combine_nodes("ENG_CON_GEN",ENG_CON,ENG_CON_3sgGEN);

}
#line 1471 "build/hi_desktop/hi.y.cpp"
    break;

  case 6: // ENG_CON_lfea_3sg: t_ENG_CON_3sg
#line 105 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_3sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_CON_lfea_3sg",word);

}
#line 1483 "build/hi_desktop/hi.y.cpp"
    break;

  case 7: // ENG_CON_lfea_GEN: t_ENG_CON_GEN
#line 114 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_CON_GEN);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_CON_lfea_GEN",word);

}
#line 1495 "build/hi_desktop/hi.y.cpp"
    break;

  case 8: // ENG_DET_Stem: t_ENG_DET_Stem
#line 123 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_DET_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_DET_Stem",word);

}
#line 1507 "build/hi_desktop/hi.y.cpp"
    break;

  case 9: // ENG_DP: ENG_DET_Stem ENG_N
#line 132 "build/hi_desktop/hi.y"
{
const node_info& ENG_DET_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_DET_Stem ENG_N");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_DET_Stem,ENG_N);

}
#line 1519 "build/hi_desktop/hi.y.cpp"
    break;

  case 10: // ENG_DP: ENG_DET_Stem ENG_Num_Nom
#line 140 "build/hi_desktop/hi.y"
{
const node_info& ENG_DET_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_Nom=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_DET_Stem ENG_Num_Nom");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_DET_Stem,ENG_Num_Nom);

}
#line 1531 "build/hi_desktop/hi.y.cpp"
    break;

  case 11: // ENG_DP: ENG_DET_Stem ENG_Num_Ord
#line 148 "build/hi_desktop/hi.y"
{
const node_info& ENG_DET_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_Ord=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_DP->ENG_DET_Stem ENG_Num_Ord");
yylhs.value=sparser->combine_nodes("ENG_DP",ENG_DET_Stem,ENG_Num_Ord);

}
#line 1543 "build/hi_desktop/hi.y.cpp"
    break;

  case 12: // ENG_N: ENG_N_Pl
#line 157 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Pl");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Pl);

}
#line 1554 "build/hi_desktop/hi.y.cpp"
    break;

  case 13: // ENG_N: ENG_N_Sg
#line 164 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N->ENG_N_Sg");
yylhs.value=sparser->set_node_info("ENG_N",ENG_N_Sg);

}
#line 1565 "build/hi_desktop/hi.y.cpp"
    break;

  case 14: // ENG_NP: ENG_CON_GEN ENG_N
#line 172 "build/hi_desktop/hi.y"
{
const node_info& main_node=sparser->get_node_info(yystack_[1].value);
const node_info& dependent_node=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(dependent_node,"N",std::string("qword"));
std::string parent_symbol="ENG_NP";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
yylhs.value=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
#line 1578 "build/hi_desktop/hi.y.cpp"
    break;

  case 15: // ENG_NP: ENG_N
#line 181 "build/hi_desktop/hi.y"
{
const node_info& ENG_N=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_NP->ENG_N");
yylhs.value=sparser->set_node_info("ENG_NP",ENG_N);

}
#line 1589 "build/hi_desktop/hi.y.cpp"
    break;

  case 16: // ENG_N_Pl: ENG_N_Stem ENG_N_lfea_Pl
#line 189 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Pl=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Pl->ENG_N_Stem ENG_N_lfea_Pl");
yylhs.value=sparser->combine_nodes("ENG_N_Pl",ENG_N_Stem,ENG_N_lfea_Pl);

}
#line 1601 "build/hi_desktop/hi.y.cpp"
    break;

  case 17: // ENG_N_Sg: ENG_1CON
#line 198 "build/hi_desktop/hi.y"
{
const node_info& ENG_1CON=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_1CON");
yylhs.value=sparser->set_node_info("ENG_N_Sg",ENG_1CON);

}
#line 1612 "build/hi_desktop/hi.y.cpp"
    break;

  case 18: // ENG_N_Sg: ENG_N_Stem ENG_N_lfea_Sg
#line 205 "build/hi_desktop/hi.y"
{
const node_info& ENG_N_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_N_lfea_Sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_N_Sg->ENG_N_Stem ENG_N_lfea_Sg");
yylhs.value=sparser->combine_nodes("ENG_N_Sg",ENG_N_Stem,ENG_N_lfea_Sg);

}
#line 1624 "build/hi_desktop/hi.y.cpp"
    break;

  case 19: // ENG_N_Stem: t_ENG_N_Stem
#line 214 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_Stem",word);

}
#line 1636 "build/hi_desktop/hi.y.cpp"
    break;

  case 20: // ENG_N_lfea_Pl: t_ENG_N_Pl
#line 223 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Pl);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Pl",word);

}
#line 1648 "build/hi_desktop/hi.y.cpp"
    break;

  case 21: // ENG_N_lfea_Sg: t_ENG_N_Sg
#line 232 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_N_Sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_N_lfea_Sg",word);

}
#line 1660 "build/hi_desktop/hi.y.cpp"
    break;

  case 22: // ENG_Num: ENG_Num_Pref ENG_Num
#line 241 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num_Pref=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Pref ENG_Num");
yylhs.value=sparser->combine_nodes("ENG_Num",ENG_Num_Pref,ENG_Num);

}
#line 1672 "build/hi_desktop/hi.y.cpp"
    break;

  case 23: // ENG_Num: ENG_Num_Stem
#line 249 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num->ENG_Num_Stem");
yylhs.value=sparser->set_node_info("ENG_Num",ENG_Num_Stem);

}
#line 1683 "build/hi_desktop/hi.y.cpp"
    break;

  case 24: // ENG_Num_Nom: ENG_Num ENG_Num_lfea_Nom
#line 257 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_lfea_Nom=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num_Nom->ENG_Num ENG_Num_lfea_Nom");
yylhs.value=sparser->combine_nodes("ENG_Num_Nom",ENG_Num,ENG_Num_lfea_Nom);

}
#line 1695 "build/hi_desktop/hi.y.cpp"
    break;

  case 25: // ENG_Num_Ord: ENG_Num ENG_Num_lfea_Ord
#line 266 "build/hi_desktop/hi.y"
{
const node_info& ENG_Num=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Num_lfea_Ord=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Num_Ord->ENG_Num ENG_Num_lfea_Ord");
yylhs.value=sparser->combine_nodes("ENG_Num_Ord",ENG_Num,ENG_Num_lfea_Ord);

}
#line 1707 "build/hi_desktop/hi.y.cpp"
    break;

  case 26: // ENG_Num_Pref: t_ENG_Num_Npref1n
#line 275 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref1n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1719 "build/hi_desktop/hi.y.cpp"
    break;

  case 27: // ENG_Num_Pref: t_ENG_Num_Npref2n
#line 283 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref2n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1731 "build/hi_desktop/hi.y.cpp"
    break;

  case 28: // ENG_Num_Pref: t_ENG_Num_Npref3n
#line 291 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref3n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1743 "build/hi_desktop/hi.y.cpp"
    break;

  case 29: // ENG_Num_Pref: t_ENG_Num_Npref4n
#line 299 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref4n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1755 "build/hi_desktop/hi.y.cpp"
    break;

  case 30: // ENG_Num_Pref: t_ENG_Num_Npref5n
#line 307 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref5n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1767 "build/hi_desktop/hi.y.cpp"
    break;

  case 31: // ENG_Num_Pref: t_ENG_Num_Npref6n
#line 315 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref6n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1779 "build/hi_desktop/hi.y.cpp"
    break;

  case 32: // ENG_Num_Pref: t_ENG_Num_Npref7n
#line 323 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref7n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1791 "build/hi_desktop/hi.y.cpp"
    break;

  case 33: // ENG_Num_Pref: t_ENG_Num_Npref8n
#line 331 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref8n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1803 "build/hi_desktop/hi.y.cpp"
    break;

  case 34: // ENG_Num_Pref: t_ENG_Num_Npref9n
#line 339 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Npref9n);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Pref",word);

}
#line 1815 "build/hi_desktop/hi.y.cpp"
    break;

  case 35: // ENG_Num_Stem: t_ENG_Num_Stem
#line 348 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_Stem",word);

}
#line 1827 "build/hi_desktop/hi.y.cpp"
    break;

  case 36: // ENG_Num_lfea_Nom: t_ENG_Num_Nom
#line 357 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Nom);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_lfea_Nom",word);

}
#line 1839 "build/hi_desktop/hi.y.cpp"
    break;

  case 37: // ENG_Num_lfea_Ord: t_ENG_Num_Ord
#line 366 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Num_Ord);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Num_lfea_Ord",word);

}
#line 1851 "build/hi_desktop/hi.y.cpp"
    break;

  case 38: // ENG_PP: ENG_PREP ENG_NP
#line 375 "build/hi_desktop/hi.y"
{
const node_info& ENG_PREP=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PP->ENG_PREP ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_PP",ENG_PREP,ENG_NP);

}
#line 1863 "build/hi_desktop/hi.y.cpp"
    break;

  case 39: // ENG_PREP: ENG_PREP_Stem
#line 384 "build/hi_desktop/hi.y"
{
const node_info& ENG_PREP_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PREP->ENG_PREP_Stem");
yylhs.value=sparser->set_node_info("ENG_PREP",ENG_PREP_Stem);

}
#line 1874 "build/hi_desktop/hi.y.cpp"
    break;

  case 40: // ENG_PREP_Stem: t_ENG_PREP_Stem
#line 392 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PREP_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_PREP_Stem",word);

}
#line 1886 "build/hi_desktop/hi.y.cpp"
    break;

  case 41: // ENG_PRON_Stem: t_ENG_PRON_Stem
#line 401 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PRON_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_PRON_Stem",word);

}
#line 1898 "build/hi_desktop/hi.y.cpp"
    break;

  case 42: // ENG_PRON_lfea_wh: t_ENG_PRON_wh
#line 410 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_PRON_wh);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_PRON_lfea_wh",word);

}
#line 1910 "build/hi_desktop/hi.y.cpp"
    break;

  case 43: // ENG_PRON_qw: ENG_PRON_Stem ENG_PRON_lfea_wh
#line 419 "build/hi_desktop/hi.y"
{
const node_info& ENG_PRON_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PRON_lfea_wh=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_PRON_qw->ENG_PRON_Stem ENG_PRON_lfea_wh");
yylhs.value=sparser->combine_nodes("ENG_PRON_qw",ENG_PRON_Stem,ENG_PRON_lfea_wh);

}
#line 1922 "build/hi_desktop/hi.y.cpp"
    break;

  case 44: // ENG_Punct_ExclamationMark: t_ENG_Punct_ExclamationMark
#line 428 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_ExclamationMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Punct_ExclamationMark",word);

}
#line 1934 "build/hi_desktop/hi.y.cpp"
    break;

  case 45: // ENG_Punct_FullStop: t_ENG_Punct_FullStop
#line 437 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_FullStop);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Punct_FullStop",word);

}
#line 1946 "build/hi_desktop/hi.y.cpp"
    break;

  case 46: // ENG_Punct_Imp: ENG_Punct_Stem ENG_Punct_ExclamationMark
#line 446 "build/hi_desktop/hi.y"
{
const node_info& ENG_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Punct_ExclamationMark=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct_Imp->ENG_Punct_Stem ENG_Punct_ExclamationMark");
yylhs.value=sparser->combine_nodes("ENG_Punct_Imp",ENG_Punct_Stem,ENG_Punct_ExclamationMark);

}
#line 1958 "build/hi_desktop/hi.y.cpp"
    break;

  case 47: // ENG_Punct_Ind: ENG_Punct_Stem ENG_Punct_FullStop
#line 455 "build/hi_desktop/hi.y"
{
const node_info& ENG_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Punct_FullStop=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct_Ind->ENG_Punct_Stem ENG_Punct_FullStop");
yylhs.value=sparser->combine_nodes("ENG_Punct_Ind",ENG_Punct_Stem,ENG_Punct_FullStop);

}
#line 1970 "build/hi_desktop/hi.y.cpp"
    break;

  case 48: // ENG_Punct_Int: ENG_Punct_Stem ENG_Punct_QuestionMark
#line 464 "build/hi_desktop/hi.y"
{
const node_info& ENG_Punct_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_Punct_QuestionMark=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_Punct_Int->ENG_Punct_Stem ENG_Punct_QuestionMark");
yylhs.value=sparser->combine_nodes("ENG_Punct_Int",ENG_Punct_Stem,ENG_Punct_QuestionMark);

}
#line 1982 "build/hi_desktop/hi.y.cpp"
    break;

  case 49: // ENG_Punct_QuestionMark: t_ENG_Punct_QuestionMark
#line 473 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_QuestionMark);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Punct_QuestionMark",word);

}
#line 1994 "build/hi_desktop/hi.y.cpp"
    break;

  case 50: // ENG_Punct_Stem: t_ENG_Punct_Stem
#line 482 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_Punct_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_Punct_Stem",word);

}
#line 2006 "build/hi_desktop/hi.y.cpp"
    break;

  case 51: // ENG_V: ENG_V_Stem
#line 491 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem");
yylhs.value=sparser->set_node_info("ENG_V",ENG_V_Stem);

}
#line 2017 "build/hi_desktop/hi.y.cpp"
    break;

  case 52: // ENG_V: ENG_V_Stem ENG_V_lfea_3sg
#line 498 "build/hi_desktop/hi.y"
{
const node_info& ENG_V_Stem=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_3sg=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V->ENG_V_Stem ENG_V_lfea_3sg");
yylhs.value=sparser->combine_nodes("ENG_V",ENG_V_Stem,ENG_V_lfea_3sg);

}
#line 2029 "build/hi_desktop/hi.y.cpp"
    break;

  case 53: // ENG_VP_Imp: ENG_V ENG_DP
#line 507 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_DP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Imp->ENG_V ENG_DP");
yylhs.value=sparser->combine_nodes("ENG_VP_Imp",ENG_V,ENG_DP);

}
#line 2041 "build/hi_desktop/hi.y.cpp"
    break;

  case 54: // ENG_VP_Imp: ENG_Vbar1
#line 515 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Imp->ENG_Vbar1");
yylhs.value=sparser->set_node_info("ENG_VP_Imp",ENG_Vbar1);

}
#line 2052 "build/hi_desktop/hi.y.cpp"
    break;

  case 55: // ENG_VP_Imp: ENG_Vbar1 ENG_PP
#line 522 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar1=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_PP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Imp->ENG_Vbar1 ENG_PP");
yylhs.value=sparser->combine_nodes("ENG_VP_Imp",ENG_Vbar1,ENG_PP);

}
#line 2064 "build/hi_desktop/hi.y.cpp"
    break;

  case 56: // ENG_VP_Ind: ENG_Vbar2 ENG_NP
#line 531 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar2=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Ind->ENG_Vbar2 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_VP_Ind",ENG_Vbar2,ENG_NP);

}
#line 2076 "build/hi_desktop/hi.y.cpp"
    break;

  case 57: // ENG_VP_Int: ENG_Vbar3 ENG_NP
#line 540 "build/hi_desktop/hi.y"
{
const node_info& ENG_Vbar3=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_NP=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_VP_Int->ENG_Vbar3 ENG_NP");
yylhs.value=sparser->combine_nodes("ENG_VP_Int",ENG_Vbar3,ENG_NP);

}
#line 2088 "build/hi_desktop/hi.y.cpp"
    break;

  case 58: // ENG_V_Aux: ENG_V ENG_V_lfea_Aux
#line 549 "build/hi_desktop/hi.y"
{
const node_info& ENG_V=sparser->get_node_info(yystack_[1].value);
const node_info& ENG_V_lfea_Aux=sparser->get_node_info(yystack_[0].value);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,"ENG_V_Aux->ENG_V ENG_V_lfea_Aux");
yylhs.value=sparser->combine_nodes("ENG_V_Aux",ENG_V,ENG_V_lfea_Aux);

}
#line 2100 "build/hi_desktop/hi.y.cpp"
    break;

  case 59: // ENG_V_Stem: t_ENG_V_Stem
#line 558 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Stem);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_Stem",word);

}
#line 2112 "build/hi_desktop/hi.y.cpp"
    break;

  case 60: // ENG_V_lfea_3sg: t_ENG_V_3sg
#line 567 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_3sg);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_3sg",word);

}
#line 2124 "build/hi_desktop/hi.y.cpp"
    break;

  case 61: // ENG_V_lfea_Aux: t_ENG_V_Aux
#line 576 "build/hi_desktop/hi.y"
{
lexicon word;
word=lex->last_word_scanned(token::t_ENG_V_Aux);
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,word.gcat+"->"+word.lexeme);
yylhs.value=sparser->set_node_info("ENG_V_lfea_Aux",word);

}
#line 2136 "build/hi_desktop/hi.y.cpp"
    break;

  case 62: // ENG_Vbar1: ENG_V ENG_NP
#line 585 "build/hi_desktop/hi.y"
{
const node_info& main_node=sparser->get_node_info(yystack_[1].value);
const node_info& dependent_node=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(main_node,"main_verb");
std::string parent_symbol="ENG_Vbar1";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
yylhs.value=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
#line 2149 "build/hi_desktop/hi.y.cpp"
    break;

  case 63: // ENG_Vbar2: ENG_N_Sg ENG_V_Aux
#line 595 "build/hi_desktop/hi.y"
{
const node_info& main_node=sparser->get_node_info(yystack_[1].value);
const node_info& dependent_node=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(dependent_node,"V",std::string("main_verb"));
std::string parent_symbol="ENG_Vbar2";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
yylhs.value=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
#line 2162 "build/hi_desktop/hi.y.cpp"
    break;

  case 64: // ENG_Vbar3: ENG_PRON_qw ENG_V_Aux
#line 605 "build/hi_desktop/hi.y"
{
const node_info& main_node=sparser->get_node_info(yystack_[1].value);
const node_info& dependent_node=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(dependent_node,"main_verb");
sparser->add_feature_to_leaf(main_node,"PRON",std::string("qword"));
std::string parent_symbol="ENG_Vbar3";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
yylhs.value=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
#line 2176 "build/hi_desktop/hi.y.cpp"
    break;

  case 65: // S: ENG_VP_Imp ENG_Punct_Imp
#line 616 "build/hi_desktop/hi.y"
{
const node_info& main_node=sparser->get_node_info(yystack_[1].value);
const node_info& dependent_node=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(main_node,"main_verb","imperative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
yylhs.value=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
#line 2189 "build/hi_desktop/hi.y.cpp"
    break;

  case 66: // S: ENG_VP_Ind ENG_Punct_Ind
#line 625 "build/hi_desktop/hi.y"
{
const node_info& main_node=sparser->get_node_info(yystack_[1].value);
const node_info& dependent_node=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(main_node,"main_verb","indicative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
yylhs.value=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
#line 2202 "build/hi_desktop/hi.y.cpp"
    break;

  case 67: // S: ENG_VP_Int ENG_Punct_Int
#line 634 "build/hi_desktop/hi.y"
{
const node_info& main_node=sparser->get_node_info(yystack_[1].value);
const node_info& dependent_node=sparser->get_node_info(yystack_[0].value);
sparser->add_feature_to_leaf(main_node,"main_verb","interrogative",true);
std::string parent_symbol="S";
logger::singleton()==NULL?(void)0:logger::singleton()->log(0,parent_symbol+"->"+main_node.symbol+" "+dependent_node.symbol);
yylhs.value=sparser->combine_nodes(parent_symbol,main_node,dependent_node);
}
#line 2215 "build/hi_desktop/hi.y.cpp"
    break;


#line 2219 "build/hi_desktop/hi.y.cpp"

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


  const signed char parser::yypact_ninf_ = -18;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       1,   -18,   -18,   -18,   -18,   -18,   -18,    33,    38,    36,
      33,     4,   -15,   -15,   -15,    35,    40,     2,     2,    51,
      37,   -18,   -18,   -18,   -18,   -18,   -18,   -18,    49,     2,
      -1,   -18,   -18,   -18,   -18,   -18,     8,   -18,   -18,    23,
     -18,    26,   -18,    27,   -18,   -18,   -18,   -18,     2,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,    53,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
      10,   -18,   -18,    18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     3,    19,    41,    59,    17,     2,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    54,     0,     0,     0,
       0,    63,    21,    18,    42,    43,    64,     8,     2,     0,
       0,    53,    15,    62,    12,    13,     0,    50,    65,     0,
      66,     0,    67,     0,    60,    52,    40,    55,     0,    39,
      56,    57,     1,    61,    58,     6,     5,     0,    14,    35,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     9,
       0,    10,    11,     0,    23,    20,    16,    44,    46,    45,
      47,    49,    48,    38,     7,     4,    36,    37,    24,    25,
      22
  };

  const signed char
  parser::yypgoto_[] =
  {
     -18,   -18,     3,   -18,   -18,   -18,   -18,   -18,   -18,     0,
     -17,   -18,    56,    59,   -18,   -18,   -13,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,    22,    61,   -18,   -18,   -18,
      52,   -18,   -18,   -18,   -18,   -18,   -18,   -18
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     5,    28,    56,    29,    57,    85,    30,    31,    32,
      33,    34,    35,    36,    76,    23,    70,    71,    72,    73,
      74,    88,    89,    47,    48,    49,     9,    25,    10,    78,
      80,    38,    40,    42,    82,    39,    20,    12,    13,    14,
      21,    15,    45,    54,    16,    17,    18,    19
  };

  const signed char
  parser::yytable_[] =
  {
      50,    51,     1,     6,     1,     1,     2,     1,     2,     2,
      27,     2,     3,    37,     4,    59,    75,    22,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    86,    87,    58,
      69,    83,     6,     6,    59,    41,    43,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     4,    22,    24,    44,
      46,    52,    53,    55,    77,    79,     7,    81,    84,     8,
      90,    11,    26
  };

  const signed char
  parser::yycheck_[] =
  {
      17,    18,     3,     0,     3,     3,     7,     3,     7,     7,
       6,     7,    11,    28,    13,    16,     8,     9,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    17,    18,    29,
      30,    48,    29,    30,    16,    13,    14,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    13,     9,    12,    14,
      10,     0,    15,     4,    31,    29,     0,    30,     5,     0,
      73,     0,    10
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     7,    11,    13,    33,    34,    44,    45,    58,
      60,    68,    69,    70,    71,    73,    76,    77,    78,    79,
      68,    72,     9,    47,    12,    59,    72,     6,    34,    36,
      39,    40,    41,    42,    43,    44,    45,    28,    63,    67,
      64,    67,    65,    67,    14,    74,    10,    55,    56,    57,
      42,    42,     0,    15,    75,     4,    35,    37,    41,    16,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    41,
      48,    49,    50,    51,    52,     8,    46,    31,    61,    29,
      62,    30,    66,    42,     5,    38,    17,    18,    53,    54,
      48
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      40,    40,    41,    41,    42,    42,    43,    44,    44,    45,
      46,    47,    48,    48,    49,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    68,    69,    69,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    79,    79
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     1,     1,     1,     2,
       2,     2,     1,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     2,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     2,     2,     2,     2,     2,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "t_ENG_CON_Stem", "t_ENG_CON_3sg",
  "t_ENG_CON_GEN", "t_ENG_DET_Stem", "t_ENG_N_Stem", "t_ENG_N_Pl",
  "t_ENG_N_Sg", "t_ENG_PREP_Stem", "t_ENG_PRON_Stem", "t_ENG_PRON_wh",
  "t_ENG_V_Stem", "t_ENG_V_3sg", "t_ENG_V_Aux", "t_ENG_Num_Stem",
  "t_ENG_Num_Nom", "t_ENG_Num_Ord", "t_ENG_Num_Npref1n",
  "t_ENG_Num_Npref2n", "t_ENG_Num_Npref3n", "t_ENG_Num_Npref4n",
  "t_ENG_Num_Npref5n", "t_ENG_Num_Npref6n", "t_ENG_Num_Npref7n",
  "t_ENG_Num_Npref8n", "t_ENG_Num_Npref9n", "t_ENG_Punct_Stem",
  "t_ENG_Punct_FullStop", "t_ENG_Punct_QuestionMark",
  "t_ENG_Punct_ExclamationMark", "$accept", "ENG_1CON", "ENG_CON",
  "ENG_CON_3sgGEN", "ENG_CON_GEN", "ENG_CON_lfea_3sg", "ENG_CON_lfea_GEN",
  "ENG_DET_Stem", "ENG_DP", "ENG_N", "ENG_NP", "ENG_N_Pl", "ENG_N_Sg",
  "ENG_N_Stem", "ENG_N_lfea_Pl", "ENG_N_lfea_Sg", "ENG_Num", "ENG_Num_Nom",
  "ENG_Num_Ord", "ENG_Num_Pref", "ENG_Num_Stem", "ENG_Num_lfea_Nom",
  "ENG_Num_lfea_Ord", "ENG_PP", "ENG_PREP", "ENG_PREP_Stem",
  "ENG_PRON_Stem", "ENG_PRON_lfea_wh", "ENG_PRON_qw",
  "ENG_Punct_ExclamationMark", "ENG_Punct_FullStop", "ENG_Punct_Imp",
  "ENG_Punct_Ind", "ENG_Punct_Int", "ENG_Punct_QuestionMark",
  "ENG_Punct_Stem", "ENG_V", "ENG_VP_Imp", "ENG_VP_Ind", "ENG_VP_Int",
  "ENG_V_Aux", "ENG_V_Stem", "ENG_V_lfea_3sg", "ENG_V_lfea_Aux",
  "ENG_Vbar1", "ENG_Vbar2", "ENG_Vbar3", "S", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    69,    69,    77,    86,    95,   104,   113,   122,   131,
     139,   147,   156,   163,   171,   180,   188,   197,   204,   213,
     222,   231,   240,   248,   256,   265,   274,   282,   290,   298,
     306,   314,   322,   330,   338,   347,   356,   365,   374,   383,
     391,   400,   409,   418,   427,   436,   445,   454,   463,   472,
     481,   490,   497,   506,   514,   521,   530,   539,   548,   557,
     566,   575,   584,   594,   604,   615,   624,   633
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
      25,    26,    27,    28,    29,    30,    31
    };
    // Last valid token kind.
    const int code_max = 286;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 2807 "build/hi_desktop/hi.y.cpp"

#line 642 "build/hi_desktop/hi.y"

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

    std::string analyses,modified_human_input;
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
            if(modified_human_input.empty()==true){
                lex=new lexer(human_input,language,locale,false,token_paths);
            }
            else{
                lex=new lexer(modified_human_input.c_str(),language,locale,false,token_paths);
            }
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
                if(crh>0&&modified_human_input.empty()==true){
                    modified_human_input=token_paths->add_context_reference_word(crh);
                }
                while(lex->is_end_of_input()==false){//go through the input simulating what bison does as well but w/o syntactic analysis
                    lex->next_token();
                }
                sparser->build_dependency_semantics(lex,token_paths);
                //sparser->build_dependency_semantics(toa,crh,language,lex,token_paths);
                delete sparser;
                sparser=NULL;
                transgraph=NULL;
                //delete lex;
                //lex=NULL;
                //break;
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
