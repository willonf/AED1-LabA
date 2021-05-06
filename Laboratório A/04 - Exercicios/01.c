#include "stdio.h"

int main(void) {
    int entrada;
	 entrada = getchar();
    while(entrada != EOF){    
		 printf("%c", entrada);
		 entrada = getchar();
	 }
    
}