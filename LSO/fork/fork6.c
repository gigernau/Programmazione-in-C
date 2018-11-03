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
#define BUFFSIZE 4096 /* max.num. di caratteri in buf */


int main(int argc, char **argv)
{
	pid_t pid;
	int status;
	int fd,n;
	char buffer[BUFFSIZE];
	
	if (argc != 3)
	{ printf ("uso: trasfile <file> <stringa> \n"); exit (1); }
	
	
	//INIZIO FORK
	pid = fork();
	
	if (pid < 0)
	{
		perror("ERRORE: fork fallita");
		exit(1);
	}
	
	
	if (pid == 0)
	{ 
		/*Processo figlio e mando execlp*/
		if (execlp("./scriviStringa", "scriviStringa", argv[1], argv[2], (char *)0)
		< 0)
		{
			perror("ERRORE: exec fallita");
			exit(1);
		}
		
	} 
	else 
	{ 
		/*Processo Padre*/
		wait(&status); /*attende la terminazione del figlio*/
		
		printf("Sono il padre e leggo\n" );
		/* Apertura file inputFile*/
		if ((fd=open(argv[1], O_RDONLY)) <0)
		{ 
			printf("Errore apertura inputFile da leggere %s\n:",argv[1]);
			exit(1); 
		}
		
		/*leggo la stringa*/
		if ( (n = read(fd, buffer, BUFFSIZE)) <= 0) 
		{
			close(fd);
			exit(1);
		}
		
		printf("Stringa: %s",buffer);
		close(fd);
	}
	exit(0);
	
}
