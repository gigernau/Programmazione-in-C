#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "Graph.h"
#include "code.h"
#include "List.h"
#include "sfida3.h"
#define inf INT_MAX
 

void sfida (Graph G, int sorgente, char colore, percorso salita[], percorso discesa[],  percorso minimo)
{
   
    // Inizializzo
    int d[G->nodes_count];
    int pi[G->nodes_count];
    char color[G->nodes_count];
    // 'w' (bianco), 'g' ( grigio), 'b' (blu), 'r'(rosso), 'n'(nero)
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
            G->adj[i]-> colore = colore;
        }
    }
   
    // Dichiaro la coda
    coda Q = coda_inizial();
    coda_insert(Q,sorgente);
   
    // Ciclo principale
    while ( !coda_vuota(Q))
    {
        u = elimina_elem(Q);
        List adj = G->adj[u];
       
        // Scorro gli adiacenti di u
        while ( adj!=NULL)
        {
            // Nodo adiacente
            v = adj->target;
            if ( (u <  v) &&  (color[v]=='w' ))//color[v]=='w'
            {
               
                color[v]= 'g';
                pi[v]=u;
                d[v]=d[u]+ (adj->peso);
                if (colore == 'r')
                {
                    inserisci_percorso (G,salita,u, v, d[v]);
                }
                else
                {
                    inserisci_percorso (G,discesa,u, v, d[v]);
                }
               
                if ((colore == 'b') && (G->adj[v]-> colore == 'r'))
                {
                   attacca_liste (G, salita,discesa, v, *minimo);
                }
               
                G->adj[v]-> colore  = colore; 
                coda_insert(Q,v);
            }
            adj =adj->next;
        }
        //  elimina_elem(Q);
        color[u]== 'n';
    }
}
 
void inserisci_percorso(Graph G, percorso percorsi[], int u, int v, int d)
{
    int i,k;
    int flag = 0;
    if (percorsi[0] == NULL)
    {
        percorsi[0]->target = v;
        percorsi[0]->peso_tot = d; //L->(u,peso)->(v,peso+peso);
        percorsi[0]->next->target=u;
        percorsi[0]->next->peso_tot=0;
        
    }
    else
    {
        //scorriamo l'array di strutture per controllare se è gia presente un persorso minore e lo sostituiamo
        i = 0;
        do
        {
            if ((v == percorsi[i] -> target) && (percorsi[i]->peso_tot > d))
            {
               
                percorsi[i]->peso_tot = d;
               
                for (int j=0; j< G->nodes_count ; j++)
                {
                    if (u == percorsi[j]->target){
                        k = j;
                        j = G->nodes_count;
                    }
                }
                percorsi[i]->next= percorsi[k];
               
                flag = 1;
            }
            i++;
        }while(percorsi[i] == NULL);
       
        if (!flag)
        {
            percorsi[i]->target = v;
            percorsi[i]->peso_tot = d;
           
            for (int j=0; j<G->nodes_count; j++)
            {
                if (u == percorsi[j]->target){
                    int k = j;
                    j = G->nodes_count;
                }
            }
            percorsi[i]->next = percorsi[k];
           
        }
       
    }
}
 
void attacca_liste (Graph G, percorso salita[], percorso discesa[], int v, percorso minimo)
{
    int i,j,k;
    int distanza;
   
    i=0;
    do
    {
        if (salita[i]->target == v )
        {
            k = i;
        }
        i++;
    }while (salita[i] != NULL);
   
    i = 0;
        do
    {
        if (discesa[i]->target == v )
        {
            int j = i;
        }
        i++;
    }while (discesa[i] != NULL);
   
    distanza = discesa[j]->peso_tot + salita[k]-> peso_tot;
    if (minimo != NULL)
    { if (minimo->peso_tot>distanza){
        free (minimo);
    }
   
       
    }
    minimo = discesa[j];
    minimo = intesta(salita,minimo, k);
    minimo->peso_tot=distanza;// ora ho tutto il percorso e il mimimo che è
   
}
 
percorso intesta(percorso salita[],percorso minimo, int k)
{   
     
    percorso tmp;
    percorso prox;
    
    if (salita[k]!= NULL){
        tmp->target = salita[k]-> target;
        tmp->peso_tot = salita[k]-> peso_tot;
        tmp->next = minimo;
        salita [k]= salita[k]-> next;
         tmp= intesta(salita[k],tmp[],k);
    }
    return tmp;
}



