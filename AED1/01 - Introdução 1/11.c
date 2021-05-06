#include "stdio.h"

int main(void){
    float galaoUSA, taxaConv, valor;
    scanf("%f%f", &galaoUSA, &taxaConv);
    valor = (galaoUSA/3.7854) *  taxaConv;
    printf("R$ %0.2f", valor);
}