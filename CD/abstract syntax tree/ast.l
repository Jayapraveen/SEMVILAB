/*Abstract Syntax Tree
ast.l:
======
*/
%{
#include "y.tab.h"
extern int yylval;
%}
%%
[0-9]+   {yylval = (int)yytext; return NUMBER;}
[ \t\n]  ;
"+"      return(PLUS);
"-"      return(MINUS);
"*"      return(TIMES);
"("      return(LEFT_PARENTHESIS);
")"      return(RIGHT_PARENTHESIS);
";"      return(END);
%%
int yywrap ( ) 
{ 
	return 1;
}
