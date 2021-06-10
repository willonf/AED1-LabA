#define torreDeHanoi_h

typedef struct pino Pino;
typedef struct disco Disco;

Pino *criarPino();
Disco *criarDisco(int tam);
Disco *pop(Pino *pino);
void push(Pino *pino, Disco *disco);
void excluirPino(Pino *pino);

struct disco
{
    char tamDisco;
    Disco *next;
};

//Pilha de discos
struct pino
{
    Disco *topo;
    char numDiscos;
};