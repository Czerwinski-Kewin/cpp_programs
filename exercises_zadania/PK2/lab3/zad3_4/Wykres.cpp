#include "Wykres.h"

Wykres::Wykres(int _rozmiar, string _nazwa, Typ _typ)
{
	nazwa = _nazwa;
	typ = _typ;
	cout << "Wykres - konstruktor wieloargumentowy" << endl;
}

Wykres::Wykres() : Wykres(5, "wyk1", Typ::Sunburst)
{
	cout << "Wykres - konstruktor bezargumentowy" << endl;;
}

Wykres::~Wykres()
{
	cout << "Wykres - destruktor" << endl;
}

ostream& operator <<(ostream& ostr, static Wykres& obj)
{
	ostr << obj.nazwa << endl;
	ostr << static_cast<ZbiorOsi&>(obj);
	return ostr;
}

