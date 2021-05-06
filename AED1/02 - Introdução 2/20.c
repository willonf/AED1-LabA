#include <stdio.h>
int main()
{
	int number;
	int count = 0;
	// 0 => Não é primo
	// 1 => É primo
	scanf("%d", &number);
		for (int i = 1; i <= number; i++){
			if(number % i == 0){
				count++;
			}
		}
			if (count == 2){
			printf("1");
		}else{
			printf("0");
		}
}