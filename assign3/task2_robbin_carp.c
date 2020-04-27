#include "power.h"

void main()
{
	//printf("enter size of your text and pattern: ");
	int n,m;
	//scanf("%d %d",&n,&m);
	char t[]="abcbabcbabcbbcbccbabcbacbcbababcb",p[]="abcb";
	//printf("enter your text: ");
	//scanf("%s",t);
	//printf("enter your pattern: ");
	//scanf("%s",p);
	n=strlen(t);m=strlen(p);
	int j=0;
	int ans[n-m+1];
	int k=0,l=0,i,hashp=0;
	int hasht[n-m+1];
	while(k<m)
	{
		l=l+(power(10,m-k-1)*((int)(t[k]-'a')+1))%11;
		hashp=hashp+(power(10,m-k-1)*((int)(p[k]-'a')+1))%11;
		k++;		
	}
	hasht[0]=l;
	for(i=0;i<n-m+1;i++)
	{
		if(hasht[i]==hashp)
		{
			k=0;
			l=i;
			while(k<m && p[k]==t[i])
			{
				i++;k++;
			}
			if(k==m)
			{
				ans[j]=l;
				j++;
			}
			i=l;
		}
		if(i+1<n-m+1)
		{
			k=0;
			l=0;
			while(k<m)
			{
				l=l+(power(10,m-k-1)*((int)(t[k]-'a')+1))%11;
				k++;
			}
			hasht[i+1]=l;
		}
	}
	printf("\npattern occurs for %d times",j);
	if(j!=0)
		printf(" at shift ");
	for(i=0;i<j;i++)
		printf("%d ",ans[i]);
	for(i=0;i<n-m+1;i++)
		printf("%d ",hasht[i]);
	
}
