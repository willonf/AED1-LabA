#include <stdio.h>

int main(void)
{
	char numero[101];
	
	scanf("%s", numero);
	while (numero[0] != 'f') {
		if (trilegal(numero)) {
			printf("TRILEGAL!\n");
		}
		else {
			printf("Chato.\n");
		}
		
		scanf("%s", numero);
	}
}

int trilegal(char numero[]) {
    
}