#include "stdio.h"
#include "math.h"

void inverte(int n, int *vet);

int main(void) {
    int qtde;
    int i;
    scanf("%d", &qtde);
    int vetor[qtde];
    for(i = 0; i < qtde; i++){
        scanf("%d", &vetor[i]);
    }
    inverte(qtde, vetor);
    for(i = 0; i < qtde; i++){
        printf("%d ", vetor[i]);
    }
}

void inverte(int n, int *vet){
    int cont = n - 1;
    int aux;
    for(int i = 0; i < n/2; i++) {
        aux = vet[i];
        vet[i] = vet[cont];
        vet[cont] = aux;
        cont--;
    } 
}
