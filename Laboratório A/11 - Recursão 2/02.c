#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
}

int somaDigitos(char *num)
{
	int soma = 0;
	int pos = 0;
	while (pos != 0)
	{
		soma += num[pos] - '0';
		if (soma >= 10)
		{
			soma = soma % 10;
		}
		pos++;
	}
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
	cp_parte(numero, 0, size / 3 - 1, p1);
	cp_parte(numero, size / 3, 2 * size / 3 - 1, p2);
	cp_parte(numero, 2 * size / 3, size - 1, p3);
	if (strlen(p1) % 3 != 0 || strlen(p2) % 3 != 0 || strlen(p3) % 3 != 0)
	{
		return 0;
	}
	else
	{
		
		if (somaDigitos)
		{
			/* code */
		}
	}
	return 1;
}
