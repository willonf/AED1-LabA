#include <stdio.h>
#include <math.h>
int MDC(int number1, int number2)
{
	int bigger, smaller, mdc;
    bigger = (int) (fmax(number1, number2));
    smaller = (int) (fmin(number1, number2));
    for(int i=bigger; i >= 1; i--){
        if(bigger % i == 0 && smaller % i ==0){
            mdc = i;
            break;
        }
    }
    return mdc;
}

int main() {
	int number1, number2, number3, mdc;
    scanf("%d%d%d", &number1, &number2, &number3);

    mdc = MDC(MDC(number1, number2), number3);
    printf("MDC: %d", mdc);

}