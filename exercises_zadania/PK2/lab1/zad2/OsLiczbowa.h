#pragma once
#include <iostream>
using namespace std;

class OsLiczbowa
{
public:
	int min;
	int max;
	int interval;

	OsLiczbowa();
	OsLiczbowa(int _min, int _max);
	OsLiczbowa(const OsLiczbowa& amin, const OsLiczbowa& amax, const OsLiczbowa& ainterval);
	~OsLiczbowa();
};

