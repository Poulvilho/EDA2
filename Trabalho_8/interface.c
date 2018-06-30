#include "interface.h"

#define MAX_NODES 35

void menu(Graph *grafo) {
	printf("\n\t\tComo ir? Versao: VICENTE PIRES!!\n");
	
	Node * node;
	for (node = grafo->start; node != NULL; node = node->next) {
		printf("%d - %s\n", node->id, node->contents.name);
	}
	free(node);

	printf("\nOPCOES:\n");
	printf("a) Adicionar ponto.\n");
	printf("b) Adicionar rua.\n");
	printf("c) Retirar ponto.\n");
	printf("d) Retirar rua.\n");
	printf("e) Vizinhos de algum ponto.\n");
	return;
}

char catch_option () {
	char select;
	printf("\nO que deseja: ");
	scanf("%c", &select);
	getchar();
	printf("\n");

	return select;
}
/*
int catch_origin() {
	int origin = 0;
	do {
		printf("Selecione o ponto de partida entre as opcoes acima: ");
		scanf("%d", &origin);
		if (origin < 0 || origin > MAX_NODES) {
			printf("ESTE PONTO NAO EXISTE!!\n\n");
		}
	} while (origin < 0 || origin > MAX_NODES);
	return origin;
}

int catch_destiny() {
	int destiny = 0;
	do {
		printf("Selecione o ponto de chegada entre as opcoes acima: ");
		scanf("%d", &destiny);
		if (destiny < 0 || destiny > MAX_NODES) {
			printf("ESTE PONTO NAO EXISTE!!\n\n");
		}
	} while (destiny < 0 || destiny > MAX_NODES);
	return destiny;
}

void calculateRoute(Graph *grafo) {
	
}
*/
