#include <stdio.h>
#include <stdbool.h>

int collatz(int N)
{
    int aux = N;
    int cont = 0;
    while (true)
    {
        if (aux == 1)
        {
            break;
        }
        if (aux % 2 == 0)
        {
            cont++;
            aux = aux / 2;
        }
        else
        {
            cont++;
            aux = aux * 3 + 1;
        }
    }
    return cont;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    printf("%d\n", collatz(N));
    return 0;
}
