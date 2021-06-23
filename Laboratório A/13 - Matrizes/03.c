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
void produto_matriz(Matriz *A, Matriz *B, Matriz *C);
bool verificaIdentidade(Matriz *m);

void main()
{
    int N;
    Matriz *matrizA;
    Matriz *matrizB;
    Matriz *matrizC;
    int valor;
    while (true)
    {
        scanf("%d", &N);
        if (!N)
        {
            break;
        }
        matrizA = criar_matriz(N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &valor);
                escrever_matriz(matrizA, i, j, valor);
            }
        }
        matrizB = criar_matriz(N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &valor);
                escrever_matriz(matrizB, i, j, valor);
            }
        }

        matrizC = criar_matriz(N);
        produto_matriz(matrizA, matrizB, matrizC);
        if (verificaIdentidade(matrizC))
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }

        liberar_matriz(matrizA);
        liberar_matriz(matrizB);
        liberar_matriz(matrizC);
    }
}

void produto_matriz(Matriz *A, Matriz *B, Matriz *C)
{
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

bool verificaIdentidade(Matriz *m)
{
    int linhas = m->linhas;
    int colunas = m->colunas;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if(i == j){
                if(m->dados[i][j] != 1){
                    return false;
                }
            } else {
                if(m->dados[i][j] != 0){
                    return false;
                }
            }
        }
    }
    return true;
}