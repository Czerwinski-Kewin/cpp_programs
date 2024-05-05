#pragma once
#include <iostream>
using namespace std;

class OsLiczbowa
{
private:
	int min;
	int max;
	int interval;
	static int licznik;
public:
	void set(int _min, int _max, int _interval);
	int getMin();
	int getMax();
	int getInterval();
	void write();
	static int wypLicznik();

	OsLiczbowa();
	OsLiczbowa(int _min, int _max);
	OsLiczbowa(const OsLiczbowa& amin, const OsLiczbowa& amax, const OsLiczbowa& ainterval);
	~OsLiczbowa();
};
