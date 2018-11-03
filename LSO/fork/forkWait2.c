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

//esercizio: figlio legge da inputfile 40 caratteri e li mentte in out aggiungendo  pidfiglio poi padre + pidpadre

int main(int argc, char **argv){
	pid_t f;
	int  status, fd_IN, fd_OUT, nread;
	char *buffer=(char*)malloc(sizeof(char)*500);
	char pid[10];

	if( (argv[1] == 0) && (argv[2] == 0) ){
		perror ("input");
		exit(EXIT_FAILURE);
	}
	
	if ((fd_OUT= open(argv[2],O_RDWR|O_CREAT,00700 )) == -1){
		perror("open");
		exit(-1);
	}
	
	
	if( (f=fork())<0){
		perror("fork");
		exit(-1);
	}	
	
	if(f==0)
	{ //sono il figlio	
			
			if ( (fd_IN = open(argv[1],O_RDWR|O_CREAT,00700 )) == -1){
				perror("open");
				exit(EXIT_FAILURE);
			}
			
			
			write(1,"[Figlio]\n", strlen("[Figlio]\n"));
			write(1,"> Lettura file input\n",strlen("> Lettura file output\n"));
			if((nread=read(fd_IN,buffer,40)) == -1){
				perror("read");
				exit(EXIT_FAILURE);
			}
			buffer[nread]='\0';
			
			write(1,"> Scrittura su File_OUT.txt eseguita correttamente\n",strlen("> Scrittura su File_OUT.txt eseguita correttamente\n"));
			write(fd_OUT,buffer,nread);
			
			sprintf(pid,"%d",(int)getpid());
			
			write(fd_OUT,pid,5);
			close(fd_IN);
			
	}
	else{
		//sono il padre
		wait(&status);
		if(WIFEXITED(status))	printf("[Padre]\nValore di uscita: %d\n", WEXITSTATUS(status));
		else		printf("Something goes wrong!\n");
	
		write(1,"> Lettura da file_OUT.txt\n",strlen("> Lettura da file_OUT.txt\n"));
		lseek(fd_OUT,0,SEEK_SET);
		nread=read(fd_OUT,buffer,500);
		buffer[nread]='\n';
		
		write(1,buffer,nread);
		sprintf(pid,"%d",(int)getppid());
		write(fd_OUT,pid,5);
		close(fd_OUT);
		write(1,"\n\n",2);
		
	}
	
	exit(0);
		 
	
}
