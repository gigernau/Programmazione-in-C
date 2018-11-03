

#include <stdio.h>
#include <stdlib.h>
#include "../Librerie/Queque/queue.h"

#define MAX 6


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







int main() {

  Queque Q = QuequeCreationMenu(MAX);
  printQueue(Q);

  printf("CONTROLLO SE Heap\n\n");
  if(checkHeap(Q->A,0,MAX))
    printf("Q e' un Heap\n\n");
  else
    printf("Q NON e' un Heap\n\n");

  modificaHeap(Q->A,MAX);
  
  return 0;
}

