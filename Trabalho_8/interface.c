#include "interface.h"

void menu(Graph *grafo) {
	printf("\n\t\tComo ir? Versao: VICENTE PIRES!!\n");
	
	for (; grafo->start != NULL; grafo->start = grafo->start->next) {
		printf("%d - %s\n", grafo->start->id, grafo->start->contents.name);
	}

	return;
}

int catch_origin() {
	int origin = 0;
	do {
		printf("Selecione o ponto de partida entre as opcoes acima: ");
		scanf("%d", &origin);
		if (origin < 0 || origin > 35) {
			printf("ESTE PONTO NAO EXISTE!!\n\n");
		}
	} while (origin < 0 || origin > 35);
	return origin;
}

int catch_destiny() {
	int destiny = 0;
	do {
		printf("Selecione o ponto de chegada entre as opcoes acima: ");
		scanf("%d", &destiny);
		if (destiny < 0 || destiny > 35) {
			printf("ESTE PONTO NAO EXISTE!!\n\n");
		}
	} while (destiny < 0 || destiny > 35);
	return destiny;
}