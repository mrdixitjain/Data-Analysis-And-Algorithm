#include<stdio.h>

void main()
{
	printf("enter size of array: ");
	int n;
	scanf("%d",&n);
	int x[n];
	printf("enter elements of array\n");
	for(int i=0; i<n;i++)
		scanf("%d",&x[i]);
	int max=0,max1=0,i,j;
	FILE *fp;
	fp=fopen("output1.txt","w");
	for(i=0;i<n;i++)
	{
		max=0;
		for(j=i;j<n;j++)
		{
			max=max+x[j];
			if(max>max1)
			{
				fp=fopen("output1.txt","w");
				fprintf(fp,"%d %d\n",i,j);
				max1=max;
			}
			else if(max==max1)
			{
				fprintf(fp,"%d %d\n",i,j);
			}
			
		}
	}                                
	fclose(fp);
	fp=fopen("output1.txt","r");
	char c[10],d;
	fscanf(fp,"%[^\n]",c);
	fscanf(fp,"%c",&d);
	printf("max = %d\n",max1);
	while(!feof(fp))
	{
		puts(c);
		fscanf(fp,"%[^\n]",c);
		fscanf(fp,"%c",&d);
	}
	fclose(fp);
}
		
				
