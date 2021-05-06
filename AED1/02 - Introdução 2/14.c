#include "stdio.h"
int main()
{
    float idade;

    scanf("%f", &idade);
    if(idade < 10){
        printf("infancia");
    }else if (idade >= 10 && idade < 15)
    {
        printf("pre-adolescencia");
    }

    else if (idade >= 15 && idade <= 19)
    {
        printf("adolescencia");
    }
    else if(idade >= 20 && idade <= 25)
    {
        printf("juventude");
    }
}
