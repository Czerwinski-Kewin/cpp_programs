#pragma once
#include "ZbiorOsi.h"

enum class Typ { XY, Column, Sunburst, Treemap };

class Wykres :
    public ZbiorOsi
{
    string nazwa;
    Typ typ;
};



