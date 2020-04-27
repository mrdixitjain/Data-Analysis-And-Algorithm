#include "t3a1.h"

void longest_seq(char x[], char y[], int index1[][100], int len[][100]){
	int top1=0, top2=0, max=0, max1=0;
	clock_t begin, end;
	double time_spent;
	printf("1\n");
	begin = clock();
	l1 = strlen(x);
	l2 = strlen(y);
	printf("l1=%d, l2=%d\n", l1, l2);
	int k,i,j,t=0;
	for(i=0; i<l1; i++){
		for(j=0; j<l2; j++){
			if(y[j]==x[i]){
				printf("i=%d,j=%d\n", i, j);
				index1[i][j]=j;
				for(k = i; k>=0; k--){
					for(t=j; t>=0; t--){
						printf("k=%d,t=%d\n", k, t);
						break;
						if(index1[k][t]<index1[i][j] && index1[k][t]!=-1){
							t=len[k][t]+1;
						}
						else
							t=1;
						if(max1<t){
							max1=t;
							len[i][j]=t;
						}
					}
				}
				if(max<len[i][j])
					max=len[i][j];
			}
		}
	}
	for(i=0; i<l1; i++){
		for(j=0; i<l2; i++)
			printf("%d ",len[i][j]);
		printf("\n");
	}
	for(i=0; i<l1; i++){
		for(j=0; i<l2; i++)
			printf("%d ",index1[i][j]);
		printf("\n");
	}
	printf("\nmax=%d\n", max);
}/*
	
	
	
	
	
	
	
	
	
	
	
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
*/
