#include "stdio.h"

int main(void) {
    double numero, soma, media;
    int qtde;
    int cont;
    scanf("%d ", &qtde);
    while(qtde != 0){
        cont = 0;
        soma = 0;
        media = 0;
        for (int i = 0; i < qtde; i++) {
            scanf("%lf", &numero);
                soma += numero;
        }
        media = soma / qtde;
        printf("%.2f\n", media);
        scanf("%d ", &qtde);
    }

}