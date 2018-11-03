#include <stdlib.h> /* exec */
#include <errno.h> /* perror */
#include <unistd.h> /* write, read, lseek, close*/
#include <sys/types.h> /* open, lseek */
#include <sys/stat.h> /* open */
#include <fcntl.h> /*open*/
#include <stdio.h>
#define BUFDIM 1000
#define perm 0777

int main (int argc, char **argv)
{
	int pid;
	int valore =0;
	
	if( argc > 1)
	{
		//trasforma stringa in intero
		valore = atoi( argv[1] );
	}
	
	printf("\nUnico processo con (PID: %d) ",getpid());
	pid = fork();
	
	if (pid == 0)
	{
		//codice eseguito dal figlio
		printf("\nfiglio(PID: %d) > valore iniziale = %d ", getpid(), valore);
		valore+= 15;
		printf("\nfiglio(PID: %d) > valore finale = %d ", getpid(), valore);
		
	}
	else if ( pid > 0 )
	{
		//eseguito dal padre
		printf("\npadre(PID: %d) > generato figlio (PID: %d)",getpid(),pid);
		printf("\npadre(PID: %d) > valore iniziale = %d ", getpid(), valore);	
		valore+=10;
		printf("\npadre(PID: %d) > valore finale = %d ", getpid(), valore);
	}
	else
	{
		printf("\npadre(PID: %d) > problemi con creazione figlio ", getpid());
		exit(-1);
	}
	
	exit(0);
}
