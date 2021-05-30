#include "stdio.h"

int main(void){
    int k;
    scanf("%d", &k);
    int array[k];
    for (int i = 0; i < k; i++) {
        array[i] = i;
    }

    for (int i = 0; i < k; i++) {
        printf("%d\n", array[i]);
    }
    
}

