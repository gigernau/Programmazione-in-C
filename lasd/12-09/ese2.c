
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Librerie/Graph/list.h"



/** Funzione acquisisci_int
 * Descrizione:
 * E' un controllo dell'input, finchè non è inserito un intero 
 */
int acquisisci_int()
{   
    // Variabile per l'elemento da inserire
    int elemento;
    
    // array di char per la verifica
    char line[256];
    int verifica=0;

    /* Risolviamo il problema dell'acqusizione di scanf di elemeti,
     * non desiderati, come i caratteri o sequenze, con questa soluzione:
     * prendiamo in input una stringa, e leggiamo da questa stringa, se è
     * un intero la inserisco altrimenti no 
     */
    do{
        verifica=0; 
        
        
        scanf("%s", line);
        for (int i=0;i<strlen(line);i++)
        {
            if ( line[i]< '0' || line[i] >'9') 
            {
                verifica=1;
            }
        }
        if (verifica==1)
        {
            printf("\nNon e' stato inserito un numero, riprovare :");
        }
            
    }while(verifica==1);
    elemento=atoi(line);
    
    //ritorna il numero corretto
    return elemento;
}


void removeNode(List **L){
	List *tmp = *L;
	if( (*L)->next ){
		L->next->prev = (L)->prev;
	}
	if( (L)->prev ){
		(L)->prev->next = (L)->next;
	}
	else{
		(L) = (L)->next;
	}
	free(tmp);
}


void rimuoviNegativi(List* L1, List *L2)
{
	if(L1 && L2)
	{
		rimuoviNegativi( &L1->next, &L2->next );
		if( (L1)->target <= 1) //rimuovere L1
			removeNode(L1);
		if( (L2)->target <= 1)
			removeNode(L2);
	}
	else if(L1)
	{
		rimuoviNegativi( &L1->next, L2);
		if( (L1)->target <=1) //rimuovere L1
			removeNode(L1);
	}
	else if(L2)
	{
		rimuoviNegativi( L1, &L2->next);
		if( (L2)->target <= 1) //rimuovere L1
			removeNode(L2);
	}
}

int main ()
{
    srand((unsigned int)time(NULL));
    List L1=NULL; 
    List L2=NULL;

    int num1,num2, el;

//random valori
    printf("Quandi elementi contiene la prima lista?  ");
    num1 = acquisisci_int();
    for ( int i =0; i< num1;i++)
      L1=addNodeList(L1,rand() % 40,0);
    printList(L1);

//manuale
    printf("\n\nQuandi elementi contiene la seconda lista?  ");
     num2 = acquisisci_int();
    for ( int j =0; j<num2;j++){
      printf("\nElemento %d:  ", j);
      int elem = acquisisci_int();
      L2=addNodeList(L2,elem,0);
    }
    printList(L2);

    rimuoviNegativi(L1,L2);

    printList(L1);
    printList(L2);

    freeList(L1);
    freeList(L2);
    return 0;
}