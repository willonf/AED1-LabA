#include "stdio.h"
#include "stdlib.h"

int* somente_pares (int n, int * v, int *npares);;

int main() {
    int length;
    int *odds;
    int *array;
    int cont = 0;

    scanf("%d",&length);
    array = (int*) malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
        if(array[i] % 2 == 0){
            cont++;
        }
    }

    odds = somente_pares(length, array, odds);
    for (int i = 0; i < cont; i++) {
        printf("%d ", odds[i]);
    }
    free(odds);
    free(array);
}

int* somente_pares (int n, int *v, int *npares) {
    int j = 0;
    npares = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if(v[i] % 2 == 0){
            npares[j] = v[i];
            j++;
        }
    }
    return npares;    
}