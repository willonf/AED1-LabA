#include <stdio.h>
#include <string.h>

void agrupa(int numero);

int main(void)
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        agrupa(num);
     printf("\n");
    }
}

void agrupa(int numero)
{
    int divisao = numero / 1000;
    int resto =  numero % 1000;  
    if(numero >= 1000)
    {
      agrupa(divisao);
      printf(".%03d", resto);
    }
    else
    {
        printf("%d", numero);
    }
}