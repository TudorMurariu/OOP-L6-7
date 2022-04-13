#include "Repo.h"

Repo::Repo(my_vector<Oferta> l)
{
	this->Lista_oferte = l;
}

my_vector<Oferta> Repo::get_list()
{
	return this->Lista_oferte;
}

int Repo::cauta_id(int id)
{
	/* cautam un id dat */
	for (int i = 0; i < this->Lista_oferte.size(); i++)
	{
		if (id == this->Lista_oferte.at(i).id)
			return i;
	}

	return -1;
}

void Repo::Add(Oferta x)
{
	/* Adaugam un element la finalul listei */
	this->Lista_oferte.push_back(x);
}

string Repo::Sterge(int id)
{
	/* Stergem elementul cu id ul id daca acesta exista , altfel trimitem
	un mesaj de eroare */

	const int poz = this->cauta_id(id);
	if (poz != -1)
	{
		this->Lista_oferte.erase(poz);
		return "";
	}

	return "Nu exista o oferta cu id-ul dat";
}


string Repo::Modificare(Oferta x)
{
	/* Cautam un mesaj pentru a il modifica */

	const int poz = this->cauta_id(x.id);
	if (poz != -1)
	{
		this->Lista_oferte.v[poz] = x;
		return "";
	}

	return "Nu exista o oferta cu id-ul dat";
}



