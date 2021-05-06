#include "stdio.h"
#include "math.h"
#define tax 1.2

void stocks(double initial, int months);

int main() {
    int months;
    double initialValue;
    scanf("%lf%d", &initialValue, &months);
    stocks(initialValue, months);
}

void stocks(double initial, int months){
    double month_value = initial;

    for (int i = 0; i < months; i++) {
        month_value = month_value + (tax/100.0) * month_value;
        printf("%.2f\n", month_value);
    }
}
