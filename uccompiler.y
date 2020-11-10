%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "functions.h"

program * myprogram, * aux;

int yylex (void);
void yyerror(char* s);
char string[999];

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

functionsAndDeclarations: functionDefinition                                    {$$ = $1;}
                        | functionDeclaration                                   {$$ = $1;}
                        | declaration                                           {$$ = $1;}
                        | functionsAndDeclarations functionDefinition           {$1 -> next = $2;}
                        | functionsAndDeclarations functionDeclaration          {$1 -> next = $2;}
                        | functionsAndDeclarations declaration                  {$1 -> next = $2;}
                        ;

functionDefinition: typeSpec functionDeclarator functionBody                    {$2-> next -> next = $3; $1-> next = $2; $$ = insert_element("FunctionDefinition", $1);}
                    ;
                    
functionDeclaration: typeSpec functionDeclarator SEMI                           {$1-> next = $2; $$ = insert_element("FunctionDeclaration", $1);}
                    ;

typeSpec: CHAR                                                                  {$$ = insert_element("Char", NULL);}
        | INT                                                                   {$$ = insert_element("Int", NULL);}
        | VOID                                                                  {$$ = insert_element("Void", NULL);}
        | SHORT                                                                 {$$ = insert_element("Short", NULL);}
        | DOUBLE                                                                {$$ = insert_element("Double", NULL);}
        ;

functionDeclarator: ID LPAR parameterList RPAR                                  {sprintf(string, "Id(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL); $$ -> next = $3;}
                    ;
                    
parameterList: parameterDeclaration                                             {$$ = insert_element("ParamList", $1); }
            | parameterList COMMA parameterDeclaration                          {
                                                                                    aux = $1->children;
                                                                                    while(aux->next){
                                                                                        aux=aux->next;
                                                                                    } 
                                                                                    aux -> next = $3; 

                                                                                    $$ = $1;

                                                                                }
            ;

parameterDeclaration: typeSpec                                                  {$$ = insert_element("ParamDeclaration", $1);}
                    | typeSpec ID                                               {sprintf(string, "Id(%s)", yylval.terminal); $1 ->next = insert_element(strdup(string), NULL); $$ = insert_element("ParamDeclaration", $1);}
                    ;

functionBody: LBRACE RBRACE                                                     {$$ = insert_element("FuncBody", NULL);}
            | LBRACE declarationsAndStatements RBRACE                           {$$ = insert_element("FuncBody", $2);}
            ;

declarationsAndStatements: statement                                            {$$ = $1;}
                        |  declaration                                          {$$ = $1;}
                        |  declarationsAndStatements statement                  {$1 -> next = $2; $$ = $1;}
                        |  declarationsAndStatements declaration                {$1 -> next = $2; $$ = $1;}
                        ;

declaration: typeSpec declaratorsList SEMI                                      {$1 -> next = $2; $$ = insert_element("Declaration", $1);}
            ;

declaratorsList: declarator                                                     {$$ = $1;}   
                | declaratorsList COMMA declarator                              {if($1 -> next) {$1 -> next -> next = $3;} else { $1 -> next = $3; }$$ = $1;}
                |                                                               {$$ = NULL;}
                ;

declarator: ID                                                                  {sprintf(string, "Id(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL);}
        |   ID ASSIGN expr                                                      {printf("ID - %s\tExpr - %s\n", yylval.terminal, $3->type); sprintf(string, "Id(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL); $$ -> next = $3;}
        ;

statementList: statement                                                        {$$ = $1;}
            |  statementList statement                                          {$1-> next = $2; $$ = $1;}   
            ;

statement: LBRACE statementList statement RBRACE                                {$$ = insert_element("StatList", $2);}
        |  LBRACE statement RBRACE                                              {$$ = $2;}
        |  LBRACE RBRACE                                                        {$$ = NULL;}
        |  IF LPAR expr RPAR statement ELSE statement                           {$5 -> next = $7; $3 -> next = $5; $$ = insert_element("IF", $3);}
        |  IF LPAR expr RPAR statement                                          {$3 -> next = $5; $$ = insert_element("IF", $3);}
        |  WHILE LPAR expr RPAR statement                                       {$3 -> next = $5; $$ = insert_element("While", $3);}
        |  RETURN expr SEMI                                                     {$$ = insert_element("Return", $2);}
        |  RETURN SEMI                                                          {$$ = insert_element("Return", NULL);}
        |  expr SEMI                                                            {$$ = $1;}       
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
    |   ID LPAR RPAR                                                            {sprintf(string, "Id(%s)", yylval.terminal); aux = insert_element(strdup(string), NULL); $$ = insert_element("Call", aux);}
    |   ID LPAR expr RPAR                                                       {sprintf(string, "Id(%s)", yylval.terminal); aux = insert_element(strdup(string), NULL); aux -> next = $3; $$ = insert_element("Call", aux);}
    |   ID LPAR expr COMMA expr RPAR                                            {sprintf(string, "Id(%s)", yylval.terminal); aux = insert_element(strdup(string), NULL); aux -> next = $3; aux -> next ->next = $5; $$ = insert_element("Call", aux);}
    |   ID                                                                      {sprintf(string, "Id(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL);}
    |   INTLIT                                                                  {sprintf(string, "IntLit(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL);}
    |   CHRLIT                                                                  {sprintf(string, "ChrLit(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL);}
    |   REALLIT                                                                 {sprintf(string, "RealLit(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL);}
    |   LPAR expr RPAR                                                          {$$ = $2;}
    ; 

%%


