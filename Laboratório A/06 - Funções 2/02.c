#include "stdio.h"
#include "stdbool.h"
#include "math.h"

bool ehPrimoGemeo(int p, int q);
bool primo(int valor);

int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if(a == 0 && b == a ){
            break;
        } else {
            if(ehPrimoGemeo(a, b)){
                printf("%d e %d sao gemeos\n", a, b);
            } else {
                printf("%d e %d nao sao gemeos\n", a, b);
            }
        }
    } 
}

bool ehPrimoGemeo(int p, int q) {
    int maior = p;
    int menor = q;
    if(q > maior) {
        maior = q;
        menor = p;
    }
    if(primo(p) && primo(q) && ( maior == menor + 2)){
        return true;
    } 
    else {
        return false;
    }
}

bool primo(int valor) {
    int cont = 0;
    for(int i = 1; i <= valor; i++){
        if (valor % i == 0){
            cont++;
        }
    }
    if(cont == 2){
        return true;
    }
    return false;
}