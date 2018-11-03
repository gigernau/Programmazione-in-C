#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "graph.h"
#include "../Input/inputReader.h"

#define EDGE_SUCC 0.33 //indica la percentuale di successo di creazione di un arco


Graph randomGraph(int nodes) {
    Graph G = initGraph(nodes);
	int i = 0;
    int j = 0;
    float p = 0;
    int target=0;
    srand((unsigned int)time(NULL));
    
    if(nodes>0) {
       	for(i=0;i<G->nodes_count;i++){
			for(j=0;j<G->nodes_count;j++){
				if(i!=j){ //per evitare di costruire cappi
					p=(float)((rand()%nodes)+1)/nodes;
					if(p<=EDGE_SUCC){
						addEdge(G,i,j,rand()%100+1);
					}
				}
			}
		}
    }
    return G;
}

void graphEditorMenu(Graph G) { //Effettua modifiche varie nel grafo G, chiamabile anche se il grafo era preesistente
	while(1) {
		printGraph(G);
		printf("1 - Aggiungi nodo\n2 - Rimuovi nodo\n3 - Aggiungi arco\n4 - Rimuovi arco\n5 - Stampa\n6 - Fine\nInput  ->  ");
		int input = 0;
		while(!getPositive(&input) || input>6 || input<0);
		switch(input) {
			case 1: {
				addNode(G);
				break;
			}
			case 2: {
				int nodo = -1;
				printf("Vertice da rimuovere:\t");
				while(!getPositive(&nodo) || nodo>=G->nodes_count) { printf("Selezione del nodo non valida. Riprovare\n"); }
				removeNode(G, nodo);
				break;
			}
			case 3: {
				int sorgente = 0;
				printf("Vertice sorgente:\t");
				while(!getPositive(&sorgente) || sorgente>=G->nodes_count) {printf("Selezione del nodo non valida. Riprovare\n"); }
				int destinazione = 0;
				printf("Vertice destinazione:\t");
				while(!getPositive(&destinazione) || destinazione>=G->nodes_count) {printf("Selezione del nodo non valida. Riprovare\n"); }
				int peso = 0;
				printf("Peso:\t");
				while(!getInt(&peso)) { printf("Peso non valido. Riprovare\n"); }
				addEdge(G, sorgente, destinazione, peso);
				break;
			}
			case 4: {
				int sorgente = 0;
				printf("Vertice sorgente:\t");
				while(!getPositive(&sorgente) || sorgente>=G->nodes_count) {printf("Selezione del nodo non valida. Riprovare\n"); }
				int destinazione = 0;
				printf("Vertice destinazione:\t");
				while(!getPositive(&destinazione) || destinazione>=G->nodes_count) {printf("Selezione del nodo non valida. Riprovare\n"); }
				removeEdge(G, sorgente, destinazione);
				break;
			}
			case 5: {
				printGraph(G);
				break;
			}
			case 6: {
				return;
			}
		}
	}
}

Graph graphCreationMenu(int n) {
	Graph G=NULL;
	int input=1;
	do{
		if(input==0 || input>3) printf("Nessuna azione associata al codice %d\n",input);
		printf("Seleziore il metodo di creazione del nuovo grafo :\n");
		printf("1) Grafo vuoto\n");
		printf("2) Grafo popolato da archi forniti in input\n");
		printf("3) Grafo popolato da archi random\n");
	} while(!getPositive(&input) || input>3 || input==0);
	
	if(input>1){
		if (n<=0) {
			do{
				printf("Quanti nodi ha il grafo?\n");
			}
			while(!getPositive(&n));
		}
		if(input==2){
			G=initGraph(n);
			graphEditorMenu(G);
		} else {
			G=randomGraph(n);
		}
	} else {
		G=initGraph(0);
	}
	
	return G;
}

Graph initGraph(int nodes_count) {
    Graph G = (Graph)malloc(sizeof(struct TGraph));
    G->adj = (List *)calloc(nodes_count, sizeof(List));
    G->nodes_count = nodes_count;
    return G;
}

void freeGraph(Graph G) {
    if (G != NULL) {
        if (G->nodes_count > 0) {
            int i = 0;
            for (i = 0; i < G->nodes_count; i++) {
                freeList(G->adj[i]);
            }
        }
        free(G);
    }
}

void printGraphAux(Graph G) {
	if (G != NULL) {
        int x = 0;
        for (x = 0; x < G->nodes_count; x++) {
            printf("%d -> ", x);
            printList(G->adj[x]);
            printf("\n");
        }
    }
}

void printGraph(Graph G) {
    printGraphAux(G);
	printf("\n\n");
}

void addEdge(Graph G, int source, int target, int peso) {
    assert(G != NULL);
    assert(source < G->nodes_count);
    assert(target < G->nodes_count);
    if (source != target) {
        G->adj[source] = appendNodeList(G->adj[source], target, peso);
    }
    
}


List removeEdge(Graph G, int source, int target) {
    assert(G != NULL);
    assert(source < G->nodes_count);
    assert(target < G->nodes_count);
    if (source != target) {
        G->adj[source] = removeNodeList(G->adj[source], target);
    }
	return G->adj[source];
}


void addNode(Graph G) {
    if (G != NULL) {
    	List * old=G->adj;
    	int i=0;
    	//G->adj = (List *)realloc(G->adj, (G->nodes_count+1) * sizeof(List));
        G->adj = (List *)malloc((G->nodes_count+1) * sizeof(List));
        for(i=0;i<G->nodes_count;i++)
        	G->adj[i]=old[i];
        G->nodes_count += 1;
        G->adj[G->nodes_count-1] = NULL;
    }
}


void removeNode(Graph G, int node_to_remove) {
    if (G != NULL) {
        int i = 0;
        int x = 0;
        List *tmp = G->adj;
        G->adj = (List *)calloc(G->nodes_count-1, sizeof(List));
        for (i = 0; i < G->nodes_count; i++) {
            if (i != node_to_remove) {
                G->adj[x] = checkListRemoval(tmp[i], node_to_remove);
                x++;
            } else {
				//freeList(G->adj[x]);
                freeList(tmp[i]);
            }
        }
        free(tmp);
        G->nodes_count -= 1;
    }
}


List checkListRemoval(List L, int node_to_remove) {
    if (L != NULL) {
        L->next = checkListRemoval(L->next, node_to_remove);
        if (L->target == node_to_remove) {
            List tmp = L->next;
            free(L);
            return tmp;
        } else if (L->target > node_to_remove) {
            L->target -= 1;
        }
    }
    return L;
}


