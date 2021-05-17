#include "stdio.h"
#include "stdlib.h"

void bubbleSort(int N, int* array);

int main (){
   int N;
   int *array;
   int a ;
   scanf("%d", &N);

   array = malloc(N * sizeof(int));

   if(array == NULL){
       return 0;
   }

   for (int i = 0; i < N; i++){
       scanf("%d", &array[i]);

   }

   bubbleSort(N, array);
   for (int i = 0; i < N; i++){
       printf("%d ", array[i]);
   }
   free(array);

}

void bubbleSort(int N, int* array) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        int troca = 0;
        for (j = 0; j < N - 1 - i; j++) {
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                troca = 1;
            }
        }
        if (troca == 0){
            return;
        }
    }
}