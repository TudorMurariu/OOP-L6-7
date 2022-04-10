#include "Vector.h"

my_vector::my_vector()
{
	//// <summary>
	/// Initiem datele si facem loc in memorie pentru ele
	/// </summary>
	this->len = 0;
	this->capacity = 2;
	this->v = (Oferta*)malloc(sizeof(Oferta) * this->capacity);
}

my_vector::~my_vector()
{
	delete[] this->v;
}
void my_vector::push_back(Oferta x)
{
	/// Adaugam un element in vector
	/// in cazul in care avem nevoie de mai multa memorie , dublam capacitatea
	/// vectorului
	if (this->len + 1 >= this->capacity)
	{
		const int new_capacity = 2 * this->capacity;
		Oferta* new_v = (Oferta*)malloc(sizeof(Oferta) * new_capacity);
		for (int i = 0; i < this->len; i++)
			new_v[i] = this->v[i];
		free(this->v);
		this->v = new_v;
		this->capacity = new_capacity;
	}

	v[this->len++] = x;
}

int my_vector::size() const {
	return this->len;
}

Oferta* my_vector::begin()
{
	return this->v;
}

Oferta* my_vector::end()
{
	return this->v + this->len;
}

void my_vector::erase(int poz)
{
	for (int i = poz; i < this->len - 1; i++)
		this->v[i] = this->v[i + 1];
	this->len--;
}