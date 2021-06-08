#define RET 0;
#define TRI 1;
#define CIRC 2;
#define PI 3.14159;

typedef struct listaNo
{
    int tipo;
    void *info;
    ListaNoHet *prox;
} ListaNoHet;

typedef struct listaHet
{
    ListaNoHet *prim;
} ListaHet;

typedef struct retangulo
{
    float b;
    float h;
} Retangulo;

typedef struct triangulo
{
    float b;
    float h;
} Triangulo;

typedef struct circulo
{
    float r;
} Circulo;
