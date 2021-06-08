#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ehPrimo(int valor);

void main(void)
{
    int N, pos;
    scanf("%d", &N);
    int tam = (N / 2) + 1;
    int vetor[tam];
    pos = tam - 1;
    int primo = 2;
    while (pos >= 0)
    {
        if (ehPrimo(primo))
        {
            vetor[pos] = primo;
            pos--;
        }
        primo++;
    }

    for (int i = 0; i < N / 2 + 1; i++)
    {

        printf("%d ", vetor[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}

int ehPrimo(int valor)
{
    int cont = 0;
    for (int i = 1; i <= valor; i++)
    {
        if (valor % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}