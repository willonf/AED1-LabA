#include <stdlib.h>
#include "TorreDeHanoi.h"

// Interface structs
struct disco // Nó da Pilha
{
    // O disco é representado por uma fila
    Disco *next;   // Ponteiro que aponta para o próximo disco
    char tamDisco; // Tamanho do disco
};

struct pino //Pilha (de discos)
{
    // O disco é representado por uma pilha de discos
    Disco *topo;    // Ponteiro para o topo da pilha
    char NumDiscos; //quantidade de discos
};


// Interface functions
Pino *criarPino()
{
    Pino *p = malloc(sizeof(Pino));
    p->NumDiscos = 0;
    return p;
}

Pino **criarPinos(int n)
{
    Pino **pino = malloc(n * sizeof(Pino*));
    for (int i = 0; i < n; i++) {
        pino[i] = criarPino();
    }
    return pino;
}

Disco *criarDisco(int tam)
{
    Disco *disco = malloc(sizeof(Disco));
    disco->tamDisco = tam;
    return disco;
}


Disco *pop(Pino *pino)
{
}


void push(Pino *pino, Disco *disco)
{
}


void excluirPino(Pino *pino)
{
}


// Other functions

int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino)
{
}

void imprimir(Pino **pinos, int numPinos, int numDiscos)
{
    for (int i = 0; i < numPinos; i++)
    {
        
    }
    
}