#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct aluno Aluno;
typedef struct lista Lista;

struct aluno
{
    char nome[30];
    int idade;
};

struct no
{
    No *ant;
    Aluno info;
    No *prox;
};

struct lista
{
    No *prim;
    No *ult;
};



Lista *criarLista()
{
    Lista *lista = malloc(sizeof(Lista));

    // (*lista).prim = NULL;
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void inserirInicio(Lista *lista, Aluno aluno)
{
    No *noNovo = (No *)malloc(sizeof(No));
    noNovo->ant = NULL;
    noNovo->info = aluno;
    noNovo->prox = lista->prim;
    lista->prim = noNovo;
    if (lista->ult == NULL)
    {
        lista->ult = noNovo;
    }
}

void inserirFinal(Lista *lista, Aluno aluno)
{
    No *noNovo = (No *)malloc(sizeof(No));
    
    noNovo->ant = lista->ult;
    noNovo->info = aluno;
    noNovo->prox = NULL;
    lista->ult = noNovo;
    if(lista->prim == NULL){
        lista->prim = noNovo;
    }
    
}

void mostrarInfo(Aluno aluno)
{
    printf("Nome: %s, Idade: %d\n", aluno.nome, aluno.idade);
}

void mostrarLista(Lista lista)
{
    while (lista.prim)
    {
        mostrarInfo(lista.prim->info);
        // Após a impressão da primeira posição, a primeira posição recebe o próximo elemento.
        lista.prim = lista.prim->prox;
    }
}

void mostrarLista2(Lista *lista)
{
    No *aux = lista->prim;
    while (aux)
    {
        mostrarInfo(aux->info);
        // Após a impressão da primeira posição, a primeira posição recebe o próximo elemento.
        aux = aux->prox;
    }
}

Aluno *buscarElemento(Lista lista, int chaveIdade)
{
    while (lista.prim)
    {
        if (lista.prim->info.idade == chaveIdade)
        {
            return &lista.prim->info;
        }
        // Após a impressão da primeira posição, a primeira posição recebe o próximo elemento.
        lista.prim = lista.prim->prox;
    }
    return NULL;
}

int removerElemento(Lista *lista, int chaveIdade)
{
    No *aux, *anterior;
    if (lista->prim)
    {
        aux = lista->prim;
        if (lista->prim->info.idade == chaveIdade)
        {
            lista->prim = aux->prox;
            free(aux);
            return 1;
        }
        else
        {
            anterior = aux;
            aux = aux->prox;
            while (aux)
            {
                if (aux->info.idade == chaveIdade)
                {
                    anterior->prox = aux->prox;
                    free(aux);
                }
                anterior = aux;
                aux = aux->prox;
            }
        }
    }
    return 0;
}

void main()
{
    
}