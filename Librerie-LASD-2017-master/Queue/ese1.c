#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void rimuovi(Queue Q);
void rimuovi1(Queue Q, int dim);



int main(int argc, const char * argv[]) {
    
    // Creo una coda
    Queue Q = queueCreationMenu(0);
    printQueue(Q);
    rimuovi(Q);

    // Stampo la coda
    printf("Fine\n");
    printQueue(Q);
    printf("Fine\n");
    return 0;
}


void rimuovi(Queue Q)
{
	int dim = dimQueue(Q); 
	rimuovi1(Q,dim);
}

void rimuovi1(Queue Q, int dim)
{
	int elim;
		if (dim > 1)
		{	
			
			if(dim %2 == 0)
			{
				if ((Q->A[dim] %2 == 0) && (Q->A[dim] < Q->A[dim-1]) )
				{
					elim = dequeue(Q);
				}
			}
			else
			{
				if (Q->A[dim] %2 != 0)
				{
					elim = dequeue(Q);
				}
			}

			rimuovi1(Q,dim-1);
		}	
}