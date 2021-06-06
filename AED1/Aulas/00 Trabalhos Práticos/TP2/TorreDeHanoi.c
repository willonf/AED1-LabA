#include <stdlib.h>
#include "TorreDeHanoi.h"

// Nó da Pilha




// Interface functions
Pino *criarPino()
{
    Pino *p = malloc(sizeof(Pino));
    p->topo = NULL;
    p->numDiscos = 0;
    return p;
}

Disco *criarDisco(int tam)
{
    Disco *novoDisco = malloc(sizeof(Disco));
    novoDisco->next = NULL;
    novoDisco->tamDisco = tam;
    return novoDisco;
}


Disco *pop(Pino *pino)
{
    Disco *aux = pino->topo;
    pino->topo = pino->topo->next;
    pino->numDiscos = pino->numDiscos - 1;
    return aux;
}


void push(Pino *pino, Disco *disco)
{
    Disco * aux = pino->topo->next;
    pino->topo = disco;
    pino->topo->next = aux;
    pino->numDiscos = pino->numDiscos + 1;
}


void excluirPino(Pino *pino)
{
    Disco *aux = pino->topo;
    while (aux != NULL)
    {
        Disco *aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    free(pino);
}