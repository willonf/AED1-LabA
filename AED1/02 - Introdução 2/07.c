#include <math.h>
#include <stdio.h>

#define PI 3.14

int main(){
    int r, a;
    double x, y, aRad;
    scanf("%d%d", &r, &a);

    aRad = PI * (a/180);
    x = r*cos(aRad);
    y = r*sin(aRad);
    printf("%.2lf %.2lf", x, y);
}