#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "inputReader.h"
#include "list.h"

#include <time.h>
#include <string.h>

/*Siano G e H due grafi orientati pesati
presi in input G e H e una lista doppiamente puntata e non circolare,
con input da tastiera sia per i grafi che per la lista (!!!), 
permetta di fare l'unione in un terzo grafo T, 
tale per cui l'arco (a,b) con peso p è inserito in T se (a,b) con peso positivo è presente sia in G e H,
p è la somma dei relativi pesi ed inoltre il valore p è presente nella lista da dove deve essere rimosso.
I grafi G ed H non devono essere modificati, la lista invece si può modificare. 

Grafo T e lista modificata vanno stampati alla fine delle operazioni. 
Si noti che se esiste un solo valore p nella lista, allora due archi con peso p non possono essere inseriti in T.
La complessità della funzione creaT dovrebbe essere O(V⋅E+N))     */


struct elemento{
  struct elemento *prev, *next;
  int target;
};

typedef struct elemento* Lista;

Graph DFS(Graph G, Graph H, Lista l);
void DFS_Visit(Graph G, Graph H,Graph T,Lista* L, int u, int *C);
int RicercaArco(List adj,int v);
Lista searchAndRemove(int val, Lista l, int *status);
Lista acquireLista();
Lista append(Lista L, int value);
void printLista(Lista L);



int main ()
{
  srand(time(NULL));
  int vertici=rand() % 9;
  Graph G=graphCreationMenu(6);
  Graph H=graphCreationMenu(6);
  printf("\nGRAFO G\n");
  printGraph(G);
  printf("\nGRAFO H\n");
  printGraph(H);
  
  //inizializza lista
  Lista L = NULL;
  int i,index,elem;
  L = acquireLista();
  printf("\nLISTA:\n");
  printLista(L);  


  Graph T = DFS(G,H,L);
  
  printf("\n\n");
  printf("\nGRAFO T\n");
  printGraph(T);
  printf("\n\n");


  return 0;
}



void DFS_Visit(Graph G, Graph H,Graph T,Lista* L, int u, int *C)
{
  C[u]='g';
  int status=0;
  int v,pesoH,pesoG,pesofinale;
  List adjG=G->adj[u];
  List adjH=H->adj[u];
  
  
  while(adjG)
  {
      v=adjG->target;
      pesoG = adjG->peso;
      pesoH=RicercaArco(adjH,v);
      
      if ( pesoH > -1)
	 {
		  pesofinale=pesoG+pesoH;
		  
		  *L = searchAndRemove(pesofinale,*L,&status);
		  
		  //se peso era presente in L 
		  if (status==1)
		  {
		    addEdge(T,u,v,pesofinale);   
		  }
		  status=0;
	 }
      
      if (C[v]=='w')
		DFS_Visit(G,H,T,L,v,C);
		
      adjG=adjG->next;
   }
  
  //return T;
}

Graph DFS(Graph G,Graph H,Lista L) 
{
  int C[G->nodes_count];
  Graph T = NULL;
  T = initGraph(G->nodes_count);
  
  for ( int i = 0; i< G->nodes_count; i++)
    C[i]='w';
    
  for ( int u = 0; u < G->nodes_count; u++)
    {
      if (C[u]=='w')
		DFS_Visit(G,H,T,&L,u,C);
    }
    
    printf("\nLISTA MODIFICATA:");
    printLista(L); 
    return T;
}


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


// Questa è la funzione che
// cerca ed elimina un nodo dalla lista d.p. .
Lista searchAndRemove(int val, Lista l, int *status){
    Lista tmp=NULL;
    if(l!=NULL)
    {
        l->next = searchAndRemove(val,l->next,status);
        
        if(*status!=1 && l->target == val)
        {
            if(l->prev)
                l->prev->next=l->next;
            if(l->next)
                l->next->prev=l->prev;
            tmp=l;
            *status=1;
            l=l->next;
            free(tmp);
        }
    }
    return l;
}

Lista acquireLista(){
  int val;
  Lista L = NULL;
  printf("Inserisci una lista di interi da accodare alla lista terminata da un char\n");
  while(scanf("%d",&val)>0)
    L=append(L,val);
  scanf("%*[^\n]");
  return L;
}

Lista append(Lista L, int value){
  if(L){
    L->next = append(L->next, value);
    L->next->prev = L;
  }
  else{
    L =(Lista)calloc(1,sizeof(struct elemento));
    L->target = value;
  }
  return L;
}


//stampa di una lista
void printLista(Lista L)
{
  if (L)
  {
      if (L->prev == NULL)
        printf("Testa->[%d]",L->target);  
      else
        printf("->[%d]", L->target);
     
      printLista(L->next);
   }
  printf("\n");
}












#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../Librerie/Input/inputReader.h"
#include "../Librerie/Queue/queue.h"
#include "../Librerie/List/list.h"
#include "../Librerie/Graph/graph.h"
#include <time.h>
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

  //punto C
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
      if ( (adjG->peso + pesoH)%2==0 && pesoH != -1)
      {
         adjH=removeEdge(H,u,v);
      }
      else if((adjG->peso + pesoH)%2!=0 && pesoH != -1)
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





//controlla se Grafi uguali

//controlla se liste uguali
int equalsList(List G,List H)
{
  if(!G && !H)
  	return 1;
  
  if (G && H && (G->target == H->target))
         return equalsList(G->next, H->next);
 
  return 0;
};


//Controlla che g e H sono uguali
int checkGraphEquals(Graph G,Graph H)
{
  if (!G && !H)
  	return 1;
  
  else if (G && H && (G->nodes_count == H->nodes_count))
  {
  	for ( int u = 0; u < G->nodes_count; u++)
    {
  		List adjG = G->adj[u];
  		List adjH = H->adj[u];
  		
  		if (!equalsList(adjG,adjH))
  			return 0;
  			
  		return 1;
    }
  }
  
  return 0;
};






//T con incidenti e adiacenti
/*
Scrivere in linguaggio C una funzione che presi in input i grafi G e H, restituisca un
nuovo grafo T con la stessa struttura in modo tale T ha l arco (a,b) se esso è presente
sia in G che in H e il suo peso è dato dalla somma de il
grado adiacente di a più il grado incidente di b in H.
*/


#include <stdio.h>
#include <stdlib.h>
#include "../Librerie/Input/inputReader.h"
#include "../Librerie/Graph/graph.h"
#include <time.h>
#include <string.h>



Graph Trasposto(Graph G);
int RicercaArco(List adj,int v);
void DFS_Visit_A(Graph G, Graph H,Graph T, int u, int *C);
Graph DFS_A(Graph G,Graph H);
int scorriListaCount(List L);

int main ()
{
  srand(time(NULL));
  int vertici=rand() % 9;
  Graph G=graphCreationMenu(5);
  Graph H=graphCreationMenu(5);
  printGraph(G);
  printGraph(H);
  
  int *adiacenti=NULL;
  int *incidenti=NULL;
  Graph T = NULL;
  
  T = DFS_A(G,H);
  printGraph(T);
  return 0;
}




// Uso una dfs per visitare un grafo G, e poi ad ogni arco
Graph DFS_A(Graph G,Graph H) 
{
  int C[G->nodes_count];
  Graph T = initGraph(G->nodes_count);
  
  for ( int i = 0; i< G->nodes_count; i++)
    C[i]='w';
  for ( int u = 0; u < G->nodes_count; u++)
    {
      if  (C[u]=='w')
 		DFS_Visit_A(G,H,T,u,C);
    }
    
    return T;
}


//modifica archi
void DFS_Visit_A(Graph G, Graph H,Graph T, int u, int *C)
{
  C[u]='g';
  int v,pesoH,pesoG,adiacentiU,incidentiV;
  List adjG=G->adj[u];
  List adjH=H->adj[u];
  List tmp = adjG;
  Graph GT = NULL;
  
  while(adjG)
  {
      v=adjG->target;
      pesoG = adjG->peso;
      pesoH=RicercaArco(adjH,v);
      
      if ( pesoH > -1)
      {	
         adiacentiU = scorriListaCount(adjG);
         GT=Trasposto(H);
         incidentiV = scorriListaCount(GT->adj[v]);
         addEdge(T,u,v,adiacentiU + incidentiV);
      }
      
    if (C[v]=='w')
     DFS_Visit_A(G,H,T,v,C);
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


Graph Trasposto(Graph G){
  List L=NULL;
  int i,size= G->nodes_count;
  Graph A= initGraph(size);
  if( G != NULL){
    for(i=0 ; i < size; i++){
      L=G->adj[i];
      while( L != NULL){
        addEdge(A, L->target, i, L->peso);
        L=L->next;  
      }
    }
  }
  return A;
}


int scorriListaCount(List L)
{	int x=0;
	while(L)
	{
		x++;
		L=L->next;
	}
	return x;		
}





//iuriiiiiii

//calcoli incidenti e adiacenti e T se sian in G che H ci sta arco
#define VERTEX_NUM 1

int foundIsolato(Graph G);
int *calcolaGrado(Graph G);
void INIT(int *array, int size);
Graph Trasposto(Graph G);
Graph DFS(Graph G, Graph H);
int foundEdge(List Adj, int target, int peso);


int main(){
  int i;
  int *uscenti=NULL, *entranti=NULL;
  Graph G=NULL, GT=NULL;
  G = randomGraph(VERTEX_NUM);

  printGraph(G);
  uscenti=calcolaGrado(G);
  GT=Trasposto(G);
  entranti=calcolaGrado(GT);

  for(i=0; i < VERTEX_NUM; i++){
    printf("%d ", uscenti[i]);
  }

  printf("\n");
  for(i=0; i < VERTEX_NUM; i++){
    printf("%d ", entranti[i]);
  }

  printf("\n");
  printf("Isolato: %d\n", foundIsolato(G));
  free(entranti);
  free(uscenti);
  
  return 0;
}


void INIT(int *array, int size){
  int i;
  for(i=0; i < size; i++){
    array[i]=0;
  }
}

void _calcolaGrado(Graph G, int u, int *color ,int *degree){
  List adjG=NULL;
  int v;
  color[u]= 'g';
  adjG =G->adj[u];
  while( adjG ){
    degree[u]++;
    v = adjG->target;

    if(color[v] == 'w')
    {
      _calcolaGrado(G, v, color, degree);
    }
    adjG=adjG->next;
  }
  color[u]= 'b';
}

int *calcolaGrado(Graph G){
  int i, size= G->nodes_count;
  int *degree=(int*)malloc(size*sizeof(int));
  int color[size];
  INIT(color, size);  
  for(i=0; i < size; i++){
    _calcolaGrado(G, i, color, degree);
  }
  return degree;
}

int foundIsolato(Graph G){
  Graph GT=NULL;
  int sum, i,size=G->nodes_count;
  int *entranti= (int*)malloc(size*sizeof(int)), *uscenti=(int*)malloc(size*sizeof(int));
  uscenti=calcolaGrado(G);
  GT=Trasposto(G);
  entranti=calcolaGrado(GT);

  for(i=0; i < size; i++){
    sum=entranti[i]+uscenti[i];
    if( sum == 0){
      free(entranti);
      free(uscenti);
      return 1;
    }
  }
  free(entranti);
  free(uscenti);
  return 0;
}

Graph Trasposto(Graph G){
  List L=NULL;
  int i,size= G->nodes_count;
  Graph A= initGraph(size);
  if( G != NULL){
    for(i=0 ; i < size; i++){
      L=G->adj[i];
      while( L != NULL){
        addEdge(A, L->target, i, L->peso);
        L=L->next;  
      }
    }
  }
  return A;
}


//crea T se ci sta arco da H e G 
void _DFS(Graph G, Graph H, Graph T, int u, int *color){
  int v;
  List adjG=NULL;
  color[u]= 'g';
  adjG= G->adj[u];
  
  while( adjG){
    v=G->adj[u]->target;
    if(color[v] == 'w'){
      _DFS(G, H, T, v, color);
      if(foundEdge(H->adj[u], G->adj[u]->target, G->adj[u]->peso ) ){
        addEdge(T, u, G->adj[u]->target, (G->adj[u]->peso - H->adj[u]->peso) );
      }
    }
    adjG=adjG->next;
  } 
  color[u]= 'b';
}

Graph DFS(Graph G, Graph H){
  Graph T=NULL;
  int i, *color= (int*)malloc(VERTEX_NUM*sizeof(int));
  for( i=0 ; i < VERTEX_NUM; i++){
    _DFS(G, H, T, i, color);    
  }
  return T;
}


int foundEdge(List Adj, int target, int peso){
  while( Adj != NULL )
  {
    if(Adj->target == target && Adj->peso == peso){
      return 1;
  }
    Adj=Adj->next;
  }
  return -1;  
}








//incidenti adiacenti

/*Sia G un grafo orientato e pesato con nodi 0..n-1. Si calcoli il grado entrante/uscente. 
Inoltre, dato in input da tastiera un nodo x, 
a) rimuovere fisicamente il nodo se la somma dei suoi archi entranti è maggiore di quelli uscenti.
b) per ogni arco (a,x) con peso p1 e (x,b) con peso p2, si consideri l'arco (a,b) con peso p=p1+p2.
Se tale arco (a,b) non è presente o è presente con peso minore, si aggiunga a G l'arco (a,b) con peso p
*/


//main
	printGraph(G);
	inDeg = (int *)calloc(G->nodes_count,sizeof(int));
	outDeg = (int *)calloc(G->nodes_count,sizeof(int));
	printf("\nCALCOLO GRADI\n\n");
	calcolaGradi(G,inDeg,outDeg);
	stampaGradi(G,inDeg, outDeg);
	
	printf("\nInserisci il nodo x: [0,%d]: ",G->nodes_count-1);
	x = acquireIntegerRange(0,G->nodes_count-1);
	//modificaArchi(G,x);
	modificaArchi2(G,x);
	if(inDeg[x]>outDeg[x])
		removeNode(G,x);
		

void modificaArchi2(Graph G, int x){
	//TODO CONTROLLARE SE G NULL
	Graph GT = transpose(G);
	List edge1 = NULL, edge2 = NULL;
	for(edge1 = GT->adj[x] ; edge1 ; edge1 = edge1->next){
		for(edge2 = G->adj[x] ; edge2 ; edge2 = edge2->next){
			G->adj[edge1->target] = addEdgeUpgrade(G->adj[edge1->target], edge2->target, edge1->peso+edge2->peso);
		}
	}
	freeGraph(GT);
}

Graph transpose(Graph G){
  Graph T = NULL;
  if(G){
    int i = 0;
    List curr = NULL;
    T = initGraph(G->nodes_count);
    for( ; i < G->nodes_count ; i++)
      for( curr = G->adj ; curr ; curr = curr->next )
        addEdge(T, curr->target, i, curr->peso);
  }
	return T;
}

void modificaArchi(Graph G, int x){
	//TODO CONTROLLARE se G NULL
	int i = 0;
	List edge1 = NULL, edge2 = NULL;
	for( ; i<G->nodes_count;i++){ //per ogni vertice
		for(edge1 = G->adj ; edge1 ; edge1 = edge1->next){ 
			if(edge1->target == x){
				for(edge2 = G->adj[x] ; edge2 ; edge2 = edge2->next){
					G->adj = addEdgeUpgrade(G->adj, edge2->target, edge1->peso+edge2->peso);
				}
				break; //posso interrompere scorrimento lista di i	
			}
		}
	}
}

void calcolaGradi(Graph G, int * inDeg, int * outDeg){
	int i = 0;
	List edge = NULL;
	for( ; i<G->nodes_count ; i++){
		for(edge = G->adj; edge ; edge = edge->next){
			inDeg[edge->target]++;
			outDeg++;
		}
	}
}

void stampaGradi(Graph G, int * inDeg, int * outDeg){
	int i = 0;
	for( ; i<G->nodes_count; i++){
		printf("NODO %2d - GRADO IN: %2d - GRADO OUT: %2d\n",i,inDeg,outDeg);
	}
}






















#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "inputReader.h"
#include "list.h"

#include <time.h>
#include <string.h>

/*Siano G e H due grafi orientati pesati
presi in input G e H e una lista doppiamente puntata e non circolare,
con input da tastiera sia per i grafi che per la lista (!!!), 
permetta di fare l'unione in un terzo grafo T, 
tale per cui l'arco (a,b) con peso p è inserito in T se (a,b) con peso positivo è presente sia in G e H,
p è la somma dei relativi pesi ed inoltre il valore p è presente nella lista da dove deve essere rimosso.
I grafi G ed H non devono essere modificati, la lista invece si può modificare. 
Grafo T e lista modificata vanno stampati alla fine delle operazioni. 
Si noti che esiste un solo valore p nella lista, allora due archi con peso p non possono essere inseriti in T.
La complessità della funzione creaT dovrebbe essere O(V⋅E+N))     */


Graph DFS(Graph G, Graph H, List l);
void DFS_Visit(Graph G, Graph H,Graph T,List* L, int u, int *C);
int RicercaArco(List adj,int v);
List searchAndRemove(int val, List l, int *status);

int main ()
{
  srand(time(NULL));
  int vertici=rand() % 9;
  Graph G=graphCreationMenu(6);
  Graph H=graphCreationMenu(6);
  printf("\nGRAFO G\n");
  printGraph(G);
  printf("\nGRAFO H\n");
  printGraph(H);
  
  //inizializza lista
  List L=NULL;
  int i,index,elem;
  printf("\nQuanti elementi ha la lista? ");
  scanf("%d",&index);
  for (i = 0; i < index; i++) 
  {
  	   printf("Elemento %d: ",i);
  	   scanf("%d",&elem);
        L = appendNodeList(L,elem,0);
  }
  printf("\nLISTA:\n");
  printList(L);  


  Graph T = DFS(G,H,L);
  
  printf("\n\n");
  printf("\nGRAFO T\n");
  printGraph(T);
  printf("\n\n");


  return 0;
}



void DFS_Visit(Graph G, Graph H,Graph T,List* L, int u, int *C)
{
  C[u]='g';
  int status=0;
  int v,peso,pesofinale;
  List adjG=G->adj[u];
  List adjH=H->adj[u];
  

  
    
  while(adjG)
    {
      v=adjG->target;
      peso=RicercaArco(adjH,v);
      if ( peso > 0)
	 {
		  pesofinale=adjG->peso+peso;
		  
		  *L = searchAndRemove(pesofinale,*L,&status);
		  
		  if (status==1)
		  {
		    addEdge(T,u,v,peso);
		    
		  }
		  status=0;
	 }
      
      if (C[v]=='w')
		DFS_Visit(G,H,T,L,v,C);
		
      adjG=adjG->next;
    }
  
  //return T;
}

Graph DFS(Graph G,Graph H,List L) 
{
  int C[G->nodes_count];
  Graph T = NULL;
  T = initGraph(G->nodes_count);
  for ( int i = 0; i< G->nodes_count; i++)
    C[i]='w';
    
  for ( int u = 0; u < G->nodes_count; u++)
    {
      if (C[u]=='w')
		DFS_Visit(G,H,T,&L,u,C);
    }
    printf("\nLISTA MODIFICATA:");
    printList(L); 
    return T;
}


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


// Questa è la funzione che
// cerca ed elimina un nodo dalla lista d.p. .
List searchAndRemove(int val, List l, int *status){
    List tmp=NULL;
    if(l!=NULL)
    {
        l->next = searchAndRemove(val,l->next,status);
        
        if(*status!=1 && l->target == val)
        {
            if(l->prev)
                l->prev->next=l->next;
            if(l->next)
                l->next->prev=l->prev;
            tmp=l;
            *status=1;
            l=l->next;
            free(tmp);
        }
    }
    return l;
}





/* 
A. input i due grafi G e H costruisca
	un terzo grafo T ( e lo restituisca) in cui l’arco (a,b) è presente se è presente sia in G
	che in H, oppure in nessuno dei due. Nel primo caso prenderà come peso la somma dei
	pesi dei relativi archi in G e H. Nel secondo caso, prenderà peso ­1
B. Scrivere una funzione in C che verifichi che per ogni nodo di G e H, il grado incidente
in G è uguale al grado adiacente in H.
*/

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
  for( ; i<G->nodes_count ; i++){grado
    for(curr = G->adj[0] ; curr ; curr=curr->next )
      app[curr->target]++;
    for(curr = H->adj[0] ; curr ; currgrado=curr->next )
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







/*GIAMMARCOOOOOOOOOO

scrivere in linguaggio C una funzione che, presi in input G e H e una lista doppiamente puntata e
non circolare, con input da tastiera sia per i grafi che per la lista (!!!), permetta di fare
l'intersezione in un terzo grafo T, tale per cui l'arco (a,b) con peso p è inserito in T se (a,b) con
peso positivo è presente sia in G e H, p è lo stesso valore dei pesi in entrambi i grafi e p è presente
nella lista da dove deve essere rimosso. I grafi G ed H non devono essere modificati, la lista invece
si può modificare. Grafo T e lista modificata vanno stampati alla fine delle operazioni

#include "graph.h"
#include "list.h"
#include "inputReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// LISTA DOPPIAMENTE CONCATENATA

struct LLista{

  int info;
  struct LLista *next;
  struct LLista *prev;
};
typedef struct LLista *Lista;

int CercaElemento(Lista L,int chiave)
{
  if ( L )
    {
      
      if ( L->info == chiave) return 1;
      else return CercaElemento(L->next,chiave);
    }
  return 0;
}
      
Lista CreaNodo(int chiave)
{
  Lista tmp=NULL;
  tmp=(Lista)malloc(sizeof(Lista));
  tmp->info=chiave;
  tmp->next=NULL;
  tmp->prev=NULL;
  return tmp;
}

Lista InserisciInTesta(Lista L,int chiave)
{
  Lista tmp=NULL;
  if (L)
    {
      tmp=CreaNodo(chiave);
      L->prev=tmp;
      tmp->next=L;
    }
  else
    {
      tmp=CreaNodo(chiave);
      tmp->next=NULL;
    }
  return tmp;
}

void Stampa(Lista L)
{
  if (L!=NULL)
    {
      if (L->prev == NULL) printf(" Testa->[%d]",L->info);
      
      else
  
      printf("->[ %d]", L->info);
     
      Stampa(L->next);
    }
  
}
void Elimina(Lista *L,int chiave)
{
  Lista tmp=NULL;
  Lista tmp2=NULL;
  if ( *L)
    {
      Elimina(&(*L)->next,chiave);
      if ( (*L)->info == chiave)
  {
    tmp=*L;
    if ((*L)->next)
      
      (*L)->next->prev = (*L)->prev;
      if ((*L)->prev)
    
  (*L)->prev->next=(*L)->next;
        else
    *L=(*L)->next;
  }
    }
      free(tmp);
}


// FUNZIONE GRAFO
int RicercaArco(List L,int u,int peso)
{
  if (L)
    {
      if (L->target==u && L->peso==peso) return 1;
      else return RicercaArco(L->next,u,peso);
    }
  return 0;
}
void DFS_visit(Graph G, Graph H, Graph T, Lista L, int *c,int u)
{
  c[u]='g';
  List adjG = G->adj[u];
  List adjH = H->adj[u];
  int trovato=0;
  int pesotro=0;
  while ( adjG )// Ciclo gli adiacenti di G[u]
    {
      int v = adjG->target;
      int peso = adjG->peso;
      
    trovato=RicercaArco(adjH,v,peso);
    if ( trovato > 0)
      {
        // esiste l'arco,trovo il peso nella lista
        pesotro=CercaElemento(L,peso);
        if ( pesotro > 0)
        addEdge(T,u,v,peso);
      }
    if ( c[v] == 'w')
  
    DFS_visit(G,H,T,L,c,v);
  
      adjG=adjG->next;
    }
  c[u]='n'; // Fine visita vertice
}
    
void DFS( Graph G, Graph H, Graph T, Lista L, int *c)
{
  for ( int u = 0; u < G->nodes_count; u++)
    {
      if ( c[u]=='w');
      DFS_visit(G,H,T,L,c,u);
    }
}
  
Graph FunzioneMaster ( Graph G, Graph H,Lista L)
{
  // Al massimo avra' i nodi di G e H
  Graph T = initGraph(G->nodes_count);
  if ( L )
    {
      // Inizializzazione
      int color[G->nodes_count];
      for ( int i = 0; i < G->nodes_count; i++)
  color[i]='w'; // 'white', non visitato
      DFS(G,H,T,L,color);
    }
  return T;
}
  
int main ()       
{
  srand((unsigned int)time(NULL));
  int nodi;
  Graph G;
  Graph H;
  Graph T;
  Lista L=NULL;
  printf("Inserire numero elementi lista:\n\n");
  scanf(" %d", &nodi);
  for (int i = 0 ; i < nodi; i++)
    
      
      L=InserisciInTesta(L,rand() % 50);
    
  Stampa(L);
  G=graphCreationMenu(nodi);
  H=graphCreationMenu(nodi);
  T=FunzioneMaster(G,H,L);
  printGraph(T);
  freeGraph(G);
  freeGraph(H);
  freeGraph(T);
  return 0;
}


*/





Graph funzioneUnisci (Graph G, Graph H)
{
  Graph P = NULL;

  if (G && H)
  {
    P = initGraph(G->nodes_count);
    Graph Gt = Trasposto(G);
    DFS(Gt,H,P);
  }
  return P;
}




// da grafo

void costruisciMatrice(Graph G, int ** M){
	int i = 0;
	List L = NULL;
	for( ; i<G->nodes_count ; i++)
		for(L=G->adj ; L ; L=L->next){
			M[L->target] = L->peso+1; //l'arco c'è, il +1 per distinguere pesi = 0
		}
}





void BFS ( Graph G, int sorgente)
{
  // Inizializzo
  int d[G->nodes_count];
  int pi[G->nodes_count];
  char color[G->nodes_count];// 'w' (bianco), 'g' ( grigio), 'b' (nero)
  int u,v;

  List maxPercorso=NULL;
  int maxPeso=0;


  for ( int i = 0; i < G->nodes_count; i++)
  {
      if ( i != sorgente)
	    {
    	  d[i]=inf;
    	  pi[i]=-1;
    	  color[i]='w';
	    }
      else // Sorgente
	    {
    	  d[i]=0;
    	  pi[i]=-1;
    	  color[i]='g';
    	}
  }

  // Dichiaro la coda
  Queue Q = initQueue();
  enqueue(Q,sorgente);

  // Ciclo principale
  while ( !emptyQueue(Q))
  {

      u = dequeue(Q);
      
      int pesotot=0;
      List adj= G->adj[u];
      // Scorro gli adiacenti di u
      while ( adj!=NULL)
	    {
      	  // Nodo adiacente
      	  v = adj->target;
      	  if ( color[v] == 'w')
      	  {
      	      color[v]='g';
      	      d[v]=d[u]+1;
      	      pi[v]=u;
      	      enqueue(Q,v);
      	  }

      	  adj =adj->next;
          pesotot+=adj->peso;
      }

      if (pesotot > maxPeso)
      {
        maxPeso = pesotot
        maxPercorso = adj;
      }
      color[u]== 'b';
  }

  // stampo array d[] e pi[]
  for ( int j = 0; j < G->nodes_count; j++)
    {
      printf(" d[%d] = '%d', pi[%d] = '%d'\n", j, d[j], j, pi[j]);
    }
}  





















































//LISTEEEEEEEE

//controlla se liste uguali
int equalsList(List G,List H)
{
  if(!G && !H)
  	return 1;
  
  if (G && H && (G->target == H->target))
         return equalsList(G->next, H->next);
 
  return 0;
};



//starac

#include <stdio.h>
#include <stdlib.h>

/*
Si   considerino   due   liste   di   numeri   interi  Lista1   e   Lista2  implementate   come   liste
doppiamente puntate e non circolari, utilizzando la seguente struttura 

struct elemento {
  struct elemento *prev;
  int inf;
  struct elemento *next;} 
struct elemento *Lista1,*Lista2;

a. Si   implementi   una   sola   funzione  ricorsiva  (che   eventualmente   può   richiamare
sottofunzioni) che rimuova sia da Lista1 che da Lista2 tutte le occorrenze di numeri
negativi.
b. Dato un valore x, scrivere una funzione ricorsiva che, verificata l’esistenza di x in
Lista1, inserisca Lista2 prima di x (in Lista1) e restituisca Lista1 così modificata. Se x
non esiste in Lista1, accodare Lista2 a Lista1. 
*/

struct elemento{
  struct elemento *prev, *next;
  int inf;
};

typedef struct elemento* List;

List acquireList();
List append(List L, int value);
void printList(List L);

void rimuoviNegativi(List *L1, List *L2);
void removeNode(List * target);
void modificaListe(List *L1, List *L2, int x);
void aggiungiAvanti(List *L1, List L2);
List duplicaLista(List L);
List duplicaLista2(List L, List app);

int main(int argc, char *argv[]) {
  int x = 0;
  struct elemento *L1 = NULL, *L2 = NULL;
  printf("ACQUISIZIONE LISTA 1\n\n");
  L1 = acquireList();
  printf("\nACQUISIZIONE LISTA 2\n\n");
  L2 = acquireList();
  printf("\nLISTA 1: ");
  printList(L1);
  printf("LISTA 2: ");
  printList(L2);
  printf("\nRIMUOVO NEGATIVI\n\n");
  rimuoviNegativi(&L1,&L2);
  printf("LISTA 1: ");
  printList(L1);
  printf("LISTA 2: ");
  printList(L2);
  printf("\nMODIFICA LISTE\n\n");
  printf("Inserisci x: ");
  scanf("%d",&x);
  modificaListe(&L1, &L2, x);
  printf("LISTA 1: ");
  printList(L1);
  printf("LISTA 2: ");
  printList(L2);
  return 0;
}



void modificaListe(List *L1, List *L2, int x){
  if(*L1){
    if( (*L1)->inf == x ){ // trovato x in lista 1
      aggiungiAvanti(L1,*L2);
    }
    else if( (*L1)->next == NULL){
      (*L1)->next = duplicaLista(*L2);
      if( (*L1)->next )
        (*L1)->next->prev = (*L1);
    }
    else
      modificaListe( &(*L1)->next, L2, x);
  }
}

void aggiungiAvanti(List *L1, List L2){
  List tmp = NULL;
  if(L2){
    aggiungiAvanti(L1,L2->next);
    tmp = (List)calloc(1,sizeof(struct elemento));
    tmp->inf = L2->inf;
    printf("AGG: %d\n",L2->inf);
    tmp->next = *L1;
    tmp->prev = (*L1)->prev;
    if( (*L1)->prev ){
      (*L1)->prev->next = tmp;
    }
    else
      (*L1)=tmp;
    //(*L1)->prev = tmp;
  }
}

List duplicaLista2(List L, List app){
  List L2 = NULL;
  if(L){
    L2 = (List)calloc(1, sizeof(struct elemento));
    L2->inf = L->inf;
    L2->next = duplicaLista2(L->next,app);
    if(L2->next)
      L2->next->prev = L2;
    else L2->next = app;
  }
  return L2;
}

List duplicaLista(List L){
  List L2 = NULL;
  if(L){
    L2 = (List)calloc(1, sizeof(struct elemento));
    L2->inf = L->inf;
    L2->next = duplicaLista(L->next);
    if(L2->next)
      L2->next->prev = L2;
  }
  return L2;
}

void rimuoviNegativi(List *L1, List*L2){
  if(*L1 && *L2){
    rimuoviNegativi( &(*L1)->next, &(*L2)->next );
    if( (*L1)->inf < 0) //rimuovere L1
      removeNode(L1);
    if( (*L2)->inf < 0)
      removeNode(L2);
  }
  else if(*L1){
    rimuoviNegativi( &(*L1)->next, L2);
    if( (*L1)->inf < 0) //rimuovere L1
      removeNode(L1);
  }
  else if(*L2){
    rimuoviNegativi( L1, &(*L2)->next);
    if( (*L2)->inf < 0) //rimuovere L1
      removeNode(L2);
  }
}

/*


void rimuoviEl(List *L1, List*L2, int el){
  if(*L1 && *L2){
    rimuoviEl( &(*L1)->next, &(*L2)->next,el);
    if( (*L1)->inf == el) //rimuovere L1
      removeNode(L1);
    if( (*L2)->inf == el )
      removeNode(L2);
  }
  else if(*L1){
    rimuoviEl( &(*L1)->next, L2,el);
    if( (*L1)->inf == el) //rimuovere L1
      removeNode(L1);
  }
  else if(*L2){
    rimuoviEl( L1, &(*L2)->next,el);
    if( (*L2)->inf == el) //rimuovere L1
      removeNode(L2);
  }
}


*/
void removeNode(List * target){
  struct elemento * tmp = *target;
  if( (*target)->next ){
    (*target)->next->prev = (*target)->prev;
  }
  if( (*target)->prev ){
    (*target)->prev->next = (*target)->next;
  }
  else{
    (*target) = (*target)->next;
  }
  free(tmp);
}

List acquireList(){
  int val;
  List L = NULL;
  printf("Inserisci una lista di interi da accodare alla lista terminata da un char\n");
  while(scanf("%d",&val)>0)
    L=append(L,val);
  scanf("%*[^\n]");
  return L;
}

List append(List L, int value){
  if(L){
    L->next = append(L->next, value);
    L->next->prev = L;
  }
  else{
    L =(List)calloc(1,sizeof(struct elemento));
    L->inf = value;
  }
  return L;
}

//stampa di una lista
void printList(List L)
{
  if (L)
  {
      if (L->prev == NULL)
        printf("Testa->[%d]",L->inf);  
      else
        printf("->[%d]", L->inf);
     
      printList(L->next);
   }
  printf("\n");
}










// Elimina pari o dispari dalla lista
void EliminaPariDispari(Lista *L,int a)
{
  if (*L)
    {
       EliminaPariDispari(&(*L)->next,a);
      if ( (*L)->info %2==a)
  
    Elimina(&(*L),(*L)->info);
     
    }
}


void InterLeaving(Lista *L, Lista *P)
{
  Lista tmp=NULL;
  Lista tmp3=NULL;
  if (*L && *P)
    {
      tmp=(*P)->next;
      (*P)->next=(*L);
      (*L)->prev=(*P);
      InterLeaving(&(*L)->next,&(tmp));
    }
}    



int Ricerca(Lista L,int info)
{
  if (L)
    {
      if (L->info == info )
  return 1;
      else
  return Ricerca(L->next,info);
    }
  return 0;
}




























// CODEEEEEEEEEE




// ELIMINA DISPARI DALLA CODA
// T(n)=O(|DimQueue(Q)|)

void EliminaDispari(Queue Q)
{
  int q;
  if ( !emptyQueue(Q))
    {
       q=dequeue(Q);
       EliminaDispari(Q);
       if ( q%2==0)
  enqueue(Q,q);
         
     
    }
}



//elimina da dietro se mod  %2  = turno
void gioco (Queue Q1, Queue Q2){

  int i=0;
  int j=0;
  int turno = 1;
  int n1 = dimQueue(Q1);
  int n2 = dimQueue(Q2);

  if ( n1 == n2){

    do{
      int mod = (Q1->A[n1] + Q2->A[n2]);
      printf("\n");
      printf("%d",mod);
      printf("\n");

      if (mod%2 == turno){
        reverseQueue(Q2);
        int put = dequeue(Q2);
        reverseQueue(Q2);
        printQueue(Q2);
      }else{
        reverseQueue(Q1);
        int put = dequeue(Q1);
        reverseQueue(Q1);
        printQueue(Q1);
      }
      n1--;
      n2--;
      turno++;
    }while ((n1 != 0) || (n2 != 0));

  int num1 = dimQueue(Q1);
  int num2 = dimQueue(Q2);

  if (num1 > num2)
    printQueue(Q1);
  else
    printQueue(Q2);
  }
}




























// STACKKKKKKKKKKKK

//Attraverso l'interazione con l'utente permette di creare e popolare un nuovo stack.
Stack stackCreationMenu(int n){
  Stack s=initStack();
  int input=1;
  
  do{
    if(input==0 || input>3) printf("Nessuna azione associata al codice %d. Riprovare\n",input);
    printf("Seleziore il metodo di creazione del nuovo stack :\n");
    printf("1) Stack vuoto\n");
    printf("2) Stack popolato da valori forniti in input\n");
    printf("3) Stack popolato da valori random\n");
  } while(!getPositive(&input) || input>3 || input ==0);
  
  if(input>1){
    if (n<=0) {
      do{
        printf("Quanti elementi da inserire?\n");
      }
      while(!getPositive(&n));
    }
    if(input==2){
      if(n!=0) printf("Digita gli elementi da inserire : \n");
      while(n>0){
        if(!fullStack(s)){
          printf("Mancano %d valori\n", n);
          while(!getInt(&input)){ printf("Il valore digitato non Ã¨ un intero, riprovare.\n");};
          push(s,input);
          n--;
        } else {
          printf("Stack pieno, non è possibile più di %d elementi\n",STACK_MAX);
          break;
        }
      }
    } else {
      randomStack(s,n);
    }
  } 
  return s;
}




void raddoppiaVal (Stack S)
{
  int s;

  if(!emptyStack(S))
  {
    s = pop(S);
    raddoppia(S);
    push(S,s);
    push(S,s);
  }
  
}


/*Si considerino due stack 
Pari  e Dispari
, implementatati con array
, riempiti con interi
. 
Si implementi la funzione ricorsiva 
void gioca 
che, utilizzando una libreria di funzioni 
proceda a turni nel modo seguente. Ad ogni turno calcola la somma di Pari+Dispari se la 
somma è pari si toglie da Pari il numero minimo, altrimenti si toglie da Dispari. Il gioco 
finisce quando uno degli stack diventa vuoto. Si ricordi che la coda è una struttura dati 
che permette l’accesso ai suoi dati solo dalla testa. Si implementi una funzione che 
permetta di stampare ogni round.*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int somma(Stack S);
int mm(Stack S,int min)
{
    int value;
    if(!emptyStack(S))
    {
        value=pop(S);
       
        if(!emptyStack(S))
        {
          min= mm(S,min);
        }
        else
         min=100;
         
         if (value < min)
             min=value;
             
        push(S,value);
    }
    
    return min;
}

int somma(Stack S){
    int sommav;
    int value;
    if(!emptyStack(S)){
        value=pop(S);
       
        if(!emptyStack(S)){
            sommav=value+somma(S);
            
        }else 
        	sommav=value;
        	
        push(S,value);
    }return sommav; 
}

//elimina il minimo
void elimina(Stack S,int min){
    int value;
    if(!emptyStack(S)){
        value=pop(S);
      
        if(!emptyStack(S)){
            elimina(S,min);
        }
        if (value>min){
        
            push(S,value);
        }
    }
}

void gioco(Stack S,Stack S2){
    int sommap=0;
    int sommad=0;
    int min=100;
    int i=0;
    while(!emptyStack(S) && !emptyStack(S2))
        {
            i++;
            sommap=somma(S);
            sommad=somma(S2);
            if((sommad+sommap)%2==0){
                printf("\nla somma e pari\n ");
                min=mm(S,min);
                elimina(S,min);
            }
            else 
            {
                printf("\nla somma e dispari \n");
                min=mm(S2,min);
                elimina(S2,min);
            }
            
            printf("\nminimo %d ",min);
            printf("\nvuoi stampare la mossa : %d " ,i);
            printf("\nvettore pari\n");
            printStack(S);
            printf("\nvettore dispari\n");
            printStack(S2);
        }
    
   printf("\nE' finita la partita");
}
    



// altro gioco: RICORSIVO finche sono pieni due stack ritorna il vincitore alla fine
//se la somma dello stesso livello dei due stack è disparie elimino dal primo altrimenti dal secondo

int giocaRIC(int *S1, int *S2){
	int hold1, hold2, err, res;
	if(!emptyStack(S1) && !emptyStack(S2))
	{
		hold1 = pop(S1,&err);
		hold2 = pop(S2,&err);
		res = giocaRIC(S1, S2);
		
		//il giocatore res ha vinto
		if(res)
		{
			push(S1,hold1,&err); //rimetto elementi a posto
			push(S2,hold2,&err);
		}
		else //gli stack hanno lo stesso numero di elementi
		{ 
			//se somma dei numeri sullo stesso livello è dispari
			if((hold1+hold2) % 2)
			{ 
				//printf("SOMMA DISPARI\n");
				push(S2,hold2,&err); //non inserisco l'elemento in S1, eliminandolo
			}
			else{
				//printf("SOMMA PARI\n");
				push(S1,hold1,&err); //elimino l'elemento di S2
			}
		}
		return res;
	}
	else if(!emptyStack(S1) && emptyStack(S2))
		return 1;
	else if(emptyStack(S1) && !emptyStack(S2))
		return 2;
	else if(emptyStack(S1) && emptyStack(S2))
		return 0;
}




//GIOCO inverso stack e code

/*
		ISTRUZIONI PER COMPILARE:
		gcc 2017_06_21_es1.c Stack/stack.c Queue/queue.c Input/inputReader.c -o <nomefile>
*/

#include <stdio.h>
#include <stdlib.h>

//se il file è nella stessa directory delle cartelle delle librerie, 
//sostituire con #include "Stack/stack.h", 
//idem per le altre librerie
/*#include "../Stack/stack.h" 
#include "../Queue/queue.h"
#include "../Input/inputReader.h" */
#include "Stack/stack.h" 
#include "Queue/queue.h"
#include "Input/inputReader.h"


//controlla s1 s2 sono uguali valore per valore
int checkStack(Stack S1, Stack S2){
	int flag=1;
	int val_S1, val_S2;

	if(!emptyStack(S1) && !emptyStack(S2)){
		val_S1= pop(S1);
		val_S2= pop(S2);

		if(val_S1 == val_S2)
			flag= checkStack(S1, S2);
		else
			flag= 0;

	}
	return flag;
}

//se s1 e s2 == dim allora s3 diventa l'inverso di s2 e si controlla se sono uguali(quindi inversi) s1 e s2
void funStack(Stack S1, Stack S2){
	if(dimStack(S1) == dimStack(S2)){
		Stack S3= stackCreationMenu(dimStack(S2));

		reverseStack(S2, S3);
		if(checkStack(S1, S3))
			printf("\nS1 è l'inverso di S2.\n");
		else
			printf("\nS1 non è l'inverso di S2.\n");
	}

	else printf("\nERRORE!!!! Devi passare due stack di uguali dimensioni.\n");
}

//stessa cosa con le code
int checkQueue(Queue Q1, Queue Q2){
	int flag=1;
	int val_Q1, val_Q2;

	if(!emptyQueue(Q1) && !emptyQueue(Q2))
	{
		val_Q1= dequeue(Q1);
		val_Q2= dequeue(Q2);

		if(val_Q1 == val_Q2)
			flag= checkQueue(Q1, Q2);
		else
			flag=0;
			
		enqueue(Q1,val_Q1);
		enqueue(Q2,val_Q2);
	}
	return flag;
}


void funQueue(Queue Q1, Queue Q2){
	if(dimQueue(Q1) == dimQueue(Q2))
	{
		reverseQueue(Q2);
		if(checkQueue(Q1, Q2))
			printf("\nQ1 è l'inverso di Q2.\n");
		else
			printf("\nQ1 non è l'inverso di Q2.\n");
		
		reverseQueue(Q1);
	}

	else printf("\nERRORE!!!! Devi passare due code di uguali dimensioni.\n");
}


int main(void){
	Stack S1, S2;
	Queue Q1, Q2;

	printf("\n\n**********Giochiamo con gli stack**********\n\n");
	S1= stackCreationMenu(0);
	printf("\n");
	S2= stackCreationMenu(0);

	printf("\nStack 1: ");
	printStack(S1);

	printf("\nStack 2: ");
	printStack(S2);

	funStack(S1, S2);

	printf("\n\n**********Giochiamo con le code**********\n\n");
	Q1= queueCreationMenu(0);
	printf("\n");
	Q2= queueCreationMenu(0);

	printf("\nCoda 1: ");
	printQueue(Q1);

	printf("\nCoda 2: ");
	printQueue(Q2);

	funQueue(Q1, Q2);

	return 0;
}

















//ALBERIIIII

//la funzione scorre tutto l'albero una sola volta
//verificando ogni elemento con il padre e nel caso della radice il controllo e' superfluo
//algoritmo e' lineare sulla dimensione dell'albero O(n)


int iSbinario(Tree T,int min, int max)
{
  int res=1;  
  if(T!=NULL){
  
   
    if(T->info1 + T->info2 <min || T->info1 + T->info2 >max){
      res=0; 
    }        
    else  
    //per rendere l'algoritmo in alcuni casi "migliore" e' stato pensato di aggiungere
   //una piccola clausola se nella parte sinistra dell'albero, la prima che visitiamo,
   // se giÃ  non è rispettata la condizione allora
   //non vi saranno effettuati controlli sulla parte destra dell'albero
    // se invece la parte sinistra rispetta la proprietÃ allora verrÃ  iniziata la ricerca nel sottoalbero destro
    {      
      res=iSbinario(T->sx,min,T->info1 + T->info2);
      if(res==1)
        res=iSbinario(T->dx,T->info1 + T->info2,max);
    }
  }
return res;
}


//funzione per trovare il minimo nell'abr
//scende sempre a sx
Tree min_abr(Tree root)
{
  Tree flag=NULL;

  if(root!=NULL){

    if(root->sx==NULL){

      flag=root;
    }
    else{

      flag=min_abr(root->sx);
    }
  }
return flag;
}




/* funzione che trova il successore dato un albero binario di ricerca e un intero k */

Tree successore(Tree root, int k)
{
  Tree flag=NULL;

  if(root!=NULL){

	//seinfo è < di key allore devo cercare a dx
    if(root->info<k){
      flag=successore(root->dx,k);
    }
    //SE HO TROVATON LA KEY ALLORA IL SUCCESSORE È IL MIN DEL SOTTO DX
    else if(root->info==k){
      flag=min_abr(root->dx);
    }
    else{//altrimenti sx
      flag=successore(root->sx,k);
    }
  }
return flag;
}


//ESTREMA DX
/* funzione che trova il massimo dato un albero */

Tree max_abr(Tree root)
{
  Tree flag=NULL;

  if(root!=NULL){
    
    if(root->dx==NULL){
      flag=root;
    } 
    else{
      flag=max_abr(root->dx);
    }
  }
return flag;
}



//MAX DEL SOTTO SX DELLA KEY
/* funzione che trova un precedessore dato un albero binario e un valore k */

Tree predecessore(Tree root, int k)
{
  Tree flag=NULL;

  if(root!=NULL){

    if(root->info<k){
      flag=predecessore(root->sx,k);
    }
    else if(root->info==k){
      flag=max_abr(root->sx);
    }
    else{
      flag=predecessore(root->dx,k);
    }
  }
return flag;
}



//funzione finale che analizza l'ABR
int analizza_ABR(Tree root){
  int res=1;
  if(root != NULL && res != 0){

    analizza_ABR(root->sx);
    analizza_ABR(root->dx);

    if(successore(root,root->info) || predecessore(root,root->info))
      res=1;
    else
      res=0;
  }
  return res;
}


int uguali(Tree T, Tree G)
{
  int res=1;

  if(T!=NULL && G!=NULL){
    if(T->info!=G->info){//valori
      res=0;
    }
    else{
      res=uguali(T->sx,G->sx);
      if(res==1)
      res=uguali(T->dx,G->dx);
    }
  }
  else if(G==NULL && T!=NULL){//struttura
    res=0;
  }
  else if(T==NULL && G!=NULL){
    res=0;
  }
return res;
}

//due alberi uguali
int isomorfiTree (Tree T, Tree P)
{
  if(T && P)
  {
    if(T->info == P->info)
    {
      isomorfiTree(T->sx, P->sx);
      isomorfiTree(T->dx, P->dx);
    }
      
  }
  else if(!T && !P)
    return 1;

  return -1;
}




void Elimina (  nodo **R, int elem){
    
    //Nodo di supporto
    struct nodo *tmp;
    tmp = *R;
    
    if ( (*R)!=NULL) {
        
        if ( elem < (*R)->key ) 
            // Scendo a sinistra
            Elimina(&((*R)->sx), elem);
        else if ( elem > (*R)->key)
            // Scendo a destra
            Elimina(&(*R)->dx, elem);
        
        else if ( elem == (*R)->key) {
            
            // Il nodo contiene l'elemento 
            
            // Caso 1, il nodo non ha figli
            if ( ((*R)->sx)==NULL && ((*R)->dx )==NULL) {
                
                
                free(*R);
                *R=NULL;
                return;
            }
            // Caso 2, ha un solo figlio
            if ( (*R)->sx == NULL || (*R)->dx == NULL ) {
                
                // Caso 2.1, solo figlio destro
                if  ( (*R)->dx != NULL) 
                    
                    *R= tmp->dx;
                return;   
                
                // Caso 2.2, solo figlio sinistro
                if ( (*R)->sx != NULL) 
                    
                    *R= tmp->sx;
                return;   
                
                // Libero
                
                free(tmp);
            }
            
            
            // Caso 3, il nodo ha entrambi i figli       
            if ( (*R)->sx != NULL && (*R)->dx != NULL ){
                
                
                (*R)->key = Minimo( &(*R)->dx);
                
                Elimina(&(*R)->dx, (*R)->key);
                
            }
        }
        
        
    }
}



/*
 * La funzione Altezza() permette di trovare l'altezza di un ABR
 */
int Altezza ( nodo **R ) {
    
    int count1 = -1;
    int count2 = -1;
    int alt = -1;
    
    if ( (*R) != NULL ) 
    {
        if (&(*R)->sx !=NULL)
            count1 = Altezza(&(*R)->sx)+1;
        if (&(*R)->dx !=NULL)
            count2 = Altezza(&(*R)->dx)+1;
    }
    alt = Val_Max(count1,count2);
    return alt;
}



  
/*
 * La funzione attaccanodo() permette di attaccare un nodo di un ABR ad un altro
 */
void attaccanodo(  nodo **R, nodo **R2) 
{
    //struct nodo *S; // Nodo di supporto
    
    if ( (*R)==NULL) {
        // Creo un singolo nodo radice
        *R = *R2;
        (*R)->sx=NULL;
        (*R)->dx=NULL;
        
        
    }
    else {
        if ( (*R)->key > (*R2)->key ) 
            // Scendo a sinistra
            attaccanodo (&(*R)->sx, R2);
        else if ( (*R)->key < (*R2)->key ) 
            // Scendo a destra
            attaccanodo(&(*R)->dx, R2);
    }
}


/*
 * La funzione Merge() permette di fondere in un unica struttura due ABR
 */


void merge(nodo **R,nodo **R2){
    if ( *R2!=NULL) {
        merge( R,&(*R2)->sx);
        
        merge(R,&(*R2)->dx);
        
        attaccanodo(R,R2);
    }
}



/*
 * La funzione Rotation() permette di ruotare un ABR in una determinata direzione (sx/dx) n volte
 */
void Rotation( nodo **R, char  dir, int n){
    
    
    nodo *T; // Nuova radice
    nodo *R2 = (*R); // Nodo di appoggio
    
    if ( (*R) != NULL &&  n > 0){
        
        // Ruotazione a destra 
        if ( (*R) ->sx != NULL  && dir == 'R') {
            
            // Salvo il figlio sinistro in T
            T = R2->sx;
            // Attacco il figlio destro di T  alla radice
            (*R)->sx = T->dx;
            // Attacco al figlio destro di T la Radice
            T->dx = R2;
            // La nuova radice diventa T
            (*R)  = T;
            
            
        }
        // Ruotazione a sinistra
        else if ( (*R)->dx != NULL && dir == 'L')
        {
            // Analogo alla ruotazione a destra
            
            T = R2->dx;
            
            (*R) ->dx = T->sx;
            
            T->sx = R2;
            
            (*R)  = T;
            
            
        }
        Rotation (&(*R), dir, n-1);  
    }
    
}

/*
 * La funzione StampaABR() permette di stampare a video un ABR
 */
void StampaABR( nodo **R, int level)
{
    if (*(R) == NULL ) return;
    else {
        
        StampaABR(&(*R)->dx, level+1);
        
        if(level!=0){
            
            for(int i=0;i<level-1;i++)
                 
                printf("    |\t");
                printf("    |----(%d)\n",  (*R)->key);
            
        }
        else
            printf("[%d]\n",(*R)->key);
        StampaABR(&(*R)->sx, level+1);
    }
}
// la funzione trasforma un albero degenere
void CreaLista( nodo **R)
{
    if ((*R)!=NULL)
    {
        if ( (*R)->sx != NULL){
           
            Rotation(&(*R), 'R',1 );
           
            CreaLista(&(*R));
        }
        else CreaLista(&(*R)->dx);
    }
}
 
//  questa funzione tende a schiacciare l'albero e renderlo quasi bilanciato
void CompattaAlbero(nodo **R, int nodo)
{
 
  if ( (*R) != NULL)
    {
      if ( nodo != 0){
    Rotation(&(*R), 'L', 1);
   
    CompattaAlbero(&(*R)->dx, nodo-1);
   
    }
    }
 
}


// grazie alle sue strutture di controllo consente di bilanciare un albero 
void Bilancia(nodo **R, int nodi)
{
  if (&(*R)!=NULL)
    {
      int CoeffBil = abs(Altezza(&(*R)->dx) - Altezza(&(*R)->sx));
      if ( CoeffBil > 1){
 
      int bil = pow(2,log2(nodi-1));
      CreaLista(R);
      CompattaAlbero(&(*R), nodi-bil);
      while ( bil > 1) {
   
      bil = bil/2;
      CompattaAlbero(&(*R), bil);
     
      }      
       Rotation(&(*R),'R',1);
      }
      else printf(" Albero bilanciato\n");
    }
     
}



/*
 * La funzione InOrder() permette di fare la visita di un ARB in order
 */
void InOrder (nodo **R ) {
    
    if (*R!=NULL) {
        InOrder( &(*R)->sx);
        printf(" %d ", (*R)->key);
        InOrder(&(*R)->dx);
    }
    
}



// ALBERO TERNARIO 
/*Presi due ABR, si costruisca un albero binario che sommi i valori posti nelle stesse 
posizioni (se esistenti). Inoltre trasformare l'albero ottenuto in ternario in modo che il 
terzo nodo, aggiunto senza figli, abbia il valore medio dei fratelli esistenti nell'albero 
binario*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

//stampa
void st(Tree T){
    if (T != NULL) {
      printf(" /%d/ ", T->info);
    }
}


void inOrder2(Tree T) {
    if (T != NULL) {
        inOrder2(T->sx);
        printf(" %d", T->info);
       st(T->med);
        
        inOrder2(T->dx);
    }
}

//somma t e t2 info e lo mette in t3
Tree summ(Tree t,Tree t2, Tree t3){
    if (t&&t2)
    {
	    t3=initNode(t->info+t2->info);
	    t3->sx=summ(t->sx,t2->sx,t3->sx);
	    t3->dx=summ(t->dx,t2->dx,t3->dx);
    }
    
    return t3;
}
    
    
//trasforma t3 IN TERNARIO
Tree trasforma(Tree t)
{
    if (t)
    {
        if(t->sx && t->dx)
        {
        	//add nodo medio con info val medio tra sx e dx suoi
        	t->med=initNode((t->sx->info + t->dx->info)/2);
        }
    }
     
    if(t->sx)    
            t->sx=trasforma(t->sx);
    if(t->dx)
          t->dx=trasforma(t->dx);
    
    return t;
}
    
    
    
int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    
    
    Tree T = treeCreationMenu(0);
    Tree T2 = treeCreationMenu(0);
    Tree t3 =summ(T,T2,t3);
    printf("\n albero numero 1 : \n");
    inOrderPrint(T);
        printf("\n albero numero 2 : \n");

    inOrderPrint(T2);
        printf("\n albero numero 3 : \n");

    inOrderPrint(t3);
        printf("\n albero numero 4 : \n");

    t3=trasforma(t3);
    inOrder2(t3);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define MAX 12
/*
Presi due ABR, si costruisca un albero binario che sommi i valori posti nelle stesse
posizioni (se esistenti). Inoltre trasformare l'albero ottenuto in quadernario in modo che il
terzo nodo, aggiunto senza figli, abbia il valore somma dei fratelli esistenti nell'albero
binario e il quarto, sempre senza figli, la differenza
*/

Tree creaTrasformaT3(Tree T1, Tree T2, Tree T3);
Tree transformation(Tree T3);
void graphicMOD(Tree tree, char *str, int last);
void graphicPrintMOD(Tree T);
Tree initNodeMOD(int info);

int main() {

  Tree T1 = treeCreationMenu(MAX);
  Tree T2 = treeCreationMenu(MAX);
  printf("\nT1:\n");
  graphicPrint(T1);
  printf("\nT2:\n");
  graphicPrint(T2);
  
  Tree T3= NULL;
  T3 = creaTrasformaT3(T1,T2,T3);
  printf("\nT3:\n");
  graphicPrint(T3);
  printf("\nT3MOD:\n");
  T3 = transformation(T3);
  graphicPrintMOD(T3);
  
  return 0;
}

Tree creaTrasformaT3(Tree T1, Tree T2, Tree T3)
{
	if(T1 && T2)
	{
		T3 = initNodeMOD(T1->info + T2->info);
    		
    		if(T1->sx && T2->sx )
			T3->sx =	creaTrasformaT3(T1->sx,T2->sx,T3->sx);
		
		if(T1->dx && T2->dx )	
			T3->dx =	creaTrasformaT3(T1->dx,T2->dx,T3->dx);		
	}
	return T3;
}

//da binario a quaternario
Tree transformation(Tree T3)
{	
	if(T3)
		if(T3->sx && T3->dx)
		{
			T3->cen1 = initNodeMOD(T3->sx->info + T3->dx->info);
			T3->cen2 = initNodeMOD(T3->sx->info - T3->dx->info);	
		}	
	
	if(T3->sx)
		T3->sx = transformation(T3->sx);		
			
	if(T3->dx)	
		T3->dx = transformation(T3->dx);
		
	return T3;
}



void graphicMOD(Tree tree, char *str, int last){
    char tmp[100];
    
	if(tree)
	{
        //Cambia la modalità di stampa se è l'ultimo figlio
        if(last == 1)
            printf("%s----------(%d)\n", str, tree->info);
        if(last == 2 || last == 3)
            printf("%s°°°(%d)\n", str, tree->info);
        if(last == 0)
            printf("%s\\-----(%d)\n", str, tree->info);

        //Stampa i sottoalberi solo se almeno uno dei due non è vuoto
        if(tree->sx != NULL || tree->dx != NULL) 
        {
            //Sceglie la stringa da stampare in base al sottoalbero dove si scende
            sprintf(tmp, "%s  |", str);
			graphicMOD(tree->dx, tmp, 1);
            
            sprintf(tmp, "%s  |", str);
			graphicMOD(tree->cen1, tmp, 2);
			
		  sprintf(tmp, "%s  |", str);
			graphicMOD(tree->cen2, tmp, 3);
            
            sprintf(tmp, "%s   ", str);
			graphicMOD(tree->sx, tmp, 0);
        }
    }
    else //abr vuoto
    {
        if(last==1)
            printf("%s--NIL\n", str);
        else if(last==0)
            printf("%s\\-NIL\n", str);
        else if(last==2 || last ==3) 
         printf("%s°NIL\n", str);
    }
}
void graphicPrintMOD(Tree T) { //Stampa graficamente in preorder l'albero
	graphicMOD(T, "", 0);
}

Tree initNodeMOD(int info) {
    Tree T = (Tree)malloc(sizeof(struct TTree));
    T->info = info;
    T->sx = NULL;
    T->dx = NULL;
    T->cen1 = NULL;
    T->cen2 = NULL;
    return T;
}




//albero esteso


int main() {
	Tree T1 = NULL, T2 = NULL;
	Albero A = NULL;
	T1 = inserisciAlbero(T1);
	T2 = inserisciAlbero(T2);
	printf("\nT1: ");
	inOrder(T1);
	printf("\nT2: ");
	inOrder(T2);
	printf("\n");
	A = estensione(T1,T2,A);
	stampaAlbero(A);
	deallocaAlbero(A);
	freeTree(T1);
	freeTree(T2);
	return 0;
}

Tree inserisciAlbero(Tree T){
	int i,n,k;
	printf("Quanti elementi vuoi inserire? ");
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		printf("elem %d: ", i+1);
		scanf("%d",&k);
		T = insertNodeTree(T,k);
	}
	return T;
}

//estenzione a ternario di A con info T1 se == a info T2
Albero estensione(Tree T1, Tree T2, Albero A){
	if(T1){
		A = nuovoNodo(T1->info);
		if(T2)
			if(T2->info == T1->info)
				A->middle = nuovoNodo(1);
		if(T2)
			A->sx = estensione(T1->sx,T2->sx,A->sx);
		else
			A->sx = estensione(T1->sx,T2,A->sx);
		if(T2)
			A->dx = estensione(T1->dx,T2->dx,A->dx);
		else
			A->dx = estensione(T1->dx,T2,A->dx);
	}
	return A;
}


//ABR con DUE info
/*
a. scrivere una funzione che verifichi che T è un albero binario di ricerca secondo la
chiave (info1+ info2) per ogni nodo. 
b. Assumendo che T sia un ABR secondo la proprietà a), data una coppia di elementi
(x1,x2) verificare se esiste un elemento in T che ha tale coppia usando una ricerca
binaria.  */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define INT_MIN 1
#define INT_MAX 32

void printTree(Tree T, int indent);
int checkABR(Tree T, int min, int max);
int binSearch(Tree T, int x1, int x2);

int main() {
  int x1 = 0, x2 = 0;
  Tree T = NULL;
  printf("GENERO ABR CASUALE\n\n");
  T = randomTree(10);
  printf("STAMPO ABR\n\n");
  printTree(T,0);
  
  
  printf("CONTROLLO SE ABR\n\n");
  if(checkABR(T,INT_MIN, INT_MAX))
    printf("T e' un ABR\n\n");
  else
    printf("T NON e' un ABR\n\n");
    
    
    
  printf("\n\nInserisci x1: ");
  scanf("%d",&x1);
  printf("Inserisci x2: ");
  scanf("%d",&x2);
  printf("\nRICERCO (%d,%d)..\n\n",x1,x2);
  if(binSearch(T,x1,x2))
    printf("(%d,%d) TROVATO!\n",x1,x2);
  else
    printf("(%d,%d) NON TROVATO!\n",x1,x2);
    
  
  printf("\n\nInserisci x1: ");
  scanf("%d",&x1);
  printf("Inserisci x2: ");
  scanf("%d",&x2);
  printf("\nRICERCO (%d,%d)..\n\n",x1,x2);
  if(binSearch(T,x1,x2))
    printf("(%d,%d) TROVATO!\n",x1,x2);
  else
    printf("(%d,%d) NON TROVATO!\n",x1,x2);
  return 0;
}

int binSearch(Tree T, int x1, int x2){
  int found = 0;
  if(T){
    if(T->info == x1 && T->info2 == x2)
      found = 1;
    else
      if(T->info + T->info2 > x1 + x2)
        found = binSearch(T->sx, x1, x2);
      else
        found = binSearch(T->dx, x1, x2);
  }
  return found;
}

//vesifica se abr max e min 
int checkABR(Tree T, int min, int max){
  int res = 1;
  if(T){
    if(T->info + T->info2 < min || T->info + T->info2 > max)
      res = 0;
    else
      res = checkABR(T->sx, min, T->info + T->info2) && checkABR(T->dx, T->info + T->info2, max);
  }
  return res;
}

void printTree(Tree T, int indent){
  if(T){
    int i = 0;
    for( ; i<indent ; i++){
      printf("   ");
    }
    printf("+--( %d + %d = %d )\n", T->info, T->info2, T->info + T->info2);
    printTree(T->sx, indent+1);
    printTree(T->dx, indent+1);
  }
}





//HEAP


#include <stdio.h>
#include <stdlib.h>
#include "../Librerie/Queue/queue.h"

#define MAX 6

void scambia(int * H, int i , int j);
int destro(int i);
int sinistro(int i);
int padre(int i);
int checkHeap(int * H, int i, int heapsize);
void costruisciHeap(int heapsize, int *H);
void heapify(int *H, int i, int heapsize);
void heapifySu(int *H, int i, int heapsize);
void modificaHeap(int * H, int heapsize);
void printHeap(int *H, int i, int heapsize, int indent);



int main() {

  Queue Q = queueCreationMenu(MAX);
  printQueue(Q);

  printf("CONTROLLO SE Heap\n\n");
  if(checkHeap(Q->A,0,MAX))
    printf("Q e' un Heap\n\n");
  else
    printf("Q NON e' un Heap\n\n");
	
  printHeap(Q->A,0,MAX,0);
  modificaHeap(Q->A,MAX);
  
  return 0;
}


void scambia(int *H, int i , int j){
  int *tmp = H;
  
  H[i] = H[j];
  H[j] = *tmp;
}

int sinistro(int i){
  return 2*i + 1;
}

int destro(int i){
  return 2*i+2;
}

int padre(int i){
  if(!i)
    return -1;
  return (i-1)/2;
}



int checkHeap(int * H, int i, int heapsize){
  int res = 1;
  if(i<heapsize){
    int sx = sinistro(i), dx = destro(i);
    if( ( sx < heapsize && H[sx] < H[i] ) || ( dx < heapsize && H[dx] < H[i] ) )
      res = 0;
    else
      res = checkHeap(H,sx,heapsize) && checkHeap(H,dx,heapsize);
  }
  return res;
}

void costruisciHeap(int heapsize, int *H){
  int i;
  for(i=heapsize/2 ; i>=0 ; i--)
    heapify(H,i,heapsize);
}

void heapify(int *H, int i, int heapsize){
  int figlioMinimo = i, figlioDestro = destro(i), figlioSinistro = sinistro(i);

  if( figlioDestro < heapsize && H[figlioDestro] < H[figlioMinimo] )
    figlioMinimo = figlioDestro;

  if( figlioSinistro < heapsize && H[figlioSinistro] < H[figlioMinimo] )
    figlioMinimo = figlioSinistro;

  if(figlioMinimo != i)
  {
    scambia(H,i,figlioMinimo);
    heapify(H,figlioMinimo, heapsize);  
  }
}

void heapifySu(int *H, int i, int heapsize){
  if(i>=0 && i<heapsize){
    int p = padre(i);
    if(p != -1){
      if(H[p] > H[i]){
        scambia(H,i,p);
        heapifySu(H,p,heapsize);  
      }
    }
  }
}

void modificaHeap(int * H, int heapsize){
  int i=0,k=0;
  
  printf("Quale indice vuoi modificare? ");
  scanf("%d",&i);
  printf("Quanto vuoi sommare ad H?  ");
  scanf("%d",&k);

  if(i<heapsize && i>=0){
    H += k;
    printf("\nECCO LO HEAP DOPO LA MODIFICA\n\n");
    printHeap(H,0,heapsize,0);
    printf("\nRIPRISTINO LA PROPRIETA' DI HEAP\n\n");
    heapify(H,i,heapsize);
    heapifySu(H,i,heapsize);
    printf("\nHEAP RIPRISTINATO\n\n");
    printHeap(H,0,heapsize,0);
  }
  else{
    printf("Indice non valido!\n");
  }
}

void printHeap(int *H, int i, int heapsize, int indent){
  if(i<heapsize*2){
    int j = 0;
    for( ; j<indent ; j++)
      printf("   ");
    if(H[i] != 0)
    		printf("+--( %d )\n",H[i]);
    else
    		printf("+--(NIL)\n");
    printHeap(H,sinistro(i),heapsize,indent+1);
    printHeap(H,destro(i),heapsize,indent+1);
  }
}

