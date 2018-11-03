#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "Graph.h"
#include "code.h"
#include "List.h"


#define inf INT_MAX

void upVisit (Graph G,int s,int col[], int pred[],int dist[]);
List DFSvisit(Graph G,List adj,List L,int s,int col[],int  pred[],int dist[]);
void AlgoSfida (Graph G,int s,int d);
void printPath (int s, int pred[], Graph G);


void upVisit2(Graph G,int s,int col[], int pred[],int dist[]);
List DFSvisit2(Graph G,List adj,List L,int s,int col[],int  pred[],int dist[]);
