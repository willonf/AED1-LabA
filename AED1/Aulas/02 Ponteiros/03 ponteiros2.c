#include "stdio.h"

float soma_prod(float a, float b, int *soma_pointer, int *prod_pointer) {
    
    // *soma_pointer e *prod_pointer estão recebendo o endereço das variáveis soma e produto
    //*soma_pointer = &soma
    //*prod_pointer = &produto

    *soma_pointer = a + b;
    *prod_pointer = a * b;
}



int main(void){

    int soma, produto;
    soma_prod(3,5, &soma, &produto);
    printf("Soma: %d --- Produto: %d\n", soma, produto);
}

