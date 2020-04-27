#include "smart_calci.h"

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
	n.decimal=b_to_d(n.nm, n.base);
	return(n);
}

void add(num n1, num n2)
{
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
	printf("\n");
		
}

void subtract(num n1, num n2)
{
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
	printf("\n");
}
