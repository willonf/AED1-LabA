#include "stdio.h"
typedef struct vetor {
    int x;
    int y;
    int z;
} Vetor;

float escalar(Vetor* v1, Vetor* v2);



void main(){
    Vetor v1;
    Vetor v2;

    scanf("%d%d%d", &v1.x, &v1.y, &v1.z);
    scanf("%d%d%d", &v2.x, &v2.y, &v2.z);
    printf("%.2f", escalar(&v1, &v2));
}


float escalar(Vetor* v1, Vetor* v2) {
    return (*v1).x * (*v2).x + (*v1).y * (*v2).y + (*v1).z*(*v2).z;
}