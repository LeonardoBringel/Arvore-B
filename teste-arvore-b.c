#include <stdio.h>
#include <stdlib.h>
#include "arvore-b.h"
#include "arvore-b-remocao.h"

int menu() {

	int resp;

	system("cls");
	printf("[1] - Inserir\t[3] - Remover\n");
	printf("[2] - Imprimir\t[4] - Buscar\n");
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

STACK* remover(STACK* stack) {

	int valor;
	do {
		system("cls");
		printf("Valor a ser removido: ");
		scanf("%d", &valor);

		if(valor != 0) {
			stack = remove_chave(stack, valor);

			printf("\nDeseja remover outro? <1/0>: ");
			scanf("%d", &valor);
		}
	} while(valor != 0 && stack);
	return stack;
}

void buscar(STACK* stack) {

	int valor;
	do {
		system("cls");
		printf("Valor a ser procurado: ");
		scanf("%d", &valor);

		valor = busca_valor(stack, valor);
		valor ? printf("\n%d\n", valor) : printf("\nValor nao encontrado\n");

		printf("\nDeseja buscar outro? <1/0>: ");
		scanf("%d", &valor);
	} while(valor != 0);
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

				if(!stack) {
					printf("Arvore vazia\n");
					break;
				}
				imprime_stack_crescente(stack);
				printf("\n");
				break;
			}
			case 3: {
				
				if(!stack) {
					printf("Arvore vazia\n");
					break;
				}
				stack = remover(stack);
				break;
			}
			case 4: {

				if(!stack) {
					printf("Arvore vazia\n");
					break;
				}
				buscar(stack);
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
