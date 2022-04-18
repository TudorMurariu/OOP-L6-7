#include "wishlist_Repo.h"

void wish_list::goleste_cos() noexcept {
	this->Lista.clear();
}

void wish_list::add(Oferta x)
{
	this->Lista.push_back(x);
}

void wish_list::genereaza(int x, vector<Oferta> v)
{
	/// generam x oferte

	this->goleste_cos();

	shuffle(v.begin(), v.end(), default_random_engine(time(0)));
	for (int i = 0; i < x && !v.empty(); i++)
	{
		this->add(v.back());
		v.pop_back();
	}
}

vector<Oferta> wish_list::getList()
{
	return this->Lista;
}

void wish_list::Export(string nume_fisier)
{
	ofstream fout(nume_fisier);
	fout << "id       denumire       destinatie       tip       pret\n";
	for (auto& x : this->Lista)
	{
		fout << x.id << "       " << x.denumire << "       " << x.destinatie
			<< "       " << x.tip << "       " << x.pret << "$\n";
	}
}