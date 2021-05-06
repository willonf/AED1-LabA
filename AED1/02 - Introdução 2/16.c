#include "stdio.h"
#include "math.h"
int main() {
    char gender;
    float weight, height;
    double imc;
    scanf("%c%f%f", &gender, &weight, &height);
    imc = weight/(pow(height,2));
    if (gender == 'M' || gender == 'm'){

        if (imc < 20) {
            printf("Abaixo do normal");
        } else if(imc < 25){
            printf("Normal");
        } else if(imc < 30){
            printf("Obesidade leve");
        } else if( imc < 43){
            printf("Obesidade moderada");
        }
    } else if (gender == 'm' || gender == 'M'){
        if (imc < 19) {
                printf("Abaixo do normal");
            } else if(imc < 24){
                printf("Normal");
            } else if( imc < 29){
                printf("Obesidade leve");
            } else if(imc < 39){
                printf("Obesidade moderada");
        }
	} else {
        printf("Entrada invalida");
    }
}
