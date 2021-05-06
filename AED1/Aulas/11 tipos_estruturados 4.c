#include "stdio.h"
#include "stdlib.h"

struct ponto {
    float x;
    float y;
};

int main()
{
    struct ponto *pp = malloc(sizeof(struct ponto));

    printf("Digite as coordenadas x: ");
    scanf("%f", &pp->x);
    
    printf("Digite as coordenadas y: ");
    scanf("%f", &(*pp).y);
    
}