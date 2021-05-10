#include <stdio.h>
#include "stdbool.h"
typedef struct
{
    unsigned short int dia, mes, ano;
} tipoData;

tipoData lerData()
{
    tipoData data;
    scanf("%d%d%d", &data.dia, &data.mes, &data.ano);
    return data;
}

int validaData(tipoData dt)
{
    if (dt.ano >= 1900 && dt.ano <= 2050) {
        switch (dt.mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dt.dia >= 1 && dt.dia <= 31) {
                return 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (dt.dia >= 1 && dt.dia <= 30) {
                return 1;
            }
            break;
        case 2:
            if(((dt.ano % 4 == 0) && (dt.ano % 100 != 0)) || (dt.ano % 400 == 0)) {
                if(dt.dia >= 1 && dt.dia <= 29) {
                    return 1;
                }
            } else if(dt.dia >= 1 && dt.dia <= 28) {
                return 1;
            }
            break;
        }
    }
    return 0;
}

void main()
{
    tipoData dt;
    dt = lerData();

    printf("%d", validaData(dt));
}
