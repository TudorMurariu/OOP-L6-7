#pragma once
#include "Service.h"
#include "Oferta.h"
#include "Vector.h"

class console
{
	friend class Service;
	private:
		Service srv;
	public:
		console(const Service &srv);
		void run();
		string adauga_oferta();
		string modifica_oferta();
		string citire_id();
		void afis_lista(my_vector<Oferta> l);
};