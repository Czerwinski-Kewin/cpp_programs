#include <iostream>
#include "Nag³ówek.h"
using namespace std;


int main(int argc, char** argv)		//char* argv[]
{
	int zm = 10;
	cout << "adres zm=" << &zm << " wartosc zm" << zm << endl;

	int* pzm = &zm;
	cout << "adres pzm=" << &pzm << " adres zm=" << pzm << " wartosc zm" << *pzm << endl;

	int zm2 = 20;
	cout << "zm=" << zm << " zm2=" << zm2 << endl;

	zamien(&zm, &zm2);
	cout << "zm=" << zm << " zm2=" << zm2 << endl;
	zamien(zm, zm2);
	cout << "zm=" << zm << " zm2=" << zm2 << endl;
	
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
		wypisz(argv[i], strlen(argv[i]));
		wypisz(argv[i], argv[i] + strlen(argv[i]));
	}

	return 0;
}


void wypisz(char* tabB, char* tabE)		//begin-end
{
	cout << *(tabB++);
	cout << ";";
	cout << endl;
}


void wypisz(char* tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << *(tab++) << ";";	//*(tab+i)
	}
	cout << endl;
}

/*
void wypisz(char* tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tab[i] << ";";
	}
	cout << endl;
}
*/

void zamien(int& a, int& b)
{
	int liczba = a;
	a = b;
	b = liczba;
}


void zamien(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}