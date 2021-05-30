#include <stdio.h>
int main(void)
{
	int L, C;
	scanf("%d%d", &L, &C);
	
	int matriz[L][C];
	
 	for (int line = 0; line < L; line++)
    {
        for (int column = 0; column < C; column++)
        {
            scanf("%d", &matriz[line][column]);
        }
    }
	
	for (int column = 0; column < C; column++)
    {
        for (int line = 0; line < L; line++)
        {
            printf("%d ", matriz[line][column]);
        }
        printf("\n");
    }  
}