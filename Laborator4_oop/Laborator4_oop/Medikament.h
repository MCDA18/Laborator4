#pragma once
#include <string>
#include <vector>
using namespace std;
class Medikament
{
private:
	string name;
	int konzentration;
	int preis;
	int menge;
public:
	bool operator< (const Medikament& other) const {return name < other.name;}
	Medikament(string nume,int concentratie,int pret,int cantitate);
	Medikament();
	void set_nume(string nume);
	void set_concentratie(int concentratie);
	void set_pret(int pret);//settere
	void set_cantitate(int cantitate);
	string get_nume();
	int get_concentratie();
	int get_pret();
	int get_cantitate();//getere
	void einfugen_medikament();
	int verificare_medicament_existent(string nume);
	void schimbare_cantitate(string nume, int cantitate);//schimba a=cantitatea in caz in care numele ii la fel
	void afisare_in_fisier_append(string nume, int concentratie, int pret, int cantitate);//afisare
	void afisare_in_fisier_write(string nume, int concentratie, int pret, int cantitate);//afisare
	void show_medikamente();//afiseaza dupa model
	void delete_medicament();//sterge medicamentul
};