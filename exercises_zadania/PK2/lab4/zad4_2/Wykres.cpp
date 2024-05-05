#include "Wykres.h"

Wykres::Wykres(int _rozmiar, string _nazwa, Typ _typ)
{
	rozmiar = _rozmiar;
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
	rozmiar = kp.rozmiar;
	nazwa = kp.nazwa;
	typ = kp.typ;
	cout << "Wykres - konstruktor przenoszacy" << endl;
}

void Wykres::draw()
{
	cout << nazwa << endl;
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
	rozmiar = r.rozmiar;
	nazwa = r.nazwa;
	typ = r.typ;
	return *this;
}

Wykres& Wykres::operator=(Wykres&& r)
{
	cout << "ZbiorOsi - operator przeniesienia" << endl;
	rozmiar = r.rozmiar;
	nazwa = r.nazwa;
	typ = r.typ;
	return *this;
}


//inne
Column::Column(){}

Column::Column(int _rozmiar, string _nazwa) : Wykres(_rozmiar, _nazwa, Typ::Column)
{

}

void Column::draw()
{
	for (int i = 0; i < rozmiar; i++)
		cout << "Column" << endl;
}

Treemap::Treemap(){}

Treemap::Treemap(int _rozmiar, string _nazwa) : Wykres(_rozmiar, _nazwa, Typ::Treemap)
{
	
}
void Treemap::draw()
{
	for (int i = 0; i < rozmiar; i++)
		cout << "Treemap" << endl;
}
