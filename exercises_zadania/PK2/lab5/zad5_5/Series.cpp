#include "Series.h"
Series::Series(int aLiczbaPunktow, string aNazwa)
{
	cout << "Series - konstruktor wieloargumentowy" << endl;
	liczbaPunktow = aLiczbaPunktow;
	nazwa = aNazwa;
}

Series::Series() : Series(5, "ser1")
{
	cout << "Series - konstruktor bezargumentowy" << endl;
}

Series::~Series()
{
	cout << "Series - destruktor" << endl;
}

ostream& operator <<(ostream& ostr, const Series& obj)
{
	ostr << obj.liczbaPunktow << " " << obj.nazwa << endl;
	return ostr;
}
