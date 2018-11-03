#ifndef code_H_
#define code_H_

#define MAX_EL 128

struct Tqueue{
	int array[MAX_EL+1];
	};
typedef struct Tqueue* coda;

coda coda_inizial();
int coda_vuota(coda C);
int coda_piena(coda C);
void coda_random(coda C, int size);
void stampa_coda(coda C);
void coda_insert(coda C,int val);
int elimina_elem(coda C);
void coda_inversa(coda C);
void stampa_bis(coda C);
#endif
