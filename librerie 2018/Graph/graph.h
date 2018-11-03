#ifndef Graph_Graph_h
#define Graph_Graph_h
#include "list.h"

struct TGraph {
    List *adj;
    int nodes_count;
};

typedef struct TGraph* Graph;

// Crea un grafo in modo random con nodes nodi
Graph randomGraph(int nodes);

// Dealloca l'intero grafo
void freeGraph(Graph G);

// Inizializza un nuovo grafo vuoto specificando in ingresso quanti nodi saranno nel grafo
Graph initGraph(int nodes_count);

// Stampa il grafo
void printGraph(Graph G);

// Aggiunge un arco, specificando sorgente, target e peso
void addEdge(Graph G, int source, int target, int peso);

// Rimuovi un arco specificando sorgente e target,restituisce la lista degli archi modifcata
List removeEdge(Graph G, int source, int target);

// Aggiungi un nodo
void addNode(Graph G);

// Rimuovi un nodo dal grafo, sistemando gli indici e riallocando la memoria
void removeNode(Graph G, int node_to_remove);

List checkListRemoval(List L, int node_to_remove);

// Crea un nuovo grafo e lo popola in base alla scelta effettuata dal menu
Graph graphCreationMenu(int n);

// Menu per la modifica e gestione dei grafi
void graphEditorMenu(Graph);

#endif
