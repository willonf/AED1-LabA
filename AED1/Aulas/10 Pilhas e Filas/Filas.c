// Filas (Qeues)
// Cada elemento novo é inserido no final
// Só é possível remover elementos do início
#include <stdio.h>
#include <stdlib.h>

// STRUCTS DEFINITION

typedef struct node Node;
typedef struct aluno Aluno;
typedef struct fila Fila;

struct aluno
{
    char nome[30];
    int idade;
};

struct node
{
    Aluno info;
    Node *prox;
};

struct fila
{
    Node *prim;
    Node *fim;
};

// LIST FUNCTIONS

Fila *criarFila()
{
    Fila *fila = malloc(sizeof(Fila));
    fila->prim = NULL;
    fila->fim = NULL;
    return fila;
}

void push(Fila *fila, Aluno aluno)
{
    Node *noNovo = (Node *)malloc(sizeof(Node));
    noNovo->info = aluno;
    noNovo->prox = NULL;

    if(fila->prim == NULL){
        fila->prim = noNovo;
    } else {
        fila->fim->prox = noNovo;
    }
    fila->fim = noNovo;
}

Aluno pop(Fila *fila)
{
    Node *aux = fila->prim;
    Aluno dado = aux->info;
    fila->prim = fila->prim->prox;
    if (fila->prim == NULL) {
        fila->fim = NULL;
    }
    free(aux);
    return dado;
}

int isEmpty(Fila *fila)
{
    if (fila->prim == NULL)
    {
        return 0;
    }
    return 1;
}

void mostrarInfo(Aluno aluno)
{
    printf("Nome: %s, Idade: %d\n", aluno.nome, aluno.idade);
}

void mostrarFila(Fila fila)
{
    while (fila.prim)
    {
        mostrarInfo(fila.prim->info);
        fila.prim = fila.prim->prox;
    }
}

void main()
{
    Aluno a;
    Aluno alunos[30];
    Fila *fila = criarFila();
    for (int i = 0; i < 2; i++)
    {
        printf("Digite o nome do aluno: ");
        scanf("%s", a.nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &a.idade);
        push(fila, a);
    }
    printf("\n\n");
    mostrarFila(*fila);
    pop(fila);
    printf("\n\n");
    mostrarFila(*fila);

    free(fila);
}