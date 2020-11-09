%{
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "functions.c"

program * myprogram;
int yylex (void);
void yyerror(char* s);

%}

%token <terminal> CHAR
%token <terminal> IF
%token <terminal> ELSE
%token <terminal> WHILE
%token <terminal> INT
%token <terminal> SHORT
%token <terminal> DOUBLE
%token <terminal> RETURN
%token <terminal> VOID
%token <terminal> BITWISEAND
%token <terminal> BITWISEOR
%token <terminal> BITWISEXOR
%token <terminal> AND
%token <terminal> ASSIGN
%token <terminal> MUL
%token <terminal> COMMA
%token <terminal> DIV
%token <terminal> EQ
%token <terminal> GE
%token <terminal> GT
%token <terminal> LBRACE
%token <terminal> LE
%token <terminal> LPAR
%token <terminal> LT
%token <terminal> MINUS
%token <terminal> MOD
%token <terminal> NE
%token <terminal> NOT
%token <terminal> OR
%token <terminal> PLUS
%token <terminal> RBRACE
%token <terminal> RPAR
%token <terminal> SEMI
%token <terminal> INTLIT
%token <terminal> ID
%token <terminal> CHRLIT
%token <terminal> REALLIT

%type <nonterminal> functionsAndDeclarations functionDefinition functionDeclaration typeSpec functionDeclarator
%type <nonterminal> parameterList parameterDeclaration functionBody declarationsAndStatements declaration
%type <nonterminal> declaratorsList declarator statementList statement expr program
 
%union{
    char * terminal;
    program * nonterminal;
}
    // associatividades

%left COMMA
%right ASSIGN
%left OR AND BITWISEOR BITWISEXOR BITWISEAND EQ NE GE GT LE LT PLUS MINUS MUL DIV MOD
%right NOT
%left LPAR RPAR
%right ELSE

%%

program: functionsAndDeclarations                                               {$$ = myprogram = insert_element("Program", $1);}
        ;

functionsAndDeclarations: functionDefinition                                    {$$ = insert_element("FuncDefinition", $1);}
                        | functionDeclaration                                   {$$ = insert_element("FuncDeclaration", $1);}
                        | declaration                                           {$$ = insert_element("Declaration", $1);}
                        | functionsAndDeclarations functionDefinition           {$1 -> next = $2;}
                        | functionsAndDeclarations functionDeclaration          {$1 -> next = $2;}
                        | functionsAndDeclarations declaration                  {$1 -> next = $2;}
                        ;

functionDefinition: typeSpec functionDeclarator functionBody                    {;}
                    ;
                    
functionDeclaration: typeSpec functionDeclarator SEMI                           {;}
                    ;

typeSpec: CHAR                                                                  {;}
        | INT                                                                   {;}
        | VOID                                                                  {;}
        | SHORT                                                                 {;}
        | DOUBLE                                                                {;}
        ;

functionDeclarator: ID LPAR parameterList RPAR                                  {;}
                    ;
                    
parameterList: parameterDeclaration                                             {;}
            | parameterList COMMA parameterDeclaration                          {;}
            ;

parameterDeclaration: typeSpec                                                  {;}
                    | typeSpec ID                                               {;}
                    ;

functionBody: LBRACE RBRACE                                                     {;}
            | LBRACE declarationsAndStatements RBRACE                           {;}
            ;

declarationsAndStatements: statement                                            {;}
                        |  declaration                                          {;}
                        |  declarationsAndStatements statement                  {;}
                        |  declarationsAndStatements declaration                {;}
                        ;

declaration: typeSpec declaratorsList SEMI                                       {;}
            ;

declaratorsList: declarator                                                     {;}   
                | declaratorsList COMMA declarator                              {;}
                |                                                               {;}
                ;

declarator: ID                                                                  {;}
        |   ID ASSIGN expr                                                      {;}
        ;

statementList: statement                                                        {;}
            |  statementList statement                                          {$1-> next = $2; $$ = insert_element("Statementlist", $1);}   
            ;

statement: LBRACE statementList RBRACE                                          {;}
        |  LBRACE RBRACE                                                        {;}
        |  IF LPAR expr RPAR statement ELSE statement                           {;}
        |  IF LPAR expr RPAR statement                                          {$3-> next = $5; $$ = insert_element("IF", $3) ;}
        |  WHILE LPAR expr RPAR statement                                       {;}
        |  RETURN expr SEMI                                                     {;}
        |  RETURN SEMI                                                          {;}
        |  expr SEMI                                                            {;}       
        |  SEMI                                                                 {;}                              
        ;

expr:   expr ASSIGN expr                                                        {;}
    |                                                             {;}
    |   expr PLUS expr                                                          {;}
    |   expr MINUS expr                                                         {;}
    |   expr MUL expr                                                           {;}
    |   expr DIV expr                                                           {;}
    |   expr MOD expr                                                           {;}
    |   expr OR expr                                                            {;}
    |   expr AND expr                                                           {;}
    |   expr BITWISEAND expr                                                    {;}
    |   expr BITWISEOR expr                                                     {;}
    |   expr BITWISEXOR expr                                                    {;}
    |   expr EQ expr                                                            {;}
    |   expr NE expr                                                            {;}
    |   expr LE expr                                                            {;}
    |   expr GE expr                                                            {;}
    |   expr LT expr                                                            {;}
    |   expr GT expr                                                            {;}
    |   PLUS expr                                                               {;}
    |   MINUS expr                                                              {;}
    |   NOT expr                                                                {;}
    |   ID LPAR RPAR                                                            {;}
    |   ID LPAR expr RPAR                                                       {;}
    |   ID LPAR expr COMMA expr RPAR                                            {;}
    |   ID                                                                      {;}
    |   INTLIT                                                                  {;}
    |   CHRLIT                                                                  {;}
    |   REALLIT                                                                 {;}
    |   LPAR expr RPAR                                                          {;}
    ; 

%%

void yyerror(char *msg) {
    printf("%s\n", msg);
}

