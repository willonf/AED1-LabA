#include <stdio.h>
int main()
{
    int matriz[5][5] = {
            { 11, 12, 13, 14, 15 }, 
            { 21, 22, 23, 24, 25 }, 
            { 31, 32, 33, 34, 35 }, 
            { 41, 42, 43, 44, 45 }, 
            { 51, 52, 53, 54, 55 }
    };
           
    int linha_selecionada;
    printf("Qual linha voce deseja zerar?\n");
    scanf("%d", &linha_selecionada);
    
    // Aqui você deve "zerar" e depois imprimir a linha
    for (int column = 0; column < 5; column++)
    {
        matriz[linha_selecionada][column] = 0;
    }

    for (int line = 0; line < 5; line++)
    {
        for (int column = 0; column < 5; column++)
        {
            printf("%d ", matriz[line][column]);
        }
        printf("\n");
    }
    
}