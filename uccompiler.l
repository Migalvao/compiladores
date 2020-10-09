int				    [0-9]*

%%
["+""-"]?{int}"."?{int}([Ee]["+""-"]?{int})?
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
