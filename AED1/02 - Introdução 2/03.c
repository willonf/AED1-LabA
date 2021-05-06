#include "stdio.h"

int main(){
    unsigned int number1, number2, number3;
    int maior;
    scanf("%d%d%d", &number1, &number2, &number3);
    maior = number1;
    if (number2 > number1 && number2>number3){
        maior= number2;
    } else if(number3 > number2 && number3 > number1) {
        maior = number3;
    }
    printf("maior: %d", maior);
}
