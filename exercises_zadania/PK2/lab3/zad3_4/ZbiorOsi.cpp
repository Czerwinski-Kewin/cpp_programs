#include "ZbiorOsi.h"
ZbiorOsi::ZbiorOsi()
{
	//ic
	//n = 0;
	//OsLiczbowa *tab = new OsLiczbowa[n];
	//OsLiczbowa* tab = new OsLiczbowa[n];
	//OsLiczbowa* tab = NULL;
	//tab = NULL;

	cout << "ZbiorOsi - konstruktor bezargumentowy" << endl;
	n = 3;
	//OsLiczbowa* tab = new OsLiczbowa[n];
	OsLiczbowa* tab = new OsLiczbowa[n];
	OsLiczbowa nowa_os;
	for (int i = 0; i < n; i++)
	{
		nowa_os.set(23 + i, 3 + i, 5 + i);
		tab[i] = nowa_os;
	}

	for (int i = 0; i < n; i++)
		cout << tab[i];
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
	tab = kp.tab;
	kp.tab = nullptr;
	cout << "ZbiorOsi - konstruktor przenoszacy" << endl;
}

ZbiorOsi::~ZbiorOsi() {
	if (tab != nullptr)
	{
		delete[] tab;
		cout << "ZbiorOsi - destruktor" << endl;
	}
	else
		cout << "ZbiorOsi - destruktor nullptr" << endl;
}

ostream& operator <<(ostream& ostr, const ZbiorOsi& obj)
{
	//ostr << obj.tab << endl;

	/*
	for (int i = 0; i < obj.n; i++)
		ostr << obj.tab[i];
	*/
	
	//ostr << static_cast<OsLiczbowa&>(obj.tab[0]);
	return ostr;
}


ZbiorOsi& ZbiorOsi::operator=(const ZbiorOsi& r)
{
	cout << "ZbiorOsi - operator przypisania" << endl;
	n = r.n;
	for (int i = 0; i < n; i++)
	{
		tab[i] = r.tab[i];
	}
	return *this;
}

ZbiorOsi& ZbiorOsi::operator=(ZbiorOsi&& r)
{
	cout << "ZbiorOsi - operator przeniesienia" << endl;
	n = r.n;
	tab = r.tab;
	r.tab = nullptr;
	return *this;
}

ZbiorOsi ZbiorOsi::operator+(const OsLiczbowa& r)
{
	n++;
	tab[n - 1] = r;
	return *this;
}
