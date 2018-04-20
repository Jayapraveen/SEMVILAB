/*3. Implementation of Calculator using LEX and YACC

calc.l:
=====
*/
%{
	#include "y.tab.h"
	extern intyylval;
%}

%%

[0-9]+ 		 { yylval=atoi(yytext);return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
\n 			 {return NL;}
. 			 {returnyytext[0];}

%%

intyywrap()
{
	return 1;
}
