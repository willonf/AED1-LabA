#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct ponto {
  float x, y;
} Ponto;

float comprimento(int n, Ponto *v);

void main() {
  Ponto *pontos;
  int n;
  float linhaPoligonal;
  scanf("%d", &n);
  pontos = malloc(n * sizeof(Ponto));

  for (int i = 0; i < n; i++) {
    scanf("%f%f", &pontos[i].x, &pontos[i].y);
  }
  linhaPoligonal = comprimento(n, pontos);
  printf("%.2f", linhaPoligonal);
}


float comprimento(int n, Ponto *v) {
  float dist = 0;
  for(int i = 0; i < n-1; i++) {
    dist += sqrtf(powf(v[i+1].x-v[i].x, 2) + powf(v[i+1].y-v[i].y, 2));
  }
  return dist;
}