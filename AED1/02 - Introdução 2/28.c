#include <stdio.h>
#include <math.h>
int main() {
    int qtde, number1, number2, number;
    int maior, menor ;
    scanf("%d", &qtde);
    scanf("%d", &number1);
    scanf("%d", &number2);
    maior = fmax(number1, number2);
    menor = fmin(number1, number2);
    for(int i = 2; i < qtde; i++){
        scanf("%d", &number);
        if (number > maior){
            maior = number;
        }
        if (number < menor){
            menor = number;
        }
    }
    printf("%d %d", menor, maior);
}