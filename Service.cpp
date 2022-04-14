#include "Service.h"


Service::Service(Repo repo,wish_list wish, Valid valid) {
	this->repo = repo;
	this->wish = wish;
	this->valid = valid;
}

static int id_count = 0;
string Service::Adauga(string denumire, string destinatie, string tip, string pret)
{
	/*
	*  Validam inputul si daca este corect il trimitem in repo
	*/

	if (!this->valid.is_pret(pret))
		return "Pret incorect!\n";
	const double pret_d = stod(pret);
	Oferta x(denumire, destinatie, tip, pret_d, id_count++);
	this->repo.Add(x);
	return "";
}

string Service::Sterge(string id)
{
	/*
	*  Validam inputul si daca este corect il trimitem in repo
	*/

	if (!this->valid.is_id(id))
		return "ID gresit\n";
	const int id_int = stoi(id);
	return this->repo.Sterge(id_int);
}

vector<Oferta> Service::get_list()
{
	return this->repo.get_list();
}

string Service::Modifica(string denumire, string destinatie, string tip, string pret, string id)
{
	/*
	*  Validam inputul si daca este corect il trimitem in repo
	*/

	if (!this->valid.is_id(id))
		return "ID gresit\n";
	const int id_int = stoi(id);

	if (!this->valid.is_pret(pret))
		return "Pret incorect!\n";
	const double pret_d = stod(pret);

	Oferta x(denumire, destinatie, tip, pret_d, id_int);
	return this->repo.Modificare(x);
}

vector<Oferta> Service::Filtrare1(string dest, vector<Oferta> v)
{
	/// Cream un nou vector care contine doar elementele 
	/// cu aceeasi destinatie cu cea ceruta
	vector<Oferta> new_v;

	copy_if(
		v.begin(),
		v.end(),
		back_inserter(new_v),
		[dest](const Oferta& x)
		{
			return x.destinatie == dest;
		}
	);

	return new_v;
}

vector<Oferta> Service::Filtrare2(double pret, vector<Oferta> v)
{
	/// Cream un nou vector care contine doar elementele 
	/// cu pretul mai mic sau egal decat cel cerut
	vector<Oferta> new_v;

	copy_if(
		v.begin(),
		v.end(),
		back_inserter(new_v),
		[pret](const Oferta& x)
		{
			return x.pret <= pret;
		}
	);

	return new_v;
}

/// Functiile de comparare vor fi folosite doar in acest modul 
bool cmp_denumire(Oferta a, Oferta b) noexcept {
	/// comparare dupa denumire
	return a.denumire < b.denumire;
}

bool cmp_destinatie(Oferta a, Oferta b) noexcept {
	/// comparare dupa destinatie
	return a.destinatie < b.destinatie;
}

bool cmp_tip_pret(Oferta a, Oferta b) noexcept {
	/// comparare dupa tip iar apoi dupa pret
	if (a.tip == b.tip)
		return a.pret < b.pret;
	return a.tip < b.tip;
}

vector<Oferta> Service::Sortare(int x, vector<Oferta> v)
{
	/// Sortam lista dupa un mod ales x

	if (x == 1)
	{
		sort(v.begin(), v.end(), cmp_denumire);
	}
	else if (x == 2)
	{
		sort(v.begin(), v.end(), cmp_destinatie);
	}
	else if (x == 3)
	{
		sort(v.begin(), v.end(), cmp_tip_pret);
	}

	return v;
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


void Service::goleste_cos()
{
	this->wish.goleste_cos();
}

string Service::add_in_wish(string denumire)
{
	Oferta x = this->repo.cauta_denumire(denumire);
	if (x.pret == -1)
		return "Denumirea nu exista.\n";
	this->wish.add(x);
	return "";
}

void Service::genereaza(int x)
{
	this->wish.genereaza(x);
}

vector<Oferta> Service::get_cos()
{
	return this->wish.getList();
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
	test_wish_list(srv);
}

void test_adauga(Service srv)
{
	srv.Adauga("OFERTA", "destinatie", "tip", "33.4");
	assert(srv.get_list().at(0).denumire == "OFERTA");
	assert(srv.get_list().at(0).destinatie == "destinatie");
	assert(srv.get_list().at(0).tip == "tip");
	assert(srv.get_list().at(0).pret == 33.4);
	assert(srv.get_list().at(0).denumire != "312rewsda");
	assert(srv.get_list().size() == 1);
	assert(srv.Adauga("OFERTA", "destinatie", "tip", "asdff") == "Pret incorect!\n");
}

void test_stergere(Service srv)
{
	srv.Adauga("OFERTA", "destinatie", "tip", "33.4");
	srv.Adauga("OFERTA1", "destinatie213", "tip132", "33.432");
	assert(srv.Sterge("1") == "");
	assert(srv.get_list().size() == 1);
	assert(srv.Sterge("5") == "Nu exista o oferta cu id-ul dat");
	assert(srv.Sterge("sdfs") == "ID gresit\n");
	assert(srv.Sterge("2") == "");
}

void test_modificare(Service srv)
{
	srv.Adauga("OFERTA", "destinatie", "tip", "33.4");
	assert(srv.Modifica("vacanta", "Iasi", "tip1", "25.6", "7") == "Nu exista o oferta cu id-ul dat");
	assert(srv.Modifica("Oferta", "destinatie", "tip1", "33", "3") == "");
	assert(srv.Modifica("Oferta", "destinatie", "tip1", "33", "sdf34fds") == "ID gresit\n");
	assert(srv.Modifica("Oferta", "destinatie", "tip1", "asd33342", "2") == "Pret incorect!\n");
	vector<Oferta> v = srv.get_list();
	assert(v.at(0).denumire == "Oferta");
	assert(v.at(0).destinatie == "destinatie");
	assert(v.at(0).tip == "tip1");
	assert(v.at(0).pret == 33);
}

void test_Filtrare1(Service srv)
{
	srv.Adaugare_Predefinite();
	vector<Oferta> v1 = srv.Filtrare1("Iasi", srv.get_list());
	assert(v1.at(0).pret == 552.7);
	assert(v1.size() == 1);
}

void test_Filtrare2(Service srv)
{
	srv.Adaugare_Predefinite();
	vector<Oferta> v1 = srv.Filtrare2(32, srv.get_list());
	assert(v1.size() == 2);
	assert(v1.at(0).pret == 32);
	assert(v1.at(1).pret == 5);
	assert(v1.at(0).denumire == "Denumire2");
}

void test_Sortare(Service srv)
{
	srv.Adaugare_Predefinite();
	vector<Oferta> v1 = srv.Sortare(1, srv.get_list());
	assert(v1.at(0).denumire == "Denumire");
	vector<Oferta> v2 = srv.Sortare(2, srv.get_list());
	assert(v2.at(0).destinatie == "Bucuresti");
	vector<Oferta> v3 = srv.Sortare(3, srv.get_list());
	assert(v3.at(0).tip == "tip1");
	assert(v3.at(1).tip == "tip2");
}

void test_wish_list(Service srv)
{
	srv.Adaugare_Predefinite();
	assert(srv.add_in_wish("idk") == "Denumirea nu exista.\n");
	assert(srv.add_in_wish("SUPER_OFERTA") == "");
	srv.goleste_cos();
	assert(srv.add_in_wish("SUPER_OFERTA") == "");
	assert(srv.add_in_wish("Oferta_2?") == "");
	assert(srv.get_cos().size() == 2);
	srv.goleste_cos();
	srv.genereaza(3);
}