#include<stdio.h>
#include<stdlib.h>

float* transposta(int m, int n, float* mat){
	float* tr = malloc(m*n*sizeof(float*));
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tr[j*n + i] = mat[i*n+j];  // n = 3
        } 
    }
    return tr;
}

int main(){
    int m, n;
    float *v, *transp;

	// leitura de m e n
	scanf("%d", &m);
	scanf("%d", &n);

	// leitura dos elementos da matriz
	v = malloc(m*n*sizeof(float*));
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            scanf("%f", &v[i*n+j]);
        }
    }

	// chama a função que retorna um ponteiro para a matriz transposta
	transp = transposta(m, n, v);

    // imprimir valores da matriz transposta
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", transp[i*n+j]);
        }
        printf("\n");
    }
	free(v);
	free(transp);
}