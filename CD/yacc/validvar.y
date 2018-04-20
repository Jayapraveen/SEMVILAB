/*2. To recognize a valid variable which starts with a letterfollowed by any number of letters or digits
*/
%{
	#include<stdio.h>
	#include<ctype.h>
	#include<stdlib.h>
%}
%token let dig
%%
sad	: let recld '\n' 	{printf("accepted\n"); exit(0);}
	| let '\n' 		{printf("accepted\n"); exit(0);}
	|
	|error 			{yyerror("rejected\n");exit(0);}
	;
recld : let recld
	| dig recld
	| let
	| dig
	;
%%
yylex(){
        char ch;
        while((ch=getchar())==' ');
        if(isalpha(ch))
                return let;
        if(isdigit(ch))
                return dig;
        return ch;
}
yyerror(char *s){
        printf("%s\n",s);
        exit(0);
}
main(){
        printf("ENTER A variable : ");
        yyparse(); 
}
/*OUTPUT
 [student@localhost]$ yacc valid.y 
[student@localhost]$ cc y.tab.c
[student@localhost]$ ./a.out 
ENTER A variable : count5
accepted	
[student@localhost]$ ./a.out 
ENTER A variable : 5count
syntax error
*/