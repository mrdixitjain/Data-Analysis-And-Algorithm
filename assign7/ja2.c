#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define max 10
int n, min=INT_MAX;
int ans[max];
int q[max][max];
int p[max];
int count=0, at, tp;
int t[max], d=0, ans1[max][max];
int prev[max];
int preans=INT_MAX;
			
int min_arr(int p){
	//printf("ans1=>\n");
	//for(int i=0; i<=p; i++){
		//for(int j=0; j<n; j++)
			//printf("%d ", ans1[i][j]);
		//printf("\n");
	//}
	int m=0;
	for(int i=0; i<n; i++)
		if(ans1[p][i]<ans1[p][m])
			m=i;
	return m;
}

bool j_in_p(int j, int i, int y[]){
	int k;
	//printf("y=>");
	//for(k=0; k<=i; k++){
		//printf("%d ", y[k]);
	//}
	//printf("\n");
	for(k=0; k<=i; k++){
		if(y[k]==j)
			break;
	}
	//printf("k=%d, i=%d\n", k, i);
	if(k==i+1 || y[k]!=j){
		//printf("%d is not in p\n", j);
		return false;
	}
	//printf("%d is in p\n", j);
	return true;
}
	
int find_min(int i){
	int z[n];
	//printf("tp in find_min=%d\n", tp);
	//printf("t=>");
	//for(int v=0; v<=tp; v++)
		//printf("%d ", t[v]);
	
	//printf("\n");
	for(int j=0; j<n; j++){
		if(j_in_p(j, tp, t))
			z[j]=INT_MAX;
		else
			z[j]=q[i][j];
	}
	//for(int v=0; v<n; v++)
		//printf("%d ", z[v]);
	//printf("\n");
	int x=0;
	for(i=0; i<n; i++)
		if(z[i]<z[x])
			x=i;
	//printf("x=%d\n", x);
	return(x);
}
	
void partial_assign(int i, int l, int j){
	l=l+q[i-1][j];
	//printf("\nl = %d\n ", l);
	if(i>=n){
		//printf("tp=%d,i=%d,d=%d, l=%d\n",tp,i,d, l);
		//printf("p in pa=>");
		//for(int di=0;di<n;di++)
		//	printf("%d ", p[di]);
		while(j_in_p(d, i-1, p))
			d++;
		ans1[tp][d]=l;
		d++;
	}
	else{
		int j=find_min(i);
		partial_assign(i+1, l, j);
	}
}
	
	
void assign(int i, int z){
	//printf("\n\n\n");
	count++;
	z = z + q[i-1][p[i-1]];
	if(i>=n){
		//for(int i=0; i<n; i++)
			//printf("%d->%d\n", i, p[i]);
		//printf("\ncost = %d\n", z);
		int h=min_arr(0);
		//printf("z=%d,h=%d, c=%d\n",z, h, ans1[0][h]);
		if(z<=ans1[0][h]){
			if(z<preans){
				min=z;
				for(i=0; i<n; i++)
					ans[i]=p[i];
			}
			else{
				min=preans;
				for(i=0; i<n; i++)
					ans[i]=prev[i];
			}
		}
		else{
			if(z<preans){
				for(i=0; i<n; i++)
					prev[i]=p[i];
				preans=z;
			}
			for(int i=0; i<n; i++){
				t[i]=-1;
				p[i]=-1;
			}
			for(int i=1; i<n; i++){
				for(int j=0; j<n; j++){
					ans1[i][j]=INT_MAX;
				}
			}
			t[0]=h;
			tp=1;
			ans1[0][h]=INT_MAX;
			at=h;
			p[0]=h;
			z=0;
			assign(1, z);
		}
	}
	else{
		d=0;
		for(int j=0; j<n; j++){
			if(!j_in_p(j, i, p)){
				t[i]=j;
				partial_assign(i+1, z, j);
			}
		}
		
		int j = min_arr(i);
	//	printf("jmin=%d", j);
		p[i]=j;
		t[i]=j;
		tp++;
		assign(i+1, z);
	}
}
			

int main(){
	scanf("%d", &n);
	int z=0, l=0;
	for(int i=0; i<n; i++){
		t[i]=-1;
		p[i]=-1;
		for(int j=0; j<n; j++){
			ans1[i][j]=INT_MAX;
			scanf("%d", &q[i][j]);
		}
	}
	for(int i=0; i<n; i++){
		t[0]=i;
		l=0;
		tp=0;
		partial_assign(1, l, i);
		//printf("\n");
	}
	printf("ans1=>");
	for(int i=0; i<n; i++)
		printf("%d ", ans1[0][i]);
	int i = min_arr(0);
	at=i;
	ans1[0][i]=INT_MAX;
	//printf("imin=%d\n", i);
	p[0]=i;
	for(int q=0; q<n; q++)
		t[q]=-1;
	t[0]=i;
	tp++;
	assign(1, z);
	for(int i=0; i<n; i++)
		printf("%d->%d\n", i, ans[i]);
	printf("\ncost = %d\n", min);
	
	
}
