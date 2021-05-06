#include <stdio.h>
#include <math.h>

int calcularRaizes(double a, double b, double c, double *px1, double *px2) {
    double delta = pow(b,2) - 4*a*c;

    if(delta < 0){
        return -1;
    } else if (delta == 0){
        double raiz = -b / (2*a);
        *px1 = raiz;
        return 1;
    } else {
        *px1 = (-b + sqrt(delta))/(2*a);
        *px2 = (-b - sqrt(delta))/(2*a);
        return 2;
    }
}

int main(){
    double a, b, c;
    double raiz1, raiz2;
    int qtde;
    scanf("%lf%lf%lf", &a, &b, &c);
    qtde = calcularRaizes(a, b, c, &raiz1, &raiz2);
    if(qtde < 0){
        printf("%d", -1);
    } else if (qtde == 1){
        printf("%d %.2f", qtde, raiz1);
    } else {
        printf("%d %.2f %.2f", qtde, raiz1, raiz2);
    }	
}
