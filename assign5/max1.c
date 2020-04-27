#include "t3a.h"

int maxt(int index1, int i){
	int max2=0;
	for(int j=i; j>=0; j--){
		if(index1[j]>max2 && index1[j]<index1[i]){
			max2=index1[j];
		}
	}
	return(max2);
