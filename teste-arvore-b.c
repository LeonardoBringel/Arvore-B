#include <stdio.h>
#include <stdlib.h>
#include "arvore-b.h"

int menu() {

	int resp;

	system("cls");
	printf("[1] - Inserir\t[2] - Imprimir\n");
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

		stack = aloca_chave(stack, valor);

		printf("\nDeseja inserir outro? <1/0>: ");
		scanf("%d", &valor);
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
