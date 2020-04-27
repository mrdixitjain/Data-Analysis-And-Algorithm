#include<stdio.h>
#include<stdlib.h>
#include "sort.h"
void main(){
	FILE *fptr, *f;
	char ch;
	int a;
	f=fopen("num.txt", "w");
	srand(time(NULL));
	a =100;
	int z[a];
	printf("a\n");
	while(a>0){
		fprintf(f,"%d ", rand()%100000);
		a=a-1;
	}
	printf("b\n");
	fclose(f);
	int i=0;
	fptr=fopen("num.txt", "r");
	fscanf(fptr, "%d", &i);
	while (!feof (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}
	printf("c\n");
    	insertion_sort(z, 100);
	printf("d\n");
	while (!feof (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}
	bubble_sort(z, 100);
	printf("e\n");
	while (!feof (fptr)){
		fprintf(f,"%d ", rand()%1000);
		a=a-1;
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}
	selection(z, 100);
	printf("f\n");
	while (!feof (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}
	quick(z, 0, 99);
	printf("g\n");	
	while (!feof (fptr)){
		z[a]=i;
      		fscanf (fptr, "%d", &i);  
      		a++;    
    	}	
	merge(z, 0, 99);
	printf("h\n");
  	fclose(fptr);
}

