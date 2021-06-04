#define torreDeHanoi_h

typedef struct disco Disco;
typedef struct pino Pino;

Pino* criarPino();
Disco* criarDisco(int tam);
Disco* pop(Pino *pino);
void push(Pino *pino, Disco *disco);
void excluirPino(Pino *pino);
