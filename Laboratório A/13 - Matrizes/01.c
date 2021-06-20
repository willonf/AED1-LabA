#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matriz
{
    int **dados;
    int linhas;
    int colunas;
} Matriz;

Matriz *criar_matriz(int linhas, int colunas);
void liberar_matriz(Matriz *matriz);
int ler_matriz(Matriz *matriz, int linha, int coluna);
void escrever_matriz(Matriz *matriz, int linha, int coluna, int valor);

void main()
{
    int La, Ca;
    int Lb, Cb;
    Matriz *matrizA;
    Matriz *matrizB;
    Matriz *matrizC;
    int valor;

    while (true)
    {
        scanf("%d%d", La, Ca);
        if (!La && !Ca)
        {
            break;
        }
        matrizA = criar_matriz(La, Ca);
        for (int i = 0; i < La; i++)
        {
            for (int j = 0; j < Ca; j++)
            {
                scanf("%d", &valor);
                escrever_matriz(matrizA, La, Ca, valor);
            }
        }
        scanf("%d%d", Lb, Cb);
        matrizB = criar_matriz(Lb, Cb);
        for (int i = 0; i < Lb; i++)
        {
            for (int j = 0; j < Cb; j++)
            {
                scanf("%d", &valor);
                escrever_matriz(matrizB, Lb, Cb, valor);
            }
        }

        if (Ca == La)
        {
            printf("Pode");
            matrizC = criar_matriz(La, Cb);
            //Função produto
        }
        else
        {
            continue;
        }
        liberar_matriz(matrizA);
        liberar_matriz(matrizB);
    }
}

int produto_matriz(Matriz *A, Matriz *B)
{
    for (int i = 0; i < A->linhas; i++)
    {
        for (int j = 0; j < B->colunas; j++)
        {
            /* code */
        }
    }
}

Matriz *criar_matriz(int linhas, int colunas)
{
    Matriz *mat = malloc(sizeof(Matriz));
    mat->linhas = linhas;
    mat->colunas = colunas;
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

void liberar_matriz(Matriz *matriz)
{
    for (int i = 0; i < matriz->linhas; i++)
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