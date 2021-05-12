#include "stdio.h"
#include "string.h"

void main()
{
    char word[41];
    int N, length, compare;
    int last = 0, tam;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        scanf("%s", word);

        char wordCopy[strlen(word)];
        last = strlen(word) - 1;

        for (int j = 0; j <= strlen(word); j++) {
            wordCopy[j] = word[last];
            last--;
        }

        compare = strcmp(word, wordCopy);
        if (compare == 0) {
            printf("%s: palindromo  |  Compare = %d\n", wordCopy, compare);
        }
        else {
            printf("%s: normal  |  Compare = %d\n", wordCopy, compare);
        }
    }
}