
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "code.h"

coda coda_inizial(){
	coda C = malloc(sizeof(struct Tqueue));
	C->array[0] = 0;
	C->array[MAX_EL] = 1;
	return C;
	}

int coda_vuota(coda C){
	return C->array[0]==0;
	}

int coda_piena(coda C){
	return C->array[0] == C->array[MAX_EL];
	}
	
void coda_random(coda C, int size){
    int i = 0;
	srand(time(NULL));
    for (i = 0; i < size; i++){
        coda_insert(C, rand() % 100);
    }
}
	
void stampa_coda(coda C){
	int val;
	if(!coda_vuota(C)){
		val = elimina_elem(C);
		printf("%d\t",val);
		stampa_coda(C);
		coda_insert(C,val);
		}
	}
	
void coda_insert(coda C, int val){
	if(!coda_piena(C)){
		C->array[C->array[MAX_EL]] = val; //inserisce un valore in coda
			if(coda_vuota(C)){
				C->array[0] = 1;
				}
				C->array[MAX_EL] = (C->array[MAX_EL]%(MAX_EL-1))+1;
		}
	}

int elimina_elem(coda C){
	int val =0;
	if(!coda_vuota(C)){
		val = C->array[C->array[0]];//prendo il valore in testa
		C->array[0] = (C->array[0] % (MAX_EL-1)) + 1;
		if (coda_piena(C)){
			C->array[0] = 0;
			C->array[MAX_EL] = 1;
			}
		}
	
	return val;
	}


void coda_inversa(coda C){
    int val;
    if (!coda_vuota(C)) {
        val = elimina_elem(C);
        coda_inversa(C);
        coda_insert(C, val);
    } 
}

void stampa_bis(coda C){
	stampa_coda(C);
	coda_inversa(C);
	}
