#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int trilegal(char numero[]);
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
	trilegal(numero);
}

void cp_parte(char *string, int inicio, int fim, char *parte)
{
	int origem = inicio;
	int destino = 0;

	while (origem <= fim)
	{
		parte[destino] = string[origem];
		destino++;
		origem++;
	}
	parte[destino] = 0;
	printf("Parte: %s\n", parte);
}

int somaDigitos(char *num)
{
	int size = strlen(num);
	int cont = 0;
	int soma = 0;
	int pos = 0;
	while (num[pos] != 0)
	{
		soma += num[pos] - '0';
		pos++;
	}
	printf("Soma digitos: %d\n", soma);
	return soma;
}

int somaNumeros(char *num1, char *num2)
{
	int size = strlen(num1);
	int soma = 0;
	for (int i = 0; i < size; i++)
	{
		soma += (num1[i]-'0') + (num2[i] - '0');
		if (soma >= 10)
		{
			soma = soma % 10;
		}
	}
	printf("Soma numeros: %d\n", soma);
	return soma;
}

int trilegal(char numero[])
{
	char size = strlen(numero);
	char *p1 = &numero[40];
	char *p2 = &numero[40];
	char *p3 = &numero[40];

	if (size % 3 != 0)
	{
		if (size == 1)
		{
			return 1;
		}
		return 0;
	}
	else
	{
		cp_parte(numero, 0, (size / 3) - 1, p1);
		cp_parte(numero, size / 3, 2 * (size / 3) - 1, p2);
		cp_parte(numero, 2 * (size / 3), size - 1, p3);
		printf("Int P3: %d\n\n", atoi(p3));
		int intP3 = atoi(p3);
		bool cond1 = somaDigitos(p1) == somaDigitos(p2);
		bool cond2 = somaNumeros(p1, p2) == intP3;

		if (trilegal(p1) && trilegal(p2) && trilegal(p3) && cond1 && cond2)
		{
			return 1;
		}
		return 0;
	}
}
