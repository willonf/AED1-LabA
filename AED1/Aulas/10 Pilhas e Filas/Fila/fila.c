#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct filaNo
{
    float info;
    FilaNo *prox;
};

struct fila
{
    FilaNo *inicio;
    FilaNo *fim;
};

Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void fila_insere(Fila *f, float v)
{
    FilaNo *new = malloc(sizeof(FilaNo));
    new->info = v;
    new->prox = NULL;
    if (f->fim != NULL)
    {                       // A fila não está vazia
        f->fim->prox = new; // O último nó aponta para o novo nó
    }
    else
    {                    // A fila está vazia
        f->inicio = new; // O início da fila aponta para o novo nó
    }
    f->fim = new; // O fima da fila aponta para o novo nó
}

float fila_retira(Fila *f)
{
    FilaNo *aux = f->inicio;
    float v = aux->info;
    f->inicio = aux->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    free(aux);
    return v;
}

int fila_vazia(Fila *f)
{
    return (f->inicio == NULL);
}

void fila_libera(Fila *f)
{
    FilaNo *aux = f->inicio;
    while (aux != NULL)
    {
        FilaNo *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(f);
}

void fila_imprime(Fila *f)
{
    FilaNo *aux;

    for(aux = f->inicio; aux != NULL; aux = aux->prox) {
        printf("%.2f\n", aux->info);
    }
}