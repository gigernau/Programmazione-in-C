/*Scrivere un programma nel quale il padre crea N figli e
invia ad essi M segnali SIGUSR1. Per ogni segnale ricevuto,
ogni figlio stamperà in standard output il proprio pid e il
numero del segnale*/

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
#include <signal.h>
#define N 5
#define M 4

int cont=0;

void handler(int signo)
{ 
  printf("Pid %d: ricevuti n.%d segnali %d\n",getpid(), cont++, signo);
}

int main ()
{
	int pid;
	signal(SIGUSR1, handler);
	
	for(int x=0; x < N; x++)
	{
		pid = fork();
		if (pid == 0) /* figlio */
			printf("\nqualcosa");
		else /* padre */
			for(int x=0; x<M;x++) 
				kill(pid, SIGUSR1);
	}
}
