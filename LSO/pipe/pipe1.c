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
#define MAXLINE 256
int main (void)
{
	int pid,fd[2]; /*contiene i due descrittori per accedere alla pipe 
	in lettura ed in scrittura*/
	int nread;
	char line[MAXLINE];
	
	
	//restituisce in fd due descrittori fd[0]: per la lettura
	//fd[1]: per la scrittura 
	if (pipe(fd)<0) 
	{
	 	perror("pipe");
		exit(1);
	}
	
	if((pid=fork())<0) /*Creazione di un nuovo processo */
	{
		perror("fork");
		exit(1);
	}
	
	if (pid==0)
	{
		//figlio
		printf("Introduci una stringa da scrivere nella pipe e premi[Enter]\n");
		
		
		if((read(0,line,MAXLINE)) <0)
		{
			perror("read");
			exit(1);
		}
		
		/*chiude il descrittore per leggere dalla pipe*/
		close(fd[0]);
		
		/*Rimane bloccato nel write finchè la pipe è piena*/
		//scrive la stringa nella pipe
		write(fd[1],line,MAXLINE); 
	}
	else
	{
		//padre
		
		/*chiude il descrittore per scrivere nella pipe*/
		close(fd[1]);
		/*Rimane bloccato nel read finchè la pipe è vuota*/
		/*Legge la stringa nella pipe*/
		nread = read(fd[0],line,MAXLINE); 
		/*terminatore di null*/
		line [nread]='\0'; 
		printf("Il padre ha letto nella pipe la stringa %s\n",line);
	}
	
	exit(0);
}
