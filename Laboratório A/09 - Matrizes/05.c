#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define DIA 7


int maiorVenda(int N, int A[][N]);

int main(void)
{
    int N;
    scanf("%d", &N);

    int matrix[N][7];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < DIA; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%d", maiorVenda(N, matrix));
}

int maiorVenda(int N, int A[][DIA])
{
    int vendedor = 0;
    int total[N];
    int pos = 0;
    for (int i = 0; i < N; i++)
    {
        total[pos] = 0;
        for (int j = 0; j < DIA; j++)
        {
            total[pos] += A[i][j];
        }
        pos++;
    }
        int maior = total[0];
        for (int i = 0; i < N; i++)
        {
            if (total[i] > maior)
            {
                maior = total[i];
                vendedor = i;
            }
            
        }
        
    return vendedor;
}