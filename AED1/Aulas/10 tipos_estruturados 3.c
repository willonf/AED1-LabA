#include "stdio.h"

/* A função abaixo recebe a struct de forma ineficiente.
 Nesse caso, na pilha de memória da função "imprime" um novo
 espaço de memória é reservado para receber a struct.
 Além disso, não será possível alterar os valores da struct original*/
//  Logo o ideal é usar ponteiros
// void imprime(struct ponto p) {
//     printf("Cordenada: (%.2f; %.2f", p.x, p.y);
// }

void imprime(struct ponto *pp) {
    printf("Cordenada: (%.2f; %.2f", pp->x, (*pp).y);
}

struct ponto {
    float x;
    float y;
};

int main()
{

    struct ponto p;
    printf("Digite as coordenadas x: ");
    scanf("%f", &p.x);
    printf("Digite as coordenadas y: ");
    scanf("%f", &p.y);
    imprime(&p);
}