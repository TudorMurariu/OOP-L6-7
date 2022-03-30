#include "Oferta.h"

Oferta::Oferta(string denumire, string destinatie, string tip, double pret, int id)
{
	this->denumire = denumire;
	this->destinatie = destinatie;
	this->pret = pret;
	this->tip = tip;
	this->id = id;
}

Oferta& Oferta::operator =(const Oferta& x)
{
	this->denumire = x.denumire;
	this->destinatie = x.destinatie;
	this->id = x.id;
	this->pret = x.pret;
	this->tip = x.tip;
	return *this;
}

/// used for UI
void Oferta::show_oferta()
{
	/// afiseaza o oferta pe ecran
	cout << this->id << "\t" <<  this->denumire << "\t" << this->destinatie
		<< "\t" << this->tip << "\t" << this->pret << "$\n";
}