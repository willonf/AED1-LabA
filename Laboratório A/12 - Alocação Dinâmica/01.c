#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N, M, valor;
    int *vetor;
    int qtde = 0;
    scanf("%d", &N);
    vetor = malloc((N + 1) * sizeof(int));
    for (int i = 0; i < N + 1; i++)
    {
        vetor[i] = i;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &valor);
        for (int j = 0; j < N + 1; j++)
        {
            if (vetor[j] % valor == 0)
            {
                vetor[j] = 0;
            }
        }
    }
    for (int i = 0; i < N + 1; i++)
    {
        if(vetor[i]){
            qtde++;
        }
    }
    printf("%d", qtde);
    return 0;
}
