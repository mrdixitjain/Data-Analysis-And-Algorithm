#include "t3b.h"

void longest_seq(char x[], char y[]){
	int l1, l2, max=0;
	clock_t begin, end;
	double time_spent;

	begin = clock();
	l1 = strlen(x);
	l2 = strlen(y);
	int c[l1+1][l2+1];
	char b[l1][100];
	for(int i=0; i<=l1; i++)
		c[i][0]=0;
	for(int i=0; i<=l2; i++)
		c[0][i]=0;		
	int k,i,j;
	for(i=1; i<=l1; i++){
		for(j=1; j<=l2; j++){
			if(x[i-1]==y[j-1]){
				c[i][j]=1+c[i-1][j-1];
				if(max<c[i][j])
					max=c[i][j];
				b[i-1][j-1]='m';
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				if(max<c[i][j])
					max=c[i][j];
				b[i-1][j-1]='n';
			}
			else{
				c[i][j]=c[i][j-1];
				if(max<c[i][j])
					max=c[i][j];
				b[i-1][j-1]='o';
			}
		}
	}
	end = clock();
	/*printf("\nC:\n");
	for(i=0; i<=l1; i++){
		for(j=0;j<=l2; j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	printf("\nB: \n");
	for(i=0; i<l1; i++){
		for(j=0;j<l2; j++){
			printf("%c ",b[i][j]);
		}
		printf("\n");
	}*/
	printf("\nmax length: %d\n",max);
	time_spent = (double)(end-begin);
	printf("\ntime = %f\n", time_spent);
	i=print_lcs(b, x, l1-1, l2-1);
	printf("\n");
}

