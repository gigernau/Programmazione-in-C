
#include <stdio.h>
#include <stdlib.h>


#include "librerie2018/Queue/queue.h"
#include "librerie2018/Input/inputReader.h"

// ELIMINA DISPARI DALLA CODA
// T(n)=O(|DimQueue(Q)|)

void EliminaDispari(Queue Q)
{
  int q;
  if ( !emptyQueue(Q))
    {
       q=dequeue(Q);
       EliminaDispari(Q);
       if ( q%2==0)
  		enqueue(Q,q);
         
     
    }
} //fuori fare reverse Q per avere stato originale



//elimina da dietro se mod%2  = turno
void gioco (Queue Q1, Queue Q2){

  int i=0;
  int j=0;
  int turno = 1;
  int n1 = dimQueue(Q1);
  int n2 = dimQueue(Q2);

  if ( n1 == n2)
  {

    do{
      int mod = (Q1->A[n1] + Q2->A[n2]);
      printf("\n");
      printf("%d",mod);
      printf("\n");

      if (mod%2 == turno)
      {
        reverseQueue(Q2);
        int put = dequeue(Q2);
        reverseQueue(Q2);
        printQueue(Q2);
      }
      else
      {
        reverseQueue(Q1);
        int put = dequeue(Q1);
        reverseQueue(Q1);
        printQueue(Q1);

      }
      n1--;
      n2--;
      turno++;
    }while ((n1 != 0) || (n2 != 0));

	  int num1 = dimQueue(Q1);
	  int num2 = dimQueue(Q2);

	  if (num1 > num2)
	  {
	   printf("\nvince q1: ");
	    printQueue(Q1);
	    }
	  else
	  {
	    printQueue(Q2);
	    printf("\nvince q2: ");
	    }
  }
}



int main(void){
	Queue Q1, Q2;


	printf("\n\n**********Giochiamo con le code**********\n\n");
	Q1= queueCreationMenu(0);
	printf("\n");
	Q2= queueCreationMenu(0);

	printf("\nCoda 1: ");
	printQueue(Q1);

	printf("\nCoda 2: ");
	printQueue(Q2);

	gioco(Q1, Q2);
	printf("\nCoda 1: ");
	printQueue(Q1);

	printf("\nCoda 2: ");
	printQueue(Q2);
	
	printf("\nRinumovi negiati: ");
	Queue Q3= queueCreationMenu(0);
	printQueue(Q3);
	EliminaDispari(Q3);
	printQueue(Q3);
	return 0;
}



