/* AUTORES: */
/* MIGUEL EDUARDO PINTO GALVÃO - 2018278986 */
/* JOÃO BERNARDO DO NASCIMENTO DOMINGUES - 2018278415 */

int				    [0-9]+
%X                  CHAR COMMENT
%{
    #include <stdbool.h>
    bool l = false, unterminated_char = false, comment_error = false;
    int line = 1, column = 1, unfinished_line, unfinished_column;
    char string[999] = "";
%}

%%
char                    {if(l) printf("CHAR\n"); column += yyleng;}
if                      {if(l) printf("IF\n"); column += yyleng; }
else                    {if(l) printf("ELSE\n"); column += yyleng;}
while                   {if(l) printf("WHILE\n"); column += yyleng;}
int                     {if(l) printf("INT\n"); column += yyleng;}
short                   {if(l) printf("SHORT\n"); column += yyleng;}
double                  {if(l) printf("DOUBLE\n"); column += yyleng;}
return                  {if(l) printf("RETURN\n"); column += yyleng;}
void                    {if(l) printf("VOID\n"); column += yyleng;}
&                       {if(l) printf("BITWISEAND\n"); column += yyleng;}
\|                      {if(l) printf("BITWISEOR\n"); column += yyleng;}
\^                      {if(l) printf("BITWISEXOR\n"); column += yyleng;}
&&                      {if(l) printf("AND\n"); column += yyleng;}
=                       {if(l) printf("ASSIGN\n"); column += yyleng;}
\*                      {if(l) printf("MUL\n"); column += yyleng;}
,                       {if(l) printf("COMMA\n"); column += yyleng;}
\/                      {if(l) printf("DIV\n"); column += yyleng;}
==                      {if(l) printf("EQ\n"); column += yyleng;}
>=                      {if(l) printf("GE\n"); column += yyleng;}
>                       {if(l) printf("GT\n"); column += yyleng;}
\{                      {if(l) printf("LBRACE\n"); column += yyleng;}
\<=                     {if(l) printf("LE\n"); column += yyleng;}
\(                      {if(l) printf("LPAR\n"); column += yyleng;}
\<                      {if(l) printf("LT\n"); column += yyleng;}
\-                      {if(l) printf("MINUS\n"); column += yyleng;}
%                       {if(l) printf("MOD\n"); column += yyleng;}
!=                      {if(l) printf("NE\n"); column += yyleng;}
!                       {if(l) printf("NOT\n"); column += yyleng;}
\|\|                    {if(l) printf("OR\n"); column += yyleng;}
\+                      {if(l) printf("PLUS\n"); column += yyleng;}
\}                      {if(l) printf("RBRACE\n"); column += yyleng;}
\)                      {if(l) printf("RPAR\n"); column += yyleng;}
\;                      {if(l) printf("SEMI\n"); column += yyleng;}

    /*RESERVED WORDS*/
auto|break|case|const|continue|default|do|long|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto|_Packed|_Bool|_Complex|_Imaginary|"++"|"--"|\[|\]|"->"|~|"<<"|">>"|"*="|"/="|"%="|"+="|"-="|"&="|"^="|"|="|"<<="|">>="|"?:" {if(l) printf("RESERVED(%s)\n", yytext); column += yyleng;}

    /* INTLIT, REALIT, CHRLIT AND ID*/
[\+\-]?{int}                                                            {if(l) printf("INTLIT(%s)\n", yytext); column += yyleng;}
([\+\-]?{int}?"."{int}?([Ee][\+\-]?{int})?)|{int}[Ee][\+\-]?{int}       {if(l) printf("REALIT(%s)\n", yytext); column += yyleng;}
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*		                        {if(l) printf("ID(%s)\n", yytext); column += yyleng;}
'([^(\n')]|\\[0-7]{1,3}|\\n|\\t|\\\\|\\'|\\\")'	                    {if(l) printf("CHRLIT(%s)\n", yytext); column += yyleng;}

    /* INVALID CHAR CONSTANTS */
'.*'                       {printf("Line %d, col %d: invalid char constant (%s)\n", line, column, yytext); column += yyleng;}
'\n+'                      {printf("Line %d, col %d: invalid char constant (%s)\n", line, column, yytext); line += yyleng; column = 1;}

    /* UNTERMINATED CHAR CONSTANTS */
'                           {BEGIN CHAR; unterminated_char = true; unfinished_line = line; unfinished_column = column; column += yyleng; }
<CHAR>'                     {printf("Line %d, col %d: invalid char constant (%s)\n", unfinished_line, unfinished_column, string); BEGIN 0; unterminated_char = false; column += yyleng; sprintf(string, "");}
<CHAR>.|\n                  {if(strcmp(yytext, "\n") == 0) line += 1; column += yyleng; strcat(string, yytext);};

    /* COMMENTS */
"//".*                      {column += yyleng;}
"/*"                        {BEGIN COMMENT; comment_error = true; unfinished_line = line; unfinished_column = column; column += yyleng;}
<COMMENT>"*/"               {BEGIN 0; comment_error = false; column += yyleng;}
<COMMENT>.                  {column += yyleng;}
<COMMENT>\n                 {line += yyleng; column = 1;}

    /* ILLEGAL CHARACTERS */
[^" ""\n""\r""\t"]	        {printf("Line %d, col %d: illegal character (%s)\n", line, column, yytext); column += yyleng;}

.	                        {column += yyleng;}
\n	                        {line += 1; column = 1;}

%%
int main(int argc, char *argv[])
{
    if(argc >= 2 && strcmp(argv[1], "-l") == 0){
        l = true;
    }
    yylex();
    return 0;
}

int yywrap()
{
    if(unterminated_char){
        printf("Line %d, col %d: unterminated char constant\n", unfinished_line, unfinished_column);
    }
    if(comment_error){
        printf("Line %d, col %d: unterminated comment\n", unfinished_line, unfinished_column);
    } 
    return 1;
}
