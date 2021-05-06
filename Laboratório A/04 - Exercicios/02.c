#include "stdio.h"

int main(void) {
    int entrada, open = 0;
	entrada = getchar();
	while( entrada != EOF) {
		if ( entrada == '('){
			open++;
		} else {
			open--;
		}
		if (open < 0){
			open = 1;
			break;
		}
		entrada = getchar();
	}
	if(open == 0) {
		printf("SIM");
	} else {
		printf("NAO");
		
	}
}