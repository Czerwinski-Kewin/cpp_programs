#pragma once
#include <string>
#include "PracaDyplomowa.h"
using namespace std;

class PracaDoktorska : public PracaDyplomowa
{
	string temat;
	string dziedzina_nauki;
public:
	void wpisanie_oceny();
	void wydrukuj_opis_pracy();
	void rezerwacja_tematu();
	void usuwanie_rezerwacji();
};

