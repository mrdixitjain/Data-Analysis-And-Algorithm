#include<stdio.h>
#include<stdlib.h>

int n,i=0,j=-1;


struct node{
	int value;
	char colour;
	struct node *next;
};

struct node *createnode(int v){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->value=v;
	t->colour='w';
	t->next=NULL;
	return(t);
}

void dfs(struct node g[], int sv){
	j++;
	int v[n];
	g[sv].colour='g';
	printf("%d ",g[sv].value);
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t=g[sv].next;
	printf("%d\n",t->value);
	while(t!=NULL){
		if(g[t->value].colour=='w'){
			v[i]=t->value;
			i++;
		}
		t=t->next;
	}
	g[sv].colour='b';
	dfs(g, v[j]);
}
	
			
	
void addedge(struct node g[], int s, int d){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t=g[s].next;
	while(t!=NULL)
		t=t->next;
	t=createnode(d);
	printf("%d\n",g[s].next->value);
}
		
	
void main(){
	printf("enter number of vertices: ");
	scanf("%d", &n);
	struct node g[n];
	for(int i=0; i<n; i++){
		g[i].value=i;
		g[i].colour='w';
		g[i].next=NULL;
	}
	addedge(g, 0, 1);
	addedge(g, 0, 3);
	addedge(g, 1, 2);
	addedge(g, 3, 1);
	addedge(g, 2, 4);
	addedge(g, 4, 3);
	addedge(g, 3, 5);
	dfs(g,1);
}
