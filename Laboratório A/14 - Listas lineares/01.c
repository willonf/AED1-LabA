#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
    int *dados;
    int tamanho;
    int capacidade;
} Lista;

void lista_inserir_inicio(Lista *lista, int novo)
{
    int aux;
    int last, pos = 0;
    lista->tamanho++;
    if (lista->tamanho > lista->capacidade)
    {
        lista->capacidade++;
        lista->dados = realloc(lista->dados, (lista->capacidade) * sizeof(int));
    }
    last = lista->tamanho - 1;
    for (int i = last; i >= 0; i--)
    {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[0] = novo;
}

void main(int argc, char const *argv[])
{
    int valor;
    bool existe;
    Lista *lista = malloc(sizeof(Lista));
    lista->capacidade = 10;
    lista->tamanho = 0;
    lista->dados = malloc(lista->capacidade * sizeof(int));
    int pos, last;
    while (true)
    {
        scanf("%d", &valor);
        if (!valor)
        {
            break;
        }
        lista_inserir_inicio(lista, valor);
    }

    last = lista->tamanho - 1;
    while (true)
    {
        scanf("%d", &valor);
        if (!valor)
        {
            exit(1);
        }
        pos = -1;
        for (int i = 0; i < lista->tamanho; i++)
        {
            if (lista->dados[i] == valor)
            {
                pos = i;
                break;
            }
        }

        if(pos == -1){
            printf("%d: nao existe\n", valor);
        } else if(pos == 0){
                printf("%d: inicio\n", valor);
            // }            
        } else if (pos == last){
                printf("%d: fim\n", valor);
        } else {
            printf("%d: existe\n", valor);
        }
    }
}
