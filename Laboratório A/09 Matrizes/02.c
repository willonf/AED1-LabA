#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int ehMagica(int N, int A[][N]);

int main(void)
{
    int N;
    while (true)
    {
        scanf("%d", &N);
        if (N == 0)
        {
            break;
        }
        int matrix[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        if (ehMagica(N, matrix) == 0)
        {
            printf("nao\n");
        }
        else
        {
            printf("sim\n");
        }
    }
}



int ehMagica(int N, int A[][N])
{

    int i, j;
    int soma = 0;
    int v[2 * N + 2];
    int pos = 0, lin = 0, col = 0;

    // Soma diagonal principal
    v[pos] = 0;
    for (i = 0; i < N; i++)
    {
        v[pos] += A[i][i];
    }
    pos++;
    v[pos] = 0;

    // Soma diagonal secundária
    for (i = 0; i < N; i++)
    {
        v[pos] += A[i][N - 1 - i];
    }
    pos++;

    // soma linhas
    for (i = 0; i < N; i++)
    {
        v[pos] = 0;
        for (j = 0; j < N; j++)
        {
            v[pos] += A[i][j];
        }
        pos++;
    }

    // soma colunas
    for (j = 0; j < N; j++)
    {
        v[pos] = 0;
        for (i = 0; i < N; i++)
        {
            v[pos] += A[i][j];
        }
        pos++;
    }

    for (j = 1; j < pos; j++){
        if (v[0] != v[j]) {
            return 0;
        }
    }
    return 1;
}