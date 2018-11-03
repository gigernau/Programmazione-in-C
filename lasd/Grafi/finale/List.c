#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "List.h"

// Inizializza un nuovo nodo
List initNodeList(int info, int peso) {
    List L = (List)malloc(sizeof(struct TList));
    L->target = info;
    L->peso = peso;
    L->next = NULL;
    return L;
}

// Crea una lista random, per mod si
// puo' specificare il modulo utilizzato la funzione rand()
// La funzione ritorna sempre la testa della lista
List randomList(int index, int mod) {
    List L = NULL;
    int i = 0;
    for (i = 0; i < index; i++) {
        L = appendNodeList(L, rand() % mod, rand() % 50);
    }
    return L;
}

// Aggiunge un nodo alla fine della lista
List appendNodeList(List L, int target, int peso) {
    if (L != NULL) {
        if (L->target != target) {
            L->next = appendNodeList(L->next, target, peso);
        }
    } else {
        L = initNodeList(target, peso);
    }
    return L;
}
// Aggiunge un nodo in testa alla lista
List addNodeHead(List L, int target, int peso) {
    if (L != NULL) {
        List G = (List )malloc(sizeof(struct TList));
        G->target = target;
        G->next = L;
        return G;
    }
    return initNodeList(target, peso);
}



// Rimuove solo un occorrenza di un nodo con il target specificato
List removeNodeList(List L, int target) {
    if (L != NULL) 
    {
        if (L->target == target)
        {
            List tmp = L->next;
            free(L);
            return tmp;
        }
        if (L->next != NULL)
            L->next = removeNodeList(L->next, target);
    }
    return L;
}

// Dealloca la lista interamente
void freeList(List L) {
    if (L != NULL) {
        freeList(L->next);
        free(L);
    }
}

// Stampa la lista
void printList(List L) {
    if (L != NULL) {
        printf(" %d(%d) ", L->target, L->peso);
        printList(L->next);
    }
}
