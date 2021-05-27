#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    int first = 0;
    int second = 1;
    int third;
    if (n >= 3) {
        for (int i = 0; i < n-1; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
    else if (n == 1 || n == 2)
    {
        return second;
    }
    else
    {
        return first;
    }
}

int main(void)
{
    for (int i = 0; i < 47; i++)
    {
        printf("fib(%d) = %d\n", i, fibonacci(i));
    }
}