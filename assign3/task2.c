#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	printf("enter size of your text and pattern: ");
	int n,m;
	scanf("%d %d",&n,&m);
	char t[n+1],p[n+1];
	printf("enter your text: ");
	scanf("%s",t);
	printf("enter your pattern: ");
	scanf("%s",p);
	int j=0;
	int ans[n-m+1];
	int k=0,l,i;
	for(i=0;i<n-m+1;i++)
	{
		j=0;
		l=i;
		while(t[i]==p[j] && j<m)
		{
			i++;j++;
		}
		if(j==m)
		{
			ans[k]=l;
			k++;
		}
		i=l;
	}
	printf("pattern occurs for %d times",k);
	if(k!=0)
		printf(" at shift ");
	for(i=0;i<k;i++)
		printf("%d ",ans[i]);
}
			
	
