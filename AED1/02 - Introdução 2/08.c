#include <stdio.h>
#define pedra 0
#define papel 1
#define tesoura 2

int main(){
    int usuario, computador;
    int jogada;
    scanf("%d%d", &usuario, &computador);

    jogada = (usuario == 2 && computador == 1) || (usuario == 1 && computador == 0) || (usuario == 0 && computador == 2);
    //usuario ganhou: 21, 10, 02
    if(jogada){
        printf("usuario venceu");
    } else if (usuario==computador){
        printf("empate");
    } else {
        printf("computador venceu");
    }
    return 0;
}
