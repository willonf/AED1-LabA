#include "stdio.h"
#include "math.h"
int main()
{
    float number1, number2, number3;
    float maior, menor, meio;
    scanf("%f%f%f", &number1, &number2, &number3);
    if(number2 > number1 && number2 > number3){
        printf("concova");
    } else if(number2 < number1 && number2 < number3) {
        printf("convexa");
    } else {
        printf("sem inflexao");
    }
}
