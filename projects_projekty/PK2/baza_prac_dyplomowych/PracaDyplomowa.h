#pragma once
#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include "PracaDyplomowa.h"
using namespace std;

class PracaDyplomowa
{
public:
	//const static int n = 5;
	int n = 5;
	int id_pracy;
	string temat;
	string promotor;
	//unique_ptr<int[]> oceny;
	//unique_ptr<int[]> oceny = make_unique<int[]>(n);
	unique_ptr<string[]> oceny_magister = make_unique<string[]>(n);
	unique_ptr<string[]> oceny_inzynier = make_unique<string[]>(n);
	unique_ptr<string[]> oceny_doktor = make_unique<string[]>(n);

	unique_ptr<string[]> tematy_magister = make_unique<string[]>(n);
	unique_ptr<string[]> tematy_inzynier = make_unique<string[]>(n);
	unique_ptr<string[]> tematy_doktor = make_unique<string[]>(n);
	//string oceny[n];
	string ocena;
	int liczba_recenzentow;
	virtual void rezerwacja_tematu();
	virtual void usuwanie_rezerwacji();
	virtual void wpisanie_oceny();
	virtual void wydrukuj_opis_pracy();
	PracaDyplomowa();
	~PracaDyplomowa();

	//PracaDyplomowa(const PracaDyplomowa& r);
};

