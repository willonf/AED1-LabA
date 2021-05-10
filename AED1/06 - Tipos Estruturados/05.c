#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

typedef struct retangulo
{
    float base;
    float altura;
} Ret;

typedef struct circulo
{
    float raio;
} Circ;

Ret *ret_circunscrito(Circ *c, float h);
Circ* circ_interno(Ret *r);

void main()
{
    Ret ret;
    Ret* retInscrito;
    Circ circulo;
    Circ* circInscrito;
    scanf("%f%f%f", &circulo.raio, &ret.base, &ret.altura);
    circInscrito = circ_interno(&ret);
    retInscrito = ret_circunscrito(&circulo, ret.altura);
    printf("%.2f\n", circInscrito->raio);
    printf("%.2f %.2f", retInscrito->base, retInscrito->altura);
    free(circInscrito);
    free(retInscrito);
}

Ret *ret_circunscrito(Circ *c, float h) {
    Ret *retInscrito = malloc(sizeof(Ret));
    retInscrito->altura=h;
    retInscrito->base = sqrtf(4*powf(c->raio, 2)-powf(h, 2));
    return retInscrito;
}

Circ* circ_interno(Ret *r)
{
    float menor = r->altura;
    Circ *circInscrito = malloc(sizeof(Circ));
    if (r->base < menor)
    {
        menor = r->base;
    }
    circInscrito->raio = menor/2;
    return circInscrito;
}
