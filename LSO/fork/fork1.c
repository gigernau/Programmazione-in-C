#include <stdlib.h> /* exec */
#include <errno.h> /* perror */
#include <unistd.h> /* write, read, lseek, close*/
#include <sys/types.h> /* open, lseek */
#include <sys/stat.h> /* open */
#include <fcntl.h> /*open*/
#include <stdio.h>
#define BUFDIM 1000
#define perm 0777

int main()
{
	int pid;
	
	printf("Unico processo con (PID: %d) ",getpid());
	pid = fork();
	
	if (pid == 0)
	{
		//codice eseguito dal figlio
		printf("\nSono il figlio con (PID: %d) ", getpid());
	}
	else if ( pid > 0 )
	{
		//codice eseguito dal padre
		printf("\nSono il padre con (PID: %d), con processo figlio (PID:%d) ", getpid(),pid);
	}
	else 
	{
		//codice eseguito dal padre in caso errore
		printf("\nSi e' verificato un errore nella chiamata a fork ");
		exit(-1);
	}
	exit(0);
}
