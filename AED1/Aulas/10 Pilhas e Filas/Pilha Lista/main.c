#include <stdio.h>
#include "pilha.h"

void main() {
    int N = 2;
    Pilha* vec1[N];

    vec1[0] = cria_pilha();
    vec1[1] = cria_pilha();

    pilha_push(vec1[0], 3.0);
    pilha_push(vec1[0], 0.3);
    pilha_push(vec1[1], 1.0);
    pilha_push(vec1[1], 0.1);

    pilha_imprime(vec1[0]);
    pilha_imprime(vec1[1]);
    pilha_libera(vec1);

}