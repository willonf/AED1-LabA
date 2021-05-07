#include "stdio.h"
#include "math.h"

typedef struct ponto Ponto;
struct ponto{
  float x,y;
};

typedef struct circulo Circulo;
struct circulo {
  Ponto c; // centro do circulo
  float r; //raio
};

int intersecao(Circulo* a, Circulo* b);

void main(){
    Circulo circle1, circle2;
    scanf("%f%f%f", &circle1.c.x, &circle1.c.y, &circle1.r);
    scanf("%f%f%f", &circle2.c.x, &circle2.c.y, &circle2.r);
    printf("%d", intersecao(&circle1, &circle2));
}

int intersecao(Circulo* a, Circulo* b){
    double dist;
    float sumRadius = (*a).r + (*b).r;
    float x1=(*a).c.x;
    float y1=(*a).c.y;
    float x2=(*b).c.x;
    float y2=(*b).c.y;
    dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    if(dist > sumRadius){
        return 0;
    }
    return 1;
}