#include "stdio.h"

int juntar_moedas(int nuques, int sicles, int galeoes);
void separar_moedas(int valor, int *nuques, int *sicles, int *galeoes);

int main(void)
{
    int compraGaleoes, compraSicles, compraNuques;
    int pagoGaleoes, pagoSicles, pagoNuques;
    int paid, cost, change;
    int changeGaleoes, changeSicles, changeNuques;
    int P, qtde;

    while(1){
        scanf("%d", &P);
        if(!P) {
            break;
        }
        scanf("%d%d%d%d", &qtde, &compraGaleoes, &compraSicles, &compraNuques);
        scanf("%d%d%d", &pagoGaleoes, &pagoSicles, &pagoNuques);

        cost = qtde * juntar_moedas(compraNuques, compraSicles, compraGaleoes);
        paid = juntar_moedas(pagoNuques, pagoSicles, pagoGaleoes);
        
        change = paid - cost;

        separar_moedas(paid, &pagoNuques, &pagoSicles, &pagoGaleoes);
        separar_moedas(cost, &compraNuques, &compraSicles, &compraGaleoes);
        separar_moedas(change, &changeNuques, &changeSicles, &changeGaleoes);

        printf("Valor da compra: %d galeoes, %d sicles, %d nuques\n", compraGaleoes, compraSicles, compraNuques);
        printf("Pagamento: %d galeoes, %d sicles, %d nuques\n", pagoGaleoes, pagoSicles, pagoNuques);
        printf("Troco: %d galeoes, %d sicles, %d nuques\n", changeGaleoes, changeSicles, changeNuques);
        printf("\n");
    }
    return 0;
}

int juntar_moedas(int nuques, int sicles, int galeoes){
    return galeoes*493 + sicles*29 + nuques;
}

void separar_moedas(int valor, int *nuques, int *sicles, int *galeoes) {
    *galeoes = valor / 493;
    *sicles = (valor % 493) / 29;
    *nuques = (valor % 493) % 29;
}