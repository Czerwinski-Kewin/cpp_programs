#include "Series.h"
Series::Series(int aLiczbaPunktow, string aNazwa)
{
	liczbaPunktow = aLiczbaPunktow;
	nazwa = aNazwa;
}

Series::Series() : Series(5, "ser1")
{

}

Series::~Series() {}

ostream& operator <<(ostream& ostr, const Series& obj)
{
	ostr << obj.liczbaPunktow << " " << obj.nazwa << endl;
	return ostr;
}