#include <stdio.h>
#include <stdlib.h>
#include "Libririe-LASD-2017-master/Graph/list.h"
#include "Libririe-LASD-2017-master/Graph/graph.h"
#include "Libririe-LASD-2017-master/Input/inputReader.h"

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
		v = L->target;

		if(color[v] == 'w')
		{
			_calcolaGrado(G, v, color, degree);
		}
		L=L->next;
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
	adjG= G->adj[i];
	while( adjG){
		v=G->adj[i]->target;
		if(color[v] == 'w'){
			_DFS(G, H, T, v, color);
			if(foundEdge(H->adj[i], G->adj[i]->target, G->adj[i]->peso ) ){
				addEdge(T, i, G->adj[i]->target, (G->adj[i]->peso - H->adj[i]->peso) );
			}
		}
		L=L->next;
	}	
	color[i]= Black;
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
