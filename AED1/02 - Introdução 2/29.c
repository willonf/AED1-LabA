

#include <stdio.h>
#include <stdlib.h>
  
int main() {
 int numero; 
 int r; 
 int i; 
  
 scanf("%d", &numero);
 for(i = 31; i >= 0; i--) {

    r = numero >> i;

    if(r & 1) {
        printf("1");
    } else {
        printf("0");
    }
 }
}