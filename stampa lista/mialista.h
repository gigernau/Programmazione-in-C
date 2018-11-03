typedef struct Nodo{
   int info;
   Nodo* link;
}nodo;

typedef Nodo* pNodo; 

pNodo crea_nodo(int elem);

pNodo Insert_in_testa(int elem, pNodo pn);

pNodo Insert_in_coda(int elem, pNodo pn);

pNodo Ric_valore(int elem, pNodo pn);

pNodo cancella_nodo(int elem, pNodo handler);

void stampa(pNodo handler);

void scrivifile (pNodo head);
void leggifile ();

using namespace std;
