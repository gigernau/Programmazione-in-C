#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "Graph.h"
#include "code.h"
#include <limits.h>
#define inf INT_MAX



/** Funzione acquisisci_int
 * Descrizione:
 * E' un controllo l'input, verifica che
 */
int acquisisci_int()
{   
    // Variabile per l'elemento da inserire
    int elemento;
    
    // array di char per la verifica
    char line[256];
    int verifica=0;

    /* Risolviamo il problema dell'acqusizione di scanf di elemeti,
     * non desiderati, come i caratteri o sequenze, con questa soluzione:
     * prendiamo in input una stringa, e leggiamo da questa stringa, se è
     * un intero la inserisco altrimenti no 
     */
    do{
        verifica=0; 
        
        getchar();
        scanf("%s", line);
        for (int i=0;i<strlen(line);i++)
        {
            if ( line[i]< '0' || line[i] >'9') 
            {
                verifica=1;
            }
        }
        if (verifica==1)
        {
            printf("\nNon e' stato inserito un numero, riprovare :");
        }
            
    }while(verifica==1);
    elemento=atoi(line);
    
    //ritorna il numero corretto
    return elemento;
}

// Inizializza un nuovo grafo
// specifica in ingresso quanti nodi vuoi nel grafo
Graph initGraph(int nodes_count) {
    Graph G = (Graph)malloc(sizeof(struct TGraph));
    G->adj = (List *)calloc(nodes_count, sizeof(List));
    G->nodes_count = nodes_count;
    return G;
}
// Crea un grafo in modo random
Graph randomGraph(int nodes, int edges_min, int edges_max) {
    Graph G = initGraph(nodes);
    int i = 0;
    int x = 0;
    int y = 0;
    int target=0;
    srand((unsigned int)time(NULL));
    assert( edges_min <= edges_max ); // non possono esserci edges_min > edges_max
    if (edges_max > nodes) {
        edges_max = nodes - 1;
    }
    if(nodes>1) { //senza questo controllo,in un grafo con un nodo aggiungeva un arco con target -1
        for (i = 0; i < nodes; i++) {
            for (x = 0; x < edges_min; x ++) {
                target=rand()%nodes;
                if(target==i) //un non ha archi ricorsivi
                    target++;
                if(target==nodes) //se nell'incremento il target è un nodo che non esiste lo decremento di due
                    target-=2;
                addEdge(G, i, target, rand() % 50);
            }
            if(edges_min<edges_max)//   crash se edges_min==edges_max  (rand()%0),quindi non aggiunge ulteriori nodi
            {
                for (y = 0; y < rand() % (edges_max - edges_min); y++) {
                    target=rand()%nodes;
                    if(target==i) //un non ha archi ricorsivi
                        target++;
                    if(target==nodes) //se nell'incremento il target è un nodo che non esiste lo decremento di due
                        target-=2;
                    addEdge(G, i, target, rand() % 50);
                }
            }
        }
    }
    return G;
}

// Dealloca l'intero grafo
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

// Stampa il grafo
void printGraph(Graph G) {
    if (G != NULL) {
        int x = 0;
        for (x = 0; x < G->nodes_count; x++) {
            printf("%d -> ", x);
            printList(G->adj[x]);
            printf("\n");
        }
    }
}
// Aggiunge un arco, specificando sorgente,
// target e peso
void addEdge(Graph G, int source, int target, int peso) {
    assert(G != NULL);
    assert(source < G->nodes_count);
    assert(target < G->nodes_count);
    if (source != target) {
        G->adj[source] = appendNodeList(G->adj[source], target, peso);
    }
    
}


// Rimuovi un arco specificando sorgente e target,restituisce la lista degli archi modifcata
List removeEdge(Graph G, int source, int target) {
    assert(G != NULL);
    assert(source < G->nodes_count);
    assert(target < G->nodes_count);
    if (source != target) {
        G->adj[source] = removeNodeList(G->adj[source], target);
    }
    return G->adj[source];
}


// Aggiungi un nodo
void addNode(Graph G) {
    if (G != NULL) {
        G->adj = (List *)realloc(G->adj, (G->nodes_count+1) * sizeof(List));
        G->nodes_count += 1;
        G->adj[G->nodes_count-1] = NULL;
    }
}


// Rimuovi un nodo dal grafo, sistemando
// gli indici e riallocando la memoria
void removeNode(Graph G, int node_to_remove) {
    if (G != NULL) {
        int i = 0;
        int x=0;
        List *tmp = G->adj;
        G->adj = (List *)calloc(G->nodes_count-1, sizeof(List));
        for (i = 0; i < G->nodes_count; i++) 
        {
            if (i != node_to_remove) 
            {
                G->adj[x] = checkListRemoval(tmp[i], node_to_remove);
                x++;
            } 
            else 
            {
                removeNodeList(G->adj[x], node_to_remove);
            }
        }
        free(tmp);
        G->nodes_count -= 1;
    }
}

//Ricerca nodo da rimuovere
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

Graph Trasposto(Graph G)
{
  Graph G_T=NULL;
  if ( G!=NULL)
    {
     
      G_T= initGraph(G->nodes_count);
      for ( int i = 0; i < G->nodes_count; i++)
    {
      List adj = G->adj[i];
      while( adj!=NULL)
        {
          int v = adj->target;
          int peso =adj->peso;
          addEdge(G_T,v,i,peso);
          adj=adj->next;
        }
    }
     
    }
  return G_T;
}
