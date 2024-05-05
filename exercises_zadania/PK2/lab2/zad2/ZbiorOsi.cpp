#include "ZbiorOsi.h"
ZbiorOsi::ZbiorOsi()
{
	n = 0;
	//OsLiczbowa *tab = new OsLiczbowa[n];
	tab = new OsLiczbowa[n];
	tab = nullptr;
}

ZbiorOsi::ZbiorOsi()
{
	delete[] tab;
}


