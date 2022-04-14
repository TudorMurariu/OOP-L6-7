#pragma once
#include "Oferta.h"

class wish_list
{	
private:
	vector<Oferta> Lista;

public:
	void goleste_cos() noexcept;
	void add(Oferta x);
	void genereaza(int x);
	vector<Oferta> getList();
};
