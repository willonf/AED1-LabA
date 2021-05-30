#include <stdio.h>
#include <stdbool.h>
int identidade(int N, int A[][N]);

int main(void)
{
    int N;
    while (true)
    {
        scanf("%d", &N);
        if(!N){
            break;
        }
        int matrix[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        if(identidade(N, matrix)){
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }
}


int identidade(int N, int A[][N]) {
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