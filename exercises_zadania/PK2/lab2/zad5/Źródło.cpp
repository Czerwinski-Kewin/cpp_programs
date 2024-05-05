#include <iostream>
#include "Nag³ówek.h"
#include "OsLiczbowa.h"
#include "ZbiorOsi.h"
using namespace std;


void auxFun(OsLiczbowa osarg)
{
	OsLiczbowa os3(osarg, osarg, osarg);
	OsLiczbowa* ptr = new OsLiczbowa(osarg);
	delete ptr;
}

int main()
{
	OsLiczbowa os;
	OsLiczbowa os2;
	//OsLiczbowa::wypLicznik();
	//OsLiczbowa os3;
	//OsLiczbowa os2(5, 10);
	//OsLiczbowa os3(os, os, os2);
	//auxFun(os2);
	os.set(4, 28, 2);
	//os.write();
	//cout << os;		//friend ostream zamiast write

	//ZbiorOsi zbior = ZbiorOsi(3);
	//cout << zbior;
	cout << "Lewe argumenty przed: " << os;
	os = os2;
	cout << "Lewe argumenty po: " << os;


	return 0;
}