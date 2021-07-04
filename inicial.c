#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char elemento[8];
	int num_casos;

	scanf("%d", &num_casos);

	while (num_casos > 0) {
		// Lê o próximo elemento
		scanf("%s", elemento);

		while (elemento[0] != '.') {
			if (isdigit(elemento[0])) {
				double operando = atof(elemento);

				// É um operando
			}
			else {
				char operador = elemento[0];

				// É um operador (+, -, * ou /)
			}

			// Lê o próximo elemento (que pode ser um ponto final)
			scanf("%s", elemento);
		}

		// Fim da expressão
		num_casos--;
	}
}
