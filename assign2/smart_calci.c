#include "smart_calci.h"

void main()
{
    FILE *fptr, *fp;
    fptr = fopen("base.txt","w");
    char str[50],z;
    gets(str);
    int i=0;
    fprintf(fptr,"%s", str);
    fclose(fptr);
    fptr=fopen("base.txt", "r");
    
    maxbase= initializeBase(fptr);
    
    fclose(fptr);
    fp=fopen("task1.txt","w");
   	i=0;
   	while(!NULL)
   	{
   		scanf("%c",&z);
   		if(z=='/')
   			break;
   		fprintf(fp, "%c", z);
   	}
   	fclose(fp);
    printf("\nmaxbase=%d\n", maxbase);
   	fp=fopen("task1.txt","r");
   	while(!feof(fp))
	{	
		char c1[10], c2[100],c3[100];
		fscanf(fp,"%[^\n]", c1);
		fscanf(fp,"%c",&z);
		fscanf(fp,"%[^\n]", c2);
		fscanf(fp,"%c",&z);
		fscanf(fp,"%[^\n]", c3);
		fscanf(fp,"%c",&z);
		num n1,n2;
		n1=createNumber(c2);
		n2=createNumber(c3);
		if(n1.base>maxbase || n2.base>maxbase)
		{
			printf("base error\n");
			exit(1);
		}
		if(!strcmp(c1, "add"))
			add(n1,n2);
		else if(!strcmp(c1,"subtract"))
			subtract(n1,n2);
		else
		{
			printf("wrong operation");
			exit(2);
		}	
	}
}
