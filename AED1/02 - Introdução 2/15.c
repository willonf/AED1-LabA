#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int number1, number2, number3, variation;
    int maior, menor, meio;
	scanf("%d%d%d", &number1, &number2, &number3);
    variation = number1 - number2;
    if(variation < (number2 - number3)){
        variation = number2 - number3;
    } else if(variation < (number3 - number2)){
        variation = number3 - number2;
    } else if (variation < (number2 - number1)){
        variation = number2 - number1;
    } else if (variation < (number1 - number3)){
        variation = number1 - number3;
    }
	printf("%d", abs(variation));
	return 0;
}