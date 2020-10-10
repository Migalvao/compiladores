
%%
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|[0-9]|"_")*		{printf("ID");}
'([^(\n|')]|[0-7]{1,3}|\"\\n\"|\\t|\\\\|\\'|\\\")'	{printf("CHRLIT");}
.	        					ECHO;
\n							;
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
