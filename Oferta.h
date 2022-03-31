#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Oferta
{
	public:
		string denumire,destinatie,tip;
		double pret;
		int id;

		Oferta(string denumire, string destinatie, string tip, double pret,int id);
		//Oferta& operator =(const Oferta& x);
		Oferta(const Oferta& x);
		void show_oferta() const;
};