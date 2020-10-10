int				    [0-9]+

%{
    #include <stdbool.h>
    bool l = false;
%}

%%
char                    {if(l) printf("CHAR\n");}
if                      {if(l) printf("IF\n");}
else                    {if(l) printf("ELSE\n");}
while                   {if(l) printf("WHILE\n");}
int                     {if(l) printf("INT\n");}
short                   {if(l) printf("SHORT\n");}
double                  {if(l) printf("DOUBLE\n");}
return                  {if(l) printf("RETURN\n");}
void                    {if(l) printf("VOID\n");}
&                       {if(l) printf("BITWISEAND\n");}
\|                      {if(l) printf("BITWISEOR\n");}
\^                      {if(l) printf("BITWISEXOR\n");}
&&                      {if(l) printf("AND\n");}
=                       {if(l) printf("ASSIGN\n");}
\*                      {if(l) printf("MUL\n");}
,                       {if(l) printf("COMMA\n");}
\/                      {if(l) printf("DIV\n");}
==                      {if(l) printf("EQ\n");}
>=                      {if(l) printf("GE\n");}
>                       {if(l) printf("GT\n");}
\{                      {if(l) printf("LBRACE\n");}
\<=                     {if(l) printf("LE\n");}
\(                      {if(l) printf("LPAR\n");}
\<                      {if(l) printf("LT\n");}
\-                      {if(l) printf("MINUS\n");}
%                       {if(l) printf("MOD\n");}
!=                      {if(l) printf("NE\n");}
!                       {if(l) printf("NOT\n");}
\|\|                    {if(l) printf("OR\n");}
\+                      {if(l) printf("PLUS\n");}
\}                      {if(l) printf("RBRACE\n");}
\)                      {if(l) printf("RPAR\n");}
\;                      {if(l) printf("SEMI\n");}

auto|break|case|const|continue|default|do|long|register|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|enum|extern|float|for|goto {if(l) printf("RESERVED(%s)\n", yytext);}

[\+\-]?{int}                                                            {if(l) printf("INTLIT(%s)\n", yytext);}
([\+\-]?{int}?"."{int}?([Ee][\+\-]?{int})?)|{int}[Ee][\+\-]?{int}       {if(l) printf("REAL(%s)\n", yytext);}
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*		                        {if(l) printf("ID(%s)\n", yytext);}
'([^(\n|')]|\\[0-7]{1,3}|\\n|\\t|\\\\|\\'|\\\")'	                    {if(l) printf("CHRLIT(%s)\n", yytext);}

.	            ;
\n	            ;

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
return 1;
}