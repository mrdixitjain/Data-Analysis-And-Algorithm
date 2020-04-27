#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
    struct node *next;
    char colour;
    int f;
    int d;
};
struct node g[50];

void addedge(int s, int d){
	struct node *t,*l;
	t=l=(struct node *)malloc(sizeof(struct node));
    t->value=d;
    t->next=NULL;
    l=g[s].next;
    if(l==NULL)
    	g[s].next=t;
    else{
    	while(l->next!=NULL)
    		l=l->next;
    	l->next=t;
    }
}
struct node a[50];
int s[1000];
int top=-1;
int pop(){
	int t;
    t=s[top];
    top--;
    return(t);
}
void push(int t){
    top++;
    s[top]=t;
}
int empty(){
    if(top==-1)
 	   return 1;
    else
       return 0;
}
int time=0;
void dfs(struct node t){
    time++;
    struct node *y;
    t.d=time;
    y=t.next;
    while(y!=NULL){
    	if(g[y->value].colour=='w'){
    		g[y->value].colour='g';
        	dfs(g[y->value]);
    	}
    	else if(g[y->value].colour=='g' || g[y->value].colour=='b')
    		printf("cycle is present\n");
    	y=y->next;
    }
    t.colour='b';
    time++;
    t.f=time;
    push(t.value);
}
void dfs_r(struct node t){
    struct node *y;
    y=t.next;
    while(y!=NULL){
    	if(a[y->value].colour=='w'){
    		a[y->value].colour='g';
        	dfs_r(a[y->value]);
    	}
    	y=y->next;
    }
    t.colour='b';
    printf("%d ", t.value);
}

void strongly(){
	int i,j,k;
    struct node x,y;
    struct node *u,*v;
    while(!empty()){
	    k=pop();
        if(g[k].colour=='w'){
	        printf("\n");
            g[k].colour='g';
            dfs_r(a[k]);
        }
    }
}
void transpose(int v){
	int i,j,k,n;
    struct node *x,*y,*z;
    struct node t,s;
    for(i=0;i<v;i++){
    	a[i].value=i;
    	a[i].next=NULL;
        a[i].colour='w';
    }
    for(i=0;i<v;i++){
    	z=g[i].next;
        while(z!=NULL){
    	    j=z->value;
            t=a[j];
            x=(struct node *)malloc(sizeof(struct node));
            x->value=i;
            x->next=NULL;
            y=t.next;
            if(y==NULL){
    	        a[j].next=x;
            }
            else{
      	      while(y->next!=NULL)
      	        y=y->next;
              y->next=x;
            }
            z=z->next;
        }
    }
}


int main(){
    int i,j,k,m,v,e;
    printf("enter no of vertices and edges");
    scanf("%d%d",&v,&e);
    struct node *t;

    for(i=0;i<v;i++){
        g[i].value=i;
        g[i].colour='w';
    	g[i].next=NULL;
    }
    addedge(0, 1);
	addedge(0, 3);
	addedge(1, 2);
	addedge(3, 1);
	addedge(2, 4);
	addedge(4, 3);
	for(i=0;i<v;i++){
	    if(g[i].colour=='w'){
		    g[i].colour='g';
            dfs(g[i]);
        }
    }
    transpose(v);
    strongly();
}
