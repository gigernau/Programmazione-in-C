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

int m = 10;//variabile globale

/*
	Scrivere un programma C che accetta un numero
	da riga di comando, crea un Thread che
	intero <n> sommerà ad una variabile globale intera di valore m
	il valore di n ed infine ne stampa il risultato a video.

	Compilazione:
	$ gcc nomeProgramma.c -lpthread
	Esecuzione
	$ ./a.out <n>  */

// Funzione che verrà eseguita dal thread
void *somma(void* arg) 
{	
	int *n = (int*) arg;
	printf ("La somma di m + n è: %d\n", m + (*n));
	sleep(2); /*Aspetta due secondi prima di terminare*/
	pthread_exit(0);
}

int main(int argc, char **argv) 
{
	pthread_t t;
	void* status;
	int arg[1];
	
	if (argc<2)
	{
		printf ("uso: nome_programma <valore> \n");
		exit(1);
	}
	
	arg[0]=atoi(argv[1]); /*valore da sommare*/
	
	if (pthread_create(&t, NULL, somma, arg) != 0) 
	{
		printf ("Errore nella creazione del nuovo thread\n");
		exit(1);
	}
	
	// Attendo che il thread venga terminato
	pthread_join(t, &status);
	printf ("Il thread è terminato con status %d\n", status);
	
}
