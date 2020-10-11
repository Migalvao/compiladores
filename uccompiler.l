int				    [0-9]+
%X                  LOG COMMENT
%{
    int line = 1;
    int column = 1;
    int commenterror = 0;
%}

%%
<LOG>.                  {printf("logstate");}
char                    {printf("CHAR\n");}
if                      {printf("IF\n");}
else                    {printf("ELSE\n");}
while                   {printf("WHILE\n");}
int                     {printf("INT\n");}
short                   {printf("SHORT\n");}
double                  {printf("DOUBLE\n");}
return                  {printf("RETURN\n");}
void                    {printf("VOID\n");}
&                       {printf("BITWISEAND\n");}
\|                      {printf("BITWISEOR\n");}
\^                      {printf("BITWISEXOR\n");}
&&                      {printf("AND\n");}
=                       {printf("ASSIGN\n");}
\*                      {printf("MUL\n");}
,                       {printf("COMMA\n");}
\/                      {printf("DIV\n");}
==                      {printf("EQ\n");}
>=                      {printf("GE\n");}
>                       {printf("GT\n");}
\{                      {printf("LBRACE\n");}
\<=                     {printf("LE\n");}
\(                      {printf("LPAR\n");}
\<                      {printf("LT\n");}
\-                      {printf("MINUS\n");}
%                       {printf("MOD\n");}
!=                      {printf("NE\n");}
!                       {printf("NOT\n");}
\|\|                    {printf("OR\n");}
\+                      {printf("PLUS\n");}
\}                      {printf("RBRACE\n");}
\)                      {printf("RPAR\n");}
\;                      {printf("SEMI\n");}

auto|break|case|const|continue|default|do|long|register|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto {printf("RESERVED(%s)\n", yytext);}

[\+\-]?{int}                                                            {printf("INTLIT(%s)\n", yytext);}
([\+\-]?{int}?"."{int}?([Ee][\+\-]?{int})?)|{int}[Ee][\+\-]?{int}       {printf("REAL(%s)\n", yytext);}
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*		                        {printf("ID(%s)\n", yytext);}
'([^(\n|')]|\\[0-7]{1,3}|\\n|\\t|\\\\|\\'|\\\")'	                    {printf("CHRLIT(%s)\n", yytext);}


"/*"                    {BEGIN COMMENT; commenterror = 1;}
<COMMENT>"*/"           {BEGIN 0; commenterror = 0;}
<COMMENT>.              ;
<COMMENT>\n              ;


[^" ""\n""\r"]	    {printf("illegal character\(<%s>)", yytext);}
.                       ;
\n                      ;

%%
int main(int argc, char *argv[])
{
    if(argc >= 2 && strcmp(argv[1], "-l") == 0){
        BEGIN LOG;
    }
    yylex();
    return 0;
}

int yywrap()
{
    if(commenterror == 1){
        printf("unterminated error");
    } 
    return 1;
}
