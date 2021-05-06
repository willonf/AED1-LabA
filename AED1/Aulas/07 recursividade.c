#include "stdio.h"

int fat(int n) {
    if (n<0){
        printf("O numero é negativo!");
        return -1;
    }
    if(n<=1) {
        return n;
    } else {
        return n*fat(n-1);
    }
}

float pot(int x, int y) {
    if (y == 0) {
        return 1;
    } else if(y > 0) {
        return x * pot(x, y-1);
    } else {
        return (1/(float)(x))*pot(x, y+1);
    }
}

int main() {
    int x, y;
    printf("Digite um valor x: ");
    scanf("%d", &x);
    printf("Digite um valor y: ");
    scanf("%d", &y);
    printf("fat (%d) = %d\n", x, fat(x));
    printf("pot (%d, %d) = %.2f\n", x, y, pot(x, y));

    return 0;
}