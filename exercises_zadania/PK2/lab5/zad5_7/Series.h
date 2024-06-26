#pragma once
using namespace std;
#include <string>
#include <memory>
#include <iostream>
#include "Name.h"

class Series : virtual public Name
{
public:
	Series();
	~Series();
protected:
	int liczbaPunktow;
	unique_ptr<double[]> data;
	string nazwa;
	Series(int aLiczbaPunktow, string aNazwa);
	friend ostream& operator << (ostream& ostr, const Series& obj);

};

