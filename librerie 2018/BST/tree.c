#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <time.h>
#include "../Input/inputReader.h"

Tree randomTree(int nodes) {
    srand((unsigned int)time(NULL));
    int i = 0;
    Tree T = NULL;
    for (i = 0; i < nodes; i++) {
        T = insertNodeTree(T, rand() % 40);
    }
    return T;
}

Tree treeCreationMenu(int n){
	int input=1;
	do{
		if(input==0 || input>3) printf("Nessuna azione associata al codice %d\n",input);
		printf("Seleziore il metodo di creazione del nuovo albero:\n");
		printf("1) Albero vuoto\n");
		printf("2) Albero popolato da valori forniti in input\n");
		printf("3) Albero popolato da valori random\n");
	} while(!getPositive(&input) || input>3 ||input ==0);
	
	if (n<=0) {
		do{
			printf("Quanti elementi da inserire?\n");
		}
		while(!getPositive(&n));
	}
	if(input==2){
		printf("Digita gli elementi da inserire : \n");
		Tree T = NULL;
		int i;
		for (i=0; i<n; i++) {
			printf("Mancano %d valori\n", n-i);
			while(!getInt(&input)){ printf("Il valore digitato non è un intero, riprovare.\n");};
			T = insertNodeTree(T, input);
		}
		return T;
	}
	else {
		return randomTree(n);
	}
}

Tree initNode(int info) {
    Tree T = (Tree)malloc(sizeof(struct TTree));
    T->info = info;
    T->sx = NULL;
    T->dx = NULL;
    return T;
}

Tree insertNodeTree(Tree T, int info) {
    if (T == NULL) {
        T = initNode(info);
    } else {
        if (T->info > info) {
            T->sx = insertNodeTree(T->sx, info);
        } else if (T->info < info) {
            T->dx = insertNodeTree(T->dx, info);
        }
    }
    return T;
}


void inOrder(Tree T) {
    if (T != NULL) {
        inOrder(T->sx);
        printf("%d ", T->info);
        inOrder(T->dx);
    }
}
void inOrderPrint(Tree T) {
	inOrder(T);
	printf("\n\n");
}

void preOrder(Tree T) {
    if (T != NULL) {
        printf("%d ", T->info);
        preOrder(T->sx);
        preOrder(T->dx);
    }
}
void preOrderPrint(Tree T) {
	preOrder(T);
	printf("\n\n");
}

void postOrder(Tree T) {
    if (T != NULL) {
        postOrder(T->sx);
        postOrder(T->dx);
        printf("%d ", T->info);
    }
}
void postOrderPrint(Tree T) {
	postOrder(T);
	printf("\n\n");
}

void graphic(Tree tree, char *str, int last){
    char tmp[100];
	if(tree!=NULL){
        //Cambia la modalità di stampa se è l'ultimo figlio
        if(!last)
            printf("%s--%d\n", str, tree->info);
        else
            printf("%s\\-%d\n", str, tree->info);

        //Stampa i sottoalberi solo se almeno uno dei due non è vuoto
        if(tree->sx != NULL || tree->dx != NULL) {
            //Sceglie la stringa da stampare in base al sottoalbero dove si scende
            sprintf(tmp, "%s  |", str);
			graphic(tree->dx, tmp, 0);
        
            sprintf(tmp, "%s   ", str);
			graphic(tree->sx, tmp, 1);
        }
	}
    else {
        if(!last)
            printf("%s--NIL\n", str);
        else
            printf("%s\\-NIL\n", str); 
    }
}
void graphicPrint(Tree T) { //Stampa graficamente in preorder l'albero
	graphic(T, "", 0);
}


void freeTree(Tree T) {
	if(T) {
		freeTree(T->sx);
		freeTree(T->dx);
		free(T);
	}
}
