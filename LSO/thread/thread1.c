#include <stdio.h> /* perror */
#include <errno.h> /* perror */
#include <unistd.h> /* write, lseek, close*/
#include <sys/types.h> /*open, lseek */
#include <sys/stat.h> /*open */
#include <fcntl.h> /*open*/
#include <stdlib.h> /*exit*/
#include <string.h> /*strlen*/
#include <sys/wait.h> /*wait*/
#include <sys/types.h> /*wait*/
#include <pthread.h>
#define READLENGTH 10

/*Scrivere un programma C che crea un “Thread” ed
attende la terminazione dello stesso
Compilazione:
Opzione di
compilazione
$ gcc nomeProgramma.c -lpthread */

// Funzione che verrà eseguita dal thread
void *start(void* arg) 
{
	printf ("Sono un thread richiamato dal processo padre\n");
	pthread_exit(-8);
}

int main() 
{
	// Identificatore del thread
	pthread_t t;
	void *status;
	
	if (pthread_create(&t, NULL, start, NULL) != 0) 
	{
		printf ("Errore nella creazione del nuovo thread\n");
		exit(1);
	}
	
	// Attende che il thread venga terminato
	pthread_join(t, &status);
	printf ("Il thread è terminato con status %d\n",status);
}

