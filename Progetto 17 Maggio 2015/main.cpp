#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h.>
#include <math.h>

using namespace std;
#include "suite.h"
#include "suite.cpp"


int main ()
{
	int scelta,risp;
	
	intro();
	menu();
			
	system ("color 4F");
	Sleep(400);
	cout<<"\n\n\n\t\t\t\tCosa desideri fare?\n\n";
	cout<<"  \t\t\t\t1) A.D.T Complex\n";
	cout<<"  \t\t\t\t2) Quick Sort\n";
	cout<<"  \t\t\t\t3) Linked List\n";
	cout<<"  \t\t\t\t4) Esci\n\n\n";
	 
	scelta = _getch();
	system("cls");
	
		switch (scelta)
		{
			case '1':
			{
				Adt_complex();
				
				
			}break;
			
			case '2':
			{
			 	 QuickSort ();
				 	 
				 	
			}break;
			
			case '3':
			{
				list();
			
			}break;
			
			case '4' :
			{
				cout<<"Ciao alla prossima!";
				_getch();
				
			}break;
				
		}
		
	return 0;	
	
}
