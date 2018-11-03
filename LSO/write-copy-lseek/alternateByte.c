#include <stdlib.h> /* exec */
#include <errno.h> /* perror */
#include <unistd.h> /* write, read, lseek, close*/
#include <sys/types.h> /* open, lseek */
#include <sys/stat.h> /* open */
#include <fcntl.h> /*open*/
#include <stdio.h>
#define BUFDIM 1000


//legge da file e stampa alternato
int main (int argc, char **argv)
{
     int fd,nread;
     int i=0;
     char buffer[BUFDIM];
     
     //controllo parametri
     if (argc != 2)
     {
          perror ("errore parametri\n");
          exit(-1);

     }

     //apertura file
     if( (fd = open(argv[1], O_RDONLY)) < 0 )
     {
          perror("errore apertura file");
          exit(-1);     
     }

     //lettura per ogni carattere uno si e uno no (i+2)
     while( (nread=read(fd, buffer, 1)) > 0)
     {    
          //scrittura su stdout
          if ( write(0,buffer,nread) < 0)
          {
               close(fd);
               exit(-1);
          }

          i=i+2; //nuovo offset alternato
          if (lseek(fd,i,SEEK_SET) < 0)
          {
               perror("lseek errore!");
               close(fd);
               exit(-1);
          }

     }  
     
     close(fd);
     exit(0);            
}
