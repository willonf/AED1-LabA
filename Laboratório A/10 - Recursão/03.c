#include <stdio.h>
#include <stdlib.h>

int soma(int size, int *v)
{
    if (!size)
    {
        return 0;
    }
    else
    {
        printf("%d ", v[size-1]);
        return v[size-1] + soma(size-1,v);
    }
}

int main(void)
{
    int size;
    scanf("%d", &size);
    int result = 0;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", array[size - 1 - i]);
    // }
    result = soma(size,  array);
    printf("\n%d", result);
}