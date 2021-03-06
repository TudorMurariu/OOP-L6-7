#pragma once
#include "Service.h"
#include "Oferta.h"
#include <unordered_map>

class console
{
	friend class Service;
private:
	Service srv;
public:
	console(const Service& srv);
	void run();
	string adauga_oferta();
	string modifica_oferta();
	string citire_id();
	void afis_lista(vector<Oferta> l);
};