#include "stdio.h"

// Variáveis globais (Escopo de arquivo)
int global = 10;

// Protótipos
float celsius_fahren(float c);

// Função principal
int main(void){

    float c, f; // Escopo local

    printf("Digite o valor da temperatura em °C: ");
    scanf("%f", &c);

    f = celsius_fahren(c);
    printf("Temperatura em Fahrenheit: %.2f\n", f);
}

// Escrita das funções declaradas como protótipos
float celsius_fahren(float c) {
    float f;
    f = 1.8*c + 32;
    return f;
}