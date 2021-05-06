#include "stdio.h"

int converterSegundos(int hora, int minuto, int segundo) {
    int tempo;
    tempo = hora*3600 + minuto*60 + segundo;
    return tempo;
}

int main()
{
	int maior_tempo=0, opcao; 
	int hora, minuto, segundo, tempo1, tempo2, periodo;


    while (1)
    {
        scanf("%d%d:%d:%d", &opcao, &hora, &minuto, &segundo);
        if(opcao == 2){
            break;
        }
        tempo1 = converterSegundos(hora, minuto, segundo);

        scanf("%d%d:%d:%d", &opcao, &hora, &minuto, &segundo);
        
        tempo2 = converterSegundos(hora, minuto, segundo);
        periodo = tempo2 - tempo1;
        if(periodo > maior_tempo){
            maior_tempo = periodo;
        }
    }

	printf("%d\n",maior_tempo);

	return 0;
}