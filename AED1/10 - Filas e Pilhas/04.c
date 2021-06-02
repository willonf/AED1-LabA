#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct filaNo FilaNo;
struct filaNo
{
    float numero;
    FilaNo *prox;
};

typedef struct fila
{
    FilaNo *inicio;
    FilaNo *fim;

} Fila;

Fila *fila_cria(void)
{
    Fila *novaFila = (Fila *)malloc(sizeof(Fila));
    novaFila->inicio = NULL;
    novaFila->fim = NULL;
    return novaFila;
}

void fila_insere(Fila *f, float v)
{
    FilaNo *novoNo = malloc(sizeof(FilaNo));
    novoNo->numero = v;
    novoNo->prox = NULL;
    if (f->fim != NULL)
    {
        f->fim->prox = novoNo;
    }
    else
    {
        f->inicio = novoNo;
    }
    f->fim = novoNo;
}

float fila_retira(Fila *f)
{
    FilaNo *aux = f->inicio;
    float v = aux->numero;
    f->inicio = aux->prox;
    if (f->inicio = NULL)
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

    for (aux = f->inicio; aux != NULL; aux = aux->prox)
    {
        printf("%.1f\n", aux->numero);
    }
}

void combina_filas(Fila *f1, Fila *f2, Fila *f_res)
{
    FilaNo *aux1 = f1->inicio;
    FilaNo *aux2 = f2->inicio;
    fila_insere(f_res, aux1->numero);
    fila_insere(f_res, aux2->numero);
    aux1 = aux1->prox;
    aux2 = aux2->prox;

    while (true)
    {
        if (aux1 != NULL)
        {
            fila_insere(f_res, aux1->numero);
            aux1 = aux1->prox;
        }
        if (aux2 != NULL)
        {
            fila_insere(f_res, aux2->numero);
            aux2 = aux2->prox;
        }
        if (aux1 == NULL && aux2 == NULL)
        {
            break; 
        }
        
    }
}

int main()
{
    Fila *fila1 = fila_cria();
    Fila *fila2 = fila_cria();
    Fila *f_res = fila_cria();
    float v;
    float v2;

    while (scanf("%f", &v) != 0)
    {
        fila_insere(fila1, v);
    }
    getchar();
    while (scanf("%f", &v2))
    {
        fila_insere(fila2, v2);
    }
    combina_filas(fila1, fila2, f_res);
    fila_imprime(f_res);
    fila_libera(fila1);
    fila_libera(fila2);
    fila_libera(f_res);
}