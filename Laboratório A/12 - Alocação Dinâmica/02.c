#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int N, i = 0, pos = 0;
    int tam;
    char *vetor, carac;
    char *vetorAux;

    scanf("%d", &N);

    vetor = malloc((N + 1) * sizeof(char));
    vetorAux = malloc((N + 1) * sizeof(char));
    getchar();

    while (pos < N + 1)
    {
        carac = getchar();
        if (carac != ' ')
        {
            vetor[pos] = carac;
            pos++;
        }
    }
    // printf("Pos = %d", pos);

    int len = strlen(vetor);

    for (int i = len - 2; i >= 0; i--)
    {
        printf("%c", vetor[i]);
    }

    return 0;
}
