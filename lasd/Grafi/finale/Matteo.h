#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "Graph.h"
#include "List.h"
#define MAX_EL 128
#define inf INT_MAX
 
struct Tqueue{
	int array[MAX_EL+1];
	};
typedef struct Tqueue* coda;

// FUNZIONI CODE

coda CreaCoda();
int CodaVuota(coda C);
void Accoda(coda C, int );
int Decoda(coda C);
int CodaPiena(coda C);

// FUNZIONI MATTEO
void stamp(int A[],int k, int j);
void stampr(int A[],int k, int j);

int TrovaSalita2(Graph G, int s, int col[],int salita[],int d[],int h[],int w);
void ProvaCostume2(Graph G,int s,int d,int h[]);
void printList2(List L);
void printGraph2(Graph G);
