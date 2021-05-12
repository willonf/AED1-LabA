#include "stdio.h"
#include "stdbool.h"

void main()
{
    int diff, valor, aux = 0;
    bool ehCrescente = true;
    while (scanf("%d", &valor) != EOF)
    {
        if (valor - aux < 0) {
            ehCrescente = false;
        }
        aux = valor;
    }

    if(ehCrescente) {
        printf("CRESCENTE");
    } else {
        printf("NAO CRESCENTE");
    }
}