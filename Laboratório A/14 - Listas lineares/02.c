#include <stdio.h>
#include <string.h>
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

void liberar_memoria(ListaMusicas *lista);

int main(void)
{
	ListaMusicas *base;
	ListaMusicas *playlist;
	ListaMusicas *result = lista_criar(1);
	Musica aux;
	int N, Q, pos, maxTempo = 0, auxTempo = 0;

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

	for (int i = 0; i < playlist->capacidade; i++)
	{
		pos = lista_buscar(base, playlist->dados[i].autor, playlist->dados[i].titulo);
		auxTempo = maxTempo + base->dados[pos].duracao;
		if ((pos >= 0) && (auxTempo <= 3600))
		{
			maxTempo += base->dados[pos].duracao;
			lista_inserir_fim(result, base->dados[pos]);
		}
	}
	int minuto = maxTempo / 60;
	int segundo = maxTempo % 60;
	printf("Lista gerada com %d musicas e duracao %02d:%02d\n", result->tamanho, minuto, segundo);
	for (int i = 0; i < result->tamanho; i++)
	{
		printf("%s\n", result->dados[i].arquivo);
	}

	liberar_memoria(base);
	liberar_memoria(playlist);
	liberar_memoria(result);

	return 0;
}

void liberar_memoria(ListaMusicas *lista)
{
	free(lista->dados);
	free(lista);
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
	if (lista->tamanho > lista->capacidade)
	{
		lista->capacidade++;
		lista->dados = realloc(lista->dados, (lista->capacidade) * sizeof(int));
	}
	last = lista->tamanho - 1;
	lista->dados[last] = novo;
}

int lista_buscar(ListaMusicas *lista, char *artista, char *titulo)
{
	int condition1, condition2;
	for (int i = 0; i < lista->capacidade; i++)
	{
		condition1 = strcmp(lista->dados[i].autor, artista);
		condition2 = strcmp(lista->dados[i].titulo, titulo);
		if (condition1 == 0 && condition2 == 0)
		{
			return i;
		}
	}
	return -1;
}
