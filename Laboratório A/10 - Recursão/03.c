#include <stdio.h>

int soma(int size, int v[]){
    int i = size;
    if(i == 0){
        return v[i];
    } else {
        return v[i] + soma(size - 1, v);
    }
}

int main(void) {
    int size;
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("%d", soma(size, array));

    
}