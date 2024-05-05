#include "OsLiczbowa.h"

#include <iostream>
using namespace std;

void OsLiczbowa::set(int _min, int _max, int _interval)
{
	min = _min;
	max = _max;
	interval = _interval;
}

int OsLiczbowa::getMin()
{
	return min;
}

int OsLiczbowa::getMax()
{
	return max;
}

int OsLiczbowa::getInterval()
{
	return interval;
}

void OsLiczbowa::write()
{
	cout << getMin() << " " << getMax() << " " << getInterval() << " " << endl;
}

OsLiczbowa::OsLiczbowa() {
	min = 5;
	max = 10;
	interval = 1;
	cout << "OsLiczbowa - konstruktor domyslny" << endl;
}

OsLiczbowa::OsLiczbowa(int _min, int _max) {
	//this->min = min;	- lepiej stosowac podkreslenia
	min = _min;
	max = _max;
	interval = (max - min) / max;
	cout << "OsLiczbowa - konstruktor dwuargumentowy" << endl;
}

OsLiczbowa::OsLiczbowa(const OsLiczbowa& amin, const OsLiczbowa& amax, const OsLiczbowa& ainterval) {
	min = amin.min;
	max = amax.max;
	interval = ainterval.interval;
	cout << "OsLiczbowa - konstruktor wieloargumentowy kopiujacy" << endl;
}

OsLiczbowa::~OsLiczbowa() {
	cout << "OsLiczbowa - destruktor" << endl;
};
