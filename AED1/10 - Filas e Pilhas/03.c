#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include "pilha.h"

typedef struct pilha Pilha;
typedef struct pilhaNo PilhaNo;
Pilha *pilha_cria();
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
float pilha_imprime(Pilha *p);
void concatena_pilhas(Pilha *p1, Pilha *p2);

typedef struct pilha
{
    PilhaNo *topo;
} Pilha;

typedef struct pilhaNo
{
    float numero;
    PilhaNo *prox;
} PilhaNo;

Pilha *pilha_cria()
{
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));
    novaPilha->topo = NULL;
    return novaPilha;
}

void pilha_push(Pilha *p, float v)
{
    PilhaNo *novoNo = malloc(sizeof(PilhaNo));
    novoNo->numero = v;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}

int pilha_vazia(Pilha *p)
{
    return (p->topo == NULL);
}

float pilha_pop(Pilha *p)
{
    PilhaNo *aux = p->topo;
    float v = aux->numero;
    p->topo = p->topo->prox;
    free(aux);
    return v;
}

void pilha_libera(Pilha *p)
{
    PilhaNo *aux = p->topo;
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
    if (pilha_vazia(p))
    {
        printf("*");
        exit(1);
    }
    for (PilhaNo *aux = p->topo; aux != NULL; aux = aux->prox)
    {
        printf("%.1f\n", aux->numero);
    }
}

PilhaNo *pegarNoBase(Pilha *p)
{
    PilhaNo *NoBase = p->topo;
    while (NoBase->prox != NULL)
    {
        NoBase = NoBase->prox;
    }
    return NoBase;
}

void concatena_pilhas(Pilha *p1, Pilha *p2)
{
    PilhaNo *baseP2 = pegarNoBase(p2);
    baseP2->prox = p1->topo;
    p1->topo = p2->topo;
    p2->topo = NULL;
}

int main()
{
    int N;
    ;
    float v;
    Pilha *pilha1 = pilha_cria();
    Pilha *pilha2 = pilha_cria();

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%f", &v);
        pilha_push(pilha1, v);
    }

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%f", &v);
        pilha_push(pilha2, v);
    }
    concatena_pilhas(pilha1, pilha2);
    pilha_imprime(pilha1);
    pilha_libera(pilha1);
}