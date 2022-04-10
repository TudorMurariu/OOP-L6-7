#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
using namespace std;

template<typename Telem>
class Iterator;

template<typename Telem>
class my_vector {

	friend class Iterator<Telem>;

	private:
		int capacity;

	public:
		int len;
		Telem* v;
		my_vector();
		~my_vector();
		my_vector(const my_vector<Telem>& ot);
		my_vector<Telem>& operator =(const my_vector<Telem>& x);
		int size() const;
		void push_back(Telem x);
		Telem* begin();
		Telem* end();
		void erase(int poz);
		Telem& at(int i);
};

template<typename Telem>
my_vector<Telem>& my_vector<Telem>:: operator =(const my_vector<Telem>& x)
{
	// not needed
	//if (&x == this)
		///return *this;

	delete[] this->v;
	this->v = new Telem[x.capacity];
	for (int i = 0; i < x.len; i++)
	{
		this->v[i] = x.v[i];
	}
	this->len = x.len;
	this->capacity = x.capacity;

	return *this;
}

template<typename Telem>
my_vector<Telem>::my_vector()
{
	/// <summary>
	/// Initiem datele si facem loc in memorie pentru ele
	/// </summary>
	this->len = 0;
	this->capacity = 2;
	this->v = new Telem[this->capacity];
}

template<typename Telem>
my_vector<Telem>::~my_vector()
{
	delete[] this->v;
}

template<typename Telem>
my_vector<Telem>::my_vector(const my_vector<Telem>& ot)
{
	this->capacity = ot.capacity;
	this->len = ot.len;
	this->v = new Telem[ot.capacity];

	for (int i = 0; i < this->len; i++)
	{
		this->v[i] = ot.v[i];
	}
}

template<typename Telem>
void my_vector<Telem>::push_back(Telem x)
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

template<typename Telem>
int my_vector<Telem>::size() const{
	return this->len;
}

template<typename Telem>
Telem* my_vector<Telem>::begin(){
	return this->v;
}

template<typename Telem>
Telem* my_vector<Telem>::end(){
	return this->v + this->len;
}

template<typename Telem>
void my_vector<Telem>::erase(int poz)
{
	for (int i = poz; i < this->len - 1; i++)
		this->v[i] = this->v[i + 1];
	this->len--;
}

template<typename Telem>
Telem& my_vector<Telem>::at(int i)
{
	return this->v[i];
}


template<typename Telem>
class Iterator {

	private:
		my_vector<Telem>& lista;
		int i;

	public:

		Iterator(my_vector<Telem>& Vector1) noexcept :lista{ Vector1 } {
			this->i = 0;
		}

		Telem& element()
		{
			return this->lista.at(this->i);
		}

		void urmator()
		{
			i++;
		}

		void prim()
		{
			i = 0;
		}

		bool valid()
		{
			return this->i > 0 && this->i < lista.len;
		}
};

