%{
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "functions.c"

program * myprogram;
int yylex (void);
void yyerror(char* s);
char *string;

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
%left OR
%left AND 
%left BITWISEOR 
%left BITWISEXOR 
%left BITWISEAND 
%left EQ NE 
%left GE GT LE LT 
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%left LPAR RPAR
%right ELSE

%%

program: functionsAndDeclarations                                               {$$ = myprogram = insert_element("Program", $1);}
        ;

functionsAndDeclarations: functionDefinition                                    {$$ = insert_element("FunctionsAndDeclarations", $1);}
                        | functionDeclaration                                   {$$ = insert_element("FunctionsAndDeclarations", $1);}
                        | declaration                                           {$$ = insert_element("FunctionsAndDeclarations", $1);}
                        | functionsAndDeclarations functionDefinition           {$1 -> next = $2;}
                        | functionsAndDeclarations functionDeclaration          {$1 -> next = $2;}
                        | functionsAndDeclarations declaration                  {$1 -> next = $2;}
                        ;

functionDefinition: typeSpec functionDeclarator functionBody                    {$2-> next = $3; $1-> next = $2; $$ = insert_element("FunctionDefinition", $1);}
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

expr:   expr ASSIGN expr                                                        {$1->next = $3; $$ = insert_element("Store", $1);}
    |   expr COMMA expr                                                         {$1->next = $3;}
    |   expr PLUS expr                                                          {$1->next = $3; $$ = insert_element("Add", $1);}
    |   expr MINUS expr                                                         {$1->next = $3; $$ = insert_element("Sub", $1);}
    |   expr MUL expr                                                           {$1->next = $3; $$ = insert_element("Mul", $1);}
    |   expr DIV expr                                                           {$1->next = $3; $$ = insert_element("Div", $1);}
    |   expr MOD expr                                                           {$1->next = $3; $$ = insert_element("Mod", $1);}
    |   expr OR expr                                                            {$1->next = $3; $$ = insert_element("Or", $1);}
    |   expr AND expr                                                           {$1->next = $3; $$ = insert_element("And", $1);}
    |   expr BITWISEAND expr                                                    {$1->next = $3; $$ = insert_element("BitWiseAnd", $1);}
    |   expr BITWISEOR expr                                                     {$1->next = $3; $$ = insert_element("BitWiseOr", $1);}
    |   expr BITWISEXOR expr                                                    {$1->next = $3; $$ = insert_element("BitWiseXor", $1);}
    |   expr EQ expr                                                            {$1->next = $3; $$ = insert_element("Eq", $1);}
    |   expr NE expr                                                            {$1->next = $3; $$ = insert_element("Ne", $1);}
    |   expr LE expr                                                            {$1->next = $3; $$ = insert_element("Le", $1);}
    |   expr GE expr                                                            {$1->next = $3; $$ = insert_element("Ge", $1);}
    |   expr LT expr                                                            {$1->next = $3; $$ = insert_element("Lt", $1);}
    |   expr GT expr                                                            {$1->next = $3; $$ = insert_element("Gt", $1);}
    |   PLUS expr                                                               {$$ = $2;}
    |   MINUS expr                                                              {$$ = $2;}
    |   NOT expr                                                                {$$ = $2;}
    |   ID LPAR RPAR                                                            {$$ = insert_element("Call", $1);}
    |   ID LPAR expr RPAR                                                       {$1->next = $3; $$ = insert_element("Call", $1);}
    |   ID LPAR expr COMMA expr RPAR                                            {$1->next = $3; $3->next = $5; $$ = insert_element("Call", $1);}
    |   ID                                                                      {sprintf(string, "Id(%s)", yylval); $$ = insert_element(strdup(string), NULL);}
    |   INTLIT                                                                  {sprintf(string, "IntLit(%s)", yylval); $$ = insert_element(strdup(string), NULL);}
    |   CHRLIT                                                                  {sprintf(string, "ChrLit(%s)", yylval); $$ = insert_element(strdup(string), NULL);}
    |   REALLIT                                                                 {sprintf(string, "RealLit(%s)", yylval); $$ = insert_element(strdup(string), NULL);}
    |   LPAR expr RPAR                                                          {$$ = $2;}
    ; 

%%

void yyerror(char *msg) {
    printf("%s\n", msg);
}

