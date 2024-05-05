#pragma once
#include "OsLiczbowa.h"
class ZbiorOsi
{
	int n;
public:
	OsLiczbowa* tab = NULL;
	ZbiorOsi();
	ZbiorOsi(int _n);
	ZbiorOsi(const ZbiorOsi& cpn);
	ZbiorOsi(ZbiorOsi&& kp);
	~ZbiorOsi();
	friend ostream& operator << (ostream& ostr, const ZbiorOsi& obj);
};

