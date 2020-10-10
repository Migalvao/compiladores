int				    [0-9]+

%%
[\+\-]?{int}                                                          {printf("INT(%s)\n", yytext);}
([\+\-]?{int}?"."{int}?([Ee][\+\-]?{int})?)|{int}[Ee][\+\-]?{int}       {printf("REAL(%s)\n", yytext);}
char                    {printf("CHAR\n");}
if                      {printf("IF\n");}
else                    {printf("ELSE\n");}
while                   {printf("WHILE\n");}
int                     {printf("INT\n");}
short                   {printf("SHORT\n");}
double                  {printf("DOUBLE\n");}
return                  {printf("RETURN\n");}
void                    {printf("VOID\n");}
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
