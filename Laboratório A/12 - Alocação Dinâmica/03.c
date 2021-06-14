#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void primo(int numero);
void main()
{
    int N;
    int numero;

    while (true)
    {
        scanf("%d", &numero);
        if (!numero)
        {
            break;
        }
        else
        {
            primo(numero);
        }
    }
}

void primo(int numero)
{
    if (numero == 2) //Verifique se N = 2
    {
        printf("%d: %d\n", numero, 2);
    }
    else if (numero % 2 == 0 || numero < 2)
    {
        printf("%d: 2\n", numero);
    }
    else
    {
        int x = sqrt(numero);
        int i = 3;
        int cont = 2;
        printf("%d: 2 ", numero);
        while (i <= x && cont <= 2)
        {
            if (numero % i == 0)
            {
                cont++;
            }
            printf("%d ", i);
            i += 2;
        }
        printf("\n");
    }
}
