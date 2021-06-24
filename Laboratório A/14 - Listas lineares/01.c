#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
    int *dados;
    int tamanho;
    int capacidade;
} Lista;

void lista_inserir_final(Lista *lista, int novo)
{
    int last, pos = 0;
    lista->tamanho++;
    if (lista->tamanho > lista->capacidade)
    {
        lista->capacidade++;
        lista->dados = realloc(lista->dados, (lista->capacidade) * sizeof(int));
    }
    last = lista->tamanho - 1;
    lista->dados[last] = novo;
}

void main(int argc, char const *argv[])
{
    int valor;
    bool existe;
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
        lista_inserir_final(lista, valor);
    }
    if (!lista->tamanho)
    {
        exit(1);
    }

    while (true)
    {
        existe = false;
        scanf("%d", &valor);
        if (!valor)
        {
            exit(1);
        }
        for (int i = 0; i < lista->tamanho; i++)
        {
            // printf("Valor atual: %d - Valor lido = %d\n", lista->dados[i], valor);
            if (lista->dados[i] == valor)
            {
                existe = true;
                if (i == 0 || lista->dados[lista->tamanho - 1] == valor)
                {
                    printf("%d: inicio\n", valor);
                    break;
                }
                else if (i == lista->tamanho - 1)
                {
                    printf("%d: fim\n", valor);
                    break;
                }
                else
                {
                    printf("%d: existe\n", valor);
                    break;
                }
            }
        }
        if (!existe)
        {
            printf("%d: nao existe\n", valor);
        }
    }
}
