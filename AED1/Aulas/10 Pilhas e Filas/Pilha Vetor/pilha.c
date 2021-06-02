#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilha
{
    int n;        // Qtde de elementos armazenados
    int dim;      // Tamanho da pilha
    float *vetor; // Vetor dos elementos
};

Pilha *cria_pilha(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->dim = 2; // Tamanho inicial da pilha

    p->vetor = malloc(p->dim * sizeof(float));
    p->n = 0;
    return p;
}

void pilha_push(Pilha *p, float v)
{
    if (p->n == p->dim)
    {                        // Capacidade esgotada
        p->dim = 2 * p->dim; // nova capacidade
        p->vetor = realloc(p->vetor, p->dim * sizeof(float));
    }
    p->vetor[p->n] = v;
    p->n = p->n + 1;
}

float pilha_pop(Pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("A pilha está vazia");
        exit(2);
    }
    p->n = p->n - 1;
    float v = p->vetor[p->n];
    return v;
}

float pilha_vazia(Pilha *p)
{
    return (p->n == 0);
}

float pilha_libera(Pilha *p)
{
    free(p->vetor);
    free(p);
}

float pilha_imprime(Pilha *p)
{
    for(int i = p->n - 1; i >= 0; i--){
        printf("%.2f\n", p->vetor[i]);
    }
}