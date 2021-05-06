#include "stdio.h"
#include "stdlib.h"

// Declaração de "alias"
typedef struct ponto Ponto;
typedef struct ponto *PPonto;
struct ponto {
    float x;
    float y;
};

// OU

// struct ponto {
//     float x;
//     float y;
// };
// typedef struct ponto Ponto;
// typedef struct ponto *PPonto;

// OU

// typedef struct ponto {
//     float x;
//     float y;
// } Ponto;

int main() {
    Ponto p;
    PPonto pp;

    pp = malloc(sizeof(struct ponto));
    
}