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
#define READLENGTH 10


/*
Scrivere un programma C che prenda come parametro un
file inputFile (controllare che il numero di
argomenti passati sia corretto). Il programma dovrà
aprire tale file, creare un processo figlio, PF che comunica con il processo padre mediante una pipe. Il processo figlio, leggerà i primi 10 caratteri di tale file, scrivendoli nella pipe, il padre, visualizzerà sul video i caratteri scritti dal figlio leggendoli dalla pipe  Esempio inputFile
111111111122222222223333333333444444444455555555556666666666
Output:
Il padre ha letto nella pipe la stringa 1111111111 */

int main (int argc, char **argv)
{
	int infile, fd[2], pid, nread;
	char buf[10];
	
	if (argc != 2)
	{ 
		printf ("uso: nomeprogramma <inputFile> \n"); 
		exit (1); 
	}
	
	/* Apertura file inputFile*/
	if ((infile=open(argv[1], O_RDONLY)) <0)
	{ 
		printf("Errore apertura inputFile %s\n:",argv[1]);
		exit(1); 
	}
	
	if (pipe(fd)<0) 
	{
		perror("pipe");
		exit(1);
	}
	
	/*Esecuzione fork*/
	if ((pid = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}
	
	if (pid == 0) /*Processo Figlio*/
	{
		close(fd[0]); /*chiude il descrittore di lettura della pipe*/
		/*legge i primi 10 caratteri dal file*/
		if ( (nread = read(infile, buf, READLENGTH)) <= 0) 
		{
			close(infile);
			exit(1);
		}
	
		/*scrive i primi 10 nella pipe*/
		if ( (write(fd[1], buf, READLENGTH)) <= 0) 
		{
			close(fd[1]);
			exit(1);
		}
		
		close(fd[1]);
		exit(0);
	}
	else 
	{ 
		/*Processo Padre*/
		close(fd[1]); /*chiude il descrittore per la scrittura sulla pipe*/
		/*legge i primi 10 caratteri dalla pipe*/
		if ( (nread = read(fd[0], buf, READLENGTH)) <= 0) 
		{
			close(fd[0]);
			exit(1);
		}
		
		/*scrive a video primi 10 caratteri*/
		if ( (write(STDOUT_FILENO, buf, READLENGTH)) <= 0) {
			close(fd[0]);
			exit(1);
		}
		
		close(fd[0]);
	}
	
	close(infile);
	exit(0);
}
