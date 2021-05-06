#include<stdio.h>
#include<stdlib.h>

float** converte_a (int m, int n, float* mat);

int main(){
    int m;
    int n;
    float *mat;
    float **matrizNova;

    scanf("%d", &m);
	scanf("%d", &n);
    mat = malloc(m*n*sizeof(float));
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            scanf("%f", &mat[i*n+j]);
        }
    }

    matrizNova = converte_a(m, n, mat);
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matrizNova[i][j]);
        }
        printf("\n");
    }
    free(mat);
    free(matrizNova);
}

float** converte_a (int m, int n, float* mat) {

    float** novaMat = malloc(m*sizeof(float*));
    for(int i = 0; i < m; i++){
        novaMat[i] = malloc(n*sizeof(float));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            novaMat[i][j] = mat[i*n+j];
        }
    }
       return novaMat;    
}
