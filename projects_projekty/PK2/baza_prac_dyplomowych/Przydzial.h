#pragma once
#include <string>
#include <sstream>
#include "PracaDyplomowa.h"
using namespace std;

class Przydzial : public PracaDyplomowa
{
public:
	int dzien;
	int miesiac;
	int rok;
	string osoba;	//komu?
	string typ;
	unique_ptr<string[]> przydzialy = make_unique<string[]>(n);
	Przydzial();
	Przydzial(int _id_pracy, int _dzien, int _miesiac, int _rok, string _osoba, string _typ);
	friend ostream& operator << (ostream& ostr, const Przydzial& obj);
};

