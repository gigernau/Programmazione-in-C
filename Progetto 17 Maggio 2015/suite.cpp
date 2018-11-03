
void Adt_complex ()
{
	int i;
	int scelta;
	complex x,y,z,v;
	char risp;
	double modulo1, modulo2;
	
	
	cout<<"\t\t\t\tA.D.T. Complex\n\n\n";
		
			do{ 	
				cout<<"Immettere due numeri complessi su cui eseguire le operazioni.\n\n";
				cout<<"\tX ===>> ";
			    carica_complex (x);
			    cout<<"\n\n\tY ===>> ";
				carica_complex (y);
			
			
			
				cout<<"\n\nScegli quale operazione svolgere:\n\n";
				cout<<"\t1) Somma\n\t2) Sottrazione\n\t3) Moltiplicazione\n\t4) Divisione\n\t5) Modulo\n\t6) Coniugato\n\n ===>> ";
				cin>>scelta;
				
				switch (scelta)
				{
					case (1):
					{
						cout<<"\n ===>>  SOMMA ";
						z = somma (x,y,z);
						cout<<" ===>>  Z = ("<<z.re<<" , "<<z.im<<"i )";
					}break;
					
					case (2):
					{
						cout<<"\n ===>>  SOTTRAZIONE ";
						z = sottrazione (x,y,z);
						cout<<" ===>>  Z = ("<<z.re<<" , "<<z.im<<"i )";
					}break;
					
					case (3):
					{
						cout<<"\n ===>>  MOLTIPLICAZIONE ";
						z = moltiplicazione(x,y,z);
						cout<<" ===>>  Z = ("<<z.re<<" , "<<z.im<<"i )";
					}break;
					
					case (4):
					{
						cout<<"\n ===>>  DIVISIONE ";
						z = divisione (x,y,z);
						cout<<" ===>>  Z = ("<<z.re<<" , "<<z.im<<"i )";
					}break;
					
					case (5):
					{
						cout<<"\n ===>>  MODULO ";
						modulo(x,y,modulo1,modulo2);
						cout<<" ===>>  Modulo X = "<<modulo1;
						cout<<"\n                ===>>  Modulo Y = "<<modulo2;
					}break;
					
					case (6):
					{
						cout<<"\n ===>>  CONIUGATO ";
						coniugato(x,y,z,v);
						cout<<" ===>>  Coniugato di X = ("<<z.re<<" , "<<z.im<<"i )";
						cout<<"\n                   ===>>  Coniugato di Y = ("<<v.re<<" , "<<v.im<<"i )";	
					}
			}
				
				cout<<"\n\nVuoi fare un'altra operazione <s/n> ? ";
				cin>>risp;
				system ("cls");
				
			}while(risp == 's');
}

complex somma (complex x, complex y, complex z)
{
	z.re = x.re + y.re;
	z.im = x.im + y.im;
	return z;	
}

complex sottrazione (complex x, complex y, complex z)
{
	z.re = x.re - y.re;
	z.im = x.im - y.im;	
	return z;
}

complex moltiplicazione (complex x, complex y, complex z)
{
	z.re = x.re * y.re;
	z.im = x.im * y.im;
	return z;	
}

complex divisione (complex x, complex y, complex z)
{
	z.re = x.re / y.re;
	z.im = x.im / y.im;	
	return z;
}

double modulo (complex x, complex y, double &modulo1, double &modulo2)
{
	modulo1 = sqrt(pow(x.re,2) + pow(x.im,2));
	
	modulo2 = sqrt(pow(y.re,2) + pow(y.im,2));
	
}

void coniugato (complex x, complex y, complex &z, complex &v)
{
	z.re = (x.re);
	z.im = -(x.im);
	
	v.re = (y.re);
	v.im = -(y.im);	
}

void carica_complex (complex& A)
{	
	
	cout<<"  °° Parte Reale = ";
	cin>>A.re;
	cout<<"\n\t\t  °° Parte immaginaria = ";
	cin>>A.im;
	
}













//    QUICK SORT

void QuickSort ()
{
	int  A[100], primo, ultimo,n,i=0;
	
	
		cout<<"\t\t\t\tQuick Sort\n\n\n";
		void QuickSort1 (int A[], int primo, int ultimo);
		carica_vettore(A,n);
		primo=A[i]; ultimo=A[n];
		QuickSort1(A,0,n-1);
		stampa_vettore (A,n);
		system ("PAUSE");
}	


void QuickSort1 (int A[], int primo, int ultimo)
 {
      int i, j, n, temp=0, medio;
 	
			i = primo ; j = ultimo;
			medio = A[(primo + ultimo)/2];
			
			while (i<=j){
				while (A[i] < medio)
					i++;
				while (A[j] > medio)
					j--;
				if (i<= j)
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
					
					i++;
					j--;
				}		
			}
			
			if (primo<j){
			
				QuickSort1 (A,primo, j);
			}
			if (i<ultimo){
				QuickSort1 (A,i,ultimo);
			}
}

void carica_vettore (int B[100], int &n)			//carica vettore
{
	int i;
	
	cout<<"Quanti elementi contiene il vettore? ";
	cin>>n;
	for (i=0; i<n; i++)
	{
		cout<<"\nA["<<i<<"]: ";
		cin>>B[i];
	}
}


void stampa_vettore (int a[100], int &n)				//Stampare vettore
{
	int i;
	cout<<"\n\nVETTORE:\n";
	for (i=0; i<n; i++){
		cout<<"["<<a[i]<<"] ";
	}
}










//  LINKED LIST


void list ()
{
	int elem;
	int scelta,scelta2;
	char risp;
	nodo* head;
	
	head = NULL;
		
	do{
	
		cout<<"\t\t\t\tLinked List\n\n\n";
		
		cout<<"\n\nScegli cosa fare: \n\n";
		cout<<"\t1) Iserisci elemento\n\t2) Stampa lista\n\t3) Elimina\n\n ";
		scelta = _getch();
		
		switch (scelta)
		{
			case '1' :
				{
						cout<<"\n\nScegliere un tipo di algoritmo da eseguire: \n\n";
						cout<<"\t1) Ricorivo\n\t2) Iterativo\n\n";
						scelta = _getch();
						
						switch (scelta)
						{
							case '1' :
								{
									cout<<"\nNuovo elemento da inserire  ===>> ";
									cin>>elem;
									head = inserimento_lista_ordinata_ricorsivo(elem, head);
								}break;
							case '2' :
								{
									cout<<"\nNuovo elemento da inserire  ===>> ";
									cin>>elem;
									head = inserimento_lista_ordinata_iterativo(elem, head);
								}break;
						}
				}break;
			case '2' :
				{
					
					if (head == NULL)
					{
						cout<<"La lista e' vuota!";
					}
					else 
					{
						cout<<" Lista Ordinata :  ";
						stampa(head);
					}
					
				}break;
			case '3' :
				{
					cout<<"\nElemento da eliminare ===>> ";
					cin>>elem;
					head = cancella_nodo(elem, head);
					cout<<"\nElemento eliminato con successo!";
					
				}break;
		}
		
		cout<<"\n\nVuoi tornare indietro? <s/n> ? ";
		cin>>risp;
		system ("cls");
		
	}while((risp == 's') || (risp == 'S'));
	
}

pNodo crea_nodo(int elem){
  Nodo* nodo= new Nodo;
  nodo->info = elem;
  nodo->link = NULL;
  return nodo;
}


pNodo inserimento_lista_ordinata_ricorsivo (int elem, pNodo pn){
  pNodo nuovo_nodo;
  
  if (pn == NULL || pn->info >= elem)
  {
  	nuovo_nodo = crea_nodo(elem);
  	nuovo_nodo->link = pn;
  }
  else if ( pn->info<= elem)
  {
  	nuovo_nodo = crea_nodo(elem);
  	pn->link = nuovo_nodo;
  }
  else inserimento_lista_ordinata_ricorsivo (elem, pn->link);
}



pNodo inserimento_lista_ordinata_iterativo (int elem, pNodo pn){
	pNodo nuovo_nodo, temp, precedente;
	nuovo_nodo = crea_nodo (elem);
	temp = pn;
	precedente = NULL;
	
	while (temp != NULL && temp->info <= elem)
	{
		precedente = temp;
		temp = temp->link;
	}
	if (precedente != NULL)
	{
		precedente->link = nuovo_nodo;
		nuovo_nodo->link = temp;
	}
	else
	{
		nuovo_nodo->link = pn;
		pn = nuovo_nodo;
	}
}


pNodo cancella_nodo(int elem, pNodo handler){
	pNodo handler1;
	if(handler==NULL)
	{
		cout<<"\nLa lista e' vuota!\n";
		return NULL;
	}	
		
		
	else
		if(handler->info==elem){
			handler1=handler->link;
			delete(handler);
			cout<<"\nElemento eliminato con successo! ";
			return handler1;
		}
		else{
			if (handler->link != NULL)
			handler->link= cancella_nodo(elem, handler->link);
			
			return handler;
		}
	
}

void stampa(pNodo handler){
	
		cout << " ° " << handler->info;		
		if (handler->link != NULL)
		{
			stampa(handler->link);
		}
}










//  GESTIONE GRAFICA INIZIALE


void intro(){
		
	system ("color 4F");     // colore sfondo e testo
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *****************\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *    Progetto   *\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *   11.05.2015  *\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t * Prof.Laccetti *\t\t\t   °°°°\n";      
	cout<<"°°°°\t\t\t\t *****************\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°° \t\t\t          Created by Gianluca De Lucia (N86001826) °°°°\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n";
	
	printf("\n\t\t\t\t  *************\n");
	
	// melodia di beep e caricamento	
	Beep(482.4, 250);printf("\t\t\t\t  °°"); Sleep(40);        
	Beep(510, 250);printf("°°"); Sleep(40);
	Beep(546.8, 250);printf("°°"); Sleep(40);
	Beep(596.0, 250);printf("°°"); Sleep(40);
	Beep(646.92, 250);printf("°°"); Sleep(40);
	Beep(729.6, 400);printf("°°"); Sleep(40); printf("°\n");
	Beep(729.6,250);
	Beep(646.92, 250);
	Beep(596.0,250);
	Beep(546.8,250);
	Beep(810,600);
	Beep(282.4,300);
	Sleep(400);
	    
	system ("cls"); //pulizia schermota
	
}

void menu ()
{
	int i;
	
	system ("cls");
	system ("color 4A");
	for(i=0;i<3;i++)
	{
	
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@                                    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@                                    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (100); system ("cls");
		
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°                           @    ";
		cout<<"\n\t\t\t@  ° ° ° °                           @   ";
		cout<<"\n\t\t\t@  °  °  °                           @    ";
		cout<<"\n\t\t\t@  °     °                           @    ";
		cout<<"\n\t\t\t@  °     °                           @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (100); system ("cls");
		
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°                    @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °                        @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°                    @    ";
		cout<<"\n\t\t\t@  °     °  °                        @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°                    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (100); system ("cls");
		
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °           @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °           @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °           @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °           @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°           @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (100); system ("cls");
		
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (100); system ("cls");
	}
	
		cout<<"\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (10); system ("cls");
		
		cout<<"\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (10); system ("cls");
		
		cout<<"\n\n\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (10); system ("cls");
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (10); system ("cls");
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
		
		cout<<"\n\n\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
		
		cout<<"\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
		
		cout<<"\n\n\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
		
		cout<<"\n\n\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
		
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
		
		
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (30); system ("cls");
	
	for (i=0; i<3; i++)
	{	
        system ("cls");	
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (200); system ("cls");
		
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@                                    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@                                    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		Sleep (200); system ("cls");
		
		cout<<"\n\n";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
	}
}

