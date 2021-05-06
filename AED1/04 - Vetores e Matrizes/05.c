#include "stdio.h"
#define N 3

int identidade(double A[][N]);

int main(void) {
    double v[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%lf", &v[i][j]);
        }
    }
    printf("%d",identidade(v));
   
}


int identidade(double A[][N]){
    int ehIdentidade = 1;
    for (int i=0; i < N; i++){
        for (int j=0; j < N; j++){
            if(i == j){
                if(A[i][j] != 1){
                    ehIdentidade = 0;
                    break;
                }
            } else {
                if(A[i][j] != 0){
                    ehIdentidade = 0;
                    break;
                }
            }
        }
    }
    return ehIdentidade;
}