#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "List.h"
#include "Graph.h"
#include "Matteo.h"
#define inf INT_MAX

void ProvaCostumPrint()
{
    printf("\n\nScegliere uno dei punto:\n\n");
    printf("\n a) Punto 1\n b) Punto 2 (Manuale)\n c) Punto 2 (Random)\n d) USCITA\n\n");
}

char *Scelta(char *scelta)
{
    char cat[50];
    scanf(" %s", cat);
    *scelta=cat[0];
    return scelta;
}

void MenuPrincipale()
{
    printf(" \n\n                *******     MENU'  ******\n\n");
    printf("\t\t\ta) Creare un Grafo\n");
    printf("\t\t\tb) Grafo Random\n");
    printf("\t\t\tc) Stampa Grafo\n");
    
    printf("\t\t\td) Inserisci Nodo\n");
    printf("\t\t\te) Inserisci Arco\n");
    printf("\t\t\tf) Elimina Nodo\n");
    printf("\t\t\tg) Elimina Arco\n");
    
    printf("\t\t\th) SFIDA DI MATTEO\n");
    printf("\t\t\tx) Uscita\n\n");
    printf(" Scegliere uno dei punti digitando una delle lettere  :");
}


void Intro()
{
    
    printf("\n\t\t\t**PROGETTO 3**");
    printf("\n\t\t\t**GRAFI**");
    printf("\tLa prova costume di  Matteo\n");
    
}
void Matteo()
{
    srand((unsigned int)time(NULL));
    int nodo,s,d;
    int nodi;
    Graph G=NULL;
    Graph GT=NULL;
    
    MenuPrincipale();
    
    char scelta;
    while (  !Scelta(&scelta) || scelta != 'x'){
        
        switch(scelta)
        {
            
            case 'a':
            {
                
                int u,v;
                int peso;
                int archi;
                printf(" Inserire numero nodi per il grafo : ");
                nodi = acquisisci_int();
                G = initGraph(nodi);
                printf("\n Inserire numero archi ( il grafo ha %d nodi ) ", nodi);
                archi = acquisisci_int();
                for ( int i = 0 ; i < archi; i++) 
                {
                    do
                    {
                        printf (" \nInserire vertice di partenza : ");
                    u = acquisisci_int();
                    printf (" \nInserire vertice di arrivo : ");
                    v = acquisisci_int();
                    }while(u>=nodi || v >=nodi);
                    
                    printf (" \nInserire il peso : "); 
                    peso = acquisisci_int();
                    addEdge(G,u,v,peso);
                }
                printGraph2(G);
                MenuPrincipale();
                break;
            }
            case 'b':
            {
                printf("\n Inserire numero di nodi:\n");
                int nodi,min,max;
                nodi=acquisisci_int();
                do
                {
                    printf(" \nInserire archi minimi : ");
                    min=acquisisci_int();
                    printf(" \nInserire archi massimi : ");
                    max=acquisisci_int();
                }while(min > max);
                
                G=randomGraph(nodi,min,max);
                printGraph2(G);
                MenuPrincipale();
                break;
            }
            case 'c':
            {
                printf("\n\n");
                printGraph2(G);
                MenuPrincipale();
                break;
            }
            case 'd':
            {
                printf("\nInserimento nodo aggiuntivo...:\n\n");
                addNode(G);
                printf(" Nodo creato:%d",G->nodes_count);
                MenuPrincipale();
                break;
            }
            case 'e':
            {
                int sorgente,destinazione,peso;
                do
                {
                    printf("\n Inserire sorgente : ");
                sorgente=acquisisci_int();
                printf("\n Inserire destinazione : "); 
                destinazione=acquisisci_int();
                }while (sorgente >=nodi || destinazione >=nodi);
                
                printf("\n Inserire peso : "); 
                peso=acquisisci_int();
                if ( G!=NULL)
                    addEdge(G,sorgente,destinazione,peso);
                else printf(" Grafo non creato!!!\n\n");
                MenuPrincipale();
                break;
            }
            case 'f':
            {
                do 
                {
                     printf(" \nScegliere nodo da eliminare:\n\n");
                nodo=acquisisci_int();
                }while(nodo >= nodi);
               
                removeNode(G,nodo);
                MenuPrincipale();
                break;
            }
            case 'g':
            {
                do 
                {
                      printf(" \n\nScegliere sorgente dell' arco da eliminare:\n\n");
                s=acquisisci_int();
                printf(" \n\nScegliere destinazione dell' arco da eliminare:\n\n");
                d=acquisisci_int();
                }while(d>=nodi || s >=nodi); 
              
                
                removeEdge(G,s,d);
                MenuPrincipale();
                break;
            }
            case 'h':
            {
                if ( G == NULL)
                {
                    printf(" Grafo vuoto!!!\n\n");
                    MenuPrincipale();
                    break;
                }
                else{
                    int casa,uni,mod;
                    char punto;
                    char punto1;
                    int h[G->nodes_count];
                    ProvaCostumPrint();
                    while ( !Scelta(&punto) || punto!='d')
                    {
                        switch (punto)
                        {
                            case 'a':
                            {
                                printf ("\nPUNTO1\n");
                                for ( int i = 0; i < G->nodes_count; i++)
                                    h[i] = i;
                                printGraph(G,h);	
                                
                                
                                do{
                                    do{
                                        printf("\n Inserire nodo casa : ");
                                    casa=acquisisci_int();
                                    printf("\n Inserire nodo universita' : ");
                                    uni=acquisisci_int();
                                    }while(casa >= nodi || uni >= nodi);
                                    
                                    ProvaCostume2(G,casa,uni,h);
                                    
                                    printf("\nvuoi effettuare un altra scelta ? y/n : ");
                                }while ( !Scelta(&punto1) || punto1!='n');
                                ProvaCostumPrint();
                                break;
                            }
                            case 'b':
                            {
                                printf("\nPUNTO2\n");
                                printf(" Inserire altezze dei nodi generati casualmente:\n\n");
                                for ( int j  = 0; j < G->nodes_count; j++)
                                {
                                    printf(" Altezza nodo %d\n",j);
                                    h[j]=acquisisci_int();
                                }
                                
                                printGraph(G,h);
                                do{
                                    do{
                                         printf("\n Inserire nodo casa : ");
                                    casa=acquisisci_int();
                                    printf("\n Inserire nodo universita' : ");
                                    uni=acquisisci_int();
                                    }while (casa >= nodi || uni >= nodi);
                                   
                                    ProvaCostume2(G,casa,uni,h);
                                    printf("\nvuoi effettuare un altra scelta ? y/n : ");
                                }while ( !Scelta(&punto1) || punto1!='n');
                                
                                ProvaCostumPrint();
                                break;
                            }
                            case 'c':
                            {
                                printf("\nPUNTO2 RANDOM\n");
                                printf(" Inserire modulo per la generazione casuale di altezze\n\n");
                                mod=acquisisci_int();
                                for ( int k = 0 ; k < G->nodes_count; k++)
                                    h[k]=rand() % mod;
                                printGraph(G,h);
                                do{
                                    printf("\n Inserire nodo casa : ");
                                    casa=acquisisci_int();
                                    printf("\n Inserire nodo universita' : ");
                                    uni=acquisisci_int();
                                    
                                    ProvaCostume2(G,casa,uni,h);
                                    printf("\nvuoi effettuare un altra scelta ? y/n : ");
                                }while ( !Scelta(&punto1) || punto1!='n');
                                ProvaCostumPrint();
                                break;
                            }
                            case 'd':
                            {
                                printf("\n ... \n");
                                return;
                                break;
                            }
                            
                        }
                    }
                }
            }
            
                            case 'x':
                            {
                                freeGraph(G);
                                printf(" \n\n Uscita... \n\n");
                                MenuPrincipale();
                                break;
                            }
                            
                            default:
                            {
                                printf("\n\nInput non valido:\n\n");
                                getchar();
                                MenuPrincipale();
                                break;
                            }
        }
    }
}

void Menu_SceltaPunto ()
{
    
    printf("\n\n\t\ta) Punto 1");
    printf("\n\n\t\tb) Punto 2");
    printf("\n\n\t\tx) USCITA");
    printf("\n\nScegliere uno dei punti digitando una delle lettere  :");
    
    
    Matteo();
}
