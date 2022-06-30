/*
Joao victor brandao de abreu
Alexandre da Fonseca vieira
Teodorio Ferreira neto
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>

char *currentPath()
{
	char currentPath[1024]; // Variável que recebera o path atual
	return getcwd(currentPath, sizeof(currentPath));
}

char *readLine()
{
	char line; // Caracteres digitados pelo usuário
	int index = 0;
	int length = 1024;
	char *args = malloc(sizeof(char) * length); // Vetor que armazenará os caracteres

	while (true)
	{
		line = getchar();
		if (line == EOF || line == '\n')
		{						// Se o comando for apenas um enter ou fim de arquivo
			args[index] = '\0'; // O "argumento atual" recebe um final de string e retorna
			return args;
		}
		else
		{
			args[index] = line; // Se não, o "argumento atual" recebe o que foi digitado
		}
		index++; // Incremento da posição para receber o próximo argumento

		// Aumento da memória caso a lista de argumentos seja muito grande
		if (index >= length)
		{
			length = length * 2;
			args = realloc(args, length);
		}
	}
}

void finish()
{
	printf("Finishing...");
	exit(0);
}

void outputRedirect(char **argfinal, char **pip)
{
	int rc;

	rc = fork();
	if (rc < 0)
	{
		printf("fork falhou");
	}
	else if (rc == 0)
	{
		close(STDOUT_FILENO);
		open(pip[1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		execvp(argfinal[0], argfinal);
		printf("Comando não encontrado!\n");
		exit(1);
	}
	else
	{
		int wt = wait(NULL);
	}
}

void inputRedirect(char **argfinal, char **pip)
{

	int rc;
	rc = fork();

	if (rc < 0)
	{
		printf("fork falhou");
	}
	else if (rc == 0)
	{
		close(STDIN_FILENO);
		open(pip[1], O_RDONLY);

		execvp(argfinal[0], argfinal);
		printf("Comando não encontrado!\n");
		exit(1);
	}
	else
	{
		int wt = wait(NULL);
	}
}

char **splitLine(char *linha)
{
	int length = 100;
	int i = 0;
	char *args2 = malloc(length * sizeof(char *));
	char **argfinal = malloc(length * sizeof(char *));
	char modificacoes[4] = " \n";

	args2 = strtok(linha, modificacoes);
	while (args2 != NULL)
	{
		argfinal[i] = args2;
		i++;

		if (i >= length)
		{
			length = length * 2;
			argfinal = realloc(argfinal, length * sizeof(char));
		}
		args2 = strtok(NULL, modificacoes);
	}

	argfinal[i] = NULL;

	return argfinal;
}

// 3. identifica se é pipe ou não
bool verifyPipe(char *linha, char **pi)
{
	for (int i = 0; i < 2; i++)
	{
		pi[i] = strsep(&linha, "|");
	}

	if (pi[1] == NULL)
	{
		return false; // não é pipe
	}
	else
	{
		return true; //é pipe
	}
}

bool splitOutputRedirect(char *line, char **pi)
{
	for (int i = 0; i < 2; i++)
	{
		pi[i] = strsep(&line, ">");
	}

	if (pi[1] == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool splitInputRedirect(char *line, char **pi)
{
	for (int i = 0; i < 2; i++)
	{
		pi[i] = strsep(&line, "<");
	}

	if (pi[1] == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

char *removeBlank(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	return str;
}

void execute(char **args)
{

	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "fork falhou\n");
		exit(1);
	}
	else if (rc == 0)
	{

		execvp(args[0], args); // Executa o comando
		int i = strlen(args[0]);
		int z = i * 2;
		char *ponto = ".\\";
		char *resul = malloc(strlen(ponto + strlen(args[0]) + 1));
		char **final = malloc(strlen(ponto) + strlen(args[0] + 1));

		if (fork() == 0)
		{
			strcpy(resul, ponto);
			strcat(resul, args[0]);
		}
		else
		{
			wait(NULL);
		}
		if (fork() == 0)
		{
			final = splitLine(resul);
		}
		execvp(final[0], final);
		printf("Comando não encontrado!\n");
		exit(1);
	}
	else
	{
		int a = 0;
		while (args[a + 2] != NULL)
		{
			a++;
		}
		if (strcmp(args[a], "&") != 0)
		{
			int wc = wait(NULL);
		}
	}
}

void executePipeCommand(char **argfinal, char **pip)
{

	int piped[2];
	pipe(piped);
	int rc = fork();
	int rc2;

	if (rc == 0)
	{

		rc2 = fork();
		if (rc2 == 0)
		{
			dup2(piped[1], STDOUT_FILENO);
			close(piped[0]);
			close(piped[1]);
			execvp(argfinal[0], argfinal);
		}
		wait(NULL);
		dup2(piped[0], STDIN_FILENO);
		close(piped[1]);
		close(piped[0]);
		execvp(pip[0], pip);

		printf("Comando não encontrado!\n");
		exit(1);
	}
	close(piped[1]);
	close(piped[0]);
	wait(NULL);
}

void fat()
{
	int number;
	int fat = 1;
	printf("Digite um número inteiro:\n");
	scanf("%d", &number);
	if(number > 1){
		for(int i = 2; i <= number; i++) {
			fat *= i;
		}
	} else if(number < 0) {
		printf("Nao é possível calcular o fatorial de números negativos.");
	}
	printf("%d! = %d", number, fat);
	
}

int main()
{

	char *cd[1];
	cd[0] = "cd";
	char *fatorial[1];
	fatorial[0] = "fat";
	char *exit[1];
	exit[0] = "exit";

	int comp = 1;
	int length = 128;
	char *pi[2]; // args
	bool hasPipe;
	char *args = malloc(length * sizeof(char *));
	char **pipe = malloc(length * sizeof(char *));
	char **argfinal = malloc(length * sizeof(char *));

	int pipes;
	int hasOutputRedirect, hasInputRedirect;
	char dir[1024];
	while (true)
	{
		printf("\n%s> ", currentPath());
		args = readLine();
		if (args[0] != '\0')
		{

			hasPipe = verifyPipe(args, pi); // verificando se tem | na linha
			if (!hasPipe)
			{
				hasOutputRedirect = splitOutputRedirect(args, pi);
				if (!hasOutputRedirect)
				{
					hasInputRedirect = splitInputRedirect(args, pi);
				}
			}

			if (hasInputRedirect)
			{
				argfinal = splitLine(pi[0]);
				pi[1] = removeBlank(pi[1]);
			}
			else if (hasOutputRedirect)
			{
				argfinal = splitLine(pi[0]);
				pi[1] = removeBlank(pi[1]);
			}
			else if (hasPipe)
			{
				argfinal = splitLine(pi[0]);
				pipe = splitLine(pi[1]);
			}
			else
			{
				argfinal = splitLine(args);
			}

			if (hasPipe)
			{
				executePipeCommand(argfinal, pipe);
			}
			else if (hasOutputRedirect)
			{ // funcao de gerar arquivo

				outputRedirect(argfinal, pi);
			}
			else if (hasInputRedirect)
			{
				inputRedirect(argfinal, pi);
			}
			else
			{
				comp = strcmp(argfinal[0], cd[0]); // verifica se o comando dado é cd
				if (comp == 0)
				{
					chdir(argfinal[1]);
				}
				else if (strcmp(argfinal[0], fatorial[0]) == 0)
				{
					fat();
				}
				else if (strcmp(argfinal[0], exit[0]) == 0)
				{
					finish();
				}
				else
				{
					execute(argfinal); // executa o comando sem pipe
				}
			}
			free(args);
			free(argfinal);
		}
	}

	return 0;
}
