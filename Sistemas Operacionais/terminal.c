/*
1) LS, CD, PWD
2) CAT, MORE, HEAD, AFINS (???)
3) Nome de um programa digitado pelo usuário e ficar parado até esse programa executar
4) Modificadores de processo: >, <, | e &
*/

#include<stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>

char* readLine(){
    char line; // Comando a ser digitado pelo usuário
    int length = 1024; // Tamanho do vetor que vai alocar a string acima
    int index = 0; // Primeiro index do comando. Ex.: ls -ls ('ls' está no index 0)
    char *args = malloc(sizeof(char) * length); // Alocação de memória para o vetor

    while(true) {
        line = getchar();  // Leitura do comando

        if(line == EOF || line == '\n'){ // Se o comando for apenas um enter ou fim de arquivo
            args[index] = '\0';  // O "argumento atual" recebe um final de string
            return args; // Retorno dos args
        } else {
            args[index] = line; // Se não, o "argumento atual" recebe o comando
        }
        index++; // Incremento da posição para receber o próximo argumento

        // Aumento da memória caso a lista de argumentos seja muito grande
        if (index >= length) {
            length *= 2;
            args = realloc(args, length);
        }
    }


}

void finish(){
    printf("Finishing...");
    exit(0);
}

bool verifyPipe(char *line, char** args){

    for(int i = 0; i < 2; i++){
        // Separa a string com base no caractere informado. Ex.: "t1 | t2" -> "t1 ", "t2 "
        args[i] = strsep(&line, "|");
    }

    if(args[1] == NULL){
        return false; // não possui pipe
    }
    return true; // possui pipe

}

// Verifica se possui o redirecionador de saída ">"
bool splitOutputRedirect(char* line, char** args) {
    for (int i = 0; i < 2; i++){
        args[i] = strsep(&line, ">"); 
    }

    if (args[1] == NULL) {
        return false;
    }
    return true;
}

bool splitInputRedirect(char* line, char** args) {
    for (int i = 0; i < 2; i++){
        args[i] = strsep(&line, "<"); 
    }

    if (args[1] == NULL) {
        return false;
    }
    return true;
}


// Separar a linha em seus diversos comandos
char **splitLine(char *line) {
    int length = 128;
    int index = 0;
    char *word  = malloc(length * sizeof(char*));
	char **list = malloc(length * sizeof(char*));
    char mods[4] = " \n";

    word = strtok(line, mods); // Vai separar por " \n"

    while(word != NULL) {
        list[index] = word;
        index++;

        if (index >= length) {
            length *= 2;
            list = realloc(list, length * sizeof(char));
        }
        word = strtok(NULL, mods);
    }

    list[index] = NULL;

    return list;
}


char* splitBlank(char* str){
    int i = 0, j = 0;

    while(str[i]) {
        if(str[i] != ' '){
            str[j++] = str[i];
            i++;
        }

        str[j] = '\0';
        return str;
    }
}

void executePipeCommand(char** argList, char** pip) {
    int piped[2];
    pipe(piped);
    int rc;
    rc = fork();
    int rc2;

    if(rc < 0){
        printf("Erro no fork");
    } else if (rc == 0) {
        rc2 = fork();
        		if(rc2 == 0){
			dup2(piped[1], STDOUT_FILENO);
			close(piped[0]);
			close(piped[1]);
			execvp(argList[0], argList); 

		}
		wait(NULL);
		dup2(piped[0], STDIN_FILENO);
		close(piped[1]);
		close(piped[0]);
		execvp(pip[0],pip);
		
		printf("Comando não encontrado\n");
		exit(1);
    }
    close(piped[1]);
	close(piped[0]);
	wait(NULL);
}

void outputRedirect(char** argList, char** pip) {
    int rc;

    rc = fork();
    if(rc < 0){
        printf("Erro no fork");
        exit(1);
    } else if (rc == 0) {
        close(STDOUT_FILENO);
        open(pip[1], O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

        execvp(argList[0], argList);
        printf("Comando não encontrado\n");
        exit(1);
    } else {
        int wt = wait(NULL);
    }

}

void inputRedirect(char** argList, char** pipe) {
    int rc = fork();
    if(rc < 0){
        printf("Erro no fork");
        exit(1);
    } else if (rc == 0) {
        close(STDIN_FILENO);
        open(pipe[1], O_RDONLY);

        execvp(argList[0], argList);
        printf("Comando não encontrado\n");
        exit(1);
    } else {
        int wt = wait(NULL);
    }

}

void execute(char** argList) {

    int rc;

    rc = fork();

    if (rc < 0){
        printf("Erro no fork");
        exit(1);
    } else if (rc == 0) {
        execvp(argList[0], argList);
        int i = strlen(argList[0]);
        int z = i * 2;
        char* point = ".\\";
        char* result = malloc(strlen(point + strlen(argList[0]) + 1));
        char** final = malloc(strlen(point) + strlen(argList[0] + 1));

        if(fork()==0){
			 strcpy(result, point);
			 strcat(result, argList[0]);
        }else{
			 wait(NULL);
        } 
		if(fork()== 0){
			final = splitLine(result);
		}
        execvp(final[0],final);
        printf("Comando não encontrado\n");
        exit(1);
    } else {
        int a =0;
		while(argList[a+2] != NULL){
			a++;
		}
		if( strcmp(argList[a], "&") != 0){
	    	int wc = wait(NULL);
		}
    }
}



int main(){

    char currentPath[1024]; // Variável que recebera o path atual

    int length = 128;
	char *command = malloc(length * sizeof(char*));
    char **pipe = malloc(length * sizeof(char*));
    char **argList = malloc(length * sizeof(char*));

    bool hasPipe = false, hasOutputRedirect = false, hasInputRedirect = false;
    char* args[2];
    char* cd[1];

    int comp = 1;

    while(true) {
        printf("%s>", getcwd(currentPath, sizeof(currentPath)));
        command = readLine();

        if (command[0] != '\0'){
            hasPipe = verifyPipe(command, args);

            if (!hasPipe) { // Se não tem pipe
                hasOutputRedirect = splitOutputRedirect(command, args);
                if(!hasOutputRedirect) {
                    hasInputRedirect = splitInputRedirect(command, args);
                }
            }

            if(hasPipe) {
                argList = splitLine(args[0]);
                args[1] = splitBlank(args[1]);
            } else if(hasOutputRedirect) {
                argList = splitLine(args[0]);
                args[1] = splitBlank(args[1]);
            } else if(hasInputRedirect) {
                argList = splitLine(args[0]);
                args[1] = splitBlank(args[1]);
            } else {
                argList = splitLine(command);
            }

            if (hasPipe){
                executePipeCommand(argList, pipe);
            }
            else if(hasOutputRedirect){
                outputRedirect(argList, args);

            } else if(hasInputRedirect) {
                inputRedirect(argList, args);
            }
            else {
                comp = strcmp(argList[0], cd[0]); // Verifica se o comando é "cd"
				if(comp == 0){
					chdir(argList[1]); 
				}else{
					execute(argList); // executa o comando sem pipe
				}
            }

        }
        // Libera memória do comando para receber a próxima leitura
        free(command);
        free(argList);
    }
	return 0;
		
}
