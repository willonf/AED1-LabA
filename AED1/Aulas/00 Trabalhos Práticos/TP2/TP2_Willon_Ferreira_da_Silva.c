#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
#include "TorreDeHanoi.h"

int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino);
void imprimir(Pino **pinos, int numPinos, int numDiscos);
Pino **criarPinos(int n);
void jogar();

int main()
{

    int m, n;
    int p1, p2;
    int pino = 0;

    // Leitura da quantidade n de pinos
    while (true)
    {
        printf("Insira a quantidade de pinos: [3..5] ");
        scanf("%d", &n);
        if (n < 3 || n > 5)
        {
            printf("Entrada invalida\n");
            continue;
        }
        else
        {
            break;
        }
    }

    // Leitura da quantidade m de discos
    while (true)
    {
        printf("Insira a quantidade de discos: [3..5] ");
        scanf("%d", &m);
        if (m < 3 || m > 5)
        {
            printf("Entrada invalida\n");
            continue;
        }
        else
        {
            break;
        }
    }

    // Criação do vetor de pinos
    Pino **vetorPinos = criarPinos(n);

    // Inserção dos discos no primeiro pino
    int tam = m;
    for (int i = 0; i < m; i++)
    {
        Disco *disco = criarDisco(tam);
        push(vetorPinos[0], disco);
        tam--;
    }

    // Início do jogo (chamada da função Jogar)
    jogar(vetorPinos, n, m);
}

Pino **criarPinos(int n)
{
    Pino **novoPino = (Pino **)malloc(n * sizeof(Pino *));
    for (int i = 0; i < n; i++)
    {
        novoPino[i] = criarPino();
    }
    return novoPino;
}

int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino)
{
    //pop do topo origem + push no topo destino
    // Validar tamanho do disco no topo da origem e tam do disco do destino
    // Validar quantidade de discos no disco do destino

    Disco *aux;
    bool condicao = pinos[pinoDestino]->topo->tamDisco > pinos[pinoOrigem]->topo->tamDisco;
    if (condicao)
    {
        return 0;
    }
    aux = pop(pinos[pinoOrigem]);
    push(pinos[pinoDestino], aux);
    return 1;
}

int pegaTamDisco(Pino *pino, int numPinos)
{
    int tamDisco = 0;

    for (Disco *aux = pino->topo; aux != NULL; aux = aux->next)
    {
        tamDisco = aux->tamDisco;
    }

    return tamDisco;
}

void imprimir(Pino **pinos, int numPinos, int numDiscos)
{
    // Deverá receber como parâmetro um vetor de Pino (pinos),
    // a quantidade de pinos (numPinos) e
    // a quantidade de discos (numDiscos)
    // e imprimir todos os pinos e discos

    int pinoAtual = 0;
    int tamDisco;
    int qtdeDiscos;
    int auxDiscos;
    int espacos = numDiscos + 1, auxEspacos = espacos;
    int k = 0;

    // Escrita dos pinos (|)
    for (int i = 0; i < numPinos; i++)
    {
        qtdeDiscos = pinos[i]->numDiscos;
        tamDisco = pegaTamDisco(pinos[i], numPinos);
        auxDiscos = tamDisco;

        // Escrita dos discos (_)
        for (int j = 0; j < numDiscos; j++)
        {

            if (qtdeDiscos > 0)
            {
                while (tamDisco)
                {
                    printf("%c", '_');
                    tamDisco--;
                }
                tamDisco = auxDiscos;
                printf("|");
                while (tamDisco)
                {
                    printf("%c", '_');
                    tamDisco--;
                }
                printf("\n");
            }
            else
            {
                printf("%*c\n", espacos, '|');
            }

            espacos--;
            tamDisco = auxDiscos;
            auxDiscos++;
            espacos = auxEspacos;
        }

        printf("\n\n");
    }
}

void jogar(Pino **pinos, int numPinos, int numDiscos)
{
    int pinoOrigem, pinoDestino;
    int jogadas = 0;
    int cond;
    while (true)
    {
        imprimir(pinos, numPinos, numDiscos);

        while (true)
        {
            printf("Insira os pinos de origem e de destino: ");
            scanf("%d%d", &pinoOrigem, &pinoDestino);
            cond = moverDisco(pinos, pinoOrigem-1, pinoDestino-1);
            if (cond)
            {
                jogadas++;
                break;
            }
            else
            {
                printf("Movimento invalido");
            }
        }
        printf("\n");
        for (int i = 0; i < numPinos; i++)
        {
            if (pinos[i]->numDiscos == 3)
            {
                printf("PARABENS VOCE CONSEGUIU\n");
                printf("TOTAL DE JOGADAS: %d", jogadas);
                break;
            }
        }
    }
}
