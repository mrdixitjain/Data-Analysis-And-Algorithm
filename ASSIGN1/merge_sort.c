#include "sort.h"
void Merge(int arr[], int low, int mid, int high){
	int b[high+1];
	int i,j,k;
	j=0;
	i=low;
	k=mid+1;
	while(i<=mid && k<=high){
		if(arr[i]<=arr[k]){
			b[j]=arr[i];
			i++;
		}
		else{
			b[j]=arr[k];
			k++;
		}
		j++;
	}
	if(i>mid){
		while(k<=high){
			b[j]=arr[k];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid){
			b[j]=arr[i];
			i++;
			j++;
		}
	}
	j=0;
	for(i=low;i<=high;i++){
		arr[i]=b[j];
		j++;
	}
}
void merge(int arr[], int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		merge(arr, low, mid);
		merge(arr, mid+1, high);
		Merge(arr, low, mid, high);
	}
}
