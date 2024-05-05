#pragma once
struct DATA {
	int rok;
	int mm;
	int dd;

	DATA(int _rok, int _mm, int _dd)
	{
		rok = _rok;
		mm = _mm;
		dd = _dd;
	}

	DATA()
	{
		rok = 0;
		mm = 0;
		dd = 0;
	}

};

int los(int _od, int _do);
void wypisz(DATA& d);
int ileLat(DATA& d1, DATA& d2);
int ileMM(DATA& d1, DATA& d2);
int ileDni(DATA& d1, DATA& d2);
int cmpData(DATA& d1, DATA& d2);
DATA losData(DATA& d1, DATA& d2);