#include <stdio.h>
#include <stdlib.h>
#include "Librerie/Stack/stack.h"
#define MAX 6

void gioca (Stack S1, Stack S2);
void gioca1(Stack S1, Stack S2);

int main(int argc, char *argv[]) {

	Stack S1 = stackCreationMenu(MAX+1);
	Stack S2 = stackCreationMenu(MAX+1);
	printStack(S1);
	printStack(S2);

	gioca(S1,S2);
	free(S1);
	free(S2);
	return 0;
}

void gioca1(Stack S1, Stack S2)
{
	if(!emptyStack(S1) && !emptyStack(S2))
	{
		//se sono uguale dim
		//si confronta somma 

		int val1 = pop(S1); 
		int val2 = pop(S2);
		if((val1 + val2)%2==0)
		{
			//se pari
			push(S1,val1);
		}
		else //se dispari
			push(S2,val2);

		printf("\nStack: \n");
		printStack(S1);
		printStack(S2);
		gioca1(S1,S2);
	}

}
void gioca (Stack S1, Stack S2)
{
	if(dimStack(S1) == dimStack(S2))
	{
		gioca1(S1,S2);
	}
	
	if(dimStack(S1) < dimStack(S2))
	{
		printf("\nVince S2");
		return;
	}	
	else
	{
		printf("\nVince S1");
		return;
	}
}