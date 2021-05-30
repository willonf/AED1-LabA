#include "stdio.h"

float troca(int *a, int *b) {
    int aux, e = 4;
    aux = *a;
    *a = *b;
    *b = aux;
}

void teste(int *a){
    a += *a + 1;
}

int main(void){
    int a = 5, b = 7;
    // troca(&a,&b);
    // printf("a = %d <---> b = %d\n", a, b);
    teste(&a);
    printf("%d", a);
}

