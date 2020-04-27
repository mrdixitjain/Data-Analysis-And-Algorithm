#include "t3a1.h"

void main(){
	//printf("enter string X: ");
	char x[100];
	int index1[100][100];
	int len[100][100];

	gets(x);
	//printf("enter string Y: ");
	char y[100];
	gets(y);
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			index1[i][j]=-1;
			len[i][j]=0;
		}
	}
	l1 = strlen(x);
	l2 = strlen(y);
	if(l1>l2)
		longest_seq(x, y, index1, len);
	else
		longest_seq(y, x, index1, len);
}
	
