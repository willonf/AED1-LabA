#include "stdio.h"
#include "stdlib.h"

typedef struct ponto{
  float x,y;
} Ponto;

float comprimento(int n, Ponto* v);

void main(){
    Ponto* pontos;
    int n;
    scanf("%d", &n);
    pontos = malloc(n * sizeof(Ponto));

    // for (int i = 0; i < n; i++) {
        scanf("%f%f", pontos[0].x, pontos[0].y);
    // }
    // printf("%.2f", pontos[0].x);
}