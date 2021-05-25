#include<stdio.h>

int f(int n)
{
	static int qtde = 1;
    printf("OLA %d\n", qtde);
    if (n>0) {
        n--;
		 qtde++;
        f(n);
        n--;
		 qtde++;
        f(n);
    }

}
int main()
{
   	int n;
    scanf("%d", &n);
    f(n);
 	return 0; 
}
