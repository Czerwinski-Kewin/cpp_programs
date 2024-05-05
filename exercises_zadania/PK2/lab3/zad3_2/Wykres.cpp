#include "Wykres.h"

Wykres::Wykres(int _rozmiar, string _nazwa, Typ _typ)
{
	nazwa = _nazwa;
	typ = _typ;
	cout << "Wykres - konstruktor wieloargumentowy";
}

Wykres::Wykres() : Wykres(5, "wyk1", Typ::Sunburst)
{
	cout << "Wykres - konstruktor bezargumentowy";
}

Wykres::~Wykres() 
{
	cout << "Wykres - destruktor";
}