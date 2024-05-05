#include "ZbiorOsi.h"
ZbiorOsi::ZbiorOsi()
{
	//ic
	//n = 0;
	//OsLiczbowa *tab = new OsLiczbowa[n];
	//OsLiczbowa* tab = new OsLiczbowa[n];
	//OsLiczbowa* tab = NULL;
	//tab = NULL;
}

ZbiorOsi::ZbiorOsi(int _n) {
	
	cout << "ZbiorOsi - konstruktor jednoargumentowy" << endl;
	n = _n;
	//OsLiczbowa* tab = new OsLiczbowa[n];
	OsLiczbowa* tab = new OsLiczbowa[n];
	OsLiczbowa nowa_os;
	for (int i = 0; i < n; i++)
	{
		nowa_os.set(23 + i, 3 + i, 5 + i);
		tab[i] = nowa_os;
	}

	//OsLiczbowa* tab = new OsLiczbowa[2];
	//OsLiczbowa test;
	//test.set(5, 10, 15);
	//tab[0] = test;
	//for (int i = 0; i < n; i++)
		//cout << tab[i].getMin() << " " << tab[i].getMax() << " " << tab[i].getInterval() << endl;
	//cout << tab[0];
	for (int i = 0; i < n; i++)
		cout << tab[i];
	
}


ZbiorOsi::ZbiorOsi(const ZbiorOsi& cpn) {
	n = cpn.n;
	tab = new OsLiczbowa[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = cpn.tab[i];
	}
	cout << "ZbiorOsi - konstuktor kopiujacy";
}

ZbiorOsi::ZbiorOsi(ZbiorOsi&& kp) {
	n = kp.n;
}

ZbiorOsi::~ZbiorOsi() {
	if (tab != nullptr)
	{
		delete[] tab;
		cout << "ZbiorOsi - destruktor" << endl;
	}
	cout << "ZbiorOsi - destruktor nullptr" << endl;
}

ostream& operator <<(ostream& ostr, const ZbiorOsi& obj)
{
	//ostr << obj.tab << endl;

	for (int i = 0; i < obj.n; i++)
		ostr << obj.tab[i];
	//ostr << obj.tab[2];
	//ostr << static_cast<OsLiczbowa&>(obj.tab[0]);
	return ostr;
}


ZbiorOsi& ZbiorOsi::operator=(const ZbiorOsi& r)
{
	cout << "ZbiorOsi - operator przypisania" << endl;
	for (int i = 0; i < n; i++)
	{
		tab[i] = r.tab[i];
	}
	
	return *this;
}
