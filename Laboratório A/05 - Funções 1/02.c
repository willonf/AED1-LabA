#include "stdio.h"

double power(double base, int expoente);


int main(void) {
    double base;
    int expoente;  
    while (scanf("%lf%d", &base, &expoente) != EOF) {
        printf("%.2f\n", power(base, expoente));
    }
    

}


double power(double base, int expoente){
    double result = 1;
    for (int i = 0; i < expoente; i++)
    {
        result *= base;
    }
    
    return result;
}