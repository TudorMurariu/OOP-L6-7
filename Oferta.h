#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include "Vector.h"

using namespace std;

class Oferta
{
public:
	string denumire, destinatie, tip;
	double pret;
	int id;

	Oferta();
	Oferta(string denumire, string destinatie, string tip, double pret, int id);
	//Oferta& operator =(const Oferta& x);
	Oferta(const Oferta& x);
	~Oferta() = default;
	void show_oferta() const;
};