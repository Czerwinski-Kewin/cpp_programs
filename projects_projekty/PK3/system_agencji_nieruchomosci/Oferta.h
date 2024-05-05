#pragma once
#include <iostream>
#include <string>
#include "Lista.h"
using namespace std;
class Oferta
{
public:
	string miasto;
	string ulica;
	string metry;
	string cena;
	string sprzedaz;
	Oferta(string src_miasta, string src_ulice, string src_metry, string src_ceny, string src_sprzedaze);
	Oferta();
	~Oferta() = default;

};

