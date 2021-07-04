#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;
typedef struct list List;
typedef struct data Data;
List *createList();
void retira_n(List *l, int x);
struct data
{
    int number;
};

struct node
{
    Data data;
    Node *prox;
};

struct list
{
    Node *prim;
};

List *createList()
{
    List *list = malloc(sizeof(List));
    list->prim = NULL;
    return list;
}

void insertLast(List *list, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prox = NULL;
    if (list->prim == NULL)
    {
        list->prim = newNode;
    }
    else
    {
        Node *aux = list->prim;
        while (aux->prox)
        {
            aux = aux->prox;
        }
        aux->prox = newNode;
    }
}

void insertFirst(List *list, Data data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->prox = list->prim;
    list->prim = newNode;
}

void mostrarInfo(Data data)
{
    printf("%d ", data.number);
}

void mostrarLista(List list)
{
    while (list.prim)
    {
        mostrarInfo(list.prim->data);
        list.prim = list.prim->prox;
    }
}

bool buscarElemento(List lista, int x)
{
    List aux = lista;
    while (lista.prim)
    {
        if (lista.prim->data.number == x)
        {
            return true;
        }
        lista.prim = lista.prim->prox;
    }
    return false;
}

void retira_n(List *l, int x)
{
    for (Node *atual = l->prim; atual != NULL; atual = atual->prox)
    {
        if (buscarElemento(*l, x)){
            atual = atual->prox;    
        }
    }
    
}

void main()
{
    List *mainList = createList();
    int N, X;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        Data data;
        scanf("%d", &data.number);
        insertFirst(mainList, data);
    }

    scanf("%d", &X);
    retira_n(mainList, X);

    mostrarLista(*mainList);

    free(mainList);
}