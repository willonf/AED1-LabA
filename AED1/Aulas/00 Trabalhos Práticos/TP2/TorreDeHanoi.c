#include <stdlib.h>
#include "TorreDeHanoi.h"

// Interface structs
struct disco // Nó da Pilha
{
    // O disco é representado por uma fila
    char tamDisco; // Tamanho do disco
    Disco *next;   // Ponteiro que aponta para o próximo disco
};

struct pino //Pilha de discos
{
    // O pino é representado por uma pilha de discos
    Disco *topo;    // Ponteiro para o topo da pilha
    char NumDiscos; //quantidade de discos
};


// Interface functions
Pino *criarPino()
{
    Pino *p = malloc(sizeof(Pino));
    p->topo = NULL;
    p->NumDiscos = 0;
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
    return aux;
}


void push(Pino *pino, Disco *disco)
{
    Pino * aux = pino->topo->next;
    pino->topo = disco;
    pino->topo->next = aux;
    pino->NumDiscos = pino->NumDiscos + 1;
}


void excluirPino(Pino *pino)
{
    Pino *aux = pino->topo;
    while (aux != NULL)
    {
        Pino *aux2 = aux->topo;
        free(aux);
        aux = aux2;
    }
    free(pino);
}