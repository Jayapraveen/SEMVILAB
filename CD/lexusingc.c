/* Lexical Analyzer using C */
#include<stdio.h>
void main()
{
	char c,a[100];
	FILE *fptr;
	fptr=fopen("sample.txt","r");
	while(!feof(fptr))
	{
		fscanf(fptr,"%s",a);
		if(!strcmp(a,"int")||!strcmp(a,"float"))
 		{
		  printf("\n%s-keyword",a);
		  fseek(fptr,1,1);
		  l:c=fgetc(fptr);
		  if(c==',')
		  {
			printf("\n%c-others\n",c);
			goto l;
		  }
		  if(c!=';')
		  {
			if(c=='=')
			{
				printf("\n%c-operator",c);
				c=fgetc(fptr);
				printf("\n%c-constant",c);
			}
			printf("\n%c-identifier",c);
			goto l;
		  }
		}
		else if(a[0]=='#')
			printf("\n%s-preprocessor directive",a);
		else if(!strcmp(a,"main()"))
			printf("\n%s-identifier",a);
		else
			printf("\n%s-others\n",a);
	}
	fclose(fptr);
}
/*Input:Sample.txt
#include<stdio.h>
void main()
{
int a;
float b,c;
}


Output:
#include<stdio.h>-preprocessor directive
void-others
main()-identifier
{-others
int-keyword
a-identifier
float-keyword
b-identifier
,-others
c-identifier
}-others
*/