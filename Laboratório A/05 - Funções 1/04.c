#include "stdio.h"

int primo(int valor);

int main(void) {
    int valor;
    while (scanf("%d", &valor) != EOF) {
        if(primo(valor)){
            printf("%d\n", valor);
        }
    }
}

int primo(int valor) {
    int cont = 0;
    for(int i = 1; i <= valor; i++){
        if (valor % i == 0){
            cont++;
        }
    }
    if(cont == 2){
        return 1;
    } else {
        return 0;
    }
}
