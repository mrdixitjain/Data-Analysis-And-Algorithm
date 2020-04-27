# include "head.h"
void selection_sort(int A[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(A[j]<A[i]){
			swap(A[i],A[j]);	
			}
		}
	}
}
