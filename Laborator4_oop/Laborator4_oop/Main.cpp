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
	int ok = 1;
	do 
	{
		cout << "1. Adaugarea unui medicament" << endl;
		cout << "2. Stergerea unui medicament" << endl;
		cout << "3. Afisarea unui medicament dupa model" << endl;
		cout << "4. Afisare unui medicament dupa concetratie" << endl;
		cout << "5. Afisare medicamentelor dupa pret" << endl;
		cout << "6. Undo/Redo" << endl;
		cout << "0. Apasand tasta 0 iesiti din program!!!" << endl;
		cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
		cin >> n;
		if (n == 1)
			m.einfugen_medikament(), ok = 0;
		else
			if (n == 2)
				m.delete_medicament(), ok = 0;
			else
				if (n == 3)
					m.show_medikamente();
				else
					if (n == 4)
						m.Cautare();
					else
						if (n == 5)
							m.Grupare();
						else
							if (n == 6) {
								if (ok == 0)
								{
									m.Undo();
									ok = 1;
								}
								else
									cout << " Ati efectuat deja o data UNDO/REDO. Modificati farmacia pentru UNDO/REDO";
							}
		if (n == 0)
			break;
		Sleep(3000);
		system("CLS");
	} while (n != 0);
	return 0;
}