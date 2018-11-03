#include <stdlib.h> /*exit*/
#include <stdio.h>
#include <errno.h> /*perror*/
#include <unistd.h> /*write, close*/
#include <sys/types.h> /*open*/
#include <sys/stat.h> /*open*/
#include <fcntl.h> /*open*/
#include <string.h> /*strlen*/


int main(void){

	int fd; int nwrite;
	char *data= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	fd=open("alfabeto.txt", O_WRONLY | O_CREAT, 00666); // 00666 corrisponde a RW per usr e grp e r per others
	if(fd < 0 ){
		perror("errore apertura!");
		exit(-1);
	}
	nwrite=write(fd,data,strlen(data));
	if (nwrite < 0 ){
		perror("ERRORE SCRITTURA!");
		exit(-1);
	}

	write(1,"\nScrittura file completata.\n\0", strlen("Scrittura file completata."));
	close(fd);
	exit(0);
}
