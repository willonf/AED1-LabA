#include "stdio.h"
int main(void) {
    float celsius, fahr;

    scanf("%f", &celsius);
    fahr = 1.8*celsius + 32;
    printf("%.02f", fahr);
}