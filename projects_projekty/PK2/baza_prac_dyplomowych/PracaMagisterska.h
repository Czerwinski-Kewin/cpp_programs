#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "PracaDyplomowa.h"
using namespace std;

class PracaMagisterska : public PracaDyplomowa
{
	string temat;
	string literatura_przedmiotu;
public:
	PracaMagisterska();
	~PracaMagisterska();
	PracaMagisterska(const PracaMagisterska& r);
	void wpisanie_oceny();
	void wydrukuj_opis_pracy();
	void rezerwacja_tematu();
	void usuwanie_rezerwacji();
};

