#include <iostream>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
using namespace std;

mt19937 gen{ random_device{}() };
uniform_real_distribution<double> los{ -1,1 };

void odczyt(vector<double>& wektor)
{
	ifstream plik_wczytaj("odczyt.txt");
	if (plik_wczytaj)
	{
		istream_iterator<double> fin(plik_wczytaj);
		istream_iterator<double> eos;
		copy(fin, eos, back_inserter(wektor));
	}
	plik_wczytaj.close();
}

void zapis(vector<double>& wektor)
{
	ofstream plik_zapisz("zapis.txt");
	if (plik_zapisz)
	{
		double x;
		double y;
		int kolo = 0;

		generate(wektor.begin(), wektor.end(),
			[]() {
				double liczba = los(gen);
				return liczba;
			}
		);

		for (double c : wektor)
		{
			x = c;
			y = los(gen);

			if (x * x + y * y <= 1)
				kolo++;
		}
		double pi = 4. * kolo / 10000;
		cout << "test: " << pi << endl;
		plik_zapisz << pi << endl;
		ostream_iterator<double> cout_it(cout);
		copy(wektor.begin(), wektor.end(), cout_it);
	}
	plik_zapisz.close();
}



int main()
{
	vector<double> wektor(10000);
	odczyt(wektor);

	zapis(wektor);


	return 0;
}