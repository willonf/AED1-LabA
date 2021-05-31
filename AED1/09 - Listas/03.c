#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;
typedef struct list List;
typedef struct data Data;
List *createList();
int ultimo(List *l);

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

void insert(List *list, Data data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->prox = NULL;
    if (list->prim == NULL)
    {
        list->prim = newNode;
    } else {
        Node *aux = list->prim;
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = newNode;
    }
}

int ultimo(List *l)
{
    return l->prim->data.number;
}

void main()
{
    List *mainList = createList();
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        Data data;
        scanf("%d", &data.number);
        insert(mainList, data);
    }
    printf("%d", ultimo(mainList));
    free(mainList);
}