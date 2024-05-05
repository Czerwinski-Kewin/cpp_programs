#pragma once
using namespace std;

struct osoba {
	string nazwisko;
	double pensja;
	int liczba_dzieci;	//max 15
	int rok_ur_dzieci[15];

	osoba(string _nazwisko, double _pensja)
	{
		nazwisko = _nazwisko;
		pensja = _pensja;
		liczba_dzieci = 0;
		
	}

	osoba()
	{
		nazwisko = "";
		pensja = 0;
		liczba_dzieci = 0;
	}
};

void zapisz(ostream& plik, const osoba& os);
void zapisztab(string nazwaPliku, const osoba tab[], int rozmiar);
void wypisztab(const osoba tab[], int rozmiar);
void wypisz(const osoba &os);
void wprowadz(osoba &os);
bool wczytaj(string nazwaPliku, vector<osoba>& vOs);
bool pobierz(istream& i, osoba& os);
void wypiszV(const vector<osoba> tab);
vector<osoba>& zwrocVosBezDzieci(const vector<osoba>& vOs);
