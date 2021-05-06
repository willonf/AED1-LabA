#include "stdio.h"

int euclidesMDC(int a, int b);

int main() {
    int a, b;
    int retorno;
    while(1){
        retorno = scanf("%d%d", &a, &b);
        if(retorno != EOF){
            printf("%d\n", euclidesMDC(a, b));
        } else {
            break;
        }
    }
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