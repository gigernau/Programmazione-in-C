#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"



// Uso una dfs per visitare un grafo G, e poi ad ogni arco
// verifico che esiste lo stesso arco in H, e sottraggo il peso di
// (u,v) in H a quello (u,v) in G



// Passo una lista di adiacenza e il target, se esiste v in adj allora ritorno il peso
// altrimenti ritorno -1, per ipotesi i pesi sono tutti positivi
int RicercaArco(List adj,int v)
{
  if (adj)
    {
      if (adj->target==v)
  return adj->peso;
      else return RicercaArco(adj->next, v);
    }
  return -1;
}


//qui elimina arco se negativo e G cambia gli archi
void DFS_Visit(Graph G, Graph H, int u, int *C)
{
  C[u]='g';
  int v,peso,pesofinale;
  List adjG=G->adj[u];
  List adjH=H->adj[u];
  while(adjG)
    {
      v=adjG->target;
      peso=RicercaArco(adjH,v);
      if ( peso > 0)
  {
    pesofinale=adjG->peso-peso;
    if (pesofinale < 0)
      adjG=removeEdge(G,u,v);
    else
      adjG->peso=pesofinale;
  }
      
      if (C[v]=='w')
  DFS_Visit(G,H,v,C);
      adjG=adjG->next;
    }
  
}

void DFS(Graph G,Graph H)
  
{
  int C[G->nodes_count];
  for ( int i = 0; i< G->nodes_count; i++)
    C[i]='w';
  for ( int u = 0; u < G->nodes_count; u++)
    {
      if  (C[u]=='w')
  DFS_Visit(G,H,u,C);
    }
}

int main ()
{
  srand(time(NULL));
  int vertici=rand() % 9;
  Graph G=graphCreationMenu(15);
  Graph H=graphCreationMenu(15);
  printGraph(G);
  printGraph(H);
  DFS(G,H);
  printGraph(G);
  return 0;
}

