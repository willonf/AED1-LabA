#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define AME "Amelisia"
#define BER "Bertinhao"
#define EMP "EMPATE"

typedef struct lista
{
    char *dados;
    int tamanho;
    int capacidade;
} Lista;

void imprimir_lista(Lista *l)
{
    for (int i = 0; i < l->tamanho; i++)
    {
        printf("%c\n", l->dados);
    }
}

Lista *criar_lista(void)
{
    Lista *l = malloc(sizeof(Lista));
    l->tamanho = 0;
    l->capacidade = 10;
    l->dados = malloc(l->capacidade * sizeof(char));
    return l;
}

void liberar_lista(Lista *l)
{
    free(l->dados);
    free(l);
}

void lista_inserir_inicio(Lista *lista, char novo)
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

char lista_desempilha(Lista *lista)
{

    double aux = lista->dados[0];

    for (int i = 0; i < lista->tamanho; i++)
    {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->tamanho--;
    return aux;
}

int main(void)
{
    char elemento[80];
    int num_casos, size;
    Lista *pontosA = criar_lista();
    Lista *pontosB = criar_lista();
    int turnosA = 0, countA = 0;
    int turnosB = 0, countB = 0;

    scanf("%d", &num_casos);

    for (int i = 0; i < num_casos; i++)
    {
        scanf("%s", elemento);
        size = strlen(elemento);
        for (int j = 0; j < size; j++)
        {
            if (elemento[j] == '|')
            {
                lista_inserir_inicio(pontosA, elemento[j]);
                countA++;
            }
            else
            {
                lista_desempilha(pontosA);
                countA--;
            }
        }

        scanf("%s", elemento);
        size = strlen(elemento);
        for (int j = 0; j < size; j++)
        {
            if (elemento[j] == '|')
            {
                lista_inserir_inicio(pontosB, elemento[j]);
                countB++;
            }
            else
            {
                lista_desempilha(pontosB);
                countB--;
            }
        }
        if (countA > countB){
            turnosA++;
        } else if(countB > countA){
            turnosB++;
        }
        countA = 0;
        countB = 0;
        
    }
    liberar_lista(pontosA);
    liberar_lista(pontosB);
    if (turnosA > turnosB)
    {
        printf("%s", AME);
    } else if(turnosB > turnosA){
        printf("%s", BER);
    } else {
        printf("%s", EMP);
    }
    
}
