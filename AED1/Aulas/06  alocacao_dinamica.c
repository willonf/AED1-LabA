#include "stdio.h"
#include "stdlib.h"

int maint() {
    float *notas, ac = 0;
    int qtde_notas;
    scanf("%d", &qtde_notas);
    
    notas = (float*) malloc(sizeof(float) * qtde_notas);
    if(notas == NULL){
        printf("Memoria insuficiente!");
        return -1;
    }
    for (int i = 0; i < qtde_notas; i++) {
        scanf("%f", &notas[i]);
    }
    qtde_notas--;
    // qtde_notas+=2;
    notas = (float*) realloc(notas, sizeof(float)*qtde_notas); //realloc não causa perda de dados
    if(notas == NULL){
        printf("Memoria insuficiente!");
        return -1;
    }
    free(notas);
    return 0;
}