#include "stdio.h"
#include "string.h"
#include "stdbool.h"

void main()
{
    char word[41];
    char wordCopy[41];
    int N, length;
    bool palind;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", word);
        length = strlen(word);
        printf("Length/2 == %d e Length == %d\n", length/2, length);
        for(int j = 0; j < length/2; j++) {
            if(word[j] != word[length-1-i]) {
                palind = false;
                printf("%s: normal\n", word);
                break;
            } else {
                printf("%s: palindromo\n", word);
                break;
            }
        }
    }
}