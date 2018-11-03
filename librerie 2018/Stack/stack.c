#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "stack.h"
#include "../Input/inputReader.h"
#define ERR_EMPTY 1
#define ERR_FULL 2

void checkStackError(int *err) {
	if (*err != 0) {
		//Manage the error here
		/*printf("Error\n");
		if (*err == ERR_FULL) {
			printf("Stack pieno!\n");
		}
		else if (*err == ERR_EMPTY) {
			printf("Stack vuoto!\n");
		}*/
	}
}

// Crea uno stack random
void randomStack(Stack S, int n) {
	int errh=0, *err=&errh;
	S->dim = n;
    srand((unsigned int)time(NULL));
    int i = 0;
    for (i = 0; i < n; i++) {
        push(S, rand() % 40);
		checkStackError(err);
    }
}

//Attraverso l'interazione con l'utente permette di creare e popolare un nuovo stack.
Stack stackCreationMenu(int n){
	Stack s=initStack();
	int input=1;
	
	do{
		if(input==0 || input>3) printf("Nessuna azione associata al codice %d. Riprovare\n",input);
		printf("Seleziore il metodo di creazione del nuovo stack :\n");
		printf("1) Stack vuoto\n");
		printf("2) Stack popolato da valori forniti in input\n");
		printf("3) Stack popolato da valori random\n");
	} while(!getPositive(&input) || input>3 || input ==0);
	
	if(input>1){
		if (n<=0) {
			do{
				printf("Quanti elementi da inserire?\n");
			}
			while(!getPositive(&n));
		}
		if(input==2){
			s->dim = n;
			if(n!=0) printf("Digita gli elementi da inserire : \n");
			while(n>0){
				if(!fullStack(s)){
					printf("Mancano %d valori\n", n);
					while(!getInt(&input)){ printf("Il valore digitato non Ã¨ un intero, riprovare.\n");};
					push(s,input);
					n--;
				} else {
					printf("Stack pieno, non è possibile più di %d elementi\n",STACK_MAX);
					break;
				}
			}
		} else {
			randomStack(s,n);
		}
	}	
	return s;
}


// Inizializza lo Stack
Stack initStack() {
    Stack S = (Stack)malloc(sizeof(struct TStack));
	S->A[0] = 0;
	S->dim = 0;
    return S;
}


// Ritorna 1 se lo Stack e' vuoto, 0 altrimenti
int emptyStack(Stack S){
	return S->A[0] == 0;
}


int dimStack(Stack S){ // Ritorna il numero di elementi attualmente nello stack
	return S->dim;
}


// Ritorna 1 se lo Stack e' pieno, 0 altrimenti
int fullStack(Stack S){
	return S->A[0] == STACK_MAX;
}

int headStack(Stack S) { //Restituisce l'elemento in testa allo stack senza rimuoverlo
	if (!emptyStack(S)) {
        return S->A[S->A[0]+1];
	}
	else {
		return INT_MIN;
	}
}

// Inserisce il dato 'value' nello Stack, se non e' pieno
void push(Stack S, int value){
	int errh=0, *err=&errh;
	if(!fullStack(S)){
		S->A[0]++;
		S->A[S->A[0]] = value;
		*err = 0;
	} else {
		*err = 1;
	}
	checkStackError(err);
}


// Estrae dallo Stack un elemento e lo ritorna
int pop(Stack S){
	int errh=0, *err=&errh;
	if(!emptyStack(S)){
		S->A[0]--;
		*err = 0;
		checkStackError(err);
		return S->A[S->A[0]+1];
	} else {
		*err = 2;
		checkStackError(err);
		return 0;
	}
}


// Dato uno Stack S, attraversera' tutto lo Stack inserendo
// in un altro Stack dato in ingresso 'tmp' tutti gli
// elementi nell'ordine inverso
void reverseStack(Stack S, Stack tmp){
	int value;
	if(!emptyStack(S)){
		value = pop(S);
		push(tmp, value);
		reverseStack(S, tmp);
		push(S, value);
	}
}


// Stampa lo Stack dato in ingresso
void printStack(Stack S){
	int value;
	if(!emptyStack(S)){
		value = pop(S);
		printf("%d ", value);
		printStack(S);
		push(S, value);
	}
	else {
		printf("\n\n");
	}
}
