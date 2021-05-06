#include "stdio.h"
#include "stdlib.h"

int *soma_vetores(int *x1, int *x2, int n);

int main(void)
{
    int *vetor1, *vetor2;
    int *vetor_soma;
    int n;

    scanf("%d", &n);
    vetor1 = malloc(n * sizeof(int));
    vetor2 = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor1[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor2[i]);
    }
    vetor_soma = soma_vetores(vetor1, vetor2, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor_soma[i]);
    }
    free(vetor1);
    free(vetor2);
    free(vetor_soma);
}

int* soma_vetores(int *x1, int *x2, int n) {
    int pos = n;
    int* x3 = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        x3[i] = x1[i] + x2[i];
    }
    return x3;
}
