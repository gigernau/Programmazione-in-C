#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Librerie/BST/tree.h"
#define INT_MIN 1
#define INT_MAX 32


void printTree(Tree T, int indent);
int checkABR(Tree T, int min, int max);
int binSearch(Tree T, int x1, int x2);

int main() {
	int x1 = 0, x2 = 0;
	Tree T = NULL;
	printf("GENERO ABR CASUALE\n\n");
	T = randomTree(10);
	printf("STAMPO ABR\n\n");
	printTree(T,0);
	printf("CONTROLLO SE ABR\n\n");
	if(checkABR(T,INT_MIN, INT_MAX))
		printf("T e' un ABR\n\n");
	else
		printf("T NON e' un ABR\n\n");
	printf("\n\nInserisci x1: ");
	scanf("%d",&x1);
	printf("Inserisci x2: ");
	scanf("%d",&x2);
	printf("\nRICERCO (%d,%d)..\n\n",x1,x2);
	if(binSearch(T,x1,x2))
		printf("(%d,%d) TROVATO!\n",x1,x2);
	else
		printf("(%d,%d) NON TROVATO!\n",x1,x2);
	
	printf("\n\nInserisci x1: ");
	scanf("%d",&x1);
	printf("Inserisci x2: ");
	scanf("%d",&x2);
	printf("\nRICERCO (%d,%d)..\n\n",x1,x2);
	if(binSearch(T,x1,x2))
		printf("(%d,%d) TROVATO!\n",x1,x2);
	else
		printf("(%d,%d) NON TROVATO!\n",x1,x2);
	return 0;
}

int binSearch(Tree T, int x1, int x2){
	Tree found = NULL;
	if(T){
		if(T->info == x1 && T->info2 == x2)
			found = T;
		else
			if(T->info + T->info2 > x1 + x2)
				found = binSearch(T->sx, x1, x2);
			else
				found = binSearch(T->dx, x1, x2);
	}
	return (found != NULL);
}




int checkABR(Tree T, int min, int max){
	int res = 1;
	if(T){
		if(T->info + T->info2 < min || T->info + T->info2 > max)
			res = 0;
		else
			res = checkABR(T->sx, min, T->info + T->info2) && checkABR(T->dx, T->info + T->info2, max);
	}
	return res;
}

void printTree(Tree T, int indent){
	if(T){
		int i = 0;
		for( ; i<indent ; i++){
			printf("   ");
		}
		printf("+--( %d + %d = %d )\n", T->info, T->info2, T->info + T->info2);
		printTree(T->sx, indent+1);
		printTree(T->dx, indent+1);
	}
}