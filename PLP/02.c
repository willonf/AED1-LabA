#include <stdio.h>

int main(void)
{
	int number1, number2;

leitura:
	scanf("%d", &number1);
	scanf("%d", &number2);
	if(number1 > number2) {
		goto fim;
	} else {
		printf("[%d, %d]: ", number1, number2);
	}
	
escrita:
	if (number1 == number2){
		printf("%d\n", number2);
		goto leitura;
	} else {
		printf("%d, ", number1);
		number1++;
		goto escrita;
	}
	
fim:
	return 0;
}
