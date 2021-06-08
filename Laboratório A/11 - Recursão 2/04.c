#include <stdio.h>
#include <string.h>

void agrupa(int numero);

int main(void)
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        if (num == 0)
        {
            printf("%d\n", num);
            continue;
        }
        agrupa(num);
    }
}

void agrupa(int numero)
{
    int divisao = numero / 1000;
    int cont = 1000;
    while (divisao >= 1000)
    {
        divisao /= 1000;
        cont *= 1000;
    }
    int resto = numero - divisao * cont;
    if (!divisao)
    {
        if (numero == 0)
        {
            printf("%03d\n", numero);
        }
        else
        {
            printf("%d\n", numero);
        }
    }
    else
    {
        printf("%d.", divisao);
        agrupa(resto);
    }
}