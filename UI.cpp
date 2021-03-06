#include "UI.h"

console::console(const Service& srv) :srv(srv) {}

void console::run()
{
	cout << "Scrieti 7 pentru a vedea toate comenzile!\n";

	while (true)
	{
		int x;
		unordered_map<string, int> map;
		string error, destinatie, id, denumire, fisier;
		double pret;
		int command;
		cout << endl;
		cout << "Introdu o comanda : ";
		cin >> command;
		cout << endl;

		switch (command)
		{

			/// iesire
		case 0:
			return;
			break;

			/// adaugare
		case 1:
			error = this->adauga_oferta();
			if (error != "")
				cout << error << endl;
			break;

			/// stergere
		case 2:
			id = this->citire_id();
			error = this->srv.Sterge(id);
			if (error != "")
				cout << error << endl;
			break;

			/// modificare
		case 3:
			error = this->modifica_oferta();
			if (error != "")
				cout << error << endl;
			break;

			/// afisare
		case 4:
			this->afis_lista(this->srv.get_list());
			break;

			/// filtrare
		case 5:
			cout << "Dupa ce vreti sa filtrati?\n1 - dupa destinatie\n2 - dupa pret\n";
			cin >> x;

			// dupa destinatie
			if (x == 1)
			{
				cout << "Destiantia cautata : ";
				cin >> destinatie;
				vector<Oferta> v = this->srv.Filtrare1(destinatie, this->srv.get_list());
				this->afis_lista(v);
			}
			else // dupa pret
			{
				cout << "Pretul cautat este : ";
				cin >> pret;
				vector<Oferta> v = this->srv.Filtrare2(pret, this->srv.get_list());
				this->afis_lista(v);
			}
			break;

			/// sortare
		case 6:
			cout << "Dupa ce vreti sa sortati lista?\n";
			cout << "1 - Dupa denumire" << endl;
			cout << "2 - Dupa destinatie" << endl;
			cout << "3 - dupa tip + pret" << endl;
			cin >> x;

			/// afisam lista sortata
			this->afis_lista(this->srv.Sortare(x, this->srv.get_list()));

			break;

			/// afisare comenzi
		case 7:
			cout << "Comenzile sunt : \n";
			cout << "0 - pentru a inchide programul\n";
			cout << "1 - adaugarea unei oferte\n";
			cout << "2 - stergerea unei oferte\n";
			cout << "3 - modificarea unei oferte\n";
			cout << "4 - afisarea tuturor ofertelor\n";
			cout << "5 - filtrare" << endl;
			cout << "6 - sortare" << endl;
			cout << "7 - afisarea tuturor comenzilor\n";
			cout << "8 - adaugare oferte predefinite\n";
			cout << "9 - goleste cos" << endl;
			cout << "10 - adauga in cos" << endl;
			cout << "11 - genereaza cos" << endl;
			cout << "12 - afiseaza cos" << endl;
			cout << "13 - afiseaza frecventa destinatiilor" << endl;
			cout << "14 - export " << endl;
			cout << "15 - undo " << endl;
			break;

			/// adaugare predefinite
		case 8:
			this->srv.Adaugare_Predefinite();
			cout << "Ofertele au fost adaugate!\n";
			break;

			/// goleste cos
		case 9:
			this->srv.goleste_cos();
			cout << "Cosul are " << this->srv.get_cos().size() << "elemente";
			break;

			/// adauga in cos
		case 10:
			cout << "Denumirea ofertei pe care o vreti adaugata : ";
			cin >> denumire;

			error = this->srv.add_in_wish(denumire);
			if (error != "")
				cout << error;

			cout << "\nCosul are " << this->srv.get_cos().size() << "elemente";
			break;

			/// genereaza cos
		case 11:
			cout << "Numarul de elemente care trebuie generate : ";
			cin >> x;

			this->srv.genereaza(x);
			cout << "\nCosul are " << this->srv.get_cos().size() << "elemente";
			break;

			/// afis cos
		case 12:
			this->afis_lista(this->srv.get_cos());
			cout << "\nCosul are " << this->srv.get_cos().size() << "elemente";
			break;

			/// map
		case 13:
			map = this->srv.getFrecvente();
			for (const auto &x : map)
				cout << x.first << " " << x.second << endl;

			break;

			/// Export
		case 14:
			cin >> fisier;
			error = this->srv.Export(fisier);

			if (error != "")
				cout << error << endl;
			break;

			/// Undo

		case 15:
			error = this->srv.Undo();

			if (error != "")
				cout << error << endl;
			else
				cout << "undo efectuat." << endl;
			break;

		default:
			cout << "Comanda gresita";
			break;
		}
	}
}


string console::adauga_oferta()
{
	/// citim o oferta si incercam sa o adaugam

	cout << "Denumirea : ";
	string denumire;
	cin >> denumire;
	cout << "Destinatia : ";
	string destinatie;
	cin >> destinatie;
	cout << "Tip-ul : ";
	string tip;
	cin >> tip;
	cout << "Pretul : ";
	string pret;
	cin >> pret;
	return this->srv.Adauga(denumire, destinatie, tip, pret);
}

string console::modifica_oferta()
{
	/// citim o oferta si incercam sa o modificam
	string id;
	cout << "ID-ul : ";
	cin >> id;

	cout << "Denumirea : ";
	string denumire;
	cin >> denumire;
	cout << "Destinatia : ";
	string destinatie;
	cin >> destinatie;
	cout << "Tip-ul : ";
	string tip;
	cin >> tip;
	cout << "Pretul : ";
	string pret;
	cin >> pret;
	return this->srv.Modifica(denumire, destinatie, tip, pret, id);
}

string console::citire_id()
{
	string id;
	cout << "Id-ul : ";
	cin >> id;
	return id;
}

void console::afis_lista(vector<Oferta> l)
{
	/// Afiseaza lista de oferte pe ecran
	cout << "id       denumire       destinatie       tip       pret\n";
	for (int i = 0; i < l.size(); i++)
		l.at(i).show_oferta();
}