#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* Siano G e H due grafi non orientati pesati entrambi con pesi positivi, di n vertici 0, 1,…,
n-1 e rappresentati con liste di adiacenza utilizzando la seguente struttura:

scrivere in linguaggio C tre funzioni che in successione, presi in input i due grafi G e H,
a. Sostituiscano tutti gli archi in G e H in modo che ogni arco (a, b) in G abbia peso
a+b in G, e a*b in H
b. Per ogni arco (a, b) in G e H, rimuovano l’arco in G se la somma dei due pesi è
dispari e da H in caso contrario.
c. Preso m come input, controllino se esiste un sottografo di G, di m nodi, fortemente
connesso
d. Studiare la complessità delle funzioni implementate.  */



// Uso una dfs per visitare un grafo G, e poi ad ogni arco
void DFS_A(Graph G,Graph H)
  
{
  int C[G->nodes_count];
  for ( int i = 0; i< G->nodes_count; i++)
    C[i]='w';
  for ( int u = 0; u < G->nodes_count; u++)
    {
      if  (C[u]=='w')
  DFS_Visit_A(G,H,u,C);
    }
}

//modifica archi
void DFS_Visit_A(Graph G, Graph H, int u, int *C)
{
  C[u]='g';
  int v,peso,pesofinale;
  List adjG=G->adj[u];
  List adjH=H->adj[u];

  while(adjG)
  {
      v=adjG->target;
      pesoH=RicercaArco(adjH,v);
      if ( pesoH != (u*v))
      {
         H->adj[u]->peso = u*v;
      }
      
      if(adjG->peso != (u+v))
      {
        G->adj[u]->peso = u+v;
      }
      
    if (C[v]=='w')
     DFS_Visit_A(G,H,v,C);
        adjG=adjG->next;
  }
}


// Passo una lista di adiacenza e il target, se esiste v in adj allora ritorno il peso
// altrimenti ritorno -1, per ipotesi i pesi sono tutti positivi
int RicercaArco(List adj,int v)
{
  if (adj)
    {
      if (adj->target==v)
         return adj->peso;
      else 
         return RicercaArco(adj->next, v);
    }
  return -1;
}






int main ()
{
  srand(time(NULL));
  int vertici=rand() % 9;
  Graph G=graphCreationMenu(5);
  Graph H=graphCreationMenu(5);
  printGraph(G);
  printGraph(H);
  DFS_A(G,H);
  printGraph(G);
  printGraph(H);
  return 0;
}