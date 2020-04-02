#include <iostream>
#include <fstream>
#include <windows.h>
#include "Medikament.h"
using namespace std;
ifstream in("medicamente.txt");
int main()
{
	Medikament m;
	int n;
	do 
	{
		cout << "1. Adaugarea unui medicament" << endl;
		cout << "2. Stergerea unui medicament" << endl;
		cout << "3. Afisarea unui medicament dupa model" << endl;
		cout << "0. Apasand tasta 0 iesiti din program!!!" << endl;
		cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
		cin >> n;
		if (n == 1)
			m.einfugen_medikament();
		else
			if (n == 2)
				m.delete_medicament();
			else
				if (n == 3)
					m.show_medikamente();
		if (n == 0)
			break;
		Sleep(3000);
		system("CLS");
	} while (n != 0);
	return 0;
}