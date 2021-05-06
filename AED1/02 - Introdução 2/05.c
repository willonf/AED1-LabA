#include "stdio.h"
#include"math.h"
int main(){
    double s0, v0, a, t;
    double s, v;
    scanf("%lf%lf%lf%lf", &s0, &v0, &t, &a);
    s = s0 + v0*t + (a*pow(t,2))*0.5;
    v = v0 + a*t;
    printf("%.2f\n%.2f", s, v);
}
