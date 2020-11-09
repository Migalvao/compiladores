%{
#include <stdio.h>
#include <stdlib.h>

int yylex (void);
void yyerror(char* s);

%token <token> CHAR
%token <token> IF
%token <token> ELSE
%token <token> WHILE
%token <token> INT
%token <token> SHORT
%token <token> DOUBLE
%token <token> RETURN
%token <token> VOID
%token <token> BITWISEAND
%token <token> BITWISEOR
%token <token> BITWISEXOR
%token <token> AND
%token <token> ASSIGN
%token <token> MUL
%token <token> COMMA
%token <token> DIV
%token <token> EQ

%}



%union{
    char* token;
}
%%


functionsAndDeclarations:   functionDefinition                                  {printf("definition");}
                        |   functionDeclaration                                 {printf("func declaration");}
                        |   declaration                                         {printf("declaration");}
                        |   functionsAndDeclarations functionDefinition         {printf("");}
                        |   functionsAndDeclarations functionDeclaration        {printf("");}
                        |   functionsAndDeclarations declaration                {printf("");}
                        ;


declaration:    typeSec declarator declaration                              {;}
            |   COMMA declarator declaration                                {;}
            |   SEMI                                                        {;}
            ;


typeSec:    CHAR                                                                {;}
        |   INT                                                                 {;}
        |   VOID                                                                {;}
        |   SHORT                                                               {;}
        |   DOUBLE                                                              {;}
        ;

declarator: ID                                                                  {;}
        |   ID ASSIGN expr                                                      {;}
        ;

expr:   expr ASSIGN expr
    |   expr COMMA expr
    |   expr PLUS expr
    |   expr MINUS expr
    |   expr MUL expr
    |   expr DIV expr
    |   expr MOD expr
    |   expr OR expr
    |   expr AND expr
    |   expr BITWISEAND expr
    |   expr BITWISEOR expr
    |   expr BITWISEXOR expr
    |   expr EQ expr
    |   expr NE expr
    |   expr LE expr
    |   expr GE expr
    |   expr LT expr
    |   expr GT expr
    |   PLUS expr
    |   MINUS expr
    |   NOT expr
    |   ID LPAR RPAR
    |   ID LPAR expr RPAR
    |   ID LPAR expr COMMA expr RPAR
    |   ID
    |   INTLIT
    |   CHRLIT
    |   REALLIT
    |   LPART expr RPAR
    ;


FunctionsAndDeclarations −→ (FunctionDefinition | FunctionDeclaration | Declaration) {FunctionDefinition | FunctionDeclaration | Declaration}
FunctionDefinition −→ TypeSpec FunctionDeclarator FunctionBody
FunctionBody −→ LBRACE [DeclarationsAndStatements] RBRACE
DeclarationsAndStatements −→ Statement DeclarationsAndStatements | Declaration DeclarationsAndStatements | Statement | Declaration
FunctionDeclaration −→ TypeSpec FunctionDeclarator SEMI
FunctionDeclarator −→ ID LPAR ParameterList RPAR
ParameterList −→ ParameterDeclaration {COMMA ParameterDeclaration}
ParameterDeclaration −→ TypeSpec [ID]
Declaration −→ TypeSpec Declarator {COMMA Declarator} SEMI
TypeSpec −→ CHAR | INT | VOID | SHORT | DOUBLE
Declarator −→ ID [ASSIGN Expr]
Statement −→ [Expr] SEMI
Statement −→ LBRACE {Statement} RBRACE
Statement −→ IF LPAR Expr RPAR Statement [ELSE Statement]
Statement −→ WHILE LPAR Expr RPAR Statement
Statement −→ RETURN [Expr] SEMI
Expr −→ Expr (ASSIGN | COMMA) Expr
Expr −→ Expr (PLUS | MINUS | MUL | DIV | MOD) Expr
Expr −→ Expr (OR | AND | BITWISEAND | BITWISEOR | BITWISEXOR) Expr
Expr −→ Expr (EQ | NE | LE | GE | LT | GT) Expr
Expr −→ (PLUS | MINUS | NOT) Expr
Expr −→ ID LPAR [Expr {COMMA Expr}] RPAR
Expr −→ ID | INTLIT | CHRLIT | REALLIT | LPAR Expr RPAR




%%

void yyerror(char *msg) {
    printf("%s\n", msg);
}

