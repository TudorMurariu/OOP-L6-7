#include "Service.h"


Service::Service(Repo repo) :repo(repo) {
	this->repo = repo;
}

static int id_count = 0;
string Service::Adauga(string denumire, string destinatie, string tip, double pret)
{
	Oferta x(denumire, destinatie, tip, pret,id_count++);
	this->repo.Add(x);
	return "";
}

string Service::Sterge(int id)
{
	return this->repo.Sterge(id);
}

vector<Oferta> Service::get_list()
{
	return this->repo.get_list();
}

string Service::Modifica(string denumire, string destinatie, string tip, double pret, int id)
{
	Oferta x(denumire, destinatie, tip, pret, id);
	return this->repo.Modificare(x);
}

vector<Oferta> Service::Filtrare1(string dest, vector<Oferta> v)
{
	/// Cream un nou vector care contine doar elementele 
	/// cu aceeasi destinatie cu cea ceruta
	vector<Oferta> new_v;
	for (int i = 0; i < v.size(); i++)
		if (dest == v[i].destinatie)
			new_v.push_back(v[i]);
	return new_v;
}

vector<Oferta> Service::Filtrare2(double pret, vector<Oferta> v)
{
	/// Cream un nou vector care contine doar elementele 
	/// cu pretul mai mic sau egal decat cel cerut
	vector<Oferta> new_v;
	for (int i = 0; i < v.size(); i++)
		if (pret >= v[i].pret)
			new_v.push_back(v[i]);
	return new_v;
}

/// Functiile de comparare vor fi folosite doar in acest modul 
bool cmp_denumire(Oferta a, Oferta b)
{
	/// comparare dupa denumire
	return a.denumire < b.denumire;
}

bool cmp_destinatie(Oferta a, Oferta b)
{
	/// comparare dupa destinatie
	return a.destinatie < b.destinatie;
}

bool cmp_tip_pret(Oferta a, Oferta b)
{
	/// comparare dupa tip iar apoi dupa pret
	if (a.tip == b.tip)
		return a.pret < b.pret;
	return a.tip < b.tip;
}

vector<Oferta> Service::Sortare(int x, vector<Oferta> v)
{
	/// Sortam lista dupa un mod ales x
	vector<Oferta> new_v;

	if (x == 1)
	{
		sort(v.begin(),v.end(),cmp_denumire); 
		new_v = v;
	}
	else if (x == 2)
	{
		sort(v.begin(), v.end(), cmp_destinatie);
		new_v = v;
	}
	else if (x == 3)
	{
		sort(v.begin(), v.end(), cmp_tip_pret);
		new_v = v;
	}

	return new_v;
}

void Service::Adaugare_Predefinite()
{
	/// Adaugam oferte predefinite in lista
	Oferta x("SUPER_OFERTA", "Timisoara", "vacanta", 542.2, id_count++);
	this->repo.Add(x);
	Oferta x1("Denumire1", "Bucuresti", "tip1", 77.2, id_count++);
	this->repo.Add(x1);
	Oferta x2("Denumire2", "NuGalati", "tip2", 32, id_count++);
	this->repo.Add(x2);
	Oferta x3("Denumire3", "NuBraila", "tip2", 5, id_count++);
	this->repo.Add(x3);
	Oferta x4("Oferta_?", "York", "tip77", 1000, id_count++);
	this->repo.Add(x4);
	Oferta x5("Oferta_2?", "Viena", "tip3", 1032, id_count++);
	this->repo.Add(x5);
	Oferta x6("Ofertaaaaaaaa", "Madrid", "tip3", 432.5, id_count++);
	this->repo.Add(x6);
	Oferta x7("Denumire4", "Delhi", "tip32", 552.7, id_count++);
	this->repo.Add(x7);
	Oferta x8("Denumire", "Iasi", "tip32", 552.7, id_count++);
	this->repo.Add(x8);
}

/// Functii de teste

void test_service(Service srv)
{
	test_adauga(srv);
	test_stergere(srv);
	test_modificare(srv);
	id_count = 0;
	test_Filtrare1(srv);
	id_count = 0;
	test_Filtrare2(srv);
	id_count = 0;
	test_Sortare(srv);
	id_count = 0;
}

void test_adauga(Service srv)
{
	srv.Adauga("OFERTA", "destinatie", "tip", 33.4);
	assert(srv.get_list()[0].denumire == "OFERTA");
	assert(srv.get_list()[0].destinatie == "destinatie");
	assert(srv.get_list()[0].tip == "tip");
	assert(srv.get_list()[0].pret == 33.4);
	assert(srv.get_list()[0].denumire != "312rewsda");
	assert(srv.get_list().size() == 1);
}

void test_stergere(Service srv)
{
	srv.Adauga("OFERTA", "destinatie", "tip", 33.4);
	assert(srv.Sterge(1) == "");
	assert(srv.get_list().size() == 0);
	assert(srv.Sterge(1) == "Nu exista o oferta cu id-ul dat");
}

void test_modificare(Service srv)
{
	srv.Adauga("OFERTA", "destinatie", "tip", 33.4);
	assert(srv.Modifica("vacanta", "Iasi", "tip1", 25.6, 7) == "Nu exista o oferta cu id-ul dat");
	assert(srv.Modifica("Oferta", "destinatie", "tip1", 33, 2) == "");
	vector<Oferta> v = srv.get_list();
	assert(v[0].denumire == "Oferta");
	assert(v[0].destinatie == "destinatie");
	assert(v[0].tip == "tip1");
	assert(v[0].pret == 33);
}

void test_Filtrare1(Service srv)
{
	srv.Adaugare_Predefinite();
	vector<Oferta> v1 = srv.Filtrare1("Iasi", srv.get_list());
	assert(v1[0].pret == 552.7);
	assert(v1.size() == 1);
}

void test_Filtrare2(Service srv)
{
	srv.Adaugare_Predefinite();
	vector<Oferta> v1 = srv.Filtrare2(32, srv.get_list());
	assert(v1.size() == 2);
	assert(v1[0].pret == 32);
	assert(v1[1].pret == 5);
	assert(v1[0].denumire == "Denumire2");
}

void test_Sortare(Service srv)
{
	srv.Adaugare_Predefinite();
	vector<Oferta> v1 = srv.Sortare(1, srv.get_list());
	assert(v1[0].denumire == "Denumire");
	vector<Oferta> v2 = srv.Sortare(2, srv.get_list());
	assert(v2[0].destinatie == "Bucuresti");
	vector<Oferta> v3 = srv.Sortare(3, srv.get_list());
	assert(v3[0].tip == "tip1");
	assert(v3[1].tip == "tip2");
}