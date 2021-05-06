#include "stdio.h"

int euclidesMDC(int a, int b);
void simplifica_fracao(int *numerador, int *denominador);

int main() {
    int a, b;
    int retorno;
    int mdc;
    while(1){
        retorno = scanf("%d%d", &a, &b);
        if(retorno != EOF){
            simplifica_fracao(&a, &b);
            printf("%d/%d\n", a, b);
        } else {
            break;
        }
    }
}

void simplifica_fracao(int *numerador, int *denominador) {
    int mdc = euclidesMDC(*numerador, *denominador);
    *numerador /= mdc;
    *denominador /= mdc;
}

int euclidesMDC(int a, int b) {
    int maior = a, menor;
    int c;

    while(1){
        if(a == b){
            c = a;
            break;
        } else if (b > a){
            b -= a; 
            continue;
        } else if (a > b) {
            a -= b;
            continue;
        }
    }
    return c;
}

