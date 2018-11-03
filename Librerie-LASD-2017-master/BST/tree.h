#ifndef ABR_Tree_h
#define ABR_Tree_h

struct TTree {
    int info;
    struct TTree* sx;
    struct TTree* dx;
};

typedef struct TTree* Tree;

Tree treeCreationMenu(int n);

// Inserisce un nodo nell'albero BST
Tree insertNodeTree(Tree T, int info);

// Inizializza un nuovo nodo
Tree initNode(int info);

// Crea un albero random, come index bisogna specificare
// il numero dei nodi desiderato nell'albero
Tree randomTree(int nodes);

// Esegue una stampa In Order sull'albero T
void inOrderPrint(Tree T);

// Esegue una stampa in Pre Order sull'albero T
void preOrderPrint(Tree T);

// Esegue una stampa in Post Order sull'albero T
void postOrderPrint(Tree T);

// Esegue una stampa Grafica in Pre Order sull'albero T
void graphicPrint(Tree T);

void freeTree(Tree);
#endif
