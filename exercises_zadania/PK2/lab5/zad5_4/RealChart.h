#pragma once
#include "Wykres.h"
#include "Series.h"
class RealChart :
    public Column, public Series
{
public:
    RealChart();
    RealChart(int _rozmiar, string _nazwa, int _liczbapunktow);
    ~RealChart();
    string& getWykresName();    //akcesor niejednoznacznosci
    string& getSeriesName();    //akcesor niejednoznacznosci
};
