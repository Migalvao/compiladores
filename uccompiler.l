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

[\+\-]?{int}                                                            {printf("INT(%s)\n", yytext);}
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
