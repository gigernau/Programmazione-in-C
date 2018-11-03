#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Dichiarazione e funzioni primitive per liste doppiamente concantenate non circolari

struct LLista
{
  int info;
  struct LLista *next,*prev;
};
typedef struct LLista *Lista;
// Crea un nodo

Lista creaNodo(int info)
{
  Lista nodo=(Lista)malloc(sizeof(Lista));
  nodo->info=info;
  nodo->next=NULL;
  nodo->prev=NULL;
  return nodo;
}
// inserisce in testa un nuovo elemento con valore 'info'
Lista insertTesta(Lista L,int info)
{
  Lista nodo=creaNodo(info);
  if (L)
    {
      // cam
      L->prev=nodo;
      nodo->next=L;
    }
  return nodo;
}
// Elimina l'elemento con info
void Elimina(Lista *L,int info)
{
  Lista tmp=NULL;
  if (*L)
    {
      Elimina(&(*L)->next,info);
      if ( (*L)->info == info)
	{
	  tmp=(*L);
	  if ((*L)->next)
	    (*L)->next->prev=(*L)->prev;
	  if ((*L)->prev)
	    (*L)->prev->next=(*L)->next;
	  else
	    (*L)=(*L)->next;
	  free(tmp);
	}
    }
}
// Elimina pari o dispari dalla lista
void EliminaPariDispari(Lista *L,int a)
{
  if (*L)
    {
       EliminaPariDispari(&(*L)->next,a);
      if ( (*L)->info %2==a)
	
	  Elimina(&(*L),(*L)->info);
     
    }
}
void InterLeaving(Lista *L, Lista *P)
{
  Lista tmp=NULL;
  Lista tmp3=NULL;
  if (*L && *P)
    {
      tmp=(*P)->next;
      (*P)->next=(*L);
      (*L)->prev=(*P);
      InterLeaving(&(*L)->next,&(tmp));
    }
}    

void Stampa(Lista L)
{
  if (L)
    {
      printf("->%d",L->info);
      Stampa(L->next);
    }
  else printf("->NIL\n");
}
// Elimina i dispari dalla lista L e i pari dalla lista P, e ne fa l'interleaving
void Maschera(Lista *L, Lista *P)
{
  if (*L)
    EliminaPariDispari(&(*L),1);
  if (*P)
    EliminaPariDispari(&(*P),0);
  printf("\n Dopo l'eliminazione:\n");
  Stampa((*L));
  Stampa((*P));
  InterLeaving(&(*L),&(*P));
  printf("\n Dopo l'e:\n");
  Stampa((*L));
  Stampa((*P));
}
// semplice stampa

// Libera memoria dalla lista
void Libera(Lista L)
{
  if (L)
    {
      Libera(L->next);
      free(L);
    }
}


int main ()
{
  Lista L=NULL;
  Lista P=NULL;
  srand(time(NULL));
  for ( int i =0; i< rand() % 9;i++)
    L=insertTesta(L,rand() % 40);
  for ( int j =0; j<rand() % 9;j++)
    P=insertTesta(P,rand() % 40);
  Stampa(L);
  Stampa(P);
  Maschera(&L,&P);
  Stampa(L);
  Stampa(P);
  Libera(L);
  Libera(P);
  return 0;
}