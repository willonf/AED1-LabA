#include "stdio.h"
#include "stdbool.h"
#include "string.h"

int automato(char cadeia[])
{
    int estado = 0;
    int pos = 0;
    bool cond1;
    bool cond2;
    int tam = strlen(cadeia);
    while (pos < tam)
    {
        // printf("Estado anterior: %d --- ", estado);

        switch (estado)
        {

        case 0:
            if (cadeia[pos] == 'F')
            {
                estado = 5;
            }
            else if (cadeia[pos] >= '1' && cadeia[pos] <= '9')
            {
                estado = 1;
            }
            else if (cadeia[pos] == '0')
            {
                estado = 2;
            }
            break;
        case 1:
            if (cadeia[pos] >= '0' && cadeia[pos] <= '9')
            {
                estado = 1;
            } else {
                estado = 0;
                return estado;
            }
            break;
        case 5:
            if (cadeia[pos] == 'I')
            {
                estado = 6;
            } else {
                estado = 0;
                return estado;
            }
            break;
        case 6:
            if (cadeia[pos] == 'M')
            {
                estado = 7;
            }
            break;
        case 2:
            if (cadeia[pos] == 'x')
            {
                estado = 3;
            } else if(cadeia[pos] == '0') {
                estado = 2;
            } else {
                return estado;
            }
            break;
        case 7:
            if (cadeia[pos] != 'F' || cadeia[pos] != 'I' || cadeia[pos] != 'M')
            {
                estado = 6;
            }
            break;

        case 3:
        case 4:
            cond1 = (cadeia[pos] >= '0') && (cadeia[pos] <= '9');
            cond2 = (cadeia[pos] >= 'A') && (cadeia[pos] <= 'F');
            if (cond1 || cond2)
            {
                estado = 4;
            }
            else
            {
                estado = 3;
                return estado;
            }
            break;
        }

        // printf("Caractere: %c (%d) --- Estado atual: %d \n", cadeia[pos], cadeia[pos], estado);
        pos++;
    }
    return estado;
}

void main()
{
    char cadeia[81];
    int resultado;
    while (true)
    {
        scanf("%s", cadeia);
        resultado = automato(cadeia);
        if (resultado == 1 || resultado == 2)
        {
            printf("%s: decimal\n", cadeia);
        }
        else if (resultado == 4)
        {
            printf("%s: hexadecimal\n", cadeia);
        }
        else if (resultado == 0 || resultado == 3 || resultado == 5 || resultado == 6)
        {
            printf("%s: rejeitado\n",cadeia);
        }
        else if(resultado == 7)
        {
            // printf("FIM");
            break;
        }
   }
}
