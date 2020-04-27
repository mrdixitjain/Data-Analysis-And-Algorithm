#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min=INT_MAX:

int mult(int a[], int i, int n){
	if(i==0 || n==0)
		return 0;
	for(int k=0; k<n; k++){
		int q=matrix(a, i, k) + matrix(a, k+1, n) + a[i-1]*a[k]*a[n]
	if(q
}

void main(){
	int a[] = {1, 2, 3, 4};
	int z = mult(a, 1, 3);
	printf("%d", z);
}
