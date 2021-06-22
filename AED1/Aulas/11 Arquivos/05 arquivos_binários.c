//Manipulação de arquivos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const **argv)
{
    FILE *arquivo;
    int numero[5], qtde;

    if (argc < 2)
    {
        printf("Informe o nome do arquivo!");
        exit(1);
    }

    arquivo = fopen(argv[1], "ab");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!");
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &numero[i]);
    }

    // fseek(arquivo, 0, SEEK_SET);

    // qtde = fwrite(&numero, sizeof(int), 1, arquivo);
    qtde = fwrite(numero, sizeof(int), 5, arquivo);

    printf("Quantidade de elementos armazenados: %d\n", qtde);
    // Fechamento do arquivo
    fclose(arquivo);
    return 0;
}
