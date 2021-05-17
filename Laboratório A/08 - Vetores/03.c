#include "stdio.h"
#include "string.h"

void main()
{
    char word[41];
    int N, length, compare;
    int last = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        scanf("%s", word);
        length = strlen(word);
        char wordCopy[strlen(word)];
        
        last = length - 1;

        for (int j = 0; j < length; j++) {
            wordCopy[j] = word[last - j];
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