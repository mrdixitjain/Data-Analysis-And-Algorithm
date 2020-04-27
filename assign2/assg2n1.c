#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int power(int a, int b)
{
    int j=1;
    while(b>0)
    {
	j=j*a;
	b--;
    }
    return(j);
}

typedef struct base
{
	char c[100];
}bas;
bas task1;
int maxbase;

typedef struct number
{
	int base;
	char nm[10];
	int decimal;
}num;

int lookup(char d)
{
	int i=0;
	for(;i<maxbase;i++)
		if(task1.c[i]==d)
		{
			return(i);
			break;
		}
	if(i==maxbase)
	{
		printf("error: not a proper notation");
		exit(0);
	}
}

int b_to_d(char c[], int base)
{
    int z=0,j,l;
    l=strlen(c);
    j=0;
    while(l-j>0)
    {
        z=z+lookup(c[l-1-j])*power(base,j);
        j++;
    }
    return(z);
}

struct number d_to_b(int z, int base)
{
    num n;
    n.decimal=z;
    n.base=base;
    int j,i=0;
    char d[10];
    while(z/base!=0)
    {
        d[i]=task1.c[z%base];
        z=z/base;
        i++;
    }
    d[i]=task1.c[z];
    for(j=0;j<=i;j++)
    	n.nm[j]=d[i-j];
    return(n);
}

void print(num n)
{
	int i=0;
	int l =strlen(n.nm);
	while(i<l)
	{
		printf("%c",n.nm[i]);
		i++;
	}
	printf("(%d)",n.base);
}

struct number createNumber(char d[])
{
	num n;
	n.base=0;
	int i=0;
	while(d[i]!=' ')
	{
		n.base=n.base*10+(int)(d[i]-'0');
		i++;
	}
	i++;
	int j=0;
	int l=strlen(d);
	while(i<l)
	{
		n.nm[j]=d[i];
		j++;
		i++;
	}
	printf("%d, %d\n",j-1, strlen(n.nm));
	n.decimal=b_to_d(n.nm, n.base);
	return(n);
}

void add(num n1, num n2)
{
	printf("\n%d %d\n", n1.decimal, n2.decimal);
	int ans=n1.decimal+n2.decimal;
	int l1=strlen(n1.nm);
	int l2=strlen(n2.nm);
	num n;
	if(n1.base>n2.base)
		n=d_to_b(ans, n1.base);
	else if(n2.base>n1.base)
		n=d_to_b(ans, n2.base);
	print(n1);
	printf(" + ");
	print(n2);
	printf(" = ");
	print(n);
		
}

void subtract(num n1, num n2)
{
	printf("\n%d %d\n", n1.decimal, n2.decimal);
	int ans=n1.decimal-n2.decimal;
	int l1=strlen(n1.nm);
	int l2=strlen(n2.nm);
	num n;
	if(ans>=0)
		if(n1.base>n2.base)
			n=d_to_b(ans, n1.base);
		else if(n2.base>n1.base)
			n=d_to_b(ans, n2.base);
	else
		if(n1.base>n2.base)
			n=d_to_b(-ans, n1.base);
		else if(n2.base>n1.base)
			n=d_to_b(-ans, n2.base);
	print(n1);
	printf(" - ");
	print(n2);
	printf(" = ");
	if(ans<0)
		printf("-");
	print(n);
}
		
		
int initializeBase(FILE *fptr)
{
	char z;
	int i=0;
	while(!feof(fptr))
    {
    	fscanf(fptr,"%c", &z);
    	if(z!=' ')
    	{
    		task1.c[i]=z;
    		i++;
    	}
    }
    return(i-1);
}	

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
