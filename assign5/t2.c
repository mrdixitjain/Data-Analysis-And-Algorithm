#include<stdio.h>
#include<stdlib.h>


int v,e;
struct node{
	int value;
	struct node *next;
	char c;
	int d;
	int f;
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

int top=-1, time=-1, tt=-1;

void set(struct node vt[]){								//set function
	for(int i=0; i<v; i++){
		vt[i].c='w';
	}
	time=-1;
}

int pop(int z[]){										//pop function
	int k=z[top];
	top--;
	return(k);
}

void push(int z[], int n){								//push function
	top++;
	z[top]=n;
}

void dfs(struct node vt[], int z[]){					//dfs
	int v1 = pop(z);
	time++;
	vt[v1].d=time;
	struct node *n;
	n=vt[v1].next;
	while(n!=NULL){
		if(vt[n->value].c=='w'){
			vt[n->value].c='g';
			push(z, vt[n->value].value);
			dfs(vt, z);
		}
		else if(vt[n->value].c=='g'){
			printf("not possible as cycle present in graph.");
			exit(0);
		}
		n=n->next;
	}
	time++;
	vt[v1].f=time;
	vt[v1].c='b';
	printf("%d ", vt[v1].value);
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
	printf("enter starting vertex: ");
	int i;	
	scanf("%d",&i);
	//for(int i=0;i<v; i++){
	//	printf("\nstarting vertex = %d",i);
		//set(vt);
		vt[i].c='g';
		push(z, i);
		printf("\ntopological sort: ");
		dfs(vt, z);
		for(int i=0;i<v;i++){
			if(vt[i].c=='w'){
				vt[i].c='g';
				push(z, vt[i].value);
				dfs(vt, z);
			}
		}
		for(i=0;i<v;i++)
			printf("\nvertex = %d\n		discovering time = %d\n		finishing time = %d\n", i, vt[i].d, vt[i].f);
	//}
}
