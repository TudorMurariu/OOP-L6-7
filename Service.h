#pragma once
#include "Oferta.h"
#include "Repo.h"
#include "Validators.h"

class Service
{
	friend class console;
	private:
		Repo repo;
		Valid valid;
	public:
		Service(Repo repo, Valid valid);
		string Adauga(string denumire, string destinatie, string tip, string pret);
		string Sterge(string id);
		string Modifica(string denumire, string destinatie, string tip, string pret, string id);
		vector<Oferta> Filtrare1(string dest, vector<Oferta> v);
		vector<Oferta> Filtrare2(double pret, vector<Oferta> v);
		vector<Oferta> Sortare(int x, vector<Oferta> v);
		void Adaugare_Predefinite();
		vector<Oferta> get_list();
};

void test_service(Service srv);
void test_adauga(Service srv);
void test_stergere(Service srv);
void test_modificare(Service srv);
void test_Filtrare1(Service srv);
void test_Filtrare2(Service srv);
void test_Sortare(Service srv);