#include<stdio.h>

int knapsack(int w[], int v[], int n){
	int wc,q,j;
	//printf("enter capacity: ");
	scanf("%d", &wc);
	int m[wc+1], max=0;
	m[0]=0;
	for(int i=1; i<wc; i++){
		printf("hey ");
		m[i]=0;
		printf("1\n");
		/*for(j=0; j<wc; j++){
			printf("hello");
			q=v[j]+m[wc-w[j]];
			if(q>m[i])
				m[i]=q;
		}*/
		printf("%d\n", wc);
		for(j=1; j<wc; j++){
			printf("hello");
			if(j<wc){
				q=v[j]+m[i-1];
				if(q>m[i])
					m[i]=q;
			}
			else
				m[i]=m[i-1];
		}
	}
	return m[wc];
	
}
	
void main(){
	int n;
	//printf("enter number of bags: ");
	scanf("%d", &n);
	int w[n], v[n];
	//printf("enter weights: ");
	for(int i=0; i<n; i++)
		scanf("%d", &w[i]);
	//printf("enter values: ");
	for(int i=0; i<n; i++)
		scanf("%d", &v[i]);
	printf("%d", knapsack(w, v, n));
}
