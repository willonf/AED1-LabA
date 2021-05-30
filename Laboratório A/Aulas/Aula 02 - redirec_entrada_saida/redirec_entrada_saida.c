#include "stdio.h"

int main(void) {
    int number1, number2;
    int soma, produto;
    scanf("%d%d", &number1, &number2);
    soma = number1 + number2;
    produto = number1*number2;

    printf("Soma: %d + %d = %d\n", number1, number2, soma);
    printf("Produto: %d x %d = %d", number1, number2, produto);
}