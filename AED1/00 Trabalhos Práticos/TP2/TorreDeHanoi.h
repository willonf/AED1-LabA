// #ifndef torreDeHanoi_h
#define torreDeHanoi_h

typedef struct pino Pino;
typedef struct disco Disco;

Pino* criarPino();
Disco* criarDisco(int tam);
Disco* pop(Pino *pino);
void push(Pino *pino, Disco *disco);
void excluirPino(Pino *pino);

struct disco {
    // O disco é representado por uma fila
    char tamDisco; // Tamanho do disco
    Disco *next;   // Ponteiro que aponta para o próximo disco
};

//Pilha de discos
struct pino {
    // O pino é representado por uma pilha de discos
    Disco *topo;    // Ponteiro para o topo da pilha
    char numDiscos; //quantidade de discos
};
// #endif