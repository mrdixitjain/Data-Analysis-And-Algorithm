#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int V, e, w, u, v;
int extract_min(int q[]){
	int min=0;
	for(int i=0; i<V; i++)
		if(q[i]<q[min])
			min=i;
	return min;
}

int main(){
	scanf("%d%d", &V,&e);
	int es[e];
	int ed[e];
	int ew[e];
	int adj[V][V];
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			adj[i][j]=-1;
	for(int i=0; i<e; i++){
		scanf("%d%d%d",&u,&v,&w);
		es[i]=u;
		ed[i]=v;
		ew[i]=w;
		adj[u][v]=i;
	}
	int esd[V], q[V];
	for(int i=0; i<V; i++){
		q[i]=INT_MAX;
		esd[i]=INT_MAX;
	}
	int s;
	scanf("%d", &s);
	esd[s]=0;
	q[s]=0;
	int count=0;
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
	while(count<V){
		for(int i=0; i<V; i++)
			printf("%d ",q[i]);
		u=extract_min(q);
		printf("\nu=%d\n", u);
		count++;
		for(int i=0; i<V; i++){
			if(adj[u][i]>=0){
				if(esd[u]+ew[adj[u][i]]<esd[i]){
					esd[i]=esd[u]+ew[adj[u][i]];
					q[i]=esd[i];
				}
			}
		}
		q[u]=INT_MAX;
	}
	for(int i=0; i<V; i++){
		printf("%d -> %d = %d\n", s, i, esd[i]);
	}
}				
	
