#pragma once
using namespace std;
#include <string>
#include <memory>
#include <iostream>

class Series
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

