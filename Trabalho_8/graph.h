#ifndef _LIB_GRAPH_
#define _LIB_GRAPH_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SUCCEED 0
#define input_ERROR 1
#define system_ERROR (-1)
#define ptr_ERROR  NULL
#define node_ERROR node_error
#define edge_ERROR edge_error

///Data types definitions

typedef struct nodedata{ //This struct may hold any information
    char name[50];
}NodeData;

typedef struct edgedata{ //This struct may hold any information
    int weight;
}EdgeData;

NodeData node_error;
EdgeData edge_error;

struct edge{ //Represents a edge, holding the destination, pointers to EdgeData and the next edge
    int destination;
    EdgeData contents;
    struct edge *next;
};
typedef struct edge Edge;

struct node{ //Represents a node, contains pointers to NodeData, list of edges and the next node
    int id;
    NodeData contents;
    Edge *start, *finish;
    struct node *next;
};
typedef struct node Node;

typedef struct graph{ //Defines the graph name, number of nodes and edges, pointers to the list of nodes
    char *graph_name;
    int n_nodes, n_edges;
    Node *start, *finish;
}Graph;

///Functions
Graph* create_graph(char *);
/*
Initialize the graph structure
*/

char* return_graph_name (Graph *);
/*
Returns the name of the graph G
*/

int destroy_graph(Graph *);
/*
Clears the memory occupied
*/

int adjacent(Graph *, int, int);
/*
Check if there's a edge between "x" and "y"
*/

int* neighbors(Graph *, int);
/*
Shows all neighbors of a given node
*/

int add_node(Graph *, int);
/*
Creates a new node
*/

int remove_node(Graph *, int);
/*
Remove a node
*/

int add_edge(Graph *, int, int);
/*
Creates an edge between "x" and "y"
*/

int remove_edge(Graph *, int, int);
/*
Removes an edge between "x" and "y"
*/

NodeData return_node_value(Graph *, int);
/*
Returns the value of a node
*/

int set_node_value(Graph *, int, NodeData );
/*
Defines the value of a node
*/

EdgeData return_edge_value(Graph *, int, int);
/*
Returns the value of an edge
*/

int set_edge_value(Graph *, int, int, EdgeData );
/*
Defines the value of an edge
*/

#endif // _LIB_GRAPH_
