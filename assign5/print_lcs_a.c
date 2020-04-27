#include "t3a.h"

void print_lcs(int len[], int index1[], int max, int l1, int l2, char x[]){
	int i;
	for(i=l2-1; i>=0; i--){
		if(len[i]==max)
			break;
	}
	char a[l1];
	a[0]=x[index1[i]];
	int top=1;
	for(int j=i; j>=0; j--){
		j=maxt(len, i);
		a[top]=x[index1[j]];
		top++;
		i=j;
	}
	for(i=top-1; i>=0; i--){
		printf("%c", a[i]);
	}
}
		
