#include "ZbiorOsi.h"
ZbiorOsi::ZbiorOsi()
{
	//ic
	n = 0;
	//OsLiczbowa *tab = new OsLiczbowa[n];
	OsLiczbowa *tab = new OsLiczbowa[n];
	//OsLiczbowa* tab = NULL;
	//tab = NULL;
}

ZbiorOsi::ZbiorOsi(int _n) {
	
	n = _n;
	OsLiczbowa* tab = new OsLiczbowa[n];
	for (int i = 0; i < n; i++)
	{
		OsLiczbowa nowa_os;
		nowa_os.set(23+i, 3+i, 5+i);
		tab[i] = nowa_os;
	}
	
	//OsLiczbowa* tab = new OsLiczbowa[2];
	//OsLiczbowa test;
	//test.set(5, 10, 15);
	//tab[0] = test;
	//for (int i = 0; i < n; i++)
		//cout << tab[i].getMin() << " " << tab[i].getMax() << " " << tab[i].getInterval() << endl;
	for (int i = 0; i < n; i++)
		cout << tab[i];
	//cout << tab[0];
	
	
}


ZbiorOsi::ZbiorOsi(const ZbiorOsi& cpn) {
	n = cpn.n;
}

ZbiorOsi::ZbiorOsi(ZbiorOsi&& kp) {
	n = kp.n;
}

ZbiorOsi::~ZbiorOsi() {
	if (tab != nullptr)
	{
		delete[] tab;
	}

}

ostream& operator <<(ostream& ostr, const ZbiorOsi& obj)
{
	//ostr << obj.tab << endl;
	
	//for (int i = 0; i < obj.n; i++)
		//ostr << obj.tab[i];
	//ostr << obj.tab[0];
	return ostr;
}

