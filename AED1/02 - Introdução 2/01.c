#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int main(void){

	 unsigned int semente;
	 int escolha, soma, computador;
	 unsigned int numero_usuario;

	 scanf("%d", &escolha);
	 scanf("%d", &numero_usuario);
	 scanf("%d", &semente);
	 srand(semente);
	 computador = rand() % 10;
	 soma = computador + numero_usuario;
	 if (soma % 2 == 0 && escolha == 0){
		  printf("Computador: %d. Voce (usuario) ganhou!", computador);
	 } else if (soma % 2 != 0 && escolha == 1){
		  printf("Computador: %d. Voce (usuario) ganhou!", computador);
	 } else {
		  printf("Computador: %d. Eu (computador) ganhei!", computador);

	 }
	 return 0;
}