// PILHAS (Stacks)
// Cada elemento novo é inserido no topo
// Só é possível remover elementos do topo
#include <stdio.h>
#include <stdlib.h>

// STRUCTS DEFINITION

typedef struct node Node;
typedef struct aluno Aluno;
typedef struct pilha Pilha;

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

struct pilha
{
    Node *topo;
};

// LIST FUNCTIONS

Pilha *criarPilha()
{
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha *pilha, Aluno aluno)
{
    Node *noNovo = (Node *)malloc(sizeof(Node));
    noNovo->info = aluno;
    noNovo->prox = pilha->topo;
    pilha->topo = noNovo;
}

Aluno pop(Pilha *pilha, int chaveIdade)
{
    Node *aux = pilha->topo;
    Aluno dado = aux->info;
    pilha->topo = pilha->topo->prox;
    free(aux);
    return dado;
}

int isEmpty(Pilha *pilha)
{
    if (pilha->topo == NULL)
    {
        return 0;
    }
    return 1;
}

void main()
{
    Aluno a;
    Aluno alunos[30];
    Pilha *pilha = criarPilha();
    for (int i = 0; i < 2; i++)
    {
        printf("Digite o nome do aluno: ");
        scanf("%s", a.nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &a.idade);
        push(pilha, a);
    }
    printf("%d", pop(pilha, a.idade).idade);

    free(pilha);
}