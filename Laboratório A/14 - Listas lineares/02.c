#include <stdio.h>

typedef struct musica {
	char autor[100];
	char titulo[100];
	char arquivo[100];
	int duracao;
} Musica;

typedef struct listaMusicas {
	Musica *dados;
	int tamanho;
	int capacidade;
} ListaMusicas;

// Cria uma nova lista vazia
struct ListaMusicas lista_criar(int capacidade);

// Insere uma música no fim
void lista_inserir_fim(ListaMusicas *lista, Musica novo);

// Verifica se uma música existe na lista; retorna o índice ou -1
int lista_buscar(ListaMusicas *lista, char *artista, char *titulo);

// Le uma nova musica do teclado e retorna um registro para ela
Musica ler_musica(void);

int main(void)
{
	ListaMusicas *base;
	ListaMusicas *playlist;

	return 0;
}
