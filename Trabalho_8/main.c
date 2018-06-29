#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "graph.h"
#include "reader.h"

int main() {

    Graph *grafo = load_graph("nodes.txt", "routes.txt");

    menu(grafo);
    int origin = catch_origin();
    int destiny = catch_destiny();

    destroy_graph(grafo);
    return 0;
}