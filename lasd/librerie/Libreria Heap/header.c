#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define MAX 32

/*===========================================================
Libreria per alberi Heap e relative funzioni di utilizzo

Autori: Gianluca De Lucia (N86001826)
        Carlo Mennella    (N86001552)
        
A.A  2016/2017
=============================================================*/









/* 
   La funzione left() trova l'indice di posizionamento 
   del figlio sinistro di un elemento in un heap.
   
   INPUT: indice di posizione dell'elemento i
   OUTPUT: indice del figlio sinistro dell'elemento in pozizione i
*/

int left(int i)
{
	return 2*i+1;
}



/*
   La funzione right() trova l'indice di posizionamento
   del figlio destro di un elemento in un heap.
   
   INPUT:  indice di posizione dell'elemento i
   OUTPUT: indice del figlio destro dell'elemento in posizione i
*/

int right(int i)
{
	return 2*i+2;
}


/* 
   La funzione p() trova l'indice di posizionamento 
   del figlio padre di un elemento in un heap.
   
   INPUT:  indice di posizione dell'elemento i
   OUTPUT: indice del padre dell'elemento in posizione i
*/
int p(int i)
{
	return (i-1)/2;
}


/*
   La funzione swap() legge in ingresso 3 parametri: l'array e due indici 
   che indicano le posizioni degli elementi da scambiare.
   La classica funzione accede all elemento dell'array e sposta l'elemento in una 
   variabile temporale, successivamente il secondo elemento nella casella
   gia copiata. In fine sovrascrive tmp sulla casella del secondo elemento.
   
   INPUT:  indici di posizione i,j e Array A[]
*/

void swap(int A[MAX], int i, int j)
{
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}


/*
	La struttura dati Heap (binaria) è un array che può
	essere visto come un albero binario completo.
	Proprietà fondamentale degli Heap è che il valore
	associato al nodo padre è sempre maggiore o uguale a
	quello associato ai nodi figli
	Un Array A per rappresentare un Heap ha bisogno di
	due attributi:  
	- Lunghezza dell’array
	- Elementi dell’Heap memorizzati nell’array
					
	Una subroutine molto importante per la manipolazione degli
    Heap è Heapfy. Questa routine ha il compito di assicurare il
    rispetto della proprietà fondamentale degli Heap. Cioè, che il
    valore di ogni nodo non è inferiore di quello dei propri figli.
    Di seguito la funzione Heapify() che ha il
    compito di far scendere il valore di un nodo che viola la
    proprietà di Heap lungo i suoi sottoalberi.
	
	INPUT: Array di interi A[] e indice i
	
	Complessità O(nlog)
	
*/
void Heapify(int A[MAX], int i,int ArraySize )
{
	int l,r,largest;
	l = left(i);
	r = right(i);
	if (l < ArraySize && A[l] > A[i])
		largest = l;
	else largest = i;
	if (r < ArraySize && A[r] > A[largest])
		largest = r;

	if (largest != i) {
		swap(A, i, largest);
		Heapify(A, largest,ArraySize);
	}
}


/*
	La funzione BuilHeap() permette di costruisce albero heap
	da un array
	
	INPUT: Array di interi A[]
	
	Complessità O(nlogn)
*/

void BuildHeap(int A[MAX],int ArraySize)
{
	int i;
    
    for (i=ArraySize/2; i>=0; i--)
		Heapify(A, i,ArraySize);
}


/*
	L’Heapsort è un algoritmo di ordinamento molto efficiente:
	Esso ordina sul posto. L’algoritmo di Heapsort basa la sua potenza
	sull’utilizzo di una struttura dati chiamata Heap, che
	gestisce intelligentemente le informazioni durante
	l’esecuzione dell’algoritmo di ordinamento.

	INPUT: Array di interi A[]

	Complessità O(nlogn)
*/
void HeapSort(int A[MAX],int ArraySize )
{   int temp=ArraySize;
	int i;
	BuildHeap(A,ArraySize);
	for (i=ArraySize-1; i>=1; i--)
	{
		swap(A, 0, i);
		ArraySize--;
		Heapify(A, 0,ArraySize);
	}
  ArraySize=temp;
}



/*
	Le funzioni Min() e Max() permettono di calcolare
	rispettivamente il valore minimo e massimo contenuto nell'array.
	Per semplificare il compito viene richiamata la funzione HeapSort();
	
	INPUT:  Array A[]
	OUTPUT: valore minimo in posizione A[0]
	
*/
int Min (int A[MAX],int ArraySize){
	HeapSort (A,ArraySize);
	printf("\nValore Minimo: %d", A[0]);
	}
	
	
/* 
	INPUT:  Array A[] e la sua lunghezza ArraySize
	OUTPUT: Valore massimo in posizione A[ArraySize -1]	
*/	
int Max (int A[MAX], int ArraySize)  // prende in ingresso l'array e la sua lunghezza
{
	HeapSort(A,ArraySize);
	printf("\nValore Massimo: %d", A[ArraySize-1]);
}


	  

/*
	La funzione IsEmpty() permette di valutare se l'arrray è vuoto o meno
	
	INPUT:  Array A[]
*/	  

int IsEmpty(int ArraySize)
{   
    if(ArraySize==0) return 1;
   
}


/*
	La funzione Insert() permette di inserire un elemento all'interno dell'array
	
	INPUT: Array A[]
*/
void Insert (int A[MAX],int *ArraySize){
	int i;
	
	printf("\nInserisci un elemento: ");
	
	i=*ArraySize;
	scanf("%d",&A[i]);
    *ArraySize=*ArraySize+1;

}
/*
	La funzione Delete() permette di eliminare un elemento dall'array
	tramite lo scambio con la funzione swap() tra l'ultimo elemento e l'elemento da eliminare,
	in modo tale che ridimensionando l'array non è più presente tale l'elemento.

	INPUT: Array A[] e indice di posizione
*/

void Delete (int A[],int indice,int *ArraySize)
{   int i=*ArraySize;
	swap(A,indice,i-1);
	*ArraySize=*ArraySize-1;			
}		
	
	
/*
	La funzione stampa() permette di stampare a video gli elmenti dell'array
*/		
void stampa (int A[],int ArraySize){
	int k;
	printf("\nArray : [");
	for (k=0;k<ArraySize;k++)
       printf(" %d",A[k]);
    printf(" ]");   
}

/*
	La funzione size() permette di restituire a video la lunghezza dell'array
*/
void size (int ArraySize ){
	printf("\nLa dimensione dell array e' : %d",ArraySize);
}
