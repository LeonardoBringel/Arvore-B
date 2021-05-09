#include <stdio.h>
#include <stdlib.h>
#include "arvore-b.h"

STACK* novo_stack(int valor) {

	STACK* stack = (STACK*) malloc(sizeof(STACK));
	if(!stack) {
		printf("\nErro ao criar o stack!\n");
		exit(0);
	}

	stack->ant = NULL;

	stack->menorq_1 = NULL;
	stack->chave1 = valor;

	stack->menorq_2 = NULL;
	stack->chave2 = 0;
	stack->menorq_3 = NULL;
	
	stack->chave3 = 0;
	stack->maiorq_3 = NULL;

	return stack;
}

int is_folha(STACK* stack) {

	if(stack->menorq_1 == NULL && stack->menorq_2 == NULL) {
		return 1;
	}
	return 0;
}

STACK* aloca_chave(STACK* stack, int valor) {

	if(!stack) {
		#if DEBUG
		printf("\nSTACK VAZIO\n");
		#endif
		return novo_stack(valor);
	}

	if(is_folha(stack)) {

		#if DEBUG
		printf("\nSTACK FOLHA\n");
		#endif
		if(valor < stack->chave1) {
			
			#if DEBUG
			printf("\nVALOR < CHAVE1");
			#endif
			stack->chave3 = stack->chave2;
			stack->chave2 = stack->chave1;
			stack->chave1 = valor;
		} else if(!stack->chave2) {

			#if DEBUG
			printf("\nVALOR = CHAVE2");
			#endif
			stack->chave2 = valor;
		} else if(valor < stack->chave2) {

			#if DEBUG
			printf("\nVALOR < CHAVE2");
			#endif
			stack->chave3 = stack->chave2;
			stack->chave2 = valor;
		} else {

			#if DEBUG
			printf("\nVALOR = CHAVE3");
			#endif
			stack->chave3 = valor;
		}
	} else {

		#if DEBUG
		printf("\nSTACK NAO FOLHA\n");
		#endif
		if(valor < stack->chave1) {

			#if DEBUG
			printf("\nVALOR -> MENORQ_1");
			#endif
			stack->menorq_1 = aloca_chave(stack->menorq_1, valor);
		} else if(valor < stack->chave2 || !stack->chave2) {

			#if DEBUG
			printf("\nVALOR -> MENORQ_2");
			#endif
			stack->menorq_2 = aloca_chave(stack->menorq_2, valor);
		} else {

			#if DEBUG
			printf("\nVALOR -> MENORQ_3");
			#endif
			stack->menorq_3 = aloca_chave(stack->menorq_3, valor);
		}
	}

	#if DEBUG
	printf("\n%d %d %d\n", stack->chave1, stack->chave2, stack->chave3);
	#endif
	return overflow(stack);
}

int is_overflow(STACK* stack) {

	if(stack->chave3 != 0) {
		return 1;
	}
	return 0;
}

STACK* split_menor(STACK* stack) {
	
	STACK* stack_menor = novo_stack(stack->chave1);
	stack_menor->menorq_1 = stack->menorq_1;
	stack_menor->menorq_2 = stack->menorq_2;

	return stack_menor;
}

STACK* split_maior(STACK* stack) {

	STACK* stack_maior = novo_stack(stack->chave3);
	stack_maior->menorq_1 = stack->menorq_3;
	stack_maior->menorq_2 = stack->maiorq_3;

	return stack_maior;
}

STACK* overflow_topo(STACK* stack) {
	
	#if DEBUG
	printf("\nSTACK TOPO\n");
	#endif

	STACK* stack_menor = split_menor(stack);
	STACK* stack_maior = split_maior(stack);

	STACK* stack_aux = novo_stack(stack->chave2);
	stack_menor->ant = stack_aux;
	stack_maior->ant = stack_aux;

	stack_aux->menorq_1 = stack_menor;
	stack_aux->menorq_2 = stack_maior;

	return stack_aux;
}

STACK* overflow_intermediario(STACK* stack) {
	
	#if DEBUG
	printf("\nSTACK INTERMEDIARIO\n");
	#endif

	STACK* stack_menor = split_menor(stack);
	STACK* stack_maior = split_maior(stack);
	
	if(stack->chave2 < stack->ant->chave1) {

		stack->ant->maiorq_3 = stack->ant->menorq_3;
		stack->ant->chave3 = stack->ant->chave2;
		stack->ant->menorq_3 = stack->ant->menorq_2;
		stack->ant->chave2 = stack->ant->chave1;

		stack->ant->chave1 = stack->chave2;
		stack->ant->menorq_2 = stack_maior;
		return stack_menor;
	}
	
	if(!stack->ant->chave2) {

		stack->ant->chave2 = stack->chave2;
		stack->ant->menorq_3 = stack_maior;

		return stack_menor;
	}

	if(stack->chave2 < stack->ant->chave2) {

		stack->ant->maiorq_3 = stack->ant->menorq_3;
		stack->ant->chave3 = stack->ant->chave2;

		stack->ant->chave2 = stack->chave2;
		stack->ant->menorq_3 = stack_maior;
		return stack_menor;
	}

	stack->ant->maiorq_3 = stack_maior;
	stack->ant->chave3 = stack->chave3;

	return stack_menor;
}

STACK* overflow(STACK* stack) {

	if(!is_overflow(stack)) {
		#if DEBUG
		printf("\nOVERFLOW = FALSE\n");
		#endif
		return stack;
	}
	#if DEBUG
	printf("\nOVERFLOW = TRUE\n");
	#endif
	return stack->ant == NULL ? overflow_topo(stack) : overflow_intermediario(stack);
}

void imprime_valor(int valor) {
	if(valor) {
		printf(" %d ", valor);
	}
}

void imprime_stack_crescente(STACK* stack) {

	if(stack) {
		imprime_stack_crescente(stack->menorq_1);
		imprime_valor(stack->chave1);
		imprime_stack_crescente(stack->menorq_2);
		imprime_valor(stack->chave2);
		imprime_stack_crescente(stack->menorq_3);
		imprime_valor(stack->chave3);
		imprime_stack_crescente(stack->maiorq_3);
	}
}
