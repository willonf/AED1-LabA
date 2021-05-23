#include <stdio.h>
#include <string.h>

#define MAX_NOMES 10
#define MAX_COMPRIMENTO 80

int verifica_login(char nome[], int num_nomes, char nomes_autorizados[][MAX_COMPRIMENTO + 1])
{
	// se "nome" pertence a lista de "nomes_autorizados", entao
	// a funcao deve retornar 1. Caso contrario, retorne zero
	int i;
	for (i = 0; i < num_nomes; i++) {
		if(!strcmp(nome, nomes_autorizados[i])) {
            return 1;
        }
	}
	
	// Se chegou ate aqui, eh porque nao teve return, entao
	// o nome nao esta autorizado
	return 0;
}

int main(void)
{
	char nomes_autorizados[MAX_NOMES][MAX_COMPRIMENTO + 1] = {
		"Asdefoghil",
		"Qwerty",
		"Zaxck",
		"Poiuye",
		"Likhigfer",
		"Minebvazx"
	};
	char nome[MAX_COMPRIMENTO + 1];
	
	scanf("%s", nome);
	if (verifica_login(nome, 6, nomes_autorizados)) {
		printf("Acesso permitido para %s!\n", nome);
	}
	else {
		printf("Acesso negado para %s!\n", nome);
	}
}