#include "stdio.h"
#include "math.h"
int main()
{
    int number1, number2, number3;
    int maior, menor, meio;
    scanf("%d%d%d", &number1, &number2, &number3);
    if (number1 > number2 && number1 > number3)
    {
        maior = number1;
        if (number2 < number3)
        {
            menor = number2;
            meio = number3;
        }
        else
        {
            menor = number3;
            meio = number2;
        }
    } else if(number2>number3){
        maior = number2;
        if (number1<number3){
            menor = number1;
            meio = number3;
        } else {
            menor = number3;
            meio = number1;

        }
    } else {
        maior = number3;
        if (number1<number2){
            menor = number1;
            meio = number2;
        } else {
            menor = number2;
            meio=number1;
        }
    }
    printf("%d %d %d", menor, meio, maior);
}
