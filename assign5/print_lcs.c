#include "t3b.h"

int print_lcs(char b[][100], char x[], int i, int j){
	int k;
	if(i<0 || j<0){
		return(0);
	}
	else if(b[i][j]=='m'){
		k=print_lcs(b, x, i-1, j-1);
		printf("%c", x[i]);
		
	}
	else if(b[i][j]=='n'){
		k=print_lcs(b, x, i-1, j);
	}
	else if(b[i][j]=='o'){
		k=print_lcs(b, x, i, j-1);
	}
}
		
