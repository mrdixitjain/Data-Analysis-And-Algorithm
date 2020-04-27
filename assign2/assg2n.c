#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct base
{
	char c[100];
}bas;
bas task1;
int maxbase;

typedef struct number
{
	int b;
	struct node *head;
	struct node *tail;
}num;

struct node
{
	char value;
	char *next;
	char *prev;
};

struct number createNumber(char d[])
{
	struct number n;
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	n.head=(struct node *)malloc(sizeof(struct node));
	n.tail=(struct node *)malloc(sizeof(struct node));
	n.b=0;
	int i=0;
	while(d[i]!=' ')
	{
		n.b=n.b*10+(int)(d[i]-'0');
		i++;
	}
	i++;
	int p=i;
	puts(d);
	printf("%d\n",n.b);
	int l=strlen(d);
	while(i<l)
	{
		if(i==p)
		{
			n.head->value=d[i];
			n.head->next=NULL;
			n.head->prev=NULL;
			n.tail=n.head;
		}
		else
		{	
			t->value=d[i];
			t->next=NULL;
			t->prev=n.tail;
			n.tail->next=t;
			n.tail=t;
		}
		i++;
	}
	return(n);
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
   	fp=fopen("task1.txt","r");
   	while(!feof(fp))
	{	
		char c1[10], c2[100],c3[100];
		fscanf(fp,"%[^\n]", c1);
		fscanf(fp,"%c",&z);
		fscanf(fp,"%[^\n]", c2);
		fscanf(fp,"%c",&z);
		fscanf(fp,"%[^\n]", c3);
		num n1,n2;
		//n1.b=(int)(c1[0]-'0');
		//n2.b=(int)(c2[0]-'0');
		n1=createNumber(c2);
		n2=createNumber(c3);
		printf("%c %c\n%d %d\n", n1.head->value,n1.tail->value,n1.b,n2.b);
		struct node *t1,*t2;
		t1=n1.head->next;
		t2=n2.head->next;
		printf("t=%c %c\n", t1->value,t2->value);
		exit(0);
		
	}
   	
}
