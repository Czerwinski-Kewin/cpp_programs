#include "RealChart.h"

RealChart::RealChart(int _rozmiar, string _nazwa, int _liczbapunktow)
{
	cout << "RealChart - konstruktor wieloargumentowy" << endl;
	rozmiar = _rozmiar;
	//nazwa = _nazwa;
	liczbaPunktow = _liczbapunktow;
}

RealChart::RealChart() : RealChart(44, "realch", 8)
{
	cout << "RealChart - konstruktor bezargumentowy" << endl;
}

RealChart::~RealChart()
{
	cout << "RealChart - destruktor" << endl;
}

string& RealChart::getWykresName()
{
	return Wykres::nazwa;
}

string& RealChart::getSeriesName()
{
	return Series::nazwa;
}
