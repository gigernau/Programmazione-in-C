#include <stdio.h>
#include <stdlib.h>
#include "Graph/graph.h"

#include "Graph/list.h"

#include <time.h>
#include <string.h>

Graph creaGrafo(Graph G, Graph H);
int verifica(Graph G, Graph H);

int main() {
  Graph G=NULL, H=NULL, T=NULL;
  printf("GENERO GRAFI CASUALI\n\n");
  G = randomGraph(5);
  H = randomGraph(5);
  printf("GRAFO G:\n\n");
  printGraph(G);
  printf("\nGRAFO H:\n\n");
  printGraph(H);
  printf("\nCREO IL GRAFO T\n\n");
  T = creaGrafo(G,H);
  printf("GRAFO T:\n\n");
  printGraph(T);
  printf("\nVERIFICO PUNTO B\n\n");
  if(verifica(G,H))
    printf("Per ogni nodo di G e H il grado entrante in G e' uguale a quello uscente in H\n");
  else
    printf("Per ogni nodo di G e H il grado entrante in G NON e' uguale a quello uscente in H\n");
  freeGraph(G);
  freeGraph(H);
  freeGraph(T);
  return 0;
}

//PUNTO B
int verifica(Graph G, Graph H){
  int * app, i=0, res=1;
  List curr = NULL;
  app = (int *)calloc(G->nodes_count,sizeof(int));

  //grado incidente G e adiacente H
  for( ; i<G->nodes_count ; i++){
    for(curr = G->adj[0] ; curr ; curr=curr->next )
      app[curr->target]++;
    for(curr = H->adj[0] ; curr ; curr=curr->next )
      app--;
  }
  //gli elementi di app con valore negativo non verificano la regola!
  for(i=0;i<G->nodes_count;i++)
    if(app){
      res=0;
      printf("Per il nodo %d la diff. tra grado entrante in G e uscente in H e' %d.\n",i,*app);
      break;
    }
  free(app);
  return res;
}

//PUNTO A
Graph creaGrafo(Graph G, Graph H){
  List curr = NULL;
  int * app, *isIn, i=0, j=0;
  Graph T = initGraph(G->nodes_count);

  app = (int *)calloc(G->nodes_count, sizeof(int));
  isIn = (int *)calloc(G->nodes_count, sizeof(int));
  for( ; i<G->nodes_count; i++){
    
    for(curr = G->adj[0] ; curr ; curr=curr->next){
      isIn[curr->target]++;
      app[curr->target] += curr->peso;
    }
    for(curr = H->adj[0]; curr ; curr=curr->next){
      isIn[curr->target]++;
      app[curr->target] += curr->peso;
    }
    for(j=0;j<G->nodes_count;j++){
      if(isIn[j] == 2){
        addEdge(T,i,j,app[j]);
      }
      if(isIn[j] > 0 )
        app[j] = isIn[j] = 0;
      else{
        addEdge(T,i,j,-1);
      }
    }
  }
  free(app);
  free(isIn);
  return T;
}



