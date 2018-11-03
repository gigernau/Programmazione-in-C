#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include "List.h"
#include "Graph.h"
#include "code.h"
#include "sfida3.h"

int main()
{
    //dichiarazione variabili
    char scelta,risp;
    int n,m, min, max;
    int h;
    int i, j;
    int p,v,a;
    Graph G;
    
    char colore;
    int sorgente;
    
    percorso salita[50];
    percorso discesa[50];
    percorso minimo;
    percorso tmp[50];
    
    
    
    //menu iniziale
    printf(" \n\n *****************************  PROGETTO 3  ************************\n\n");
    printf("                                   GRAFI           \n");
    printf("                         La sfida di Matteo\n");
    
    
    do
    {
        
        
        printf(" \n\n ***************************     MENU'    ************************\n\n");
        printf("\t\t\ta) Creare un Grafo\n");
        printf("\t\t\tb) Grafo Random\n");
        printf("\t\t\tc) Stampa Grafo\n\n");
        
        printf("\t\t\td) Inserisci Nodo\n");
        printf("\t\t\te) Inserisci Arco\n");
        printf("\t\t\tf) Elimina Nodo\n");
        printf("\t\t\tg) Elimina Arco\n\n");
        
        printf("\t\t\th) SFIDA DI MATTEO\n");
        printf("\n\n\t\t\tx) Uscita\n\n");
        printf(" Scegliere uno dei punti digitando una delle lettere  :");
        
        
        char cat[50];
        scanf(" %s", cat);
        scelta=cat[0];
        
        switch (scelta)
        {
            
            //punto a
            case 'a' :
            {
                printf("\nInserire il numero dei vertici del grafo : ");
                n = acquisisci_int();
                G = initGraph(n);
                
                for (i = 0; i < n ; i++)
                {
                    do
                    {
                        printf("\nIl nodo di altezza %d e' collegato ad altri vertici? (y/n) : ", i);
                        scanf(" %c", &risp);
                    }while (risp != 'y' && risp != 'Y' && risp != 'n'  && risp != 'N');
                    
                    
                    if (risp == 'y' || risp == 'Y')
                    {
                        do
                        {
                            printf("\nA quanti vertici e' collegato? (max %d): ", n-1);
                            m = acquisisci_int();
                        }while (m > n-1);
                        
                        for (j = 0; j < m; j++)
                        {
                            do
                            {
                                printf("\nInserire il vertice a cui è collegato l'arco %d (compreso tra 0 e %d): ", i, n-1);
                                v = acquisisci_int();
                                
                            }while (v >= n);
                            
                            printf("\nInserire il peso dell'arco  tra %d e %d: ", i,v);
                            p = acquisisci_int();
                            addEdge(G, i, v, p);
                        }
                        
                    }
                }
                break;
            }
            
            //punto b
            case 'b' :
            {
                printf("\nInserie numero vertici : ");
                //scanf(" %d", &n);
                n = acquisisci_int();
                printf("\nInserie numero MINIMO di archi : ");
                //scanf(" %d", &min);
                min = acquisisci_int();
                
                do
                {
                    printf("\nInserie numero MASSIMO di archi : ");
                    //scanf(" &d", &max);
                    max = acquisisci_int();
                }while (max < min);
                
                printf("\nCreazione grafo random in corso...\n");
                G = randomGraph(n   ,min,max);
                getchar();
                break;
            }
            
            
            //punto c
            case 'c' :
            {
                printf("\nStampa del Grafo in corso...\n\n");
                printGraph(G);
                
                break;
            }
            
            //punto d
            case 'd' :
            {
                printf("\nAggiunta nodo in corso...");
                addNode(G);
                
                break;
            }
            
            
            //punto e
            case 'e' :
            {
                printf("\nSpecificare sorgente dell'arco : ");
                v = acquisisci_int();
                printf("\nSpecificare arrivo dell'arco : ");
                a = acquisisci_int();
                printf("\nSpecificare peso dell'arco : ");
                p = acquisisci_int();
                printf("\nAggiunta arco in corso...");
                addEdge(G,v,a,p);
                
                break;
            }
            
            
            //punto f
            case 'f':
            {
                printf("\nSpecificare il nodo da eliminare : ");
                v = acquisisci_int();
                printf("\nEliminazione nodo in corso...");
                removeNode(G, v);
                break;
            }
            
            //punto g
            case 'g' :
            {
                printf("\nSpecificare sorgente dell'arco da eliminare : ");
                v = acquisisci_int();
                printf("\nSpecificare arrivo dell'arco da eliminare : ");
                a = acquisisci_int();
                printf("\nEliminazione arco in corso...");
                removeEdge(G, v, a);
                break;
            }
            
            
            
            //punto h
            case 'h' :
            {
                colore = 'r';
                printf("\nInserire il vertice come sorgente: ");
                sorgente = acquisisci_int();
                sfida(G, sorgente, colore, *salita, *discesa, minimo);
                G = Trasposto(G);
                colore = 'b';
                sfida(G, sorgente, colore, *salita, *discesa, minimo);
                
                break;
            }
            
            //uscita   
            case 'x' :
            {
                printf("\n\n\nArrivederci!\n\n");
                getchar();
                break;
            }
            
            default :
            {
                printf("\n\n\nErrore reinserire la scelta!\n\n");
                getchar();
                break;
            }
        }
        
        // ripete la scelta del menu finche'  l'utente non desidera uscire
    }while (scelta != 'x'); 
    
    return 0; 
}

