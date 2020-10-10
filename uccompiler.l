int				    [0-9]*

%%
[\+\-]?{int}                                                          {printf("INT(%s)\n", yytext);}
([\+\-]?{int}"."{int}([Ee][\+\-]?{int})?)|{int}[Ee][\+\-]?{int}       {printf("REAL(%s)\n", yytext);}
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
