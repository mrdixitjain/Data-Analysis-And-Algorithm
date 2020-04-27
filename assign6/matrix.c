#include<stdio.h> 
#include<limits.h> 
int matrix(int p[], int n) 
{ 
    int min[n][n]; 
    for (int i=1; i<n; i++) 
        min[i][i] = 0;  
    for (int l=2; l<n; l++) 
    { 
        for (int i=1; i<n-l+1; i++) 
        { 
            int j = i+l-1; 
            min[i][j] = INT_MAX; 
            for (int k=i; k<=j-1; k++) 
            {
                int q = min[i][k] + min[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < min[i][j]) 
                    min[i][j] = q; 
            } 
        } 
    } 
    return min[1][n-1]; 
} 
  
int main() 
{ 
    printf("enter number of matrix: ");
    int n;
    scanf("%d", &n);
    int dim[n+1];
    for(int i=0; i<n+1; i++)
    	scanf("%d", &dim[i]);  
    printf("min =%d", matrix(dim, n+1));
    return 0; 
} 

