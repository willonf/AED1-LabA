//Manipulação de arquivos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const **argv)
{
    FILE *arquivo;
    char texto[100];

    if (argc < 2)
    {
        printf("Informe o nome do arquivo!");
        exit(1);
    }

    arquivo = fopen(argv[1], "a+");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!");
        exit(1);
    }

    do
    {
        printf("Digite um texto ou 'fim' para sair: \n");
        scanf("%s", texto);
        // Inserindo strings no arquivo
        fputs(texto, arquivo);
        // Inserindo caracteres no arquivo
        fputc('\n', arquivo);
    } while (strcmp(texto, "fim") != 0);

    // Manipulando o "indicador de linha" do arquivo
    /*
    SEEK_SET = início do arquivo
    SEEK_CUR = posição atual do arquivo
    SEEK_END = final do arquivo
    */
    fseek(arquivo, 0, SEEK_SET);

    while (fgets(texto, 100, arquivo))
    {
        printf("%s", texto);
    }

    // Fechamento do arquivo
    fclose(arquivo);
    return 0;
}
