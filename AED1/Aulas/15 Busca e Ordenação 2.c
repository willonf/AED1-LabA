#include "stdio.h"

// O(n) = n²
// Pior caso: ordenar de forma crescente um vetor que está em ordem decrescente
void bubbleSort(int *v, int length)
{
    int i, j;
    for (i = 0; i < length - 1; i++)
    {
        // A variável "troca" irá mudar caso haja troca.
        // Caso não haja troca, o vetor já está ordenado e não é necessário mais seguir com o algoritmo
        int troca = 0;
        for (j = 0; j < length - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                troca = 1;
            }
        }
        if (troca == 0){
            return;
        }
    }
}

void main() {
}
