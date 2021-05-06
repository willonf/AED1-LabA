#include "stdio.h"

int main(void)
{
    float valorEmReal;
    int ced100, ced50, ced20, ced10, ced5, ced2, ced1, valorAtual;

    scanf("%f", &valorEmReal);

    ced100 = valorEmReal / 100;
    valorAtual = valorEmReal-100*ced100;

    ced50 = valorAtual / 50;
    valorAtual = valorAtual-50*ced50;

    ced20 = valorAtual / 20;
    valorAtual = valorAtual-20*ced20;

    ced10 = valorAtual / 10;
    valorAtual = valorAtual-10*ced10;

    ced5 = valorAtual / 5;
    valorAtual = valorAtual-5*ced5;

    ced2 = valorAtual / 2;
    ced1 = valorAtual-2*ced2;
    
    
    printf("R$100: %d\n", ced100);
    printf("R$50: %d\n", ced50);
    printf("R$20: %d\n", ced20);
    printf("R$10: %d\n", ced10);
    printf("R$5: %d\n", ced5);
    printf("R$2: %d\n", ced2);
    printf("R$1: %d\n", ced1);
}