#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "PracaDyplomowa.h"
using namespace std;

class PracaInzynierska : public PracaDyplomowa
{
	string temat;
	string abstrakcyjne_rozwiazanie;
	string techniczne_rozwiazanie;
public:
	void wpisanie_oceny();
	void wydrukuj_opis_pracy();
	void rezerwacja_tematu();
	void usuwanie_rezerwacji();
};

