// LISTAS CIRCULARES
// Em uma lista circular o último elemento tem o "prox" apontando para o primeiro elemento da lista

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
    No *atual;
};

// LIST FUNCTIONS

Lista *criarLista()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->atual = NULL;
    return lista;
}

void inserir(Lista *lista, Aluno aluno)
{
    No *noNovo = (No *)malloc(sizeof(No));
    noNovo->info = aluno;

    if (lista->atual)
    {
        //Insere um elemento após o atual
        noNovo->prox = lista->atual->prox;
    }
    else
    {
        // Caso lista vazia
        lista->atual = noNovo;
    }
    lista->atual->prox = noNovo;
}

void mostrarInfo(Aluno aluno)
{
    printf("Nome: %s, Idade: %d\n", aluno.nome, aluno.idade);
}

void mostrarLista(Lista *lista)
{
    No *aux;
    // Uma lista circular entra em loop infinito quando fazemos uma busca sempre chamando o próximo elemento.

    if (lista->atual)
    {
        aux = lista->atual;
        do
        {
            mostrarInfo(aux->info);
            aux = aux->prox;
        } while (aux != lista->atual);
    }
}

int removerElemento(Lista *lista, int chaveIdade)
{
    No *aux, *anterior;
    if (lista->atual)
    {
        aux = lista->atual;

        do
        {
            anterior = aux;
            aux = aux->prox;
            if (aux->info.idade == chaveIdade)
            {
                if (anterior == aux)
                {
                    lista->atual = NULL;
                }
                else
                {
                    anterior->prox = aux->prox;
                    if (aux == lista->atual)
                    {
                        lista->atual = aux->prox;
                    }
                }
                free(aux);
                return 1;
            }
        } while (aux != lista->atual);
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
        inserir(lista, a);
    }

    printf("EXIBINDO A LISTA\n");
    mostrarLista(lista);
    printf("REMOVENDO DA LISTA\n");
    removerElemento(lista, 25);
    mostrarLista(lista);
    free(lista);
}