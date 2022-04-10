#pragma once
#include "Oferta.h"

// repo class
class Repo 
{
	private:

		my_vector Lista_oferte;

	public:

		Repo(my_vector l);
		my_vector get_list();
		void Add(Oferta x);
		int cauta_id(int id);
		string Sterge(int id);
		string Modificare(Oferta x);
};