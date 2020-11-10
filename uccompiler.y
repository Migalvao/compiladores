%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "functions.h"

program * myprogram, * aux, * aux2;

int yylex (void);
void yyerror(const char* s);
char string[999], type_string[10];

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
%token <idTerminal> ID
%token <terminal> CHRLIT
%token <terminal> REALLIT

%type <nonterminal> functionsAndDeclarations functionDefinition functionDeclaration typeSpec functionDeclarator
%type <nonterminal> parameterList parameterDeclaration functionBody declarationsAndStatements declaration
%type <nonterminal> declaratorsList declarator statementList statement expr program id_token statement_error 
%type <terminal> error
 
%union{
    char * terminal;
    char * idTerminal;
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
                        | functionsAndDeclarations functionDefinition           {if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1;}
                        | functionsAndDeclarations functionDeclaration          {if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1;}
                        | functionsAndDeclarations declaration                  {if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1;}
                        ;

functionDefinition: typeSpec functionDeclarator functionBody                    {$2-> next -> next = $3; $1-> next = $2; $$ = insert_element("FuncDefinition", $1);}
                    ;
                    
functionDeclaration: typeSpec functionDeclarator SEMI                           {$1-> next = $2; $$ = insert_element("FuncDeclaration", $1);}
                    ;

typeSpec: CHAR                                                                  {$$ = insert_element("Char", NULL); sprintf(type_string,"Char" );}
        | INT                                                                   {$$ = insert_element("Int", NULL); sprintf(type_string,"Int" );}
        | VOID                                                                  {$$ = insert_element("Void", NULL); sprintf(type_string,"Void" );}
        | SHORT                                                                 {$$ = insert_element("Short", NULL); sprintf(type_string,"Short" );}
        | DOUBLE                                                                {$$ = insert_element("Double", NULL); sprintf(type_string,"Double" );}
        ;

functionDeclarator: id_token LPAR parameterList RPAR                                  {$$ = $1; $$ -> next = $3;}
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
                    | typeSpec id_token                                         {$1 -> next = $2; $$ = insert_element("ParamDeclaration", $1);}
                    ;

functionBody: LBRACE RBRACE                                                     {$$ = insert_element("FuncBody", NULL);}
            | LBRACE declarationsAndStatements RBRACE                           {$$ = insert_element("FuncBody", $2);}
            ;

declarationsAndStatements: statement                                            {$$ = $1;}
                        |  declaration                                          {$$ = $1;}
                        |  declarationsAndStatements statement                  {if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1;}
                        |  declarationsAndStatements declaration                {if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1;}
                        ;

declaration: typeSpec declaratorsList SEMI                                      {$$ = $2;}
            | error SEMI                                                        {$$ = insert_element("Erro", NULL); /*FAZER ERRO*/}
            ;

declaratorsList: declarator                                                     {aux2 = insert_element(strdup(type_string), NULL);
                                                                                    aux2 -> next = $1;
                                                                                    $$ = insert_element("Declaration", aux2);}   
                | declaratorsList COMMA declarator                              {
                                                                                    /*INSERIR TIPO*/
                                                                                    aux2 = insert_element(strdup(type_string), NULL);
                                                                                    aux2 -> next = $3;

                                                                                    if(! $1 -> next) {
                                                                                        $1 -> next = $3;
                                                                                        $1-> next = insert_element("Declaration", aux2);
                                                                                    } else {
                                                                                        aux = $1 -> next; 
                                                                                        while(aux->next)
                                                                                            aux=aux->next; 
                                                                                            
                                                                                        aux-> next = insert_element("Declaration", aux2);
                                                                                    } 
                                                                                    $$ = $1;
                                                                                    }
                |                                                               {$$ = NULL;}
                ;

declarator: id_token                                                                  {$$ = $1;}
        |   id_token ASSIGN expr                                                      {$$ = $1; $$ -> next = $3;}
        ;

id_token: ID                                                                    {sprintf(string, "Id(%s)", yylval.idTerminal); $$ = insert_element(strdup(string), NULL);}
        ;

statementList: statement                                                        {$$ = $1;}
            |  statementList statement                                          {if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1;}   
            ;

statement: LBRACE statementList statement_error RBRACE                                {if(! $2 -> next) {$2 -> next = $3;} else {aux =$2 -> next; while(aux->next)aux=aux->next; aux-> next = $3;}  $$ = insert_element("StatList", $2);}
        |  LBRACE statement_error RBRACE                                              {$$ = $2;}
        |  LBRACE RBRACE                                                        {$$ = NULL;}
        |  IF LPAR expr RPAR statement_error ELSE statement_error               {$5 -> next = $7; $3 -> next = $5; $$ = insert_element("If", $3);}
        |  IF LPAR expr RPAR statement_error                                    {$5 -> next = insert_element("Null", NULL); $3 -> next = $5; $$ = insert_element("If", $3);}
        |  WHILE LPAR expr RPAR statement_error                                 {$3 -> next = $5; $$ = insert_element("While", $3);}
        |  RETURN expr SEMI                                                     {$$ = insert_element("Return", $2);}
        |  RETURN SEMI                                                          {$$ = insert_element("Return", insert_element("Null", NULL));}
        |  expr SEMI                                                            {$$ = $1;}       
        |  SEMI                                                                 {$$ = NULL;}
        ;

statement_error:  error SEMI                                                    {$$ = insert_element("Erro", NULL); /*ERRO*/ } 
        |  LBRACE error RBRACE                                                  {$$ = insert_element("Erro", NULL); /* ERRO*/ }   
        |  LBRACE statementList statement_error RBRACE                          {if(! $2 -> next) {$2 -> next = $3;} else {aux =$2 -> next; while(aux->next)aux=aux->next; aux-> next = $3;}  $$ = insert_element("StatList", $2);}
        |  LBRACE statement_error RBRACE                                        {$$ = $2;}
        |  LBRACE RBRACE                                                        {$$ = NULL;}
        |  IF LPAR expr RPAR statement_error ELSE statement_error               {$5 -> next = $7; $3 -> next = $5; $$ = insert_element("If", $3);}
        |  IF LPAR expr RPAR statement_error                                    {$5 -> next = insert_element("Null", NULL); $3 -> next = $5; $$ = insert_element("If", $3);}
        |  WHILE LPAR expr RPAR statement_error                                 {$3 -> next = $5; $$ = insert_element("While", $3);}
        |  RETURN expr SEMI                                                     {$$ = insert_element("Return", $2);}
        |  RETURN SEMI                                                          {$$ = insert_element("Return", NULL);}
        |  expr SEMI                                                            {$$ = $1;}                     
        ;

expr:   expr ASSIGN expr                                                        {$1->next = $3; $$ = insert_element("Store", $1);}
    |   expr COMMA expr                                                         {aux = $1; while(aux->next) aux=aux->next; aux->next = $3; $$ = $1;}
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
    |   id_token LPAR RPAR                                                      {$$ = insert_element("Call", $1);}
    |   id_token LPAR expr RPAR                                                 {$1 -> next = $3; $$ = insert_element("Call", $1);}
    |   id_token LPAR expr COMMA expr RPAR                                      {
                                                                                aux = $3; while(aux->next) aux = aux ->next; aux ->next = $5; 
                                                                                $1 -> next = $3; 
                                                                                $$ = insert_element("Call", $1);}
    |   id_token                                                                {$$ = $1;}
    |   INTLIT                                                                  {sprintf(string, "IntLit(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL);}
    |   CHRLIT                                                                  {sprintf(string, "ChrLit(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL);}
    |   REALLIT                                                                 {sprintf(string, "RealLit(%s)", yylval.terminal); $$ = insert_element(strdup(string), NULL);}
    |   LPAR expr RPAR                                                          {$$ = $2;}
    |   id_token LPAR error RPAR                                                {$$ = insert_element("Erro", NULL); /* ERRO */}
    |   LPAR error RPAR                                                         {$$ = insert_element("Erro", NULL); /* ERRO */ }   
    ; 

%%


