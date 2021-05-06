#include "stdio.h"
#include "math.h"

int main(void) {
    int v[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &v[i][j]);
            v[i][j] *= 5;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
   
}