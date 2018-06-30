
#include "graph.h"

Graph* create_graph(char *name){

    int length = strlen(name);
    Graph *G = (Graph *) malloc(sizeof(Graph));
    if (G== NULL)
        return ptr_ERROR; //Graph could not be allocated
    G->graph_name = (char *) malloc(length*sizeof(char));
    if (G->graph_name==NULL)
        return ptr_ERROR; //Graph's name could not be allocated
    strcpy(G->graph_name, name);
    G->n_nodes = 0;
    G->n_edges = 0;
    G->start = NULL;
    G->finish = NULL;

    return G;
}

char* return_graph_name (Graph *G){
    return G->graph_name;
}


int destroy_graph(Graph *G){
    Node *p;
    for(p=G->start; p!=NULL; p=p->next){ //Wipes the list of nodes
        remove_node(G, p->id);
    }
    free(G);
    return SUCCEED; //Task completed
}

int adjacent(Graph *G, int x, int y){
    Node *p;
    Edge *q;
    for(p=G->start; p!=NULL; p=p->next){
        if(x == p->id){
            for(q=p->start; q!=NULL; q=q->next){
                if(y == q->destination){
                   return SUCCEED; //Indicates that there's a connection between "x" and "y"
                }
            }
        }
    }
    return input_ERROR; //The edge does not exists
}

int* neighbors(Graph *G, int x){
    Node *p;
    Edge *q;
    int i;
    int *neighbor = (int *) malloc(2*sizeof(int));
    neighbor[0] = 0;
    for (p=G->start; p!=NULL; p=p->next){
        if(x == p->id && p->start != NULL){
            for(q=p->start, i = 1; q!=NULL; q=q->next, i++){
                neighbor[i] = q->destination;
                neighbor = (int *) realloc(neighbor, (i+2)*sizeof(int));
                neighbor[0]++;
            }
            neighbor = (int *) realloc(neighbor, (neighbor[0]+1)*sizeof(int));
            return neighbor; //Task completed, all neighbors of "x" were returned
        }
    }
    free(neighbor);
    return ptr_ERROR; //Indicates that the node "x" does not exist or does not have neighbors
}

int add_node(Graph *G, int x){
    Node *p, *q;
    if (G->start == NULL){ //Verifies if it's the first node
        p = (Node *) malloc(sizeof(Node));
        if (p==NULL)
            return system_ERROR; //The node could not be allocated
        p->id = x;
        p->next = NULL;
        p->start = NULL;
        p->finish = NULL;
        G->start = p;
        G->finish = p;
        G->n_nodes++;
        return SUCCEED; //Node successfully created
    }
    else{
        for(q=G->start; q!=NULL; q=q->next){
            if(q->id == x)
                return x++; //Att id
        }
        p = (Node *) malloc(sizeof(Node));
        if (p==NULL)
            return system_ERROR; //The node could not be allocated
        p->id = x;
        p->next = NULL;
        p->start = NULL;
        p->finish = NULL;
        G->finish->next = p;
        G->finish = p;
        G->n_nodes++;
        return SUCCEED; //Node successfully created
    }
}

int remove_node(Graph *G, int x){
    Node *p, *q, *s, *aux_N;
    Edge *r;
    if(G->start->id == x){ //Special case: the first node on the list
        for(p=G->start; p!=NULL; p=p->next){ //Wipes out all the edges destined to this node
            remove_edge(G, p->id, x);
        }
        for(r=G->start->start; r!=NULL; r=r->next){ //Wipes out all the edges departing from this node
            remove_edge(G, x, r->destination);
        }
        aux_N = G->start->next;
        free(G->start);
        G->start = aux_N;
        G->n_nodes--;
        return SUCCEED; //The node was found and removed
    }
    for(p=G->start, q=NULL; p!=NULL; p=p->next){
        if(p->id == x){
            for(s=G->start; s!=NULL; s=s->next){ //Wipes out all the edges destined to this node
                remove_edge(G, s->id, x);
            }
            for(r=p->start; r!=NULL; r=r->next){ //Wipes out all the edges departing from this node
                remove_edge(G, x, r->destination);
            }
            aux_N = q->next->next;
            free(p);
            q->next = aux_N;
            G->n_nodes--;
            return SUCCEED; //The node was found and removed
        }
        else
            q = p;
    }
    return input_ERROR; //The node does not exist
}

int add_edge(Graph *G, int x, int y){
    Node *p;
    Edge *q;
    int node_detect = 0;
    for (p = G->start; p!=NULL; p=p->next){ //Ensure that both nodes exists
        if (p->id == x || p->id == y)
            node_detect++;
    }
    if(node_detect != 2)
        return input_ERROR; //At least one of the nodes does not exist

    for (p = G->start; p!=NULL; p=p->next){
        if(p->id == x){
            if(p->start==NULL){ //Verifies the existence of the list of edges
                q = (Edge *) malloc(sizeof(Edge));
                if(q == NULL)
                    return system_ERROR; //Could not allocate memory for the new edge
                q->destination = y;
                q->next = NULL;
                p->start = q;
                p->finish = q;
                G->n_edges++;
                return SUCCEED; //Edge successfully created
            }
            else{
                for(q=p->start; q!=NULL; q=q->next){
                    if(q->destination == y){
                        return input_ERROR; //The edge already exists
                    }
                }
                q = (Edge *) malloc(sizeof(Edge));
                if(q == NULL)
                    return system_ERROR; //Could not allocate memory for the new edge
                q->destination = y;
                q->next = NULL;
                p->finish->next = q;
                p->finish = q;
                G->n_edges++;
                return SUCCEED; //Edge successfully created
            }
        }
    }
}

int remove_edge(Graph *G, int x, int y){
   Node *p;
   Edge *q, *r, *aux_E;
   int flag = adjacent(G, x, y);
   if(flag == 0){ //Indicates that there's a edge between
        for(p=G->start; p!=NULL; p=p->next){
            if(p->id == x){
                if(p->start->destination == y){ //Special case: first edge
                    aux_E = p->start->next;
                    free(p->start);
                    p->start = aux_E;
                    G->n_edges--;
                    return SUCCEED; //Edge removed
                }
                for(q=p->start, r=NULL; q!=NULL; q=q->next){
                    if(q->destination == y){
                        aux_E = r->next->next;
                        free(q);
                        r->next = aux_E;
                        G->n_edges--;
                        return SUCCEED; //Edge removed
                    }
                    else
                        r = q;
                }
            }
        }
   }
   return input_ERROR; //The required edge does not exist
}

NodeData return_node_value(Graph *G, int x){
    Node *p;
    for(p=G->start; p!=NULL; p=p->next){
        if(p->id == x)
            return p->contents;
    }
    return node_ERROR; //Node does not exist
}

int set_node_value(Graph *G, int x, NodeData v){
    Node *p;
    for(p=G->start; p!=NULL; p=p->next){
        if(p->id == x){
            p->contents = v;
            return SUCCEED; //Value set successfully
        }
    }
    return input_ERROR; //Node does not exist
}

EdgeData return_edge_value(Graph *G, int x, int y){
    Node *p;
    Edge *q;
    for(p=G->start; p!=NULL; p=p->next){
        if(p->id == x){
            for(q=p->start; q!=NULL; q=q->next){
                if(q->destination == y)
                    return q->contents;
            }
        }
    }
    return edge_ERROR; //Edge does not exist
}

int set_edge_value(Graph *G, int x, int y, EdgeData v){
    Node *p;
    Edge *q;
    for(p=G->start; p!=NULL; p=p->next){
        if(p->id == x){
            for(q=p->start; q!=NULL; q=q->next){
                if(q->destination == y){
                    q->contents = v;
                    return SUCCEED; //Edge value set
                }
            }
        }
    }
    return input_ERROR; //Edge does not exist
}
