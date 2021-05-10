#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct ponto {
    float x, y;
} Ponto;



int dentroRet(Ponto *v1, Ponto *v2, Ponto *p);

void main() {
    Ponto v1;
    Ponto v2;
    Ponto p;

    scanf("%f%f", &v1.x, &v1.y);
    scanf("%f%f", &v2.x, &v2.y);
    scanf("%f%f", &p.x, &p.y);
    printf("%d", dentroRet(&v1, &v2, &p));
}

int dentroRet(Ponto *v1, Ponto *v2, Ponto *p) {
    bool fora = (*p).x<(*v1).x || (*p).x>(*v2).x || (*p).y<(*v1).y || (*p).y>(*v2).y;
    if(fora){
        return 0;
    }
    return 1;
}