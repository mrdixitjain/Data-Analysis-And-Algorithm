#include"header.h"
int selection(int n,int a[n]){
	int i,j,c,k,m;
	for(i=0;i<n-1;i++){
		c=0;
		for(j=i+1;j<n-1;j++){
			if(a[i]>a[j]){
				if(c==0){
					k=a[i];
					c++;
					}
			a[i]=a[j];
			m=j;
			}
			a[m]=k;
			}}}
