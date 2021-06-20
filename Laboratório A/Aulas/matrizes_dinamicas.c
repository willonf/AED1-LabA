#include <stdio.h>
#include <stdlib.h>

typedef struct matriz
{
    int **dados;
    int linhas;
    int colunas;
} Matriz;

Matriz *criar_matriz(int linhas, int colunas);
void liberar_matriz(Matriz *matriz, int linhas);
int ler_matriz(Matriz *matriz, int linha, int coluna);
void escrever_matriz(Matriz *matriz, int linha, int coluna, int valor);

void main()
{
    Matriz *matriz = criar_matriz(3, 3);
    escrever_matriz(matriz, 0, 0, 1);
    printf("Valor: %d\n", ler_matriz(matriz, 0, 0));
    liberar_matriz(matriz, 3);
    printf("Valor: %d\n", ler_matriz(matriz, 0, 0));
}

Matriz *criar_matriz(int linhas, int colunas)
{
    Matriz *mat = malloc(sizeof(Matriz));
    if (mat == NULL)
    {
        exit(1);
    }
    mat->dados = malloc(linhas * sizeof(int *));
    if (mat->dados == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < linhas; i++)
    {
        mat->dados[i] = malloc(colunas * sizeof(int));
        if (mat->dados[i] == NULL)
        {
            exit(1);
        }
    }
    return mat;
}

void liberar_matriz(Matriz *matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz->dados[i]);
    }
    free(matriz->dados);
    free(matriz);
    printf("Matriz liberada!\n");
}

int ler_matriz(Matriz *matriz, int linha, int coluna)
{
    return matriz->dados[linha][coluna];
}

void escrever_matriz(Matriz *matriz, int linha, int coluna, int valor)
{
    matriz->dados[linha][coluna] = valor;
}