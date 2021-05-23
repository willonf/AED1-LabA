#include <stdio.h>
int main()
{
    int matriz[3][3] = {{0, 1, 0},
                        {1, 0, 0},
                        {0, 1, 1}};
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }
}
