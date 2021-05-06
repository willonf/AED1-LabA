#include <stdio.h>
#include <stdbool.h> 

int main(void)
{
    printf("char: %d bytes\n", sizeof(char));
    printf("unsigned char: %d bytes\n", sizeof(unsigned char));
    printf("short int: %d bytes\n", sizeof(short int));
    printf("unsigned short int: %d bytes\n", sizeof(unsigned short int));
    printf("int: %d bytes\n", sizeof(int));
    printf("long int: %d bytes\n", sizeof(long int));
    printf("unsigned long int: %d bytes\n", sizeof(unsigned long int));
    printf("float: %d bytes\n", sizeof(float));
    printf("double: %d bytes\n", sizeof(double));
    printf("bool: %d bytes\n", sizeof(bool));
    printf("void: %d bytes\n", sizeof(void));
}
