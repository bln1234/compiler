/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "l25.y"

#include <vector>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "SymbolTable.hpp"
#include "VM.hpp"

void yyerror(const char *s);
int yylex(void);

std::vector<Instruction> code;
int level = 0;  // 当前嵌套层级
int blockStartIndex;
int mainEntryIndex = 0;
SymbolTable symtab;
int addressOffset = 0;  // 当前作用域内的偏移地址

/* Line 371 of yacc.c  */
#line 88 "l25.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "l25.tab.hpp".  */
#ifndef YY_YY_L25_TAB_HPP_INCLUDED
# define YY_YY_L25_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     IDENT = 259,
     PROGRAM = 260,
     FUNC = 261,
     MAIN = 262,
     RETURN = 263,
     LET = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     INPUT = 268,
     OUTPUT = 269,
     STRUCT_DEF = 270,
     STRUCT = 271,
     EQ = 272,
     NEQ = 273,
     LEQ = 274,
     GEQ = 275,
     LT = 276,
     GT = 277,
     ASSIGN = 278,
     PLUS = 279,
     MINUS = 280,
     MUL = 281,
     DIV = 282,
     LPAREN = 283,
     RPAREN = 284,
     LBRACKET = 285,
     RBRACKET = 286,
     LBRACE = 287,
     RBRACE = 288,
     COMMA = 289,
     SEMICOLON = 290,
     DOT = 291
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 21 "l25.y"

    int num;
    char *id;
    std::string* str;
    std::vector<int>* numlist;


/* Line 387 of yacc.c  */
#line 175 "l25.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_L25_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 203 "l25.tab.cpp"

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    12,    15,    22,    23,    27,    28,
      31,    43,    54,    55,    59,    61,    65,    68,    72,    74,
      76,    78,    80,    82,    84,    86,    88,    90,    98,   102,
     104,   108,   117,   119,   123,   126,   131,   135,   141,   148,
     154,   162,   168,   173,   178,   183,   187,   189,   193,   195,
     199,   201,   205,   209,   213,   217,   221,   225,   229,   232,
     235,   237,   241,   245,   249,   253,   255,   257,   261,   266,
     268,   272,   274,   275
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,     5,     4,    32,    39,    42,    44,    33,
      -1,    -1,    39,    40,    -1,    15,     4,    32,    41,    33,
      35,    -1,    -1,    41,    53,    35,    -1,    -1,    42,    43,
      -1,     6,     4,    28,    46,    29,    32,    47,     8,    64,
      35,    33,    -1,     6,     4,    28,    29,    32,    47,     8,
      64,    35,    33,    -1,    -1,     7,    45,    67,    -1,     4,
      -1,    46,    34,     4,    -1,    48,    35,    -1,    47,    48,
      35,    -1,    53,    -1,    51,    -1,    49,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      16,     4,     4,    23,    32,    50,    33,    -1,    16,     4,
       4,    -1,    64,    -1,    50,    34,    64,    -1,    30,     3,
      31,     4,    23,    32,    52,    33,    -1,     3,    -1,    52,
      34,     3,    -1,     9,     4,    -1,     9,     4,    23,    64,
      -1,     4,    23,    64,    -1,     4,    36,     4,    23,    64,
      -1,     4,    30,    64,    31,    23,    64,    -1,    10,    28,
      63,    29,    67,    -1,    10,    28,    63,    29,    67,    11,
      67,    -1,    12,    28,    63,    29,    67,    -1,    13,    28,
      62,    29,    -1,    14,    28,    61,    29,    -1,     4,    28,
      60,    29,    -1,     4,    28,    29,    -1,    64,    -1,    60,
      34,    64,    -1,    64,    -1,    61,    34,    64,    -1,     4,
      -1,    62,    34,     4,    -1,    64,    17,    64,    -1,    64,
      18,    64,    -1,    64,    21,    64,    -1,    64,    20,    64,
      -1,    64,    22,    64,    -1,    64,    19,    64,    -1,    24,
      65,    -1,    25,    65,    -1,    65,    -1,    64,    24,    65,
      -1,    64,    25,    65,    -1,    65,    26,    66,    -1,    65,
      27,    66,    -1,    66,    -1,     4,    -1,     4,    36,     4,
      -1,     4,    30,    64,    31,    -1,     3,    -1,    28,    64,
      29,    -1,    59,    -1,    -1,    32,    68,    47,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    39,    39,    45,    47,    51,    57,    59,    62,    64,
      68,    73,    81,    80,    91,    92,    96,    97,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   113,   117,   124,
     125,   129,   158,   163,   171,   176,   186,   202,   205,   236,
     237,   241,   248,   255,   262,   266,   273,   274,   278,   282,
     289,   290,   294,   298,   302,   306,   310,   314,   321,   322,
     326,   327,   331,   338,   342,   346,   350,   359,   360,   380,
     384,   385,   390,   389
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "PROGRAM", "FUNC",
  "MAIN", "RETURN", "LET", "IF", "ELSE", "WHILE", "INPUT", "OUTPUT",
  "STRUCT_DEF", "STRUCT", "EQ", "NEQ", "LEQ", "GEQ", "LT", "GT", "ASSIGN",
  "PLUS", "MINUS", "MUL", "DIV", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "COMMA", "SEMICOLON", "DOT", "$accept",
  "program", "struct_def_list", "struct_def_stmt", "struct_member_list",
  "func_def", "func", "main_block", "$@1", "param_list", "stmt_list",
  "stmt", "struct_declare_stmt", "struct_init_list", "array_declare_stmt",
  "number_list", "declare_stmt", "assign_stmt", "if_stmt", "while_stmt",
  "input_stmt", "output_stmt", "func_call", "arg_list", "expr_list",
  "ident_list", "bool_expr", "expr", "term", "factor", "block", "$@2", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    41,    41,    42,    42,
      43,    43,    45,    44,    46,    46,    47,    47,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    56,    57,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    64,    64,
      64,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    68,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     0,     2,     6,     0,     3,     0,     2,
      11,    10,     0,     3,     1,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     3,     1,
       3,     8,     1,     3,     2,     4,     3,     5,     6,     5,
       7,     5,     4,     4,     4,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     3,     3,     3,     3,     1,     1,     3,     4,     1,
       3,     1,     0,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     8,     0,     4,     0,
       0,     0,    12,     9,     0,     6,     0,     0,     2,     0,
       0,    72,    13,     0,     0,     0,    14,     0,     0,     0,
      34,     5,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    19,    18,    21,    22,
      23,    24,    25,    26,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
      16,    69,    66,     0,     0,     0,    71,    35,    60,    65,
       0,     0,    36,    45,     0,    46,     0,     0,     0,     0,
       0,    50,     0,     0,    48,    28,     0,    17,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    43,     0,     0,     0,     0,    67,    70,
      61,    62,    63,    64,     0,     0,    47,     0,    37,    39,
      52,    53,    57,    55,    54,    56,    41,    51,    49,     0,
       0,    68,    11,     0,    38,     0,     0,    29,     0,    10,
      40,    27,     0,    32,     0,    30,    31,     0,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     8,    19,     9,    13,    14,    17,    28,
      43,    44,    45,   156,    46,   164,    47,    48,    49,    50,
      51,    52,    76,    84,    93,    92,    88,    89,    78,    79,
      22,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
       7,    21,    42,    20,  -113,  -113,    66,    64,  -113,   121,
      46,    87,  -113,  -113,    61,  -113,    73,    79,  -113,    14,
       9,  -113,  -113,   101,    80,    82,  -113,    93,   -10,   100,
     106,  -113,  -113,   100,   120,   128,   103,   114,   136,   137,
     138,   134,   141,    63,   132,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,    96,    23,   100,  -113,    96,    94,
      96,   151,    96,    96,   164,    96,   165,   139,  -113,   140,
    -113,  -113,    -8,     6,     6,    96,  -113,   116,   130,  -113,
      96,    76,   116,  -113,    37,   116,    26,   148,   143,   129,
     144,  -113,    40,    53,   116,   153,   170,  -113,    96,   173,
     130,   130,    78,     6,     6,     6,     6,    24,    96,  -113,
      96,   155,    96,    79,    96,    96,    96,    96,    96,    96,
      79,  -113,   175,  -113,    96,   149,   157,   112,  -113,  -113,
     130,   130,  -113,  -113,   150,   110,   116,    96,   116,   171,
     116,   116,   116,   116,   116,   116,  -113,  -113,   116,    96,
     152,  -113,  -113,   154,   116,    79,   125,   116,   182,  -113,
    -113,  -113,    96,  -113,   127,   116,  -113,   183,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
     -15,   -41,  -113,  -113,  -113,  -113,   169,  -113,  -113,  -113,
    -113,  -113,   -26,  -113,  -113,  -113,   126,   -54,   -58,    57,
    -112,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      77,   139,    69,    53,    82,    85,    86,    53,   146,    71,
      72,    94,     1,    26,    69,   100,   101,    53,    55,    34,
      59,   102,    98,    23,    35,     3,   107,    36,    99,    53,
      53,    80,    23,    37,    75,    38,    39,    40,    27,    41,
      69,    81,     4,   160,   127,   130,   131,    24,   103,   104,
     103,   104,     5,    42,   135,    53,   136,   111,   138,   134,
     140,   141,   142,   143,   144,   145,   109,    36,    10,   121,
     148,   110,    23,    37,   122,    38,    39,    40,    15,    41,
      36,     7,   123,   154,   108,    23,    37,   124,    38,    39,
      40,    16,    41,    42,    18,   157,    68,    71,    72,    71,
      72,    20,   103,   104,    36,    30,    42,   129,   165,    23,
      37,    21,    38,    39,    40,    31,    41,    32,    73,    74,
      73,    74,    75,    83,    75,    33,    58,    11,    12,    54,
      42,    59,    57,    60,   103,   104,   103,   104,    66,    61,
     103,   104,    62,   151,    67,   153,   114,   115,   116,   117,
     118,   119,    56,   103,   104,    87,   105,   106,   161,   162,
     166,   167,   132,   133,    63,    64,    65,    70,    91,    95,
      96,   112,   113,   120,   126,    97,   125,   128,   137,   147,
     150,   149,   155,   152,   158,   163,   168,   159,    25,    90
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-113)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      54,   113,    43,    29,    58,    59,    60,    33,   120,     3,
       4,    65,     5,     4,    55,    73,    74,    43,    33,    29,
      28,    75,    30,     9,    34,     4,    80,     4,    36,    55,
      56,     8,     9,    10,    28,    12,    13,    14,    29,    16,
      81,    56,     0,   155,    98,   103,   104,    33,    24,    25,
      24,    25,    32,    30,   108,    81,   110,    31,   112,    35,
     114,   115,   116,   117,   118,   119,    29,     4,     4,    29,
     124,    34,     9,    10,    34,    12,    13,    14,    32,    16,
       4,    15,    29,   137,     8,     9,    10,    34,    12,    13,
      14,     4,    16,    30,    33,   149,    33,     3,     4,     3,
       4,    28,    24,    25,     4,     4,    30,    29,   162,     9,
      10,    32,    12,    13,    14,    35,    16,    35,    24,    25,
      24,    25,    28,    29,    28,    32,    23,     6,     7,    23,
      30,    28,     4,    30,    24,    25,    24,    25,     4,    36,
      24,    25,    28,    31,     3,    35,    17,    18,    19,    20,
      21,    22,    32,    24,    25,     4,    26,    27,    33,    34,
      33,    34,   105,   106,    28,    28,    28,    35,     4,     4,
      31,    23,    29,    29,     4,    35,    23,     4,    23,     4,
      23,    32,    11,    33,    32,     3,     3,    33,    19,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    38,     4,     0,    32,    39,    15,    40,    42,
       4,     6,     7,    43,    44,    32,     4,    45,    33,    41,
      28,    32,    67,     9,    33,    53,     4,    29,    46,    68,
       4,    35,    35,    32,    29,    34,     4,    10,    12,    13,
      14,    16,    30,    47,    48,    49,    51,    53,    54,    55,
      56,    57,    58,    59,    23,    47,    32,     4,    23,    28,
      30,    36,    28,    28,    28,    28,     4,     3,    33,    48,
      35,     3,     4,    24,    25,    28,    59,    64,    65,    66,
       8,    47,    64,    29,    60,    64,    64,     4,    63,    64,
      63,     4,    62,    61,    64,     4,    31,    35,    30,    36,
      65,    65,    64,    24,    25,    26,    27,    64,     8,    29,
      34,    31,    23,    29,    17,    18,    19,    20,    21,    22,
      29,    29,    34,    29,    34,    23,     4,    64,     4,    29,
      65,    65,    66,    66,    35,    64,    64,    23,    64,    67,
      64,    64,    64,    64,    64,    64,    67,     4,    64,    32,
      23,    31,    33,    35,    64,    11,    50,    64,    32,    33,
      67,    33,    34,     3,    52,    64,    33,    34,     3
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 40 "l25.y"
    {
        code[0].a = mainEntryIndex;
    }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 52 "l25.y"
    {
        printf("Struct definition: %s\n", (yyvsp[(2) - (6)].id));
    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 69 "l25.y"
    {
        // 添加函数信息到符号表
    
    }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 74 "l25.y"
    {
        printf("Parsed function without param: %s\n", (yyvsp[(2) - (10)].id));
    }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 81 "l25.y"
    {
        mainEntryIndex = code.size();
    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 85 "l25.y"
    {
        code.push_back(Instruction(jmp, 0, 0));
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 114 "l25.y"
    {
        
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 118 "l25.y"
    {
        printf("Declare struct variable: %s of type %s\n", (yyvsp[(3) - (3)].id), (yyvsp[(2) - (3)].id));
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 130 "l25.y"
    {
        int length = (yyvsp[(2) - (8)].num);
        char* name = (yyvsp[(4) - (8)].id);
        std::vector<int>* vals = (yyvsp[(7) - (8)].numlist);

        // 1. 检查数组长度是否匹配
        if ((int)vals->size() != length) {
            fprintf(stderr, "数组初始化长度与声明长度不匹配: %s\n", name);
            exit(1);
        }

        // 2. 向符号表添加数组符号
        Symbol sym(name, SymbolKind::ARRAY, ValueType::Integer, level, symtab.allocateAddress(), length);
        symtab.addSymbol(sym);

        // 3. 生成初始化数组的p-code
        int baseAddr = sym.address;
        for (int i = 0; i < length; ++i) {
            code.push_back(Instruction(lit, 0, (*vals)[i])); 
            code.push_back(Instruction(sto, 0, baseAddr + i));
        }

        // 4. 释放临时vector
        delete vals;
    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 159 "l25.y"
    {
        (yyval.numlist) = new std::vector<int>();
        (yyval.numlist)->push_back((yyvsp[(1) - (1)].num));
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 164 "l25.y"
    {
        (yyval.numlist) = (yyvsp[(1) - (3)].numlist);
        (yyval.numlist)->push_back((yyvsp[(3) - (3)].num));
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 172 "l25.y"
    {
        int addr = symtab.allocateAddress();
        symtab.addSymbol(Symbol((yyvsp[(2) - (2)].id), SymbolKind::Variable, ValueType::Integer, level, addr));
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 177 "l25.y"
    {
        int addr = symtab.allocateAddress();
        symtab.addSymbol(Symbol((yyvsp[(2) - (4)].id), SymbolKind::Variable, ValueType::Integer, level, addr));
        // 赋值 expr 的值在栈顶
        code.push_back(Instruction(sto, level, addr));
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 187 "l25.y"
    {
        Symbol* sym = symtab.findSymbol((yyvsp[(1) - (3)].id));
        if (!sym) {
            fprintf(stderr, "Undefined Variable: %s\n", (yyvsp[(1) - (3)].id));
            exit(1);
        }
        if (sym->kind != SymbolKind::Variable) {
            fprintf(stderr, "%s is noy Variable\n", (yyvsp[(1) - (3)].id));
            exit(1);
        }

        // expr 的值已在栈顶
        // 将其存储到变量地址
        code.push_back(Instruction(sto, level - sym->level, sym->address));
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 203 "l25.y"
    {   
    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 206 "l25.y"
    {
        Symbol* sym = symtab.findSymbol((yyvsp[(1) - (6)].id));
        if (!sym) {
            fprintf(stderr, "Undefined Array: %s\n", (yyvsp[(1) - (6)].id));
            exit(1);
        }
        if (sym->kind != SymbolKind::ARRAY) {
            fprintf(stderr, "%s is not Array\n", (yyvsp[(1) - (6)].id));
            exit(1);
        }

        // 两个 expr：前一个是索引，后一个是值
        // 它们的值会依次在栈上（值在顶，索引在次顶）

        // 先交换栈顶两个元素，使得栈顶是索引，次顶是值
        code.push_back(Instruction(opr, 0, 17)); // opr 20 是 swap

        // 加载基址
        code.push_back(Instruction(lit, 0, sym->address));

        // 加上索引
        code.push_back(Instruction(opr, 0, 2));  // 加法

        // 存储到目标地址（数组[i] = val）
        code.push_back(Instruction(stoi, 0, 0)); // 假设 `stoi` 表示间接存储指令
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 242 "l25.y"
    {
        printf("While stmt\n");
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 249 "l25.y"
    {
        printf("Input stmt\n");
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 256 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 15));
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 263 "l25.y"
    {
        printf("Function call: %s\n", (yyvsp[(1) - (4)].id));
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 267 "l25.y"
    {
        printf("Function call (no args): %s\n", (yyvsp[(1) - (3)].id));
    }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 279 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 14));
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 283 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 14));
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 295 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 8));  // ==
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 299 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 9));  // !=
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 303 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 10)); // <
    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 307 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 11)); // >=
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 311 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 12)); // >
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 315 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 13)); // <=
    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 323 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 1)); //取负
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 328 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 2));  // 加法
    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 332 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 3));  // 减法
    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 339 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 4));  // 乘法
    }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 343 "l25.y"
    {
        code.push_back(Instruction(opr, 0, 5));  // 除法
    }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 351 "l25.y"
    {
        Symbol* sym = symtab.findSymbol((yyvsp[(1) - (1)].id));
        if(!sym) {
            fprintf(stderr, "Undefined Variable: %s\n", (yyvsp[(1) - (1)].id));
            exit(1);
        }
        code.push_back(Instruction(lod, sym->level, sym->address));
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 359 "l25.y"
    { printf("Struct member access: %s.%s\n", (yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id)); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 361 "l25.y"
    {
        Symbol* sym = symtab.findSymbol((yyvsp[(1) - (4)].id));
        if (!sym) {
            fprintf(stderr, "未定义的数组变量: %s\n", (yyvsp[(1) - (4)].id));
            exit(1);
        }
        if (sym->kind != SymbolKind::ARRAY) {
            fprintf(stderr, "变量 %s 不是数组类型\n", (yyvsp[(1) - (4)].id));
            exit(1);
        }
        // 生成数组访问的 p-code
        // expr 的结果已经在栈顶
        // 加载数组基地址
        code.push_back(Instruction(lit, 0, sym->address));
        // 加上索引
        code.push_back(Instruction(opr, 0, 2));
        // 加载数组元素的值
        code.push_back(Instruction(ind, 0, 0));
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 381 "l25.y"
    {
        code.push_back(Instruction(lit, 0, (yyvsp[(1) - (1)].num)));
    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 390 "l25.y"
    {
        symtab.enterScope();
        symtab.resetAddress();
        code.push_back(Instruction(ini, 0, 0));  // 临时，地址数稍后回填
        blockStartIndex = code.size() - 1;
    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 398 "l25.y"
    {
        int localSize = symtab.getCurrentOffset(); // 获取当前作用域变量个数
        code[blockStartIndex].a = localSize;
        symtab.leaveScope();
    }
    break;


/* Line 1792 of yacc.c  */
#line 1946 "l25.tab.cpp"
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 405 "l25.y"

extern FILE *yyin;  // 声明 Flex 的输入流变量

void yyerror(const char *s) {
    fprintf(stderr, "error: %s\n", s);
}

std::string getFctName(Fct f) {
    switch (f) {
        case lit: return "lit";
        case opr: return "opr";
        case lod: return "lod";
        case sto: return "sto";
        case cal: return "cal";
        case ini: return "ini";
        case jmp: return "jmp";
        case jpc: return "jpc";
        case ind: return "ind";
        case stoi: return "stoi";
        default: return "???";
    }
}

void outputCodeToFile(const std::vector<Instruction>& code) {
    for (size_t i = 0; i < code.size(); ++i) {
        const Instruction& instr = code[i];
        printf("%s %d %d\n", getFctName(instr.f).c_str(), instr.l, instr.a);
    }
}

int main(int argc, char **argv) {
    FILE *input = fopen("test.l25", "r");   // 输入文件
    if (!input) {
        perror("打开输入文件失败");
        return 1;
    }

    yyin = input; // 设置 Flex 输入流

    FILE *output = freopen("p-code.txt", "w", stdout);  // 重定向 stdout 到文件
    if (!output) {
        perror("打开输出文件失败");
        return 1;
    }
    code.push_back(Instruction(jmp, 0, 0));
    yyparse();  // 解析开始
    outputCodeToFile(code);
    VM vm(code);
    std::ofstream fout("fout.txt");
    vm.interpret(fout);
    fclose(input);
    fclose(output);
    std::ofstream symout("symtable.txt");
    symtab.dump(symout);
    return 0;
}