#include "t3a.h"

void main(){
	//printf("enter string X: ");
	char x[100];
	gets(x);
	//printf("enter string Y: ");
	char y[100];
	gets(y);
	for(int i=0; i<100; i++){
		index1[i]=-1;
		len[i]=0;
	}
	l1 = strlen(x);
	l2 = strlen(y);
	if(l1>l2)
		longest_seq(x, y);
	else
		longest_seq(y,x);
}
	
