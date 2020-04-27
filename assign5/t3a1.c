#include "t3a.h"

void longest_seq(char x[], char y[]){
	int top1=0, top2=0, max=0, max1=0;
	clock_t begin, end;
	double time_spent;

	begin = clock();
	l1 = strlen(x);
	l2 = strlen(y);
	printf("l1=%d, l2=%d\n", l1, l2);
	int k,i,j,t=0;
	for(i=0; i<l2; i++)
	{
		for(j=0; j<l1; j++)
		{
			if(y[i]==x[j])
			{
				max1=0;
				for(k=0; k<top1; k++)
				{
					if(index1[k]==j)
					{
						break;
					}
				}
				if(k==top1)
				{
					index1[top1]=j;
					for(k=top1; k>=0; k--)
					{
						if(index1[k]<index1[top1] && len[k]!=0)
						{
							t=len[k]+1;
						}
						else
						{
							t=1;
						}	
						if(max1<t){
							max1=t;
							len[top1]=t;
						}							
					}
					if(max<len[top1])
					{
						max=len[top1];
					}
					j++;
					while(j<l1)
					{
						if(y[i]==x[j])
						{
							for(k=top1-1; k>=0; k--)
							{
								if(index1[k]<j)
								{
									t=len[k]+1;
									break;
								}
							}
							if(max<t)
							{
								max=t;
								len[top1]=t;
								index1[top1]=j;
							}
						}
						j++;
					}
				}				
			}
		}
		top1++;
		/*printf("\n");
		for(int Z=0; Z<top1; Z++)
			printf("%d ",len[Z]);
		printf("\n");
		for(int Z=0; Z<top1; Z++)
			printf("%d ",index1[Z]);
		printf("\n");*/
	}
	end = clock();
	for(int i=0; i<top1; i++)
		printf("%d ",len[i]);
	printf("\n");
	for(int i=0; i<top1; i++)
		printf("%d ",index1[i]);
	printf("\nmax length = %d\n", max);
	time_spent = (double)(end-begin);
	printf("\ntime = %f\n", time_spent);
	printf("lcs: ");
	print_lcs(len, index1, max, l1, l2, x);
	printf("\n");
}

