#include "stdio.h"

int main(){
    double p1, p2, p3, media_parcial;
    short int aprovado = 1;
    // Media >= 5 e p1 < 3 e p2 < 3 : Aprovado direto
    //Prova final: p3 + maior(p1, p2) : media >= 5
    scanf("%lf%lf%lf", &p1, &p2, &p3);
    int maior = p1;
    if (p2 > maior) {
        maior = p2;
    }
    media_parcial = (p1 + p2)/2;
    
    if (p1 < 3 || p2 < 3 || media_parcial < 5){
        aprovado = 0;
        media_parcial = (maior + p3) / 2;
        if (media_parcial < 5){
            aprovado = 0;
        } else {
            aprovado = 1;
        }
    }
    if (aprovado){
        printf("Aprovado\nMedia: %.2f", media_parcial);
    } else {
        printf("Reprovado\nMedia: %.2f", media_parcial);

    }
}
