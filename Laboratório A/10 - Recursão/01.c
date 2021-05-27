#include <stdio.h>

int mdc(int a, int b)
{
    if (a == b) {
        return a;
    } else {
        if (a > b) {
            return mdc(a - b, b);
        } else {
            return mdc(a, b - a);
        }
    }

}

int main(void)
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		printf("%d\n", mdc(a, b));
	}
}