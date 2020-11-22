%{
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

%}

%token <terminal> CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI RESERVED CHRLIT REALLIT INTLIT

%token <idTerminal> ID

%type <nonterminal> functionsAndDeclarations functionDefinition functionDeclaration typeSpec functionDeclarator
%type <nonterminal> parameterList parameterDeclaration functionBody declarationsAndStatements declaration
%type <nonterminal> declaratorsList declarator statementList expr program id_token statement statement_error
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

functionDeclarator: id_token LPAR parameterList RPAR                            {$$ = $1; $$ -> next = $3;}
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
                        |  declarationsAndStatements statement                  {if(!$1) $$ = $2; else { if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1; }}
                        |  declarationsAndStatements declaration                {if(!$1) $$ = $2; else { if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1; }}
                        ;

declaration: typeSpec declaratorsList SEMI                                      {$$ = $2;}
             | error SEMI                                                       {$$ = insert_element("Erro", NULL); is_error = true; /*FAZER ERRO*/}
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
                ;

declarator: id_token                                                            {$$ = $1;}
        |   id_token ASSIGN expr                                                {$$ = $1; $$ -> next = $3;}
        ;

id_token: ID                                                                    {$$ = insert_element(strdup("Id"), insert_element(strdup(yylval.idTerminal), NULL));}
        ;

statementList: statement_error                                                  {$$ = $1;}
            |  statementList statement_error                                    {
                                                                                    if(!$2){ 
                                                                                        $$ = $1; 
                                                                                    }  else { 
                                                                                        if(!$1) {
                                                                                            $$ = $2;
                                                                                        } else {
                                                                                            if(! $1 -> next) {$1 -> next = $2;} else {aux =$1 -> next; while(aux->next)aux=aux->next; aux-> next = $2;  } $$ = $1; 
                                                                                        }
                                                                                    }
                                                                                }   
            ;

statement:  LBRACE error RBRACE                                                 {$$ = insert_element("Erro", NULL); is_error = true; /* ERRO*/ }  
        |  LBRACE statementList statement_error RBRACE                          {
                                                                                    if(!$2 && !$3){
                                                                                        $$ =  NULL;
                                                                                    } else if(!$2 && $3){
                                                                                        $$ = $3;
                                                                                    } else if($2 && !$3){
                                                                                        if($2 -> next){
                                                                                            $$ = insert_element("StatList", $2);
                                                                                        } else {
                                                                                            $$ = $2;
                                                                                        }
                                                                                    } else if($2 && $3){
                                                                                        aux = $2;
                                                                                        while(aux->next)
                                                                                            aux = aux->next;
                                                                                        aux -> next = $3;
                                                                                        $$ = insert_element("StatList", $2);
                                                                                    }
                                                                                }
        |  LBRACE statement_error RBRACE                                        {$$ = $2;}
        |  LBRACE RBRACE                                                        {$$ = NULL;}
        |  IF LPAR expr RPAR statement_error ELSE statement_error               {if($5){ $3 -> next = $5; } else { $3 -> next = insert_element("Null", NULL);} if($7){ $3 -> next -> next = $7; } else { $3 -> next -> next = insert_element("Null", NULL);} $$ = insert_element("If", $3);}
        |  IF LPAR expr RPAR statement_error                                    {if($5){ $3 -> next = $5; } else { $3 -> next = insert_element("Null", NULL);} $3 -> next -> next = insert_element("Null", NULL); $$ = insert_element("If", $3);}
        |  WHILE LPAR expr RPAR statement_error                                 {if($5){ $3 -> next = $5; } else { $3 -> next = insert_element("Null", NULL);} $$ = insert_element("While", $3);}
        |  RETURN expr SEMI                                                     {$$ = insert_element("Return", $2);}
        |  RETURN SEMI                                                          {$$ = insert_element("Return", insert_element("Null", NULL));}
        |  expr SEMI                                                            {$$ = $1;}     
        |  SEMI                                                                 {$$ = NULL;}  
        ;

statement_error: statement                                                      {$$ = $1;}
                | error SEMI                                                    {$$ = insert_element("Erro", NULL); is_error = true; /*ERRO*/ } 
                ;

expr:   expr ASSIGN expr                                                        {$1->next = $3; $$ = insert_element("Store", $1);}
    |   expr COMMA expr                                                         {aux = $1; while(aux->next) aux=aux->next; aux->next = $3; $$ = insert_element("Comma", $1);}
    |   LPAR expr COMMA expr RPAR                                               {aux = $2; while(aux->next) aux=aux->next; aux->next = $4; $$ = insert_element("RealComma", $2);}
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
    |   PLUS expr %prec NOT                                                     {$$ = insert_element("Plus", $2);}
    |   MINUS expr %prec NOT                                                    {$$ = insert_element("Minus", $2);}
    |   NOT expr                                                                {$$ = insert_element("Not", $2);}
    |   id_token LPAR RPAR                                                      {$$ = insert_element("Call", $1);}
    |   id_token LPAR expr RPAR                                                 {$1 -> next = children_to_brother($3); $$ = insert_element("Call", $1);}
    |   id_token                                                                {$$ = $1;}
    |   INTLIT                                                                  {$$ = insert_element(strdup("IntLit"), insert_element(strdup(yylval.terminal), NULL));}
    |   CHRLIT                                                                  {$$ = insert_element(strdup("ChrLit"), insert_element(strdup(yylval.terminal), NULL));}
    |   REALLIT                                                                 {$$ = insert_element(strdup("RealLit"), insert_element(strdup(yylval.terminal), NULL));}
    |   LPAR expr RPAR                                                          {$$ = $2;}
    |   id_token LPAR error RPAR                                                {$$ = insert_element("Erro", NULL); is_error = true; /* ERRO */}
    |   LPAR error RPAR                                                         {$$ = insert_element("Erro", NULL); is_error = true;  /* ERRO */ }   
    ; 

%%


