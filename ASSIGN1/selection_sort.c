#include "sort.h"
void selection(int arr[], int n){
	int i,j,k;
	for(i=0; i<n; i++){
		int min = arr[i];
		k = i;
		for(j=i+1; j<n; j++){
			if(min>arr[j]){
				min=arr[j];
				k = j;
			}
		}
		if(k!=i)
			swap(&arr[i], &arr[k]);
	}
}
