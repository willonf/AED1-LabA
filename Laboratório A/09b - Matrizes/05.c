#include <stdio.h>

#define MAX_LINHAS   10
#define MAX_COLUNAS  10

void imprime_transposta(int linhas, int colunas, int matriz[][MAX_COLUNAS])
{
    for (int column = 0; column < colunas; column++)
    {
        for (int line = 0; line < linhas; line++)
        {
            printf("%d ", matriz[line][column]);
        }
        printf("\n");
    }
    
}

int main(void)
{
	int m1[MAX_LINHAS][MAX_COLUNAS] = {
			{ 11, 12, 13 },
			{ 21, 22, 23 },
			{ 31, 32, 33 }
	};
	int m2[MAX_LINHAS][MAX_COLUNAS] = {
			{ 1, 2, 3, 4, 5 }
	};
	int m3[MAX_LINHAS][MAX_COLUNAS] = {
			{ 1 },
			{ 2 },
			{ 3 },
			{ 4 },
			{ 5 }
	};
 	
	printf("Matriz 1 (3x3):\n");
	imprime_transposta(3, 3, m1);
	printf("\n");
	
	printf("Matriz 2 (1x5):\n");
	imprime_transposta(1, 5, m2);
	printf("\n");
	
	printf("Matriz (5x1):\n");
	imprime_transposta(5, 1, m3);
	printf("\n");
}