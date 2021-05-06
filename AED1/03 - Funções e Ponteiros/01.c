#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

float calcularVolume(float radius, float height) {
    double result;

    double volEsfera = (4.0/3)*PI*pow(radius, 3);

    double volCalota = (1.0/3.0) * PI * pow(height, 2) * (3*radius - height);

    double raioCilindro = sqrt(pow(radius,2) - pow(radius-height, 2));
    double alturaCilindro = 2 * sqrt(pow(radius,2) - pow(raioCilindro,2));
    double volCilindro = PI * pow(raioCilindro,2) * alturaCilindro ;

    result = volEsfera - 2*volCalota - volCilindro;
    return result;
}

int main(){
    float radius, height;
    scanf("%f%f", &radius, &height);
    printf("%.2f", calcularVolume(radius, height));    	
}
