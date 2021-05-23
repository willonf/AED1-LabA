#include "stdio.h"

int comprimento (char *atr);
void copia (char *dest, char *orig);
void concat(char *dest, char *orig);

void main() {

    char str[101], str1[51], str2[51];

    scanf(" %50[^\n]", str1);
    scanf(" %50[^\n]", str2);

    copia(str, str1);
    concat(str, str2);
}