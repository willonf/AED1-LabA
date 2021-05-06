#include "stdio.h"
#include "stdbool.h"
#include "math.h"


int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if(a == 0 && b == a ){
            break;
        } else {
            if(ehPrimoGemeo(a, b)){
                printf("%d e %d sao gemeos\n", a, b);
            } else {
                printf("%d e %d nao sao gemeos\n", a, b);
            }
        }
    } 
}
