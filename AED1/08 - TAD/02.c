#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complexo {
    double a;
    double b;
} Complexo;


Complexo *cmplx_cria(float a, float b);

void cmplx_libera(Complexo * c);

Complexo *cmplx_soma(Complexo * c1, Complexo * c2);

Complexo *cmplx_subtrai(Complexo * c1, Complexo * c2);

Complexo *cmplx_multiplica(Complexo * c1, Complexo * c2);

Complexo *cmplx_divide(Complexo * c1, Complexo * c2);

void main() {

    Complexo *c1;
    Complexo *c2;
    Complexo *soma;
    Complexo *sub;
    Complexo *prod;
    Complexo *div;
    double a, b;

    scanf("%lf%lf", &a, &b);
    c1 = cmplx_cria(a, b);
    scanf("%lf%lf", &a, &b);
    c2 = cmplx_cria(a, b);

    soma = cmplx_soma(c1, c2);
    sub = cmplx_subtrai(c1, c2);
    prod = cmplx_multiplica(c1, c2);
    div = cmplx_divide(c1, c2);

    printf("Soma: parte real: %.2f parte imaginaria: %.2f\n", soma->a, soma->b);
    printf("Subtracao: parte real: %.2f parte imaginaria: %.2f\n", sub->a, sub->b);
    printf("Multiplicacao: parte real: %.2f parte imaginaria: %.2f\n", prod->a, prod->b);
    printf("Divisao: parte real: %.2f parte imaginaria: %.2f\n", div->a, div->b);

    cmplx_libera(c1);
    cmplx_libera(c2);
    cmplx_libera(soma);
    cmplx_libera(sub);
    cmplx_libera(prod);
    cmplx_libera(div);
}

Complexo *cmplx_cria(float a, float b) {
    Complexo *c = malloc(sizeof(Complexo));
    c->a = a;
    c->b = b;
    return c;
}

void cmplx_libera(Complexo * c) {
    free(c);
}

Complexo *cmplx_soma(Complexo * c1, Complexo * c2) {
    Complexo *c = cmplx_cria(0, 0);
    c->a = c1->a + c2->a;
    c->b = c1->b + c2->b;
    return c;
}

Complexo *cmplx_subtrai(Complexo * c1, Complexo * c2) {
    Complexo *c = cmplx_cria(0, 0);
    c->a = c1->a - c2->a;
    c->b = c1->b - c2->b;
    return c;
}

Complexo *cmplx_multiplica(Complexo * c1, Complexo * c2) {
    Complexo *c = cmplx_cria(0, 0);
    c->a = (c1->a) * (c2->a) - (c1->b) * (c2->b);
    c->b = (c1->b) * (c2->a) + (c1->a) * (c2->b);
    return c;
}

Complexo *cmplx_divide(Complexo * c1, Complexo * c2) {
    Complexo *c = cmplx_cria(0, 0);
    c->a = ((c1->a) * (c2->a) + (c1->b) * (c2->b))/(pow(c2->a, 2) + pow(c2->b, 2));
    c->b = ((c1->b) * (c2->a) - (c1->a) * (c2->b))/(pow(c2->a, 2) + pow(c2->b, 2));
    return c;
}