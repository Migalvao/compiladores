int				    [0-9]+

%%
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

.	            ;
\n	            ;

%%
int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}
