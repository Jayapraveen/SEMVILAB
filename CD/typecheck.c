#include<stdio.h>
#include<string.h>

struct symtab{
	char symname[25];
	char type[25];
}symtab;
struct symtab s1[20];
int findtype(char t, int n){
	int i;
	for(i=0;i<n;i++){
		if(s1[i].symname[0]==t)
			return i;
	}
	return 0;
}
void main() {
	char s[20];
	char flag[20]="//TypeCheck";
	double op1,op2,interrslt;
	int flag2=0,n,i;
	int tr,top1,top2;
	FILE *fp1,*fp2;

	printf("Enter the number of identifiers : ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("Enter identifier name and its type : ");
		scanf("%s",&s1[i].symname);
		scanf("%s",&s1[i].type);
	}
	fp1 = fopen("input.txt","r");
	fp2 = fopen("output.txt","w");
	fscanf(fp1,"%s",s);
	while(!feof(fp1)) {
		if(strcmp(s,flag)==0) {
			flag2 = 1;
		}
		if(flag2==1) {	
			fscanf(fp1,"%s",s);
						
			tr = findtype(s[0],n);
			top1 = findtype(s[2],n);
			top2 = findtype(s[4],n);

			if(strcmp(s1[tr].type,s1[top1].type)==0 &&	strcmp(s1[tr].type,s1[top2].type)==0) {
				fprintf(fp2,"/*VALID EXP*/\n");
			else 
				fprintf(fp2,"/*TYPE MISMATCH*/\n");
			flag2=0;
		} 
		fprintf(fp2,"%s\n",s);
		fscanf(fp1,"%s",s);
	}
	fclose(fp1);
	fclose(fp2);
}

/*
OUTPUT
[student@localhost ~]$ cc typecheck.c 
[student@localhost ~]$ ./a.out 
Enter the number of identifiers : 4
Enter identifier name and its type : a in
Enter identifier name and its type : b in
Enter identifier name and its type : c in
Enter identifier name and its type : d float
[student@localhost ~]$cat input.txt
#include<stdio.h>
int main()
{
int a,b,c,d;
//TypeCheck
a=b+c;
//TypeCheck
b=c+d;
}
[student@localhost ~]$cat Output.txt
#include<stdio.h>
int
main()
{
int
a,b,c,d;
/*VALID EXP*/
a=b+c;
/*TYPE MISMATCH*/
b=c+d;
}
*/