#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
#include "TorreDeHanoi.h"

int main()
{

    int m, n;
    int p1, p2;

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

    criarPino();
    criarDisco(m);
}