//Manipulação de arquivos
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const **argv)
{
    // Declaração de um ponteiro para um arquivo salvo em um computador
    FILE *arquivo;
    char texto[100];
    // Abertura de um arquivo. O "r" indica que é apenas para leitura:
    arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL){
        printf("File not found!");
        exit(1);
    }

    // Pegando uma linha do arquivo.
    //Parâmetros: variável onde se quer salvar a linha do arquivo, o tamanho máximo e o arquivo
    fgets(texto, 100, arquivo);
    printf("Linha do arquivo: %s", texto);

    fgets(texto, 100, arquivo);
    printf("Linha do arquivo: %s", texto);

    // Fechamento do arquivo
    fclose(arquivo);
    return 0;
}
