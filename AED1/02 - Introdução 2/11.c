#include "stdio.h"
int main()
{
    double number1, number2, number3, number4, media;
    double maior, menor;
    double vetor[4];

    scanf("%lf%lf%lf%lf", &number1, &number2, &number3, &number4);
    vetor [0] = number1;
    vetor [1] = number2;
    vetor [2] = number3;
    vetor [3] = number4;
    maior = vetor[0];
    menor = vetor[1];

    for (int i = 0; i < 4; i++){
        if (vetor[i] > maior){
            maior = vetor[i];
        }
        if (vetor[i] < menor){
            menor = vetor[i];
        }
    }
    media = (number1  + number2 + number3 + number4 - maior - menor) / 2.0;
    
    printf("%.2f", media);
}
