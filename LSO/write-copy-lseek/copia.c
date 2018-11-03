#include <stdlib.h> /* exec */
#include <errno.h> /* perror */
#include <unistd.h> /* write, read, lseek, close*/
#include <sys/types.h> /* open, lseek */
#include <sys/stat.h> /* open */
#include <fcntl.h> /*open*/
#include <stdio.h>
#define BUFDIM 1000
#define perm 0777

//legge param 1 e lo scrive su param 2

int main ( int argc, char **argv)
{
	int infile,outfile, nread;
	char buffer[BUFDIM];
	int i=1;
	int currpos;
	
	//controllo numero parametri
	if (argc != 3)
	{ 
		printf("errore \n");
       	exit(1);
	}
	
	//legge paramentro 2
	if((infile=open(argv[2], O_RDONLY)) < 0)
	{
		perror("errore apertura file");
		exit(1);
	}
	
	//crea il paramentro 1
	if ((outfile=creat(argv[1], perm)) <0)
	{
		perror("errore creazione");
		close(infile);
		exit(1);
	}
	
	//legge param 1 e lo scrive su param 2
	while( (nread=read(infile, buffer, BUFDIM)) > 0)
	{
		if (write(outfile, buffer, nread) == -1)
		{
			close(infile);
			close(outfile);
			exit(1);
		}
	}
	
	close(infile);
	close(outfile);
	exit(0);
}
