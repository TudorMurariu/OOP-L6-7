#pragma once
#include "Oferta.h"
#include "Repo.h"

class Service
{
	friend class console;
	private:
		Repo repo;
	public:
		Service(Repo repo);
		string Adauga(string denumire, string destinatie, string tip, double pret);
		string Sterge(int id);
		string Modifica(string denumire, string destinatie, string tip, double pret,int id);
		vector<Oferta> Filtrare1(string dest, vector<Oferta> v);
		vector<Oferta> Filtrare2(double pret, vector<Oferta> v);
		vector<Oferta> Sortare(int x, vector<Oferta> v);
		void Adaugare_Predefinite();
		vector<Oferta> get_list();
};

void test_service(Service srv);
void test_adauga(Service srv);
void test_stergere(Service srv);

bool cmp_denumire(Oferta a, Oferta b);

bool cmp_destinatie(Oferta a, Oferta b);

bool cmp_tip_pret(Oferta a, Oferta b);