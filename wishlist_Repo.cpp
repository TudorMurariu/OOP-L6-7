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