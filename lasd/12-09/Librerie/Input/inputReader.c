#include <stdio.h>
#include <stdlib.h>
#include "inputReader.h"

void clearBuffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { };
}

int getPositive(int *data){
	int ok, // ritorno della funzione 
		i; // indice per scorrere la stringa letta
	char buffer[51];
	
	scanf("%50s",buffer);
	clearBuffer();
	
	i = 0;
	
	while( buffer[i]>47 && buffer[i]<58 ) i++;
	
	ok = (buffer[i]=='\0' && i>0 );
	
	if(ok) *data = atoi(buffer);
	
	return ok;
}

int getFloat(float *f){
	char buffer[51];
	int cont, //indice per lo scorrimento dell'input utente
		off, //lunghezza minima della stringa (in base alla presenza del punto e/o del segno negativo)
		ret;
	
	scanf("%50s",buffer);
	clearBuffer();
	
	cont = off = (buffer[0]=='-') ? 1 : 0;
	while(buffer[cont]>47 && buffer[cont]<58) cont++;
	if(buffer[cont]=='.'){
		cont++;
		off++;
		while(buffer[cont]>47 && buffer[cont]<58) cont++;		
	}
	
	ret = (buffer[cont]=='\0' && cont>off);
	
	if(ret)
		*f = atof(buffer);
		
	return ret;
}

int getInt(int *data){
	int ok, // ritorno della funzione 
		i, // indice per scorrere la stringa letta
		negative; // indica se il numero è negativo
	char buffer[51];
	
	scanf("%50s",buffer);
	clearBuffer();
	
	i = negative = (buffer[0]=='-') ? 1 : 0 ;
	
	while( buffer[i]>47 && buffer[i]<58 ) i++;
	
	ok = (buffer[i]=='\0' && i>negative );
	
	if(ok) *data = atoi(buffer);
	
	return ok;
}
