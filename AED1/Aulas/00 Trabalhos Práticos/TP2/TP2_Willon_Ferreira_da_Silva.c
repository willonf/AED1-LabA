#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
#include "TorreDeHanoi.h"



Pino **criarPinos(int n);
int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino);
void imprimir(Pino **pinos, int numPinos, int numDiscos);

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
            printf("Entrada invalida");
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
            printf("Entrada invalida");
            continue;
        }
        else
        {
            break;
        }
    }

    Pino **pinos = criarPinos(n);
    for (int i = m - 1; i >= 0; i--)
    {
        int pos = 0;
        criarDisco(i);
    }
}

Pino **criarPinos(int n)
{
    Pino **novoPino = malloc(n * sizeof(Pino*));
    for (int i = 0; i < n; i++) {
        novoPino[i] = criarPino();
    }
    return novoPino;
}

int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino)
{
    //pop + push

}

void imprimir(Pino **pinos, int numPinos, int numDiscos)
{
    for (int i = 0; i < numPinos; i++)
    {
        
    }
    
}