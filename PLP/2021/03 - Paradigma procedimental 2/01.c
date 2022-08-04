#include <stdio.h>

int main(void)
{
    int lista[10];
    int N;
    int k = 0;

    while (scanf("%d", &N), N != 0)
    {

        // Faz a leitura da lista
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &lista[i]);
        }
        int aux;
        k = 0;
        while (k < N)
        {
            for (int i = 0; i < N - 1; i++)
            {
                if (lista[i] > lista[i + 1])
                {
                    aux = lista[i + 1];
                    lista[i + 1] = lista[i];
                    lista[i] = aux;
                }
            }
            k++;
        }
        

        for (int i = 0; i < N; i++)
        {
            printf("%d ", lista[i]);
        }
        printf("\n");
        
    }
}