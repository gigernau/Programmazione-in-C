#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"



int isomorfiTree (Tree T, Tree P)
{
	if(T && P)
	{
		if(T->info == P->info)
		{
			isomorfiTree(T->sx, P->sx);
			isomorfiTree(T->dx, P->dx);
		}
			
	}
	else if(!T && !P)
		return 1;

	return -1;
}







int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    int res;
    // Creo un nuovo albero T da 10 nodi
    Tree T = treeCreationMenu(0);
    Tree P = treeCreationMenu(0);

    // Eseguo una In Order sull'albero T
    inOrderPrint(T);
    inOrderPrint(P);
  	res = isomorfiTree(T,P);
  	if(res == 1)
  		printf("So uguali compa!\n");
  	else 
  		printf("fai schifo conmpa so diversi!\n");
    return 0;
}

