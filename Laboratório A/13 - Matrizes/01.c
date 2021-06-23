#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matriz
{
    int **dados;
    int linhas;
    int colunas;
} Matriz;

Matriz *criar_matriz(int N);
void liberar_matriz(Matriz *matriz);
int ler_matriz(Matriz *matriz, int linha, int coluna);
void escrever_matriz(Matriz *matriz, int linha, int coluna, int valor);
void imprimirMatriz(Matriz *m);

void main()
{
    Matriz *matriz;

    liberar_matriz(matriz);
}

void imprimirMatriz(Matriz *m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            printf("%d ", ler_matriz(m, i, j));
        }
        printf("\n");
    }
}

Matriz *criar_matriz(int N)
{
    Matriz *mat = malloc(sizeof(Matriz));
    mat->linhas = N;
    mat->colunas = N;
    if (mat == NULL)
    {
        exit(1);
    }
    mat->dados = malloc(N * sizeof(int *));
    if (mat->dados == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        mat->dados[i] = malloc(N * sizeof(int));
        if (mat->dados[i] == NULL)
        {
            exit(1);
        }
    }
    return mat;
}

void liberar_matriz(Matriz *matriz)
{
    for (int i = 0; i < matriz->linhas; i++)
    {
        free(matriz->dados[i]);
    }
    free(matriz->dados);
    free(matriz);
}

int ler_matriz(Matriz *matriz, int linha, int coluna)
{
    return matriz->dados[linha][coluna];
}

void escrever_matriz(Matriz *matriz, int linha, int coluna, int valor)
{
    matriz->dados[linha][coluna] = valor;
}