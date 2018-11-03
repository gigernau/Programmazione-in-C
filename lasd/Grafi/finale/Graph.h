#ifndef Graph_Graph_h
#define Graph_Graph_h
#include "List.h"

struct TGraph {
    List *adj;
    int nodes_count;
};

typedef struct TGraph* Graph;

int acquisisci_int();

Graph initGraph(int nodes_count);

Graph randomGraph(int nodes, int edges_min, int edges_max);

void freeGraph(Graph G);

void printGraph2(Graph G);

void printGraph(Graph G,int h[]);

void addEdge(Graph G, int source, int target, int peso);

List removeEdge(Graph G, int source, int target);

void addNode(Graph G);

void removeNode(Graph G, int node_to_remove);

List checkListRemoval(List L, int node_to_remove);

Graph Trasposto(Graph G);
#endif
