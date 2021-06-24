#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
    int *dados;
    int tamanho;
    int capacidade;
} Lista;

void lista_inserir(Lista *lista, int pos, int novo)
{
    lista->capacidade++;
    lista->dados = realloc(lista->dados, (lista->capacidade) * sizeof(int));
    // for (int i = lista->tamanho; i >= pos; i--)
    // {
    //     lista->dados[i] = lista->dados[i - 1];
    // }
    lista->dados[pos] = novo;
    lista->tamanho++;
}

void main(int argc, char const *argv[])
{
    int valor;
    int existe;
    Lista *lista = malloc(sizeof(Lista));
    lista->capacidade = 10;
    lista->tamanho = 0;
    lista->dados = malloc(lista->capacidade * sizeof(int));
    int pos = 0;
    while (true)
    {
        scanf("%d", &valor);
        if (!valor)
        {
            break;
        }
        lista_inserir(lista, pos, valor);
        pos++;
    }
    while (true)
    {
        pos = 0;
        existe = -1;
        scanf("%d", &valor);
        if (!valor)
        {
            exit(1);
        }
        while (pos <= lista->tamanho - 1)
        {
            if (valor == lista->dados[pos])
            {
                existe = pos;
                break;
            }
            pos++;
        }
        if (existe == 0)
        {
            printf("%d: fim", valor);
        }
        else if (existe == lista->tamanho - 1)
        {
            printf("%d: inicio", valor);
        }
        else if (existe > 0 && existe < lista->tamanho - 1)
        {
            printf("%d: existe", valor);
        }
        else if (existe < 0)
        {
            printf("%d: nao existe", valor);
        }
        printf("\n");
    }
}
