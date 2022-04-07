#pragma once

template<class Telem>
class vector {

	private:
		int len;
		int capacity;

	public:
		Telem* v;
		vector();
		~vector();
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
	this->v = (Telem*)malloc(sizeof(Telem) * this->capacity);
}

template<class Telem>
vector<Telem>::~vector()
{
	delete[] this->v;
}

template<class Telem>
void vector<Telem>::push_back(Telem x)
{
	/// Adaugam un element in vector
	/// in cazul in care avem nevoie de mai multa memorie , dublam capacitatea
	/// vectorului
	if (this->len + 1 >= this->capacity)
	{
		int new_capacity = 2 * this->capacity;
		Telem* new_v = (Telem*)malloc(sizeof(Telem) * new_capacity);
		for (int i = 0; i < this->len; i++)
			new_v[i] = this->v[i];
		free(this->v);
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