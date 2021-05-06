#include "stdio.h"
int main() {
    float celsius, fahr;

    scanf("%f", &fahr);
    celsius = (fahr - 32)/1.8;
    printf("%.02f", celsius);
}