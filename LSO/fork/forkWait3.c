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

//esercizio: figlio legge da inputfile primi 10 caratteri e ultimi10 e li mentte in outfile e padre li visualizza

int main(int argc, char **argv)
{
	
	int  status, fileIN, fileOUT, nread;
	char buffer[10];
	int pid;

	if(argc != 3 )
	{
		perror ("input");
		exit(EXIT_FAILURE);
	}
	
	//apertura fileout
	if((fileOUT=open(argv[2], O_RDWR|O_CREAT,00666 )) <0 )
	{
		perror ("read");
		exit(EXIT_FAILURE);
	}
	
	//fork
	if( (pid=fork())<0)
	{
		perror("fork");
		exit(-1);
	}	
	
	if(pid==0)
	{
		//figlio
		if((fileIN=open(argv[1],O_RDONLY))<0 )
		{
			perror ("read");
			exit(EXIT_FAILURE);
		}
		
		write(1,"[Figlio]\n", strlen("[Figlio]\n"));
		
		//legge i primi 10 caratteri
		if ((nread=read(fileIN, buffer, 10)) < 0)
		{	
			perror ("read");
			close(fileIN);
			exit(EXIT_FAILURE);
		}
		
		//scrive i primi 10 caratteri
		if((write(fileOUT,buffer,10))<0)
		{
			perror("write");
			close(fileOUT);
			exit(EXIT_FAILURE);
		}
		
		//si posiziona alla fine e torna indietro di 10
		if(lseek(fileIN, lseek(fileIN,0,SEEK_END)-11, SEEK_SET) < 0)
		{
			perror ("lseek");
			exit(EXIT_FAILURE);
		}
		
		//legge gli ultimmi 10 caratteri
		if ((nread=read(fileIN, buffer, 10)) < 0)
		{	
			perror ("read");
			close(fileIN);
			exit(EXIT_FAILURE);
		}
		
		//scrive gli ultimi 10 caratteri
		if((write(fileOUT,buffer,nread))<0)
		{
			perror("write");
			close(fileOUT);
			exit(EXIT_FAILURE);
		}
		
		//chiude il proprio file descriptor
		write(1,"Fine processo Figlio\n",strlen("Fine processo Figlio\n"));
		close(fileIN);
		exit(0);
	}
	else
	{
		//processo padre
		
		//wait figlio
		wait(&status);
		if(WIFEXITED(status))
			printf("[Padre]\nValore di uscita: %d\n", WEXITSTATUS(status));
		else		
			printf("Something goes wrong!\n");
			
		write(1,"Inizio processo Padre\n",strlen("Inizio processo Padre\n"));
		
		//si posizione all'ininzio del file da leggere
		if(lseek(fileOUT, 0, SEEK_SET) < 0)
		{
			perror ("lseek");
			close(fileOUT);
			exit(EXIT_FAILURE);
		}
		
		//legge i primi 20 caratteri
		if ((nread=read(fileOUT, buffer, 20)) < 0)
		{	
			perror ("read");
			close(fileOUT);
			exit(EXIT_FAILURE);
		}
		
		//scrive primi 20 carateri
		if((write(STDOUT_FILENO,buffer,nread))<0)
		{
			perror("write");
			close(fileOUT);
			exit(EXIT_FAILURE);
		}
		
		//chiude il proprio file descriptor
		write(1,"Fine processo Padre\n",strlen("Fine processo Padre\n"));
		
		
	}
	
	close(fileOUT);
	exit(0);
	
}
