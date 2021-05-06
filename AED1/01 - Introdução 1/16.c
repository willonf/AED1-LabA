#include "stdio.h"
#include "math.h"
#define conv 57.29578
int main(void)
{
    float grau, minuto, segundo;
    float angRad, valorAtual;

    scanf("%f", &angRad);
    valorAtual = angRad*conv;
    grau = floor(valorAtual);
    minuto = floor((valorAtual - grau)*60);

    segundo = floor(((valorAtual - grau)*60 - minuto)*60);
    printf("%.0f graus, %.0f minutos e %.0f segundos", grau, minuto, segundo);

}