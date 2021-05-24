#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto {
  double r; //raio
  double t; //angulo
} ponto;

//Recebe duas coordenadas cartesianas e retorna uma struc do tipo ponto com coordenadas polares
ponto* cria (double x, double y);
ponto* cria (double x, double y) {
    struct ponto *p;
    p = malloc(sizeof(ponto));
    p->r = sqrt(pow(x,2) + pow(y, 2));
    p->t = atan2f(x, y);
    return p;
}

//Desaloca a memória utilizada por um ponto
void libera(ponto* p);
void libera(ponto* p) {
    free(p);
}

//Recebe um ponto p, com coordenadas polares, e coloca seu valor, em coordenadas catesianas, nas variáveis apontadas por x e y.
void acessa (ponto* p, double* x, double* y);
void acessa (ponto* p, double* x, double* y) {
    *x = (p->r)*cos(p->t);
    *y = (p->r)*sin(p->t);
}

//Modifica as coordenadas polares do ponto p utilizando as duas coordenadas cartesianas recebidas como parâmetro
void atribui (ponto* p, double x, double y);
void atribui (ponto* p, double x, double y) {
    p->r = sqrt(pow(x,2) + pow(y,2));
    p->t = atan2f(x, y);
}

//Calcula a distância entre dois pontos
double distancia(ponto* p1, ponto* p2);
double distancia(ponto* p1, ponto* p2) {

    double x1;
    double y1; 
    double x2;
    double y2; 
    double distance;

    acessa(p1, &x1, &y1);
    acessa(p2, &x2, &y2);

    distance = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    return distance;
}


void main() {
    struct ponto *p1;
    struct ponto *p2;
    float x, y;

    scanf("%f%f", &x, &y);
    p1 = cria(x, y);
    scanf("%f%f", &x, &y);
    p2 = cria(x, y);
    cria(x, y);


    printf("%.2f", distancia(p1, p2));
}






