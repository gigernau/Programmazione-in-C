#include <stdlib.h> /* exit */
#include <errno.h> /* perror */
#include <unistd.h> /*write, read, close*/
#include <sys/types.h> /*open*/
#include <sys/stat.h> /*open */
#include <fcntl.h>/*open*/
#include <string.h>
#include <stdio.h>
#define BUFDIM 1000

int main (void)
{
     int fd, nread;
     char buffer [BUFDIM];

     int i=0;

     fd = open("alfabeto.txt", O_RDONLY);
     if( fd == -1)
     {
          perror("errore lettura");
          exit(-1);
     }
     
     /*cicla finchè c’è da leggere*/ //due caratteri per volta
     while( (nread = read (fd,buffer,2) ) > 0 )
     {
          if ( write(1,buffer,nread) < 0 )
          {
               close(fd);
               exit(-1);
          }   
          
          i=i+5; //nuovo offset
          
          if(lseek(fd, i, SEEK_SET) < 0)
          {
               close(fd);
               exit(1);
          }      
     }

     close(fd);
     exit(0);
}
