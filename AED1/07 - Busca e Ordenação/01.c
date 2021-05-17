#include "stdio.h"
#include "stdlib.h"

void bubbleSort(int N, int* array);

void main(){
   int N;
   int *array;
   scanf("%d, &N");
   array = malloc(N * sizeof(int));
   if(array == NULL){
       return 0;
   }
   bubbleSort(N, array);

}

void bubbleSort(int N, int* array) {
    
}