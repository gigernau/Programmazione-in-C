#include <stdlib.h> /* exec */
#include <errno.h> /* perror */
#include <unistd.h> /* write, read, lseek, close*/
#include <sys/types.h> /* open, lseek */
#include <sys/stat.h> /* open */
#include <fcntl.h> /*open*/
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
	int fd, pid , pid_processo;
	int nread,nwrite,status;
	char *buffer=(char*)malloc(sizeof(char)*500);
	
	if(argc != 2 )
	{
		fprintf(stderr,"Uso: %s nomefile\n", argv[0]);
		exit(-1);
	}
	
	//apertura file in lettura e scrittura
	if((fd=open(argv[1],O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) <0)
	{
		perror("opening argv[1]");
		exit(-1);
	}
	
	pid=fork();
	
	if(pid < 0)
	{
		perror("fork err");
		exit(-1);
	}
	
	if (pid == 0)
	{
		write(1,"\nFiglio: Introduci una stringa e premi [Enter]\n",strlen("Figlio: Introduci una stringa e premi [Enter]\n"));
			nread=read(0,buffer,500);
			buffer[nread]='\0';
			
		//figlio eredita il descrittore fd del padre
		if ((nwrite=write(fd,buffer,strlen(buffer))) ==-1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		//l'I/O pointer si è spostato alla fine del file
		buffer[nwrite]='\0';
		exit(0);
	}
	
	if(pid > 0)
	{
		//pid > 0 Padre
		
		//attesa terminazione figlio
		wait(&status);
		if (WIFEXITED(status))
			printf("padre: figlio ha terminato con status %d\n", WEXITSTATUS(status));
		else
			printf("padre: figlio terminato in modo anomalo!\n");
			
		//riposizionamento a inizio file
		lseek(fd,0,SEEK_SET);
		if((nread=read(fd,buffer,500)) < 0)
		{
			perror("read error");
			exit(-1);
		}
		
		write(1,"Mio figlio ha scritto: ",strlen("Mio figlio ha scritto: "));
	write(1,buffer,strlen(buffer));
		close(fd);
	}
	
	exit(0);
}


