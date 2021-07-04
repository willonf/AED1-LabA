#include <stdio.h>
#include <stdlib.h>

/* Sugestao de estrutura de dados para guardar a lista de programa
 * e os programas. Voce pode alterar essa estrutura como quiser,
 * mas deve implementar uma lista circular encadeada.
 */
typedef struct programa Programa;
struct programa {
    char nome[81];
    int tempo_restante;
    Programa *anterior;
    Programa *sucessor;
};

typedef struct lista Lista;
struct lista {
    Programa *inicio;
    Programa *fim;
};


/* Sugestao de funcao para criar uma lista. Voce pode
 * alterar, usar ou remover esta funcao.
 */
Lista *criar_lista(void)
{
	Lista *nova = malloc(sizeof *nova);
	nova->inicio = nova->fim = NULL;
	return nova;
}


/* Sugestao de funcao para ler a descricao de um programa e
 * retornar um novo no' para ele. Voce pode usar, modificar
 * ou remover esta funcao.
 */
Programa *ler_programa(void)
{
	Programa *novo = malloc(sizeof *novo);
	
	// Leitura do nome do programa
	scanf("%80s", novo->nome);
	
	// Leitura do tempo total de execucao do programa
	scanf("%d", &novo->tempo_restante);
	
	// Atribui um valor inicial para o ponteiro prox
	novo->sucessor = NULL;
	
	return novo;
}

void main() {
    Lista *listaProgramas = criar_lista();
    int Q, N;

    scanf("%d%d", &Q, &N);

    listaProgramas->inicio = ler_programa();
    listaProgramas->fim = listaProgramas->inicio;

    printf
}