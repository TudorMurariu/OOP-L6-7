#pragma once
#include "Oferta.h"

#include <algorithm>  
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

class wish_list
{	
private:
	vector<Oferta> Lista;

public:
	void goleste_cos() noexcept;
	void add(Oferta x);
	void genereaza(int x, vector<Oferta> v);
	vector<Oferta> getList();
};
