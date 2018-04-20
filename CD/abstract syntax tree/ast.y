/*
ast.y:
======
*/
%{
#include <stdio.h>
#include <stdlib.h>
	#include <string.h>
typedef struct node
{
		struct node *left;
	struct node *right;
	char *token;
} node;
node *mknode(node *left, node *right, char *token);
void printtree(node *tree);
#define YYSTYPE struct node *
%}
%start lines
%token NUMBER PLUS MINUS TIMES L_PAREN R_PAREN END
%left   PLUS    MINUS
%left   TIMES

%%

lines:  /* empty */ 
        | lines line /* do nothing */
line   : exp END     		    { printtree($1); printf("\n");}
         ;
exp    : term             	    {$$ = $1;}
         | exp PLUS term       {$$ = mknode($1, $3, "+");}
         | exp MINUS term      {$$ = mknode($1, $3, "-");}
         ;
term   : factor                {$$ = $1;}
         | term TIMES factor   {$$ = mknode($1, $3, "*");}
         ;
factor : NUMBER                {$$ = mknode(0,0,(char *)yylval);}
         | L_PAREN exp R_PAREN {$$ = $2;}
         ;

%%
int main ()
{     
	returnyyparse ( );
}
node *mknode(node *left, node *right, char *token)
{
	node *newnode = (node *)malloc(sizeof(node));
	char *newstr = (char *)malloc(strlen(token)+1);

	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}
void printtree(node *tree)
{
	inti;
	if (tree->left || tree->right)
		printf("(");
	printf(" %s ", tree->token);
	if (tree->left)
		printtree(tree->left);
	if (tree->right)
		printtree(tree->right);
	if (tree->left || tree->right)
		printf(")");
}
int yyerror (char *s)
{
	fprintf (stderr, "%s\n", s);
}
/*OUTPUT
[student@localhost]$ lex ast.l
[student@localhost]$ yacc -d ast.y
[student@localhost]$ cc lex.yy.c y.tab.c
[student@localhost]$ ./a.out
8+9*2
;
( +  8 ( *  9  2 ))
3+4
;
( +  3  4 )
[student@localhost]$
*/