#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAX 4


void gioco (Queue Q1, Queue Q2){

	int i=0;
	int j=0;
	int turno = 1;
	int n1 = dimQueue(Q1);
	int n2 = dimQueue(Q2);

	if ( n1 == n2){

		do{
			int mod = (Q1->A[n1] + Q2->A[n2]);
			printf("\n");
			printf("%d",mod);
			printf("\n");

			if (mod%2 == turno){
				reverseQueue(Q2);
				int put = dequeue(Q2);
				reverseQueue(Q2);
				printQueue(Q2);
			}else{
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
		printQueue(Q1);
	else
		printQueue(Q2);
	}
}

int main(int argc, char *argv[]) {

	Queue Q1 = queueCreationMenu(MAX+2);
	Queue Q2 = queueCreationMenu(MAX+2);

	printQueue(Q1);
	
	printQueue(Q2);


	gioco(Q1,Q2);



	free(Q1);
	free(Q2);

	return 0;
}

