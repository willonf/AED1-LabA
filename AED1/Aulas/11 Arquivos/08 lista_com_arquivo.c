// LISTA ENCADEADA OU SIMPLESMENTE ENCADEADA
#include <stdio.h>
#include <stdlib.h>
#define ARQ "alunos"
// STRUCTS DEFINITION

typedef struct no No;
typedef struct aluno Aluno;
typedef struct lista Lista;

struct aluno
{
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
    return lista;
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

void mostrarInfo(Aluno a)
{
    printf("Idade: %d\n", a.idade);
}

void mostrarLista2(Lista *lista)
{
    No *aux = lista->prim;
    while (aux)
    {
        mostrarInfo(aux->info);
        aux = aux->prox;
    }
}

void salvarListaNoArquivo(Lista *lista)
{
    FILE *arquivo;
    arquivo = fopen(ARQ, "ab");
    No *aux = lista->prim;
    while (aux)
    {
        fwrite(&aux->info, sizeof(Aluno), 1, arquivo);
        aux = aux->prox;
    }
}

void recuperarLista(Lista *lista)
{
    FILE *arquivo;
    Aluno a;
    arquivo = fopen(ARQ, "rb");

    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!");
        return;
    }

    while (fread(&a, sizeof(Aluno), 1, arquivo))
    {
        inserirFinal(lista, a);
    }
}

void main()
{
    Aluno alunos[30];
    Lista *lista = criarLista();
    for (int i = 0; i < 3; i++)
    {
        Aluno a;
        printf("Digite a idade do aluno: ");
        scanf("%d", &a.idade);
        inserirFinal(lista, a);
    }
    salvarListaNoArquivo(lista);
    printf("Recuperando lista...\n");
    recuperarLista(lista);
    printf("Imprimindo lista:\n");
    mostrarLista2(lista);
    free(lista);
}