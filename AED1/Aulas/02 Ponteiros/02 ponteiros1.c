#include "stdio.h"

int main(void){

    int a, b = 10;
    int *p, *q = &b;

    a = 5; // "a" recebe o valor 5;
    p = &a; // "p" recebe o endereço de memória de a;
    *p = 6; // O conteúdo da variável apontada por p recebe o valor 6, ou seja, a = 6;
    printf("%d", *q);
}
