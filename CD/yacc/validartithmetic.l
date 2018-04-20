/*YACC program
1. To recognize a valid arithmetic expression that usesoperator +, - , * and /.
exp.l
=====
*/
%{
	#include "y.tab.h"
%}

%%

[0-9]+ 		 { return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
\n 			 {return NL;}
. 			 {return yytext[0];}

%%

int yywrap()
{
	return 1;
}
