#include <stdio.h>
#include <stdlib.h>
#include "arvore-b.h"
#include "arvore-b-remocao.h"

int menu() {

	int resp;

	system("cls");
	printf("[1] - Inserir\t[3] - Remover\n");
	printf("[2] - Imprimir\n");
	printf("[0] - Sair\tOpcao: ");
	scanf("%d", &resp);
	system("cls");

	return resp;
}

STACK* inserir(STACK* stack) {

	int valor;
	do {
		system("cls");
		printf("Insira um valor (diferente de 0): ");
		scanf("%d", &valor);

		if(valor != 0) {
			stack = aloca_chave(stack, valor);

			printf("\nDeseja inserir outro? <1/0>: ");
			scanf("%d", &valor);
		}
	} while(valor != 0);
	return stack;
}

int main() {

	STACK* stack = NULL;

	do {
		switch(menu()) {
			case 1: {
				stack = inserir(stack);
				break;
			}
			case 2: {
				imprime_stack_crescente(stack);
				printf("\n");
				break;
			}
			case 3: {

				int valor;

				printf("Valor a ser removido: ");
				scanf("%d", &valor);

				stack = remove_chave(stack, valor);
				break;
			}
			case 0: {
				printf("Voce escolheu sair :(");
				exit(0);
				break;
			}
			default: {
				printf("Opcao invalida!\n");
				break;
			}
		}
		system("pause");
	} while(1);
}
