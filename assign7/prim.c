complete nhi h yeh

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10
int V, e, w, u, v;
int extract_min(int q[]){
	int min=0;
	for(int i=0; i<V; i++)
		if(q[i]<q[min])
			min=i;
	return min;
}

primMST(int adj[max][max], int key[], bool visited[]){
	for(int i=0; i<V; i++){
		u=find_min(key, visited[]);
		

int main(){
	scanf("%d%d", &V);
	int adj[max][max];
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			scanf("%d", &adj[i][j]);
	
	int key[V];
	bool visited[V]
	for(int i=0; i<V; i++){
		visited[i]=false;
		key[i]=INT_MAX;
	}
	key[0]=0;
	primMST(adj, key, visited);
}
