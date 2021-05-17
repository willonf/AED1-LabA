#include "stdio.h"
#include "stdlib.h"

void binarySearch(int *v, int length, int x);

int main (){
   int N;
   int X;
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

   scanf("%d", &X);
   binarySearch(array, N, X);
   free(array);

}

void binarySearch(int *v, int length, int value) {
    int inf = 0;
    int sup = length - 1;
    int meio;
    int comparacoes = 0;

    while(inf <= sup){
        meio = (inf + sup) / 2;
        comparacoes++;
        if(value == v[meio]) {
            printf("%d %d", meio, comparacoes);
            exit(0);
        } else if(value > v[meio]) {
            sup = meio - 1;
        } else {
            inf = meio + 1;
        }
    }
    printf("Elemento nao encontrado");
}