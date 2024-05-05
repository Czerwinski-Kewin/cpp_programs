#include "ZbiorOsi.h"
ZbiorOsi::ZbiorOsi()
{
	//ic
	n = 0;
	//OsLiczbowa *tab = new OsLiczbowa[n];
	tab = new OsLiczbowa[n];
	tab = nullptr;
}

ZbiorOsi::ZbiorOsi(int _n) {
	//n = _n;
}

ZbiorOsi::ZbiorOsi(const ZbiorOsi& cpn) {
	//n = cpn.n;
}

ZbiorOsi::ZbiorOsi(ZbiorOsi&& kp) {

}

ZbiorOsi::~ZbiorOsi() {
	if (tab != nullptr)
	{
		delete[] tab;
	}
	
}