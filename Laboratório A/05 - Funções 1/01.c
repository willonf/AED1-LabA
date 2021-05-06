#include "stdio.h"

int fatorial(int numberP){
    int fat = 1;
    for(int i = numberP; i > 1; i--){
        fat*=i;
    }
    return fat;
}

int main(void) {
    int number;
	scanf("%d", &number);
    printf("%d", fatorial(number));
    
}