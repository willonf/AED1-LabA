#include <stdlib.h>
#include "TorreDeHanoi.h"

// Aloca e retorna um pino vazio
Pino *criarPino()
{
    Pino *p = malloc(sizeof(Pino));
    p->topo = NULL;
    p->numDiscos = 0;
    return p;
}

// Aloca e retornar um disco cujo tamanho é passado como parâmetro
Disco *criarDisco(int tam)
{
    Disco *novoDisco = malloc(sizeof(Disco));
    novoDisco->tamDisco = tam;
    return novoDisco;
}

// Retira um disco do topo de um pino passado como parâmetro
// Troca o "next" do topo para o "next" do disco que foi retirado
Disco *pop(Pino *pino)
{
    Disco *aux = pino->topo;
    pino->topo = pino->topo->next;
    pino->numDiscos = pino->numDiscos - 1;
    return aux;
}

// Coloca um disco no topo de um pino passado como parâmetro
void push(Pino *pino, Disco *disco)
{
    pino->numDiscos = pino->numDiscos + 1;
    // Verifica se o topo está vazio (pino sem discos)
    if (pino->topo == NULL)
    {
        pino->topo = disco;
        disco->next = NULL;
    }
    else // Se o pino já possui discos, o novo disco é colocado no topo,
         // alterando o "next" para o disco que estava no topo anteriormente
    {
        Disco *aux = pino->topo;
        pino->topo = disco;
        disco->next = aux;
    }
}

// Recebe um pino como parâmetro e desaloca os discos desse pino e o próprio pino
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