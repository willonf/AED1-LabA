#include <stdio.h>

#define PEDRA   11
#define PAPEL   22
#define TESOURA 33

int main(void) {

    int N;
    int scoreEusapia = 0;
    int scoreBarsanulfo = 0;

    scanf("%d", &N);
    int eusapia [N];
    int barsanulfo [N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &eusapia[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &barsanulfo[i]);
        if((barsanulfo[i] > eusapia[i])){
            if((barsanulfo[i] == 33 && eusapia[i] == 11)){
                scoreEusapia++;
            } else {
                scoreBarsanulfo++;
            }
        } else if(eusapia[i] > barsanulfo[i]) {
            if((eusapia[i] == 33 && barsanulfo[i] == 11)){
                scoreBarsanulfo++;
            } else {
                scoreEusapia++;
            }
        }
    }

    if(scoreBarsanulfo == scoreEusapia) {
        printf("EMPATE");
    } else if(scoreBarsanulfo > scoreEusapia){
        printf("BARSANULFO");
    } else {
        printf("EUSAPIA");
    }
}