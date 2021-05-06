#include "stdio.h"

int main(void) {
    int qtde;
    int pont ;
    int anel;
    scanf("%d ", &qtde);
    while(qtde != 0){
        pont = 0;
        for (int i = 0; i < qtde; i++) {
            scanf("%d", &anel);
            switch (anel) {
            case 1:
                pont += 100;
                break;
            case 2:
                pont += 60;
                break;
            case 3:
                pont += 20;
                break;
            default:
                break;
            }
            getchar();
        }
        scanf("%d", &qtde);
        printf("%d\n", pont);
    }
}