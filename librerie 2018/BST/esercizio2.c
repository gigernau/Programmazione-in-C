#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
struct TTTTree {
    int info;
    struct TTTTree* sx;
    struct TTTTree* cen1;
    struct TTTTree* cen2;
    struct TTTTree* dx;
};
typedef struct TTTTree* Tree4;


Tree merge(Tree albero1, Tree albero2);
Tree4 transform(Tree albero1);
void graphicPrintMOD(Tree4 T);
void graphicMOD(Tree4 tree, char *str, int last);

int main(){
	
	Tree albero3=NULL;
	Tree4 albero4=NULL;
	Tree albero1=treeCreationMenu(0);
	Tree albero2=treeCreationMenu(0);
	
	printf("\nT1:\n");
	graphicPrint(albero1);
	printf("\nT2:\n");
	graphicPrint(albero2);
	
	albero3 = merge(albero1,albero2);
	printf("\nT3:\n");
	graphicPrint(albero3);
	
	albero4=transform(albero3);
	printf("\nT4:\n");
	graphicPrintMOD(albero4);
	return 0;
}


Tree merge(Tree albero1, Tree albero2)
{	
	Tree elem = NULL; 																																																																																																																																																																																																																																																																																		
	if(albero1!=NULL && albero2!=NULL)
	{
		Tree elem=(Tree)malloc(sizeof(struct TTree));
		elem->sx = merge(albero1->sx,albero2->sx);
		elem->info=albero1->info+albero2->info;
		elem->dx = merge(albero1->dx,albero2->dx);
	}
	return elem;
}	
		

Tree4 transform(Tree albero1)
{
	Tree4 elem=NULL;
	if(albero1!=NULL){
		elem=(Tree4)malloc(sizeof(struct TTTTree));
		elem->info=albero1->info;
		elem->sx=transform(albero1->sx);
		if(albero1->sx!=NULL&&albero1->dx!=NULL){		
			elem->cen1=(Tree4)calloc(sizeof(struct TTTTree),1);
		     elem->cen2=(Tree4)calloc(sizeof(struct TTTTree),1);
			elem->cen1->info=albero1->sx->info+albero1->dx->info;
			elem->cen2->info=albero1->sx->info-albero1->dx->info;		
		}																																																																																																																																																																																																																																																																						
		elem->dx=transform(albero1->dx);
	}
	return elem;
}

void graphicMOD(Tree4 tree, char *str, int last){
    char tmp[100];
    
	if(tree)
	{
        //Cambia la modalità di stampa se è l'ultimo figlio
        if(last == 1)
            printf("%s----------(%d)\n", str, tree->info);
        if(last == 2 || last == 3)
            printf("%s°°°(%d)\n", str, tree->info);
        if(last == 0)
            printf("%s\\-----(%d)\n", str, tree->info);

        //Stampa i sottoalberi solo se almeno uno dei due non è vuoto
        if(tree->sx != NULL || tree->dx != NULL) 
        {
            //Sceglie la stringa da stampare in base al sottoalbero dove si scende
            sprintf(tmp, "%s  |", str);
			graphicMOD(tree->dx, tmp, 1);
            
            sprintf(tmp, "%s  |", str);
			graphicMOD(tree->cen1, tmp, 2);
			
		  sprintf(tmp, "%s  |", str);
			graphicMOD(tree->cen2, tmp, 3);
            
            sprintf(tmp, "%s   ", str);
			graphicMOD(tree->sx, tmp, 0);
        }
    }
    else //abr vuoto
    {
        if(last)
            printf("%s--NIL\n", str);
        else
            printf("%s\\-NIL\n", str); 
    }
}
void graphicPrintMOD(Tree4 T) { //Stampa graficamente in preorder l'albero
	graphicMOD(T, "", 0);
}

