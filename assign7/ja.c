#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define max 10
int n, min=INT_MAX;
int ans[max];
int q[max][max];
int p[max];
int count=0;
			

bool j_in_p(int j, int i){
	int k;
	for(k=0; k<i; k++)
		if(p[k]==j)
			break;
	if(k==i)
		return false;
	return true;
}
void assign(int i, int z){
	count++;
	z = z + q[i-1][p[i-1]];
	//printf("%d %d\n", i, n);
	if(i>=n){
		if(z<min){
			min=z;
			for(i=0; i<n; i++)
				ans[i]=p[i];
		}
	}
	else{
		for(int j=0; j<n; j++){
			if(!j_in_p(j, i)){
				p[i]=j;
				assign(i+1, z);
			}
		}
	}
}
			

int main(){
	scanf("%d", &n);
	int z=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &q[i][j]);
	for(int i=0; i<n; i++){
		p[0]=i;
		assign(1, z);
	}
	for(int i=0; i<n; i++)
		printf("%d->%d\n", i, ans[i]);
	printf("\ncost = %d\n", min);
}
