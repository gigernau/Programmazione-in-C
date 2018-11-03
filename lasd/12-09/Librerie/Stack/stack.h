#ifndef Library_stack_h
#define Library_stack_h
#define STACK_MAX 128

struct TStack{
	int A[STACK_MAX+1];
};

typedef struct TStack* Stack;

//Attraverso l'interazione con l'utente permette di creare e popolare un nuovo stack.
Stack stackCreationMenu(int n);

Stack initStack();
int emptyStack(Stack);

int dimStack(Stack); //Restituisce il numero di nodi attualmente nello stack

int headStack(Stack S); //Restituisce l'elemento in testa allo stack senza rimuoverlo

int fullStack(Stack);
void push(Stack, int);
int pop(Stack);
void reverseStack(Stack, Stack);
void printStack(Stack);

#endif
