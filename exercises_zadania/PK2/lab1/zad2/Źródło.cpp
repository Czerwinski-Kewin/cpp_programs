#include <iostream>
#include "OsLiczbowa.h"
using namespace std;

int main()
{
	OsLiczbowa os;
	OsLiczbowa os2(5, 10);
	OsLiczbowa os3(os, os, os2);
}