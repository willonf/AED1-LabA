#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilhaNo
{
    float info;
    PilhaNo *prox;
};

struct pilha
{
    PilhaNo *prim
};

PilhaNo *cria_pilha(void)
{
    Pilha *p = malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
};

void pilha_push(Pilha *p, float v)
{
    PilhaNo *n = malloc(sizeof(PilhaNo));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

float pilha_pop(Pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("A pilha já está vazia!");
        exit(1);
    }
    // O topo é armazenado em um nó auxiliar
    PilhaNo *aux = p->prim;
    // O valor "info" é armazenado em um "v" temporário
    float v = aux->info;
    // O topo da pilha agora apontará para o próximo item da pilha
    p->prim = aux->prox;
    // O antigo topo é liberado e seu valor é retornado
    free(aux);
    return v;
}

int pilha_vazia(Pilha *p)
{
    return (p->prim == NULL);
}

float pilha_libera(Pilha *p)
{
    PilhaNo *aux = p->prim;
    while (aux != NULL)
    {
        PilhaNo *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(p);
}

float pilha_imprime(Pilha *p)
{
    for (PilhaNo *aux = p->prim; aux != NULL; aux = aux->prox)
    {
        printf("%.2f\n", aux->info);
    }
}