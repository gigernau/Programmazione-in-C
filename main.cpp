#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <String>
using namespace std;
#include "header.h"
#include "suite.cpp"


main()
{
	
	int cent =0;
	
	int tempo =0;
	cd* playlist = new cd;
	
	intro();
	menu();
	
	cout<<"\n\nLettura canzoni in corso...\n\n";
	leggicanzoni ();
	caricaplaylist (playlist);
	cout<<"\n\nPlayList caricata correttamente!\n\n";
	
	cent = costo (playlist,cent);
	cout<<"\n\nIl costo della PlayList e': "<<costo;
	
	tempo = Reproduction_time (playlist, tempo);
	cout<<"\nIl tempo totale di riproduzione della Playlist e': "<<tempo;
	
}
