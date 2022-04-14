#include "wishlist_Repo.h"

void wish_list::goleste_cos() noexcept {
	this->Lista.clear();
}

void wish_list::add(Oferta x)
{
	this->Lista.push_back(x);
}

void wish_list::genereaza(int x)
{

}

vector<Oferta> wish_list::getList()
{
	return this->Lista;
}