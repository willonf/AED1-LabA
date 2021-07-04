// EXERCÍCIO FINALIZADO EM 04/07

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct pilhaNo PilhaNo;
typedef struct pilha Pilha;
Pilha *cria_pilha(void);
void pilha_push(Pilha *p, char simbolo);
char pilha_pop(Pilha *p);
bool pilha_vazia(Pilha *p);
float pilha_libera(Pilha *p);
float pilha_imprime(Pilha *p);

struct pilhaNo
{
    char simbolo;
    PilhaNo *prox;
};

struct pilha
{
    PilhaNo *prim;
};

Pilha *cria_pilha(void)
{
    Pilha *p = malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
};

void pilha_push(Pilha *p, char simbolo)
{
    PilhaNo *n = malloc(sizeof(PilhaNo));
    n->simbolo = simbolo;
    n->prox = p->prim;
    p->prim = n;
}

char pilha_pop(Pilha *p)
{
    if (pilha_vazia(p))
    {
        exit(1);
    }
    PilhaNo *aux = p->prim;
    float v = aux->simbolo;
    p->prim = aux->prox;
    free(aux);
    return v;
}

bool pilha_vazia(Pilha *p)
{
    return (p->prim == NULL);
}

float pilha_libera(Pilha *p)
{
    PilhaNo *aux = p->prim;
    while (aux != NULL)
    {
        PilhaNo *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(p);
}

float pilha_imprime(Pilha *p)
{
    for (PilhaNo *aux = p->prim; aux != NULL; aux = aux->prox)
    {
        printf("%c", aux->simbolo);
    }
}

bool ehBalanceada(Pilha *p, char *sequencia)
{
    int size = strlen(sequencia);
    for (int i = 0; sequencia[i] != '\0'; i++)
    {
        char carac;
        switch (sequencia[i])
        {
        case ')':
            if (pilha_vazia(p))
            {
                return false;
            }
            carac = pilha_pop(p);
            if (carac != '(')
            {
                return false;
            }
            break;
        case ']':
            if (pilha_vazia(p))
            {
                return false;
            }
            carac = pilha_pop(p);
            if (carac != '[')
            {
                return false;
            }
            break;
        case '}':
            if (pilha_vazia(p))
            {
                return false;
            }
            carac = pilha_pop(p);
            if (carac != '{')
            {
                return false;
            }
            break;
        default:
            pilha_push(p, sequencia[i]);
        }
    }
    return pilha_vazia(p);
}

int main(void)
{
    char entrada[100];
    bool balanceada;
    int parent = 0, colch = 0, chaves = 0;
    while (scanf("%s", entrada) != EOF)
    {
        Pilha *minhaPilha = cria_pilha();
        balanceada = ehBalanceada(minhaPilha, entrada);
        if (balanceada)
        {
            printf("SIM\n");
        }
        else
        {
            printf("NAO\n");
        }
        pilha_libera(minhaPilha);
    }
    // pilha_imprime(minhaPilha);
}