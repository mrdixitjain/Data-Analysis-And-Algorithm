#include<stdio.h>
#include<stdlib.h>
void read_file_by_line(FILE *fptr)
{
	char i;
	int a,t=0;
	fscanf(fptr, "%c", &i);
	while (!feof(fptr))
	{
		char c[10];
		a=0;
		while(i!='\n')
		{
			c[a]=i;
      		fscanf (fptr, "%c", &i);
      		a++;   
    	}
    	fscanf (fptr, "%c", &i);
    	if(i!='\n' && i!=EOF)
    		c[a]=i;
    	c[a]='\0';
    	puts(c);
    }
}

void main()
{
	FILE *fptr;
	fptr=fopen("task1.txt","w");
	int i;
	char z;
	scanf("%c",&z);
	while(z!='/')
	{
		fprintf(fptr, "%c", z);
		scanf("%c",&z);
	}
	fclose(fptr);
	
	fptr=fopen("task1.txt","r");
	while(!feof(fptr))
	{	
		char c1[10], d;
		fscanf(fptr,"%[^\n]", c1);
		puts(c1);
		fscanf(fptr,"%c",&d);
		char c2[100];
		fscanf(fptr,"%c[^\n]", c2);
		puts(c2);

	}
	
}
    	

