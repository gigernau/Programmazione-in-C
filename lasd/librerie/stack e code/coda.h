
#define MAX 128

/*==================================================================================================
Libreria Code

Autori: Gianluca De Lucia     (N86001826)
        Carlo Mennella        (N86001552)
        Giammarco Moscariello (N86001446)
        
A.A  2016/2017
===================================================================================================*/

struct Tcode{
    int A[MAX+1];
};
typedef struct Tcode *coda;

// Inizializza una nuova coda e ritorna un puntatore
// ad una struct di tipo Queue
int* inicoda();

// Ritorna 1 se la coda e' vuota, altrimenti torna 0
int empty(int *);

// Ritorna 1 se la coda e' piena, altrimenti torna 0
int pieno(int *);
void reverse(int *C);
// Accoda un elemento nella struttura
// "errore", passato per riferimetno dall'esterno
// restera' 0 se non ci sono errori
// altrimenti se l'accodamento non va a buon fine
// poiche' la coda e' piena, err sara' uguale a 5
void accoda(int *, int);

// Toglie un elemento dalla struttura
// "err", passato per riferimetno dall'esterno
// restera' 0 se non ci sono errori
// altrimenti se il decodamento non va a buon fine
// poiche' la coda e' vuota, err sara' uguale a 6
int decoda(int *, int*);

// Stampa la coda
void print(int *);

void printer(int *C, int);


