#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"
#include <string.h>

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




void DFS_A(Graph G,Graph H);
void DFS_Visit_A(Graph G, Graph H, int u, int *C);
void DFS_B(Graph G,Graph H);
void DFS_Visit_B(Graph G, Graph H, int u, int *C);
int RicercaArco(List adj,int v);
int acquisisci_int();
int CFC (Graph G, int m);
void DFS1(Graph G, int *C);
void DFS_Visit1(Graph G, int u, int *C);
Graph Trasposto(Graph G);
List DFS2(Graph G, int *C);
void DFS_Visit2(Graph G, int u, int *D, int *C, List L);
void lunghezzaL(List L, int count);


int main ()
{
  
  Graph G=graphCreationMenu(5);
  Graph H=graphCreationMenu(5);
  printf("\nGrafo G: \n");
  printGraph(G);
  printf("\nGrafo H: \n");
  printGraph(H);

  //punto A
  DFS_A(G,H);

  printf("\nGrafo G: \n");
  printGraph(G);
  printf("\nGrafo H: \n");
  printGraph(H);

  //punto B
  DFS_B(G,H);

  printf("\nGrafo G: \n");
  printGraph(G);
  printf("\nGrafo H: \n");
  printGraph(H);


  printf("\nInserire numero nodi m per ricerca sottografo di G: ");
  int m = acquisisci_int();
  int flag = CFC(G,m);

  if (flag ==1)
   printf("\nIl Grafo G ha un sottografo di dimensione %d che è una CFC\n",m);
  else
     printf("\nIl Grafo G NON ha un sottografo di dimensione %d che è una CFC\n",m);

  return 0;
}



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
  int v,pesoH,pesofinale;
  List adjG=G->adj[u];
  List adjH=H->adj[u];

  while(adjG)
  {
      v=adjG->target;
      pesoH=RicercaArco(adjH,v);
      if ( pesoH != (u*v) && pesoH != -1)
      {
         H->adj[u]->peso = u*v;
      }
      
      if(adjG->peso != (u+v) && pesoH != -1)
      {
        G->adj[u]->peso = u+v;
      }
      
    if (C[v]=='w')
     DFS_Visit_A(G,H,v,C);
        adjG=adjG->next;
  }
}

//modifica archi B
void DFS_Visit_B(Graph G, Graph H, int u, int *C)
{
  C[u]='g';
  int v,pesoH,pesofinale;
  List adjG=G->adj[u];
  List adjH=H->adj[u];

  while(adjG)
  {
      v=adjG->target;
      pesoH=RicercaArco(adjH,v);
      if ( pesoH%2==0 && pesoH != -1)
      {
         adjH=removeEdge(H,u,v);
      }
      else if(pesoH%2!=0 && pesoH != -1)
      {
        adjG=removeEdge(G,u,v);
      }
      
    if (C[v]=='w')
     DFS_Visit_B(G,H,v,C);
        adjG=adjG->next;
  }
}

// Uso una dfs per visitare un grafo G, e poi ad ogni arco
void DFS_B(Graph G,Graph H)
{
  int C[G->nodes_count];
  for ( int i = 0; i< G->nodes_count; i++)
    C[i]='w';
  for( int u = 0; u < G->nodes_count; u++)
    {
      if  (C[u]=='w')
  DFS_Visit_B(G,H,u,C);
    }
}

/** Funzione acquisisci_int
 * Descrizione:
 * E' un controllo dell'input, finchè non è inserito un intero 
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

//conponente fortemente connessa
int CFC (Graph G, int m)
{
  
    int count=0;
    int C[G->nodes_count];

    printf("\nCFC: inizio DFS1");
    DFS1(G,C);
    printf("\nCFC: fine DFS1");
    Graph Gt = Trasposto(G);
    printf("\nCFC: inizio DFS2");
    List L = DFS2(Gt,C);
    printf("\nCFC: fine DFS2");

    lunghezzaL(L,count);
    printf("\nfine count");
    if (count == m)
      return 1;
    return 0;
} 

void DFS1(Graph G, int *C)
{
  

  for ( int i = 0; i< G->nodes_count; i++)
    C[i]='w';
  for( int u = 0; u < G->nodes_count; u++)
    {
      if  (C[u]=='w')
       
  DFS_Visit1(G,u,C);
    }
}

//modifica archi B
void DFS_Visit1(Graph G, int u, int *C)
{
  C[u]='g';
  int v,pesoH,pesofinale;
  List adjG=G->adj[u];


  while(adjG)
  {
      v=adjG->target;
    if (C[v]=='w')
     DFS_Visit1(G,v,C);
        adjG=adjG->next;
  }

  C[u]='b';
}

//grafo trasosto
Graph Trasposto(Graph G)
{
  Graph GT=NULL;
  List adj=NULL;

  if (G)
    {
     
      GT= initGraph(G->nodes_count);
      for ( int i = 0; i < G->nodes_count; i++)
    {
      adj = G->adj[i];
      while( adj )
        {
          int v = adj->target;
          int peso =adj->peso;
          addEdge(GT,v,i,peso);
          adj=adj->next;
        }
    }
     
    }
  return GT;
}

List DFS2(Graph G, int *C)
{
  int D[G->nodes_count];
  List L=NULL;

  for ( int i = 0; i< G->nodes_count; i++)
    D[i]='w';
  for( int u = 0; u < G->nodes_count; u++)
    {
      if  (D[u]=='w')
        DFS_Visit2(G,u,D,C,L);
    }

    return L;
}

//modifica archi B
void DFS_Visit2(Graph G, int u, int *D, int *C, List L)
{
  printf("\nvisit2");
  D[u]='g';
  if (C[u] == 'b')
    L = addNodeList(L,u,0);

  int v,pesoH,pesofinale;
  List adjG=G->adj[u];

  while(adjG)
  { 
      v=adjG->target;
    if (D[v]=='w')
      DFS_Visit2(G,v,D,C,L);
        adjG=adjG->next;
  }

  D[u]='b';
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

void lunghezzaL(List L, int count)
{
  printf("cucu %d",count);
  if(L){
    printf("cucu %d",count);
    count++;
    lunghezzaL(L->next,count);
  }
}
