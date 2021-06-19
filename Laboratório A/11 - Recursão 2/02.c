#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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
	// printf("\nNumero em somaDigitos: %s\n", num);
	int size = strlen(num);
	int cont = 0;
	int soma = 0;
	int pos = 0;
	if (strlen(num) == 1)
	{
		return (int)(num[0]);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			soma = soma + (num[i] - '0');
		}
	}
	// printf("Soma digitos: %d -- Size: %d\n", soma, size);
	return soma;
}

int somaNumeros(char *num1, char *num2)
{
	int size = strlen(num1);
	int soma = 0;
	int casa = 1;
	for (int i = size - 1; i >= 0; i--)
	{
		int n1 = num1[i] - '0';
		int n2 = num2[i] - '0';
		if ((n1 + n2) >= 10)
		{
			soma = (n1+n2) % 10;
			printf("\n Soma atual modulo:  %d\n", soma);
		}
		else
		{
			soma += (n1 + n2);
		}
		soma *= casa;
		casa = casa * 10;
		printf("\n Soma total atual:  %d\n", soma);
	}

	printf("Soma numeros: %d\n", soma);
	return soma;
}

int trilegal(char numero[])
{
	char size = strlen(numero);
	char p1[40];
	char p2[40];
	char p3[40];
	if (size == 3)
	{
		int intP1 = numero[0] - '0';
		int intP2 = numero[1] - '0';
		int intP3 = numero[2] - '0';
		int soma = intP1 + intP2;
		if (intP1 + intP2 > 10)
		{
			soma = soma % 10;
		}
		bool cond = soma == intP3;

		if (trilegal(p1) && trilegal(p2) && trilegal(p3) && cond)
		{
			return 1;
		}
		return 0;
	}
	else if (size % 3 != 0)
	{
		if (size == 1)
		{
			return 1;
		}
		return 0;
	}
	else if (size > 3)
	{
		int somaP1P2;
		cp_parte(numero, 0, size / 3 - 1, p1);
		cp_parte(numero, size / 3, 2 * size / 3 - 1, p2);
		cp_parte(numero, 2 * size / 3, size - 1, p3);
		int intP3 = atoi(p3);
		int somaP1 = somaDigitos(p1);
		int somaP2 = somaDigitos(p2);
		int somaP3 = somaDigitos(p3);
		bool cond1 = somaP1 == somaP2;
		somaP1P2 = somaNumeros(p1, p2);
		// printf("INT P3: %s\n", soma);

		if (trilegal(p1) && trilegal(p2) && trilegal(p3))
		{
			printf("entrou");
			// if (cond1 && cond2)
			// {
			// }
			return 0;
		}
		return 0;
	}
}

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
