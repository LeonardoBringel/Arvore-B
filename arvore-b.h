#ifndef _ARVOREB_H_
#define _ARVOREB_H_

#define DEBUG 1

struct stack {

	struct stack* ant;

	struct stack* menorq_1;
	int chave1;
	struct stack* menorq_2;
	int chave2;
	struct stack* menorq_3;
	int chave3;
	struct stack* maiorq_3;
};

typedef struct stack STACK;

STACK* novo_stack(int valor);
int is_folha(STACK* stack);
STACK* aloca_chave(STACK* stack, int valor);

int is_overflow(STACK* stack);

STACK* split_menor(STACK* stack);
STACK* split_maior(STACK* stack);

STACK* overflow_topo(STACK* stack);
STACK* overflow_intermediario(STACK* stack);
STACK* overflow(STACK* stack);

void imprime_valor(int valor);
void imprime_stack_crescente(STACK* stack);

#endif