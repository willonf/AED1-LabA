#include <stdio.h>

int main(void)
{
	int number;
    int cont_pontos = 0;
    int cont_asteriscos = 0;

leitura:
	scanf("%d", &number);
    if (number == 0) {
        goto fim;
    } else if(number == 1) {
        goto escreve_asterisco;
    }

escreve_asterisco:
    printf("*");
    if(cont_pontos > 0) {
        goto escreve_ponto;
    }
    goto pula_linha;

escreve_ponto:
    printf(".");
    if(number > 0) {
        goto pula_linha;
    }

pula_linha:
    printf("\n");
    number--;
    if (number == 0) {
        goto fim;
    } else {
        goto escreve_asterisco;
    }
	
fim:
	return 0;
}
