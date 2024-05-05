#pragma once
#include "ZbiorOsi.h"

enum class Typ { XY, Column, Sunburst, Treemap };

class Wykres :
    public ZbiorOsi
{
public:
    string nazwa;
    Typ typ;
    Wykres(int _rozmiar, string _nazwa, Typ _typ);
    Wykres();
    ~Wykres();
    friend ostream& operator << (ostream& ostr, static Wykres& obj);
};

