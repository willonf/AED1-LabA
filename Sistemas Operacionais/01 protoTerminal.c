/*
Joao victor brandao de abreu
Alexandre da Fonseca vieira 
Teodorio Ferreira neto
*/ 
#include<stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

char *lerlinha(){
	char p; 
	int x;
	int posicao = 0;
	int tamanho = 1000;
	char *args = malloc(sizeof(char)* tamanho);
	
	while(x){
		p = getchar();
		if(p == EOF || p == '\n'){
			args[posicao] = '\0';
			return args;
		}else{
			args[posicao] = p;
		}
		posicao++; 
		
		if(posicao >= tamanho){
			tamanho = tamanho * 2; 
			args = realloc(args,tamanho);
		}
	}
	
}

void comando_arqv(char** argfinal , char** pip){
	int rc;
	
	rc = fork();
	if(rc < 0){
		printf("fork falhou");
	}else if( rc == 0){
		close(STDOUT_FILENO);
		open(pip[1], O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		execvp(argfinal[0],argfinal);
	    printf("Comando não encontrado\n");
		 exit(1);
		
		
	}else{
		int wt = wait(NULL);
	}
	
}

void comando_arqv_in(char** argfinal , char** pip){
	
	int rc;
	rc = fork();
	
	if(rc < 0){
		printf("fork falhou");
	}else if( rc == 0){
		close(STDIN_FILENO);
 		open(pip[1], O_RDONLY);
		
		execvp(argfinal[0], argfinal);
	    printf("Comando não encontrado\n");
		 exit(1);
		
	}else{
		int wt = wait(NULL);
	}
	
}


// separa a linha em comandos 
char** separalinha(char* linha){
	int tamanho = 100;
	int i = 0;
	char *args2  = malloc(tamanho * sizeof(char*));
	char **argfinal = malloc(tamanho * sizeof(char*));
	char modificacoes[4] = " \n";
	
	args2 = strtok(linha,modificacoes);	
	while(args2 != NULL){
		argfinal[i] = args2;
		i++;
			
		if(i >= tamanho){
			tamanho = tamanho*2;
			argfinal = realloc(argfinal , tamanho *sizeof(char));
		}
		args2 = strtok(NULL,modificacoes);
	}
	
	argfinal[i] = NULL;
	
	return argfinal;
}




//3. identifica se é pipe ou não 
int separapipe(char* linha , char** pi){
	int i  = 4;
	for(i=0 ; i<2 ; i++){
		pi[i] = strsep(&linha , "|");
	}
	
	if(pi[1] == NULL){
		i=0;
		return i;//não é pipe
	}else{
		return 1;//é pipe
	}
}

int separamaior(char* linha , char** pi){
	int i  = 4;
	for(i=0 ; i<2 ; i++){
		pi[i] = strsep(&linha , ">");
		
	}
	
	if(pi[1] == NULL){
		i=0;
		return i;//não é maior
	}else{
		return 2;//é maior
	}
}
int separamenor(char* linha , char** pi){
	int i  = 4;
	for(i=0 ; i<2 ; i++){
		pi[i] = strsep(&linha , "<");
		
	}
	
	if(pi[1] == NULL){
		i=0;
		return i;//não é menor
	}else{
		return 3;//é menor
	}
}



char *removeespaco(char *str)
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



void comando(char ** args){

	//printf("hello world (pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {// fork falhou
	    fprintf(stderr, "fork falhou\n");
	    exit(1);
	} else if (rc == 0) { // filho
	   
	    execvp(args[0], args); // roda o comando		
		 int i = strlen(args[0]);
		 int z = i*2;
		 char* ponto = ".\\";
		 char* resul = malloc(strlen(ponto + strlen(args[0]) + 1));
		 char** final = malloc(strlen(ponto) + strlen(args[0] + 1));
		
		 if(fork()==0){
			 strcpy(resul ,ponto);
			 strcat(resul,args[0]);
		 }else{
			 wait(NULL);
		 } 
		if(fork()== 0){
			final = separalinha(resul);
		}
		 execvp(final[0],final);
	     printf("Comando não encontrado\n");
		 exit(1);
	} else {// Pai vem por aqui
		int a =0;
		while(args[a+2] != NULL){
			a++;
		}
		if( strcmp(args[a], "&") != 0){
	    	int wc = wait(NULL);
		}else{
			
		}
	}
}

void comandopipe(char** argfinal , char** pip){

	int piped[2];
	pipe(piped);
	int rc = fork();
	int rc2;

	if ( rc == 0){
		
		rc2 = fork();
		if(rc2 == 0){
			dup2(piped[1], STDOUT_FILENO);
			close(piped[0]);
			close(piped[1]);
			execvp(argfinal[0], argfinal); 

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
int main(){


	int x = 1; 
	int i = 0;
	char* cd[1];
	cd[0] = "cd";
	int comp = 1 ;
	int tamanho = 100;
	char* pi[2]; // args
	int identifica = 0;
	char *args = malloc(tamanho * sizeof(char*)); // command
	char **pipe = malloc(tamanho * sizeof(char*));
	char **argfinal = malloc(tamanho * sizeof(char*)); // argList

	int pipes;
	int id,id2;
	char dir[1024];
	while(x){
		// ler uma linha 
		getcwd(dir, sizeof(dir));
    	printf("%s", dir);
		printf(">");
		args = lerlinha();	// LINHA LENDO 
			// tentando criar um vetor de vetores com tokens 
		if(args[0] != '\0'){
		// verificar se é pipe e separa. 		
			identifica = separapipe(args , pi ); // verificando se tem | na linha 
			if(identifica != 1 ){
				id= separamaior(args , pi);
			}
			if(identifica != 1 ){
				if(id != 2){
					id2 = separamenor(args,pi);
				}
			}
			
			if(id2 == 3){ // tem <
				argfinal = separalinha(pi[0]);
				pi[1] = removeespaco(pi[1]);
			}
			else if(id == 2){ // tem > 
				argfinal = separalinha(pi[0]);
				pi[1] = removeespaco(pi[1]);
				
			}else if(identifica == 1 ){ // tem || 
				argfinal = separalinha(pi[0]);
				pipe = separalinha(pi[1]);
				
			}else{
				argfinal = separalinha(args);

			}

			//salva o identifica pipe se for 1 é pipe se for 0 é normal;
			
			if(identifica== 1){
				comandopipe(argfinal, pipe);

			}else if(id == 2){ // funcao de gerar arquivo

				comando_arqv(argfinal , pi); // sendo pipe o nome do arquivo; 
				
			}else if(id2 == 3){
				//printf("sou menor que\n"); // criar a funcao de receber um arquivo;
				comando_arqv_in(argfinal,pi);	

			}else {
				comp = strcmp(argfinal[0],cd[0]); // verifica se o comando dado é cd 
				if(comp == 0){
					chdir(argfinal[1]); 
				}else{
					comando(argfinal); // executa o comando sem pipe
				}
			}
			free(args);
			free(argfinal);
		}
			
	}
	
	return 0;
		
}

