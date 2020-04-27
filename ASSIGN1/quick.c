#include "head.h"
int partition (int a[], int low, int high) 
{ 
    int pivot = a[high];   
    int i = (low - 1); 
    int t; 
  
    for (int j = low; j <= high- 1; j++) 
    {  
        if (a[j] <= pivot) 
        { 
            i++; 
	    t=a[i];
	    a[i]=a[j];
	    a[j]=t;
        } 
    } 
	    t=a[i+1];
	    a[i+1]=a[high];
	    a[high]=t; 
    return (i + 1); 
} 
  

void quick_sort(int a[], int low, int high) 
{ 
    if (low < high) 
    {
        int p = partition(a, low, high);
        quick_sort(a, low, p - 1); 
        quick_sort(a, p + 1, high); 
    } 
} 
