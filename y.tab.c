
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 6 "parser.y"


#include "scanner.h" // for yylex
#include "parser.h"


#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine



/* Line 189 of yacc.c  */
#line 86 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Double = 261,
     T_String = 262,
     T_Class = 263,
     T_LessEqual = 264,
     T_GreaterEqual = 265,
     T_Equal = 266,
     T_NotEqual = 267,
     T_Dims = 268,
     T_And = 269,
     T_Or = 270,
     T_Null = 271,
     T_This = 272,
     T_While = 273,
     T_For = 274,
     T_If = 275,
     T_Else = 276,
     T_Return = 277,
     T_Break = 278,
     T_New = 279,
     T_NewArray = 280,
     T_Print = 281,
     T_ReadInteger = 282,
     T_ReadLine = 283,
     T_Identifier = 284,
     T_StringConstant = 285,
     T_IntConstant = 286,
     T_DoubleConstant = 287,
     T_BoolConstant = 288,
     T_UnaryMinus = 289,
     T_Lower_Than_Else = 290
   };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Double 261
#define T_String 262
#define T_Class 263
#define T_LessEqual 264
#define T_GreaterEqual 265
#define T_Equal 266
#define T_NotEqual 267
#define T_Dims 268
#define T_And 269
#define T_Or 270
#define T_Null 271
#define T_This 272
#define T_While 273
#define T_For 274
#define T_If 275
#define T_Else 276
#define T_Return 277
#define T_Break 278
#define T_New 279
#define T_NewArray 280
#define T_Print 281
#define T_ReadInteger 282
#define T_ReadLine 283
#define T_Identifier 284
#define T_StringConstant 285
#define T_IntConstant 286
#define T_DoubleConstant 287
#define T_BoolConstant 288
#define T_UnaryMinus 289
#define T_Lower_Than_Else 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 22 "parser.y"

    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
    Type *type;
    NamedType *cType;
    List<NamedType*> *cTypeList;
    FnDecl *fDecl;
    VarDecl *var;
    List<VarDecl*> *varList;
    Expr *expr;
    List<Expr*> *exprList;
    Stmt *stmt;
    List<Stmt*> *stmtList;
    LValue *lvalue;



/* Line 214 of yacc.c  */
#line 215 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 240 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    41,     2,     2,
      50,    51,    39,    37,    52,    38,    44,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      35,    34,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    43,
      46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    19,
      22,    24,    26,    28,    30,    32,    35,    41,    44,    45,
      47,    49,    55,    61,    63,    64,    68,    70,    73,    78,
      81,    82,    85,    86,    89,    91,    98,   104,   114,   118,
     121,   127,   130,   132,   136,   141,   146,   153,   155,   156,
     158,   160,   162,   166,   170,   174,   178,   182,   186,   190,
     194,   198,   202,   206,   210,   214,   218,   221,   224,   228,
     232,   237,   241,   248,   250,   252,   254,   256,   258,   260,
     262,   263,   267,   269,   272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    56,    -1,    56,    57,    -1,    57,    -1,
      61,    -1,    67,    -1,    58,    -1,    59,    47,    -1,    60,
      29,    -1,     5,    -1,     7,    -1,     6,    -1,     4,    -1,
      29,    -1,    60,    13,    -1,     8,    29,    48,    62,    49,
      -1,    62,    63,    -1,    -1,    58,    -1,    67,    -1,    60,
      29,    50,    65,    51,    -1,     3,    29,    50,    65,    51,
      -1,    66,    -1,    -1,    66,    52,    59,    -1,    59,    -1,
      64,    68,    -1,    48,    69,    70,    49,    -1,    69,    58,
      -1,    -1,    71,    70,    -1,    -1,    74,    47,    -1,    68,
      -1,    20,    50,    75,    51,    71,    79,    -1,    18,    50,
      75,    51,    71,    -1,    19,    50,    74,    47,    75,    47,
      74,    51,    71,    -1,    22,    75,    47,    -1,    22,    47,
      -1,    26,    50,    78,    51,    47,    -1,    23,    47,    -1,
      29,    -1,    75,    44,    29,    -1,    75,    45,    75,    53,
      -1,    29,    50,    77,    51,    -1,    75,    44,    29,    50,
      77,    51,    -1,    75,    -1,    -1,    72,    -1,    73,    -1,
      76,    -1,    72,    34,    75,    -1,    75,    37,    75,    -1,
      75,    38,    75,    -1,    75,    40,    75,    -1,    75,    39,
      75,    -1,    75,    41,    75,    -1,    75,    12,    75,    -1,
      75,    11,    75,    -1,    75,    35,    75,    -1,    75,    36,
      75,    -1,    75,     9,    75,    -1,    75,    14,    75,    -1,
      75,    15,    75,    -1,    50,    75,    51,    -1,    38,    75,
      -1,    42,    75,    -1,    27,    50,    51,    -1,    28,    50,
      51,    -1,    24,    50,    29,    51,    -1,    75,    10,    75,
      -1,    25,    50,    75,    52,    60,    51,    -1,    17,    -1,
      31,    -1,    32,    -1,    33,    -1,    30,    -1,    16,    -1,
      78,    -1,    -1,    78,    52,    75,    -1,    75,    -1,    21,
      71,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   111,   112,   115,   116,   117,   120,   123,
     126,   127,   128,   129,   130,   131,   134,   138,   139,   142,
     143,   146,   148,   152,   153,   156,   158,   161,   164,   168,
     169,   172,   173,   176,   177,   178,   180,   182,   184,   186,
     188,   190,   193,   194,   195,   198,   200,   204,   205,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   224,   225,   226,   227,   229,   230,   232,
     233,   235,   237,   239,   242,   243,   244,   245,   246,   249,
     250,   253,   254,   257,   258
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Double",
  "T_String", "T_Class", "T_LessEqual", "T_GreaterEqual", "T_Equal",
  "T_NotEqual", "T_Dims", "T_And", "T_Or", "T_Null", "T_This", "T_While",
  "T_For", "T_If", "T_Else", "T_Return", "T_Break", "T_New", "T_NewArray",
  "T_Print", "T_ReadInteger", "T_ReadLine", "T_Identifier",
  "T_StringConstant", "T_IntConstant", "T_DoubleConstant",
  "T_BoolConstant", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "T_UnaryMinus", "'.'", "'['", "T_Lower_Than_Else", "';'", "'{'",
  "'}'", "'('", "')'", "','", "']'", "$accept", "Program", "DeclList",
  "Decl", "VarDecl", "Variable", "Type", "ClassDecl", "FieldList", "Field",
  "FnHeader", "Formals", "FormalList", "FnDecl", "StmtBlock", "VarDecls",
  "StmtList", "Stmt", "LValue", "Call", "OptExpr", "Expr", "Constant",
  "Actuals", "ExprList", "OptElse", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    61,    60,    62,    43,    45,    42,
      47,    37,    33,   289,    46,    91,   290,    59,   123,   125,
      40,    41,    44,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    58,    59,
      60,    60,    60,    60,    60,    60,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     2,     5,     2,     0,     1,
       1,     5,     5,     1,     0,     3,     1,     2,     4,     2,
       0,     2,     0,     2,     1,     6,     5,     9,     3,     2,
       5,     2,     1,     3,     4,     4,     6,     1,     0,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       4,     3,     6,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     1,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    13,    10,    12,    11,     0,    14,     0,     2,
       4,     7,     0,     0,     5,     0,     6,     0,     0,     1,
       3,     8,    15,     9,    30,    27,    24,    18,    24,    32,
      26,     0,     0,    23,     0,     0,    78,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    77,
      74,    75,    76,     0,     0,     0,    29,    34,     0,    32,
      49,    50,     0,    47,    51,     9,    22,     0,    16,    19,
      17,    20,    21,     0,    48,     0,    42,    39,     0,    41,
       0,     0,     0,     0,     0,    80,    66,    67,     0,    28,
      31,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,    38,     0,     0,    82,     0,    68,    69,     0,
      79,    65,    52,    62,    71,    59,    58,    63,    64,    60,
      61,    53,    54,    56,    55,    57,    43,     0,    48,     0,
      48,    70,     0,     0,     0,    45,    80,    44,    36,     0,
      84,     0,    40,    81,     0,    48,    48,    35,    72,    46,
       0,    83,    48,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,    31,    14,    34,    70,
      15,    32,    33,    16,    57,    29,    58,    59,    60,    61,
      62,    63,    64,   119,   120,   157
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
      83,   -18,   -73,   -73,   -73,   -73,   -11,   -73,    26,    83,
     -73,   -73,    -8,     3,   -73,     4,   -73,   -19,    20,   -73,
     -73,   -73,   -73,    27,   -73,   -73,    17,   -73,    17,    91,
     -73,     7,    -4,    24,     1,    -2,   -73,   -73,    30,    31,
      32,   449,    37,    35,    42,    43,    44,    50,   -10,   -73,
     -73,   -73,   -73,   473,   473,   473,   -73,   -73,    52,   387,
      68,   -73,    56,   298,   -73,   -73,   -73,    17,   -73,   -73,
     -73,   -73,   -73,   473,   473,   473,    55,   -73,   246,   -73,
     103,   473,   473,    84,    85,   473,   -16,   -16,   153,   -73,
     -73,   473,   -73,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   105,   473,   -73,   191,
      90,   208,   -73,    89,   135,   298,   -14,   -73,   -73,    92,
      96,   -73,   298,    34,    34,   320,   320,   357,   309,    34,
      34,   168,   168,   -16,   -16,   -16,   108,   116,   422,   473,
     422,   -73,    17,   112,   473,   -73,   473,   -73,   -73,   259,
     145,    -3,   -73,   298,   126,   473,   422,   -73,   -73,   -73,
     127,   -73,   422,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   172,   -17,    -1,     0,   -73,   -73,   -73,
     -73,   154,   -73,   149,   169,   -73,   136,   354,   -73,   -73,
     -72,   -40,   -73,    39,   104,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int16 yytable[] =
{
      13,    78,   110,   -14,     1,     2,     3,     4,     5,    13,
      22,    17,    56,    86,    87,    88,    22,    69,    18,   -14,
      22,     2,     3,     4,     5,    30,    19,    30,   106,   107,
       7,    26,    23,   109,    13,   111,    65,   143,   144,    21,
      85,   114,   115,   -49,   -49,   115,     7,    66,   158,    72,
      68,   122,    24,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   108,   137,    27,   -49,
     -49,   101,   102,   103,   104,   105,    67,    28,   106,   107,
      73,    74,    75,   160,    79,    80,     1,     2,     3,     4,
       5,     6,    81,    82,    83,     2,     3,     4,     5,   149,
      84,    89,    91,    92,   153,    85,   115,    36,    37,    38,
      39,    40,     7,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    93,    94,    95,    96,    53,
      97,    98,   113,    54,   136,   117,   118,   139,   -48,    24,
     141,    55,   151,   145,    93,    94,    95,    96,   144,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   146,   152,
     106,   107,    93,    94,    95,    96,   156,    97,    98,   147,
      99,   100,   101,   102,   103,   104,   105,   159,   162,   106,
     107,    20,    35,    71,    25,   154,   116,   142,    99,   100,
     101,   102,   103,   104,   105,    90,     0,   106,   107,     0,
      93,    94,    95,    96,   121,    97,    98,   103,   104,   105,
       0,     0,   106,   107,     0,     0,     0,    93,    94,    95,
      96,     0,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   104,   105,     0,     0,   106,   107,     0,     0,     0,
       0,     0,   138,    99,   100,   101,   102,   103,   104,   105,
       0,     0,   106,   107,     0,    93,    94,    95,    96,   140,
      97,    98,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,     0,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,   107,     0,   112,    99,   100,   101,   102,   103,   104,
     105,     0,     0,   106,   107,     0,   155,    93,    94,    95,
      96,     0,    97,    98,     0,     0,     0,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,     0,     0,    93,
      94,   -49,   -49,    99,   100,   101,   102,   103,   104,   105,
       0,     0,   106,   107,    99,   100,   101,   102,   103,   104,
     105,     0,     0,   106,   107,    99,   100,   101,   102,   103,
     104,   105,     0,     0,   106,   107,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,     0,
       0,   106,   107,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    76,    49,    50,    51,
      52,     0,     0,     0,     0,    53,     0,     0,     0,    54,
       0,     0,     0,     0,   -48,    24,     0,    55,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,    46,
      47,    76,    49,    50,    51,    52,     0,     0,     0,     0,
      53,     0,     0,     0,    54,    36,    37,     0,     0,     0,
      24,     0,    55,    43,    44,     0,    46,    47,    76,    49,
      50,    51,    52,     0,     0,     0,     0,    53,     0,    36,
      37,    54,   148,     0,   150,     0,    77,    43,    44,    55,
      46,    47,    76,    49,    50,    51,    52,     0,     0,     0,
     161,    53,     0,     0,     0,    54,   163,     0,     0,     0,
       0,     0,     0,    55
};

static const yytype_int16 yycheck[] =
{
       0,    41,    74,    13,     3,     4,     5,     6,     7,     9,
      13,    29,    29,    53,    54,    55,    13,    34,    29,    29,
      13,     4,     5,     6,     7,    26,     0,    28,    44,    45,
      29,    50,    29,    73,    34,    75,    29,    51,    52,    47,
      50,    81,    82,     9,    10,    85,    29,    51,    51,    51,
      49,    91,    48,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    67,   107,    48,    35,
      36,    37,    38,    39,    40,    41,    52,    50,    44,    45,
      50,    50,    50,   155,    47,    50,     3,     4,     5,     6,
       7,     8,    50,    50,    50,     4,     5,     6,     7,   139,
      50,    49,    34,    47,   144,    50,   146,    16,    17,    18,
      19,    20,    29,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     9,    10,    11,    12,    38,
      14,    15,    29,    42,    29,    51,    51,    47,    47,    48,
      51,    50,   142,    51,     9,    10,    11,    12,    52,    14,
      15,    35,    36,    37,    38,    39,    40,    41,    50,    47,
      44,    45,     9,    10,    11,    12,    21,    14,    15,    53,
      35,    36,    37,    38,    39,    40,    41,    51,    51,    44,
      45,     9,    28,    34,    15,   146,    82,    52,    35,    36,
      37,    38,    39,    40,    41,    59,    -1,    44,    45,    -1,
       9,    10,    11,    12,    51,    14,    15,    39,    40,    41,
      -1,    -1,    44,    45,    -1,    -1,    -1,     9,    10,    11,
      12,    -1,    14,    15,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    51,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    -1,     9,    10,    11,    12,    51,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    45,    -1,    47,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    45,    -1,    47,     9,    10,    11,
      12,    -1,    14,    15,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    45,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    45,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    48,    -1,    50,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    42,    16,    17,    -1,    -1,    -1,
      48,    -1,    50,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    16,
      17,    42,   138,    -1,   140,    -1,    47,    24,    25,    50,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
     156,    38,    -1,    -1,    -1,    42,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    29,    55,    56,
      57,    58,    59,    60,    61,    64,    67,    29,    29,     0,
      57,    47,    13,    29,    48,    68,    50,    48,    50,    69,
      59,    60,    65,    66,    62,    65,    16,    17,    18,    19,
      20,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    38,    42,    50,    58,    68,    70,    71,
      72,    73,    74,    75,    76,    29,    51,    52,    49,    58,
      63,    67,    51,    50,    50,    50,    29,    47,    75,    47,
      50,    50,    50,    50,    50,    50,    75,    75,    75,    49,
      70,    34,    47,     9,    10,    11,    12,    14,    15,    35,
      36,    37,    38,    39,    40,    41,    44,    45,    59,    75,
      74,    75,    47,    29,    75,    75,    78,    51,    51,    77,
      78,    51,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    29,    75,    51,    47,
      51,    51,    52,    51,    52,    51,    50,    53,    71,    75,
      71,    60,    47,    75,    77,    47,    21,    79,    51,    51,
      74,    71,    51,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {//debug("PROGRAM");
                                      (yylsp[(1) - (1)]);/* pp2: The @1 is needed to convince
                                       * yacc to set up yylloc. You can remove
                                       * it once you have other uses of @n*/
                                        Program *program = new Program((yyvsp[(1) - (1)].declList));
                                      // if no errors, advance to next phase
                                      // if (ReportError::NumErrors() == 0)
                                          program->Print(0);

                                     }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    { (yyval.decl)=(yyvsp[(1) - (1)].fDecl); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { (yyval.decl)=(yyvsp[(1) - (1)].var); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { (yyval.var) = new VarDecl(new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier)), (yyvsp[(1) - (2)].type)); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { (yyval.type) = Type::intType; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { (yyval.type) = Type::stringType; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    { (yyval.type) = Type::doubleType; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { (yyval.type) = Type::boolType; }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { (yyval.type) = new NamedType(new Identifier((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].identifier))); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { (yyval.type) = new ArrayType(Join((yylsp[(1) - (2)]), (yylsp[(2) - (2)])), (yyvsp[(1) - (2)].type)); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { (yyval.decl) = new ClassDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), (yyvsp[(4) - (5)].declList)); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { (yyval.declList) = new List<Decl*>(); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].var); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].fDecl); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { (yyval.fDecl) = new FnDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), (yyvsp[(1) - (5)].type), (yyvsp[(4) - (5)].varList)); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { (yyval.fDecl) = new FnDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), Type::voidType, (yyvsp[(4) - (5)].varList)); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval.varList) = (yyvsp[(1) - (1)].varList); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval.varList) = new List<VarDecl*>; }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { ((yyval.varList)=(yyvsp[(1) - (3)].varList))->Append((yyvsp[(3) - (3)].var)); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { ((yyval.varList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].var)); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { ((yyval.fDecl)=(yyvsp[(1) - (2)].fDecl))->SetFunctionBody((yyvsp[(2) - (2)].stmt)); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { (yyval.stmt) = new StmtBlock((yyvsp[(2) - (4)].varList), (yyvsp[(3) - (4)].stmtList)); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { ((yyval.varList)=(yyvsp[(1) - (2)].varList))->Append((yyvsp[(2) - (2)].var)); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { (yyval.varList) = new List<VarDecl*>; }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    { (yyval.stmtList) = (yyvsp[(2) - (2)].stmtList); (yyval.stmtList)->InsertAt((yyvsp[(1) - (2)].stmt), 0); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    { (yyval.stmtList) = new List<Stmt*>; }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (2)].expr); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    { (yyval.stmt) = new IfStmt((yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].stmt), (yyvsp[(6) - (6)].stmt)); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    { (yyval.stmt) = new WhileStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt)); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { (yyval.stmt) = new ForStmt((yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt)); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    { (yyval.stmt) = new ReturnStmt((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].expr)); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    { (yyval.stmt) = new ReturnStmt((yylsp[(1) - (2)]), new EmptyExpr()); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    { (yyval.stmt) = new PrintStmt((yyvsp[(3) - (5)].exprList)); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    { (yyval.stmt) = new BreakStmt((yylsp[(1) - (2)])); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    { (yyval.lvalue) = new FieldAccess(NULL, new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier))); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    { (yyval.lvalue) = new FieldAccess((yyvsp[(1) - (3)].expr), new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier))); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    { (yyval.lvalue) = new ArrayAccess(Join((yylsp[(1) - (4)]), (yylsp[(4) - (4)])), (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    { (yyval.expr) = new Call(Join((yylsp[(1) - (4)]),(yylsp[(4) - (4)])), NULL, new Identifier((yylsp[(1) - (4)]),(yyvsp[(1) - (4)].identifier)), (yyvsp[(3) - (4)].exprList)); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    { (yyval.expr) = new Call(Join((yylsp[(1) - (6)]),(yylsp[(6) - (6)])), (yyvsp[(1) - (6)].expr), new Identifier((yylsp[(3) - (6)]),(yyvsp[(3) - (6)].identifier)), (yyvsp[(5) - (6)].exprList)); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    { (yyval.expr) = new EmptyExpr(); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].lvalue); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    { (yyval.expr) = new AssignExpr((yyvsp[(1) - (3)].lvalue), new Operator((yylsp[(2) - (3)]),"="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "+"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "-"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"/"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"*"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"%"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    { (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"!="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    { (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"=="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"<"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),">"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"<="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"&&"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    { (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),"||"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    { (yyval.expr) = new ArithmeticExpr(new Operator((yylsp[(1) - (2)]),"-"), (yyvsp[(2) - (2)].expr)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    { (yyval.expr) = new LogicalExpr(new Operator((yylsp[(1) - (2)]),"!"), (yyvsp[(2) - (2)].expr)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    { (yyval.expr) = new ReadIntegerExpr(Join((yylsp[(1) - (3)]),(yylsp[(3) - (3)]))); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    { (yyval.expr) = new ReadLineExpr(Join((yylsp[(1) - (3)]),(yylsp[(3) - (3)]))); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    { (yyval.expr) = new NewExpr(Join((yylsp[(1) - (4)]),(yylsp[(4) - (4)])),new NamedType(new Identifier((yylsp[(3) - (4)]),(yyvsp[(3) - (4)].identifier)))); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]),">="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    { (yyval.expr) = new NewArrayExpr(Join((yylsp[(1) - (6)]),(yylsp[(6) - (6)])),(yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].type)); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    { (yyval.expr) = new This((yylsp[(1) - (1)])); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { (yyval.expr) = new IntConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].integerConstant)); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    { (yyval.expr) = new DoubleConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].doubleConstant)); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { (yyval.expr) = new BoolConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].boolConstant)); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    { (yyval.expr) = new StringConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].stringConstant)); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    { (yyval.expr) = new NullConstant((yylsp[(1) - (1)])); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    { (yyval.exprList) = (yyvsp[(1) - (1)].exprList); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    { (yyval.exprList) = new List<Expr*>; }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    { ((yyval.exprList)=(yyvsp[(1) - (3)].exprList))->Append((yyvsp[(3) - (3)].expr)); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    { ((yyval.exprList) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expr)); }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    { (yyval.stmt) = (yyvsp[(2) - (2)].stmt); }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    { (yyval.stmt) = NULL; }
    break;



/* Line 1455 of yacc.c  */
#line 2244 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 262 "parser.y"



/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}

