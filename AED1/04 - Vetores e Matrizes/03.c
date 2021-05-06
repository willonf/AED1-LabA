#include "stdio.h"
#include "math.h"

void histograma(int n, float *v, int *h);

int main(void) {
    int qtde;
    int h[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    scanf("%d", &qtde);
    float v[qtde];
    for(int i = 0; i < qtde; i++){
        scanf("%f", &v[i]);
    }
    histograma(qtde, v, h);
    for(int i = 0; i < 10; i++){
        printf("%d ", h[i]);
    }  
}

void histograma(int n, float *v, int *h){
    for (int i = 0; i < n; i++){
        if (v[i] >= 0 && v[i] < 0.1){
            h[0]++;
        } else if (v[i] >= 0.1f && v[i] < 0.2f){
            h[1]++;
        } else if (v[i] >= 0.2f && v[i] < 0.3f){
            h[2]++;
        } else if (v[i] >= 0.3f && v[i] < 0.4f){
            h[3]++;
        } else if (v[i] >= 0.4f && v[i] < 0.5f){
            h[4]++;
        } else if (v[i] >= 0.5f && v[i] < 0.6f){
            h[5]++;
        } else if (v[i] >= 0.6f && v[i] < 0.7f){
            h[6]++;
        } else if (v[i] >= 0.7f && v[i] < 0.8f){
            h[7]++;
        } else if (v[i] >= 0.8f && v[i] < 0.9f){
            h[8]++;
        } else if (v[i] >= 0.9f && v[i] < 1.0f){
            h[9]++;
        }
    }
}
