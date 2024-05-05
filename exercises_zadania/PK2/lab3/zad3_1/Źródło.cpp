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
	//OsLiczbowa os;
	//OsLiczbowa os2;
	//OsLiczbowa::wypLicznik();
	//OsLiczbowa os3;
	//OsLiczbowa os2(5, 10);
	//OsLiczbowa os3(os, os, os2);
	//auxFun(os2);
	//os.set(4, 28, 2);
	//os.write();
	//cout << os;		//friend ostream zamiast write

	cout << "Lewe argumenty przed: " << endl;
	ZbiorOsi zbior = ZbiorOsi(3);
	ZbiorOsi zbior2 = ZbiorOsi(3);

	zbior = move(zbior2);

	//cout << zbior;
	cout << "Lewe argumenty po: " << endl;

	OsLiczbowa test;
	test.set(1, 3, 100);
	test *= 2;
	cout << test;
	//ZbiorOsi zbior3 = ZbiorOsi(3) + test;


	return 0;
}