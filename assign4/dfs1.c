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
    printf("vertex=%d \n	t.d=%d\n	t.f=%d\n\n",t.value,t.d,t.f);
}

int main(){
    int i,j,k,m,v;
    printf("enter no of vertices");
    scanf("%d",&v);
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
}
