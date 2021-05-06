#include "stdio.h"
#include "math.h"

double fatorial(double numberP);
double seno(double x, int N);

int main(void) {
    double ang;
    int N;
	while(scanf("%lf%d", &ang, &N) != EOF){
        printf("%.10f\n", seno(ang, N));
    }    
}

double fatorial(double numberP){
    double fat = 1.0;
    for(int i = numberP; i > 1; i--){
        fat*=i;
    }
    return fat;
}

double seno(double x, int N){
    int sinal = 1;
    int exp = 1;
    int denom = 1;
    double seno = 0.0;
    for (int i = 0; i < N; i++) {
        seno += sinal*(pow(x, exp)/fatorial(denom));
        sinal *= (-1);
        exp += 2;
        denom+=2;
    }
    return seno;    
}