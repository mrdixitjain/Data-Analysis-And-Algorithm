#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int main(){
	int V, e, w;
	scanf("%d%d", &V,&e);
	int es[e];
	int ed[e];
	int ew[e];
	for(int i=0; i<e; i++)
		scanf("%d%d%d", &es[i], &ed[i], &ew[i]);
	int esd[V];
	for(int i=0; i<V; i++)
		esd[i]=INT_MAX;
	int s;
	scanf("%d", &s);
	esd[s]=0;
	for(int j=0; j<V-1; j++){
		for(int i=0; i<e; i++){
			int u=es[i];
			int v=ed[i];
			w=ew[i];
			if(esd[u]+w<esd[v])
				esd[v]=esd[u]+w;
		}	
	}
	for(int i=0; i<e; i++){
		int u=es[i];
		int v=ed[i];
		w=ew[i];
		if(esd[u]+w<esd[v]){
			printf("NEGATIVE WEIGHT CYCLE EXIST\n");
			exit(0);
		}
	}
	for(int i=0; i<V; i++){
		printf("%d -> %d = %d\n", s, i, esd[i]);
	}
}
		
