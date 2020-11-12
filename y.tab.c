/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "uccompiler.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structures.h"
#include "functions.h"

program * myprogram, * aux, * aux2;
bool is_error = false;
int i;

int yylex (void);
void yyerror(const char* s);
char string[999], type_string[10];


#line 88 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CHAR = 258,
    RESERVED = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    INT = 263,
    SHORT = 264,
    DOUBLE = 265,
    RETURN = 266,
    VOID = 267,
    BITWISEAND = 268,
    BITWISEOR = 269,
    BITWISEXOR = 270,
    AND = 271,
    ASSIGN = 272,
    MUL = 273,
    COMMA = 274,
    DIV = 275,
    EQ = 276,
    GE = 277,
    GT = 278,
    LBRACE = 279,
    LE = 280,
    LPAR = 281,
    LT = 282,
    MINUS = 283,
    MOD = 284,
    NE = 285,
    NOT = 286,
    OR = 287,
    PLUS = 288,
    RBRACE = 289,
    RPAR = 290,
    SEMI = 291,
    INTLIT = 292,
    ID = 293,
    ILLEGAL = 294,
    CHRLIT = 295,
    REALLIT = 296
  };
#endif
/* Tokens.  */
#define CHAR 258
#define RESERVED 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define INT 263
#define SHORT 264
#define DOUBLE 265
#define RETURN 266
#define VOID 267
#define BITWISEAND 268
#define BITWISEOR 269
#define BITWISEXOR 270
#define AND 271
#define ASSIGN 272
#define MUL 273
#define COMMA 274
#define DIV 275
#define EQ 276
#define GE 277
#define GT 278
#define LBRACE 279
#define LE 280
#define LPAR 281
#define LT 282
#define MINUS 283
#define MOD 284
#define NE 285
#define NOT 286
#define OR 287
#define PLUS 288
#define RBRACE 289
#define RPAR 290
#define SEMI 291
#define INTLIT 292
#define ID 293
#define ILLEGAL 294
#define CHRLIT 295
#define REALLIT 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "uccompiler.y"

    char * terminal;
    char * idTerminal;
    program * nonterminal;

#line 228 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   690

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    86,    86,    89,    90,    91,    92,    93,    94,    97,
     100,   103,   104,   105,   106,   107,   110,   113,   114,   126,
     127,   130,   131,   134,   135,   136,   137,   140,   141,   144,
     147,   166,   167,   170,   173,   174,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "RESERVED", "IF", "ELSE",
  "WHILE", "INT", "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND",
  "BITWISEOR", "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ",
  "GE", "GT", "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT",
  "OR", "PLUS", "RBRACE", "RPAR", "SEMI", "INTLIT", "ID", "ILLEGAL",
  "CHRLIT", "REALLIT", "$accept", "program", "functionsAndDeclarations",
  "functionDefinition", "functionDeclaration", "typeSpec",
  "functionDeclarator", "parameterList", "parameterDeclaration",
  "functionBody", "declarationsAndStatements", "declaration",
  "declaratorsList", "declarator", "id_token", "statementList",
  "statement", "statement_error", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     108,   -28,   -64,   -64,   -64,   -64,   -64,    42,    20,   -64,
     -64,    10,   -64,   -64,   -64,   -64,   -64,   -64,   -64,     7,
     -12,   -64,    58,    95,   -64,   -64,    10,   -64,    13,   678,
      26,    61,   611,   154,    48,    13,    13,    13,   -64,   -64,
     -64,   -64,   -64,    10,   136,   -64,    64,   -64,   255,   -64,
      76,   512,    10,   -10,   -64,    13,    13,   -64,   279,    65,
      71,    82,   627,   192,   -64,   -64,   210,    78,   303,    75,
     351,   -64,   -64,   -64,   -64,   -64,   -64,   226,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   -64,   -64,   678,   -64,
     374,   397,   -64,   -64,    13,    13,   -64,   327,     1,   -64,
     210,    79,    80,   -64,   -64,   -64,    13,   -64,    87,   -64,
     420,   605,   573,   591,   554,   512,   -64,   512,   -64,   651,
     180,   180,   180,   180,    -2,   -64,   651,   533,    -2,   -64,
     210,   210,   443,   466,   -64,   -64,    81,   -64,   -64,   489,
     -64,   -64,   118,   -64,   210,   210,   -64,   -64,   210,   119,
     -64,   -64,   210,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    11,    12,    14,    15,    13,     0,     0,     3,
       4,     0,     5,    28,     1,     6,     7,     8,    33,     0,
       0,    29,    31,     0,    10,     9,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    45,
      83,    84,    85,     0,     0,    24,    82,    23,     0,    30,
      31,    32,    19,     0,    17,     0,     0,    43,     0,     0,
       0,     0,     0,     0,    38,    57,     0,    34,     0,     0,
       0,    78,    79,    77,    22,    26,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    20,     0,    16,
       0,     0,    42,    46,     0,     0,    55,     0,     0,    50,
       0,    34,    35,    37,    56,    88,     0,    86,     0,    80,
       0,    68,    69,    70,    67,    58,    63,    59,    64,    71,
      74,    76,    73,    75,    62,    65,    72,    66,    61,    18,
       0,     0,     0,     0,    54,    47,    35,    49,    36,    59,
      87,    81,    40,    41,     0,     0,    48,    60,     0,    52,
      53,    39,     0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   122,   126,   -18,   -64,   -64,    29,   -64,
     -64,    -6,   -64,   112,    -7,    77,    98,   -63,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    19,    53,    54,    25,
      44,    12,    20,    21,    46,    66,    47,    67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,    48,    17,   112,    22,    43,    51,    26,    13,    98,
      58,    52,    70,    71,    72,    73,    83,    45,    85,    50,
      -2,     1,    48,     2,    27,    99,    43,    92,     3,     4,
       5,    23,     6,   100,   101,   145,    50,   103,    75,    34,
     107,    35,    14,    24,    36,    97,    37,   146,    18,    69,
      40,    18,    55,    41,    42,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    34,    28,    35,   152,   153,    36,
      52,    37,   142,   143,    29,    40,    18,    56,    41,    42,
      77,   159,   160,    28,   149,   161,     1,   104,     2,   163,
      30,   103,    31,     3,     4,     5,    32,     6,   105,     1,
     115,     2,   113,   147,   148,   156,     3,     4,     5,    33,
       6,    34,   150,    35,   158,   162,    36,   139,    37,    38,
      15,    39,    40,    18,    16,    41,    42,     1,    49,     2,
     110,    30,    76,    31,     3,     4,     5,    32,     6,     0,
       0,     0,     0,     0,     0,    59,     0,     0,     0,    60,
      33,    61,    34,     0,    35,    62,     0,    36,     0,    37,
      74,     0,    39,    40,    18,     0,    41,    42,    63,     0,
      34,     0,    35,     0,     0,    36,     0,    37,    64,     0,
      65,    40,    18,   108,    41,    42,     0,    60,    83,    61,
      85,     0,     0,    62,     0,     0,     0,     0,    91,    92,
       0,    59,     0,    95,     0,    60,    63,    61,    34,     0,
      35,    62,     0,    36,     0,    37,   109,   118,    65,    40,
      18,     0,    41,    42,    63,     0,    34,     0,    35,     0,
       0,    36,     0,    37,     0,     0,    65,    40,    18,     0,
      41,    42,    34,     0,    35,     0,     0,    36,     0,    37,
       0,   119,     0,    40,    18,     0,    41,    42,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
      89,     0,    90,    91,    92,    93,     0,    94,    95,     0,
       0,    96,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,    89,     0,    90,    91,    92,    93,
       0,    94,    95,     0,     0,   102,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,     0,
      90,    91,    92,    93,     0,    94,    95,     0,     0,   114,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,    89,     0,    90,    91,    92,    93,     0,    94,
      95,     0,     0,   144,    78,    79,    80,    81,    82,    83,
     116,    85,    86,    87,    88,     0,    89,     0,    90,    91,
      92,    93,     0,    94,    95,     0,   117,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,    89,
       0,    90,    91,    92,    93,     0,    94,    95,     0,   140,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,    89,     0,    90,    91,    92,    93,     0,    94,
      95,     0,   141,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,    89,     0,    90,    91,    92,
      93,     0,    94,    95,     0,   151,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,     0,
      90,    91,    92,    93,     0,    94,    95,     0,   154,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,    89,     0,    90,    91,    92,    93,     0,    94,    95,
       0,   155,    78,    79,    80,    81,    82,    83,     0,    85,
      86,    87,    88,     0,    89,     0,    90,    91,    92,    93,
       0,    94,    95,     0,   157,    78,    79,    80,    81,    82,
      83,     0,    85,    86,    87,    88,     0,    89,     0,    90,
      91,    92,    93,     0,    94,    95,    78,    79,    80,    81,
       0,    83,     0,    85,    86,    87,    88,     0,    89,     0,
      90,    91,    92,    93,     0,     0,    95,    78,    79,    80,
       0,     0,    83,     0,    85,    86,    87,    88,     0,    89,
       0,    90,    91,    92,    93,     0,    78,    95,    80,     0,
       0,    83,     0,    85,    86,    87,    88,     0,    89,     0,
      90,    91,    92,    93,    78,     0,    95,     0,     0,    83,
       0,    85,    86,    87,    88,     0,    89,     0,    90,    91,
      92,    93,     0,    83,    95,    85,    86,    87,    88,     0,
      89,     0,    90,    91,    92,    93,     0,    34,    95,    35,
       0,     0,    36,     0,    37,     0,     0,    57,    40,    18,
       0,    41,    42,    34,     0,    35,     0,     0,    36,     0,
      37,     0,     0,   106,    40,    18,     0,    41,    42,    83,
       0,    85,     0,    87,    88,     0,    89,     0,    90,    91,
      92,     2,     0,     0,    95,     0,     3,     4,     5,     0,
       6
};

static const yytype_int16 yycheck[] =
{
      63,    23,     8,    66,    11,    23,    28,    19,    36,    19,
      32,    29,    34,    35,    36,    37,    18,    23,    20,    26,
       0,     1,    44,     3,    36,    35,    44,    29,     8,     9,
      10,    24,    12,    55,    56,    34,    43,    36,    44,    26,
      62,    28,     0,    36,    31,    52,    33,   110,    38,     1,
      37,    38,    26,    40,    41,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    26,    17,    28,   140,   141,    31,
      98,    33,   104,   105,    26,    37,    38,    26,    40,    41,
      26,   154,   155,    17,   116,   158,     1,    26,     3,   162,
       5,    36,     7,     8,     9,    10,    11,    12,    26,     1,
      35,     3,    34,    34,    34,    34,     8,     9,    10,    24,
      12,    26,    35,    28,     6,     6,    31,    98,    33,    34,
       8,    36,    37,    38,     8,    40,    41,     1,    26,     3,
      63,     5,    44,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     5,
      24,     7,    26,    -1,    28,    11,    -1,    31,    -1,    33,
      34,    -1,    36,    37,    38,    -1,    40,    41,    24,    -1,
      26,    -1,    28,    -1,    -1,    31,    -1,    33,    34,    -1,
      36,    37,    38,     1,    40,    41,    -1,     5,    18,     7,
      20,    -1,    -1,    11,    -1,    -1,    -1,    -1,    28,    29,
      -1,     1,    -1,    33,    -1,     5,    24,     7,    26,    -1,
      28,    11,    -1,    31,    -1,    33,    34,     1,    36,    37,
      38,    -1,    40,    41,    24,    -1,    26,    -1,    28,    -1,
      -1,    31,    -1,    33,    -1,    -1,    36,    37,    38,    -1,
      40,    41,    26,    -1,    28,    -1,    -1,    31,    -1,    33,
      -1,    35,    -1,    37,    38,    -1,    40,    41,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    32,    33,    -1,
      -1,    36,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    32,    33,    -1,    -1,    36,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    32,    33,    -1,    -1,    36,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    -1,    32,
      33,    -1,    -1,    36,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    -1,    32,    33,    -1,    35,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    -1,    32,    33,    -1,    35,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    -1,    32,
      33,    -1,    35,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    -1,    27,    28,    29,
      30,    -1,    32,    33,    -1,    35,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    32,    33,    -1,    35,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    32,    33,
      -1,    35,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    32,    33,    13,    14,    15,    16,
      -1,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    -1,    33,    13,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    -1,    13,    33,    15,    -1,
      -1,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    13,    -1,    33,    -1,    -1,    18,
      -1,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    -1,    18,    33,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    26,    33,    28,
      -1,    -1,    31,    -1,    33,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    26,    -1,    28,    -1,    -1,    31,    -1,
      33,    -1,    -1,    36,    37,    38,    -1,    40,    41,    18,
      -1,    20,    -1,    22,    23,    -1,    25,    -1,    27,    28,
      29,     3,    -1,    -1,    33,    -1,     8,     9,    10,    -1,
      12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     8,     9,    10,    12,    43,    44,    45,
      46,    47,    53,    36,     0,    45,    46,    53,    38,    48,
      54,    55,    56,    24,    36,    51,    19,    36,    17,    26,
       5,     7,    11,    24,    26,    28,    31,    33,    34,    36,
      37,    40,    41,    47,    52,    53,    56,    58,    60,    55,
      56,    60,    47,    49,    50,    26,    26,    36,    60,     1,
       5,     7,    11,    24,    34,    36,    57,    59,    60,     1,
      60,    60,    60,    60,    34,    53,    58,    26,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    25,
      27,    28,    29,    30,    32,    33,    36,    56,    19,    35,
      60,    60,    36,    36,    26,    26,    36,    60,     1,    34,
      57,    59,    59,    34,    36,    35,    19,    35,     1,    35,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    50,
      35,    35,    60,    60,    36,    34,    59,    34,    34,    60,
      35,    35,    59,    59,    35,    35,    34,    35,     6,    59,
      59,    59,     6,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    44,    44,    45,
      46,    47,    47,    47,    47,    47,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     3,
       3,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       2,     2,     3,     1,     1,     2,     2,     3,     2,     1,
       3,     1,     3,     1,     1,     2,     4,     3,     2,     7,
       5,     5,     3,     2,     2,     1,     2,     3,     4,     3,
       2,     7,     5,     5,     3,     2,     2,     1,     3,     3,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     4,     1,     1,     1,     1,     3,     4,     3
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 86 "uccompiler.y"
                                                                                {printf("programa\n");(yyval.nonterminal) = myprogram = insert_element("Program", (yyvsp[0].nonterminal));}
#line 1619 "y.tab.c"
    break;

  case 3:
#line 89 "uccompiler.y"
                                                                                {printf("funcsNDec\n");(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1625 "y.tab.c"
    break;

  case 4:
#line 90 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1631 "y.tab.c"
    break;

  case 5:
#line 91 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1637 "y.tab.c"
    break;

  case 6:
#line 92 "uccompiler.y"
                                                                                {if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1643 "y.tab.c"
    break;

  case 7:
#line 93 "uccompiler.y"
                                                                                {if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1649 "y.tab.c"
    break;

  case 8:
#line 94 "uccompiler.y"
                                                                                {if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1655 "y.tab.c"
    break;

  case 9:
#line 97 "uccompiler.y"
                                                                                {printf("funcDef\n");(yyvsp[-1].nonterminal)-> next -> next = (yyvsp[0].nonterminal); (yyvsp[-2].nonterminal)-> next = (yyvsp[-1].nonterminal); (yyval.nonterminal) = insert_element("FuncDefinition", (yyvsp[-2].nonterminal));}
#line 1661 "y.tab.c"
    break;

  case 10:
#line 100 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)-> next = (yyvsp[-1].nonterminal); (yyval.nonterminal) = insert_element("FuncDeclaration", (yyvsp[-2].nonterminal));}
#line 1667 "y.tab.c"
    break;

  case 11:
#line 103 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Char", NULL); sprintf(type_string,"Char" );}
#line 1673 "y.tab.c"
    break;

  case 12:
#line 104 "uccompiler.y"
                                                                                {printf("int\n");(yyval.nonterminal) = insert_element("Int", NULL); sprintf(type_string,"Int" );}
#line 1679 "y.tab.c"
    break;

  case 13:
#line 105 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Void", NULL); sprintf(type_string,"Void" );}
#line 1685 "y.tab.c"
    break;

  case 14:
#line 106 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Short", NULL); sprintf(type_string,"Short" );}
#line 1691 "y.tab.c"
    break;

  case 15:
#line 107 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Double", NULL); sprintf(type_string,"Double" );}
#line 1697 "y.tab.c"
    break;

  case 16:
#line 110 "uccompiler.y"
                                                                                      {printf("declarator\n");(yyval.nonterminal) = (yyvsp[-3].nonterminal); (yyval.nonterminal) -> next = (yyvsp[-1].nonterminal);}
#line 1703 "y.tab.c"
    break;

  case 17:
#line 113 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("ParamList", (yyvsp[0].nonterminal)); }
#line 1709 "y.tab.c"
    break;

  case 18:
#line 114 "uccompiler.y"
                                                                                {
                                                                                    aux = (yyvsp[-2].nonterminal)->children;
                                                                                    while(aux->next){
                                                                                        aux=aux->next;
                                                                                    } 
                                                                                    aux -> next = (yyvsp[0].nonterminal); 

                                                                                    (yyval.nonterminal) = (yyvsp[-2].nonterminal);

                                                                                }
#line 1724 "y.tab.c"
    break;

  case 19:
#line 126 "uccompiler.y"
                                                                                {printf("param\n");(yyval.nonterminal) = insert_element("ParamDeclaration", (yyvsp[0].nonterminal));}
#line 1730 "y.tab.c"
    break;

  case 20:
#line 127 "uccompiler.y"
                                                                                {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("ParamDeclaration", (yyvsp[-1].nonterminal));}
#line 1736 "y.tab.c"
    break;

  case 21:
#line 130 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("FuncBody", NULL);}
#line 1742 "y.tab.c"
    break;

  case 22:
#line 131 "uccompiler.y"
                                                                                {printf("funcBody\n");(yyval.nonterminal) = insert_element("FuncBody", (yyvsp[-1].nonterminal));}
#line 1748 "y.tab.c"
    break;

  case 23:
#line 134 "uccompiler.y"
                                                                                {printf("statement\n");(yyval.nonterminal) = (yyvsp[0].nonterminal); aux=(yyvsp[0].nonterminal)->children; printf("%s\n", (yyvsp[0].nonterminal)->type); while(aux){ printf("%s - ", aux->type); aux=aux->next; }         }
#line 1754 "y.tab.c"
    break;

  case 24:
#line 135 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1760 "y.tab.c"
    break;

  case 25:
#line 136 "uccompiler.y"
                                                                                {if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1766 "y.tab.c"
    break;

  case 26:
#line 137 "uccompiler.y"
                                                                                {printf("+declaration\n");if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1772 "y.tab.c"
    break;

  case 27:
#line 140 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1778 "y.tab.c"
    break;

  case 28:
#line 141 "uccompiler.y"
                                                                                 {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true; /*FAZER ERRO*/}
#line 1784 "y.tab.c"
    break;

  case 29:
#line 144 "uccompiler.y"
                                                                                {aux2 = insert_element(strdup(type_string), NULL);
                                                                                    aux2 -> next = (yyvsp[0].nonterminal);
                                                                                    (yyval.nonterminal) = insert_element("Declaration", aux2);}
#line 1792 "y.tab.c"
    break;

  case 30:
#line 147 "uccompiler.y"
                                                                                {
                                                                                    /*INSERIR TIPO*/
                                                                                    aux2 = insert_element(strdup(type_string), NULL);
                                                                                    aux2 -> next = (yyvsp[0].nonterminal);

                                                                                    if(! (yyvsp[-2].nonterminal) -> next) {
                                                                                        (yyvsp[-2].nonterminal) -> next = (yyvsp[0].nonterminal);
                                                                                        (yyvsp[-2].nonterminal)-> next = insert_element("Declaration", aux2);
                                                                                    } else {
                                                                                        aux = (yyvsp[-2].nonterminal) -> next; 
                                                                                        while(aux->next)
                                                                                            aux=aux->next; 
                                                                                            
                                                                                        aux-> next = insert_element("Declaration", aux2);
                                                                                    } 
                                                                                    (yyval.nonterminal) = (yyvsp[-2].nonterminal);
                                                                                    }
#line 1814 "y.tab.c"
    break;

  case 31:
#line 166 "uccompiler.y"
                                                                                      {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1820 "y.tab.c"
    break;

  case 32:
#line 167 "uccompiler.y"
                                                                                      {(yyval.nonterminal) = (yyvsp[-2].nonterminal); (yyval.nonterminal) -> next = (yyvsp[0].nonterminal);}
#line 1826 "y.tab.c"
    break;

  case 33:
#line 170 "uccompiler.y"
                                                                                {sprintf(string, "Id(%s)", yylval.idTerminal); (yyval.nonterminal) = insert_element(strdup(string), NULL);}
#line 1832 "y.tab.c"
    break;

  case 34:
#line 173 "uccompiler.y"
                                                                                      {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1838 "y.tab.c"
    break;

  case 35:
#line 174 "uccompiler.y"
                                                                                      {if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1844 "y.tab.c"
    break;

  case 36:
#line 177 "uccompiler.y"
                                                                                {if(! (yyvsp[-2].nonterminal) -> next) {(yyvsp[-2].nonterminal) -> next = (yyvsp[-1].nonterminal);} else {aux =(yyvsp[-2].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[-1].nonterminal);} i=0; aux = (yyvsp[-2].nonterminal); while(aux){if(strcmp(aux->type, "Semi") != 0) i++; aux = aux->next;}   if(i>=2) (yyval.nonterminal) = insert_element("StatList", (yyvsp[-2].nonterminal)); else (yyval.nonterminal) = (yyvsp[-2].nonterminal);}
#line 1850 "y.tab.c"
    break;

  case 37:
#line 178 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1856 "y.tab.c"
    break;

  case 38:
#line 179 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Semi", NULL); /*insert_element("Null", NULL);*/}
#line 1862 "y.tab.c"
    break;

  case 39:
#line 180 "uccompiler.y"
                                                                                {if((yyvsp[-2].nonterminal) && strcmp((yyvsp[-2].nonterminal) -> type, "Semi") != 0){ (yyvsp[-4].nonterminal) -> next = (yyvsp[-2].nonterminal); } else { (yyvsp[-4].nonterminal) -> next = insert_element("Null", NULL); free((yyvsp[-2].nonterminal));} if((yyvsp[0].nonterminal) && strcmp((yyvsp[0].nonterminal) -> type, "Semi") != 0){ (yyvsp[-4].nonterminal) -> next -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-4].nonterminal) -> next -> next = insert_element("Null", NULL); free((yyvsp[0].nonterminal));} (yyval.nonterminal) = insert_element("If", (yyvsp[-4].nonterminal));}
#line 1868 "y.tab.c"
    break;

  case 40:
#line 181 "uccompiler.y"
                                                                                {if((yyvsp[0].nonterminal) && strcmp((yyvsp[0].nonterminal) -> type, "Semi") != 0){ (yyvsp[-2].nonterminal) -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-2].nonterminal) -> next = insert_element("Null", NULL); free((yyvsp[0].nonterminal));} (yyvsp[-2].nonterminal) -> next -> next = insert_element("Null", NULL); (yyval.nonterminal) = insert_element("If", (yyvsp[-2].nonterminal));}
#line 1874 "y.tab.c"
    break;

  case 41:
#line 182 "uccompiler.y"
                                                                                {if((yyvsp[0].nonterminal) && strcmp((yyvsp[0].nonterminal) -> type, "Semi") != 0){ (yyvsp[-2].nonterminal) -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-2].nonterminal) -> next = insert_element("Null", NULL); free((yyvsp[0].nonterminal));} (yyval.nonterminal) = insert_element("While", (yyvsp[-2].nonterminal));}
#line 1880 "y.tab.c"
    break;

  case 42:
#line 183 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Return", (yyvsp[-1].nonterminal));}
#line 1886 "y.tab.c"
    break;

  case 43:
#line 184 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Return", insert_element("Null", NULL));}
#line 1892 "y.tab.c"
    break;

  case 44:
#line 185 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1898 "y.tab.c"
    break;

  case 45:
#line 186 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Semi", NULL);}
#line 1904 "y.tab.c"
    break;

  case 46:
#line 189 "uccompiler.y"
                                                                              {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true; /*ERRO*/ }
#line 1910 "y.tab.c"
    break;

  case 47:
#line 190 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true; /* ERRO*/ }
#line 1916 "y.tab.c"
    break;

  case 48:
#line 191 "uccompiler.y"
                                                                                {if(! (yyvsp[-2].nonterminal) -> next) {(yyvsp[-2].nonterminal) -> next = (yyvsp[-1].nonterminal);} else {aux =(yyvsp[-2].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[-1].nonterminal);} i=0; aux = (yyvsp[-2].nonterminal); while(aux){if(strcmp(aux->type, "Semi") != 0) i++; aux = aux->next;}   if(i>=2) (yyval.nonterminal) = insert_element("StatList", (yyvsp[-2].nonterminal)); else (yyval.nonterminal) = (yyvsp[-2].nonterminal);}
#line 1922 "y.tab.c"
    break;

  case 49:
#line 192 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1928 "y.tab.c"
    break;

  case 50:
#line 193 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Semi", NULL); /*insert_element("Null", NULL);*/}
#line 1934 "y.tab.c"
    break;

  case 51:
#line 194 "uccompiler.y"
                                                                                {if((yyvsp[-2].nonterminal) && strcmp((yyvsp[-2].nonterminal) -> type, "Semi") != 0){ (yyvsp[-4].nonterminal) -> next = (yyvsp[-2].nonterminal); } else { (yyvsp[-4].nonterminal) -> next = insert_element("Null", NULL); free((yyvsp[-2].nonterminal));} if((yyvsp[0].nonterminal) && strcmp((yyvsp[0].nonterminal) -> type, "Semi") != 0){ (yyvsp[-4].nonterminal) -> next -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-4].nonterminal) -> next -> next = insert_element("Null", NULL); free((yyvsp[0].nonterminal));} (yyval.nonterminal) = insert_element("If", (yyvsp[-4].nonterminal));}
#line 1940 "y.tab.c"
    break;

  case 52:
#line 195 "uccompiler.y"
                                                                                {if((yyvsp[0].nonterminal) && strcmp((yyvsp[0].nonterminal) -> type, "Semi") != 0){ (yyvsp[-2].nonterminal) -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-2].nonterminal) -> next = insert_element("Null", NULL); free((yyvsp[0].nonterminal));} (yyvsp[-2].nonterminal) -> next -> next = insert_element("Null", NULL); (yyval.nonterminal) = insert_element("If", (yyvsp[-2].nonterminal));}
#line 1946 "y.tab.c"
    break;

  case 53:
#line 196 "uccompiler.y"
                                                                                {if((yyvsp[0].nonterminal) && strcmp((yyvsp[0].nonterminal) -> type, "Semi") != 0){ (yyvsp[-2].nonterminal) -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-2].nonterminal) -> next = insert_element("Null", NULL); free((yyvsp[0].nonterminal));} (yyval.nonterminal) = insert_element("While", (yyvsp[-2].nonterminal));}
#line 1952 "y.tab.c"
    break;

  case 54:
#line 197 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Return", (yyvsp[-1].nonterminal));}
#line 1958 "y.tab.c"
    break;

  case 55:
#line 198 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Return", insert_element("Null", NULL));}
#line 1964 "y.tab.c"
    break;

  case 56:
#line 199 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1970 "y.tab.c"
    break;

  case 57:
#line 200 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Semi", NULL);}
#line 1976 "y.tab.c"
    break;

  case 58:
#line 203 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Store", (yyvsp[-2].nonterminal));}
#line 1982 "y.tab.c"
    break;

  case 59:
#line 204 "uccompiler.y"
                                                                                {aux = (yyvsp[-2].nonterminal); while(aux->next) aux=aux->next; aux->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Comma", (yyvsp[-2].nonterminal));}
#line 1988 "y.tab.c"
    break;

  case 60:
#line 205 "uccompiler.y"
                                                                                {aux = (yyvsp[-3].nonterminal); while(aux->next) aux=aux->next; aux->next = (yyvsp[-1].nonterminal); (yyval.nonterminal) = insert_element("RealComma", (yyvsp[-3].nonterminal));}
#line 1994 "y.tab.c"
    break;

  case 61:
#line 206 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Add", (yyvsp[-2].nonterminal));}
#line 2000 "y.tab.c"
    break;

  case 62:
#line 207 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Sub", (yyvsp[-2].nonterminal));}
#line 2006 "y.tab.c"
    break;

  case 63:
#line 208 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Mul", (yyvsp[-2].nonterminal));}
#line 2012 "y.tab.c"
    break;

  case 64:
#line 209 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Div", (yyvsp[-2].nonterminal));}
#line 2018 "y.tab.c"
    break;

  case 65:
#line 210 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Mod", (yyvsp[-2].nonterminal));}
#line 2024 "y.tab.c"
    break;

  case 66:
#line 211 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Or", (yyvsp[-2].nonterminal));}
#line 2030 "y.tab.c"
    break;

  case 67:
#line 212 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("And", (yyvsp[-2].nonterminal));}
#line 2036 "y.tab.c"
    break;

  case 68:
#line 213 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("BitWiseAnd", (yyvsp[-2].nonterminal));}
#line 2042 "y.tab.c"
    break;

  case 69:
#line 214 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("BitWiseOr", (yyvsp[-2].nonterminal));}
#line 2048 "y.tab.c"
    break;

  case 70:
#line 215 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("BitWiseXor", (yyvsp[-2].nonterminal));}
#line 2054 "y.tab.c"
    break;

  case 71:
#line 216 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Eq", (yyvsp[-2].nonterminal));}
#line 2060 "y.tab.c"
    break;

  case 72:
#line 217 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Ne", (yyvsp[-2].nonterminal));}
#line 2066 "y.tab.c"
    break;

  case 73:
#line 218 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Le", (yyvsp[-2].nonterminal));}
#line 2072 "y.tab.c"
    break;

  case 74:
#line 219 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Ge", (yyvsp[-2].nonterminal));}
#line 2078 "y.tab.c"
    break;

  case 75:
#line 220 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Lt", (yyvsp[-2].nonterminal));}
#line 2084 "y.tab.c"
    break;

  case 76:
#line 221 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("Gt", (yyvsp[-2].nonterminal));}
#line 2090 "y.tab.c"
    break;

  case 77:
#line 222 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Plus", (yyvsp[0].nonterminal));}
#line 2096 "y.tab.c"
    break;

  case 78:
#line 223 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Minus", (yyvsp[0].nonterminal));}
#line 2102 "y.tab.c"
    break;

  case 79:
#line 224 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Not", (yyvsp[0].nonterminal));}
#line 2108 "y.tab.c"
    break;

  case 80:
#line 225 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Call", (yyvsp[-2].nonterminal));}
#line 2114 "y.tab.c"
    break;

  case 81:
#line 226 "uccompiler.y"
                                                                                {(yyvsp[-3].nonterminal) -> next = children_to_brother((yyvsp[-1].nonterminal)); (yyval.nonterminal) = insert_element("Call", (yyvsp[-3].nonterminal));}
#line 2120 "y.tab.c"
    break;

  case 82:
#line 227 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 2126 "y.tab.c"
    break;

  case 83:
#line 228 "uccompiler.y"
                                                                                {sprintf(string, "IntLit(%s)", yylval.terminal); (yyval.nonterminal) = insert_element(strdup(string), NULL);}
#line 2132 "y.tab.c"
    break;

  case 84:
#line 229 "uccompiler.y"
                                                                                {sprintf(string, "ChrLit(%s)", yylval.terminal); (yyval.nonterminal) = insert_element(strdup(string), NULL);}
#line 2138 "y.tab.c"
    break;

  case 85:
#line 230 "uccompiler.y"
                                                                                {sprintf(string, "RealLit(%s)", yylval.terminal); (yyval.nonterminal) = insert_element(strdup(string), NULL);}
#line 2144 "y.tab.c"
    break;

  case 86:
#line 231 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2150 "y.tab.c"
    break;

  case 87:
#line 232 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true; /* ERRO */}
#line 2156 "y.tab.c"
    break;

  case 88:
#line 233 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true;  /* ERRO */ }
#line 2162 "y.tab.c"
    break;


#line 2166 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 236 "uccompiler.y"



