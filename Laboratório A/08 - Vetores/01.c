#include "stdio.h"

void main()
{
    int vetor[30];
    int cont = 0;
    while (scanf("%d", &vetor[cont]) != EOF)
    {
        cont++;
    }

    for (int i = cont - 1; i >= 0; i--)
    {
        printf("%d ", vetor[i]);
    }
}