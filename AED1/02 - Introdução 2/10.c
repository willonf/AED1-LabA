#include "stdio.h"
int main()
{
    int number1, number2, number3;
    int meio;
    scanf("%d%d%d", &number1, &number2, &number3);
    if (number1 > number2 && number1 > number3)
    {
        if (number2 < number3)
        {
            meio = number3;
        }
        else
        {
            meio = number2;
        }
    } else if(number2>number3){
        if (number1<number3){
            meio = number3;
        } else {
            meio = number1;
        }
    } else {
        if (number1<number2){
            meio = number2;
        } else {
            meio=number1;
        }
    }
    printf("%d", meio);
}
