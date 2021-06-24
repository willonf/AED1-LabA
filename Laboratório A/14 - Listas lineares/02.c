#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct musica
{
	char autor[100];
	char titulo[100];
	char arquivo[100];
	int duracao;
} Musica;

typedef struct listaMusicas
{
	Musica *dados;
	int tamanho;
	int capacidade;
} ListaMusicas;

// Cria uma nova lista vazia
ListaMusicas *lista_criar(int capacidade);

// Insere uma música no fim
void lista_inserir_fim(ListaMusicas *lista, Musica novo);

// Verifica se uma música existe na lista; retorna o índice ou -1
int lista_buscar(ListaMusicas *lista, char *artista, char *titulo);

// Le uma nova musica do teclado e retorna um registro para ela
Musica ler_musica(bool ehBase);

int main(void)
{
	ListaMusicas *base;
	ListaMusicas *playlist;
	Musica aux;
	int N, Q;

	// Lendo a base de "dados"
	scanf("%d", &N);
	base = lista_criar(N);
	for (int i = 0; i < base->capacidade; i++)
	{
		aux = ler_musica(true);
		lista_inserir_fim(base, aux);
	}
	

	// Montando a playlist
	scanf("%d", &Q);
	playlist = lista_criar(Q);
	for (int i = 0; i < playlist->capacidade; i++)
	{
		aux = ler_musica(false);
		lista_inserir_fim(playlist, aux);
	}

	

	return 0;
}

ListaMusicas *lista_criar(int capacidade)
{
	ListaMusicas *lista = malloc(sizeof(ListaMusicas));
	lista->dados = malloc(capacidade * sizeof(Musica));
	lista->tamanho = 0;
	lista->capacidade = capacidade;
	return lista;
}

Musica ler_musica(bool ehBase)
{
	Musica musica;
	scanf("%s", musica.autor);
	scanf("%s", musica.titulo);
	if (ehBase)
	{
		scanf("%s", musica.arquivo);
		scanf("%d", &musica.duracao);
	}
	return musica;
}

void lista_inserir_fim(ListaMusicas *lista, Musica novo)
{
		
	int last;
    lista->tamanho++;
    if(lista->tamanho > lista->capacidade){
        lista->capacidade++;
        lista->dados = realloc(lista->dados, (lista->capacidade) * sizeof(int));
    }
    last = lista->tamanho - 1;
    lista->dados[last] = novo;
}
