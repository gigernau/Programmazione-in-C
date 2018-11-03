#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"
#include "inputReader.h"
#include <time.h>











//GRAFIIIII



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
  Graph G=graphCreationMenu(5);
  Graph H=graphCreationMenu(5);
  printGraph(G);
  printGraph(H);
  DFS(G,H);
  printGraph(G);
  return 0;
}




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



//aggiunge arco con differenza peso al terzo P
void DFS_Visit(Graph G, Graph H, Graph P, int u,int *C)
{
  C[u]='g';
  List adjG=G->adj[u];
  List adjH=H->adj[u];
  int v,peso,diff;
  while(adjG)
    {
      v=adjG->target;
      peso=RicercaArco(adjH,v);
      if (peso>0)
      {
          diff=adjG->peso-peso;
          if ( diff>0)
             addEdge(P,u,v,diff);
       }
       
      if ( C[v]=='w')
         DFS_Visit(G,H,P,v,C);

      adjG=adjG->next;
    }
}
  
void DFS(Graph G,Graph H,Graph P)
  
{
  int C[G->nodes_count];
  for ( int i = 0; i< G->nodes_count; i++)
    C[i]='w';
  for ( int u = 0; u < G->nodes_count; u++)
    {
      if  (C[u]=='w')
  DFS_Visit(G,H,P,u,C);
    }
}



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
  coda Q = coda_inizial();
  coda_insert(Q,sorgente);
  // Ciclo principale
  while ( !coda_vuota(Q))
    {
      u = elimina_elem(Q);
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
	      coda_insert(Q,v);
	    }
	  adj =adj->next;
        }
      //  elimina_elem(Q);
      color[u]== 'b';
    }
  // stampo array d[] e pi[]
  for ( int j = 0; j < G->nodes_count; j++)
    {
      printf(" d[%d] = '%d', pi[%d] = '%d'\n", j, d[j], j, pi[j]);
    }
}  



































//LISTEEEEEEEE

 
struct LLista
{
  int info;
  struct LLista *next,*prev;
};
typedef struct LLista *Lista;
// Crea un nodo

Lista creaNodo(int info)
{
  Lista nodo=(Lista)malloc(sizeof(Lista));
  nodo->info=info;
  nodo->next=NULL;
  nodo->prev=NULL;
  return nodo;
}
// inserisce in testa un nuovo elemento con valore 'info'
Lista insertTesta(Lista L,int info)
{
  Lista nodo=creaNodo(info);
  if (L)
    {
      // cam
      L->prev=nodo;
      nodo->next=L;
    }
  return nodo;
}
// Elimina l'elemento con info
void Elimina(Lista *L,int info)
{
  Lista tmp=NULL;
  if (*L)
    {
      Elimina(&(*L)->next,info);
      if ( (*L)->info == info)
  {
    tmp=(*L);
    if ((*L)->next)
      (*L)->next->prev=(*L)->prev;
    if ((*L)->prev)
      (*L)->prev->next=(*L)->next;
    else
      (*L)=(*L)->next;
    free(tmp);
  }
    }
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

void Stampa(Lista L)
{
  if (L)
    {
      printf("->%d",L->info);
      Stampa(L->next);
    }
  else printf("->NIL\n");
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

// Elimina i dispari dalla lista L e i pari dalla lista P, e ne fa l'interleaving
void Maschera(Lista *L, Lista *P)
{
  if (*L)
    EliminaPariDispari(&(*L),1);
  if (*P)
    EliminaPariDispari(&(*P),0);
  printf("\n Dopo l'eliminazione:\n");
  Stampa((*L));
  Stampa((*P));
  InterLeaving(&(*L),&(*P));
  printf("\n Dopo l'e:\n");
  Stampa((*L));
  Stampa((*P));
}
// semplice stampa

// Libera memoria dalla lista
void Libera(Lista L)
{
  if (L)
    {
      Libera(L->next);
      free(L);
    }
}

int  sommaLista(struct elem * L){
  return L ? sommaLista(L->next)+L->key : 0;
}



int main(int argc, const char * argv[]) {

   

        srand((unsigned int)time(NULL));
        Lista L1=NULL;
        Lista L2=NULL;

      for ( int i =0; i< rand() % 9;i++)
        L1=insertTesta(L1,rand() % 40);

      for ( int j =0; j<rand() % 9;j++)
        L2=insertTesta(L2,rand() % 40);

      Stampa(L1);
      Stampa(L2);
      
      funzione(L1,L2);

      Stampa(L1);
      

      Libera(L1);
      Libera(L2);
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




























// STACKKKKKKKKKKKK

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
int mm(Stack S,int min){
    int value;
    if(!emptyStack(S)){
        value=pop(S);
       
        if(!emptyStack(S)){
          min= mm(S,min);
         }else min=100;
         if (value<min)
             min=value;
        push(S,value);
    }
    return min;}

int somma(Stack S){
    int sommav;
    int value;
    if(!emptyStack(S)){
        value=pop(S);
       
        if(!emptyStack(S)){
            sommav=value+somma(S);
            
        }else sommav=value;
        push(S,value);
    }return sommav; 
}

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
    while(!emptyStack(S)&&!emptyStack(S2))
        {
            i++;
            sommap=somma(S);
            sommad=somma(S2);
            if((sommad+sommap)%2==0){
                printf("\nla somma e pari\n ");
                min=mm(S,min);
                elimina(S,min);
            }else {
                printf("\nla somma e dispari \n");
                min=mm(S2,min);
                elimina(S2,min);}
            printf("\nminimo %d ",min);
            printf("\nvuoi stampare la mossa : %d " ,i);
            printf("\nvettore pari\n");
            printStack(S);
            printf("\nvettore dispari\n");
            printStack(S2);
        }
    
   printf("\nE' finita la partita");
}
    



// altro gioco

int giocaRIC(int *S1, int *S2){
	int hold1, hold2, err, res;
	if(!emptyStack(S1) && !emptyStack(S2)){
		hold1 = pop(S1,&err);
		hold2 = pop(S2,&err);
		res = giocaRIC(S1, S2);
		if(res){//il giocatore res ha vinto
			push(S1,hold1,&err); //rimetto elementi a posto
			push(S2,hold2,&err);
		}
		else{ //gli stack hanno lo stesso numero di elementi
			//printf("curr %d, %d\n",hold1, hold2);
			if((hold1+hold2) % 2){ //se somma dei numeri sullo stesso liv. dispari
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






















//ALBERIIIII


int iSbinario(Tree T,int min, int max)
{
  int res=1;  //la funzione scorre tutto l'albero una sola volta
        //verificando ogni elemento con il padre e nel caso della radice il controllo e' superfluo
  if(T!=NULL){//per tanto la complessitÃ  risultante da questo algoritmo e' lineare sulla dimensione dell'albero O(n)
    if(T->info<min || T->info>max){ //per rendere l'algoritmo in alcuni casi "migliore" e' stato pensato di aggiungere
      res=0; //una piccola clausola se nella parte sinistra dell'albero, la prima che visitiamo, se giÃ  non Ã¨ rispettata la condizione allora
    }          //non vi saranno effettuati controlli sulla parte destra dell'albero se invece la parte sinistra rispetta la proprietÃ 
    else{      //allora verrÃ  iniziata la ricerca nel sottoalbero destro
      res=iSbinario(T->sx,min,T->info);
      if(res==1)
      res=iSbinario(T->dx,T->info,max);
    }
  }
return res;
}


//funzione per trovare il minimo nell'abr
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

    if(root->info<k){
      flag=successore(root->dx,k);
    }
    else if(root->info==k){
      flag=min_abr(root->dx);
    }
    else{
      flag=successore(root->sx,k);
    }
  }
return flag;
}

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








//ternario
/*Presi due ABR, si costruisca un albero binario che sommi i valori posti nelle stesse 
posizioni (se esistenti). Inoltre trasformare l'albero ottenuto in ternario in modo che il 
terzo nodo, aggiunto senza figli, abbia il valore medio dei fratelli esistenti nell'albero 
binario*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
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
Tree summ(Tree t,Tree t2, Tree t3){
    if (t&&t2){
    t3=initNode(t->info+t2->info);
    t3->sx=summ(t->sx,t2->sx,t3->sx);
    t3->dx=summ(t->dx,t2->dx,t3->dx);
    }
    return t3;}
    
Tree trasforma(Tree t){
    if (t){
        if(t->sx&&t->dx){
        t->med=initNode((t->sx->info + t->dx->info)/2);
       

    }}
          if(t->sx)    
            t->sx=trasforma(t->sx);
          if(t->dx)
          t->dx=trasforma(t->dx);
    
    return t;}
    
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



int Min(Tree T)
{
  if (T){
  if (T->sx==NULL)
    return T->info;
  else
    Min(T->sx);
  }
  else return -1;
}
      
void Elimina (Tree *T,int elem)
{
  Tree tmp=NULL;
  if ( *T)
    {
      if ( (*T)->info > elem)
  Elimina(&(*T)->sx,elem);
      else if ( (*T)->info < elem)
  Elimina(&(*T)->dx,elem);
      else if ( (*T)->info == elem)
  {
    tmp=(*T);
    if ( !(*T)->dx && !(*T)->sx)
      {
        free(*T);
        *T=NULL;
        return;
      }
    if ( !(*T)->sx || !(*T)->dx)
      { 
        if ((*T)->sx)
    (*T)=tmp->sx;
    if ((*T)->dx)
      (*T)=(*T)->dx;
        
        free(tmp);
      }
    if ( (*T)->dx && (*T)->sx)
      {
        (*T)->info=Min((*T)->dx);
        Elimina(&(*T)->dx, (*T)->info);
      }
  }
    }
}






//HEappppppppppppppppp




int checkHeap(int * H, int i, int heapsize){
	int res = 1;
	if(i<heapsize){
		int sx = sinistro(i), dx = destro(i);
		if( ( sx < heapsize && H[sx] < H ) || ( dx < heapsize && H[dx] < H ) )
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
	if(figlioMinimo != i){
		scambia(H,i,figlioMinimo);
		heapify(H,figlioMinimo, heapsize);	
	}
}

void heapifySu(int *H, int i, int heapsize){
	if(i>=0 && i<heapsize){
		int p = padre(i);
		if(p != -1){
			if(H[p] > H){
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
	if(i<heapsize){
		int j = 0;
		for( ; j<indent ; j++)
			printf("   ");
		printf("+--( %d )\n",H);
		printHeap(H,sinistro(i),heapsize,indent+1);
		printHeap(H,destro(i),heapsize,indent+1);
	}
}

int acquireHeap(int * H){
	int n=0, tot = 0;
	printf("Inserisci una sequenza di interi da inserire nello heap\nterminata da un char (MAX %d elementi):\n",MAX);
	while(tot<MAX && scanf("%d",&n)>0){
		H[tot++] = n;		
	}
	scanf("%*[^\n]");
	costruisciHeap(tot,H);
	return tot;
}

void scambia(int * H, int i , int j){
	int tmp = H;
	H = H[j];
	H[j] = tmp;
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
