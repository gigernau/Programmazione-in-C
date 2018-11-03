dna* crea_nodo (string elem){
  dna* nodo = new dna;
  nodo->info = elem;
  nodo->link = NULL;
  return nodo;
}

void Stampa_DNA(dna* head)
{
	if (head != NULL)
	{
		cout<<"["<<head->info<<"] ";
		Stampa_DNA(head->link);
	}
			
}

dna* aggiungi_elemento (string elem, dna* head)
{
    dna* nodo;
	nodo = crea_nodo (elem);

    if (head != NULL)
    {
        
        nodo->link = head;
        cout<<"\nElemento aggiunto con successo!\n";
        head = nodo;
    }
    else
    {
    	head = nodo;
        cout<<"\nE' stato creato un nuovo DNA!\n";
    }

    return head;
}


int conta_ATT (dna* head, int stato, int conta)
{
	
	if (stato == 0)
	{
		if (head->info == "A")
		stato++;
	}
	else if (stato == 1)
	{
		if (head->info == "T")
			stato++;
		else 
			stato = 0;
	}
	else if (stato == 2)
	{
		if (head->info == "T" )
		{
			stato = 0;
			conta++;
		}
		else 
		{
			stato = 0;
		}
			
	}

	
	if (head->link != NULL)
	{
		conta = conta_ATT (head->link, stato, conta);
	}
	
	return conta;
	
}

void intro(){
	
	int i;	
	
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *****************\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *    Esercizi   *\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *   25.05.2015  *\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *   Prof.Cuomo  *\t\t\t   °°°°\n";      
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
	
	for(i=0;i<1090000000;i++);
	system (CLEAR);

}

void menu ()
{
	int i;
	
	
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
		 for(i=0;i<100090000;i++);system (CLEAR);
		
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
		 for(i=0;i<100090000;i++);  system (CLEAR);
		
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
		for(i=0;i<100090000;i++); system (CLEAR);
		
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
		for(i=0;i<100090000;i++); system (CLEAR);
		
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
		for(i=0;i<100090000;i++); system (CLEAR);
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++);system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++); system (CLEAR);
		
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
		for(i=0;i<10000000;i++);system (CLEAR);
		
		
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ";
		cout<<"\n\t\t\t@                                    @  ";
		cout<<"\n\t\t\t@  °°   °°  °°°°°  °°    °  °    °   @    ";
		cout<<"\n\t\t\t@  ° ° ° °  °      ° °   °  °    °   @   ";
		cout<<"\n\t\t\t@  °  °  °  °°°°°  °  °  °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °      °   ° °  °    °   @    ";
		cout<<"\n\t\t\t@  °     °  °°°°°  °    °°   °°°°    @   ";
		cout<<"\n\t\t\t@                                    @    ";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ";
		for(i=0;i<10000000;i++); system (CLEAR);
	
	for (i=0; i<5; i++)
	{	
        system (CLEAR);
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
		for(i=0;i<100000000;i++); system (CLEAR);
		
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
		for(i=0;i<100000000;i++); system (CLEAR);
		
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
		for(i=0;i<100000000;i++)	;
	}
}

