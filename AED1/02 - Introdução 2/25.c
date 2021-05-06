#include <stdio.h>
#include <math.h>
int main() {
    int n, i = 0;
    double somatorio, resultado;
    scanf("%d", &n);
    do {
		 if( i % 2 == 0){
			somatorio += ( 4 * pow((-1), i) / (2*i) ); 
		 }else {
			somatorio += ( 4 * pow((-1), i) / (2*i + 1) ); 
		 }
        i++;
    } while(i < n);
    resultado = somatorio;
    printf("%.6f", resultado);
}