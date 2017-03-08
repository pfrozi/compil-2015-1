/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include "cc_misc.h"
#include "cc_dict.h"
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_list.h"
#include "main.h"
extern comp_tree_t* ast;

#line 77 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_HOME_PEDRO_DOCUMENTS_UFRGS_TRABCOMPILADORES_COMPIL_2015_1_BUILD_PARSER_H_INCLUDED
# define YY_YY_HOME_PEDRO_DOCUMENTS_UFRGS_TRABCOMPILADORES_COMPIL_2015_1_BUILD_PARSER_H_INCLUDED
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
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_STATIC = 271,
    TK_PR_CONST = 272,
    TK_CE_COMMA = 273,
    TK_CE_SEMICOLON = 274,
    TK_CE_COLON = 275,
    TK_CE_PAR_OPEN = 276,
    TK_CE_PAR_CLOSE = 277,
    TK_CE_BRA_OPEN = 278,
    TK_CE_BRA_CLOSE = 279,
    TK_CE_BRA_CURL_OPEN = 280,
    TK_CE_BRA_CURL_CLOSE = 281,
    TK_CE_PLUS = 282,
    TK_CE_MINUS = 283,
    TK_CE_MUL = 284,
    TK_CE_DIV = 285,
    TK_CE_BRA_ANGL_OPEN = 286,
    TK_CE_BRA_ANGL_CLOSE = 287,
    TK_CE_EQUAL = 288,
    TK_CE_EXCL = 289,
    TK_CE_AMP = 290,
    TK_CE_EG = 291,
    TK_CE_DOLLAR = 292,
    TK_OC_LE = 293,
    TK_OC_GE = 294,
    TK_OC_EQ = 295,
    TK_OC_NE = 296,
    TK_OC_AND = 297,
    TK_OC_OR = 298,
    TK_OC_GT = 299,
    TK_OC_LT = 300,
    TK_OC_NEG = 301,
    TK_LIT_INT = 302,
    TK_LIT_FLOAT = 303,
    TK_LIT_FALSE = 304,
    TK_LIT_TRUE = 305,
    TK_LIT_CHAR = 306,
    TK_LIT_STRING = 307,
    TK_IDENTIFICADOR = 308,
    TOKEN_ERRO = 309,
    TOKEN_EOF = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "parser.y" /* yacc.c:355  */

    comp_dict_item_t *valor_simbolo_lexico;
    comp_tree_t      *ast;
    comp_list_t      *arguments;
    comp_list_t      *integer_list;
    int              integer;

#line 181 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_PEDRO_DOCUMENTS_UFRGS_TRABCOMPILADORES_COMPIL_2015_1_BUILD_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:358  */

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   343

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   109,   110,   111,   115,   119,   122,   126,
     127,   128,   129,   133,   140,   147,   154,   163,   170,   177,
     178,   182,   183,   184,   185,   186,   187,   188,   189,   192,
     193,   194,   195,   196,   197,   200,   201,   205,   206,   207,
     208,   209,   210,   211,   214,   215,   216,   217,   218,   221,
     222,   226,   237,   238,   239,   240,   241,   242,   243,   246,
     247,   250,   251,   254,   263,   273,   278,   287,   288,   292,
     293,   298,   299,   300,   305,   306,   307,   308,   321,   322,
     326,   327,   331,   335,   339,   343,   344,   345,   348,   349,
     350,   351,   354,   355,   356,   357,   358,   359,   363,   364,
     365,   368,   368,   371,   372,   373,   374,   378,   379,   380,
     381,   384,   391,   398,   405,   412,   413,   414,   415,   416,
     417,   422,   423,   432,   433,   438,   439,   440,   444,   445,
     450,   451,   456,   457,   462,   464,   465,   466,   469,   470,
     474,   475
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_PR_STATIC", "TK_PR_CONST", "TK_CE_COMMA", "TK_CE_SEMICOLON",
  "TK_CE_COLON", "TK_CE_PAR_OPEN", "TK_CE_PAR_CLOSE", "TK_CE_BRA_OPEN",
  "TK_CE_BRA_CLOSE", "TK_CE_BRA_CURL_OPEN", "TK_CE_BRA_CURL_CLOSE",
  "TK_CE_PLUS", "TK_CE_MINUS", "TK_CE_MUL", "TK_CE_DIV",
  "TK_CE_BRA_ANGL_OPEN", "TK_CE_BRA_ANGL_CLOSE", "TK_CE_EQUAL",
  "TK_CE_EXCL", "TK_CE_AMP", "TK_CE_EG", "TK_CE_DOLLAR", "TK_OC_LE",
  "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_OC_GT",
  "TK_OC_LT", "TK_OC_NEG", "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE",
  "TK_LIT_TRUE", "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR",
  "TOKEN_ERRO", "TOKEN_EOF", "$accept", "programa", "input", "global_line",
  "line", "endline", "global_statement", "array", "array_int",
  "statement_array", "statement", "local_statement", "const_statement",
  "literal", "op_literal", "type", "exp", "val_exp", "exp_bool",
  "exp_bool_ou", "exp_bool_e", "exp_art", "exp_art_t", "exp_art_par",
  "exp_neg", "exp_end", "lst_exp", "lst_int", "command_block",
  "init_scope", "close_scope", "command", "command2", "single_command",
  "flow_command", "function", "$@1", "func_head", "func_head_params",
  "func_params", "assignment", "in", "out", "ret", "func_call", "cond",
  "whiledo", "dowhile", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,  -115,  -115,  -115,  -115,  -115,   155,   100,    15,   -28,
      26,    26,  -115,    19,     2,    -5,  -115,    24,  -115,    -1,
      51,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    17,
    -115,  -115,    96,  -115,  -115,  -115,    96,   167,  -115,    44,
     -14,    47,    48,    81,  -115,  -115,    95,  -115,  -115,    97,
      70,    71,    71,   109,  -115,    17,  -115,    92,   118,    95,
     165,   249,   249,   127,   172,    30,  -115,   105,  -115,   113,
     102,  -115,    95,   130,    19,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,    71,   135,  -115,  -115,    71,
    -115,   200,   208,   152,   257,    88,    34,   249,    34,  -115,
    -115,  -115,  -115,  -115,  -115,     1,  -115,   129,  -115,   150,
     144,   156,   114,   117,  -115,  -115,  -115,  -115,   191,  -115,
    -115,   178,   157,  -115,   166,   216,   249,   249,   190,   264,
     282,  -115,   130,  -115,  -115,    95,  -115,    71,  -115,   215,
      14,   214,   210,   249,   298,  -115,  -115,  -115,  -115,  -115,
    -115,   249,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   249,  -115,   180,  -115,  -115,  -115,
     212,   217,  -115,   249,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,    95,    95,   230,    95,   228,  -115,  -115,
    -115,   144,   144,   144,   144,   144,   144,   156,   114,   117,
     117,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
      95,  -115,    95,   232,  -115,    95,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    44,    45,    46,    47,    48,     0,    20,     0,     0,
       3,     3,     6,     0,    11,     0,     7,     0,    19,     0,
     110,   109,   106,     1,     2,     5,     4,     8,     9,     0,
      10,    12,    18,   105,    83,   101,    17,     0,   107,   117,
     119,     0,    81,     0,    16,   104,    85,    15,   103,   118,
       0,     0,     0,   113,   108,     0,    14,     0,     0,     0,
       0,   129,   131,     0,     0,    20,    91,    26,    93,    25,
       0,    89,    85,     0,    87,    88,    90,    97,    94,    95,
      96,    92,    98,    99,   100,     0,   114,   115,   120,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,    50,    76,    75,     0,    49,    51,
      58,    60,    62,    65,    68,    70,    73,    74,    79,   128,
     130,     0,     0,    33,    34,     0,     0,   123,     0,    28,
      27,    18,     0,    84,   102,    85,   116,     0,   111,     0,
       0,     0,     0,   141,     0,    42,    43,    71,   126,    72,
      77,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    31,    17,    32,   132,
       0,     0,   121,   124,    36,    23,    24,    35,    21,    22,
      82,    86,   112,     0,     0,     0,     0,     0,   140,    69,
     125,    54,    55,    56,    57,    53,    52,    59,    61,    63,
      64,    66,    67,    78,    29,   133,    13,   122,   136,   137,
       0,   139,     0,   134,   138,     0,   135
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,   139,  -115,  -115,    -7,  -115,   140,    60,  -115,
      80,  -115,  -115,   141,    38,     8,   -57,  -115,   179,    50,
     116,   120,    36,    37,  -115,   -52,  -114,   220,  -115,   255,
     148,   -70,   -58,  -115,  -115,  -115,  -115,  -115,     5,   -42,
    -115,  -115,  -115,  -115,   -46,  -115,  -115,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    66,    12,   128,    31,    13,
      67,    68,    69,   176,   106,    70,   118,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   119,    43,    71,    72,
     134,    73,    74,    75,    76,    16,    46,    17,    22,    41,
      77,    78,    79,    80,   117,    82,    83,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      81,    93,   132,   107,    52,   120,    28,    30,    15,    87,
      88,   170,   171,    81,    19,    23,    20,    21,    15,    15,
      33,    27,   125,   184,   126,    29,    81,    24,    40,     1,
       2,     3,     4,     5,   140,   142,   185,    45,    27,    53,
     148,    48,     6,   136,   147,    50,   149,   138,    32,    34,
     203,   125,    36,   126,     1,     2,     3,     4,     5,    40,
      40,    95,    51,   127,    42,   181,    55,   135,    37,    54,
     172,   122,   124,    38,     1,     2,     3,     4,     5,     7,
      14,    99,   100,   101,   102,   103,   188,   105,    37,    81,
      14,    14,    44,    40,   190,   182,    47,    40,     1,     2,
       3,     4,     5,    57,    39,    56,    58,    59,    60,    61,
      62,    63,    64,    91,    27,    85,   207,    20,    21,    29,
      34,    20,    21,    86,    39,   208,   209,    89,   211,   166,
       1,     2,     3,     4,     5,   145,   146,    81,    81,    92,
      81,   160,   161,   129,   121,    40,   162,   163,    65,    25,
      26,   130,   213,   137,   214,   131,   133,   216,     1,     2,
       3,     4,     5,   143,    81,   151,    81,   177,   177,    81,
       1,     2,     3,     4,     5,     1,     2,     3,     4,     5,
      18,     1,     2,     3,     4,     5,    94,   158,   152,   153,
     154,   155,    95,    96,   156,   157,   199,   200,   159,   201,
     202,    97,   191,   192,   193,   194,   195,   196,    18,   164,
     167,    98,    99,   100,   101,   102,   103,   104,   105,   168,
      49,    94,   139,   173,   183,   123,   186,    95,    96,    94,
     141,   165,   187,   204,   205,    95,    96,    94,   169,   210,
     212,   206,   215,    95,    96,   150,    98,    99,   100,   101,
     102,   103,   104,   105,    98,    99,   100,   101,   102,   103,
     104,   105,    98,    99,   100,   101,   102,   103,   104,   105,
      94,   179,    35,   144,   197,    90,    95,    96,    94,   198,
     180,     0,     0,     0,    95,    96,     0,     0,     0,     0,
       0,    95,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,    98,    99,   100,   101,   102,   103,    95,
     105,    99,   100,   101,   102,   103,   174,   175,     0,     0,
     189,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   174,   178,   152,   153,   154,   155,
       0,     0,   156,   157
};

static const yytype_int16 yycheck[] =
{
      46,    59,    72,    60,    18,    62,    13,    14,     0,    51,
      52,   125,   126,    59,     6,     0,    21,    22,    10,    11,
      15,    19,    21,     9,    23,    23,    72,    55,    20,     3,
       4,     5,     6,     7,    91,    92,    22,    32,    19,    53,
      97,    36,    16,    85,    96,    37,    98,    89,    53,    25,
     164,    21,    53,    23,     3,     4,     5,     6,     7,    51,
      52,    27,    18,    33,    47,   135,    18,    74,    17,    22,
     127,    63,    64,    22,     3,     4,     5,     6,     7,    53,
       0,    47,    48,    49,    50,    51,   143,    53,    17,   135,
      10,    11,    32,    85,   151,   137,    36,    89,     3,     4,
       5,     6,     7,     8,    53,    24,    11,    12,    13,    14,
      15,    16,    17,    21,    19,    18,   173,    21,    22,    23,
      25,    21,    22,    53,    53,   183,   184,    18,   186,   121,
       3,     4,     5,     6,     7,    47,    48,   183,   184,    21,
     186,    27,    28,    38,    17,   137,    29,    30,    53,    10,
      11,    38,   210,    18,   212,    53,    26,   215,     3,     4,
       5,     6,     7,    11,   210,    36,   212,   129,   130,   215,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      53,     3,     4,     5,     6,     7,    21,    43,    38,    39,
      40,    41,    27,    28,    44,    45,   160,   161,    42,   162,
     163,    36,   152,   153,   154,   155,   156,   157,    53,    18,
      53,    46,    47,    48,    49,    50,    51,    52,    53,    53,
      53,    21,    22,    33,     9,    53,    12,    27,    28,    21,
      22,    53,    22,    53,    22,    27,    28,    21,    22,     9,
      12,    24,    10,    27,    28,   105,    46,    47,    48,    49,
      50,    51,    52,    53,    46,    47,    48,    49,    50,    51,
      52,    53,    46,    47,    48,    49,    50,    51,    52,    53,
      21,   130,    17,    94,   158,    55,    27,    28,    21,   159,
     132,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    46,    47,    48,    49,    50,    51,    27,
      53,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    38,    39,    40,    41,
      -1,    -1,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    16,    53,    57,    58,
      59,    60,    62,    65,    66,    71,    91,    93,    53,    71,
      21,    22,    94,     0,    55,    58,    58,    19,    61,    23,
      61,    64,    53,    94,    25,    85,    53,    17,    22,    53,
      71,    95,    47,    83,    64,    94,    92,    64,    94,    53,
      71,    18,    18,    53,    22,    18,    24,     8,    11,    12,
      13,    14,    15,    16,    17,    53,    61,    66,    67,    68,
      71,    84,    85,    87,    88,    89,    90,    96,    97,    98,
      99,   100,   101,   102,   103,    18,    53,    95,    95,    18,
      83,    21,    21,    88,    21,    27,    28,    36,    46,    47,
      48,    49,    50,    51,    52,    53,    70,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   100,    72,    82,
      72,    17,    71,    53,    71,    21,    23,    33,    63,    38,
      38,    53,    87,    26,    86,    61,    95,    18,    95,    22,
      72,    22,    72,    11,    74,    47,    48,    81,    72,    81,
      63,    36,    38,    39,    40,    41,    44,    45,    43,    42,
      27,    28,    29,    30,    18,    53,    71,    53,    53,    22,
      82,    82,    72,    33,    52,    53,    69,    70,    53,    69,
      86,    87,    95,     9,     9,    22,    12,    22,    72,    22,
      72,    75,    75,    75,    75,    75,    75,    76,    77,    78,
      78,    79,    79,    82,    53,    22,    24,    72,    88,    88,
       9,    88,    12,    88,    88,    10,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    59,    60,    61,    62,
      62,    62,    62,    63,    64,    65,    65,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    71,    71,    71,    72,
      72,    73,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    78,    78,    78,    79,
      79,    80,    80,    80,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    85,    86,    87,    87,    87,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    90,    90,
      90,    92,    91,    93,    93,    93,    93,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   101,   101,   102,   102,
     103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     1,     1,     1,     2,
       2,     1,     2,     3,     3,     4,     3,     3,     2,     2,
       1,     3,     3,     3,     3,     1,     1,     2,     2,     4,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     2,     2,     1,     1,     1,     1,     2,     3,     1,
       3,     1,     3,     1,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     4,     3,     2,     2,     2,     3,     1,
       1,     4,     5,     2,     3,     3,     4,     1,     2,     1,
       3,     3,     4,     2,     3,     4,     3,     3,     2,     1,
       2,     1,     3,     4,     6,     8,     5,     5,     6,     5,
       4,     3
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
#line 99 "parser.y" /* yacc.c:1646  */
    {
                              (yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_PROGRAMA,NULL)),(yyvsp[-1].ast)); 
                              ast=(yyval.ast); 
                              tree_pass_gen_labels(ast,NULL); 
                              tree_pass_code(ast); 
                              print_iloc_code(ast); 
                              return SINTATICA_SUCESSO; 
                          }
#line 1480 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1486 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node((yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1492 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1498 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "parser.y" /* yacc.c:1646  */
    {}
#line 1504 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast); fun_reset((yyval.ast),1); }
#line 1510 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a ;"); return SINTATICA_ERRO; }
#line 1516 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a ;"); return SINTATICA_ERRO; }
#line 1522 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "parser.y" /* yacc.c:1646  */
    {
                                                      if((yyvsp[-1].ast)->item->iks_type==IKS_CHAR) return IKS_ERROR_CHAR_TO_X;
                                                      if((yyvsp[-1].ast)->item->iks_type==IKS_STRING) return IKS_ERROR_STRING_TO_X; 
                                                      (yyval.ast) = (yyvsp[-1].ast);
                                                  }
#line 1532 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 140 "parser.y" /* yacc.c:1646  */
    {
                                                      //if($2->item->iks_type==IKS_CHAR) return IKS_ERROR_CHAR_TO_X;
                                                      //if($2->item->iks_type==IKS_STRING) return IKS_ERROR_STRING_TO_X; 
                                                      (yyval.integer_list) = (yyvsp[-1].integer_list);
                                                  }
#line 1542 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 147 "parser.y" /* yacc.c:1646  */
    { 
                                                                if(yystack_find_top((yyvsp[-1].valor_simbolo_lexico))!=NULL) 
                                                                    return IKS_ERROR_DECLARED; 
                                                                else 
                                                                    yystack_add_array((yyvsp[-1].valor_simbolo_lexico), (yyvsp[-2].integer), IKS_ARRAY, (yyvsp[0].integer_list)); 
                                                                (yyval.valor_simbolo_lexico) = (yyvsp[-1].valor_simbolo_lexico); 
                                                            }
#line 1554 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 154 "parser.y" /* yacc.c:1646  */
    { 
                                                                if(yystack_find_top((yyvsp[-1].valor_simbolo_lexico))!=NULL) 
                                                                    return IKS_ERROR_DECLARED; 
                                                                else 
                                                                    yystack_add_array((yyvsp[-1].valor_simbolo_lexico), (yyvsp[-2].integer), IKS_ARRAY, (yyvsp[0].integer_list)); 
                                                                (yyval.valor_simbolo_lexico) = (yyvsp[-1].valor_simbolo_lexico); 
                                                            }
#line 1566 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "parser.y" /* yacc.c:1646  */
    { 
                                                        if(yystack_find_top((yyvsp[0].valor_simbolo_lexico))!=NULL) 
                                                            return IKS_ERROR_DECLARED; 
                                                        else 
                                                            yystack_add((yyvsp[0].valor_simbolo_lexico), (yyvsp[-1].integer), IKS_VARIABLE); 
                                                        (yyval.valor_simbolo_lexico) = (yyvsp[0].valor_simbolo_lexico); 
                                                    }
#line 1578 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 170 "parser.y" /* yacc.c:1646  */
    { 
                                                        if(yystack_find_top((yyvsp[0].valor_simbolo_lexico))!=NULL) 
                                                            return IKS_ERROR_DECLARED; 
                                                        else 
                                                            yystack_add((yyvsp[0].valor_simbolo_lexico), (yyvsp[-1].integer), IKS_VARIABLE); 
                                                        (yyval.valor_simbolo_lexico) = (yyvsp[0].valor_simbolo_lexico); 
                                                    }
#line 1590 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 177 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a type"); return SINTATICA_ERRO; }
#line 1596 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 178 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a type"); return SINTATICA_ERRO; }
#line 1602 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 182 "parser.y" /* yacc.c:1646  */
    {  }
#line 1608 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 184 "parser.y" /* yacc.c:1646  */
    {  }
#line 1614 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 188 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a attrib"); return SINTATICA_ERRO; }
#line 1620 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 189 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a attrib"); return SINTATICA_ERRO; }
#line 1626 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 192 "parser.y" /* yacc.c:1646  */
    { if(yystack_find_top((yyvsp[0].valor_simbolo_lexico))!=NULL) return IKS_ERROR_DECLARED; else yystack_add((yyvsp[0].valor_simbolo_lexico), (yyvsp[-1].integer), IKS_VARIABLE); (yyval.valor_simbolo_lexico) = (yyvsp[0].valor_simbolo_lexico); }
#line 1632 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 193 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a type"); return SINTATICA_ERRO; }
#line 1638 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 194 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a IDENTIFICADOR"); return SINTATICA_ERRO; }
#line 1644 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 195 "parser.y" /* yacc.c:1646  */
    { if(yystack_find_top((yyvsp[0].valor_simbolo_lexico))!=NULL) return IKS_ERROR_DECLARED; else yystack_add((yyvsp[0].valor_simbolo_lexico),(yyvsp[-1].integer), IKS_VARIABLE); (yyval.valor_simbolo_lexico) = (yyvsp[0].valor_simbolo_lexico); }
#line 1650 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 196 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a type"); return SINTATICA_ERRO; }
#line 1656 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 197 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a IDENTIFICADOR"); return SINTATICA_ERRO; }
#line 1662 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1668 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,(yyvsp[0].valor_simbolo_lexico)));}
#line 1674 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_INT,(yyvsp[0].valor_simbolo_lexico))),NULL);}
#line 1680 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_FLOAT,(yyvsp[0].valor_simbolo_lexico))),NULL);}
#line 1686 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_BOOL,(yyvsp[0].valor_simbolo_lexico))),NULL);}
#line 1692 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_BOOL,(yyvsp[0].valor_simbolo_lexico))),NULL);}
#line 1698 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_CHAR,(yyvsp[0].valor_simbolo_lexico))),NULL);}
#line 1704 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_INT,(yyvsp[0].valor_simbolo_lexico))),NULL);}
#line 1710 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_FLOAT,(yyvsp[0].valor_simbolo_lexico))),NULL);}
#line 1716 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.integer) = IKS_INT; }
#line 1722 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.integer) = IKS_FLOAT; }
#line 1728 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.integer) = IKS_BOOL; }
#line 1734 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.integer) = IKS_CHAR; }
#line 1740 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.integer) = IKS_STRING; }
#line 1746 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 221 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1752 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 222 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_STRING,(yyvsp[0].valor_simbolo_lexico))),NULL);}
#line 1758 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1764 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 237 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_L,yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item), NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1770 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 238 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_G,yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item), NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1776 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 239 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_LE,yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item), NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1782 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 240 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_GE,yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item), NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1788 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 241 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_IGUAL,yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item), NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1794 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 242 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_DIF, yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item),NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1800 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1806 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 246 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_OU,yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item), NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1812 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1818 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 250 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_E,yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item), NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1824 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1830 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 254 "parser.y" /* yacc.c:1646  */
    { 
                                            if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) 
                                                return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); 
                                            (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2
                                                                                       , cc_tree_item_create_type(AST_ARIM_SOMA
                                                                                                                 , yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item)
                                                                                                                 , NULL))
                                                                                       , (yyvsp[-2].ast)), (yyvsp[0].ast)); 
                                        }
#line 1844 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 263 "parser.y" /* yacc.c:1646  */
    { 
                                            if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) 
                                                return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); 
                                            
                                            (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2
                                                                                       , cc_tree_item_create_type(AST_ARIM_SUBTRACAO
                                                                                                                , yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item)
                                                                                                                , NULL))
                                                                                       , (yyvsp[-2].ast)), (yyvsp[0].ast)); 
                                        }
#line 1859 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 273 "parser.y" /* yacc.c:1646  */
    { 
                                            (yyval.ast) = (yyvsp[0].ast); 
                                        }
#line 1867 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 278 "parser.y" /* yacc.c:1646  */
    { 
                                              if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) 
                                                  return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); 
                                              (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2
                                                                                          ,cc_tree_item_create_type(AST_ARIM_MULTIPLICACAO
                                                                                                                  , yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item)
                                                                                                                  , NULL))
                                                                                          , (yyvsp[-2].ast)), (yyvsp[0].ast)); 
                                          }
#line 1881 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 287 "parser.y" /* yacc.c:1646  */
    { if(yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].ast)->item->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_ARIM_DIVISAO, yystack_inf((yyvsp[-2].ast)->item, (yyvsp[0].ast)->item), NULL)), (yyvsp[-2].ast)), (yyvsp[0].ast)); }
#line 1887 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1893 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1899 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1905 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_ARIM_INVERSAO, (yyvsp[0].ast)->item->iks_type,NULL)),(yyvsp[0].ast)); }
#line 1911 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LOGICO_COMP_NEGACAO, (yyvsp[0].ast)->item->iks_type,NULL)),(yyvsp[0].ast)); }
#line 1917 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 1923 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1929 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1935 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 307 "parser.y" /* yacc.c:1646  */
    { if(yystack_find((yyvsp[0].valor_simbolo_lexico))==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find((yyvsp[0].valor_simbolo_lexico))->iks_var!=IKS_VARIABLE) return yyerror_var((yyvsp[0].valor_simbolo_lexico)); (yyval.ast) = cc_tree_create_node(1,cc_tree_item_create_type(AST_IDENTIFICADOR,(yyvsp[0].valor_simbolo_lexico)->iks_type,(yyvsp[0].valor_simbolo_lexico))); }
#line 1941 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 308 "parser.y" /* yacc.c:1646  */
    { 
                                                    if(yystack_find((yyvsp[-1].valor_simbolo_lexico))==NULL) return IKS_ERROR_UNDECLARED; 
                                                    if(yystack_find((yyvsp[-1].valor_simbolo_lexico))->iks_var!=IKS_ARRAY) return yyerror_var((yyvsp[-1].valor_simbolo_lexico)); 
                                                    (yyval.ast) = cc_tree_insert_node(
                                                            cc_tree_insert_node(
                                                                cc_tree_create_node(2
                                                                                    , cc_tree_item_create_type(AST_VETOR_INDEXADO, (yyvsp[-1].valor_simbolo_lexico)->iks_type,NULL))
                                                                                    , cc_tree_create_node(1,cc_tree_item_create_type(AST_IDENTIFICADOR,(yyvsp[-1].valor_simbolo_lexico)->iks_type,(yyvsp[-1].valor_simbolo_lexico))))
                                                                ,(yyvsp[0].ast));
                                                 }
#line 1956 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = cc_tree_insert_node((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1962 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 322 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1968 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 326 "parser.y" /* yacc.c:1646  */
    { (yyval.integer_list) = cc_list_append((yyvsp[0].integer_list), cc_list_create((yyvsp[-2].valor_simbolo_lexico)->val_int)); }
#line 1974 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval.integer_list) = cc_list_create((yyvsp[0].valor_simbolo_lexico)->val_int); }
#line 1980 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 331 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_BLOCO,NULL)),(yyvsp[-1].ast));}
#line 1986 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 335 "parser.y" /* yacc.c:1646  */
    { yystack_push_scope(); }
#line 1992 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 339 "parser.y" /* yacc.c:1646  */
    { yystack_pop_scope(); }
#line 1998 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 343 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 2004 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 344 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2].ast)!=NULL){(yyval.ast) = cc_tree_insert_node((yyvsp[-2].ast),(yyvsp[0].ast));} else{(yyval.ast)=(yyvsp[0].ast);};}
#line 2010 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 345 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].ast)!=NULL){(yyval.ast) = (yyvsp[0].ast);}else{(yyval.ast)=NULL;}}
#line 2016 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 348 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2022 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 349 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2028 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 350 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2034 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 351 "parser.y" /* yacc.c:1646  */
    {}
#line 2040 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2046 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 355 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL;}
#line 2052 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 356 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2058 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 357 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2064 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 358 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2070 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 359 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2076 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 363 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2082 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 364 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2088 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 365 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);}
#line 2094 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 368 "parser.y" /* yacc.c:1646  */
    {yystack_set_type((yyvsp[-1].ast));}
#line 2100 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 368 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = cc_tree_insert_node((yyvsp[-4].ast),(yyvsp[-1].ast));}
#line 2106 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 371 "parser.y" /* yacc.c:1646  */
    { if(yystack_find_top((yyvsp[-1].valor_simbolo_lexico))!=NULL) return IKS_ERROR_DECLARED; else yystack_add((yyvsp[-1].valor_simbolo_lexico), (yyvsp[-2].integer), IKS_FUNCTION); (yyval.ast) = cc_tree_create_node(3,cc_tree_item_create_type(AST_FUNCAO,(yyvsp[-2].integer),(yyvsp[-1].valor_simbolo_lexico))); (yyval.ast)->item->sentry->iks_arguments=(yyvsp[0].arguments);}
#line 2112 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 372 "parser.y" /* yacc.c:1646  */
    { if(yystack_find_top((yyvsp[-1].valor_simbolo_lexico))!=NULL) return IKS_ERROR_DECLARED; else yystack_add((yyvsp[-1].valor_simbolo_lexico), (yyvsp[-2].integer), IKS_FUNCTION); (yyval.ast) = cc_tree_create_node(3,cc_tree_item_create_type(AST_FUNCAO,(yyvsp[-2].integer),(yyvsp[-1].valor_simbolo_lexico))); (yyval.ast)->item->sentry->iks_arguments=(yyvsp[0].arguments);}
#line 2118 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 373 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
#line 2124 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 374 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a type IDENTIFICADOR"); return SINTATICA_ERRO; }
#line 2130 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.arguments) = NULL;}
#line 2136 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.arguments) = (yyvsp[-1].arguments);}
#line 2142 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 380 "parser.y" /* yacc.c:1646  */
    {yyerror("Missing ')'"); return SINTATICA_ERRO; }
#line 2148 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 381 "parser.y" /* yacc.c:1646  */
    {yyerror("Missing '('"); return SINTATICA_ERRO; }
#line 2154 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 384 "parser.y" /* yacc.c:1646  */
    { 
                                                                        if(yystack_find_top((yyvsp[-2].valor_simbolo_lexico))!=NULL) 
                                                                            return IKS_ERROR_DECLARED; 
                                                                        else 
                                                                            yystack_add((yyvsp[-2].valor_simbolo_lexico), (yyvsp[-3].integer), IKS_VARIABLE); 
                                                                        (yyval.arguments) = cc_list_append(cc_list_create((yyvsp[-3].integer)),(yyvsp[0].arguments));
                                                                      }
#line 2166 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 391 "parser.y" /* yacc.c:1646  */
    {  
                                                                        if(yystack_find_top((yyvsp[-2].valor_simbolo_lexico))!=NULL) 
                                                                            return IKS_ERROR_DECLARED; 
                                                                        else 
                                                                            yystack_add((yyvsp[-2].valor_simbolo_lexico), (yyvsp[-3].integer), IKS_VARIABLE); 
                                                                        (yyval.arguments) = cc_list_append(cc_list_create((yyvsp[-3].integer)),(yyvsp[0].arguments));
                                                                      }
#line 2178 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 398 "parser.y" /* yacc.c:1646  */
    { 
                                                                        if(yystack_find_top((yyvsp[0].valor_simbolo_lexico))!=NULL) 
                                                                            return IKS_ERROR_DECLARED; 
                                                                        else 
                                                                            yystack_add((yyvsp[0].valor_simbolo_lexico), (yyvsp[-1].integer), IKS_VARIABLE); 
                                                                        (yyval.arguments) = cc_list_create((yyvsp[-1].integer));
                                                                      }
#line 2190 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 405 "parser.y" /* yacc.c:1646  */
    { 
                                                                        if(yystack_find_top((yyvsp[0].valor_simbolo_lexico))!=NULL) 
                                                                            return IKS_ERROR_DECLARED; 
                                                                        else 
                                                                            yystack_add((yyvsp[0].valor_simbolo_lexico), (yyvsp[-1].integer), IKS_VARIABLE); 
                                                                        (yyval.arguments) = cc_list_create((yyvsp[-1].integer));
                                                                      }
#line 2202 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 412 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a param type"); return SINTATICA_ERRO; }
#line 2208 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 413 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a param type"); return SINTATICA_ERRO; }
#line 2214 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 414 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a param type"); return SINTATICA_ERRO; }
#line 2220 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 415 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a param type"); return SINTATICA_ERRO; }
#line 2226 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 416 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
#line 2232 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 417 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
#line 2238 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 422 "parser.y" /* yacc.c:1646  */
    { if(yystack_find((yyvsp[-2].valor_simbolo_lexico))==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find((yyvsp[-2].valor_simbolo_lexico))->iks_var!=IKS_VARIABLE) return yyerror_var((yyvsp[-2].valor_simbolo_lexico)); if(yystack_verify_types((yyvsp[-2].valor_simbolo_lexico)->iks_type,(yyvsp[0].ast)->item->iks_type)>0) return yystack_verify_types((yyvsp[-2].valor_simbolo_lexico)->iks_type,(yyvsp[0].ast)->item->iks_type); (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_ATRIBUICAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,(yyvsp[-2].valor_simbolo_lexico)))),(yyvsp[0].ast));}
#line 2244 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 423 "parser.y" /* yacc.c:1646  */
    { 
                                                      if(yystack_find((yyvsp[-3].valor_simbolo_lexico))==NULL) return IKS_ERROR_UNDECLARED; 
                                                      if(yystack_find((yyvsp[-3].valor_simbolo_lexico))->iks_var!=IKS_ARRAY) return yyerror_var((yyvsp[-3].valor_simbolo_lexico));
                                                      if(yystack_verify_types((yyvsp[-3].valor_simbolo_lexico)->iks_type,(yyvsp[0].ast)->item->iks_type)>0) 
                                                        return yystack_verify_types((yyvsp[-3].valor_simbolo_lexico)->iks_type,(yyvsp[0].ast)->item->iks_type); 
                                                      (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_ATRIBUICAO,NULL))
                                                                              ,cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_VETOR_INDEXADO,NULL))
                                                                              ,cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,(yyvsp[-3].valor_simbolo_lexico)))),(yyvsp[-2].ast))),(yyvsp[0].ast));                         
                                                    }
#line 2258 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 432 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a expression"); return SINTATICA_ERRO; }
#line 2264 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 433 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a expression"); return SINTATICA_ERRO; }
#line 2270 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 438 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[0].ast)->item->type!=AST_IDENTIFICADOR) return IKS_ERROR_WRONG_PAR_INPUT; (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_INPUT,NULL)),(yyvsp[-2].ast)),(yyvsp[0].ast));}
#line 2276 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 439 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a expression left of =>"); return SINTATICA_ERRO; }
#line 2282 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 440 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a expression right of =>"); return SINTATICA_ERRO; }
#line 2288 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 444 "parser.y" /* yacc.c:1646  */
    { if(yytree_match_types_out((yyvsp[0].ast))>0) return IKS_ERROR_WRONG_PAR_OUTPUT; (yyval.ast) = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_OUTPUT,NULL)),(yyvsp[0].ast));}
#line 2294 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 445 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a expression list"); return SINTATICA_ERRO; }
#line 2300 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 450 "parser.y" /* yacc.c:1646  */
    { if(yystack_return_type((yyvsp[0].ast))>0) return IKS_ERROR_WRONG_PAR_RETURN; (yyval.ast) = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_RETURN,NULL)),(yyvsp[0].ast)); set_return(); }
#line 2306 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 451 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing a expression"); return SINTATICA_ERRO; }
#line 2312 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 456 "parser.y" /* yacc.c:1646  */
    { if(yystack_find((yyvsp[-2].valor_simbolo_lexico))==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find((yyvsp[-2].valor_simbolo_lexico))->iks_var!=IKS_FUNCTION) return yyerror_var((yyvsp[-2].valor_simbolo_lexico)); if((yyvsp[-2].valor_simbolo_lexico)->iks_arguments!=NULL) return IKS_ERROR_MISSING_ARGS; (yyval.ast) = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_CHAMADA_DE_FUNCAO,yystack_find((yyvsp[-2].valor_simbolo_lexico))->iks_type,NULL)),cc_tree_create_node(1,cc_tree_item_create_type(AST_IDENTIFICADOR,yystack_find((yyvsp[-2].valor_simbolo_lexico))->iks_type,(yyvsp[-2].valor_simbolo_lexico)))); }
#line 2318 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 457 "parser.y" /* yacc.c:1646  */
    { if(yystack_find((yyvsp[-3].valor_simbolo_lexico))==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find((yyvsp[-3].valor_simbolo_lexico))->iks_var!=IKS_FUNCTION) return yyerror_var((yyvsp[-3].valor_simbolo_lexico)); comp_list_t* args = yytree_get_argument_list((yyvsp[-1].ast)); if(cc_list_length((yyvsp[-3].valor_simbolo_lexico)->iks_arguments)<cc_list_length(args)) return IKS_ERROR_EXCESS_ARGS; if(cc_list_length((yyvsp[-3].valor_simbolo_lexico)->iks_arguments)>cc_list_length(args)) return IKS_ERROR_MISSING_ARGS; if(yytree_match_arguments((yyvsp[-3].valor_simbolo_lexico)->iks_arguments,args)>0) return IKS_ERROR_WRONG_TYPE_ARGS; (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create_type(AST_CHAMADA_DE_FUNCAO,yystack_find((yyvsp[-3].valor_simbolo_lexico))->iks_type,NULL)),cc_tree_create_node(1,cc_tree_item_create_type(AST_IDENTIFICADOR,yystack_find((yyvsp[-3].valor_simbolo_lexico))->iks_type,(yyvsp[-3].valor_simbolo_lexico)))),(yyvsp[-1].ast));}
#line 2324 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 462 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(4,cc_tree_item_create(AST_IF_ELSE,NULL)),(yyvsp[-3].ast)),(yyvsp[0].ast));}
#line 2330 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 464 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(4,cc_tree_item_create(AST_IF_ELSE,NULL)),(yyvsp[-5].ast)),(yyvsp[-2].ast)),(yyvsp[0].ast));}
#line 2336 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 465 "parser.y" /* yacc.c:1646  */
    { yyerror("if statement without expression"); return SINTATICA_ERRO; }
#line 2342 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 466 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing ')'"); return SINTATICA_ERRO; }
#line 2348 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 469 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_WHILE_DO,NULL)),(yyvsp[-3].ast)),(yyvsp[0].ast));}
#line 2354 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 470 "parser.y" /* yacc.c:1646  */
    { yyerror("while statement without expression"); return SINTATICA_ERRO; }
#line 2360 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 474 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_DO_WHILE,NULL)),(yyvsp[-2].ast)),(yyvsp[0].ast));}
#line 2366 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 475 "parser.y" /* yacc.c:1646  */
    { yyerror("do statement without expression"); return SINTATICA_ERRO; }
#line 2372 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
    break;


#line 2376 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.c" /* yacc.c:1646  */
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
#line 478 "parser.y" /* yacc.c:1906  */

