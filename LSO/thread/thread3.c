/*Scrivere un programma C che crea due Thread
“somma1” e “somma2”, entrambi accedono alle variabili
test.a e test.b di una struttura dati test condivisa
incrementandole di 1 per 10 volte, aspettano 2 secondi
prima di stampare a video i valori delle due variabile.
Supporremo che tale accesso non venga
regolamentato da alcun meccanismo di gestione della concorrenza. */

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

#define CICLI 10 /*Costante usata per incrementare le variabili*/

struct test {/* Memoria Condivisa fra i thread */
	int a;
	int b;
} mytest;

/* dichiarazione delle due funzioni dei due thread*/
void *somma1(void *in)//Funzione che verrà eseguita dai thread
{
	int i;
	for(i=0; i<CICLI; i++) 
	{
		mytest.a++;
		mytest.b++;
		/* sleep di 2 secondi */
		sleep(2);
		printf("somma1 -- a = %d \n", mytest.a);
		printf("somma1 -- b = %d \n", mytest.b);
	}
	pthread_exit(0);
}

void *somma2(void *in)
//Funzione che verrà eseguita dal t2
{
	int i;
	for(i=0; i<CICLI; i++) 
	{
		mytest.a++;
		mytest.b++;
		sleep(2);
		printf("somma2 -- a = %d \n", mytest.a);
		printf("somma2 -- b = %d \n", mytest.b);
	}
	pthread_exit(0);
}

int main(void)
{
	pthread_t som1TID, som2TID;
	
	/* Inizializzo la memoria condivisa */
	mytest.a = 0;
	mytest.b = 0;
	
	/* A questo punto posso creare i thread */
	if (pthread_create(&som1TID, NULL, somma1, NULL) != 0) {
	printf ("Errore nella creazione del thread somma1\n");
	exit(1);
	}
	/* A questo punto posso creare i thread .... */
	if (pthread_create(&som2TID, NULL, somma2, NULL) != 0) {
	printf ("Errore nella creazione del thread somma2\n");
	exit(1);
	}
	/* A questo punto aspetto che i due thread finiscano */
	pthread_join(som1TID, NULL);
	pthread_join(som2TID, NULL);
	printf("E' finito il programma ....\n");
	exit (0);
}
