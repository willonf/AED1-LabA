#include <stdio.h>

int pot(int b, int e)
{
    if(e  == 0){
        return 1;
    } else if( e % 2 == 0){
        return pot(b, e/2) * pot(b, e/2);
    } else {
        return b * pot(b, e-1);
    }
}

int main(void)
{
	int b, e;
	while (scanf("%d%d", &b, &e) != EOF) {
		printf("%d\n", pot(b, e));
	}
}
