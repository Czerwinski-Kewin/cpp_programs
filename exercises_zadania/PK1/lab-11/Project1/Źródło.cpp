using namespace std;
#include <iostream>
#include <chrono>
#include <random>

#include "Nag³ówek.h";

const int N = 100;		//rozmiar tworzonej tablicy

int main(int argc, char** argv)		//char* argv[]
{
	DATA* tab[N];
	initTab(tab, N);
	tab[2] = new DATA(2022, 12, 11);
	tab[5] = new DATA(2020, 12, 11);
	wypiszTab(tab, N);
	cout << "-----" << endl;
	deleteTab(tab, N);
	wypiszTab(tab, N);
	cout << "-----" << endl;

	//drzewo binarne
	DATA* root = NULL;
	DATA d3(2020, 11, 5);
	addNode(root, d3);

	DATA d4(2025, 12, 11);
	addNode(root, d4);

	DATA d1(2021, 11, 5);
	addNode(root, d1);
	addNode(root, d4);

	DATA d2(2022, 12, 11);
	addNode(root, d2);

	addNode(root, d4);
	addNode(root, d4);

	wypiszTree(root);		//sortowanie dat drzewem binarnym
	usunTree(root);
	//-----
	/*
	DATA* B = new DATA(2020, 12, 11);
	DATA b(2010, 12, 11);
	b.dd = 5;
	B->dd = 5;

	tab[8] = B;
	*/

	/*
	DATA d1(2022, 11, 5);
	DATA d2(2022, 12, 11);
	wypisz(d1);
	wypisz(d2);
	DATA d3 = losData(d1, d2);
	wypisz(d3);
	cout << ileDni(d1, d2) << endl;
	int wynik = cmpData(d2, d1);
	cout << "cmp=" << wynik << endl;
	

	typedef int (*typ_pF) (DATA&, DATA&);	//synonim typu
	//typ_pF fun = cmpData;
	typ_pF fun[4];
	fun[0] = cmpData;
	fun[1] = ileLat;
	fun[2] = ileMM;
	fun[3] = ileDni;
	for (int i = 0; i < 4; i++)
	{
		wynik = fun[i](d1, d2);
		cout << "cmp=" << wynik << endl;
	}
	*/


	/*
	fun = ileDni;
	wynik = fun(d1, d2);
	cout << "cmp=" << wynik << endl;
	return 0;
	*/

}

void usunTree(DATA* root)
{
	if (root == NULL)	return;

	usunTree(root->lewy);
	usunTree(root->prawy);
	delete root;
	root = NULL;			//konieczne przypisanie nulla
}

void addNode(DATA *&root, DATA& d)
{
	if (root == NULL)
	{
		root = new DATA(d.rok, d.mm, d.dd);
		return;
	}
	if (cmpData(*root, d) > 0)
		addNode(root->prawy, d);
	else if(cmpData(*root, d) == 0)		//jesli data juz istnieje
		root->ile++;
	else
		addNode(root->lewy, d);

	
}

void wypiszTree(DATA* root)
{
	if (root == NULL)	return;
	wypiszTree(root->lewy);
	wypisz(*root);
	wypiszTree(root->prawy);
	/*
	if (root == NULL)	return;
	if (root->lewy != NULL)	wypiszTree(root->lewy);
	wypisz(*root);
	if (root->prawy != NULL)	wypiszTree(root->prawy);
	*/

}

void initTab(DATA* tab[], int size)	//lub DATA** tab
{
	for (int i = 0; i < size; i++)
	{
		tab[i] = nullptr;
	}
}

void wypiszTab(DATA* tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if(tab[i]!=nullptr)
			wypisz(*tab[i]);	//NULL
	}
}

void deleteTab(DATA* tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (tab[i] != nullptr)
		{
			delete tab[i];
			tab[i] = NULL;		//nie ma potrzeby na koncu programu
		}
	}
}

int los(int _od, int _do)
{
	static std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double> rozklad(_od, _do);
	int losowa = rozklad(silnik);
	return losowa;
}

void wypisz(DATA& d)
{
	cout << d.rok << "." << d.mm << "." << d.dd << "(" << d.ile << ")" << endl;
}

DATA losData(DATA& d1, DATA& d2)
{
	DATA nowa;
	int dni = ileDni(d1, d2);
	if (dni < 0)	return nowa;
	if (dni == 0)	return d1;
	int losowy = los(0, dni);

	int dzien = losowy % 30;
	int miesiac = (losowy - dzien) / 30;
	int mm = miesiac % 12;
	int rok = (miesiac - mm) / 12;
	nowa.rok = d1.rok + rok;
	nowa.mm = d1.mm + mm;
	if (nowa.mm > 12)
		nowa.mm = 12 - nowa.mm;
	nowa.dd = d1.dd + dzien;
	if (nowa.dd > 30)
		nowa.dd = 30 - nowa.dd;
	return nowa;
}

int cmpData(DATA& d1, DATA& d2)
{
	int wynik = ileDni(d1, d2);
	if (wynik < 0)	return -1;
	if (wynik > 0)	return 1;
	return 0;
}

int ileLat(DATA& d1, DATA& d2)
{
	//if (d1.rok > d2.rok)	return -1;
	if (d1.rok == d2.rok)	return 0;
	return d2.rok - d1.rok;
}

int ileMM(DATA& d1, DATA& d2)
{
	int mm = -1;
	int lata = ileLat(d1, d2);
	if (lata < 0)	return -1;
	if (lata == 0)
	{
		return d2.mm - d1.mm;
	}
	else
	{
		mm = 12 * (lata - 1);
		mm += 12 - d1.mm + d2.mm;
	}
	return mm;

}

int ileDni(DATA& d1, DATA& d2)
{
	int dd = -1;
	int mm = ileMM(d1, d2);
	if (mm < 0)	return -1;
	if (mm == 0)
	{
		return d2.dd - d1.dd;
	}
	else
	{
		dd = 30 * (mm - 1);
		dd += 30 - d1.dd + d2.dd;
	}
	return dd;


}