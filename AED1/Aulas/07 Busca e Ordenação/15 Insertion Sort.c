#include <stdio.h>
#include <stdbool.h>

//  Insertion Sort é um algoritmo para inserir dados em um vetor já ordenado (crescente ou decrescente);

void insertionSorT(int v[], int size) {
    for (int i = 1; i < size; i++)
    {
        /* code */
    }
    
}


void insertionSortOredered(int v[], int size, int value) {
    int position = size - 1;

    while(v[position] > value && position >= 0) {
        v[position + 1] = v[position];
        position--;
    }
    v[position + 1] = value;
}

void main() {
    int v[10] = {1, 3, 5, 7, 9};
    insertionSortOrdered(v, 5, 4);
    for (int i = 0; i < 6; i++) {
        printf("%d ", v[i]);
    }
}