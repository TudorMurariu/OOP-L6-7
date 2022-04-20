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
	fout << "<html>";
	fout << "<style> p {text-align: center;} body{background-color: #E6E6FA;} </style>";
	fout << "<body>";
	fout << "<p><big><b>id &nbsp;&nbsp; denumire &nbsp;&nbsp; destinatie &nbsp;&nbsp; tip &nbsp;&nbsp; pret</b></big><br>";
	for (auto& x : this->Lista)
	{
		fout << x.id << "&nbsp;&nbsp;&nbsp;&nbsp;" << x.denumire << "&nbsp;&nbsp;&nbsp;&nbsp;" << x.destinatie
			<< "&nbsp;&nbsp;&nbsp;&nbsp;" << x.tip << "&nbsp;&nbsp;&nbsp;&nbsp;" << x.pret << "<br>";
	}
	fout << "</p></body>";
	fout << "<html>";
}