#include<stdio.h>
#include<stdlib.h>

float* converte_a (int m, int n, float** mat);

int main(){
    int m;
    int n;
    float** mat;
    float* novaMat;

    scanf("%d", &m);
	scanf("%d", &n);
    // Alocando matriz em cada ponteiro do vetor de ponteiros mat
    mat = (float**) malloc(m*sizeof(float*));
    if(mat == NULL) {
        exit(1);
    }
    for(int i = 0; i < m; i++){
        mat[i] = malloc(n*sizeof(float));
        if(mat[i] == NULL) {
            exit(1);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
        scanf("%f", &mat[i][j]);
        }
    }

    novaMat = converte_a(m, n, mat);

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            printf("%.2f ", novaMat[i*n+j]);
        }
        printf("\n");
    }

    for(int i = 0; i < m; i++){
        free(mat[i]);
    }
    free(mat);
    free(novaMat);

}

float* converte_a (int m, int n, float** mat) {
    float* novaMat = malloc(m*n*sizeof(float));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            novaMat[i*n+j] = mat[i][j];
        }
    }
    return novaMat;
}
