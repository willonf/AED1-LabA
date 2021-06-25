#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matriz
{
    char **dados;
    int linhas;
    int colunas;
    char nomeArquivo[80];
} Matriz;

Matriz *criar_matriz(int L, int C);
void limparMatriz(Matriz *m);
void definirCorPixel(int L, int C, char cor, Matriz *mat);
void corVertical(int C, int L1, int L2, char cor, Matriz *mat);
void corHorizontal(int L, int C1, int C2, char cor, Matriz *mat);

void escrever_matriz(Matriz *matriz, int linha, int coluna, char carac);
int ler_matriz(Matriz *matriz, int linha, int coluna);
void imprimirMatriz(Matriz *m);
void liberar_matriz(Matriz *matriz);

void main()
{
    char comando, cor;
    int C, L;
    int C1, C2;
    int L1, L2;
    Matriz *tela;
    while (true)
    {
        scanf("%c", &comando);
        switch (comando)
        {
        case 'I':
            scanf("%d%d", &L, &C);
            tela = criar_matriz(L, C);
            break;
        case 'C':
            limparMatriz(tela);
            break;
        case 'L':
            scanf("%d%d", &C, &L);
            scanf("%c", &cor);
            definirCorPixel(L, C, cor, tela);
            break;
        case 'V':
            scanf("%d%d%d%d", &C, &L1, &L2, &cor);
            corVertical(C, L1, L2, cor, tela);
            /* code */
            break;
        case 'H':
            /* code */
            break;
        case 'K':
            /* code */
            break;
        case 'F':
            /* code */
            break;
        case 'S':
            scanf("%s", tela->nomeArquivo);
            printf("%s\n", tela->nomeArquivo);
            imprimirMatriz(tela);
            break;
        default:
            break;
        }
        // imprimirMatriz(tela);
    }
}

Matriz *criar_matriz(int L, int C)
{
    Matriz *mat = malloc(sizeof(Matriz));
    mat->linhas = L;
    mat->colunas = C;
    printf("%d linahs na matriz\n", L);
    if (mat == NULL)
    {
        exit(1);
    }
    mat->dados = malloc(L * sizeof(char *));
    if (mat->dados == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < L; i++)
    {
        mat->dados[i] = malloc(C * sizeof(char));
        if (mat->dados[i] == NULL)
        {
            exit(1);
        }
    }

    limparMatriz(mat);
    return mat;
}

void limparMatriz(Matriz *m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            m->dados[i][j] = 'O';
        }
    }
}

void definirCorPixel(int L, int C, char cor, Matriz *mat)
{
    mat->dados[L][C] = cor;
}

void corVertical(int C, int L1, int L2, char cor, Matriz *mat)
{
    for (int i = L1; i <= L2; i++)
    {
        mat->dados[i][C] = cor;
    }
}

void corHorizontal(int L, int C1, int C2, char cor, Matriz *mat)
{
    for (int i = C1; i <= C2; i++)
    {
        mat->dados[L][i] = cor;
    }
}

void escrever_matriz(Matriz *matriz, int linha, int coluna, char carac)
{
    matriz->dados[linha][coluna] = carac;
}

int ler_matriz(Matriz *matriz, int linha, int coluna)
{
    return matriz->dados[linha][coluna];
}

void imprimirMatriz(Matriz *m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            printf("%c ", m->dados[i][j]);
        }
        printf("\n");
    }
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
