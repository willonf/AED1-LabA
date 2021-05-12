#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

int compararValores (const void *a, const void *b) {
   return (*(int *)a - *(int *)b);
}

void main() {
    int K, M, N, lenC;
    int cont = 0;
    int posicao;

    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        scanf("%d", &N);
        int A[N];

        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }

        scanf("%d", &M);
        int B[M];

        for (int j = 0; j < M; j++) {
            scanf("%d", &B[j]);
        }

        lenC = M + N;
        int C[lenC];

        for (int j = 0; j < lenC; j += 2) {
            C[j] = A[cont];
            C[j+1] = B[cont];
            cont++;
        }
      
        qsort(C, lenC, sizeof(int), compararValores);
        
        for (int j = 0; j < lenC; j++) {
            printf("%d ", C[j]);
        }
        printf("\n");
        cont = 0;
    }
}