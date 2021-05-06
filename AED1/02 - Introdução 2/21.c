#include <stdio.h>

int main(void){
	char simbolo;
	scanf("%c", &simbolo);
	
    int l, c;
	const int N = 12;
	int espaco = 0;
	for(l = 1; l <= N; l++){
		for(c = 1; c <= N; c++){
			if(c == l || c == N - espaco){
				printf("%c%c", simbolo, simbolo);
			}else {
				printf(" ");
			}
			if (c == N){
				espaco++;
				printf("\n");
			}
		}
	}
	return 0;

}