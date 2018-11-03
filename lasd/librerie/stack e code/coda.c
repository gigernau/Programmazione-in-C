#include <stdio.h>
#include <stdlib.h>
#include "coda.h"


/*==================================================================================================
Libreria Code

Autori: Gianluca De Lucia     (N86001826)
        Carlo Mennella        (N86001552)
        Giammarco Moscariello (N86001446)
        
A.A  2016/2017
===================================================================================================*/


//nb uso error come debug prima di consegnarlo eliminare
// Inizializza la coda 
int* inicoda() {
    
	int* C = (int*) calloc(MAX + 2, sizeof(int));
	C[MAX + 1] = 1;
	return C;
}


// Stampa la coda
void print(int *C){
    int value;
    if (!empty(C)) {
        value = decoda(C);
        printf("%d ", value);
        print(C);
        accoda(C, value);
    }
    
}




// Salva la coda in reverse
void reverse(int *C){
    int value;
    if (!empty(C)) {
        value = decoda(C);
        reverse(C);
        accoda(C, value);
    }
}


// Stampa la coda
void printer(int *C){
    print(C); // Stampa la coda
    reverse(C); // Riordina la coda prima di uscire
}

// Ritorna 1 se la coda e' vuota, 0 altrimenti
int empty(int *C){
    return C[0] == 0;
}


// Ritorna 1 se la coda e' piena, 0 altrimenti
int piena(int *C){
    return C[0] == C[MAX];
}


// Accoda un elemento 'value' dato in ingresso
void accoda(int *C, int value){
    if (!piena(C)) {
       C[C[MAX+1]] = value; // Inserisci valore in coda
        if (empty(C)) {
            C[0] = 1; // Se e' vuota, sposto la testa in prima posizione
        }
        C[MAX+1] = (C[MAX+1] % (MAX)) + 1;
    }
}


// Toglie un elemento dalla coda
int decoda(int *C){
    int value = 0;
    if (!empty(C)) {
        value = C[C[0]]; // Prendo il valore in 'head' della coda
        C[0] = (C[0] % (MAX)) + 1;
        if (pieno){
            C[0] = 0;
            C[MAX] = 1;
            }
    }
    return value;
}
