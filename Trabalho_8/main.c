#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "graph.h"
#include "reader.h"

int main() {

    Graph *grafo = load_graph("nodes.txt", "routes.txt");

    menu(grafo);
    //int origin = catch_origin();
    //int destiny = catch_destiny();

    //calculate_route(grafo);
    
	int id;
	char name[50];
	NodeData insert_node;
	int conection;
	int weight;
	EdgeData insert_edge;
    int *neighbor;
	char option;
    do {
    	option = catch_option(grafo);

		switch (option) {
			case 'a':
				printf("Coloque o id do ponto: ");
				scanf("%d", &id);
				printf("Coloque o nome do ponto: ");
				scanf("%s", name);
				getchar();
				add_node(grafo, id);
				strcpy(insert_node.name, name);
				set_node_value(grafo, id, insert_node);
				menu(grafo);
			break;

			case 'b':
				printf("Digite o id dos dois pontos que ela liga e seu peso(Ex: 1 2 4): ");
				scanf("%d %d %d", &id, &conection, &weight);
				add_edge(grafo, id, conection);
				add_edge(grafo, conection, id);
				insert_edge.weight = weight;
				set_edge_value(grafo, id, conection, insert_edge);
				set_edge_value(grafo, conection, id, insert_edge);
			break;

			case 'c':
				printf("Digite o id ponto que deseja retirar: ");
				scanf("%d", &id);
				remove_node(grafo, id);
				menu(grafo);	
			break;

			case 'd':
				printf("Digite os dois pontos em que ela liga para ser retirado(Ex: 1 2): ");
				scanf("%d %d", &id, &conection);
				remove_edge(grafo, id, conection);
			break;

			case 'e':
				printf("Digite o id que deseja ver suas conexoes: ");
				scanf("%d", &conection);
				neighbor = neighbors(grafo, conection);
    			for(int i = 1; i <= neighbor[0]; i++){
       		 		printf("V%d: %d\n", i, neighbor[i]);
    			}
			break;

			case 'f':

			break;

			default:
				printf("DIGITE UMA OPCAO VALIDA\n\n");
			break;
		}
	} while (option != 'f');
	free(neighbor);
    destroy_graph(grafo);
    return 0;
}