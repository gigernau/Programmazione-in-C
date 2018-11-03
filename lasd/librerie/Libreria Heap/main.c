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





main()
{
	int A[MAX];
	int k;
	int elem;
    int ArraySize;
 	printf("\nQuanti elementi deve contenere l'array (max %d elementi): ", MAX);
 	scanf("%d", &ArraySize);
 
 	while (ArraySize>MAX) 
    {
		printf("\n max MAX elementi: ", MAX);
    	scanf("%d",&ArraySize);
	}
		
 	for (k=0;k<ArraySize;k++)
	{
	 	printf("\nInserire il %d elemento: ",k+1);
	 	scanf("%d",&A[k]);
	}
			
		
	BuildHeap(A,ArraySize);
	Heapify(A,k,ArraySize);	
	printf("\nAlbero Heap: ");
    stampa(A,ArraySize );
       
    HeapSort(A,ArraySize);			
    printf("\nArray Ordinato: ");
    stampa(A,ArraySize );
       
    Min(A,ArraySize);
    Max(A,ArraySize);
    
    
    Insert(A, &ArraySize);
    HeapSort(A,ArraySize);
    stampa(A,ArraySize );
    
  
 	printf("\nIndice dell'elemento da cancellare: ");
 	scanf("%d",&elem);
 	while (elem>ArraySize) 
    {
		printf("\n max MAX elementi: ", ArraySize);
    	scanf("%d",&elem);
	}
	Delete(A,elem-1,&ArraySize);
	HeapSort(A,ArraySize);		
	printf("\nArray Riordinato: [");
    for (k=0;k<ArraySize;k++)
       printf(" %d",A[k]);
    printf(" ]");   
    size(ArraySize);
    if (IsEmpty(ArraySize))
	{
    	printf("\nl'array non e' vuoto");
	}else 
	{
		printf("\nl'array e' vuoto");
	}
    
}
