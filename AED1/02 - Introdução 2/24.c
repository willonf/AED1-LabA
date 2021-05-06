#include <stdio.h>

int fibonacci (int termo){
	int anterior = 0, fib = 1, suc;

	if(termo == 0){
        suc = anterior;
    } else if(termo == 1) {
        suc = fib;
    } else {
        for (int i = 2; i <= termo; i++)
        // i = 3
        {   //anterior = 0
            //fib = 1
            suc = anterior + fib; // Suc = 1
            anterior = fib; // 1
            fib = suc; // 1
        }
    }
    return suc;
}


int main()
{
    int termo;
    scanf("%d", &termo);
    printf("%d", fibonacci(termo));
}