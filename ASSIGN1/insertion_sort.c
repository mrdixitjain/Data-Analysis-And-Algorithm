#include "sort.h"
void insertion_sort(int arr[], int n){
	int i,j;
	for(i = 0; i<n-1; i++){
		if(arr[i]>arr[i+1]){
			swap(&arr[i], &arr[i+1]);
			j = i;
			while(arr[j]<arr[j-1] && j>0){
				swap(&arr[j], &arr[j-1]);
				j=j-1;
			}
		}
		
	}
}
