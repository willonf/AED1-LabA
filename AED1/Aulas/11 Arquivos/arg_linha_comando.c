//Argumentos da linha de comandos

#include <stdio.h>

int main(int argc, char const **argv)
{
    int ac = 0, aux;
    for (int i = 0; i < argc; i++)
    {
        sscanf(argv[i], "%d", &aux);
        ac += aux;
    }
    printf("Soma = %d\n", aux);
    return 0;
}
