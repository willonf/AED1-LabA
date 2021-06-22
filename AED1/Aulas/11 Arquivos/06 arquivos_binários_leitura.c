//Manipulação de arquivos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const **argv)
{
    FILE *arquivo;
    int numero, qtde;

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

    fseek(arquivo, 0, SEEK_SET);

    qtde = fread(&numero, sizeof(int), 1, arquivo);
    
    printf("Quantidade de elementos lidos: %d\n", qtde);
    printf("Numero = %d\n", numero);
    // Fechamento do arquivo
    fclose(arquivo);
    return 0;
}
