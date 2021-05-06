#include "stdio.h"
#include "math.h"
#define PI 3.14

int main(){
    float r;
    double volume;
    scanf("%f", &r);
    volume = (4/3.0)* PI * pow(r, 3);
    printf("%0.2f", volume);

}