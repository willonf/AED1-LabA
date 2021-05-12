#include <stdio.h>

void modificaVariavelApontada(int **q){
    **q = 2;
}

int main(){
    int x = 1;
    int *xPtr = &x;

    printf("Valor de x: %d\n", x);
    modificaVariavelApontada(&xPtr);
    printf("Valor de x: %d\n", x);

    return 0;
}