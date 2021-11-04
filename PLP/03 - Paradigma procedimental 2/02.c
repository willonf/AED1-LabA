#include <stdio.h>
#include <string.h>

int *removedup(int *vetor)
{
    int tam = 0;

    while (vetor[tam] != NULL)
    {
        tam++;
    }

    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam;)
        {
            if (vetor[j] == vetor[i])
            {
                for (int k = j; k < tam; k++)
                {
                    vetor[k] = vetor[k + 1];
                }
                tam--;
            }
            else
            {
                j++;
            }
        }
    }
    int result[tam];

    for (int i = 0; i < tam; i++)
    {
        result[i] = vetor[i];
    }

    return result;
}

int main(void)
{
    int lista[10];
    int N;
    int result;

    while (scanf("%d", &N), N != 0)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &lista[i]);
        }
        result = (int *)removedup(lista);

        int tam = 0;

        while (result[tam] != NULL)
        {
            tam++;
        }

        for (int i = 0; i < N; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}