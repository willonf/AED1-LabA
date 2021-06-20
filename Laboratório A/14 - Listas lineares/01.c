#include <stdio.h>
#include <stdlib.h>

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
    for (int i = lista->tamanho; i > pos; i--)
    {
        lista->dados[i] = lista->dados[i - 1];
    }
    lista->dados[pos] = novo;
    lista->tamanho++;

    // lista->tamanho++;
    // printf("\n%d\n\n", lista->tamanho);
    // printf("Tamanho: %d\n", lista->tamanho);
    // lista->dados[lista->tamanho-1] = novo;
    // printf("Oi");
}

void lista_remover(Lista *lista, int pos)
{
    while (pos < lista->tamanho - 1)
    {
        lista->dados[pos] = lista->dados[pos + 1];
        pos++;
    }
    lista->tamanho--;
}



void main(int argc, char const *argv[])
{
    int valor;
    Lista *lista = malloc(sizeof(Lista));
    lista->capacidade = 1;
    lista->tamanho = 1;
    lista->dados = malloc(lista->capacidade * sizeof(int));
    
    while(1) {
        scanf("%d", valor);
        lista_inserir(lista, )
    }

    lista_inserir(lista, lista->capacidade, 3);
}
