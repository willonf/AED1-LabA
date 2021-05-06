#include <stdio.h>
int main() {
    int N, T, tempoTotal, aux, transcorrido;
    scanf("%d", &N);
    scanf("%d", &T);
    aux = T;
    for(int i = 1; i < N; i++){
        scanf("%d", &T);
        tempoTotal = T;
    }
    transcorrido = tempoTotal - aux;
    printf("%d", transcorrido);
}