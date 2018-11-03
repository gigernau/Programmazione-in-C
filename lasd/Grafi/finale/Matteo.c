#include "Graph.h"
#include "List.h"
#include "Matteo.h"


coda CreaCoda(){
    coda C = malloc(sizeof(struct Tqueue));
    C->array[0] = 0;
    C->array[MAX_EL] = 1;
    return C;
}


int CodaPiena(coda C){
    return C->array[0] == C->array[MAX_EL];
}


int CodaVuota(coda C){
    return C->array[0]==0;
}


void Accoda(coda C, int val){
    if(!CodaPiena(C)){
        C->array[C->array[MAX_EL]] = val; //inserisce un valore in coda
        if(CodaVuota(C)){
            C->array[0] = 1;
        }
        C->array[MAX_EL] = (C->array[MAX_EL]%(MAX_EL-1))+1;
    }
}


int Decoda(coda C){
    int val =0;
    if(!CodaVuota(C)){
        val = C->array[C->array[0]];//prendo il valore in testa
        C->array[0] = (C->array[0] % (MAX_EL-1)) + 1;
        if (CodaPiena(C)){
            C->array[0] = 0;
            C->array[MAX_EL] = 1;
        }
    }
    
    return val;
}



void  TrovaSalite(Graph G, int s, int col[],int salita[],int d[])
{
    int h[G->nodes_count];
    // Inizializzo sorgente
    col[s]='g';
    d[s]=0;
    
    // Inizializzo  l'array delle altezze con l'indice dei nodi
    for ( int i = 0 ; i < G->nodes_count; i++)
        h[i]=i;
    
    List adj;
    int u,v;
    
    // Dichiaro la coda
    coda Q = CreaCoda();
    Accoda(Q,s);
    
    
    // Ciclo principale
    while ( !CodaVuota(Q))
    {
        u = Decoda(Q);
        
        adj = G->adj[u];
        // Scorro gli adiacenti di u
        while ( adj!=NULL)
        {
            
            // Nodo adiacente
            v = adj->target;
            
            // Arco in salita
            if (h[u] <  h[v]) 
            {
                // Rilassamento sull'arco
                if (d[v]==-1 || d[v]>d[u]+ adj->peso)
                {
                    d[v]= d[u]+ adj->peso ;
                    
                    // Array salita[] usato con elementi solo in salita
                    salita[v]=u;
                    Accoda(Q,v);
                }
                
            }
            adj = adj->next;
        } 
        col[u] = 'n';
    }
    
    
}



void ProvaCostume(Graph G,int s,int d )
{
    int n = G->nodes_count;
    int salit[n];
    int disces[n];
    int min = inf;
    int intersect = -1;
    int cols[n],cold[n],ds[n],dd[n];
    
    // Inizializzazione array
    for(int j=0;j<n;j++)
        
    {   cols[j]='w';
        cold[j]='w';
        ds[j]=inf;
        dd[j]=inf;
        salit[j]=-1;
        disces[j]=-1;
        
    }
    
    TrovaSalite(G,s,cols,salit,ds);
    Graph Gt = Trasposto(G);
    TrovaSalite(Gt,d,cold,disces,dd);
    
    for (int i=0;i<n;i++){
        
        if(cold[i]=='n' && cols[i]=='n' && ( (ds[i] + dd[i]) < min )){
            
            intersect = i;
            
            min = ds[i] + dd[i];
            
        }
        
        
    }
    
    
    
    // Se si e' trovata un intersezione diversa dalle sorgenti 
    if(intersect != -1 && intersect != s && intersect != d)
    {
        printf("\nLa lunghezza del percorso minimo e': %d ",min);
        printf("\nPercorso: ");
        stampr(salit,intersect,s);
        printf(" --->[%d]",intersect);
        stamp(disces,intersect,d);
    }
    else
        printf("\nNon esiste il percoso minimo");
    
    
}


void stamp(int A[],int k, int j)
{
    if ( A[k] != -1 )
        printf ("--->(%d)", A[k]);
    if (k != j )
    {  
        stamp (A,A[k],j);
    }
    
}
void stampr(int A[],int k, int j)
{
    if (k != j )
    {
        stampr (A,A[k],j);
    }
    
    if ( A[k] != -1 )
        printf ("--->(%d)", A[k]);
    
}



int TrovaSalita2(Graph G, int s, int col[],int salita[],int d[],int h[],int w)
{
    // Inizializzo
    col[s]='g';
    d[s]=0;
    List adj;
    int u,v;
    
    // Dichiaro la coda
    coda Q = CreaCoda();
    Accoda(Q,s);
    
    
    // Ciclo principale
    while ( !CodaVuota(Q))
    {
        u = Decoda(Q);
        adj = G->adj[u];
        
        // Scorro gli adiacenti di u
        while ( adj!=NULL)
        {
            
            // Nodo adiacente
            v = adj->target;
            
            if (h[u] <=  h[v]){
                
                if (h[u] < h[v])
                    
                    w=1;
                
                if (d[v]==-1 || d[v]>d[u]+ adj->peso)
                {
                    d[v]=d[u]+ adj->peso ;
                    
                    salita[v]=u;
                    
                    Accoda(Q,v);
                }
                
            }
            adj = adj->next;
        } 
        
        
        col[u] = 'n';
    }
    
    return w;
}



void ProvaCostume2(Graph G,int s,int d, int h[])
{
    int n = G->nodes_count;
    int salit[n];
    int disces[n];
    int min=inf;
    int salita=0;// flag, utile per capire se vi e' almeno una salita
    int discesa=0;
    int intersect = -1;
    int cols[n],cold[n],ds[n],dd[n];
    for(int j=0;j<n;j++)
    {
        cols[j]='w';
        cold[j]='w';
        ds[j]=inf;
        dd[j]=inf;
        salit[j]=-1;
        disces[j]=-1;
    }
    
    salita=TrovaSalita2(G,s,cols,salit,ds,h,salita);
    Graph Gt = Trasposto(G);
    discesa=TrovaSalita2(Gt,d,cold,disces,dd,h,discesa);
    
    for (int i=0;i<n;i++){
        if(cold[i]=='n' && cols[i]=='n' && ( (ds[i] + dd[i]) < min )){
            intersect = i;
            min = ds[i] + dd[i];
            
        }
        
        
    }
    
    
    
    // Se si e' trovata un intersezione diversa dalle sorgenti, e almeni una salia e discesa nel percorso
    if(intersect != -1 && intersect!=s && intersect != d && salita==1 && discesa==1){
        printf("\nLa lunghezza del percorso minimo e': %d ",min);
        printf("\nPercorso ");
        stampr(salit,intersect,s);
        printf(" --->[%d]",intersect);
        stamp(disces,intersect,d);
    }
    else
        printf("\nNon esiste il percoso minimo");
    freeGraph(Gt);
}   
