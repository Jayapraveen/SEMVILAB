/*CONTROL FLOW ANALYSIS*/
#include<stdio.h>
#include<string.h>
char atEnd(char a[128])
{
	return a[strlen(a)-1];
}
void main()
{
	FILE* fp1;
	char oneword[128],c;
	int i=0;
	fp1=fopen("sample.txt","r+");
	if(fp1==NULL)
	{
		printf("file not found");
		return;
	}
	do{
		c=fscanf(fp1,"%s",oneword);
		if(atEnd(oneword)==':')
		{
			printf("\n %s goes to ",oneword);
			do{
				c=fscanf(fp1,"%s",oneword);
				if(strcmp("goto",oneword)==0)
				{
					c=fscanf(fp1,"%s",oneword);
					printf("%s",oneword);
				}
			}while(c!=EOF&&atEnd(oneword)!=':');
			i++;
		}
		fseek(fp1,-strlen(oneword),SEEK_CUR);
		printf("\n");
	}
	while(c!=EOF);
}
/*
INPUT FILE: sample.txt

b1:
a=a+1
b=b+a
if b<a
goto b2
else goto b1
b2:
b--
goto b1

OUTPUT:
b1: goes to b2 b1
b2: goes to b1
*/
