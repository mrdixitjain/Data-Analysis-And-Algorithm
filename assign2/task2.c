#include<stdio.h>
#include<string.h>

void swap(int *a, int *b)
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int max(int l[], int i, int z, int t[])
{
	if(z>0)
	{
		int j=z,a;
		int max1 = l[z-1];
		a=z-1;
		while(j>0)
		{
			if(l[j-1]>max1)
			{
				if(t[j-1]<t[i])
				{
					max1=l[j-1];
					a=j-1;
				}
			}
			j--;
		}
		if(t[a]<t[i])
		{
			return(l[a]);
		}
		else
		{
			return(max(l,i,a,t));
			/*else
			{
				printf("h\n");
				swap(l[a],l[z-1]);
				printf("\ne\n");
				return(max(l,i,z-1,t));
			}*/
		}
	}
	else
		return(0);
}

void main()
{
	char a[100];
	gets(a);
	int l[51], t[51];
	int i=0,j=0,k=0;
	int s=strlen(a);
	while(j<s)
	{
		i=0;
		while(a[j]!=' ' && j<s)
		{
			i=i*10+(int)(a[j]-'0');
			j++;
		}
		t[k]=i;
		k++;
		j++;
	}
	j=0;
	for(i=0;i<k;i++)
	{
		if(j==0)
			l[j]=1;
		else
			l[j]=1+max(l,j,j,t);
		printf("l[%d]=%d\n",j,l[j]);
		j++;
	}
	int max1 = l[0];
	i=0;
	while(i<j)
	{
		if(l[i]>max1)
		{
			max1=l[i];
		}
		i++;
	}
	printf("length of longest monotone subsequence is %d\n", max1);
}
