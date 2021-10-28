#include "stdio.h"
#include "stdbool.h"
#include "math.h"

void imprime(int linha, int coluna, char matriz[][coluna]){
    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

void piramide(int nivel){
    int linha = nivel;
    int coluna = 2*nivel - 1;
    char piramide [linha][coluna];
    int pivo1 = coluna/2;
    int pivo2 = coluna/2;
    for(int i = 0; i < linha; i++) {
        for(int j = pivo1; j <pivo2 + 1; j++) {
            piramide[i][j] = '*';
        }
        for (int k = 0; k < pivo1; k++){
            piramide[i][k] = '.';
        }
        for (int k = pivo2+1; k < coluna; k++){
            piramide[i][k] = '.';
        }
        pivo1--;
        pivo2++;
    }
    imprime(linha, coluna, piramide);
}

void triangulo(int level){
    char triangulo[level][level];
    int pivo = 1;
	for (int i = 0; i < level; i++){
		for (int j = 0; j < pivo; j++){
			triangulo[i][j] = '*';
		}
        for(int k = pivo; k < level; k++){
            triangulo[i][k] = '.';
        }
        pivo++;
	}
    imprime(level, level, triangulo);
}

void losango(int nivel){
    if(nivel == 1){
        printf("*\n");
    } else {
        int tam = 2*nivel - 1;
        int pivo1 = tam/2, pivo2 = tam/2;
        char losango[tam][tam];
        for(int i = 0; i < tam/2 + 1; i++) {
            for(int j = pivo1; j <pivo2 + 1; j++) {
                losango[i][j] = '*';
            }
            for (int k = 0; k < pivo1; k++){
                losango[i][k] = '.';
            }
            for (int k = pivo2+1; k < tam; k++){
                losango[i][k] = '.';
            }
            pivo1--;
            pivo2++;
        }
        pivo1 = 0;
        pivo2 = tam;
        for(int i = tam/2+1; i < tam; i++) {
            for(int j = 0; j <pivo1 + 1; j++) {
                losango[i][j] = '.';
            }
            for (int k = pivo1+1; k < pivo2-1; k++){
                losango[i][k] = '*';
            }
            for (int k = pivo2-1; k < tam; k++){
                losango[i][k] = '.';
            }
            pivo1++;
            pivo2--;
        }
        imprime(tam, tam, losango);
    }
}

void quadrado(int nivel) {
    char quadrado[nivel][nivel];
    for(int i = 0; i < nivel; i++) {
        for(int j = 0; j < nivel; j++) {
            if(i == 0 || i == nivel -1){
                quadrado[i][j] = '*';
            } else if(i > 0 && j > 0 && j<nivel-1) {
                quadrado[i][j] = '.';
            } else {
                quadrado[i][j] = '*';
            }
        }
    }
    imprime(nivel, nivel, quadrado);
}



int main() {
    int nivel;
    scanf("%d", &nivel);
    printf("Piramide, nivel %d\n", nivel);
    piramide(nivel);
    printf("Triangulo, nivel %d\n", nivel);
    triangulo(nivel);
    printf("Losango, nivel %d\n", nivel);
    losango(nivel);
    printf("Quadrado, nivel %d\n", nivel);
    quadrado(nivel);
}
