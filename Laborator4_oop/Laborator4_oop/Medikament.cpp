#include "Medikament.h"
#include <iostream>
#include <sstream>
#include<vector>
#include <fstream>
#include<algorithm>
using namespace std;
//constructoru implicit
vector<Medikament> c;

Medikament::Medikament()
{
	name = "";
	konzentration = 0;
	preis = 0;
	menge = 0;
}
//constructoru in cazu in care dam parametrii
Medikament::Medikament(string nume, int concentratie, int pret, int cantitate)
{
	name = nume;
	konzentration = concentratie;
	preis = pret;
	menge = cantitate;
}
//setteru pentru nume
void Medikament::set_nume(string nume)
{
	name = nume;
}
//setteru pentru concerntratie
void Medikament::set_concentratie(int concentratie)
{
	konzentration = concentratie;
}
//setteru pentru pret
void Medikament::set_pret(int pret)
{
	preis = pret;
}
//setteru pentru cantitate
void Medikament::set_cantitate(int cantitate)
{
	menge = cantitate;
}
//getteru pentru nume
string Medikament::get_nume()
{
	return name;
}
//getteru pentru concentratie
int Medikament::get_concentratie()
{
	return konzentration;
}
//getteru pentru pret
int Medikament::get_pret()
{
	return preis;
}
//getteru pentru cantitate
int Medikament::get_cantitate()
{
	return menge;
}
//verifica daca exista medicamentul in fisier
int Medikament::verificare_medicament_existent(string nume)
{
	Medikament temp;
	ifstream in("medicamente.txt", ios::in);
	while (in >> temp.name >> temp.konzentration >> temp.preis >> temp.menge)//ia pe rand randurile
		if (nume == temp.name)//daca numele ii la fel cu cel introdus de la tastatura
			return 1;
	return 0;

}
//schimbarea cantitaii in cazul in care medicamentul exista
void Medikament::schimbare_cantitate(string nume, int cantitate)
{
	Medikament temp;
	vector<Medikament> v;
	ifstream in("medicamente.txt", ios::in);
	while (in >> temp.name >> temp.konzentration >> temp.preis >> temp.menge)//se iau randurile pe rand
		if (nume == temp.name)
		{
			temp.menge = cantitate;//se schimba cantitatea 
			v.push_back(temp);//se creaza un vector cu valoarea schimbata
		}
		else
			v.push_back(temp);
	//afisarea noului fisier schimbat
	ofstream out("medicamente.txt", ios::out);
	for (const auto& medi : v) {
		out << medi.name << ' ' << medi.konzentration << ' ' << medi.preis << ' ' << medi.menge << endl;
	}
	cout << "Cantitatea a fost modificata!...verificati fisierul" << endl;
}
//introducerea unui medicament nou 
void Medikament::einfugen_medikament()
{
	Medikament m;
	string nume;
	int concentratie, pret, cantitate;
	cout << "Ce nume doriti sa aiba medicamentul?"<<endl;
	cin >> nume;
	RUndo();
	//caz in care existena medicamentul in fisier
	if (verificare_medicament_existent(nume) == 1)
	{
		cout << "Medicament existent...se va modifica numai cantitatea....Ce cantitate?" << endl;
		cin >> cantitate;
		schimbare_cantitate(nume, cantitate);
	}
	//cazul in care nu exista medicamentul in fisier
	else
	{
		cout << "Ce concentratie va avea medicamentul?" << endl;
		cin >> concentratie;
		cout << "Ce pret va avea medicamentul?" << endl;
		cin >> pret;
		cout << "Care i cantitatea?" << endl;
		cin >> cantitate;
		m.afisare_in_fisier_append(nume, concentratie, pret, cantitate);
	}
}
//afisare de tip append
void Medikament::afisare_in_fisier_append(string nume, int concentratie, int pret, int cantitate)
{
	fstream f("medicamente.txt",ios::app);
	f << nume << " " << concentratie << " " << pret << " " << cantitate<<endl;
	f.close();
}
//afisare de tip write
void Medikament::afisare_in_fisier_write(string nume, int concentratie, int pret, int cantitate)
{
	fstream f("medicamente.txt");
	f << nume << " " << concentratie << " " << pret << " " << cantitate << endl;
	f.close();
}
//stergerea medicametului
void Medikament::delete_medicament()
{
	RUndo();
	string nume;
	cout << "Ce medicament doriti sa stergeti?"<<endl;
	cin >> nume;
	ifstream in("medicamente.txt", ios::in);
	Medikament temp;
	vector<Medikament> v;
	while (in >> temp.name >> temp.konzentration >> temp.preis >> temp.menge)//ia randurile pe rand
		if (nume != temp.name)//creaza un vector care contine toate randurile in afara de cel dorit
			v.push_back(temp);
	//afisarea lor
	ofstream out("medicamente.txt", ios::out);
	for (const auto& medi:v ) {
		out <<medi.name << ' ' << medi.konzentration << ' ' << medi.preis << ' '<<medi.menge<<endl;
	}
	cout << "Stergerea a fost efecutata...verificati fisierul!" << endl;
}
//afisarea medicametelor dupa model
void Medikament::show_medikamente()
{
	string model;
	cout << "Dupa ce model doriti sa cautati medicamentul/medicamentele?"<<endl;
	cin >> model;
	Medikament temp;
	vector<Medikament> v;
	int ok = 0;
	ifstream in("medicamente.txt", ios::in);
	while (in >> temp.name >> temp.konzentration >> temp.preis >> temp.menge)//citeste cate un rand
		if (model == temp.name || model == to_string(temp.konzentration) || model == to_string(temp.preis) || model == to_string(temp.menge))//merge dupa model
		{
			ok = 1;
			v.push_back(temp);//daca il gaseste creaza un vector 
		}
	if (ok != 0)//daca ok !=0 a gasit cel putin un match
	{
		sort(v.begin(), v.end());
		for (const auto& medi : v) {
			cout << medi.name << ' ' << medi.konzentration << ' ' << medi.preis << ' ' << medi.menge << endl;
		}
		cout << "Cel/cele de mai sus potrivesc modelului!" << endl;
	}
	//nu a gasit nimic...afiseaza mesajul
	else
		cout << "Nu s-a gasit nimic dupa modelul cautat!!!" << endl;
}
/// Cautare medicamente cu o concentratie mai mica
void Medikament::Cautare()
{
	int x;
	cout << "Dati concentratia pentru cautare: ";
	cin >> x;
	Medikament temp;
	int ok = 0;
	ifstream in("medicamente.txt", ios::in);
	while (in >> temp.name >> temp.konzentration >> temp.preis >> temp.menge)//citeste cate un rand
		if (x > temp.konzentration)//merge dupa model
		{
			ok = 1;
			cout << temp.name <<" "<< temp.konzentration <<" "<< temp.preis <<" "<<temp.menge << "\n";

		}
	if (ok == 0)//daca ok ==0 Nu a gasit niciun element
	{
		cout << "Nu exista medicament dupa concetratie";
	}
}


void Medikament::Grupare() {// Grupam medicamentele dupa pret

	vector<Medikament> v;
	pair <double, string> p;
	vector<string> name = {};
	vector<double> preis = {};

	//Creez doi vectori, in care memorez numele respectiv pretul fiecarui element
	Medikament temp;
	ifstream in("medicamente.txt", ios::in);
	while (in >> temp.name >> temp.konzentration >> temp.preis >> temp.menge)//citeste cate un rand
		v.push_back(temp);//creaza un vector
	int k = 0;
	for (const auto& it : v)
	{
		name.push_back(it.name);
		preis.push_back(it.preis);
		k++;
	}

	/// Ordonez vectorul preis si vectorul name

	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (preis[i] > preis[j])
			{
				int aux = preis[i];
				string aux1 = name[i];
				preis[i] = preis[j];
				preis[j] = aux;
				name[i] = name[j];
				name[j] = aux1;
			}
		}
	}
	//// Grupez elementele dupa pret si le afisez
	int i = 0;
	while (i < k)
	{
		cout << "Pretul: " << preis[i] << " - ";
		int j = i;
		while (j < k)
		{
			if (preis[i] == preis[j])
			{
				cout << name[j] << " ";
				j++;
			}
			else
				break;
		}
		i = j;
		cout << endl;
	}

	/*
	vector<Medikament> v;
	Medikament temp;
	ifstream in("medicamente.txt", ios::in);
	while (in >> temp.name >> temp.konzentration >> temp.preis >> temp.menge)//citeste cate un rand
		v.push_back(temp);//creaza un vector
	sort(v.begin(), v.end());
	int k = 0, nr = 0, ok = 1;
	for (const auto& it : v) {
		cout << it.name << " " << it.konzentration << " " << it.preis << " " << it.menge << "\n";
	}*/

}
void Medikament::RUndo()
{
	Medikament temp;
	ifstream in("medicamente.txt", ios::in);
	while (in >> temp.name >> temp.konzentration >> temp.preis >> temp.menge)//citeste cate un rand
		c.push_back(temp);//creaza un vector
}

void Medikament::Undo()
{
	vector <Medikament> l;
	l = c;
	ofstream trunc("medicamente.txt", ios::out);
	for (const auto& medi : l) {
		trunc << medi.name << ' ' << medi.konzentration << ' ' << medi.preis << ' ' << medi.menge << endl;
	}
	cout << "Undo/Redo a fost efecutata...verificati fisierul!" << endl;
	c = {};
}