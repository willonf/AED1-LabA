#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;
typedef struct list List;
typedef struct data Data;

int comprimento(List *l);
List *createList();

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

void insert(List *list, int value)
{
    Node *node = malloc(sizeof(Node));
    node->data.number = value;
    node->prox = list->prim;
    list->prim = node;
}

int comprimento(List *l)
{
    int length = 0;
    while (l->prim)
    {
        length++;
        l->prim = l->prim->prox;
    }
    return length;
}

void main()
{
    int length = 0, value;
    List *mainList = createList();
    int scanReturn;
    while (true)
    {
        scanReturn = scanf("%d", &value);
        if (scanReturn != EOF)
        {
            insert(mainList, value);
        }
        else{
            break;
        }
    }
    length = comprimento(mainList);
    printf("%d", length);
    free(mainList);
}