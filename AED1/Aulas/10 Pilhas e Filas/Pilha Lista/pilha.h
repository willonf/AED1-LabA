typedef	struct pilhaNo PilhaNo;
typedef	struct pilha Pilha;
PilhaNo *cria_pilha(void);
void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha *p);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
float pilha_libera(Pilha *p);
float pilha_imprime(Pilha *p);