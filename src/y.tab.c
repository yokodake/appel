/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./src/tiger.grm"

#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "errormsg.h"
#include "absyn.h"

extern int yylex(); /* function prototype */

A_exp absyn_root;

void yyerror(const char *s) {
 EM_error(EM_tokPos, "%s", s);
}


#line 87 "src/y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
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
    ID = 258,
    STRING = 259,
    INT = 260,
    COMMA = 261,
    COLON = 262,
    SEMICOLON = 263,
    LPAREN = 264,
    RPAREN = 265,
    LBRACK = 266,
    RBRACK = 267,
    LBRACE = 268,
    RBRACE = 269,
    DOT = 270,
    PLUS = 271,
    MINUS = 272,
    TIMES = 273,
    DIVIDE = 274,
    EQ = 275,
    NEQ = 276,
    LT = 277,
    LE = 278,
    GT = 279,
    GE = 280,
    AND = 281,
    OR = 282,
    ASSIGN = 283,
    ARRAY = 284,
    IF = 285,
    THEN = 286,
    ELSE = 287,
    WHILE = 288,
    FOR = 289,
    TO = 290,
    DO = 291,
    LET = 292,
    IN = 293,
    END = 294,
    OF = 295,
    BREAK = 296,
    NIL = 297,
    FUNCTION = 298,
    VAR = 299,
    TYPE = 300,
    LOWPREC = 301,
    UMINUS = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "./src/tiger.grm"

  int pos;
  int ival;
  string sval;
  struct {string sval; int ssiz; } str;
  A_field field;
  A_fieldList fieldList;
  A_dec dec;
  A_decList decList;
  A_fundecList fundecList;
  A_fundec fundec;
  A_ty ty;
  A_namety namety;
  A_nametyList nametyList;
  A_exp exp;
  A_var var;
  A_efield efield;
  A_efieldList efieldList;
  A_expList expList;
  S_symbol symbol;

#line 200 "src/y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   367

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

#define YYUNDEFTOK  2
#define YYMAXUTOK   302

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    86,    89,    90,    92,    93,    94,    97,
      99,   100,   101,   103,   104,   105,   106,   107,   110,   112,
     116,   118,   122,   123,   124,   125,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   147,   148,   150,   151,   153,   154,   156,
     157,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   171,   172,   175,   176,   178,   180,   181,   183,
     184
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INT", "\",\"", "\":\"",
  "\";\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\".\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"=\"", "\"!=\"", "\"<\"", "\"<=\"",
  "\">\"", "\">=\"", "\"&\"", "\"|\"", "\":=\"", "\"array\"", "\"if\"",
  "\"then\"", "\"else\"", "\"while\"", "\"for\"", "\"to\"", "\"do\"",
  "\"let\"", "\"in\"", "\"end\"", "\"of\"", "\"break\"", "\"nil\"",
  "\"function\"", "\"var\"", "\"type\"", "LOWPREC", "UMINUS", "$accept",
  "program", "id", "decs", "dec", "tydec", "ty", "tyfields", "tyfield",
  "tyfieldList", "vardec", "fundec", "lvalue", "exp", "expseq", "seq",
  "funcall", "funargs", "binexp", "boolexp", "reccrea", "recfield",
  "recfields", "ifexp", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -42

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-42)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,   -42,   -42,   -42,    69,   147,   147,   147,     6,   -32,
     -42,   -42,    27,    -3,    48,   309,   -42,   -42,   -42,   -42,
     -42,   -42,   216,   -42,   265,   174,     3,     6,     6,     6,
      -9,   -32,   -42,   -42,   -42,   -42,   137,   147,    57,   147,
       6,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,    24,   147,   147,   147,    53,
       0,    45,   147,   -42,   -42,    -1,   281,   -42,    47,    63,
     297,   -42,   309,    62,    62,   -42,   -42,   332,   332,   332,
     332,   332,   332,   342,   321,   216,   -42,   248,   309,   228,
       6,     6,   147,     1,   216,    36,   147,    67,    42,   147,
       6,    70,   -42,   -42,   147,   147,    76,    75,    81,    71,
     309,     6,    49,   -42,   -42,   -42,   -42,    -1,   -42,   147,
     309,    63,   -42,   309,   195,     6,    44,     6,   -42,   147,
      79,     6,   -42,   309,   -42,   147,   -42,     6,   147,    81,
     309,   -42,   -42,   309,    74,   309,   -42,   147,   309
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,    29,    28,     0,     0,     0,     0,     0,     5,
      40,    27,     0,    22,    26,     2,    31,    32,    33,    34,
      37,    30,    46,    51,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     4,    48,    50,     0,    65,     0,    68,
       0,    23,    36,    52,    53,    54,    55,    56,    57,    59,
      60,    58,    61,    62,    63,    46,    35,    69,    38,     0,
      14,     0,     0,     0,    46,     0,     0,     0,    25,     0,
       0,     0,    24,    45,     0,     0,     0,     0,    17,     0,
      18,    14,     0,    10,     9,    43,    41,    50,    47,     0,
      66,    68,    64,    70,     0,     0,     0,     0,    13,     0,
       0,     0,    49,    42,    67,     0,    15,     0,     0,    17,
      19,    11,    12,    39,     0,    20,    16,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,    28,    59,   -42,   -42,   -42,   -15,   -30,   -41,
     -42,   -42,   -42,    -4,   -42,   -24,   -42,   -13,   -42,   -42,
     -42,     5,   -14,   -42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    30,    31,    32,   114,   107,   108,   128,
      33,    34,    14,    15,    95,    55,    16,    97,    17,    18,
      19,    69,   101,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    23,    24,    25,     1,    96,    36,    91,    37,     1,
      38,    27,    28,    29,   111,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    35,    92,    62,
     112,    58,    65,    66,    86,    70,    26,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   137,    87,    88,    89,    59,    60,    61,    94,    39,
       1,   103,    90,    40,   138,    93,    68,    99,    71,   100,
     115,    67,     1,     2,     3,   116,    41,   118,     4,    21,
      44,    45,   119,   125,   122,   126,     5,   127,   110,   131,
      63,   129,   117,   141,   147,   120,   130,   139,   146,     6,
     123,   124,     7,     8,   132,   121,     9,   134,     0,     0,
      10,    11,     0,     0,     0,   133,     0,     0,   106,   109,
       0,   113,     0,     0,     0,   140,     0,     0,    68,     0,
       0,   143,     0,     0,   145,     0,     0,     0,     0,   106,
       1,     2,     3,   148,     0,     0,     4,    64,     0,     0,
       1,     2,     3,   136,     5,   106,     4,     0,     0,   142,
       0,     0,     0,     0,     5,   144,     0,     6,     0,     0,
       7,     8,     0,     0,     9,     0,     0,     6,    10,    11,
       7,     8,     0,     0,     9,     0,     0,     0,    10,    11,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,    54,     0,     0,     0,     0,     0,
       0,   135,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,   105,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
     104,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    98,     0,     0,    56,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   102,
       0,     0,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,     7,     3,     6,     9,     7,    11,     3,
      13,    43,    44,    45,    13,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    38,
      29,    28,    36,    37,    10,    39,     8,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     7,    56,    57,    58,    27,    28,    29,    62,    11,
       3,    85,     9,    15,    20,    20,    38,    20,    40,     6,
      94,    14,     3,     4,     5,    39,    28,    10,     9,    10,
      18,    19,    40,     7,    14,    10,    17,     6,    92,    40,
      31,    20,    96,    14,    20,    99,   111,   127,   139,    30,
     104,   105,    33,    34,   117,   100,    37,   121,    -1,    -1,
      41,    42,    -1,    -1,    -1,   119,    -1,    -1,    90,    91,
      -1,    93,    -1,    -1,    -1,   129,    -1,    -1,   100,    -1,
      -1,   135,    -1,    -1,   138,    -1,    -1,    -1,    -1,   111,
       3,     4,     5,   147,    -1,    -1,     9,    10,    -1,    -1,
       3,     4,     5,   125,    17,   127,     9,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    17,   137,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    37,    -1,    -1,    30,    41,    42,
      33,    34,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    12,    -1,    -1,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    12,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    17,    30,    33,    34,    37,
      41,    42,    49,    50,    60,    61,    64,    66,    67,    68,
      71,    10,    61,    61,    61,    61,    50,    43,    44,    45,
      51,    52,    53,    58,    59,     0,     9,    11,    13,    11,
      15,    28,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     8,    63,    31,    36,    28,    50,
      50,    50,    38,    51,    10,    61,    61,    14,    50,    69,
      61,    50,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    10,    61,    61,    61,
       9,     7,    28,    20,    61,    62,     6,    65,    12,    20,
       6,    70,    12,    63,    32,    35,    50,    55,    56,    50,
      61,    13,    29,    50,    54,    63,    39,    61,    10,    40,
      61,    69,    14,    61,    61,     7,    10,     6,    57,    20,
      55,    40,    65,    61,    70,    36,    50,     7,    20,    56,
      61,    14,    50,    61,    50,    61,    57,    20,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    52,    52,    53,
      54,    54,    54,    55,    55,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    70,    70,    71,
      71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     1,     1,     1,     4,
       1,     3,     3,     2,     0,     3,     3,     0,     4,     6,
       7,     9,     1,     3,     4,     4,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     4,     3,     1,     4,     8,
       1,     5,     6,     2,     0,     3,     0,     5,     3,     3,
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     3,     3,     3,     0,     4,
       6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 83 "./src/tiger.grm"
    {(yyval.exp)=absyn_root = (yyvsp[0].exp);}
#line 1438 "src/y.tab.c"
    break;

  case 3:
#line 86 "./src/tiger.grm"
    {(yyval.symbol)= S_Symbol(String((yyvsp[0].sval)));}
#line 1444 "src/y.tab.c"
    break;

  case 4:
#line 89 "./src/tiger.grm"
    {(yyval.decList)=A_DecList((yyvsp[-1].dec), (yyvsp[0].decList));}
#line 1450 "src/y.tab.c"
    break;

  case 5:
#line 90 "./src/tiger.grm"
    {(yyval.decList)=NULL;}
#line 1456 "src/y.tab.c"
    break;

  case 6:
#line 92 "./src/tiger.grm"
    {(yyval.dec)=A_TypeDec(EM_tokPos, A_NametyList((yyvsp[0].namety), NULL));}
#line 1462 "src/y.tab.c"
    break;

  case 7:
#line 93 "./src/tiger.grm"
    {(yyval.dec)=(yyvsp[0].dec);}
#line 1468 "src/y.tab.c"
    break;

  case 8:
#line 94 "./src/tiger.grm"
    {(yyval.dec)=A_FunctionDec(EM_tokPos, A_FundecList((yyvsp[0].fundec), NULL));}
#line 1474 "src/y.tab.c"
    break;

  case 9:
#line 97 "./src/tiger.grm"
    {(yyval.namety)=A_Namety((yyvsp[-2].symbol), (yyvsp[0].ty));}
#line 1480 "src/y.tab.c"
    break;

  case 10:
#line 99 "./src/tiger.grm"
    {(yyval.ty)=A_NameTy(EM_tokPos, (yyvsp[0].symbol));}
#line 1486 "src/y.tab.c"
    break;

  case 11:
#line 100 "./src/tiger.grm"
    {(yyval.ty)=A_RecordTy(EM_tokPos, (yyvsp[-1].fieldList));}
#line 1492 "src/y.tab.c"
    break;

  case 12:
#line 101 "./src/tiger.grm"
    {(yyval.ty)=A_ArrayTy(EM_tokPos, (yyvsp[0].symbol));}
#line 1498 "src/y.tab.c"
    break;

  case 13:
#line 103 "./src/tiger.grm"
    {(yyval.fieldList)=A_FieldList((yyvsp[-1].field), (yyvsp[0].fieldList));}
#line 1504 "src/y.tab.c"
    break;

  case 14:
#line 104 "./src/tiger.grm"
    {(yyval.fieldList)=NULL;}
#line 1510 "src/y.tab.c"
    break;

  case 15:
#line 105 "./src/tiger.grm"
    {(yyval.field)=A_Field(EM_tokPos, (yyvsp[-2].symbol), (yyvsp[0].symbol));}
#line 1516 "src/y.tab.c"
    break;

  case 16:
#line 106 "./src/tiger.grm"
    {(yyval.fieldList)=A_FieldList((yyvsp[-1].field), (yyvsp[0].fieldList));}
#line 1522 "src/y.tab.c"
    break;

  case 17:
#line 107 "./src/tiger.grm"
    {(yyval.fieldList)=NULL;}
#line 1528 "src/y.tab.c"
    break;

  case 18:
#line 110 "./src/tiger.grm"
    {(yyval.dec)=A_VarDec(EM_tokPos, (yyvsp[-2].symbol), NULL, (yyvsp[0].exp));}
#line 1534 "src/y.tab.c"
    break;

  case 19:
#line 112 "./src/tiger.grm"
    {(yyval.dec)=A_VarDec(EM_tokPos, (yyvsp[-4].symbol), (yyvsp[-2].symbol), (yyvsp[0].exp));}
#line 1540 "src/y.tab.c"
    break;

  case 20:
#line 117 "./src/tiger.grm"
    {(yyval.fundec)=A_Fundec(EM_tokPos, (yyvsp[-5].symbol), (yyvsp[-3].fieldList), NULL, (yyvsp[0].exp));}
#line 1546 "src/y.tab.c"
    break;

  case 21:
#line 119 "./src/tiger.grm"
    {(yyval.fundec)=A_Fundec(EM_tokPos, (yyvsp[-7].symbol), (yyvsp[-5].fieldList), (yyvsp[-2].symbol), (yyvsp[0].exp));}
#line 1552 "src/y.tab.c"
    break;

  case 22:
#line 122 "./src/tiger.grm"
    {(yyval.var)=A_SimpleVar(EM_tokPos, (yyvsp[0].symbol));}
#line 1558 "src/y.tab.c"
    break;

  case 23:
#line 123 "./src/tiger.grm"
    {(yyval.var)=A_FieldVar(EM_tokPos, (yyvsp[-2].var), (yyvsp[0].symbol));}
#line 1564 "src/y.tab.c"
    break;

  case 24:
#line 124 "./src/tiger.grm"
    {(yyval.var)=A_SubscriptVar(EM_tokPos, (yyvsp[-3].var), (yyvsp[-1].exp));}
#line 1570 "src/y.tab.c"
    break;

  case 25:
#line 125 "./src/tiger.grm"
    {(yyval.var)=A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[-3].symbol)), (yyvsp[-1].exp));}
#line 1576 "src/y.tab.c"
    break;

  case 26:
#line 129 "./src/tiger.grm"
    {(yyval.exp)=A_VarExp(EM_tokPos, (yyvsp[0].var));}
#line 1582 "src/y.tab.c"
    break;

  case 27:
#line 130 "./src/tiger.grm"
    {(yyval.exp)=A_NilExp(EM_tokPos);}
#line 1588 "src/y.tab.c"
    break;

  case 28:
#line 131 "./src/tiger.grm"
    {(yyval.exp)=A_IntExp(EM_tokPos, (yyvsp[0].ival));}
#line 1594 "src/y.tab.c"
    break;

  case 29:
#line 132 "./src/tiger.grm"
    {(yyval.exp)=A_StringExp(EM_tokPos, String_strip((yyvsp[0].str).sval, (yyvsp[0].str).ssiz));}
#line 1600 "src/y.tab.c"
    break;

  case 30:
#line 133 "./src/tiger.grm"
    {(yyval.exp)=NULL;}
#line 1606 "src/y.tab.c"
    break;

  case 31:
#line 134 "./src/tiger.grm"
    {(yyval.exp)=(yyvsp[0].exp);}
#line 1612 "src/y.tab.c"
    break;

  case 32:
#line 135 "./src/tiger.grm"
    {(yyval.exp)=(yyvsp[0].exp);}
#line 1618 "src/y.tab.c"
    break;

  case 33:
#line 136 "./src/tiger.grm"
    {(yyval.exp)=(yyvsp[0].exp);}
#line 1624 "src/y.tab.c"
    break;

  case 34:
#line 137 "./src/tiger.grm"
    {(yyval.exp)=(yyvsp[0].exp);}
#line 1630 "src/y.tab.c"
    break;

  case 35:
#line 138 "./src/tiger.grm"
    {(yyval.exp)=A_SeqExp(EM_tokPos, A_ExpList((yyvsp[-2].exp), (yyvsp[-1].expList)));}
#line 1636 "src/y.tab.c"
    break;

  case 36:
#line 139 "./src/tiger.grm"
    {(yyval.exp)=A_AssignExp(EM_tokPos, (yyvsp[-2].var), (yyvsp[0].exp));}
#line 1642 "src/y.tab.c"
    break;

  case 37:
#line 140 "./src/tiger.grm"
    {(yyval.exp)=(yyvsp[0].exp);}
#line 1648 "src/y.tab.c"
    break;

  case 38:
#line 141 "./src/tiger.grm"
    {(yyval.exp)=A_WhileExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1654 "src/y.tab.c"
    break;

  case 39:
#line 142 "./src/tiger.grm"
    {(yyval.exp)=A_ForExp(EM_tokPos, (yyvsp[-6].symbol), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1660 "src/y.tab.c"
    break;

  case 40:
#line 143 "./src/tiger.grm"
    {(yyval.exp)=A_BreakExp(EM_tokPos);}
#line 1666 "src/y.tab.c"
    break;

  case 41:
#line 144 "./src/tiger.grm"
    {(yyval.exp)=A_LetExp(EM_tokPos, (yyvsp[-3].decList), (yyvsp[-1].exp));}
#line 1672 "src/y.tab.c"
    break;

  case 42:
#line 145 "./src/tiger.grm"
    {(yyval.exp)=A_ArrayExp(EM_tokPos, (yyvsp[-5].symbol), (yyvsp[-3].exp), (yyvsp[0].exp));}
#line 1678 "src/y.tab.c"
    break;

  case 43:
#line 147 "./src/tiger.grm"
    {(yyval.exp)=A_SeqExp(EM_tokPos, A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList)));}
#line 1684 "src/y.tab.c"
    break;

  case 44:
#line 148 "./src/tiger.grm"
    {(yyval.exp)=NULL;}
#line 1690 "src/y.tab.c"
    break;

  case 45:
#line 150 "./src/tiger.grm"
    {(yyval.expList)=A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList));}
#line 1696 "src/y.tab.c"
    break;

  case 46:
#line 151 "./src/tiger.grm"
    {(yyval.expList)=NULL;}
#line 1702 "src/y.tab.c"
    break;

  case 47:
#line 153 "./src/tiger.grm"
    {(yyval.exp)=A_CallExp(EM_tokPos, (yyvsp[-4].symbol), A_ExpList((yyvsp[-2].exp), (yyvsp[-1].expList)));}
#line 1708 "src/y.tab.c"
    break;

  case 48:
#line 154 "./src/tiger.grm"
    {(yyval.exp)=A_CallExp(EM_tokPos, (yyvsp[-2].symbol), NULL);}
#line 1714 "src/y.tab.c"
    break;

  case 49:
#line 156 "./src/tiger.grm"
    {(yyval.expList)=A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList));}
#line 1720 "src/y.tab.c"
    break;

  case 50:
#line 157 "./src/tiger.grm"
    {(yyval.expList)=NULL;}
#line 1726 "src/y.tab.c"
    break;

  case 51:
#line 159 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_minusOp,A_IntExp(EM_tokPos, 0), (yyvsp[0].exp));}
#line 1732 "src/y.tab.c"
    break;

  case 52:
#line 160 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_plusOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1738 "src/y.tab.c"
    break;

  case 53:
#line 161 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_minusOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1744 "src/y.tab.c"
    break;

  case 54:
#line 162 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_timesOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1750 "src/y.tab.c"
    break;

  case 55:
#line 163 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_divideOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1756 "src/y.tab.c"
    break;

  case 56:
#line 164 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_eqOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1762 "src/y.tab.c"
    break;

  case 57:
#line 165 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_neqOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1768 "src/y.tab.c"
    break;

  case 58:
#line 166 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_gtOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1774 "src/y.tab.c"
    break;

  case 59:
#line 167 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_ltOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1780 "src/y.tab.c"
    break;

  case 60:
#line 168 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_leOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1786 "src/y.tab.c"
    break;

  case 61:
#line 169 "./src/tiger.grm"
    {(yyval.exp)=A_OpExp(EM_tokPos, A_geOp,(yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1792 "src/y.tab.c"
    break;

  case 62:
#line 171 "./src/tiger.grm"
    {(yyval.exp)=A_IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), A_IntExp(EM_tokPos, 0));}
#line 1798 "src/y.tab.c"
    break;

  case 63:
#line 172 "./src/tiger.grm"
    {(yyval.exp)=A_IfExp(EM_tokPos, (yyvsp[-2].exp), A_IntExp(EM_tokPos, 1), (yyvsp[0].exp));}
#line 1804 "src/y.tab.c"
    break;

  case 64:
#line 175 "./src/tiger.grm"
    {(yyval.exp)=A_RecordExp(EM_tokPos, (yyvsp[-4].symbol), A_EfieldList((yyvsp[-2].efield), (yyvsp[-1].efieldList)));}
#line 1810 "src/y.tab.c"
    break;

  case 65:
#line 176 "./src/tiger.grm"
    {(yyval.exp)=A_RecordExp(EM_tokPos, (yyvsp[-2].symbol), NULL);}
#line 1816 "src/y.tab.c"
    break;

  case 66:
#line 178 "./src/tiger.grm"
    {(yyval.efield)=A_Efield((yyvsp[-2].symbol), (yyvsp[0].exp));}
#line 1822 "src/y.tab.c"
    break;

  case 67:
#line 180 "./src/tiger.grm"
    {(yyval.efieldList)=A_EfieldList((yyvsp[-1].efield), (yyvsp[0].efieldList));}
#line 1828 "src/y.tab.c"
    break;

  case 68:
#line 181 "./src/tiger.grm"
    {(yyval.efieldList)=NULL;}
#line 1834 "src/y.tab.c"
    break;

  case 69:
#line 183 "./src/tiger.grm"
    {(yyval.exp)=A_IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), NULL);}
#line 1840 "src/y.tab.c"
    break;

  case 70:
#line 184 "./src/tiger.grm"
    {(yyval.exp)=A_IfExp(EM_tokPos, (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1846 "src/y.tab.c"
    break;


#line 1850 "src/y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
