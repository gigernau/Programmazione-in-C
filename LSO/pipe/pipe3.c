/*Scrivere un programma C che realizzi una comunicazione
bidirezionale tra il processo padre ed il processo figlio
mediante la creazione di due pipe distinte “pipe1” , “pipe2” Il
programma
dovrà creare le due pipe ed il processo figlio. Il
processo padre, scriverà sulla pipe1 (pdf1) un messaggio
immesso da tastiera, il processo figlio leggerà tale messaggio
dalla pipe1 (pdf1), lo stamperà a video e scriverà la notifica di
lettura sulla pipe2 (pdf2) che verrà poi letta dal padre e
stampata a video. (Utilizzare la funzione fgets per leggere un
messaggio con spazi inserito da tastiera)
Esecuzione: ./a.out Inserire il messaggio e premere [ENTER]
Output:
Il processo figlio ha ricevuto il messaggio: <xxxxxx>
Il processo padre ha ricevuto la notifica di lettura del
messaggio <xxxxxx> */

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
#define SIZE 128

int main(int argc, char **argv) 
{

	int pfd1[2], pfd2[2]; /*descrittori di pipe*/ // sono 2 perchè bidirezionale
	int nread, pid;
	char inBuf[SIZE], outBuf[SIZE];
	
	if (pipe(pfd1)!= 0 || pipe(pfd2)!=0) 
	{ 
		/*creazione delle due pipe*/
		perror("pipe() fallita)");
		exit(-1);
	}
	
	if ((pid=fork()) < 0 ) 
	{ 
		/*creazione del processo figlio*/
		perror("fork() fallita");
		exit(-2);
	}
	
	if (pid==0) 
	{ 
		/* figlio */
		close(pfd1[1]); /*descrittore di lettura pipe1 */
		close(pfd2[0]); /*descittore di scrittura pipe2 */
		/* legge un messaggio dal padre */
		nread=read(pfd1[0], inBuf, SIZE); /*legge il messaggio da
		pipe1*/
		inBuf[nread]='\0'; /*terminatore di null */
		close(pfd1[0]);
		
		printf("Il figlio ha ricevuto il messaggio: %s\n", inBuf);
		/* manda un messaggio indietro di notifica lettura su
		pipe2*/
		write(pfd2[1],inBuf,strlen(inBuf));
		close(pfd2[1]);
	}
	
	else 
	{ 
		/* padre */
		close(pfd1[0]); /*descrittore di scrittura pipe1 */
		close(pfd2[1]); /*descrittore di lettura pipe2 */
		printf("Inserire il Messaggio e premere [ENTER]"); // legge un msg da tastiera
		fgets(outBuf,SIZE,stdin);
		
		 /*Scrittura su pipe1 il mess*/
		write(pfd1[1], outBuf, strlen(outBuf));
		close(pfd1[1]);
		
		/* leggi il messaggio di notifica lettura del figlio */
		nread = read(pfd2[0],inBuf,SIZE); /*Lettura su pipe2*/
		inBuf[nread]='\0'; /*terminatore di null */
		close(pfd2[0]);
		printf("Il padre ha ricevuto la notifica di lettura del messaggio: %s\n",inBuf);
	}

	exit(0);	
}

