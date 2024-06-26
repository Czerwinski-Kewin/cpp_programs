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

Wykres::Wykres(const Wykres& cpn) : Wykres(5, cpn.nazwa, cpn.typ) {
	//nazwa = cpn.nazwa;
	//typ = cpn.typ;
	cout << "Wykres - konstuktor kopiujacy" << endl;
}

Wykres::Wykres(Wykres&& kp) {
	nazwa = kp.nazwa;
	typ = kp.typ;
	cout << "Wykres - konstruktor przenoszacy" << endl;
}

ostream& operator <<(ostream& ostr, static Wykres& obj)
{
	ostr << obj.nazwa << endl;
	ostr << static_cast<ZbiorOsi&>(obj);
	return ostr;
}

Wykres& Wykres::operator=(const Wykres& r)
{
	cout << "Wykres - operator przypisania" << endl;
	nazwa = r.nazwa;
	typ = r.typ;
	return *this;
}
