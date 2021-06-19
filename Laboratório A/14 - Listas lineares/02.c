#include <stdio.h>

struct Musica {
	char autor[100];
	char titulo[100];
	char arquivo[100];
	int duracao;
};

struct ListaMusicas {
	struct Musica *dados;
	int tamanho;
	int capacidade;
};

// Cria uma nova lista vazia
struct ListaMusicas lista_criar(int capacidade);

// Insere uma música no fim
void lista_inserir_fim(struct ListaMusicas *lista, struct Musica novo);

// Verifica se uma música existe na lista; retorna o índice ou -1
int lista_buscar(struct ListaMusicas *lista, char *artista, char *titulo);

// Le uma nova musica do teclado e retorna um registro para ela
struct Musica ler_musica(void);

int main(void)
{
	struct ListaMusicas *base;
	struct ListaMusicas *playlist;
	

	return 0;
}
