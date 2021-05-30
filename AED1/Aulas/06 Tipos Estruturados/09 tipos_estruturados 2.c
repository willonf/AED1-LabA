#include "stdio.h"
    
    struct ponto {
        float x;
        float y;
    };

int main(){

    struct ponto p;
    struct ponto *pp;

    pp = &p;
    
    printf("Digite as coordenadas x: ");
    //Sempre usar parenteses para acessar o ponteiro de struct
    scanf("%f", &(*pp).x);
    printf("Digite as coordenadas y: ");
    // Outra forma de acessar o endereço
    scanf("%f", &pp->y);
    // Acesso: (*pp).y ou pp->x
    printf("Coordenadas digitadas: (%.2f; %.2f)", (*pp).y, pp->y);
    
}