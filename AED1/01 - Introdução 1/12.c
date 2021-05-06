#include "stdio.h"

int main(void)
{
    int tempo, hora, minuto, segundo;

    scanf("%d", &tempo);
    hora = tempo / 3600;
    minuto = (tempo % 3600 )/ 60;
    segundo = (tempo % 60);
    printf("%02d:%02d:%02d", hora, minuto, segundo);
}