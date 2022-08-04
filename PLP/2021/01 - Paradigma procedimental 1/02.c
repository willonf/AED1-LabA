#include "stdio.h"
#include "stdbool.h"
#include "string.h"

void ehPalindromo(char palavra[])
{
    int first = 0;
    int tam = strlen(palavra) - 1;
    int diff = 0;

    while (tam >= first)
    {
        if (palavra[first] != palavra[tam])
        {
            diff++;
        }
        first++;
        tam--;
    }
    if (diff == 0)
    {
        printf("%s: palindromo\n", palavra);
        return;
    }
    printf("%s: normal\n", palavra);
}

int main()
{
    int n;
    char palavra[41];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", palavra);
        ehPalindromo(palavra);
    }
}
