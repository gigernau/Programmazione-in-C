#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, const char * argv[]) {
    
    // Creo una coda
    Queue coda = queueCreationMenu(0);
    
    // Stampo la coda
    printQueue(coda);
    return 0;
}
