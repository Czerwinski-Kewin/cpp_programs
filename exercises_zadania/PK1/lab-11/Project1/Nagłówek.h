#pragma once
struct DATA {
	int rok;
	int mm;
	int dd;

	int ile;

	DATA* lewy;
	DATA* prawy;

	DATA(int _rok, int _mm, int _dd)
	{
		rok = _rok;
		mm = _mm;
		dd = _dd;
		ile = 1;
		lewy = NULL;
		prawy = NULL;
	}

	DATA()
	{
		rok = 0;
		mm = 0;
		dd = 0;
		lewy = NULL;
		prawy = NULL;
	}

};

int los(int _od, int _do);
void wypisz(DATA& d);
int ileLat(DATA& d1, DATA& d2);
int ileMM(DATA& d1, DATA& d2);
int ileDni(DATA& d1, DATA& d2);
int cmpData(DATA& d1, DATA& d2);
DATA losData(DATA& d1, DATA& d2);
void initTab(DATA* tab[], int size);
void wypiszTab(DATA* tab[], int size);
void deleteTab(DATA* tab[], int size);
void addNode(DATA*& root, DATA& d);
void wypiszTree(DATA* root);
void usunTree(DATA* root);