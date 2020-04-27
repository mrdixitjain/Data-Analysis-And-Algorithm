#include "t3a.h"

int maxt(int len[], int i){
	int max2=-1,t;
	for(int j=i; j>=0; j--){
		if(len[j]>max2 && len[j]<len[i]){
			max2=len[j];
			t=j;
		}
	}
	return(t);
}
