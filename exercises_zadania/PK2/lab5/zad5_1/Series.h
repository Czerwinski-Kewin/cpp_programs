#pragma once
using namespace std;
#include <string>
#include <memory>

class Series
{
protected:
	int liczbaPunktow;
	unique_ptr<double[]> data;
	string nazwa;
};

