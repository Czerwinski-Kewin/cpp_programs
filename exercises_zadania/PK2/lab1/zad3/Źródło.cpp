#include <iostream>
#include "Nag³ówek.h"
#include "OsLiczbowa.h"
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
	OsLiczbowa os2(5, 10);
	//OsLiczbowa os3(os, os, os2);
	auxFun(os2);

	return 0;
}

