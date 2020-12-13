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
char type_string[10];


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
    ELSE = 259,
    WHILE = 260,
    IF = 261,
    INT = 262,
    SHORT = 263,
    DOUBLE = 264,
    RETURN = 265,
    VOID = 266,
    BITWISEAND = 267,
    BITWISEOR = 268,
    BITWISEXOR = 269,
    AND = 270,
    ASSIGN = 271,
    MUL = 272,
    COMMA = 273,
    DIV = 274,
    EQ = 275,
    GE = 276,
    GT = 277,
    LBRACE = 278,
    LE = 279,
    LPAR = 280,
    LT = 281,
    MINUS = 282,
    MOD = 283,
    NE = 284,
    NOT = 285,
    OR = 286,
    PLUS = 287,
    RBRACE = 288,
    RPAR = 289,
    SEMI = 290,
    RESERVED = 291,
    CHRLIT = 292,
    REALLIT = 293,
    INTLIT = 294,
    ID = 295
  };
#endif
/* Tokens.  */
#define CHAR 258
#define ELSE 259
#define WHILE 260
#define IF 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define RESERVED 291
#define CHRLIT 292
#define REALLIT 293
#define INTLIT 294
#define ID 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "uccompiler.y"

    char * terminal;
    char * idTerminal;
    program * nonterminal;

#line 226 "y.tab.c"

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
#define YYLAST   650

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    58,    59,    60,    61,    62,    63,    66,
      69,    72,    73,    74,    75,    76,    79,    82,    83,    95,
      96,    99,   100,   103,   104,   105,   106,   109,   110,   113,
     116,   135,   136,   139,   142,   143,   156,   157,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   187,   188,   192,
     195,   198,   201,   204,   207,   210,   213,   216,   219,   222,
     225,   228,   231,   234,   237,   240,   243,   246,   249,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "WHILE", "IF", "INT",
  "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "SEMI", "RESERVED", "CHRLIT", "REALLIT", "INTLIT",
  "ID", "$accept", "program", "functionsAndDeclarations",
  "functionDefinition", "functionDeclaration", "typeSpec",
  "functionDeclarator", "parameterList", "parameterDeclaration",
  "functionBody", "declarationsAndStatements", "declaration",
  "declaratorsList", "declarator", "id_token", "statementList",
  "statement", "statement_error", "return_token", "plus_token",
  "minus_token", "mul_token", "div_token", "mod_token", "or_token",
  "and_token", "bitwiseand_token", "bitwiseor_token", "bitwisexor_token",
  "eq_token", "ne_token", "le_token", "ge_token", "lt_token", "gt_token",
  "assign_token", "not_token", "comma_token", "expr", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,   -29,   -53,   -53,   -53,   -53,   -53,     7,   263,   -53,
     -53,   -26,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -15,
     -17,   -53,    17,   210,   -53,   -53,   -26,   -53,   610,    37,
       2,     4,   -53,   150,   307,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -26,   250,   -53,     9,   -53,   105,   610,
     610,   610,   336,   -53,    21,   499,   -26,    -9,   -53,   610,
     610,   -22,   -53,   290,   -53,     8,    23,   384,   -53,   -53,
     -53,   267,   -53,   360,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   -53,    37,   -53,   407,   430,   -53,   -53,    16,
      10,   -53,   -53,   -53,   610,    24,   -53,   453,   -53,    11,
      11,   -53,   -53,   -53,   520,   541,   592,   560,   578,   606,
     606,    33,    33,    33,    33,   499,   499,   -53,   290,   290,
     -53,   476,   -53,   -53,   -53,    55,   -53,   290,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    11,    12,    14,    15,    13,     0,     0,     3,
       4,     0,     5,    28,     1,     6,     7,     8,    33,     0,
       0,    29,    31,     0,    10,     9,     0,    27,     0,     0,
       0,     0,    49,     0,     0,    51,    67,    50,    21,    46,
      95,    96,    94,     0,     0,    24,    93,    23,     0,     0,
       0,     0,     0,    30,    31,    32,    19,     0,    17,     0,
       0,     0,    39,     0,    47,    34,     0,     0,    22,    26,
      25,     0,    44,     0,    88,    89,    90,    57,    58,    59,
      56,    66,    52,    68,    53,    60,    63,    65,    62,    64,
      54,    61,    55,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,    16,     0,     0,    36,    48,     0,
      35,    38,    99,    97,     0,     0,    91,     0,    43,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    69,    70,    18,     0,     0,
      37,    70,    98,    92,    42,    41,    71,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,    54,    59,   -13,   -53,   -53,   -44,   -53,
     -53,    -6,   -53,    44,    -7,   -53,   -18,   -51,   -53,   -52,
     -20,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,    34,    99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    19,    57,    58,    25,
      44,    12,    20,    21,    46,    63,    64,    65,    48,    49,
      50,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    51,   111,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      94,    26,    17,    94,    22,    47,    13,    14,    23,   113,
      43,   117,   120,   118,    18,    94,    56,    45,    27,    54,
      24,    94,    94,    94,    94,   114,    70,    59,    82,    60,
      84,    43,    95,    28,    71,    95,    54,    28,    69,    90,
       2,   121,    29,   150,     3,     4,     5,    95,     6,   112,
      82,   118,    84,    95,    95,    95,    95,   122,   152,   157,
      35,    90,    15,    94,    94,    37,     1,    16,     2,   147,
      53,     0,     3,     4,     5,    94,     6,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,   154,   155,    94,
      56,   124,     0,     0,     0,     0,   158,    95,     0,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    55,     0,     0,
      34,    95,    35,    67,     0,    36,     0,    37,     0,     0,
      72,     0,    40,    41,    42,    18,     0,    73,    74,    75,
      76,    61,     0,     0,     0,    30,    31,     0,   115,   116,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,     0,    33,     0,    34,     0,    35,     0,     0,
      36,     0,    37,    62,     0,    39,     0,    40,    41,    42,
      18,     0,     0,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     1,     0,     2,     0,    30,    31,     3,     4,     5,
      32,     6,     0,   151,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,    34,     0,    35,     0,     0,
      36,     0,    37,    38,     0,    39,     0,    40,    41,    42,
      18,     1,     0,     2,     0,    30,    31,     3,     4,     5,
      32,     6,     0,    -2,     1,     0,     2,     0,   125,     0,
       3,     4,     5,    33,     6,    34,     0,    35,     0,     0,
      36,     0,    37,    68,     0,    39,     0,    40,    41,    42,
      18,   119,    34,     0,    35,    30,    31,    36,     0,    37,
      32,   126,     0,     0,    40,    41,    42,    18,    66,     0,
       0,     0,     0,    33,     0,    34,     0,    35,     0,     0,
      36,     0,    37,     0,     0,    39,     0,    40,    41,    42,
      18,     0,    34,     0,    35,     0,     0,    36,     0,    37,
       0,     0,     0,     0,    40,    41,    42,    18,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
      88,     0,    89,    35,    90,    91,     0,    92,    37,     0,
       0,    93,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,    88,     0,    89,    35,    90,    91,
       0,    92,    37,     0,     0,   128,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,    88,     0,
      89,    35,    90,    91,     0,    92,    37,     0,   123,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    88,     0,    89,    35,    90,    91,     0,    92,    37,
       0,   148,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,    88,     0,    89,    35,    90,    91,
       0,    92,    37,     0,   149,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,    88,     0,    89,
      35,    90,    91,     0,    92,    37,     0,   153,    77,    78,
      79,    80,    81,    82,     0,    84,    85,    86,    87,     0,
      88,     0,    89,    35,    90,    91,     0,    92,    37,     0,
     156,    77,    78,    79,    80,    81,    82,     0,    84,    85,
      86,    87,     0,    88,     0,    89,    35,    90,    91,     0,
      92,    37,    77,    78,    79,    80,     0,    82,     0,    84,
      85,    86,    87,     0,    88,     0,    89,    35,    90,    91,
       0,     0,    37,    77,    78,    79,     0,     0,    82,     0,
      84,    85,    86,    87,     0,    88,     0,    89,    35,    90,
      91,     0,    77,    37,    79,     0,     0,    82,     0,    84,
      85,    86,    87,     0,    88,     0,    89,    35,    90,    91,
      77,     0,    37,     0,     0,    82,     0,    84,    85,    86,
      87,     0,    88,     0,    89,    35,    90,    91,     0,    82,
      37,    84,    85,    86,    87,     0,    88,     0,    89,    35,
      90,    91,     0,    82,    37,    84,     0,    86,    87,     0,
      88,     0,    89,    35,    90,    34,     0,    35,    37,     0,
      36,     0,    37,     0,     0,     0,     0,    40,    41,    42,
      18
};

static const yytype_int16 yycheck[] =
{
      52,    18,     8,    55,    11,    23,    35,     0,    23,    18,
      23,    33,    63,    35,    40,    67,    29,    23,    35,    26,
      35,    73,    74,    75,    76,    34,    44,    25,    17,    25,
      19,    44,    52,    16,    25,    55,    43,    16,    44,    28,
       3,    33,    25,    33,     7,     8,     9,    67,    11,    56,
      17,    35,    19,    73,    74,    75,    76,    34,    34,     4,
      27,    28,     8,   115,   116,    32,     1,     8,     3,   113,
      26,    -1,     7,     8,     9,   127,    11,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   115,   116,   148,   149,   151,
     113,    67,    -1,    -1,    -1,    -1,   157,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    28,    -1,    -1,
      25,   151,    27,    34,    -1,    30,    -1,    32,    -1,    -1,
      35,    -1,    37,    38,    39,    40,    -1,    48,    49,    50,
      51,     1,    -1,    -1,    -1,     5,     6,    -1,    59,    60,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    32,    33,    -1,    35,    -1,    37,    38,    39,
      40,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    32,    33,    -1,    35,    -1,    37,    38,    39,
      40,     1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    -1,     0,     1,    -1,     3,    -1,     1,    -1,
       7,     8,     9,    23,    11,    25,    -1,    27,    -1,    -1,
      30,    -1,    32,    33,    -1,    35,    -1,    37,    38,    39,
      40,     1,    25,    -1,    27,     5,     6,    30,    -1,    32,
      10,    34,    -1,    -1,    37,    38,    39,    40,     1,    -1,
      -1,    -1,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    32,    -1,    -1,    35,    -1,    37,    38,    39,
      40,    -1,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    35,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    -1,    -1,    35,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    -1,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    -1,    34,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    31,    32,    -1,    34,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      34,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    -1,
      31,    32,    12,    13,    14,    15,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    12,    13,    14,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    12,    32,    14,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      12,    -1,    32,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    17,
      32,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    17,    32,    19,    -1,    21,    22,    -1,
      24,    -1,    26,    27,    28,    25,    -1,    27,    32,    -1,
      30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    42,    43,    44,
      45,    46,    52,    35,     0,    44,    45,    52,    40,    47,
      53,    54,    55,    23,    35,    50,    18,    35,    16,    25,
       5,     6,    10,    23,    25,    27,    30,    32,    33,    35,
      37,    38,    39,    46,    51,    52,    55,    57,    59,    60,
      61,    77,    79,    54,    55,    79,    46,    48,    49,    25,
      25,     1,    33,    56,    57,    58,     1,    79,    33,    52,
      57,    25,    35,    79,    79,    79,    79,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    24,    26,
      28,    29,    31,    35,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    78,    55,    18,    34,    79,    79,    33,    35,     1,
      58,    33,    34,    34,    78,     1,    34,    79,    35,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    49,    34,    34,
      33,    79,    34,    34,    58,    58,    34,     4,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    44,
      45,    46,    46,    46,    46,    46,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     3,
       3,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       2,     2,     3,     1,     1,     2,     2,     3,     2,     1,
       3,     1,     3,     1,     1,     2,     3,     4,     3,     2,
       7,     5,     5,     3,     2,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     4,     1,     1,     1,     1,     3,     4,     3
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
#line 55 "uccompiler.y"
                                                                                {(yyval.nonterminal) = myprogram = insert_element("Program", (yyvsp[0].nonterminal));}
#line 1617 "y.tab.c"
    break;

  case 3:
#line 58 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1623 "y.tab.c"
    break;

  case 4:
#line 59 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1629 "y.tab.c"
    break;

  case 5:
#line 60 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1635 "y.tab.c"
    break;

  case 6:
#line 61 "uccompiler.y"
                                                                                {if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1641 "y.tab.c"
    break;

  case 7:
#line 62 "uccompiler.y"
                                                                                {if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1647 "y.tab.c"
    break;

  case 8:
#line 63 "uccompiler.y"
                                                                                {if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1653 "y.tab.c"
    break;

  case 9:
#line 66 "uccompiler.y"
                                                                                {(yyvsp[-1].nonterminal)-> next -> next = (yyvsp[0].nonterminal); (yyvsp[-2].nonterminal)-> next = (yyvsp[-1].nonterminal); (yyval.nonterminal) = insert_element("FuncDefinition", (yyvsp[-2].nonterminal));}
#line 1659 "y.tab.c"
    break;

  case 10:
#line 69 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)-> next = (yyvsp[-1].nonterminal); (yyval.nonterminal) = insert_element("FuncDeclaration", (yyvsp[-2].nonterminal));}
#line 1665 "y.tab.c"
    break;

  case 11:
#line 72 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Char", NULL); sprintf(type_string,"Char" );}
#line 1671 "y.tab.c"
    break;

  case 12:
#line 73 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Int", NULL); sprintf(type_string,"Int" );}
#line 1677 "y.tab.c"
    break;

  case 13:
#line 74 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Void", NULL); sprintf(type_string,"Void" );}
#line 1683 "y.tab.c"
    break;

  case 14:
#line 75 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Short", NULL); sprintf(type_string,"Short" );}
#line 1689 "y.tab.c"
    break;

  case 15:
#line 76 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Double", NULL); sprintf(type_string,"Double" );}
#line 1695 "y.tab.c"
    break;

  case 16:
#line 79 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-3].nonterminal); (yyval.nonterminal) -> next = (yyvsp[-1].nonterminal);}
#line 1701 "y.tab.c"
    break;

  case 17:
#line 82 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("ParamList", (yyvsp[0].nonterminal)); }
#line 1707 "y.tab.c"
    break;

  case 18:
#line 83 "uccompiler.y"
                                                                                {
                                                                                    aux = (yyvsp[-2].nonterminal)->children;
                                                                                    while(aux->next){
                                                                                        aux=aux->next;
                                                                                    } 
                                                                                    aux -> next = (yyvsp[0].nonterminal); 

                                                                                    (yyval.nonterminal) = (yyvsp[-2].nonterminal);

                                                                                }
#line 1722 "y.tab.c"
    break;

  case 19:
#line 95 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("ParamDeclaration", (yyvsp[0].nonterminal));}
#line 1728 "y.tab.c"
    break;

  case 20:
#line 96 "uccompiler.y"
                                                                                {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal); (yyval.nonterminal) = insert_element("ParamDeclaration", (yyvsp[-1].nonterminal));}
#line 1734 "y.tab.c"
    break;

  case 21:
#line 99 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("FuncBody", NULL);}
#line 1740 "y.tab.c"
    break;

  case 22:
#line 100 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("FuncBody", (yyvsp[-1].nonterminal));}
#line 1746 "y.tab.c"
    break;

  case 23:
#line 103 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1752 "y.tab.c"
    break;

  case 24:
#line 104 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1758 "y.tab.c"
    break;

  case 25:
#line 105 "uccompiler.y"
                                                                                {if(!(yyvsp[-1].nonterminal)) (yyval.nonterminal) = (yyvsp[0].nonterminal); else { if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal); }}
#line 1764 "y.tab.c"
    break;

  case 26:
#line 106 "uccompiler.y"
                                                                                {if(!(yyvsp[-1].nonterminal)) (yyval.nonterminal) = (yyvsp[0].nonterminal); else { if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal); }}
#line 1770 "y.tab.c"
    break;

  case 27:
#line 109 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1776 "y.tab.c"
    break;

  case 28:
#line 110 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true; /*FAZER ERRO*/}
#line 1782 "y.tab.c"
    break;

  case 29:
#line 113 "uccompiler.y"
                                                                                {aux2 = insert_element(strdup(type_string), NULL);
                                                                                    aux2 -> next = (yyvsp[0].nonterminal);
                                                                                    (yyval.nonterminal) = insert_element("Declaration", aux2);}
#line 1790 "y.tab.c"
    break;

  case 30:
#line 116 "uccompiler.y"
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
#line 1812 "y.tab.c"
    break;

  case 31:
#line 135 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1818 "y.tab.c"
    break;

  case 32:
#line 136 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-2].nonterminal); (yyval.nonterminal) -> next = (yyvsp[0].nonterminal);}
#line 1824 "y.tab.c"
    break;

  case 33:
#line 139 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Id"), insert_element(strdup(yylval.idTerminal), NULL));}
#line 1830 "y.tab.c"
    break;

  case 34:
#line 142 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1836 "y.tab.c"
    break;

  case 35:
#line 143 "uccompiler.y"
                                                                                {
                                                                                    if(!(yyvsp[0].nonterminal)){ 
                                                                                        (yyval.nonterminal) = (yyvsp[-1].nonterminal); 
                                                                                    }  else { 
                                                                                        if(!(yyvsp[-1].nonterminal)) {
                                                                                            (yyval.nonterminal) = (yyvsp[0].nonterminal);
                                                                                        } else {
                                                                                            if(! (yyvsp[-1].nonterminal) -> next) {(yyvsp[-1].nonterminal) -> next = (yyvsp[0].nonterminal);} else {aux =(yyvsp[-1].nonterminal) -> next; while(aux->next)aux=aux->next; aux-> next = (yyvsp[0].nonterminal);  } (yyval.nonterminal) = (yyvsp[-1].nonterminal); 
                                                                                        }
                                                                                    }
                                                                                }
#line 1852 "y.tab.c"
    break;

  case 36:
#line 156 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true; /* ERRO*/ }
#line 1858 "y.tab.c"
    break;

  case 37:
#line 157 "uccompiler.y"
                                                                                {
                                                                                    if(!(yyvsp[-2].nonterminal) && !(yyvsp[-1].nonterminal)){
                                                                                        (yyval.nonterminal) =  NULL;
                                                                                    } else if(!(yyvsp[-2].nonterminal) && (yyvsp[-1].nonterminal)){
                                                                                        (yyval.nonterminal) = (yyvsp[-1].nonterminal);
                                                                                    } else if((yyvsp[-2].nonterminal) && !(yyvsp[-1].nonterminal)){
                                                                                        if((yyvsp[-2].nonterminal) -> next){
                                                                                            (yyval.nonterminal) = insert_element("StatList", (yyvsp[-2].nonterminal));
                                                                                        } else {
                                                                                            (yyval.nonterminal) = (yyvsp[-2].nonterminal);
                                                                                        }
                                                                                    } else if((yyvsp[-2].nonterminal) && (yyvsp[-1].nonterminal)){
                                                                                        aux = (yyvsp[-2].nonterminal);
                                                                                        while(aux->next)
                                                                                            aux = aux->next;
                                                                                        aux -> next = (yyvsp[-1].nonterminal);
                                                                                        (yyval.nonterminal) = insert_element("StatList", (yyvsp[-2].nonterminal));
                                                                                    }
                                                                                }
#line 1882 "y.tab.c"
    break;

  case 38:
#line 176 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1888 "y.tab.c"
    break;

  case 39:
#line 177 "uccompiler.y"
                                                                                {(yyval.nonterminal) = NULL;}
#line 1894 "y.tab.c"
    break;

  case 40:
#line 178 "uccompiler.y"
                                                                                {if((yyvsp[-2].nonterminal)){ (yyvsp[-4].nonterminal) -> next = (yyvsp[-2].nonterminal); } else { (yyvsp[-4].nonterminal) -> next = insert_element("Null", NULL);} if((yyvsp[0].nonterminal)){ (yyvsp[-4].nonterminal) -> next -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-4].nonterminal) -> next -> next = insert_element("Null", NULL);} (yyval.nonterminal) = insert_element("If", (yyvsp[-4].nonterminal));}
#line 1900 "y.tab.c"
    break;

  case 41:
#line 179 "uccompiler.y"
                                                                                {if((yyvsp[0].nonterminal)){ (yyvsp[-2].nonterminal) -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-2].nonterminal) -> next = insert_element("Null", NULL);} (yyvsp[-2].nonterminal) -> next -> next = insert_element("Null", NULL); (yyval.nonterminal) = insert_element("If", (yyvsp[-2].nonterminal));}
#line 1906 "y.tab.c"
    break;

  case 42:
#line 180 "uccompiler.y"
                                                                                {if((yyvsp[0].nonterminal)){ (yyvsp[-2].nonterminal) -> next = (yyvsp[0].nonterminal); } else { (yyvsp[-2].nonterminal) -> next = insert_element("Null", NULL);} (yyval.nonterminal) = insert_element("While", (yyvsp[-2].nonterminal));}
#line 1912 "y.tab.c"
    break;

  case 43:
#line 181 "uccompiler.y"
                                                                                             {(yyvsp[-2].nonterminal)->children = (yyvsp[-1].nonterminal), (yyval.nonterminal) = (yyvsp[-2].nonterminal);}
#line 1918 "y.tab.c"
    break;

  case 44:
#line 182 "uccompiler.y"
                                                                                             {(yyvsp[-1].nonterminal)->children = insert_element("Null", NULL),(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1924 "y.tab.c"
    break;

  case 45:
#line 183 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 1930 "y.tab.c"
    break;

  case 46:
#line 184 "uccompiler.y"
                                                                                {(yyval.nonterminal) = NULL;}
#line 1936 "y.tab.c"
    break;

  case 47:
#line 187 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 1942 "y.tab.c"
    break;

  case 48:
#line 188 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true; /*ERRO*/ }
#line 1948 "y.tab.c"
    break;

  case 49:
#line 192 "uccompiler.y"
                                                                                  {(yyval.nonterminal) = insert_element(strdup("Return"), NULL);}
#line 1954 "y.tab.c"
    break;

  case 50:
#line 195 "uccompiler.y"
                                                                                    {(yyval.nonterminal) = insert_element(strdup("Add"), NULL);}
#line 1960 "y.tab.c"
    break;

  case 51:
#line 198 "uccompiler.y"
                                                                                      {(yyval.nonterminal) = insert_element(strdup("Sub"), NULL);}
#line 1966 "y.tab.c"
    break;

  case 52:
#line 201 "uccompiler.y"
                                                                                  {(yyval.nonterminal) = insert_element(strdup("Mul"), NULL);}
#line 1972 "y.tab.c"
    break;

  case 53:
#line 204 "uccompiler.y"
                                                                                  {(yyval.nonterminal) = insert_element(strdup("Div"), NULL);}
#line 1978 "y.tab.c"
    break;

  case 54:
#line 207 "uccompiler.y"
                                                                                  {(yyval.nonterminal) = insert_element(strdup("Mod"), NULL);}
#line 1984 "y.tab.c"
    break;

  case 55:
#line 210 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Or"), NULL);}
#line 1990 "y.tab.c"
    break;

  case 56:
#line 213 "uccompiler.y"
                                                                                  {(yyval.nonterminal) = insert_element(strdup("And"), NULL);}
#line 1996 "y.tab.c"
    break;

  case 57:
#line 216 "uccompiler.y"
                                                                                                {(yyval.nonterminal) = insert_element(strdup("BitWiseAnd"), NULL);}
#line 2002 "y.tab.c"
    break;

  case 58:
#line 219 "uccompiler.y"
                                                                                              {(yyval.nonterminal) = insert_element(strdup("BitWiseOr"), NULL);}
#line 2008 "y.tab.c"
    break;

  case 59:
#line 222 "uccompiler.y"
                                                                                                {(yyval.nonterminal) = insert_element(strdup("BitWiseXor"), NULL);}
#line 2014 "y.tab.c"
    break;

  case 60:
#line 225 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Eq"), NULL);}
#line 2020 "y.tab.c"
    break;

  case 61:
#line 228 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Ne"), NULL);}
#line 2026 "y.tab.c"
    break;

  case 62:
#line 231 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Le"), NULL);}
#line 2032 "y.tab.c"
    break;

  case 63:
#line 234 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Ge"), NULL);}
#line 2038 "y.tab.c"
    break;

  case 64:
#line 237 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Lt"), NULL);}
#line 2044 "y.tab.c"
    break;

  case 65:
#line 240 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Gt"), NULL);}
#line 2050 "y.tab.c"
    break;

  case 66:
#line 243 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Store"), NULL);}
#line 2056 "y.tab.c"
    break;

  case 67:
#line 246 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Not"), NULL);}
#line 2062 "y.tab.c"
    break;

  case 68:
#line 249 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("Comma"), NULL);}
#line 2068 "y.tab.c"
    break;

  case 69:
#line 252 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2074 "y.tab.c"
    break;

  case 70:
#line 253 "uccompiler.y"
                                                                                {aux = (yyvsp[-2].nonterminal); while(aux->next) aux=aux->next; aux->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2080 "y.tab.c"
    break;

  case 71:
#line 254 "uccompiler.y"
                                                                                {aux = (yyvsp[-3].nonterminal); while(aux->next) aux=aux->next; aux->next = (yyvsp[-1].nonterminal); (yyvsp[-2].nonterminal) -> type = strdup("RealComma"); (yyvsp[-2].nonterminal) -> children = (yyvsp[-3].nonterminal); (yyval.nonterminal) = (yyvsp[-2].nonterminal);}
#line 2086 "y.tab.c"
    break;

  case 72:
#line 255 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2092 "y.tab.c"
    break;

  case 73:
#line 256 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2098 "y.tab.c"
    break;

  case 74:
#line 257 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2104 "y.tab.c"
    break;

  case 75:
#line 258 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2110 "y.tab.c"
    break;

  case 76:
#line 259 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2116 "y.tab.c"
    break;

  case 77:
#line 260 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2122 "y.tab.c"
    break;

  case 78:
#line 261 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2128 "y.tab.c"
    break;

  case 79:
#line 262 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2134 "y.tab.c"
    break;

  case 80:
#line 263 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2140 "y.tab.c"
    break;

  case 81:
#line 264 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2146 "y.tab.c"
    break;

  case 82:
#line 265 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2152 "y.tab.c"
    break;

  case 83:
#line 266 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2158 "y.tab.c"
    break;

  case 84:
#line 267 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2164 "y.tab.c"
    break;

  case 85:
#line 268 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2170 "y.tab.c"
    break;

  case 86:
#line 269 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2176 "y.tab.c"
    break;

  case 87:
#line 270 "uccompiler.y"
                                                                                {(yyvsp[-2].nonterminal)->next = (yyvsp[0].nonterminal); (yyvsp[-1].nonterminal) -> children = (yyvsp[-2].nonterminal); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2182 "y.tab.c"
    break;

  case 88:
#line 271 "uccompiler.y"
                                                                                {(yyvsp[-1].nonterminal) -> children = (yyvsp[0].nonterminal);  (yyvsp[-1].nonterminal) -> type = strdup("Plus"); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2188 "y.tab.c"
    break;

  case 89:
#line 272 "uccompiler.y"
                                                                                {(yyvsp[-1].nonterminal) -> children = (yyvsp[0].nonterminal);  (yyvsp[-1].nonterminal) -> type = strdup("Minus"); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2194 "y.tab.c"
    break;

  case 90:
#line 273 "uccompiler.y"
                                                                                {(yyvsp[-1].nonterminal) -> children = (yyvsp[0].nonterminal);  (yyvsp[-1].nonterminal) -> type = strdup("Not"); (yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2200 "y.tab.c"
    break;

  case 91:
#line 274 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Call", (yyvsp[-2].nonterminal));}
#line 2206 "y.tab.c"
    break;

  case 92:
#line 275 "uccompiler.y"
                                                                                {(yyvsp[-3].nonterminal) -> next = children_to_brother((yyvsp[-1].nonterminal)); (yyval.nonterminal) = insert_element("Call", (yyvsp[-3].nonterminal));}
#line 2212 "y.tab.c"
    break;

  case 93:
#line 276 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[0].nonterminal);}
#line 2218 "y.tab.c"
    break;

  case 94:
#line 277 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("IntLit"), insert_element(strdup(yylval.terminal), NULL));}
#line 2224 "y.tab.c"
    break;

  case 95:
#line 278 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("ChrLit"), insert_element(strdup(yylval.terminal), NULL));}
#line 2230 "y.tab.c"
    break;

  case 96:
#line 279 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element(strdup("RealLit"), insert_element(strdup(yylval.terminal), NULL));}
#line 2236 "y.tab.c"
    break;

  case 97:
#line 280 "uccompiler.y"
                                                                                {(yyval.nonterminal) = (yyvsp[-1].nonterminal);}
#line 2242 "y.tab.c"
    break;

  case 98:
#line 281 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true; /* ERRO */}
#line 2248 "y.tab.c"
    break;

  case 99:
#line 282 "uccompiler.y"
                                                                                {(yyval.nonterminal) = insert_element("Erro", NULL); is_error = true;  /* ERRO */ }
#line 2254 "y.tab.c"
    break;


#line 2258 "y.tab.c"

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
#line 285 "uccompiler.y"



