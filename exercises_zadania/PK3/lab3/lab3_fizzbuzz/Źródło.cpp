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
			plik_zapisz << c << " - ";
			if (c % 3 == 0 && c % 5 == 0)
				plik_zapisz << "FizzBuzz";
			else if (c % 3 == 0)
				plik_zapisz << "Fizz";
			else if (c % 5 == 0)
				plik_zapisz << "Buzz";
			plik_zapisz << endl;
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