%{
#include <stdio.h>
#include <stdlib.h>

int yylex (void);
void yyerror(char* s);


%}


%token <token> GE
%token <token> GT
%token <token> LBRACE
%token <token> LE
%token <token> LPAR
%token <token> LT
%token <token> MINUS
%token <token> MOD
%token <token> NE
%token <token> NOT
%token <token> OR
%token <token> PLUS
%token <token> RBRACE
%token <token> RPAR
%token <token> SEMI
%token <token> INTLIT
%token <token> ID
%token <token> CHRLIT
%token <token> REALLIT

%union{
    char * token;
}
%%

functionsAndDeclarations: functionDefinition                                    {printf("func definition");}
                        | functionDeclaration                                   {printf("func declaration added");}
                        | declaration                                           {printf("declaration");}
                        | functionsAndDeclarations functionDefinition           {printf("definition");}
                        | functionsAndDeclarations functionDeclaration          {printf("definition");}
                        | functionsAndDeclarations declaration                  {printf("definition");}
                        ;

functionDefinition: typeSpec functionDeclarator functionBody                    {;}
                    ;
                    
functionDeclaration: typeSpec functionDeclarator SEMI                           {;}
                    ;

typeSpec: CHAR          {;}
        | INT       {;}
        | VOID      {;}
        | SHORT     {;}
        | DOUBLE    {;}
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

declaration: typeSec declaratorsList SEMI                                       {;}
            ;

declaratorsList: declarator                                                     {;}   
                | declaratorsList COMMA declarator                              {;}
                |                                                               {;}
                ;

declarator: ID                                                                  {;}
        |   ID ASSIGN expr                                                      {;}
        ;

statementList: statement                                                        {;}
            |  statementList statement                                          {;}
            |                                                                   {;}
            ;

statement: LBRACE statementList RBRACE                                          {;}
        |  IF LPAR xpr RPAR statement ELSE statement                            {;}
        |  IF LPAR xpr RPAR statement                                           {;}
        |  WHILE LPAR xxpr RPAR statement                                       {;}
        |  RETURN expr SEMI                                                     {;}
        |  RETURN SEMI                                                          {;}
        |  expr SEMI                                                            {;}       
        |  SEMI                                                                 {;}                              
        ;

expr:   expr ASSIGN expr                                                        {;}
    |   expr COMMA expr                                                         {;}
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
    |   LPART expr RPAR                                                         {;}
    ; 

%%

void yyerror(char *msg) {
    printf("%s\n", msg);
}

