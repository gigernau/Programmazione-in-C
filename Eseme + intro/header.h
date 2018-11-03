#ifdef _WIN32
		#define CLEAR "cls"
		#define PAUSE "PAUSE"
#else
		#define CLEAR "clear"
		#define PAUSE "pause"
#endif

typedef struct cd{
    string nome;
    string durata;
    cd* succ;
}cd;

typedef cd* playlist; 

void intro();
void menu ();

void leggicanzoni ();
void caricaplaylist (cd* playlist);
int costo (cd* playlist, int cent);
int Reproduction_time (cd* playlist, int tempo);
cd* crea_traccia (string n, string s);

