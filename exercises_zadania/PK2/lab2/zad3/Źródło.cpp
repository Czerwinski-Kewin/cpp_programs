#include <iostream>
#include "Nag��wek.h"
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
	OsLiczbowa os;
	OsLiczbowa os2;
	//OsLiczbowa::wypLicznik();
	OsLiczbowa os3;
	//OsLiczbowa os2(5, 10);
	//OsLiczbowa os3(os, os, os2);
	//auxFun(os2);
	os.set(4, 28, 2);
	//os.write();
	cout << os;		//friend ostream zamiast write


	return 0;
}