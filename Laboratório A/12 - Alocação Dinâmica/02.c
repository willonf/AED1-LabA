#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int N;
    int tam;
    char *vetor, carac;
    scanf("%d", &N);
    vetor = malloc((N + 1) * sizeof(char));
    tam = N+1;
    for (int i = 0; i < N+1; i++)
    {
        scanf("%c", &vetor[i]);
    }
    
    // for (int i = N+1; i >= 0; i--)
    // {
        printf("%s", vetor);
    // }
    return 0;
}
