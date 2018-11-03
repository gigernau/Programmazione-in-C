 typedef struct{
	double re;
	double im;
}complex ;

typedef struct Nodo{
	int info;
	struct Nodo* link;
}nodo;

int B[100];

typedef Nodo* pNodo; 

complex somma (complex x, complex y, complex z);
complex sottrazione (complex x, complex y, complex z);
complex moltiplicazione (complex x, complex y, complex z);
complex divisione (complex x, complex y, complex z);
double modulo (complex x, complex y, double &modulo1, double &modulo2);
void coniugato (complex x, complex y, complex &z, complex &v);
void carica_complex (complex &A);
void Adt_complex();
void intro();
void menu();
void QuickSort ();
void stampa_vettore (int a[100], int &n);
void carica_vettore (int B[100], int &n);
void stampa_lista ( nodo new_node);
void list ();
pNodo crea_nodo(int elem);
pNodo inserimento_lista_ordinata_ricorsivo(int elem, pNodo head);
pNodo inserimento_lista_ordinata_iterativo (int elem, pNodo pn);
pNodo Insert_in_coda(int elem, pNodo pn);
pNodo cancella_nodo(int elem, pNodo handler);
void stampa(pNodo handler);
using namespace std;
