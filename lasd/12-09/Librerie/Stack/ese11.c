#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



void raddoppia (Stack S);

int main(int argc, char *argv[]) {

	Stack S = stackCreationMenu(0);
	printStack(S);

	raddoppia (S);

	printStack(S);

	free(S);
	return 0;
}

void raddoppia (Stack S)
{
	int s;

	if(!emptyStack(S))
	{
		s = pop(S);
		raddoppia(S);
		push(S,s);
		push(S,s);
	}
	
}
