/* AUTORES: */
/* MIGUEL EDUARDO PINTO GALVÃO - 2018278986 */
/* JOÃO BERNARDO DO NASCIMENTO DOMINGUES - 2018278415 */

int				    [0-9]+
%X                  COMMENT
%{
    #include <stdbool.h>
    #include "structures.h"
    #include "functions.h"
    #include "y.tab.h"

    bool l = false, t = false, comment_error = false;
    int line = 1, column = 1, unfinished_line, unfinished_column;
    extern program * myprogram;

%}

%%
char                    {if(l) printf("CHAR\n"); column += yyleng; return CHAR;}
if                      {if(l) printf("IF\n"); column += yyleng; return IF;}
else                    {if(l) printf("ELSE\n"); column += yyleng; return ELSE;}
while                   {if(l) printf("WHILE\n"); column += yyleng; return WHILE;}
int                     {if(l) printf("INT\n"); column += yyleng; return INT;}
short                   {if(l) printf("SHORT\n"); column += yyleng; return SHORT;}
double                  {if(l) printf("DOUBLE\n"); column += yyleng; return DOUBLE;}
return                  {if(l) printf("RETURN\n"); column += yyleng; return RETURN;}
void                    {if(l) printf("VOID\n"); column += yyleng; return VOID;}
\&                       {if(l) printf("BITWISEAND\n"); column += yyleng; return BITWISEAND;}
\|                      {if(l) printf("BITWISEOR\n"); column += yyleng; return BITWISEOR;}
\^                      {if(l) printf("BITWISEXOR\n"); column += yyleng; return BITWISEXOR;}
\&\&                      {if(l) printf("AND\n"); column += yyleng; return AND;}
\=                       {if(l) printf("ASSIGN\n"); column += yyleng; return ASSIGN;}
\*                      {if(l) printf("MUL\n"); column += yyleng; return MUL;}
\,                       {if(l) printf("COMMA\n"); column += yyleng; return COMMA;}
\/                      {if(l) printf("DIV\n"); column += yyleng; DIV;}
\=\=                      {if(l) printf("EQ\n"); column += yyleng; return EQ;}
\>\=                      {if(l) printf("GE\n"); column += yyleng; return GE;}
\>                       {if(l) printf("GT\n"); column += yyleng; return GT;}
\{                      {if(l) printf("LBRACE\n"); column += yyleng; return LBRACE;}
\<=                     {if(l) printf("LE\n"); column += yyleng; return LE;}
\(                      {if(l) printf("LPAR\n"); column += yyleng; return LPAR;}
\<                      {if(l) printf("LT\n"); column += yyleng; return LT;}
\-                      {if(l) printf("MINUS\n"); column += yyleng; return MINUS;}
\%                       {if(l) printf("MOD\n"); column += yyleng; return MOD;}
\!\=                      {if(l) printf("NE\n"); column += yyleng; return NE;}
\!                       {if(l) printf("NOT\n"); column += yyleng; return NOT;}
\|\|                    {if(l) printf("OR\n"); column += yyleng; return OR;}
\+                      {if(l) printf("PLUS\n"); column += yyleng; return PLUS;}
\}                      {if(l) printf("RBRACE\n"); column += yyleng; return RBRACE;}
\)                      {if(l) printf("RPAR\n"); column += yyleng; return RPAR;}
\;                      {if(l) printf("SEMI\n"); column += yyleng; return SEMI;}

    /*RESERVED WORDS*/
auto|break|case|const|continue|inline|define|default|do|long|NULL|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|_Packed|_Bool|_Complex|_Imaginary|"++"|"--"|\[|\] {if(l) printf("RESERVED(%s)\n", yytext); column += yyleng;}

    /* INTLIT, REALIT, CHRLIT AND ID*/
{int}                                                                       {if(l) printf("INTLIT(%s)\n", yytext); column += yyleng;  yylval.terminal = strdup(yytext); return INTLIT;}
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*		                            {if(l) printf("ID(%s)\n", yytext); column += yyleng; yylval.terminal = strdup(yytext); return ID;}
\'([^\n\'\\]|\\[0-7]{1,3}|\\n|\\t|\\\\|\\'|\\\")\'	                        {if(l) printf("CHRLIT(%s)\n", yytext); column += yyleng; yylval.terminal = strdup(yytext); return CHRLIT;}
({int}"."{int}([Ee][\+\-]?{int})?)|{int}[Ee][\+\-]?{int}|{int}"."|"."{int}([Ee][\+\-]?{int})?|{int}"."([Ee][\+\-]?{int})             {if(l) printf("REALLIT(%s)\n", yytext); column += yyleng; yylval.terminal = strdup(yytext); return REALLIT;}


    /* INVALID CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*'                                      {printf("Line %d, col %d: invalid char constant (%s)\n", line, column, yytext); column += yyleng;}

    /* UNTERMINATED CHAR CONSTANTS */
'([^'\n\\]|(\\')|(\\[^'\n]))*(\n|(\\\n))                       {printf("Line %d, col %d: unterminated char constant\n", line, column); line += 1; column=1;}

    /* COMMENTS */
"//".*                      {column += yyleng;}
"/*"                        {BEGIN COMMENT; comment_error = true; unfinished_line = line; unfinished_column = column; column += yyleng;}
<COMMENT>"*/"               {BEGIN 0; comment_error = false; column += yyleng;}
<COMMENT>.                  {column += yyleng;}
<COMMENT>\n                 {line += yyleng; column = 1;}

    /* ILLEGAL CHARACTERS */
[\t|\r| ]	                            {column += yyleng;}

.           	                        {printf("Line %d, col %d: illegal character (%s)\n", line, column, yytext); column += yyleng;}
\n	                                    {line += 1; column = 1;}

%%
int main(int argc, char *argv[])
{
    if(argc >= 2 && strcmp(argv[1], "-l") == 0){
        l = true;
    }
    else if(argc >= 2 && strcmp(argv[1], "-e1") == 0){
        l = false;
    }

    if(argc >= 2 && strcmp(argv[1], "-t") == 0){
        t = true;
    }

    yyparse();

    if(t){
        print_ast(myprogram);
    }

    return 0;
}

int yywrap()
{
    if(comment_error){
        printf("Line %d, col %d: unterminated comment\n", unfinished_line, unfinished_column);
    } 
    return 1;
}
