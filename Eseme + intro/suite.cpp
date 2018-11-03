cd* crea_traccia (string n, string s){
  cd* traccia = new cd;
  traccia->nome = n;
  traccia->durata = s;
  traccia->succ = NULL;
  return traccia;
}

void leggicanzoni ()
{
	fstream file ("Music.txt");
	string s;
	
	while (file.good())
	{
		getline (file, s);
		cout<<s<<endl;
	}
	file.close();	
}


void caricaplaylist (cd* playlist)
{
	fstream file ("Music.txt");
	string s, n;
	cd* traccia;

	
	while (file.good())
	{
		getline (file, n);
		getline (file, s);
		traccia = crea_traccia (n,s);
		traccia->succ=playlist;
		traccia->succ = playlist;
	}
	
	file.close();	
}

int Reproduction_time (cd* playlist, int tempo)
{
	
	
	int sec = atoi (playlist->durata.c_str());
	if (playlist->succ != NULL)
	{
		sec = Reproduction_time (playlist->succ,tempo);
	}
		
	return sec;
}


int costo (cd* playlist, int cent)
{
		
	if (playlist->succ != NULL)
	{
		cent++;
		cent = costo (playlist->succ, cent);
	}

	return cent;
}


//GESTIONE GRAFICA

void intro(){
	
	int i;	
	
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t\t\t\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *****************\t\t\t   °°°°\n";
	cout<<"°°°°\t\t\t\t *     Prova     *\t\t\t   °°°°\n";
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

