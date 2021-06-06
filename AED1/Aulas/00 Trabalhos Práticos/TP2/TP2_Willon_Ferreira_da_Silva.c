#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
#include "TorreDeHanoi.h"

int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino);
void imprimir(Pino **pinos, int numPinos, int numDiscos);
Pino **criarPinos(int n);
void jogar();

int main()
{

    int m, n;
    int p1, p2;
    int pino = 0;

    // Leitura da quantidade n de pinos
    while (true)
    {
        printf("Insira a quantidade de pinos: [3..5] ");
        scanf("%d", &n);
        if (n < 3 || n > 5)
        {
            printf("Entrada invalida\n");
            continue;
        }
        else
        {
            break;
        }
    }

    // Leitura da quantidade m de discos
    while (true)
    {
        printf("Insira a quantidade de discos: [3..5] ");
        scanf("%d", &m);
        if (m < 3 || m > 5)
        {
            printf("Entrada invalida\n");
            continue;
        }
        else
        {
            break;
        }
    }

    // Criação do vetor de pinos
    Pino **vetorPinos = criarPinos(n);

    // Inserção dos discos no primeiro pino
    int tam = m;
    for (int i = 0; i < m; i++)
    {
        Disco *disco = criarDisco(tam);
        tam--;
        push(vetorPinos[0], disco);
        free(disco);
    }

    imprimir(vetorPinos, n, m);

    // Início do jogo (chamada da função Jogar)
    // jogar();
}

Pino **criarPinos(int n)
{
    Pino **novoPino = (Pino **)malloc(n * sizeof(Pino *));
    for (int i = 0; i < n; i++)
    {
        novoPino[i] = criarPino();
    }
    return novoPino;
}

int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino)
{
    //pop do topo origem + push no topo destino
    // Validar tamanho do disco no topo da origem e tam do disco do destino
    // Validar quantidade de discos no disco do destino

    Disco *aux;
    bool condicao = pinos[pinoDestino]->topo->tamDisco > pinos[pinoOrigem]->topo->tamDisco;
    if (condicao)
    {
        return 0;
    }
    aux = pop(pinos[pinoOrigem]);
    push(pinos[pinoDestino], aux);
    return 1;
}

void imprimir(Pino **pinos, int numPinos, int numDiscos)
{
    // Deverá receber como parâmetro um vetor de Pino (pinos),
    // a quantidade de pinos (numPinos) e
    // a quantidade de discos (numDiscos)
    // e imprimir todos os pinos e discos
    int dist = 2 * numDiscos + 2;
    for (int i = 0; i < numDiscos; i++)
    {
        for (int j = 0; j < numPinos; j++)
        {
            printf("%5c", '|');
            /* code */
        }
        printf("\n");
    }
}

// void jogar(Pino **pinos, int qtdePinos)
void jogar()
{
    int pinoOrigem, pinoDestino;
    while (true)
    {
        // imprimir()
        printf("Insira os pinos de origem e de destino: ");
        scanf("%d%d", &pinoOrigem, &pinoDestino);
    }
}