#include <stdio.h>
#include <stdlib.h>
#include "arvore-b.h"
#include "arvore-b-remocao.h"

STACK* remove_chave(STACK* stack, int valor) {

	if(is_folha(stack)) {

		#if DEBUG
		printf("\nSTACK FOLHA\n");
		#endif
		if(valor == stack->chave1) {

			#if DEBUG
			printf("\nVALOR == CHAVE1\n");
			#endif
			stack->chave1 = stack->chave2;
			stack->chave2 = 0;
		} else if(valor == stack->chave2) {

			#if DEBUG
			printf("\nVALOR == CHAVE2\n");
			#endif
			stack->chave2 = 0;
		} else {
			printf("\nO valor nao existe\n");
		}
	} else {

		if(valor == stack->chave1 || valor == stack->chave2) {
			printf("\nValor encontrado, mas nao pode ser removido\n");
		} else if(valor < stack->chave1) {
			stack->menorq_1 = remove_chave(stack->menorq_1, valor);
		} else if(valor < stack->chave2 || stack->chave2 == 0) {
			stack->menorq_2 = remove_chave(stack->menorq_2, valor);
		} else {
			stack->menorq_3 = remove_chave(stack->menorq_3, valor);
		}
	}

	#if DEBUG
	printf("\n%d %d %d\n", stack->chave1, stack->chave2, stack->chave3);
	#endif
	return underflow(stack);
}

int is_underflow(STACK* stack) {
	return stack->chave1 == 0 ? 1 : 0;
}

STACK* underflow(STACK* stack) {

	if(!is_underflow(stack)) {
		#if DEBUG
		printf("\nUNDEFLOW = FALSE\n");
		#endif
		return stack;
	}

	#if DEBUG
	printf("\nUNDERFLOW = TRUE\n");
	#endif

	if(is_folha(stack)) {
		free(stack);
		return NULL;
	}
}
