#include "stdio.h"
#define lanche 5.00
#define salgado 3.50
#define refrigerante 4.00

double calcularpreco(int cod, int qtd);

int main() {
    int C, qtde;
    double total = 0;
    
    while(1) {
        scanf("%d", &C);
        if(C == 0){
            break;
        } else if(C<0 || C>3){
            continue;
        } else{
            scanf("%d", &qtde);
            total += calcularpreco(C, qtde);
        }
    }
    printf("%.2f", total);
}

double calcularpreco(int cod, int qtd) {
    switch (cod) {
    case 1:
        return qtd * lanche;
        break;
    case 2:
        return qtd * salgado;
        break;
    case 3:
        return qtd * refrigerante;
        break;
    default:
    return 0;
        break;
    }
}