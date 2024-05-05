using namespace std;
#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <string>


void inicjalizacja(vector<int> &wektor, int n)
{
	for (int i = 0; i < n; i++)
		wektor.push_back(rand()%21);
}

void wypisz(vector<int> &wektor)
{
	for (int i = 0; i < wektor.size(); i++)
		cout << wektor[i] << " ";
	cout << endl;
}

void znajdz(vector<int>& wektor, int &min, int &max)
{
	for (int i = 0; i < wektor.size(); i++)
	{
		
		if (min > wektor[i])	min = wektor[i];
		if (max < wektor[i])	max = wektor[i];
	}
	
	cout << "min=" << min << " " << "max=" << max;
	cout << endl;
}

void znaki(string& napis)
{
	for (int i = 0; i < napis.length(); i++)
	{
		cout << napis.substr(i, 1) << " ";
	}
		
}

int main(int liczArg, char* tabArg[])	//argc argv
{
	cout << liczArg << endl;
	for (int i = 0; i < liczArg; i++)
		cout << tabArg[i] << endl;

	if (liczArg < 2)
	{
		cout << "za malo arg";
		//return 0;
	}
	int liczba = atoi(tabArg[1]);
	if (liczba > 20)	liczba = 20;
	int tab[20];
	for (int i = 0; i < 20; i++)
	{
		if (i < liczba)
			tab[i] = i;
		else
			tab[i] = 0;
		cout << tab[i] << " ";
	}
	cout << endl;

	vector<int> wektor;
	string napis = "hyheydheyh";
	int min = 0;
	int max = 0;
	srand(time(NULL));

	char tekst[30];
	char tek[] = "bbb";
	cout << tek << endl;

	//int liczba = atoi("10");
	//cout << "liczba: " << liczba << endl;


	inicjalizacja(wektor, 10);
	min = wektor[0];
	max = wektor[0];
	wypisz(wektor);
	znajdz(wektor, min, max);
	znaki(napis);

	
}
