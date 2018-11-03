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

int main(int argc, char **argv)
{
	int fd,n;
	
	printf("sono il figlio e scrivo %s su %s \n",argv[2],argv[1]);
	/* Apertura file inputFile*/
	if ((fd=open(argv[1], O_WRONLY|O_CREAT ,S_IRWXU)) <0)
	{ 
		printf("Errore apertura inputFile %s\n:",argv[1]);
		exit(1);
	}
	
	/*scrive la stringa su inputFile */
	if ( (write(fd, argv[2], strlen(argv[2]))) <= 0) 
	{
		close(fd);
		exit(1);
	}
	
	close(fd);
	exit(0);
}
