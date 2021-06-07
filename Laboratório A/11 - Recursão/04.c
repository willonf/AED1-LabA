#include <stdio.h>

int main(void)
{
    int num;
	while (scanf("%d", &num) != EOF)
    {
        printf("%d", agrupa(num));
    }
    
}

int agrupa (int numero) {
    
    if() {
        return numero;
    } else {
        return agrupa();
    }
}