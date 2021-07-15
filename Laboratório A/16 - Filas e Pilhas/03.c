// EXERCÍCIO FINALIZADO EM 04/07

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
	double *dados;
	int tamanho;
	int capacidade;
} Lista;

Lista *criar_lista(void)
{
	Lista *l = malloc(sizeof(Lista));
	l->tamanho = 0;
	l->capacidade = 10;
	return l;
}

void liberar_lista(Lista *l)
{
	free(l->dados);
	free(l);
}

void lista_inserir_inicio(Lista *lista, double novo)
{
	int aux;
	int last, pos = 0;
	lista->tamanho++;

	if (lista->tamanho > lista->capacidade)
	{
		lista->capacidade++;
		lista->dados = realloc(lista->dados, (lista->tamanho) * sizeof(int));
	}
	last = lista->tamanho - 1;
	for (int i = last; i >= 0; i--)
	{
		lista->dados[i] = lista->dados[i - 1];
	}
	lista->dados[0] = novo;
}

double lista_desempilha(Lista *lista)
{

	double aux = lista->dados[0];

	for (int i = 0; i < lista->tamanho; i++)
	{
		lista->dados[i] = lista->dados[i + 1];
	}
	lista->tamanho--;
	return aux;
}

void imprimir_lista(Lista *l)
{
	printf("%.2f\n", l->dados[0]);
}

int main(void)
{
	char elemento[8];
	int num_casos;

	scanf("%d", &num_casos);

	Lista *minhaLista = criar_lista();
	while (num_casos > 0)
	{
		while (true)
		{
			scanf("%s", elemento);
			if (elemento[0] == '.')
			{
				break;
			}
			if (isdigit(elemento[0]))
			{
				// É um operando
				double operando = atof(elemento);
				lista_inserir_inicio(minhaLista, operando);
			}
			else
			{
				// É um operador (+, -, * ou /)
				char operador = elemento[0];
				double op1, op2;
				switch (operador)
				{
				case '#':
					op1 = lista_desempilha(minhaLista);
					op2 = lista_desempilha(minhaLista);
					// printf("%.2f\n", op2 + op1);
					lista_inserir_inicio(minhaLista, op2 + op1);
					break;
				case '-':
					op1 = lista_desempilha(minhaLista);
					op2 = lista_desempilha(minhaLista);
					// printf("%.2f\n", op2 - op1);
					lista_inserir_inicio(minhaLista, op2 - op1);
					break;
				case '*':
					op1 = lista_desempilha(minhaLista);
					op2 = lista_desempilha(minhaLista);
					// printf("%.2f\n", op2 * op1);
					lista_inserir_inicio(minhaLista, op2 * op1);
					break;
				case '/':
					op1 = lista_desempilha(minhaLista);
					op2 = lista_desempilha(minhaLista);
					// printf("%.2f\n", op2 / op1);
					lista_inserir_inicio(minhaLista, op2 / op1);
					break;
				}
			}
		}
		// Fim da expressão
		num_casos--;
	imprimir_lista(minhaLista);
	}
	liberar_lista(minhaLista);
}
