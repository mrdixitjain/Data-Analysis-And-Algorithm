#include<stdio.h>
#include<stdlib.h>


int v,e;
struct node{
	int value;
	struct node *next;
	char c;
};

void addedge(int v1, int v2, struct node vt[]){			//addedge function
	struct node *n,*n1;
	n = (struct node *)malloc(sizeof(struct node));
	n->value=v2;
	n->c='w';
	n->next=NULL;
	n1=vt[v1].next;
	if(n1==NULL){
		vt[v1].next=n;
	}
	else{
		while(n1->next!=NULL)
			n1=n1->next;
		n1->next=n;
	}
}

int top=-1, tt=-1;

int pop(int z[]){										//pop function
	int k=z[top];
	top--;
	return(k);
}

void push(int z[], int n){								//push function
	top++;
	z[top]=n;
}

void bfs(struct node vt[], int z[], int t[]){			//bfs function
	while(top!=-1){
		int v1 = pop(z);
		tt++;
		t[tt]=v1;
		struct node *n;
		n=vt[v1].next;
		while(n!=NULL){
			if(vt[n->value].c=='w'){
				vt[n->value].c='g';
				push(z,vt[n->value].value);
				bfs(vt, z, t);
			}
			n=n->next;
		}
		vt[v1].c='b';
		printf("%d ", vt[v1].value);
	}
}
	
	
	

void main(){
	printf("enter number of vertices And number of edges: ");
	scanf("%d%d",&v,&e);
	struct node vt[v], *n;
	n=(struct node *)malloc(sizeof(struct node));
	for(int i=0; i<v; i++){
		vt[i].value=i;
		vt[i].c='w';
		vt[i].next=NULL;
	}
	printf("enter starting and ending vertex of each edge: ");
	int v1,v2;
	for(int i=0;i<e;i++){
		scanf("%d%d",&v1,&v2);
		addedge(v1,v2,vt);
	}
	for(int i=0; i<v; i++){
		n=vt[i].next;
		printf("%d ",vt[i].value);
		while(n!=NULL){
			printf("%d ",n->value);
			n=n->next;
		}
		printf("\n");
	}
	int z[v], t[v];
	printf("enter root vertex: ");
	scanf("%d", &v1);
	vt[v1].c='g';
	push(z, v1);
	printf("\nbfs traversal: ");
	bfs(vt, z, t);
	for(int i=0;i<v;i++){
		if(vt[i].c=='w'){
			vt[i].c='g';
			push(z, vt[i].value);
			bfs(vt, z, t);
		}
	}
	printf("\norder of traversed vertices: ");
	for(int i=0; i<=tt; i++){
		printf("%d ", t[i]);
	}	
}
	
	
