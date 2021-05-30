#include <stdio.h>

void modificaVariavelApontada(int *****q){
    *****q = 2;
}

int main(){
    int x = 1;
    int *xPtr1 = &x;
    int **xPtr2 = &xPtr1;
    int ***xPtr3 = &xPtr2;
    int ****xPtr4 = &xPtr3;
    printf("Valor de x: %d\n", x);
    modificaVariavelApontada(&xPtr4);
    printf("Valor de x: %d\n", x);

    return 0;
}