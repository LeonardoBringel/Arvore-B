#include <stdio.h>
#include <stdlib.h>
#include "arvore-b.h"
#include "arvore-b-remocao.h"

STACK* remove_chave(STACK* stack, int valor) {

	if(!stack) {
		printf("Arvore vazia\n");
		return stack;
	}

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
		
		#if DEBUG
		printf("\nSTACK NAO FOLHA\n");
		#endif
		if(valor == stack->chave1) {

			#if DEBUG
			printf("\nVALOR == CHAVE1\n");
			#endif
			if(stack->menorq_1) {

				if(stack->menorq_1->chave2) {

					#if DEBUG
					printf("\nCHAVE 1 = MENORQ 1 CHAVE2\n");
					#endif
					stack->chave1 = stack->menorq_1->chave2;
					stack->menorq_1->chave2 = 0;
				} else {

					#if DEBUG
					printf("\nCHAVE 1 = MENORQ 1 CHAVE1\n");
					#endif
					stack->chave1 = stack->menorq_1->chave1;
					stack->menorq_1->chave1 = 0;
					stack->menorq_1 = underflow(stack->menorq_1);
				}
			} else if(stack->menorq_2) {

				#if DEBUG
				printf("\nCHAVE 1 = MENORQ 2 CHAVE1\n");
				#endif
				stack->chave1 = stack->menorq_2->chave1;
				stack->menorq_2->chave1 = stack->menorq_2->chave2;
				stack->menorq_2->chave2 = 0;
				stack->menorq_2 = underflow(stack->menorq_2);
			} else {

				#if DEBUG
				printf("\nROTACAO ESQUERDA\n");
				#endif
				stack->chave1 = stack->chave2;
				stack->chave2 = 0;
				stack->menorq_2 = stack->menorq_3;
				stack->menorq_3 = NULL;
			}
		} else if(valor == stack->chave2) {

			#if DEBUG
			printf("\nVALOR == CHAVE2\n");
			#endif
			if(stack->menorq_2) {

				if(stack->menorq_2->chave2) {

					#if DEBUG
					printf("\nCHAVE 2 = MENORQ 2 CHAVE2\n");
					#endif
					stack->chave2 = stack->menorq_2->chave2;
					stack->menorq_2->chave2 = 0;
				} else {

					#if DEBUG
					printf("\nCHAVE 2 = MENORQ 2 CHAVE1\n");
					#endif
					stack->chave2 = stack->menorq_2->chave1;
					stack->menorq_2->chave1 = 0;
					stack->menorq_2 = underflow(stack->menorq_2);
				}
			} else if(stack->menorq_3) {

				#if DEBUG
				printf("\nCHAVE 2 = MENORQ 3 CHAVE1\n");
				#endif
				stack->chave2 = stack->menorq_3->chave1;
				stack->menorq_3->chave1 = stack->menorq_3->chave2;
				stack->menorq_3->chave2 = 0;
				stack->menorq_3 = underflow(stack->menorq_3);
			} else {
				
				#if DEBUG
				printf("\nCHAVE 2 = 0\n");
				#endif
				stack->chave2 = 0;
			}
		} else if(valor < stack->chave1) {

			#if DEBUG
			printf("\nVALOR -> MENORQ 1\n");
			#endif
			stack->menorq_1 = remove_chave(stack->menorq_1, valor);
		} else if(valor < stack->chave2 || stack->chave2 == 0) {

			#if DEBUG
			printf("\nVALOR -> MENORQ 2\n");
			#endif
			stack->menorq_2 = remove_chave(stack->menorq_2, valor);
		} else {

			#if DEBUG
			printf("\nVALOR -> MENORQ 3\n");
			#endif
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
