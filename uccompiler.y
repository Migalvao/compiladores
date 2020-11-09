%{
#include <stdio.h>
#include <stdlib.h>

int yylex (void);
void yyerror(char* s);

%}

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
    // associatividades

%left COMMA
%right ASSIGN
%left OR AND BITWISEOR BITWISEXOR BITWISEAND EQ NE GE GT LE LT PLUS MINUS MUL DIV MOD
%right NOT
%left LPAR RPAR
%right ELSE

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
            |  statementList statement                                          {;}   
            ;

statement: LBRACE statementList RBRACE                                          {;}
        |  LBRACE RBRACE                                                        {;}
        |  IF LPAR expr RPAR statement ELSE statement                            {;}
        |  IF LPAR expr RPAR statement                                           {;}
        |  WHILE LPAR expr RPAR statement                                       {;}
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
    |   LPAR expr RPAR                                                         {;}
    ; 

%%

void yyerror(char *msg) {
    printf("%s\n", msg);
}

