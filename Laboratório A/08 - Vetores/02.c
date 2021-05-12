#include "stdio.h"

void main()
{
    int array[100];
    int n;
    float media = 0, soma = 0;
    int cont = 0, b = 0, a = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        cont++;
        soma += array[i];
    }
    media = (float) soma / cont;

    for (int i = 0; i < n; i++)
    {
        if (array[i] > media)
        {
            b++;
        }
        else if(array[i] < media)
        {
            a++;
        }
    }
    printf("%d %d", a, b);
}