#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int trilegal(char *string);
int separaTrilegal(int *numero, int esq, int dir);
int somaDigitos(int *num, int esquerda, int direita);


int main(void)
{
	char numero[101];
	scanf("%s", numero);
	while (numero[0] != 'f')
	{
		if (trilegal(numero))
		{
			printf("TRILEGAL!\n");
		}
		else
		{
			printf("Chato.\n");
		}
		scanf("%s", numero);
	}
}

int separaTrilegal(int *numero, int esq, int dir)
{
	int N = dir - esq;
	if (N == 1) {
		return 1;
	}
	if (N % 3 != 0) {
		return 0;
	}

	int p1 = esq;
	int p2 = esq + N/3;
	int p3 = p2 + N/3;
	
	if (N > 3) {
		int soma1 = somaDigitos(numero, p1, p2);
		int soma2 = somaDigitos(numero, p2, p3);
		if (soma1 != soma2) {
			return 0;
		}
	}

	int i;
	for (i = 0; i < N/3; i++) {
		if ((numero[p1 + i] + numero[p2 + i]) % 10 != numero[p3 + i]) {
			return 0;
		}
	}

	if (N > 1) {
		if (!separaTrilegal(numero, p1, p2)) {
			return 0;
		}
		if (!separaTrilegal(numero, p2, p3)) {
			return 0;
		}
		if (!separaTrilegal(numero, p3, dir)) {
			return 0;
		}
	}

	return 1;
}

int trilegal(char *string)
{
	int numero[100];
	int N = strlen(string);

	for (int i = 0; string[i] != 0; i++) {
		numero[i] = string[i] - '0';
	}
	return separaTrilegal(numero, 0, N);
}

int somaDigitos(int *num, int esquerda, int direita)
{
	int soma = 0;
	for (int i = esquerda; i < direita; i++)
	{
		soma += num[i];
	}
	return soma;
}

