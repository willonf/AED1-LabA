#include <stdio.h>


int main(){
    int opcao1, opcao2;
    double valor, convertido;
    scanf("%d%d%lf",&opcao1, &opcao2,&valor);
    switch (opcao1)
    {
    case 1:
        switch (opcao2)
        {
        case 1:
            printf("%.2f", valor*0.4536);
            break;
        case 2:
            printf("%.2f", valor/0.4536);
            break;
        case 3:
            printf("%.2f", valor*28.3495);
            break;
        case 4:
            printf("%.2f", valor/28.3495);
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (opcao2)
        {
        case 1:
            printf("%.2f", valor*3.7854);
            break;
        case 2:
            printf("%.2f", valor/37854);
            break;
        case 3:
            printf("%.2f", valor*29.5735);
            break;
        case 4:
            printf("%.2f", valor/29.5735);
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (opcao2)
        {
        case 1:
            printf("%.2f", valor*1.6093);
            break;
        case 2:
            printf("%.2f", valor/1.6093);
            break;
        case 3:
            printf("%.2f", valor*0.9144);
            break;
        case 4:
            printf("%.2f", valor/0.9144);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
   
}