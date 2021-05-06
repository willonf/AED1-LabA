#include <stdio.h>

int main()
{
    int number1, number2, number3;
    scanf("%d%d%d", &number1, &number2, &number3);
    
    printf("%d", number1<=number2 && number1<=number3 && number2<=number3);
   
}