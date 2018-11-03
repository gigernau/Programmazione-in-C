#ifndef Library_queue_h
#define Library_queue_h
#define QUEUE_MAX 128

struct TQueue {
    int A[QUEUE_MAX+2];
};

typedef struct TQueue* Queue;

Queue queueCreationMenu(int n);

// Inizializza una nuova coda e ritorna un puntatore
// ad una struct di tipo Queue
Queue initQueue();

// Ritorna 1 se la coda e' vuota, altrimenti torna 0
int emptyQueue(Queue);

// Ritorna 1 se la coda e' piena, altrimenti torna 0
int fullQueue(Queue);

int dimQueue(Queue); //Restituisce il numero di nodi attualmente nella coda

// Accoda un elemento nella struttura
// "err", passato per riferimetno dall'esterno
// restera' 0 se non ci sono errori
// altrimenti se l'accodamento non va a buon fine
// poiche' la coda e' piena, err sara' uguale a 2
void enqueue(Queue, int);

// Toglie un elemento dalla struttura
// "err", passato per riferimetno dall'esterno
// restera' 0 se non ci sono errori
// altrimenti se il decodamento non va a buon fine
// poiche' la coda e' vuota, err sara' uguale a 1
int dequeue(Queue);

int headQueue(Queue Q); //Restituisce l'elemento in testa alla coda senza rimuoverlo

// Stampa la coda
void printQueue(Queue);


//capovolge la coda data in input
void reverseQueue(Queue);
#endif
