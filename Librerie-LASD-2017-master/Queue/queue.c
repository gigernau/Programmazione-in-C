#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../Input/inputReader.h"
#include <time.h>
#include <limits.h>
#define ERR_EMPTY 1
#define ERR_FULL 2

void checkQueueError(int *err) {
	if (*err != 0) {
		//Manage the error here
		
		/*printf("Error\n");
		if (*err == ERR_FULL) {
			printf("Coda piena!\n");
		}
		else if (*err == ERR_EMPTY) {
			printf("Coda vuota!\n");
		}*/
	}
}


// Inserisce valori random nella coda
void randomQueue(Queue Q, int dim){
    int i = 0;
	srand((unsigned int)time(NULL));
    for (i = 0; i < dim; i++){
        enqueue(Q, rand() % 100);
    }
}

Queue queueCreationMenu(int n){
	Queue q=initQueue();
	int input=1;
	
	do{
		if(input==0 || input>3) printf("Nessuna azione associata al codice %d\n",input);
		printf("Seleziore il metodo di creazione della nuova coda :\n");
		printf("1) Coda vuota\n");
		printf("2) Coda popolata da valori forniti in input\n");
		printf("3) Coda popolata da valori random\n");
	} while(!getPositive(&input) || input>3 ||input ==0);
	
	if(input>1){
		if (n<=0) {
			do{
				printf("Quanti elementi da inserire?\n");
			}
			while(!getPositive(&n));
		}
		if(input==2){
			printf("Digita gli elementi da inserire : \n");
			while(n>0){
				if(!fullQueue(q)){
					printf("Mancano %d valori\n", n);
					while(!getInt(&input)){ printf("Il valore digitato non Ã¨ un intero, riprovare.\n");};
					enqueue(q,input);
					n--;
				} else {
					printf("Coda piena, non è possibile inserire più di %d elementi \n",QUEUE_MAX);
					break;
				}
			}
		} else {
			randomQueue(q,n);
		}
	}	
	return q;
}

// Inizializza la coda
Queue initQueue() {
    Queue Q = (Queue)malloc(sizeof(struct TQueue));
    Q->A[0] = 0;
    Q->A[QUEUE_MAX+1] = 1;
    return Q;
}


// Ritorna 1 se la coda e' vuota, 0 altrimenti
int emptyQueue(Queue Q){
    return Q->A[0] == 0;
}

int dimQueue(Queue Q) { //Restituisce il numero di nodi attualmente nella coda
	return ((Q->A[QUEUE_MAX+1]-Q->A[0])%QUEUE_MAX);
}


// Ritorna 1 se la coda e' piena, 0 altrimenti
int fullQueue(Queue Q){
    return Q->A[0] == Q->A[QUEUE_MAX+1];
}


// Accoda un elemento 'value' dato in ingresso
void enqueue(Queue Q, int value){
	int errh=0, *err=&errh;
    if (!fullQueue(Q)) {
        Q->A[Q->A[QUEUE_MAX+1]] = value; // Inserisci valore in coda
        if (emptyQueue(Q)) {
            Q->A[0] = 1; // Se e' vuota, sposto la testa in prima posizione
        }
        Q->A[QUEUE_MAX+1] = (Q->A[QUEUE_MAX+1] % (QUEUE_MAX)) + 1;
    } else {
        *err = ERR_FULL;
		checkQueueError(err);
    }
}


int headQueue(Queue Q) { //Restituisce l'elemento in testa alla coda senza rimuoverlo
	if (!emptyQueue(Q)) {
        return Q->A[Q->A[0]];
	}
	else {
		return INT_MIN;
	}
}

// Toglie un elemento dalla coda
int dequeue(Queue Q){
	int errh=0, *err=&errh;
    int value = 0;
    if (!emptyQueue(Q)) {
        value = Q->A[Q->A[0]]; // Prendo il valore in 'head' della coda
        Q->A[0] = (Q->A[0] % (QUEUE_MAX)) + 1;
        if (fullQueue(Q)) {
            Q->A[0] = 0;
            Q->A[QUEUE_MAX+1] = 1;
        }
    } else {
        *err = ERR_EMPTY;
		checkQueueError(err);
    }
    return value;
}


// Stampa la coda
void printQueueInc(Queue Q){
	int errh=0, *err=&errh;
    int value;
    if (!emptyQueue(Q)) {
        value = dequeue(Q);
        printf("%d ", value);
        printQueueInc(Q);
        enqueue(Q, value);
    } else {
        *err = ERR_EMPTY;
		checkQueueError(err);
    }
}


// Salva la coda in reverse
void reverseQueue(Queue Q){
	int errh=0, *err=&errh;
    int value;
    if (!emptyQueue(Q)) {
        value = dequeue(Q);
        reverseQueue(Q);
        enqueue(Q, value);
    } else {
        *err = ERR_EMPTY;
		checkQueueError(err);
    }
}


// Stampa la coda
void printQueue(Queue Q){
    printQueueInc(Q); // Stampa la coda
    reverseQueue(Q); // Riordina la coda prima di uscire
	printf("\n\n");
}
