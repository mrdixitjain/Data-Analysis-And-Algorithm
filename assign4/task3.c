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
