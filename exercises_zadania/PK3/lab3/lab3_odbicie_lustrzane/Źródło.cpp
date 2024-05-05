#include <iostream>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
using namespace std;


void odczyt(vector<int>& wektor)
{
	ifstream plik_wczytaj("odczyt.txt");
	if (plik_wczytaj)
	{
		istream_iterator<int> fin(plik_wczytaj);
		istream_iterator<int> eos;
		copy(fin, eos, back_inserter(wektor));
	}
	plik_wczytaj.close();
}

void zapis(vector<int>& wektor)
{
	ofstream plik_zapisz("zapis.txt");
	if (plik_zapisz)
	{
		for (int c : wektor)
		{
			int a = 0;
			while (c > 0)
			{
				a = a * 10 + c % 10;
				c = c / 10;
			}
			cout << "test: " << a << endl;
			plik_zapisz << a << endl;
		}
		ostream_iterator<int> cout_it(cout);
		copy(wektor.begin(), wektor.end(), cout_it);
	}
	plik_zapisz.close();
}

int main()
{
	vector<int> wektor;
	odczyt(wektor);

	zapis(wektor);


	return 0;
}