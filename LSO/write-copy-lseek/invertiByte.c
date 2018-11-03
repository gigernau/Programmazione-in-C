#include <stdlib.h> /* exec */
#include <errno.h> /* perror */
#include <unistd.h> /* write, read, lseek, close*/
#include <sys/types.h> /* open, lseek */
#include <sys/stat.h> /* open */
#include <fcntl.h> /*open*/
#include <stdio.h>
#define BUFDIM 1000
#define perm 0777

//legge e inverte param 1
int main ( int argc, char **argv)
{
     int fd, nread;
     int i=1;
     char buffer[BUFDIM];
     int currpos;

     if ( argc != 2)
     {
          perror("errore parametri input");
          exit(1);
     }

	//apre file 1
     if( (fd=open(argv[1], O_RDONLY)) < 0)
     {
          perror("errore apertura");
          exit(1);
     }

     //offset alla fine del file fd(1)
     if ( lseek(fd,0,SEEK_END) < 0)
     {
          perror("errore lseek");
          close(fd);
          exit(1);
     }

     /*Restituisce l’ offset corrente*/
     currpos = lseek(fd,0,SEEK_CUR);
     currpos = currpos-i;

     if (lseek(fd, currpos, SEEK_SET) == -1)
     {
          perror( "lseek errore" );
          close(fd);
          exit( 1 );
     }

     while(( nread=read(fd,buffer,1)) > 0)
     {
          if( write(1,buffer,nread) == -1)
          {
               close(fd);
               exit(1);
          }
          
          //aggiorna la posizione decrementata
          currpos--;
          if(currpos >0)
          {
                 if (lseek(fd, currpos, SEEK_SET) == -1)
                 {
                    perror( "lseek errore" );
                    close(fd);
                    exit( 1 );
                 }
          }
          else 
          {
               //se fine file
               close(fd);
               exit(0);
          }
     }
     
     close(fd);
     exit(0);
}
