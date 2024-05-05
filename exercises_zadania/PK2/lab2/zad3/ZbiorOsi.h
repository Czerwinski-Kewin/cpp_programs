#pragma once
#include "OsLiczbowa.h"
class ZbiorOsi
{
	int n;
	OsLiczbowa *tab;
	ZbiorOsi();
	ZbiorOsi(int _n);
	ZbiorOsi(const ZbiorOsi& cpn);
	ZbiorOsi(ZbiorOsi&& kp);
	~ZbiorOsi();
};

