#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

template<class Telem>
class vector {

	private:
		int len;
		int capacity;

	public:
		Telem* v;
		vector();
		~vector();
		vector(const vector<Telem>& ot);
		int size() const;
		void push_back(Telem x);
		Telem* begin();
		Telem* end();
		void erase(int poz);
};



template<class Telem>
vector<Telem>::vector()
{
	/// <summary>
	/// Initiem datele si facem loc in memorie pentru ele
	/// </summary>
	this->len = 0;
	this->capacity = 2;
	this->v = new Telem[this->capacity];
}

template<class Telem>
vector<Telem>::~vector()
{
	//delete[] this->v;
}

template<class Telem>
vector<Telem>::vector(const vector<Telem>& ot)
{
	this->capacity = ot.capacity;
	this->len = ot.len;
	this->v = new Telem[ot.capacity];

	for (int i = 0; i < this->len; i++)
	{
		this->v[i] = ot.v[i];
	}
}

template<class Telem>
void vector<Telem>::push_back(Telem x)
{
	/// Adaugam un element in vector
	/// in cazul in care avem nevoie de mai multa memorie , dublam capacitatea
	/// vectorului
	if (this->len + 1 >= this->capacity)
	{
		const int new_capacity = 2 * this->capacity;
		Telem* new_v = new Telem[new_capacity];
		for (int i = 0; i < this->len; i++)
			new_v[i] = this->v[i];
		delete[] this->v;
		this->v = new_v;
		this->capacity = new_capacity;
	}

	v[this->len++] = x;
}

template<class Telem>
int vector<Telem>::size() const {
	return this->len;
}

template<class Telem>
Telem* vector<Telem>::begin()
{
	return this->v;
}

template<class Telem>
Telem* vector<Telem>::end()
{
	return this->v + this->len;
}

template<class Telem>
void vector<Telem>::erase(int poz)
{
	for (int i = poz; i < this->len - 1; i++)
		this->v[i] = this->v[i + 1];
	this->len--;
}