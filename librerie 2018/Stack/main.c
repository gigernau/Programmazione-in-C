#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	Stack S=stackCreationMenu(0);
	printStack(S);
	free(S);
	return 0;
}
