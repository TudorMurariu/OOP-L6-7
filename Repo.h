#pragma once
#include "Oferta.h"

class Repo 
{
	private:

		vector<Oferta> Lista_oferte;

	public:

		Repo(vector<Oferta> l);
		vector<Oferta> get_list();
		void Add(Oferta x);
		int cauta_id(int id);
		string Sterge(int id);
		string Modificare(Oferta x);
};