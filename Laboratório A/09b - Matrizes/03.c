#include <stdio.h>
int main() {
    int matrix[3][3];

    for (int line = 0; line < 3; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            scanf("%d", &matrix[line][column]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", matrix[i][i]);
    }
    
    
}