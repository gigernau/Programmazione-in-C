#include <iostream>
using namespace std;
#include "header.h"
#include "suite.cpp"
main()
{
    int scelta, att;
	dna* head = NULL;
    string elem;
	int stato = 0;
	int conta = 0;
	
	intro();
	menu();

    do{

        cout<<"\n\n\nScegli cosa fare:\n\t1) Stampa\n\t2) Aggiungi Elemento\n\t3) Conta sequenza A-T-T\n\t4) Esci\n";
        cin>>scelta;

        switch (scelta)
        {
            case (1):
                {
                    if (head == NULL)
                    {
                      cout<<"La lista e' vuota!\n";
                    }
                    else
                    {
                    	cout<<"\n\nLISTA:\n";
                    	Stampa_DNA (head);
                    	cout<<"\nLista terminata!\n";
                    }
                }break;
            case (2):
                {
                    cout<<"\n\nQuale elemento vuoi aggiungere? <A,T,G,C>\n";
                    cin>>elem;
                    head = aggiungi_elemento (elem, head);
					
                }break;
            case (3):
                {
					att = conta_ATT (head,stato,conta);
						cout<<"\nNel DNA sono presenti "<<att<<" sequenze A-T-T !\n";
                }break;
            case (4):
                {
                    cout<<"\nArrivederci!";
                    
                }break;
                
        }
		system (PAUSE);
        system(CLEAR);
        
        
       }while(scelta > 0 && scelta < 4);
    }


