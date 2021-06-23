#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int contPrimos(int *primos, int N);
void crivo(int *primos, int N);
int pegaMultiplo(int *primos, int N, int inicio);

int main(int argc, char const *argv[])
{
    int N;
    int *primos;
    scanf("%d", &N);

    primos = malloc(sizeof *primos * (N + 1));
    crivo(primos, N);
    printf("%d", contPrimos(primos, N));
    free(primos);
    return 0;
}

void crivo(int *primos, int N)
{
    int maior = N;
    int multiplo = 2;
    for (int i = 0; i <= N; i++)
    {
        primos[i] = 1;
    }
    primos[0] = 0;
    primos[1] = 0;
    multiplo = pegaMultiplo(primos, N, 0);

    while (maior > multiplo * multiplo)
    {
        for (int i = multiplo; i <= N; i += multiplo)
        {
            if (i != multiplo && i % multiplo == 0)
            {
                primos[i] = 0;
            }
        }
        multiplo = pegaMultiplo(primos, N, multiplo);
    }
}

int pegaMultiplo(int *primos, int N, int inicio)
{
    int *aux = malloc(sizeof *primos * (N + 1));
    aux = primos;
    int numero;
    for (int i = inicio + 1; i <= N; i++)
    {
        if (primos[i])
        {
            return i;
        }
    }
}

int contPrimos(int *primos, int N)
{
    int contPrimos = 0;
    int maior = primos[N];
    for (int i = 0; i <= N; i++)
    {
        if (primos[i] == 1)
        {
            contPrimos++;
        }
    }
    return contPrimos;
}
