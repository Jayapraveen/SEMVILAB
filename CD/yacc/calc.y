/*calc.y:
=====
	*/
%{
	#include <stdio.h>
%}
%token NUMBER ID NL
%left '+''-'
%left '*''/'

%%

stmt 	: E NL 		{ printf("valid=%d\n",$1); exit(0); }
	;
E 	: E '+' E 		{ $$=$1+$3; }
	| E '-' E 		{ $$=$1-$3; }
	| E '*' E 		{ $$=$1*$3; }
	| E '/' E 		{ $$=$1/$3; }
	| '(' E ')' 		{ $$=$2; }
	| ID 			{ $$=$1; }
	| NUMBER 		{ $$=$1; }
	;

%%

int yyerror(char *msg)
{
	printf("invalid%s\n",msg);
	exit(0);
}
main()
{
	yyparse();
}

/*OUTPUT
[student@localhost]$ lex calc.l
[student@localhost]$ yacc -d calc.y
[student@localhost]$ cc lex.yy.c y.tab.c
[student@localhost]$ ./a.out 
6+7*2
valid=20
[student@localhost 201301084]$ 
 */
