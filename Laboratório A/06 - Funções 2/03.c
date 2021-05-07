#include "stdio.h"
#include "stdbool.h"
#include "math.h"

void piramide(int nivel){
    int linha = nivel;
    int coluna = 2*nivel - 1;
    char piramide [linha][coluna];
    int pivo = coluna/2;
    for(int i = 0; i <= linha; i++) {
        for(int j = 0; j < coluna/2 + 1; j++) {

        }
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
    for(int i = 0; i < nivel; i++) {
        for(int j = 0; j < nivel; j++) {
            printf("%c", quadrado[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int nivel = 4;
    quadrado(nivel);
}
