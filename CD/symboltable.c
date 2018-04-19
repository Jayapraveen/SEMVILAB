/*SYMBOL TABLE*/
#include <stdio.h>
#include <string.h>
struct symtab 
{ 
   char id; 
   char type[10]; 
   int size; 
   char scope[25]; 
}; 
void main() 
{ 
  struct symtab s[15]; 
  int sindex=0,i,flag=0; 
  char scope[25]; 
  char c,a[100]; 
  FILE *fptr; 
  fptr=fopen("sample.txt","r"); 
  strcpy(scope,"global");
  while(!feof(fptr)) 
  { 
    fscanf(fptr,"%s",a); 
    if(strcmp(a,"main()")==0)
	strcpy(scope,"local"); 
    if(!strcmp(a,"int")) 
    { 
	fseek(fptr,1,1); 
	c=fgetc(fptr); 
	s[sindex].id = c; 
	strcpy(s[sindex].type,"int");
	s[sindex].size = 2; 
	strcpy(s[sindex].scope,scope); 
	sindex++; 
    } 
    if(!strcmp(a,"float")) 
    { 
	fseek(fptr,1,1); 
	c=fgetc(fptr); 
	s[sindex].id = c; 
	strcpy(s[sindex].type,"float"); 
	s[sindex].size = 4; 
	strcpy(s[sindex].scope,scope); 
	sindex++; 
    } 
    if(!strcmp(a,"char")) 
    { 
	fseek(fptr,1,1); 
	c=fgetc(fptr); 
	s[sindex].id = c; 
	strcpy(s[sindex].type,"char"); 
	s[sindex].size = 1; 
	strcpy(s[sindex].scope,scope); sindex++; 
    } 
  } 
  fclose(fptr); 
  printf("Name\tType\tSize\tScope\n"); 
  printf("===========================\n");
  for(i=0;i<sindex;i++)
    printf("%c\t%s\t%d\t%s\n",s[i].id,s[i].type,s[i].size,s[i].scope);
}	

/*Input: sample.txt
#include<stdoi.h>
int g;
void main()
{
	int a;
	float c;
	char e;
}

/*Ouput
Name    Type    Size    Scope
==============================
g       int     	2      global
a       int     	2      local
c       float   	4      local
e       char    	1      local
*/