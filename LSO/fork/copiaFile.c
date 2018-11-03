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
#define READLENGTH 256


//esercizio: con exec cp da in a out

int main(int argc, char **argv)
{
	int outfile,nread,status;
	pid_t processo;
	char buf[READLENGTH];
	
	if(argc != 3 )
	{
		perror ("input");
		exit(EXIT_FAILURE);
	}
	
	printf("Sono processo iniziale (PID:%d)\n",getpid());
	processo = fork();
	
	if (processo < 0)
	{
		perror("fork");
		exit(-1);
	}
	
	if(processo == 0)
	{
		//figlio
		printf("esegue comando 'cp'\n");
		
		if (execl("/bin/cp", "cp", argv[1], argv[2], (char *)0) < 0)
		{
			perror("ERRORE: exec fallita");
			exit(1);
		}
	}
	else
	{
		//padre
		//wait figlio
		wait(&status);
		if(WIFEXITED(status))
			printf("[Padre]\nValore di uscita: %d\n", WEXITSTATUS(status));
		else		
			printf("Something goes wrong!\n");
			
		//apertura file out
		if ((outfile=open(argv[2], O_RDONLY)) <0)
		{ 
			printf("Errore apertura outputFile da leggere %s\n:",argv[2]);
			exit(1); 
		}
		
		/*legge i caratteri*/
		if ( (nread = read(outfile, buf, READLENGTH)) <= 0)
		{
			close(outfile);
			exit(1);
		}
		
		/*scrive i caratteri a video*/
		if ( (write(STDOUT_FILENO, buf, nread)) <= 0) 
		{
			close(outfile);
			exit(1);
		}
			
		close(outfile);
		exit(0);
	}
	
}
