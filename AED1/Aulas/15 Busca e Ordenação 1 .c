#include "stdio.h"


int binarySearch(int *v, int length, int x) {
    int inf = 0;
    int sup = length - 1;
    int meio;

    while(inf <= sup){
        meio = (inf + sup) / 2;
        if(x == v[meio]) {
            return meio;
        } else if(x > v[meio]) {
            inf = meio + 1;
        } else {
            sup = meio - 1;
        }
    }
    return -1;
}

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
