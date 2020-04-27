#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
          int n,i,m;
          int *ptr;
          int z=1;
          // enter 1 for insertion
          while(z==1 || z==2 || z==3){
          printf("enter number of values\n");
          scanf("%d",&n);
          for(i=1;i<n;i++){
                    if(pow(2,i) < n && n <= pow(2,i+1)){
                           m=pow(2,i+1);
                           printf("%d",m);
                           break;
                    }
        
          }
          ptr=(int *)calloc(m,sizeof(int));
          int a[m];
           printf("enter values");
           for(i=0;i<m;i++){
                    a[i]=0;
           }
          for(i=0;i<n;i++){
                   scanf("%d",&a[i]);
          }
          for(i=0;i<m;i++){
                    printf("%d\n",a[i]);
          }
            printf("enter 1 for insertion ,2 for delete 3 for size");
          scanf("%d",&z);
          
          int x;
          if (z==2){
          printf("enter the element you want to delete ");
          scanf("%d",&x);
          for(i=0;i<n;i++){
                    if(x==a[i])
                              a[i]=0;
          }
          for(i=1;i<n;i++){
                    if(pow(2,i)<n-1 && n-1<=pow(2,i+1)){
                              m=pow(2,i+1);
                    }
          }
          int b[m];
          int j=0;
          ptr=(int*)calloc(m,sizeof(int));
           for(i=0;i<m;i++){
                    b[i]=0;
           }
          for(i=0;i<n-1;i++){
                 if(a[j]==0)
                              j++;
                 b[i]=a[j];
                 j++;
          }
          for(i=0;i<m;i++){
                    printf("%d\n",b[i]);
          }}
          if(z==3){
          printf("the size is %d",m);
          }}}



