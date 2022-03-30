#pragma once
#include "Service.h"
#include "Oferta.h"
#include <vector>

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
		int citire_id();
		void afis_lista(vector<Oferta> l);
};