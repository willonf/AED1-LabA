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

int trilegal(char numero[])
{
	if (strlen(numero) % 3 != 0)
	{
		return 0;
	}
	else
	{
		int digitos = strlen(numero) / 3;
		char p[digitos];
		while (true)
		{

			for (int i = 0; i < 3; i++)
			{
				strcat(p, numero[i]);
			}
		}

		return 1;
	}
}