/*exp.y
======
*/
%token NUMBER ID NL
%left '+''-'
%left '*''/'
%%
stmt	:E NL 	{printf("valid  \n"); exit(0);}
	;
E	:E'+'E
	|E'-'E
	|E'*'E
	|E'/'E
	|'('E')'
	|ID
	|NUMBER
	;

%%

int yyerror(char *msg)
{
	printf(“Invalid\n%s",msg);
	exit(0);
}

main()
{
	yyparse();
}

/*OUTPUT
[student@localhost 201301084]$ yacc -d exp.y
[student@localhost 201301084]$ cc lex.yy.c y.tab.c
[student@localhost 201301084]$ ./a.out 
8+9
valid
[student@localhost 201301084]$ ./a.out 
89+
invalidsyntax error
*/