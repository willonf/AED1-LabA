#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matriz
{
    float **dados;
    int linhas;
    int colunas;
} Matriz;

Matriz *criar_matriz(int linhas, int colunas);
void liberar_matriz(Matriz *matriz);
int ler_matriz(Matriz *matriz, int linha, int coluna);
void escrever_matriz(Matriz *matriz, int linha, int coluna, float valor);
void imprimirMatriz(Matriz *m);
void produto_matriz(Matriz *A, Matriz *B, Matriz *C);

void main()
{
    int La, Ca;
    int Lb, Cb;
    int caso = 0;
    Matriz *matrizA;
    Matriz *matrizB;
    Matriz *matrizC;
    float valor;
    while (true)
    {
        scanf("%d%d", &La, &Ca);
        if (!La && !Ca)
        {
            break;
        }
        caso++;
        matrizA = criar_matriz(La, Ca);
        for (int i = 0; i < La; i++)
        {
            for (int j = 0; j < Ca; j++)
            {
                scanf("%f", &valor);
                escrever_matriz(matrizA, i, j, valor);
            }
        }
        scanf("%d%d", &Lb, &Cb);
        matrizB = criar_matriz(Lb, Cb);
        for (int i = 0; i < Lb; i++)
        {
            for (int j = 0; j < Cb; j++)
            {
                scanf("%f", &valor);
                escrever_matriz(matrizB, i, j, valor);
            }
        }

        printf("Caso #%d\n", caso);
        if (Ca == Lb)
        {
            matrizC = criar_matriz(La, Cb);
            produto_matriz(matrizA, matrizB, matrizC);
            imprimirMatriz(matrizC);
            // printf("Matriz [0][0]: %.2f ", matrizC->dados[0][0]);
        }
        else
        {
            continue;
        }
        liberar_matriz(matrizA);
        liberar_matriz(matrizB);
        liberar_matriz(matrizC);
    }
}

void produto_matriz(Matriz *A, Matriz *B, Matriz *C)
{
    int soma;
    for (int i = 0; i < A->linhas; i++)
    {
        for (int j = 0; j < B->colunas; j++)
        {
            C->dados[i][j] = 0;
            for (int k = 0; k < A->colunas; k++)
            {
                C->dados[i][j] += A->dados[i][k] * B->dados[k][j];
            }
        }
    }
    // printf("Matriz A\n");
    // imprimirMatriz(A);
    // printf("\n\n");
    // printf("Matriz B\n");
    // imprimirMatriz(B);
}

void imprimirMatriz(Matriz *m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            printf("%.2f ", m->dados[i][j]);
        }
        printf("\n");
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
    mat->dados = malloc(linhas * sizeof(float *));
    if (mat->dados == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < linhas; i++)
    {
        mat->dados[i] = malloc(colunas * sizeof(float));
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

void escrever_matriz(Matriz *matriz, int linha, int coluna, float valor)
{
    matriz->dados[linha][coluna] = valor;
}