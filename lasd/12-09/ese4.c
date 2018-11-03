#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../Librerie/Input/inputReader.h"
#include "../Librerie/Queue/queue.h"
#include "../Librerie/List/list.h"
#include "../Librerie/Graph/graph.h"
#include <time.h>
#include <string.h>

/*
a. Scrivere in linguaggio C una funzione che, presi in input i due grafi G e H costruisca
un terzo grafo T ( e lo restituisca) in cui l’arco (a,b) è presente se è presente sia in G
che in H, oppure in nessuno dei due. Nel primo caso prenderà come peso la somma dei
pesi dei relativi archi in G e H. Nel secondo caso, prenderà peso ­1
b. Scrivere una funzione in C che verifichi che per ogni nodo di G e H, il grado incidente
in G è uguale al grado adiacente in H.
   */

Graph creaGrafo(Graph G, Graph H);
int verifica(Graph G, Graph H);

int main() {
	Graph G=NULL, H=NULL, T=NULL;
	printf("GENERO GRAFI CASUALI\n\n");
	G = randomGraph(5,1,4);
	H = randomGraph(5,1,4);
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

int verifica(Graph G, Graph H){
	int * app, i=0, res=1;
	List curr = NULL;
	app = (int *)calloc(G->nodes_count,sizeof(int));
	//per ogni vertice e  suoi adiacenti 
	//controllo i suoi incidenti in G e adiacenti in H
	for( ; i<G->nodes_count ; i++){
		for(curr = G->adj ; curr ; curr=curr->next )
			app[curr->target]++;
		for(curr = H->adj ; curr ; curr=curr->next )
			app--;
	}
	//gli elementi di app con valore negativo non verificano la regola!
	for(i=0;i<G->nodes_count;i++)
		if(app){
			res=0;
			printf("Per il nodo %d la diff. tra grado entrante in G e uscente in H e' %d.\n",i,app);
			break;
		}
	free(app);
	return res;
}

Graph creaGrafo(Graph G, Graph H){
	List curr = NULL;
	int * app, *isIn, i=0, j=0;
	Graph T = initGraph(G->nodes_count);

	app = (int *)calloc(G->nodes_count, sizeof(int));
	isIn = (int *)calloc(G->nodes_count, sizeof(int));

	//per ogni vertice controllo la sua lista adj
	for( ; i<G->nodes_count; i++){
		for(curr = G->adj ; curr ; curr=curr->next){
			isIn[curr->target]++;
			app[curr->target] += curr->peso;
		}
		for(curr = H->adj ; curr ; curr=curr->next){
			isIn[curr->target]++;
			app[curr->target] += curr->peso;
		}
		for(j=0;j<G->nodes_count;j++){
			//se arvo sta sia in g che in H
			if(isIn[j] == 2){
				addEdge(T,i,j,app[j]);
			}
			//se solo in uno dei due
			if(isIn[j] > 0 )
				app[j] = isIn[j] = 0;
			//se in nessuno dei due
			else{
				addEdge(T,i,j,-1);
			}
		}
	}
	free(app);
	free(isIn);
	return T;
}