#include <stdlib.h>
#include <stdio.h>
// #include "pilha.h"

typedef struct pilha Pilha;
typedef struct pilhaNo PilhaNo;
Pilha *pilha_cria();
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
float pilha_imprime(Pilha *p);

typedef struct pilha
{
    PilhaNo *topo;
} Pilha;

typedef struct pilhaNo {
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
    if(pilha_vazia(p)){
        printf("*");
        exit(1);
    }
    for (PilhaNo *aux = p->topo; aux != NULL; aux= aux->prox)
    {
        printf("%.2f\n", aux->numero);
    }
}

int main()
{
    int N;
    int opcao;
    float v;
    Pilha *pilha = pilha_cria();

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            pilha_pop(pilha);
            break;
        case 1:
            scanf("%f", &v);
            pilha_push(pilha, v);
        default:
            break;
        }
    }
    pilha_imprime(pilha);
    pilha_libera(pilha);
}