#include <stdio.h>  
#define INF 2147483647  
   
int n = 5; // size of the adjaceny matrix  
   
// O(n^2)  
void fillDistanceMatrix(int A[n][n], int D[n][n]) {  
   for (int i = 0; i < n; i++) {  
       for (int j = 0; j < n; j++) {  
           if (i == j)  
               D[i][j] = 0;  
           else if (A[i][j] == 0)  
               D[i][j] = INF;  
           else  
               D[i][j] = A[i][j];  
       }  
   }  
}  
   
// O(n^3)  
void floydWarshall(int A[n][n], int D[n][n]) {  
   fillDistanceMatrix(A, D);  
   
   for (int k = 0; k < n; k++)
   {  
       for (int i = 0; i < n; i++) 
       {  
           for (int j = 0; j < n; j++)
           {  
               //if (D[i][k] < INF && D[k][j] < INF) 
               if(D[i][j] > (D[i][k] + D[k][j]) && (D[k][j] != INF
                        && D[i][k] != INF))
               {
                   if (D[i][k] + D[k][j] < D[i][j]) 
                   {
                       D[i][j] = D[i][k] + D[k][j];
                    }
               }  
           }  
       }  
   }  
}  
int main() {  
    int A[5][5] = {{0, 5, 0,6,0},  
                   {0, 0, 1,0,7},  
                   {3, 0, 0,4, 0},  
                   {0, 0, 2, 0,3},
                   {2, 0, 0,5, 0}};  
    int D[5][5];  
   
    floydWarshall(A, D);  
   
    printf("Shortest distances between all pairs of vertices:\n");  
    for (int i = 0; i < 5; i++) {  
        for (int j = 0; j < 5; j++) {  
            if (D[i][j] == INF)  
                printf("%7s", "INF");  
            else  
                printf("%7d", D[i][j]);  
        }  
        printf("\n");  
    }  
   
    return 0;  
}  