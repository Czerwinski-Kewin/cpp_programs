#pragma once
#include "ZbiorOsi.h"

enum class Typ { XY, Column, Sunburst, Treemap };

class Wykres :
    public ZbiorOsi
{
public:
    int rozmiar;
    string nazwa;
    Typ typ;
    Wykres(int _rozmiar, string _nazwa, Typ _typ);
    Wykres();
    ~Wykres();
    friend ostream& operator << (ostream& ostr, static Wykres& obj);
    Wykres(const Wykres& cpn);
    Wykres(Wykres&& kp);
    Wykres& operator=(const Wykres& r);
    Wykres& operator=(Wykres&& r);
    virtual void draw();
    //void drawName();
    //virtual void draw() = 0;    //metoda czysto wirtualna
};

class Column : public Wykres
{
public:
    void draw();
    //void drawName();
    Column();
    Column(int _rozmiar, string _nazwa);
    ~Column();
};

class Treemap : public Wykres
{
public:
    void draw();
    //void drawName();
    Treemap();
    Treemap(int _rozmiar, string _nazwa);
};

