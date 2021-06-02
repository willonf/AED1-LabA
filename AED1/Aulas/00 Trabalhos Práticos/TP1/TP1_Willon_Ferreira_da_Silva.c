#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
#define N 9


void imprime_mat(char M[][N], int n);
int n_bombas(int l, int c, char M[][N], int n);
void minar_campo(char matriz[][N], int n);
void imprime_matriz_final(char matriz[][N], int n);

int main() {
    int tam, linha, coluna;
    int linhaBomba, colunaBomba;
    int qtdeBombas, casas_livres;
    char matriz[N][N];
    int acabou = 1;
    int venceu = 0;

    printf("Digite o tamanho da matriz N x N: ");
    scanf("%d", &tam);
    casas_livres = (8 * tam * tam)/10;

    minar_campo(matriz, tam);


    while (1) {
        imprime_mat(matriz, tam);
        printf("\nDigite linha e coluna desejados: ");
        scanf("%d%d", &linha, &coluna);
        if(linha > tam || coluna > tam || linha < 1 || coluna < 1){
            printf("Entrada invalida.\n");
            continue;
        }
        if(matriz[linha-1][coluna-1] == '*'){
            printf("VOCE PERDEU! FIM DO JOGO.\n");
            imprime_matriz_final(matriz, tam);
            break;
        } else {
            matriz[linha-1][coluna-1] = n_bombas(linha - 1, coluna - 1, matriz, tam) + '0';
            venceu++;
        }
        if(venceu == casas_livres) {
            printf("PARABENS! VOCE VENCEU!\n");
            imprime_matriz_final(matriz, tam);
            break;
        }
    } 
}

void imprime_mat(char M[][N], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d | ", (i + 1));
        for (int j = 0; j < n; j++) {
            if(M[i][j] == '*'){
                printf("? ");
            } else {
                printf("%c ", M[i][j]);
            }
        }
        printf("\n");
    }
    printf("   ");
    for (int i = 0; i < n; i++) {
        printf("--");
    }
    printf("\n   ");
    for (int i = 0; i < n; i++) {
        printf(" %d", (i + 1));
    }
}


void imprime_matriz_final(char matriz[][N], int n){
    for (int i = 0; i < n; i++) {
            printf("%d | ", (i + 1));
            for (int j = 0; j < n; j++) {
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }
        printf("   ");
        for (int i = 0; i < n; i++) {
            printf("--");
        }
        printf("\n   ");
        for (int i = 0; i < n; i++) {
            printf("%d ", (i + 1));
        }
        printf("\n");
}

int n_bombas(int l, int c, char M[][N], int n) {
    int cont = 0;
        if((c + 1) <= n && (c + 1 >= 0) && M[l][c+1] == '*'){
            cont++;
        }
        if ((l + 1 <= n) && (l + 1 >= 0) && M[l + 1][c] == '*'){
            cont++;
        }
        if ((c - 1 <= n) && (c - 1 >= 0) && M[l][c-1] == '*'){
            cont++;
        }
        if ((l - 1 <= n) && (l - 1 >= 0) && M[l-1][c] == '*'){
            cont++;
        }
        if ((c - 1 <= n) && (l - 1 <= n) && (c - 1 >= 0 && l - 1 >= 0) && M[l-1][c-1] == '*'){
            cont++;
        }
        if ((c + 1 <= n) && (l - 1 <= n) && (c + 1 >= 0) && (l - 1 >= 0) && M[l-1][c+1] == '*'){
            cont++;
        }
        if ((c - 1 <= n) && (l + 1 <= n) && (c - 1 >= 0) && (l + 1 >= 0) && M[l+1][c-1] == '*'){
            cont++;
        }
        if ((c + 1 <= n) && (l + 1 <= n) && (c + 1 >= 0) && (l + 1 >= 0) && M[l+1][c+1] == '*'){
            cont++;
        }
        return cont;
    }


void minar_campo(char matriz[][N], int n) {
    srand(time(NULL));
    int linhaBomba, colunaBomba;
    int qtdeBombas = (2*n*n)/10;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                matriz[i][j] = '?';
        }
    }

    for (int i = 0; i < qtdeBombas; i++) {
        linhaBomba = rand()%n;
        colunaBomba = rand()%n;
    matriz[linhaBomba][colunaBomba] = '*';
    }
}