#include <stdio.h>

void modificaEnderecoApontado(int **q){
    *q = NULL;
}

int main(){
    int x = 1;
    int *xPtr = &x;

    printf("Endereco de xPtr: %p\n", &xPtr);
    printf("Endereco que xPtr aponta: %p\n", xPtr);
    modificaEnderecoApontado(&xPtr);
    printf("\nEndereco de xPtr: %p\n", &xPtr);
    printf("Endereco que xPtr aponta: %p\n", xPtr);
    return 0;
}