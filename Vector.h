#pragma once
#include "Oferta.h"
#include <stdlib.h>
#include <stdio.h>

// vector class
class my_vector {

private:
	int len;
	int capacity;

public:
	Oferta* v;
	my_vector();
	~my_vector();
	int size() const;
	void push_back(Oferta x);
	Oferta* begin();
	Oferta* end();
	void erase(int poz);
};