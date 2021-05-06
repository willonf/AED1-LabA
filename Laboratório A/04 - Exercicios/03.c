#include "stdio.h"

int main(void) {
    int numero1;
    int numero2;
    int areaRet, perimRet;

    while(scanf("%d %d", &numero1, &numero2) != EOF){
        perimRet = 2*(numero1 + numero2);
        areaRet = numero1 * numero2;
        printf("%d %d\n", perimRet, areaRet);
    }
}
