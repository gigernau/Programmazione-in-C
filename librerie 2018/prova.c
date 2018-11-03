
/*Si considerino due stack 
Pari  e Dispari
, implementatati con array
, riempiti con interi
. 
Si implementi la funzione ricorsiva 
void gioca 
che, utilizzando una libreria di funzioni 
proceda a turni nel modo seguente. Ad ogni turno calcola la somma di Pari+Dispari se la 
somma è pari si toglie da Pari il numero minimo, altrimenti si toglie da Dispari. Il gioco 
finisce quando uno degli stack diventa vuoto. Si ricordi che la coda è una struttura dati 
che permette l’accesso ai suoi dati solo dalla testa. Si implementi una funzione che 
permetta di stampare ogni round.*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack/stack.h"
#include "Input/inputReader.h"

int somma(Stack S);
int mm(Stack S,int min)
{
    int value;
    if(!emptyStack(S))
    {
        value=pop(S);
       
        if(!emptyStack(S))
        {
          min= mm(S,min);
        }
        else
         min=100;
         
         if (value < min)
             min=value;
             
        push(S,value);
    }
    
    return min;
}

int somma(Stack S){
    int sommav;
    int value;
    if(!emptyStack(S)){
        value=pop(S);
       
        if(!emptyStack(S)){
            sommav=value+somma(S);
            
        }else 
        	sommav=value;
        	
        push(S,value);
    }return sommav; 
}

//elimina il minimo
void elimina(Stack S,int min){
    int value;
    if(!emptyStack(S)){
        value=pop(S);
      
        if(!emptyStack(S)){
            elimina(S,min);
        }
        if (value>min){
        
            push(S,value);
        }
    }
}

void gioco(Stack S,Stack S2){
    int sommap=0;
    int sommad=0;
    int min=100;
    int i=0;
    while(!emptyStack(S) && !emptyStack(S2))
        {
            i++;
            sommap=somma(S);
            sommad=somma(S2);
            if((sommad+sommap)%2==0){
                printf("\nla somma e pari\n ");
                min=mm(S,min);
                elimina(S,min);
            }
            else 
            {
                printf("\nla somma e dispari \n");
                min=mm(S2,min);
                elimina(S2,min);
            }
            
            printf("\nminimo %d ",min);
            printf("\nvuoi stampare la mossa : %d " ,i);
            printf("\nvettore pari\n");
            printStack(S);
            printf("\nvettore dispari\n");
            printStack(S2);
        }
    
   printf("\nE' finita la partita");
}
   
