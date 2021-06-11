#define torreDeHanoi_h

Pino *criarPino();
Disco *criarDisco(int tam);
Disco *pop(Pino *pino);
void push(Pino *pino, Disco *disco);
void excluirPino(Pino *pino);

typedef struct disco Disco;
typedef struct pino Pino;
struct disco
{
    char tamDisco;
    Disco *next;
};

struct pino
{
    Disco *topo;
    char numDiscos;
};