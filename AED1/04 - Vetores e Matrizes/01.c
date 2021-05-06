#include "stdio.h"
#include "math.h"

void media_variancia(int n, const double x[], double *pm, double *pv){

    for (int i = 0; i < n; i++){
        *pm += x[i];
    }
    *pm /= n;

    for (int i = 0; i < n; i++){
        *pv += pow(x[i]-(*pm), 2);
    }
    *pv /= n;
}

int main(void) {
    double media = 0, variancia = 0;
    int qtde;
    scanf("%d", &qtde);
    double vetor[qtde];
    for (int i = 0; i < qtde; i++){
        scanf("%lf", &vetor[i]);
    }
    media_variancia(qtde, vetor, &media, &variancia);
    printf("%.2f\n", media);
    printf("%.2f", variancia);
}
