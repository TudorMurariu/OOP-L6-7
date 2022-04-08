#pragma once
#include "Oferta.h"

class Repo 
{
	private:

		my_vector<Oferta> Lista_oferte;

	public:

		Repo(my_vector<Oferta> l);
		my_vector<Oferta> get_list();
		void Add(Oferta x);
		int cauta_id(int id);
		string Sterge(int id);
		string Modificare(Oferta x);
};