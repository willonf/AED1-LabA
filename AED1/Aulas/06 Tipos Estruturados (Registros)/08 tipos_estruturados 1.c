#include "stdio.h"
    
    struct ponto {
        float x;
        float y;
    };

int main(){

    struct ponto p;
    
    printf("Digite as coordenadas x: ");
    scanf("%f", &p.x);
    printf("Digite as coordenadas y: ");
    scanf("%f", &p.y);
    printf("Coordenadas digitadas: (%.2f; %.2f)", p.x, p.y);
    
}