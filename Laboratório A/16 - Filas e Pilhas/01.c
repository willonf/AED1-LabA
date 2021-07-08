#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila Fila;
typedef struct filaNo FilaNo;

Fila *fila_cria(void);
void fila_insere(Fila *f, int tempo);
int fila_retira(Fila *f);
bool fila_vazia(Fila *f);
void fila_libera(Fila *f);
void fila_imprime(Fila *f);

struct filaNo
{
    int tempo;
    FilaNo *prox;
};

struct fila
{
    FilaNo *inicio;
    FilaNo *fim;
};

Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void fila_insere(Fila *f, int tempo)
{
    FilaNo *new = malloc(sizeof(FilaNo));
    new->tempo = tempo;
    new->prox = NULL;
    if (f->fim != NULL)
    {                       // A fila não está vazia
        f->fim->prox = new; // O último nó aponta para o novo nó
    }
    else
    {                    // A fila está vazia
        f->inicio = new; // O início da fila aponta para o novo nó
    }
    f->fim = new; // O fim da fila aponta para o novo nó
}

int fila_retira(Fila *f)
{
    FilaNo *aux = f->inicio;
    int v = aux->tempo;
    f->inicio = aux->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    free(aux);
    return v;
}

bool fila_vazia(Fila *f)
{
    return (f->inicio == NULL);
}

void fila_libera(Fila *f)
{
    FilaNo *aux = f->inicio;
    while (aux != NULL)
    {
        FilaNo *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(f);
}

void fila_imprime(Fila *f)
{
    FilaNo *aux;

    for (aux = f->inicio; aux != NULL; aux = aux->prox)
    {
        printf("%d\n", aux->tempo);
    }
}

int main()
{
    Fila *filaAlunos = fila_cria();
    int tempoSessao, tempo, tempoTotal = 0;

    scanf("%d", &tempoSessao);
    // tempoSessao = 20;
    while (scanf("%d", &tempo) != EOF)
    {
        fila_insere(filaAlunos, tempo);
    }
    // fila_insere(filaAlunos, 10);
    // fila_insere(filaAlunos, 25);

    FilaNo *aux = filaAlunos->inicio;
    while (true)
    {
        if(fila_vazia(filaAlunos)){
            break;
        }
        int tmp;
        if (aux->tempo > tempoSessao)
        {
            tmp = fila_retira(filaAlunos);
            tempoTotal += tempoSessao;
            tmp = tmp - tempoSessao;
            fila_insere(filaAlunos, tmp);
        }
        else if (aux->tempo <= tempoSessao)
        {
            if (filaAlunos->inicio == filaAlunos->fim)
            {
                tmp = fila_retira(filaAlunos);
                tempoTotal += (tmp);
            }else {
               tmp = fila_retira(filaAlunos);
                tempoTotal += tempoSessao; 
            }
        }
          aux = filaAlunos->inicio;
    }
    printf("%d", tempoTotal);
    fila_libera(filaAlunos);
}
