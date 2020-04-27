#include<stdio.h>

struct node{
	int value;
	int *next;
};

struct node *createnode(int value){
	struct node *n;
	n->value=value;
	n->next=NULL;
	return(n);
}


void main(){
	printf("enter number of verteces: ");
	int n;
	scanf("%d",&n);
	struct node *head[n],*p;
	for(int i=0;i<n;i++){
		head[i]=NULL;
	}
	grph(0,1);
	grph(1,2);
	grph(0,3);
	grph(1,4);
	grph(
}
			
		
	
