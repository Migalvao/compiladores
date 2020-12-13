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
%type <nonterminal> plus_token minus_token mul_token div_token mod_token and_token or_token bitwiseand_token
%type <nonterminal> bitwiseor_token bitwisexor_token eq_token ne_token le_token lt_token gt_token ge_token 
%type <nonterminal> assign_token not_token comma_token
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


plus_token: PLUS                                                                    {$$ = insert_element(strdup("Add"), NULL);}
        ;

minus_token: MINUS                                                                    {$$ = insert_element(strdup("Sub"), NULL);}
        ;

mul_token: MUL                                                                    {$$ = insert_element(strdup("Mul"), NULL);}
        ;

div_token: DIV                                                                    {$$ = insert_element(strdup("Div"), NULL);}
        ;
        
mod_token: MOD                                                                    {$$ = insert_element(strdup("Mod"), NULL);}
        ;

or_token: OR                                                                    {$$ = insert_element(strdup("Or"), NULL);}
        ;

and_token: AND                                                                    {$$ = insert_element(strdup("And"), NULL);}
        ;

bitwiseand_token: BITWISEAND                                                                    {$$ = insert_element(strdup("BitWiseAnd"), NULL);}
        ;

bitwiseor_token: BITWISEOR                                                                    {$$ = insert_element(strdup("BitWiseOr"), NULL);}
        ;

bitwisexor_token: BITWISEXOR                                                                    {$$ = insert_element(strdup("BitWiseXor"), NULL);}
        ;

eq_token: EQ                                                                    {$$ = insert_element(strdup("Eq"), NULL);}
        ;

ne_token: NE                                                                    {$$ = insert_element(strdup("Ne"), NULL);}
        ;

le_token: LE                                                                    {$$ = insert_element(strdup("Le"), NULL);}
        ;

ge_token: GE                                                                    {$$ = insert_element(strdup("Ge"), NULL);}
        ;

lt_token: LT                                                                    {$$ = insert_element(strdup("Lt"), NULL);}
        ;

gt_token: GT                                                                    {$$ = insert_element(strdup("Gt"), NULL);}
        ;

assign_token: ASSIGN                                                            {$$ = insert_element(strdup("Store"), NULL);}
        ;

not_token: NOT                                                                  {$$ = insert_element(strdup("Not"), NULL);}
        ;

comma_token: COMMA                                                              {$$ = insert_element(strdup("Comma"), NULL);}
        ;

expr:   expr assign_token %prec ASSIGN expr                                     {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr comma_token %prec COMMA expr                                       {aux = $1; while(aux->next) aux=aux->next; aux->next = $3; $2 -> children = $1; $$ = $2;}
    |   LPAR expr comma_token %prec COMMA expr RPAR                             {aux = $2; while(aux->next) aux=aux->next; aux->next = $4; $3 -> type = strdup("RealComma"); $3 -> children = $2; $$ = $3;}
    |   expr plus_token %prec PLUS expr                                         {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr minus_token %prec MINUS expr                                       {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr mul_token %prec MUL expr                                           {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr div_token %prec DIV expr                                           {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr mod_token %prec MOD expr                                           {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr or_token %prec OR expr                                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr and_token %prec AND expr                                           {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr bitwiseand_token %prec BITWISEAND expr                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr bitwiseor_token %prec BITWISEOR expr                               {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr bitwisexor_token %prec BITWISEXOR expr                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr eq_token %prec EQ expr                                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr ne_token %prec NE expr                                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr le_token %prec LE expr                                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr ge_token %prec GE expr                                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr lt_token %prec LT expr                                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   expr gt_token %prec GT expr                                             {$1->next = $3; $2 -> children = $1; $$ = $2;}
    |   plus_token expr %prec NOT                                               {$1 -> children = $2;  $1 -> type = strdup("Plus"); $$ = $1;}
    |   minus_token expr %prec NOT                                              {$1 -> children = $2;  $1 -> type = strdup("Minus"); $$ = $1;}
    |   not_token expr %prec NOT                                                {$1 -> children = $2;  $1 -> type = strdup("Not"); $$ = $1;}
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


