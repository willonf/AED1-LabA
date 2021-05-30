// LISTA ENCADEADA OU SIMPLESMENTE ENCADEADA
#include <stdio.h>
#include <stdlib.h>

// STRUCTS DEFINITION

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
    Aluno info;
    No *prox;
};

struct lista
{
    No *prim;
};

// LIST FUNCTIONS

Lista *criarLista()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->prim = NULL;
    // (*lista).prim = NULL;
    return lista;
}

void inserirInicio(Lista *lista, Aluno aluno)
{
    No *noNovo = (No *)malloc(sizeof(No));
    noNovo->info = aluno;
    noNovo->prox = lista->prim;
    lista->prim = noNovo;
}

void inserirFinal(Lista *lista, Aluno aluno)
{
    No *noNovo = (No *)malloc(sizeof(No));
    noNovo->info = aluno;
    noNovo->prox = NULL;
    if (lista->prim == NULL)
    {
        lista->prim = noNovo;
    }
    else
    {
        No *aux = lista->prim;
        while (aux->prox)
        {
            aux = aux->prox;
        }
        aux->prox = noNovo;
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
    Aluno alunos[30];
    Lista *lista = criarLista();
    for (int i = 0; i < 2; i++)
    {
        Aluno a;
        printf("Digite o nome do aluno: ");
        scanf("%s", a.nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &a.idade);
        // inserirInicio(lista, a);
        inserirFinal(lista, a);
    }

    // Atentar-se à troca de ponteiros entre prim e prox
    printf("EXIBINDO A LISTA\n");
    mostrarLista2(lista);
    // printf("BUSCANDO ELEMENTO DE IDADE IGUAL A 3\n");
    // Aluno *aluno = buscarElemento(*lista, 3);
    // if (aluno == NULL)
    // {
    //     printf("Nao encontrado.\n");
    // }
    // else
    // {
    //     mostrarInfo(*aluno);
    // }
    // printf("REMOVENDO ELEMENTO DE IDADE IGUAL A 25\n");
    // removerElemento(lista, 25);
    // printf("EXIBINDO A LISTA\n");
    // mostrarLista2(lista);
    // free(aluno);
    free(lista);
}