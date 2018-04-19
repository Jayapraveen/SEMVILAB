#include<stdio.h>
//#include<conio.h>
void strip(char *s) {
    char *p2 = s;
    while(*s != '\0') {
    	if(*s != '\t' && *s != '\n' && *s != '&' && *s != '"') {
    		*p2++ = *s++;
    	} else {
    		++s;
    	}
    }
    *p2 = '\0';
}
void main()
{
  FILE *fp;
  int addr = 1000,flag1=0,flag=0;
  char str[100][100];
  char *ch;
  fp = fopen("strg.txt","r");
  while(!feof(fp))
  {
    fread(str,sizeof(str),1,fp);
    ch = strtok(str," ;");
    while(ch != NULL)
    {
       strip(ch);
      	if(strcmp(ch,"int")==0 )
	{
	  flag1 = 1;
	  flag++; 
	}
	else if(strcmp(ch,"float")==0 )
	{
	  flag1 = 2;
	  flag++;
	}
	else if(strcmp(ch,"long")==0)
	{
	  flag1 = 3;
	  flag++;
	}
	else if(strcmp(ch,"char")==0 )
	{
	  flag1 = 4;
	  flag++;
	}
	else if(strcmp(ch,"double")==0)
	{
	  flag1 = 5;
	  flag++;
	}
	else
	{
	  if(flag1>0)
	  {
	    if(flag1==1)
	    {
	      addr+=sizeof(int);
	      printf("%s   %d\n",ch,addr);
	    }
	    else if(flag1==2)
	    {
	      addr+=sizeof(float);
	      //printf("%d",sizeof(double));
	      printf("%s   %d\n",ch,addr);
	    }
	    else if(flag1==3)
	    {
	      addr+=sizeof(long);
	      printf("%s   %d\n",ch,addr);
	    }
	    else if(flag1==4)
	    {
	      addr+=sizeof(char);
	      printf("%s   %d\n",ch,addr);
	    }
	    else if(flag1==5)
	    {
	      addr+=sizeof(double);
	      printf("%s   %d\n",ch,addr);
	    }
	  }
	}
	ch = strtok(NULL," ;");
    }
}
}
/*
strg.txt
int a;
double b;
long c;

Output:

[student@localhost ~]$ cc storage.c
[student@localhost ~]$ ./a.out
a   1004
b   1012
c   1016
*/