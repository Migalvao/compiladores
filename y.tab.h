/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 61 "uccompiler.y"

    char * terminal;
    char * idTerminal;
    program * nonterminal;

#line 145 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
