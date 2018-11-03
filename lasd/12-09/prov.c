#include <stdio.h>
#include <stdlib.h>

/*
Si   considerino   due   liste   di   numeri   interi  Lista1   e   Lista2  implementate   come   liste
doppiamente puntate e non circolari, utilizzando la seguente struttura 

struct elemento {
	struct elemento *prev;
	int inf;
	struct elemento *next;} 
struct elemento *Lista1,*Lista2;

a. Si   implementi   una   sola   funzione  ricorsiva  (che   eventualmente   può   richiamare
sottofunzioni) che rimuova sia da Lista1 che da Lista2 tutte le occorrenze di numeri
negativi.
b. Dato un valore x, scrivere una funzione ricorsiva che, verificata l’esistenza di x in
Lista1, inserisca Lista2 prima di x (in Lista1) e restituisca Lista1 così modificata. Se x
non esiste in Lista1, accodare Lista2 a Lista1. 
*/

struct elemento{
	struct elemento *prev, *next;
	int inf;
};

struct elemento * acquireList();
struct elemento * append(struct elemento * L, int value);
void printList(struct elemento *L);

void rimuoviNegativi(struct elemento **L1, struct elemento **L2);
void removeNode(struct elemento ** target);
void modificaListe(struct elemento **L1, struct elemento **L2, int x);
void aggiungiAvanti(struct elemento **L1, struct elemento *L2);
struct elemento * duplicaLista(struct elemento * L);
struct elemento * duplicaLista2(struct elemento * L, struct elemento * app);

int main(int argc, char *argv[]) {
	int x = 0;
	struct elemento *L1 = NULL, *L2 = NULL;
	printf("ACQUISIZIONE LISTA 1\n\n");
	L1 = acquireList();
	printf("\nACQUISIZIONE LISTA 2\n\n");
	L2 = acquireList();
	printf("\nLISTA 1: ");
	printList(L1);
	printf("LISTA 2: ");
	printList(L2);
	printf("\nRIMUOVO NEGATIVI\n\n");
	rimuoviNegativi(&L1,&L2);
	printf("LISTA 1: ");
	printList(L1);
	printf("LISTA 2: ");
	printList(L2);
	printf("\nMODIFICA LISTE\n\n");
	printf("Inserisci x: ");
	scanf("%d",&x);
	modificaListe(&L1, &L2, x);
	printf("LISTA 1: ");
	printList(L1);
	printf("LISTA 2: ");
	printList(L2);
	return 0;
}

/*
void modificaListe(struct elemento **L1, struct elemento **L2, int x){
	if(*L1){
		if( (*L1)->inf == x ){ // trovato x in lista 1
			if( (*L1)->prev ){
				(*L1)->prev->next = duplicaLista2(*L2, *L1);
				if( (*L1)->prev->next )
					(*L1)->prev->next->prev = (*L1)->prev;
			}
		}
		else if( (*L1)->next == NULL){
			(*L1)->next = duplicaLista(*L2);
			if( (*L1)->next )
				(*L1)->next->prev = (*L1);
		}
		else
			modificaListe( &(*L1)->next, L2, x);
	}
}
*/

void modificaListe(struct elemento **L1, struct elemento **L2, int x){
	if(*L1){
		if( (*L1)->inf == x ){ // trovato x in lista 1
			aggiungiAvanti(L1,*L2);
		}
		else if( (*L1)->next == NULL){
			(*L1)->next = duplicaLista(*L2);
			if( (*L1)->next )
				(*L1)->next->prev = (*L1);
		}
		else
			modificaListe( &(*L1)->next, L2, x);
	}
}

void aggiungiAvanti(struct elemento **L1, struct elemento *L2){
	struct elemento * tmp = NULL;
	if(L2){
		aggiungiAvanti(L1,L2->next);
		tmp = (struct elemento *)calloc(1,sizeof(struct elemento));
		tmp->inf = L2->inf;
		printf("AGG: %d\n",L2->inf);
		tmp->next = *L1;
		tmp->prev = (*L1)->prev;
		if( (*L1)->prev ){
			(*L1)->prev->next = tmp;
		}
		else
			(*L1)=tmp;
		//(*L1)->prev = tmp;
	}
}

struct elemento * duplicaLista2(struct elemento * L, struct elemento * app){
	struct elemento * L2 = NULL;
	if(L){
		L2 = (struct elemento *)calloc(1, sizeof(struct elemento));
		L2->inf = L->inf;
		L2->next = duplicaLista2(L->next,app);
		if(L2->next)
			L2->next->prev = L2;
		else L2->next = app;
	}
	return L2;
}

struct elemento * duplicaLista(struct elemento * L){
	struct elemento * L2 = NULL;
	if(L){
		L2 = (struct elemento *)calloc(1, sizeof(struct elemento));
		L2->inf = L->inf;
		L2->next = duplicaLista(L->next);
		if(L2->next)
			L2->next->prev = L2;
	}
	return L2;
}

void rimuoviNegativi(struct elemento **L1, struct elemento **L2){
	if(*L1 && *L2){
		rimuoviNegativi( &(*L1)->next, &(*L2)->next );
		if( (*L1)->inf < 0) //rimuovere L1
			removeNode(L1);
		if( (*L2)->inf < 0)
			removeNode(L2);
	}
	else if(*L1){
		rimuoviNegativi( &(*L1)->next, L2);
		if( (*L1)->inf < 0) //rimuovere L1
			removeNode(L1);
	}
	else if(*L2){
		rimuoviNegativi( L1, &(*L2)->next);
		if( (*L2)->inf < 0) //rimuovere L1
			removeNode(L2);
	}
}

void removeNode(struct elemento ** target){
	struct elemento * tmp = *target;
	if( (*target)->next ){
		(*target)->next->prev = (*target)->prev;
	}
	if( (*target)->prev ){
		(*target)->prev->next = (*target)->next;
	}
	else{
		(*target) = (*target)->next;
	}
	free(tmp);
}

struct elemento * acquireList(){
	int val;
	struct elemento * L = NULL;
	printf("Inserisci una lista di interi da accodare alla lista terminata da un char\n");
	while(scanf("%d",&val)>0)
		L=append(L,val);
	scanf("%*[^\n]");
	return L;
}

struct elemento * append(struct elemento * L, int value){
	if(L){
		L->next = append(L->next, value);
		L->next->prev = L;
	}
	else{
		L =(struct elemento *)calloc(1,sizeof(struct elemento));
		L->inf = value;
	}
	return L;
}

void printList(struct elemento *L){
	if(L){
		printf("%d -> ",L->inf);
		printList(L->next);
	}
	else
		printf("NIL\n");
}