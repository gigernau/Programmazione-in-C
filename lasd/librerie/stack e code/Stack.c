// Stack & Code

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

#define MAX 20

/*==================================================================================================
Libreria Stack

Autori: Gianluca De Lucia     (N86001826)
        Carlo Mennella        (N86001552)
        Giammarco Moscariello (N86001446)
        
A.A  2016/2017
===================================================================================================*/


// Funzioni base

// Controlli sullo stack

int isEmpty(int S[]){
   
    if ( S[0] == 0 ) return 1;
    else return -1;
    
}

int isFull ( int S[])
{
   if  ( S[0] == MAX ) return 1;
   else return -1;
}
/* Push, con gestione dell'errore
 */
void Push(int S[], int valore) {
 
        S[0] = S[0]+1;
        S[S[0]] = valore;
    

}
/* Pop, con gestione dell'errore
 */

int Pop(int S[]) {
    
    int valore = 0;
    
   
        S[0]=S[0]-1;
        valore=S[S[0]+1];
 
    return valore;
}

void Stampa ( int S[], int Top)
{
   if ( Top != 0 ) {
       
       printf (" [%d]\n",S[Top]);
       
       Stampa(S, Top-1);
       
    }
    else printf ("-_\n");
}

void CreaStack ( int S[]) {
    
    int numElementi;
    int valore;
    
    S[0] = 0;
    
    
    printf(" Inserire il numero di elemento, massimo :%d\n\n", MAX);
    scanf(" %d", &numElementi);
    
    while ( numElementi > MAX ) {
    
           printf (" Errore, massimo %d elementi \n\n", MAX);
           
           scanf( " %d", &numElementi);
    }
    while ( numElementi) {
          
          
          printf (" \n . . . \n");
          
          valore = rand() % 9;
          
          Push(S,valore);
          
          --numElementi;
    }
}

int TOP  ( int S[] ) {
    
   if (isEmpty(S) < 0)
       return S[0];
else return 0;
    
}
