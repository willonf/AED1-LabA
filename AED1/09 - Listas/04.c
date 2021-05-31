#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;
typedef struct list List;
typedef struct data Data;
List *createList();
void concatena(List *l1, List *l2);
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

void concatena(List *l1, List *l2)
{
    while (l2->prim)
    {
        insertLast(l1, l2->prim->data);
        l2->prim = l2->prim->prox;
    }
}

void main()
{
    List *mainList1 = createList();
    List *mainList2 = createList();
    int N, T;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        Data data;
        scanf("%d", &data.number);
        insertFirst(mainList1, data);
    }

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        Data data;
        scanf("%d", &data.number);
        insertFirst(mainList2, data);
    }

    concatena(mainList1, mainList2);
    mostrarLista(*mainList1);

    free(mainList1);
    free(mainList2);
}