#include "stdio.h"
#include "math.h"
#define PI 3.14159265358979323846264338327950288 // Definição de uma constante

int main()
{
    float a, b, y, c, angRad;
    scanf("%f%f%f", &a, &b, &y);
    angRad = (y*PI)/180;
    c = sqrt(pow(a,2) + pow(b,2) - 2*a*b*cos(angRad));
    printf("%0.2f", c);
}