#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
            if (numero == 2)
            {
                printf("%d: %d\n", numero, 2);
            }
            else if (numero % 2 == 0 || numero < 1)
            {
                printf("%d: 2\n", numero);
            }
            else
            {
                int x = sqrt(numero);
                int i = 3;
                int cont = 0;
                printf("%d: 2 ", numero);
                while (i <= x && cont < 2)
                {
                    if (numero % i == 0)
                    {
                        printf("%d ", i);
                        cont++;
                    }
                    i+=2;
                }
                printf("\n");
            }
        }
    }
}
