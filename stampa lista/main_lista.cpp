#include <iostream>
#include <conio.h>
#include "mialista.h"
#include <fstream>

using namespace std;

int main(){
  int scegli,elem,pn; 
  pNodo head = NULL;
  
  
  do{
     cout << "inserire una opzione:"<<endl;
     cout << "1 - Inserimento in testa"<<endl;
     cout << "2 - Inserimento in coda"<<endl;
     cout << "3 - Ricerca di un valore"<<endl;
     cout << "4 - cancella un nodo"<<endl;
     cout << "5 - stampa il valore "<<endl;
     cout << "6 - scrivi su file "<<endl;
     cout << "7 - EXIT"<<endl;
     
     scegli = _getch();
     
     
     
     switch(scegli){
	    case '1':
		   cout << "Inserisci valore:"<<endl;
		   cin >> elem;  
            	   head =Insert_in_testa(elem,head);  
                   break;  
        case '2':
		   cout << "Inserisci valore:"<<endl;
		   cin >> elem;  
                   head=Insert_in_coda(elem,head);  
                   break;  
        case '3':               
		   cout << "Inserisci valore:"<<endl;
		   cin >> elem;  
                   if(Ric_valore(elem,head)!=NULL){
			cout << "il valore cercato e' presente"<<endl;
		   } 
		   else{
		        cout << "Il valore cercato non e' presente"<<endl;
                   } 
                   break;  
        case '4':
		   cout << "Inserisci il valore da cercare:"<<endl;;
		   cin >> elem;  
                   head =cancella_nodo(elem,head);    
                   break;      
        case '5':
                   stampa(head);  
                   break;      
        case '7':
                   cout << "Fine "<<endl;  
                   break;
                   
        case '6':
        	
        			scrivifile (head);
        			cout<<"\nScrittura avvenuta con successo!\n";
        			cout<<"E' stato scritto:\n\n\n";
        			leggifile ();
        			cout<<"\n\n\n";
        			break;
		default:
                    cout << "\nIl valore di scelta non e' definito\n"<<endl;
					break;                                        
            
     }                       
  }while(scegli!= '7');

  return 0;
	
}

pNodo crea_nodo(int elem){
  Nodo* nodo= new Nodo;
  nodo->info = elem;
  nodo->link = NULL;
  return nodo;
}


pNodo Insert_in_testa(int elem, pNodo pn){
  pNodo Testa;
  Testa = crea_nodo(elem); 
     
  if(pn!=NULL){
      Testa->link = pn;       
  }
  return Testa;  
}

pNodo Insert_in_coda(int elem, pNodo pn){
	
  if(pn==NULL){
    return crea_nodo(elem);     
  }
  else{
      pn->link = Insert_in_coda(elem, pn->link);
      return pn;
  }  
}

pNodo Ric_valore(int elem, pNodo pn){
  if(pn==NULL){
    return NULL;     
  }
  else if(pn->info == elem ){
      return pn;
  } 
  else{
      return Ric_valore(elem, pn->link);
  }
}

pNodo cancella_nodo(int elem, pNodo handler){
	pNodo handler1;
	if(handler==NULL)
		return NULL;
	else
		if(handler->info==elem){
			handler1=handler->link;
			delete(handler);
			return handler1;
		}
		else{
			handler->link= cancella_nodo(elem, handler->link);
			return handler;
		}
	
}

void stampa(pNodo handler){
	if (handler==NULL){
		cout << endl;
		
	}
	else{
		cout << handler->info<< " ";
		stampa(handler->link);
	}
}

void scrivifile (pNodo head)
{
	fstream file("prova.txt");
	
   	file<<"lista:\n";
   	while (head != NULL)
   	{
   		file<<head->info<<"  ";
   		head = head->link;
   	}
   	file.close ();
}

void leggifile ()
{
	fstream file ("prova.txt");
	string s;
	
	while (file.good())
	{
		getline (file, s);
		cout<<s<<endl;
	}
	file.close();	
}



