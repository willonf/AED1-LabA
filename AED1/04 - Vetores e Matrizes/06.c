#include "stdio.h"
#define N 3

int triangular_inferior(double A[][N]);

int main(void) {
    double v[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%lf", &v[i][j]);
        }
    }
    printf("%d",triangular_inferior(v));
   
}


int triangular_inferior(double A[][N]){
    int ehTriangularInferior = 1;
    for (int i=0; i < N; i++){
        for (int j=0; j < N; j++){
            if(i < j){
                if(A[i][j] != 0){
                    ehTriangularInferior = 0;
                    break;
                }
            }
        }
    }
    return ehTriangularInferior;
}