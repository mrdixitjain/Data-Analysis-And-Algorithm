#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int n;

bool check(int q[], int i){
	int j;
	for(j=1; j<i; j++)
		if(q[j]-q[i]==0 || q[j]-q[i]==j-i || q[j]-q[i]==-(j-i))
			break;
	if(j==i)
		return true;
	return false;
}

void nq(int q[], int i){
	if(i>n){
		for(int j=1; j<=n; j++)
			printf("%d ", q[j]);
		printf("\n");
	}
	else{
		for(int j=1; j<=n; j++){
			q[i]=j;
			if(check(q, i)){
				nq(q, i+1);
			}
		}
	}
}
		

int main(){
	n=8;
	for(int i=1; i<=n; i++){
		int q[n+1];
		q[0]=0;
		q[1]=i;
		nq(q, 2);
	}
} 
	
