#include"header.h"
int insert(int n,int a[n]){
	int i
	for(i=0;i<n;i++){
		for(j=i;j>0;j--){
			if(a[j-1]>a[j]){
				swap(a[j],a[j-1]);      
				}
			}
			return 0;
			}
