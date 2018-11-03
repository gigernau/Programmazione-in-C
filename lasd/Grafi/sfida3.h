#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "Graph.h"
#include "code.h"
#include "List.h"

#define inf INT_MAX
 
struct Percor{
    int target;
    int peso_tot;
  struct Percor *next;
};
typedef struct Percor* percorso;



void sfida (Graph G, int sorgente, char colore, percorso salita[], percorso discesa[],  percorso minimo[]);
void inserisci_percorso(Graph G,percorso percorsi[], int u, int v, int d);
void attacca_liste (Graph G,percorso salita[], percorso discesa[], int v, percorso minimo);
percorso intesta(percorso salita[], percorso minimo, int k);
