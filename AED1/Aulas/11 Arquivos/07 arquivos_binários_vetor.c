//Manipulação de arquivos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const **argv)
{
    FILE *arquivo;
    int numero[3], qtde;

    if (argc < 2)
    {
        printf("Informe o nome do arquivo!");
        exit(1);
    }

    arquivo = fopen(argv[1], "rb");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!");
        exit(1);
    }

    do
    {
        qtde = fread(numero, sizeof(int), 3, arquivo);
        printf("Quantidade de elementos lidos: %d\n", qtde);

        for (int i = 0; i < qtde; i++)
        {
            printf("Numero [%d] = %d\n", i, numero[i]);
        }
    } while (qtde > 0);

    // Fechamento do arquivo
    fclose(arquivo);
    return 0;
}
