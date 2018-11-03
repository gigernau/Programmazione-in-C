#ifdef _WIN32
		#define CLEAR "cls"
		#define PAUSE "PAUSE"
#else
		#define CLEAR "clear"
		#define PAUSE "pause"
#endif

typedef struct dna{
    string info;
    dna* link;
}dna;

void Stampa_DNA (dna* head);

dna* aggiungi_elemento (string elem, dna* head);
int conta_ATT (dna* head, int* stato, int* conta);
void intro();
void menu ();
