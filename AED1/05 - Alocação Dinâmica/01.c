#include "stdio.h"
#include "stdlib.h"

float *reverso(int n, float *v);

int main(void)
{
    float *v;
    float *invertido;
    int n;

    scanf("%d", &n);
    v = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &v[i]);
    }
    invertido = reverso(n, v);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", invertido[i]);
    }
    free(v);
    free(invertido);
}

float* reverso(int n, float *v) {
    int pos = n;
    float* inversoV = malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        inversoV[i] = v[pos-1];
        pos--;
    }
    return inversoV;
}
