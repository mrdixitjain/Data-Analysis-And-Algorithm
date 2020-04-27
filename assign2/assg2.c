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

int b_to_d(char c[], int base)
{
    int z,j,l,i=0;
    while(c[i]!=' ')
        i++;
    i++;
    l=strlen(c);
    j=0;
    while(l-j>i)
    {
        z=z+(int)(c[l-1-j]-'0')*power(base,j);
        j++;
    }
    return(z);
}

int d_to_b(int a[],int z, int base)
{
    int i=0;
    while(z/base!=0)
    {
        a[i]=z%base;
        z=z/base;
        i++;
    }
    a[i]=z;
    return(i);
}

int addition(int a[], int c[], int e[], int n2, int n1,int b1)
{
    int i=0,j=0,carry=0;
    while(n2-j>0)
    {
        e[j]=a[i]+c[n2-1-j]+carry;
	if(e[j]>=b1)
	{
	    e[j]=e[j]%b1;
	    carry=1;
	}
	else
	    carry=0;
	j++;
	i++;
    }
    while(i<=n1)
    {
	e[j]=a[i]+carry;
	if(e[j]>=b1)
	{
	    e[j]=e[j]%b1;
	    carry=1;
	}
	else
	    carry=0;
	j++;
	i++;
    }
    return(j-1);
}

int subtract(int a[], int c[], int e[], int n2, int n1, int b1)
{
	int i=0,j=0;
	while(n2-i>=0)
    {
    	if(c[n1-i-1]>=a[i])
    		e[i]=c[n1-i-1]-a[i];
    	else
    	{
    		e[i]=b1+c[n1-1-i]-a[i];
    		c[n1-i-2]=c[n1-i-2]-1;
    	}
    	i++;
    }
    while(i<n1)
    {
		if(c[i]>=0)
			e[i]=c[n1-i-1];
		else
		{
			e[i]=b1+c[n1-1-i];
    		c[n1-i-2]=c[n1-i-2]-1;
		}
		i++;
    }
    i--;
    return(i);

}

int number(int c[], char c1[])
{
	int i=0,j,l;
    while(c1[i]!=' ')
    	i++;
    i++;
    j=0;
	l=strlen(c1);
    while(i<l)
    {
        c[j]=(int)(c1[i]-'0');
        i++;
        j++;
    }
	return(j);
}

void print(int e[], int j)
{
	while(j>=0)
	{
    	printf("%d",e[j]);  
    	j--;
	}
}

void main()
{
    int n1,n2,b1,b2,z=0;
    char c1[10],c2[10];
    gets(c1);
    gets(c2);
    int c[10],a[10],e[10];
    int i=0;
    b1=(int)(c1[0]-'0');
    b2=(int)(c2[0]-'0');
    int l,j=0;
    int carry=0;
    if(b1>b2)
    {
        z=b_to_d(c2,b2);
        n1=d_to_b(a, z, b1);
		n2=number(c,c1);
            j=addition(a,c,e,n2,n1,b1);
		else
            j=addition(a,c,e,n1,n2,b1);
    }
    else if(b2>b1)
    {
        z=b_to_d(c1,b1);
        n1=d_to_b(a, z, b2);
		n2=number(c,c2);
        if(n2>=n1)
            j=addition(a,c,e,n2,n1,b2);
		else
            j=addition(a,c,e,n1,n2,b2);
		print(e,j);
    }
    else
    {
		if(n2>=n1)
            j=addition(a,c,e,n2,n1,b2);
		else
            j=addition(a,c,e,n1,n2,b2);
		print(e,j);
    }
}
