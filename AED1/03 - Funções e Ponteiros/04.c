#include<stdio.h>

void inverte(char *letra1, char *letra2){
    char aux;
    aux = *letra1;
    *letra1 = *letra2;
    *letra2 = aux;
}

int main()
{
   	char x, y;
	scanf("%c %c", &x, &y);
    inverte(&x, &y);
   	printf("%c%c", x, y);
 	return 0; 

}