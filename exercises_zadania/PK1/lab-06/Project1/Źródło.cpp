#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Nag³ówek.h"
using namespace std;

//wypisz nie potrzebuje koniecznie referencji
void wypisz(const osoba &os)
{
	cout << os.nazwisko << endl;
	cout << os.pensja << endl;
	cout << os.liczba_dzieci << " : ";
	for (int i = 0; i < os.liczba_dzieci; i++)
		cout << os.rok_ur_dzieci[i] << " ";
	cout << endl;
}

void wprowadz(osoba &os)
{
	os.nazwisko = "AAA";
	os.pensja = 44.11;
	os.liczba_dzieci = 2;
	os.rok_ur_dzieci[0] = 2020;
	os.rok_ur_dzieci[1] = 2022;
}

void zapisz(ostream &plik, const osoba &os)
{
	plik << os.nazwisko << endl;
	plik << os.pensja << endl;
	plik << os.liczba_dzieci << " : ";
	for (int i = 0; i < os.liczba_dzieci; i++)
		plik << os.rok_ur_dzieci[i] << " ";
	plik << endl;
}

void wypisztab(const osoba tab[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		if(tab[i].pensja)	//if(tab[i].pensja!=0)
			wypisz(tab[i]);
}

void zapisztab(string nazwaPliku, const osoba tab[], int rozmiar)
{
	ofstream plik(nazwaPliku);
	for (int i = 0; i < rozmiar; i++)
		if (tab[i].pensja)	//if(tab[i].pensja!=0)
			zapisz(plik, tab[i]);
	plik.close();
}

bool wczytaj(string nazwaPliku, vector<osoba> &vOs)
{
	ifstream plik(nazwaPliku);
	if (!plik.is_open())
		return false;

	while (!plik.eof())
	{
		osoba os;
		if(pobierz(plik, os))			//if wykonuje tylko wtedy gdy uda³o siê pobraæ
			vOs.push_back(os);
		//zapisz(cout, os);
	}
	return true;
	
}

bool pobierz(istream& i, osoba& os)
{
	i >> os.nazwisko;						//istream - dowolny strumieñ wejœciowy
	i >> os.pensja;							//ifstream - strumieñ wejœciowy pliku
	if (!i)
	{
		i.clear();
		i.ignore(10000, '\n');
		return false;
	}
	i >> os.liczba_dzieci;
	if (!i)
	{
		i.clear();
		i.ignore(10000, '\n');
		return false;
	}
	for (int j = 0; j < os.liczba_dzieci; j++)
	{
		i >> os.rok_ur_dzieci[j];
		if (!i)
		{
			i.clear();
			i.ignore(10000, '\n');
			return false;
		}
	}
	return true;	

}

void wypiszV(const vector<osoba> tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		zapisz(cout, tab[i]);
	}
}

vector<osoba>& zwrocVosBezDzieci(vector<osoba> &vOs)
{
	vector<osoba> vOsB;
	for (int i = 0; i < vOs.size(); i++)
	{
		if (!vOs[i].liczba_dzieci)
		{
			vOsB.push_back(vOs[i]);
			vOs.erase(vOs.begin() + i);
			--i;
		}
	}
	return vOsB;
}

int main()
{
	string nazwa = "plik.txt";
	osoba os1;
	const int N = 100;
	osoba tab[N];
	vector<osoba> vOs;
	vector<osoba> vOsB;
	wprowadz(tab[0]);
	wprowadz(tab[4]);
	wypisztab(tab, N);
	zapisztab("plik.txt", tab, N);
	/*
	cout << endl;
	cout << "Podaj dane" << endl;
	if (pobierz(cin, os1))
		zapisz(cout, os1);
	else
		cout << "B³¹d danych";
	*/
	
	if (!wczytaj(nazwa, vOs))
		cout << "Blad pliku" << " " << nazwa << endl;
	else
		cout << "Plik wczytany" << endl;
	wypiszV(vOs);
	vOsB = zwrocVosBezDzieci(vOs);

	/*
	osoba(os);
	osoba o1, o3;	//metoda inicjalizacyjna bez argumentów
	osoba o2("BBBB", 7589.56);		//z argumentami
	//kolejnosc wykonania funkcji kluczowa
	wprowadz(o1);
	wypisz(o1);
	wypisz(o2);
	wypisz(o3);
	*/
	
	return 0;
}