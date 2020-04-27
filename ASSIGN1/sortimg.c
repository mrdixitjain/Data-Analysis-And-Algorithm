#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[], int n) {
   int i, j; 
   for (i = 0; i < n-1; i++)       
	  for (j = 0; j < n-i-1; j++)  
          	if (arr[j] > arr[j+1]) 
              		swap(&arr[j], &arr[j+1]); 
   /*while(i>0){
   	printf("%d ", arr[n-i]);
   	i--;
   }*/
}

void insertion(int arr[], int n){
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
	j=0;
	/*while(j<10000){
		printf("%d ", arr[j]);
		j++;
	}*/
}

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
	j=0;
	/*while(j<10000){
		printf("%d ", arr[j]);
		j++;
	}*/
}


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
	

void main(){
	FILE *fptr, *f;
	char ch;
	int a;
	f=fopen("num.txt", "w");
	srand(time(NULL));
	a =100000;
	int z[a];
	while(a>0){
		fprintf(f,"%d ", rand()%100000);
		a=a-1;
	}
	fclose(f);
	int i=0;
	fptr=fopen("num.txt", "r");
	fscanf(fptr, "%d", &i);
	while (!feof (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}
    	insertion(z, 100000);
	while (!feof (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}
	bubbleSort(z, 100000);
	while (!feo	fprintf(f,"%d ", rand()%1000);
		a=a-1;f (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}
	selection(z, 0, 100000);
	while (!feof (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}
	quick(arr, 0, 99999);	
	while (!feof (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}	
	merge(z, 0, 99999);	
  	fclose(fptr);
}


