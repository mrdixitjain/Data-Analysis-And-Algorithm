#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char t[100]="HXYX X DYBXABXYCDYXZYZY";
	int a[100],i,j=0,l,k;
	l=strlen(t);
	for(i=0;i<l;i++)
	{
		if(t[i]=='X')
		{
			a[j]=0;
			j++;
		}
		else if(t[i]=='Y')
		{
			for(k=0;k<j;k++)
				a[k]=a[k]+1;
		}
	}
	k=0;
	for(i=0;i<j;i++)
		k=k+a[i];
	printf("%d",k);
}
