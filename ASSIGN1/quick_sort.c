#include "sort.h"
void quick(int arr[],int low, int high){
	int i,j;
	if(low<high){
		int pivot = arr[high];
		j=low-1;
		for(i = low; i<=high-1; i++)
			if(arr[i]<=pivot){ 
				j++;
				swap(&arr[j], &arr[i]);
			}
		swap(&arr[j+1], &arr[high]);
		quick(arr, low, j);
		quick(arr, j+2, high);	
	}
}

